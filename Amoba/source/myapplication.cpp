    #include "myapplication.hpp"


MyApplication::MyApplication(const int palyaMeret)
    :
      palya(palyaMeret,std::vector<int>(palyaMeret,0)),
      current_player(1),
      teljesPalyaMeret(palyaMeret* palyaMeret),
      mezoSzam(palyaMeret)
{
    genv::gout.open((palyaMeret * palyaMeret),(palyaMeret * palyaMeret));

    genv::gout.showmouse(true);

    for(int dx = 0; dx < palyaMeret; ++dx){
        for(int dy = 0; dy < palyaMeret; ++dy){
            Mezo* ujMezo = new Mezo((dx * palyaMeret),(dy * palyaMeret),palyaMeret,palyaMeret,dx,dy);
            ujMezo->setTartalmazoApp(this);
            registerWidget(ujMezo);
        }
    }
}

void MyApplication::event_loop(genv::event &ev){

    int focus = -1;

    while(genv::gin >> ev ) {
        if(!gameEnded){
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

            if(gameEnded){
                endGame();
                focus = -1;
            }
        }else{
            if(genv::ev_key && ev.keycode == genv::key_enter){
                resetGame();
            }
        }
        genv::gout << genv::refresh;
    }//while
}

void MyApplication::action(const int miLegyen){

}

void MyApplication::resetGame(){
    for (auto& w : widgetek){
        w->setWidgetAllapot(0);
    }
    palya =std::vector<std::vector<int>>(mezoSzam,std::vector<int>(mezoSzam,0));
    /*
    for (Widget * w : widgetek) {
        w->draw();
    }*/
    gameEnded = false;
}

int MyApplication::egyIranybaKereso(const int iranyX, const int iranyY, const int pozicioX, const int pozicioY) const{
    int jelenlegiX = pozicioX + iranyX;
    int jelenlegiY = pozicioY + iranyY;
    int pontszam(0);
    while (true) {
        if(( palya[0].size() >= jelenlegiY)
           && (palya[0].size() >= jelenlegiX)
           && (0 < jelenlegiY)
           && (0 < jelenlegiX)
           && current_player == palya[jelenlegiX][jelenlegiY]){
            ++pontszam;
            jelenlegiX += iranyX;
            jelenlegiY += iranyY;
        }else{
            break;
        }
    }//while

    return pontszam;
}


bool MyApplication::amobaKereso(const int X, const int Y){

    //vizszintesen van e 5
    int pontszam(1);
    pontszam += egyIranybaKereso(-1,0,X,Y);
    pontszam += egyIranybaKereso(1,0,X,Y);
    if(5 <= pontszam){
        return true;
    }

    //fuggolegesen van e ot
    pontszam = 1;
    pontszam += egyIranybaKereso(0,-1,X,Y);
    pontszam += egyIranybaKereso(0,1,X,Y);
    if(5 <= pontszam){
        return true;
    }

    //balrol-jobbra ferden van e 5
    pontszam = 1;
    pontszam += egyIranybaKereso(-1,-1,X,Y);
    pontszam += egyIranybaKereso(1,1,X,Y);
    if(5 <= pontszam){
        return true;
    }

    //jobbrol-balra ferden van e ot

    pontszam = 1;
    pontszam += egyIranybaKereso(1,-1,X,Y);
    pontszam += egyIranybaKereso(-1,1,X,Y);
    if(5 <= pontszam){
        return true;
    }
    return false;
}


void MyApplication::endGame(){
    //felenel legyen, kozepen, mindig meg nincs kesz
    const int pozicio = (teljesPalyaMeret / 2);
    const int boxXMeret = (teljesPalyaMeret / 10);
    const int boxYMeret = (teljesPalyaMeret / 20);
    genv::gout << genv::move_to(pozicio - boxXMeret,pozicio - boxYMeret)
               << genv::color(255,0,0)
               << genv::box(boxXMeret,boxYMeret)
               << genv::color(255,255,255)
               << genv::move_to(pozicio - boxXMeret + 2,pozicio - boxYMeret + 2)
               << genv::box(boxXMeret - 4, boxYMeret - 4)
               << genv::color(0,0,0)
               << genv::move_to(pozicio - boxXMeret + 5,pozicio - boxYMeret + 15);

    if(player_two == current_player){
        genv::gout << genv::text("Player one \n wins.");
    }else{
        genv::gout << genv::text("Player two \n wins.");
    }
    current_player = player_one;
}


int MyApplication::widget_handle(const int X, const int Y){
    if(empty == palya[X][Y]){
        palya[X][Y] = current_player;

        if(amobaKereso(X,Y)){
            gameEnded = true;
        }

        if(player_one == current_player){
            current_player = player_two;
        }else {
            current_player = player_one;
        }
    }
    return current_player;
}
