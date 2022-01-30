#pragma once

#include <cmath>
#include "SFML/Graphics.hpp"

#include "headers/Point.h"

class Square
{
public:
    Square();
    Square(sf::Vector2f center);
    ~Square();
    void InitSquare();
    void Update(sf::Vector2f radius);
    void SetShape();
    float GetXPos(){return XWindowPos;};
    float GetYPos(){return YWindowPos;};
    float GetSize(){return pixelSize;};
    sf::Vector2f GetInitVec(){return initVector;};
    sf::Vector2f GetFinalVec(){return finalVector;};
    void Render(sf::RenderTarget * target);

private:
    float XWindowPos, YWindowPos;
    float pixelSize;

    int pointCount = 2;
    sf::CircleShape square;
    sf::Vector2f initVector;
    sf::Vector2f finalVector;
    sf::Vector2f relVector;
};