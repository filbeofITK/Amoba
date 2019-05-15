#include "myapplication.hpp"

#include "mezo.hpp"

MyApplication::MyApplication()
    :
      palya(30,std::vector<int>(30,0))
{
    genv::gout.showmouse(true);

    for(int dx = 0; dx < 30; ++dx){
        for(int dy = 0; dy < 30; ++dy){
            Mezo* ujMezo = new Mezo((dx * 30),(dy * 30),30,30,dx,dy);
            ujMezo->setTartalmazoApp(this);
            registerWidget(ujMezo);
        }
    }
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

void MyApplication::widget_handle(const int X, const int Y){
    if(palya[X][Y] != empty){
        //itt kell lekezelni, visszaállítani hogy továnnra is az adott player jön
        //és displayelni hogy ilyet nem lehet
    }
}
