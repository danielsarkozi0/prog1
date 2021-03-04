#include "Simple_window.h"
#include "Graph.h"

/*
g++ drill13.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o d13 `fltk-config --ldflags --use-images`
*/
/*
void Lines::add(Point p1, Point p2)
{
	Shape::add(p1);
	Shape::add(p2);
}*/

int main()
{
	using namespace Graph_lib;

    int xmax = 800;
    int ymax = 1000;

    Simple_window win {Point{100,100}, xmax, ymax, "Grid"};

    int x_size = win.x_max();
    int y_size = win.y_max();
    int x_grid = 100;
	int y_grid = 100;
	
	Lines grid;
	for (int x = x_grid; x <= 800; x+=x_grid)
	{
		grid.add(Point(x,0),Point(x,800));
	}
	for (int y = y_grid; y <= 800; y+=y_grid)
	{
		grid.add(Point(0,y),Point(x_size,y));
	}
	Image i2001 {Point{0,0},"200x200.jpg"};
	Image i2002 {Point{0,600},"200x200.jpg"};
	Image i2003 {Point{600,0},"200x200.jpg"};
	Image i2004 {Point{600,600},"200x200.jpg"};

	Vector_ref<Rectangle> vr;

	for (int i = 0; i < 8; ++i)
	{
		vr.push_back(new Rectangle(Point{i*grid_size,i*grid_size}, grid_size,grid_size));
		vr[vr.size()-1].set_fill_color(Color::red);
		win.attach(vr[vr.size()-1]);
	}


	win.attach(grid);

	win.attach(i2001);
	win.attach(i2002);
	win.attach(i2003);
	win.attach(i2004);

	win.wait_for_button();
}