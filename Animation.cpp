#include "headers/Animation.h"

Animation::Animation(FigureAnimation anim)
{
    figAnim = anim;
    Xdirection = 0.f;
    Ydirection = 0.f;
    Xdistance = 0.f;
    Ydistance = 0.f;
    speed = 1.f;
    angSpeed = M_PI / 60.f;
    Xpos = Ypos = 10.f;
    XScreenSize = 800.f;
    YScreenSize = 600.f;
    Xcenter = 400.f;
    Ycenter = 300.f;
    AnimRadius = 100.f;
    XBoxPos = YBoxPos = 10.f;
    BoxWidth = BoxHeight = 100.f;
}

Animation::~Animation()
{

}

void Animation::SetPosBox(sf::CircleShape &poly, sf::ConvexShape &conv)
{
    XBoxPos = poly.getPosition().x - speed;
    YBoxPos = poly.getPosition().y - speed;
}

void Animation::SetInitialDirection(sf::CircleShape &poly, sf::ConvexShape &conv, bool vertical, bool horizontal)
{
    float Xpos = poly.getPosition().x;
    float Ypos = poly.getPosition().y;
    if(Xpos < XScreenSize * 0.5f && Ypos < YScreenSize * 0.5f)
    {
        Xdirection = horizontal ? 1.f : 0.f;
        Ydirection = vertical ? 1.f : 0.f;    
    }
    else if(Xpos > XScreenSize * 0.5f && Ypos < YScreenSize * 0.5f)
    {
        Xdirection = horizontal ? -1.f : 0.f;
        Ydirection = vertical ? 1.f : 0.f;    
    }
    else if(Xpos > XScreenSize * 0.5f && Ypos > YScreenSize * 0.5f)
    {
        Xdirection = horizontal ? -1.f : 0.f;
        Ydirection = vertical ? -1.f : 0.f;    
    }
    else if(Xpos < XScreenSize * 0.5f && Ypos > YScreenSize * 0.5f)
    {
        Xdirection = horizontal ? 1.f : 0.f;
        Ydirection = vertical ? -1.f : 0.f;    
    }
}

void Animation::LeftRight(sf::CircleShape &poly, sf::ConvexShape &conv)
{   
    bool leftBound = poly.getPosition().x < 0.f;
    bool rightBound = poly.getPosition().x > XScreenSize;    

    if(leftBound)
    {
        poly.setPosition(speed, poly.getPosition().y);
        conv.setPosition(speed, conv.getPosition().y);
        Xdirection = 1.f;
    }
    if(rightBound)
    {
        poly.setPosition(2.f * (XScreenSize - speed) - poly.getPosition().x, poly.getPosition().y);
        conv.setPosition(2.f * (XScreenSize - speed) - conv.getPosition().x, conv.getPosition().y);
        Xdirection = -1.f;
    }
    poly.move(speed * Xdirection, 0.f);
    conv.move(speed * Xdirection, 0.f);
    //std::cout << poly.getPosition().x << ", speed=" << speed <<  "\n";
}
void Animation::UpDown(sf::CircleShape &poly, sf::ConvexShape &conv)
{
    bool upBound = poly.getPosition().y < 0.f;
    bool downBound = poly.getPosition().y > YScreenSize;    

    if(upBound)
    {
        poly.setPosition(poly.getPosition().x, speed);
        conv.setPosition(conv.getPosition().x, speed);
        Ydirection = 1.f;
    }
    if(downBound)
    {
        poly.setPosition(poly.getPosition().x, 2.f * (YScreenSize - speed) - poly.getPosition().y);
        conv.setPosition(conv.getPosition().x, 2.f * (YScreenSize - speed) - conv.getPosition().y);
        Ydirection = -1.f;
    }
    poly.move(0.f, speed * Ydirection);
    conv.move(0.f, speed * Ydirection);
    //std::cout << poly.getPosition().y << ", speed=" << speed  << "\n";
}
void Animation::Circular(sf::CircleShape &poly, sf::ConvexShape &conv)
{
    float Xcoor = poly.getPosition().x - Xcenter;
    float Ycoor = poly.getPosition().y - Ycenter;
    float angle = atan2(Ycoor, Xcoor);
    float cos_a = cos(angle);
    float sin_a = sin(angle);
    float cos_da_1 = cos(angSpeed) - 1.f;
    float sin_da = sin(angSpeed);
    float moveX = (cos_a * cos_da_1 - sin_a * sin_da) * AnimRadius;
    float moveY = (sin_a * cos_da_1 + cos_a * sin_da) * AnimRadius;

    poly.move(moveX, moveY);
    conv.move(moveX, moveY);
}

void Animation::Box(sf::CircleShape &poly, sf::ConvexShape &conv)
{
    
    bool leftBound = poly.getPosition().x < XBoxPos;
    bool rightBound = poly.getPosition().x > XBoxPos + BoxWidth; 

    bool upBound = poly.getPosition().y < YBoxPos;
    bool downBound = poly.getPosition().y > YBoxPos + BoxHeight; 

    if(leftBound)
    {
        poly.setPosition(XBoxPos + speed, poly.getPosition().y);
        conv.setPosition(XBoxPos + speed, conv.getPosition().y);
        Xdirection = 0.f;
        Ydirection = -1.f;
    }
    if(rightBound)
    {
        poly.setPosition(2.f*(XBoxPos + BoxWidth - speed ) - poly.getPosition().x, poly.getPosition().y);
        conv.setPosition(2.f*(XBoxPos + BoxWidth - speed ) - poly.getPosition().x, conv.getPosition().y);
        Xdirection = 0.f;
        Ydirection = 1.f;
    }
    if(upBound)
    {
        poly.setPosition(poly.getPosition().x, YBoxPos + speed);
        conv.setPosition(conv.getPosition().x, YBoxPos + speed);
        Xdirection = 1.f;
        Ydirection = 0.f;
    }
    if(downBound)
    {
        poly.setPosition(poly.getPosition().x, 2.f*(YBoxPos + BoxHeight - speed) - poly.getPosition().y);
        conv.setPosition(conv.getPosition().x, 2.f*(YBoxPos + BoxHeight - speed) - conv.getPosition().y);
        Xdirection = -1.f;
        Ydirection = 0.f;
    }

    poly.move(speed * Xdirection, speed * Ydirection);
    conv.move(speed * Xdirection, speed * Ydirection);
    
}

