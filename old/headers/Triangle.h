#pragma once

#include <cmath>
#include "SFML/Graphics.hpp"

#include "headers/Point.h"

class Triangle
{
public:
    //Triangle();
    Triangle(sf::Vector2f first);    
    ~Triangle();
    void InitTriangle();
    void SetPoints();
    void Update(sf::Vector2f next, int pointCount);
    sf::Vector2f GetFirst(){return firstVector;};
    sf::Vector2f GetSecond(){return secondVector;};
    sf::Vector2f GetThird(){return thirdVector;};
    int GetVectorCount(){return vectorCount;};
    void Render(sf::RenderTarget* target);
private:
    sf::ConvexShape triangle;
    sf::Vector2f firstVector;
    sf::Vector2f secondVector;
    sf::Vector2f thirdVector;

    sf::Vector2f zero;
    int vectorCount;
};