#pragma once

#include <cmath>
#include "SFML/Graphics.hpp"

class Point
{
public:
    Point(float x, float y);
    ~Point();
    void InitPoint(float x, float y);
    void Render(sf::RenderTarget* target);
    void Erease(sf::Color bkColor);
    sf::Vector2f GetPosition();
private:
    int xPos, yPos, radius = 5.f;
    sf::CircleShape renderPoint;
};