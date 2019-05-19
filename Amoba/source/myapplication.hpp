#ifndef MYAPPLICATION_HPP
#define MYAPPLICATION_HPP

#include "application.hpp"
#include "mezo.hpp"
#include "widgets.hpp"

#include <vector>

enum ertek{
    empty = 0,
    player_one = 1,
    player_two = 2
};

class MyApplication : public Application
{
public:
    MyApplication(const int palyaMeret);
    void event_loop(genv::event& ev);
    void action(const int miLegyen);
    int widget_handle(const int X, const int Y);
    bool amobaKereso(const int X, const int Y);
    void endGame();
    void resetGame();
    int egyIranybaKereso(const int iranyX, const int iranyY, const int pozicioX, const int pozicioY) const;
private:
    std::vector<std::vector<int>> palya;
    int current_player;
    bool gameEnded = false;
    const int teljesPalyaMeret;
    const int mezoSzam;
};

#endif // MYAPPLICATION_HPP
