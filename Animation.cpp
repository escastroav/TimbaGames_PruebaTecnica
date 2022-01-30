#include "headers/Animation.h"

Animation::Animation(FigureAnimation anim)
{
    figAnim = anim;
    direction = 1.f;
    speed = 1.f;
    Xpos = Ypos = 10.f;
    XScreenSize = 800.f;
    YScreensize = 600.f;
    Xcenter = 400.f;
    Ycenter = 300.f;
    AnimRadius = 100.f;
    XBoxPos = YBoxPos = 10.f;
    BoxWidth = BoxHeight = 100.f;
}

Animation::~Animation()
{

}

void Animation::LeftRight(sf::CircleShape &poly, sf::ConvexShape &conv)
{   
    bool leftBound = poly.getPosition().x < 0.f;
    bool rightBound = poly.getPosition().x > XScreenSize;    

    if(leftBound)
    {
        poly.setPosition(speed, poly.getPosition().y);
        conv.setPosition(speed, conv.getPosition().y);
        direction = 1.f;
    }
    if(rightBound)
    {
        poly.setPosition(2.f * (XScreenSize - speed) - poly.getPosition().x, poly.getPosition().y);
        conv.setPosition(2.f * (XScreenSize - speed) - conv.getPosition().x, conv.getPosition().y);
        direction = -1.f;
    }
    poly.move(speed * direction, 0.f);
    conv.move(speed * direction, 0.f);
    std::cout << poly.getPosition().x << ", speed=" << speed <<  "\n";
}
void Animation::UpDown(sf::CircleShape &poly, sf::ConvexShape &conv)
{
    if(poly.getPosition().x >= 0.f && poly.getPosition().x <= XScreenSize)
        poly.move(speed, 0.f); 
    if(conv.getPosition().x >= 0.f && conv.getPosition().x <= XScreenSize)
        conv.move(speed, 0.f);
    std::cout << poly.getPosition().y << ", speed=" << speed  << "\n";
}
void Animation::Circular(sf::CircleShape &poly, sf::ConvexShape &conv)
{
    
}

void Animation::Box(sf::CircleShape &poly, sf::ConvexShape &conv)
{

}

