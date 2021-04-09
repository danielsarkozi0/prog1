#include "Lines_window.h"
#include "Graph.h"

/*
g++ drill16.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp Lines_window.cpp -o d16 `fltk-config --ldflags --use-images`
*/

int main()
{
    Lines_window win {Point{100,100}, 1920, 1080, "Lines"};
    
    return gui_main();
}