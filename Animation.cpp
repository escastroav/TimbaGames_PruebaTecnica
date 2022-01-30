#include "headers/Animation.h"

Animation::Animation(FigureAnimation anim)
{
    figAnim = anim;
    direction = 1.f;
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
        direction = 1.f;
    }
    if(downBound)
    {
        poly.setPosition(poly.getPosition().x, 2.f * (YScreenSize - speed) - poly.getPosition().y);
        conv.setPosition(conv.getPosition().x, 2.f * (YScreenSize - speed) - conv.getPosition().y);
        direction = -1.f;
    }
    poly.move(0.f, speed * direction);
    conv.move(0.f, speed * direction);
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

}

