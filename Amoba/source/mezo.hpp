#ifndef MEZO_HPP
#define MEZO_HPP

#include "widgets.hpp"
#include "mezo.hpp"

enum ertek{
    empty = 0,
    player_one = 1,
    player_two = 2
};

//class MyApplication;

class Mezo : public Widget
{
public:
    Mezo(int x, int y, int sx, int sy, int mezoXPozicio, int mezoYPozicio);
    void setTartalmazoApp(Application* app);
    void handle(genv::event& ev);
    void draw() const;
protected:
    int mezoerteke = 0;
    int mezoXPozicio;
    int mezoYPozicio;
};

#endif // MEZO_HPP
