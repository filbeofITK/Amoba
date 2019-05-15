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

void Mezo::draw() const{

    switch (mezoerteke) {
    default:
        genv::gout << genv::color(0,0,0) << genv::box(_size_x,_size_y)
                << genv::color(255,255,255) << genv::move_to(_x,_y) << genv::box((_size_x - 2),(_size_y - 2));
        break;
    case player_one:
        genv::gout << genv::color(0,0,0) << genv::box(_size_x,_size_y)
                   << genv::color(255,255,255) //feher
                   << genv::move_to(_x,_y) << genv::box(_size_x,_size_y) //alap doboz
                   << genv::color(0,0,0) //fekete
                   << genv::move_to(_x,_y) << genv::line_to( (_x + _size_x), (_y + _size_y)) //x
                   << genv::move_to((_x + _size_x), _y) << genv::line_to(_x, (_y + _size_y));
        break;
    case player_two:
        const int r = ((_size_x / 2) - 2);
        genv::gout << genv::move_to(_x,_y) << genv::color(0,0,0) << genv::box(_size_x,_size_y);
        for(int k = (_y + 2); k < (_size_y + _y); ++k){
            int v = _y + 1 + r;
            for(int i = _x; i < (_size_x + _x); ++i){
                const int u = _x + 1 + r;
                genv::gout << genv::move_to(i,k) ;

                if(pow(((i - u)+(k - v)),2) == r ){
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
    if(is_selected(ev.pos_x,ev.pos_y)){
        tartalmazoApp->widget_handle(mezoXPozicio,mezoYPozicio);
    }
}
