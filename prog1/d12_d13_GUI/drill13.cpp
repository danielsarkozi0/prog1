#include "Simple_window.h"
#include "Graph.h"

/*
g++ drill13.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o d13 `fltk-config --ldflags --use-images`
*/

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
	int grid_size = 100;
	
	Lines grid;
	for (int x = x_grid; x <= 800; x+=x_grid)
	{
		grid.add(Point(x,0),Point(x,800));
	}
	for (int y = y_grid; y <= 800; y+=y_grid)
	{
		grid.add(Point(0,y),Point(x_size,y));
	}
	win.attach(grid);

	Vector_ref<Rectangle> vr;

	for (int i = 0; i < 8; ++i)
	{
		vr.push_back(new Rectangle(Point{i*grid_size,i*grid_size}, grid_size,grid_size));
		vr[vr.size()-1].set_fill_color(Color::red);
		win.attach(vr[vr.size()-1]);
	}

	Vector_ref<Image> vi;

	vi.push_back(new Image(Point{0,200}, "200x200.jpg"));
	vi.push_back(new Image(Point{0,400}, "200x200.jpg"));
	vi.push_back(new Image(Point{0,600}, "200x200.jpg"));

	constexpr int image_size = 200;

	for (int i = 0; i < vi.size(); ++i)
	{
		vi[i].set_mask(Point{0,0}, image_size, image_size);
		win.attach(vi[i]);
	}

	Image logo(Point{0,0}, "badge.jpg");
	logo.set_mask(Point{0,0},100, 100);
	win.attach(logo);
	

	for (int i = 0; i < 8; ++i)
	{
		for (int j = 0; j < 8; ++j)
		{
			win.wait_for_button();
			if(j < 7) logo.move(100,0);
			else logo.move(-700,100);
		}
	}
	win.wait_for_button();
}