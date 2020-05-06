//
// Created by WS on 06.05.2020.
//

#ifndef EXAMPLEAPPLICATIONS_COLOR2_H
#define EXAMPLEAPPLICATIONS_COLOR2_H

#include "Color.h"


class Color2 : public Color{
public:
    Color2();
    Color2(uint8_t brightness);
    Color2(uint8_t red, uint8_t green, uint8_t blue);
    static Color pink(){   return Color(255,0,255); };
    static Color yellow(){ return Color(0,255,255); };
    static Color cyan(){   return Color(255,255,0); };
};


#endif //EXAMPLEAPPLICATIONS_COLOR2_H
