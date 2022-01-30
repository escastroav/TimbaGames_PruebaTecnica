#include "headers/Point.h"

Point::Point(float x, float y)
{
    InitPoint(x, y);
}

void Point::InitPoint(float x, float y)
{    
    xPos = x;
    yPos = y;

    this->renderPoint.setPosition(x, y);
    this->renderPoint.setRadius(radius);
    this->renderPoint.setFillColor(sf::Color::White);
    this->renderPoint.move(sf::Vector2f(-1.f * radius, -1.f * radius));
}

sf::Vector2f Point::GetPosition()
{
    sf::Vector2f position(xPos, yPos);
    return position;
}

Point::~Point()
{

}

void Point::Render(sf::RenderTarget* target)
{
    target->draw(this->renderPoint);
}

void Point::Erease(sf::Color bkColor)
{
    renderPoint.setFillColor(bkColor);
}