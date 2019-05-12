#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "graphics.hpp"

#include <vector>

class Widget;

class Application
{
public:
    Application();
    virtual void event_loop(genv::event& ev) =0;
    virtual void registerWidget(Widget* w);
    virtual void action(const int miLegyen) = 0;
    virtual ~Application(){}
protected:
    std::vector<Widget*> widgetek;
};

#endif // APPLICATION_HPP
