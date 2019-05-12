#ifndef MYAPPLICATION_HPP
#define MYAPPLICATION_HPP

#include "application.hpp"
#include "widgets.hpp"

class MyApplication : public Application
{
public:
    MyApplication();
    void event_loop(genv::event& ev);
    void action(const int miLegyen);
};

#endif // MYAPPLICATION_HPP
