#pragma once

#include <cmath>
#include "SFML/Graphics.hpp"

#include "headers/Point.h"

class Circle
{
public:
    Circle();
    Circle(sf::Vector2f center);
    ~Circle();
    void InitCircle();
    void Update(sf::Vector2f radius);
    void SetShape();
    float GetXPos(){return XWindowPos;};
    float GetYPos(){return YWindowPos;};
    float GetSize(){return pixelRadius;};
    sf::Vector2f GetInitVec(){return initVector;};
    sf::Vector2f GetFinalVec(){return finalVector;};
    void Render(sf::RenderTarget * target);
private:
    float XWindowPos, YWindowPos;
    float pixelRadius;

    int pointCount = 2;
    sf::CircleShape circle;
    sf::Vector2f initVector;
    sf::Vector2f finalVector;
    sf::Vector2f relVector;
};