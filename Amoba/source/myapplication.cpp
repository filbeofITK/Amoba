#include "myapplication.hpp"



MyApplication::MyApplication()
{

}

void MyApplication::event_loop(genv::event &ev){

    int focus = -1;

    while(genv::gin >> ev ) {
        if (ev.type == genv::ev_mouse && ev.button == genv::btn_left) {
            for (size_t i = 0; i < widgetek.size(); i++) {
                if (widgetek[i]->is_selected(ev.pos_x, ev.pos_y)) {
                        focus = i;
                }
            }
        }
        if (focus!=-1) {
            widgetek[focus]->handle(ev);
        }
        for (Widget * w : widgetek) {
            w->draw();
        }
        if((ev.type == genv::ev_key) && (ev.button == genv::key_enter)){
            action(genv::key_enter);
        }
        genv::gout << genv::refresh;
    }
}

void MyApplication::action(const int miLegyen){

}
