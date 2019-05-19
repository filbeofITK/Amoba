#ifndef MEZO_HPP
#define MEZO_HPP

#include "widgets.hpp"
#include "mezo.hpp"

#include <cmath>

//class MyApplication;

class Mezo : public Widget
{
public:
    Mezo(int x, int y, int sx, int sy, int mezoXPozicio, int mezoYPozicio);
    void setTartalmazoApp(Application* app);
    void handle(genv::event& ev);
    void draw() const;
    void setWidgetAllapot(const int ujAllapot);
protected:
    int mezoerteke = 0;
    int mezoXPozicio;
    int mezoYPozicio;
};

#endif // MEZO_HPP
