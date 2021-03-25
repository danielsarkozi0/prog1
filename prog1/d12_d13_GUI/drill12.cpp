#include "Simple_window.h"
#include "Graph.h"
#include "std_lib_facilities.h"
/*
g++ drill12.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o d12 `fltk-config --ldflags --use-images`
*/

int main()
try
{
	using namespace Graph_lib;

    int xmax = 600;
    int ymax = 400;
    Point tl {100,100};

    Simple_window win {tl, xmax, ymax, "Az en ablakom"};
    
 
	Axis xa {Axis::x, Point{20,300}, 280, 10, "x axis"};

	Axis ya {Axis::y, Point{20,300}, 280, 10, "y axis"};
	ya.set_color(Color::dark_cyan);
	ya.label.set_color(Color::dark_red);

	Function sine {sin,0,100,Point{20,150},1000,50,50};


	sine.set_color(Color::blue);
	Polygon poly;
	poly.add(Point{300,50});
	poly.add(Point{350,150});
	poly.add(Point{400,200}); 
	poly.set_color(Color::red);
	poly.set_style(Line_style::dash);

	Rectangle r {Point{200,200}, 55, 50};

	Closed_polyline poly_rect;
	poly_rect.add(Point{100,50});
	poly_rect.add(Point{300,50});
	poly_rect.add(Point{300,100});
	poly_rect.add(Point{100,100});

	poly_rect.add(Point{50,75});

	r.set_fill_color(Color::blue); // teglalap szinezese
	poly.set_style(Line_style(Line_style::dash,4)); //haromszog vonalai 
	poly_rect.set_style(Line_style(Line_style::dash,2)); //otszog vonalai
	poly_rect.set_fill_color(Color::dark_yellow); //otszog szinezese

	Text t {Point{150,150}, "Sarkozi Daniel"};
	t.set_font(Font::times_bold);
	t.set_font_size(30);

	win.attach(t);	//szoveg
	win.attach(poly_rect);//otszog
	win.attach(r);//teglalap
	win.attach(poly);//haromszog
	win.attach(sine);//sin vonal
	win.attach(ya); //y tengely
	win.attach(xa); //x tengely

	Image ii {Point{100,50},"200x200.jpg"};
	win.attach(ii);  //kep
	win.wait_for_button();
	ii.move(100,200);


	Circle c {Point{100,200},20};
	Ellipse e {Point{100,200}, 75,25};
	e.set_color(Color::dark_red);
	Mark m {Point{100,200},'x'};

	ostringstream oss;
	oss << "screen size: " << x_max() << "*" << y_max()
	<< "; window size: " << win.x_max() << "*" << win.y_max();
	Text sizes {Point{100,20},oss.str()};

	win.attach(m);//x
	win.attach(c);//ellipszis
	win.attach(e);//ellipszis
	win.attach(sizes);//kepernyo meretek

	Image cal {Point{225,225},"snow_cpp.jpeg"};
	cal.set_mask(Point{40,40},200,150);
	win.attach(cal);//kep
	win.set_label("Az en ablakocskam");

	win.wait_for_button();
}
catch(exception& e){
	return 1;
}
catch(...){
	return 2;
}