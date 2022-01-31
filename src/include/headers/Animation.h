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
    void SetInitialDirection(sf::CircleShape &poly, sf::ConvexShape &conv, bool vertical, bool horizontal);
    void SetPosBox(sf::CircleShape &poly, sf::ConvexShape &conv);
    void LeftRight(sf::CircleShape &poly, sf::ConvexShape &conv);
    void UpDown(sf::CircleShape &poly, sf::ConvexShape &conv);
    void Circular(sf::CircleShape &poly, sf::ConvexShape &conv);
    void Box(sf::CircleShape &poly, sf::ConvexShape &conv);        
    float Xpos, Ypos;
    float XScreenSize, YScreenSize;    
    float speed, angSpeed;
    float Xcenter, Ycenter, AnimRadius;
    float XBoxPos, YBoxPos, BoxWidth, BoxHeight;
private:
    FigureAnimation figAnim; 
    float Xdirection, Ydirection, Xdistance, Ydistance;       
};