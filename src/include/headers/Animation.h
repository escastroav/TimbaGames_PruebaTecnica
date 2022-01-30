#pragma once

#include <cmath>
#include <iostream>
#include "SFML/Graphics.hpp"

enum FigureAnimation {noAnim = 0, leftRight = 1, upDown = 2, circular = 3, box = 4};

class Animation
{
public:
    Animation(FigureAnimation anim);
    ~Animation();
    void LeftRight(sf::CircleShape &poly, sf::ConvexShape &conv);
    void UpDown(sf::CircleShape &poly, sf::ConvexShape &conv);
    void Circular(sf::CircleShape &poly, sf::ConvexShape &conv);
    void Box(sf::CircleShape &poly, sf::ConvexShape &conv);        

    float Xpos, Ypos;
    float XScreenSize, YScreensize;    
    float speed;
    float Xcenter, Ycenter, AnimRadius;
    float XBoxPos, YBoxPos, BoxWidth, BoxHeight;
private:
    FigureAnimation figAnim; 
    float direction;       
};