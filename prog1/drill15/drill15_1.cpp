#include "Simple_window.h"
#include "Graph.h"

#include <iostream>

/* 
g++ drill15_1.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o d15 `fltk-config --ldflags --use-images`
*/

double one(double x) { return 1; }
double slope(double x) { return x / 2; }
double square(double x) { return x * x; }
double sloping_cos(double x) { return cos(x) + slope(x); }

int main()
{

Simple_window win{Point{100, 100}, 600, 600, "Function graphs"};

constexpr int xmax= 600;
constexpr int ymax = 600;

Point origo (xmax/2, ymax/2);

constexpr int notch =20;
constexpr int length = 400;

Axis xa {Axis::x, Point{100, 300}, length, notch, "1 == 20 pixels"};
Axis ya {Axis::y, Point{300, 500}, length, notch, "1 == 20 pixels"};

xa.set_color(Color::red);
ya.set_color(Color::red);
xa.label.set_color(Color::black);
ya.label.set_color(Color::black);
win.attach(xa);
win.attach(ya);
win.wait_for_button();

constexpr int r_min = -10;
constexpr int r_max = 11;
constexpr int x_scale = 20;
constexpr int y_scale = 20;

Function f1 {one, r_min, r_max, origo, length, x_scale, y_scale};

Function f2 {[] (double x) {return x/2;}, r_min, r_max, origo, length, x_scale, y_scale};

Function f3 {square, r_min, r_max, origo, length, x_scale, y_scale};

Function f4 {cos, r_min, r_max, origo, length, x_scale, y_scale};
f4.set_color(Color::blue);

Function f5 {[](double x) { return cos(x) + slope(x); },
            r_min, r_max, origo, length, x_scale, y_scale};

Text slope_text {Point{100,390}, "x/2"};

win.attach(f1);
win.attach(f2);
win.attach(f3);
win.attach(f4);
win.attach(f5);
win.attach(slope_text);

win.wait_for_button();
}