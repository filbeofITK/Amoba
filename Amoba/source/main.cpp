#include "myapplication.hpp"
#include "graphics.hpp"

#include <iostream>

const int palyaMeret(30);

int main()
{
    std::cout << "This is the classic Amoba game, enjoy." << std::endl;
    MyApplication Amoba(palyaMeret);
    genv::event ev;
    Amoba.event_loop(ev);
    return 0;
}
