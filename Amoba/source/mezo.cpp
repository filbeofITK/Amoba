#include "mezo.hpp"
#include "myapplication.hpp"

#include <cmath>

Mezo::Mezo(int x, int y, int sx, int sy, int mezoXPozicio, int mezoYPozicio)
    :
      Widget(x,y,sx,sy),
      mezoXPozicio(mezoXPozicio),
      mezoYPozicio(mezoYPozicio)
{

}

void Mezo::setTartalmazoApp(Application *app){
    tartalmazoApp = app;
}

void Mezo::setWidgetAllapot(const int ujAllapot){
    mezoerteke = ujAllapot;
}

void Mezo::draw() const{
    genv::gout << genv::move_to(_x,_y);
    switch (mezoerteke) {
    default:
        genv::gout << genv::color(0,0,0) << genv::box(_size_x,_size_y)
                << genv::color(255,255,255) << genv::move_to(_x,_y) << genv::box((_size_x - 2),(_size_y - 2));
        break;
    case player_one:
        genv::gout << genv::color(0,0,0) << genv::box(_size_x,_size_y)
                   << genv::color(255,255,255) //feher
                   << genv::move_to((_x),(_y)) << genv::box((_size_x - 2),(_size_y - 2)) //alap doboz
                   << genv::color(0,0,0) //fekete
                   << genv::move_to(_x,_y) << genv::line_to( (_x + _size_x), (_y + _size_y)) //x
                   << genv::move_to((_x + _size_x - 2), _y) << genv::line_to(_x, (_y + _size_y - 2));
        break;
    case player_two:
        const float r = ((_size_x / 2) - 2);
        genv::gout << genv::move_to(_x,_y) << genv::color(0,0,0) << genv::box(_size_x,_size_y);
        for(int k = _y; k < (_size_y + _y - 2); ++k){
            const float v = _y  + r;
            for(int i = _x; i < (_size_x + _x - 2); ++i){
                const float u = _x  + r;
                genv::gout << genv::move_to(i,k) ;
                //ezen meg dolgozni kell, hogy szep kor legyen
                if(std::abs( pow((i - u),2) + pow((k - v),2) - pow(r,2)) < 20){
                    genv::gout << genv::color(0,0,0) << genv::dot;
                }else{
                    genv::gout << genv::color(255,255,255) << genv::dot;
                }
            }//for
        }//for
        break;
    }
}

void Mezo::handle(genv::event &ev){
    if(empty == mezoerteke){
        mezoerteke = tartalmazoApp->widget_handle(mezoXPozicio,mezoYPozicio);
    }
}
