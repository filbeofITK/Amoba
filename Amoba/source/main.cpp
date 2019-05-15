#include "myapplication.hpp"
#include "widgets.hpp"
#include "graphics.hpp"

#include <iostream>


int main()
{
    std::cout << "This is the classic Amoba game, enjoy." << std::endl;
    MyApplication Amoba;
    genv::gout.open(900,900);
    genv::event ev;
    Amoba.event_loop(ev);
    return 0;
}
