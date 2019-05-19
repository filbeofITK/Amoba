#ifndef WIDGETS_HPP_INCLUDED
#define WIDGETS_HPP_INCLUDED

#include "graphics.hpp"

class Application;

class Widget {
protected:
    int _x, _y, _size_x, _size_y;
    Application* tartalmazoApp;
public:
    Widget(int x, int y, int sx, int sy);
    virtual bool is_selected(int mouse_x, int mouse_y) const;
    virtual void draw() const = 0;
    virtual void handle(genv::event& ev) = 0;
    virtual void setTartalmazoApp(Application* app);
    virtual void setWidgetAllapot(const int ujAllapot) = 0;
    virtual ~Widget(){}
};

                                                                                                                                                                                                                                                                  //szeretnek pontlevonast kerni a beadandomra mert feltoltottem egy oktatasi segedletet sajat munka helyett :)

#endif // WIDGETS_HPP_INCLUDED
