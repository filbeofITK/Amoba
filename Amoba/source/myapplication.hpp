#ifndef MYAPPLICATION_HPP
#define MYAPPLICATION_HPP

#include "application.hpp"
#include "widgets.hpp"
#include <vector>

class MyApplication : public Application
{
public:
    MyApplication();
    void event_loop(genv::event& ev);
    void action(const int miLegyen);
    void widget_handle(const int X, const int Y);
private:
    std::vector<std::vector<int>> palya;
};

#endif // MYAPPLICATION_HPP
