#pragma once

#include <cmath>
#include "SFML/Graphics.hpp"

enum FigureSelect {square = 0, triangle = 1, circle = 2, hexagon = 3};

class Figure
{
public:
    Figure();
    Figure(sf::Vector2f center, FigureSelect fig);
    ~Figure();
    void InitFigure();
    void InitPolygon();
    void InitConvex();
    void UpdatePolygon(sf::Vector2f radius);
    void UpdateConvex(sf::Vector2f next, int pointCount);
    void Render(sf::RenderTarget * target);
    float GetXPos(){return XWindowPos;};
    float GetYPos(){return YWindowPos;};
    float GetSize(){return pixelRadius;};
    sf::Vector2f GetFirstVec(){return firstVector;};
    sf::Vector2f GetSecondVec(){return secondVector;};
    sf::Vector2f GetThirdVec(){return thirdVector;};
    sf::Vector2f GetRelVec(){return relVector;};
    FigureSelect figType;
private:
    float XWindowPos, YWindowPos;
    float pixelRadius;

    int pointCount = 2;
    unsigned int vertexCount;
    sf::CircleShape polygon;
    sf::ConvexShape convex;

    sf::Vector2f zero;
    sf::Vector2f firstVector;
    sf::Vector2f secondVector;
    sf::Vector2f thirdVector;

    sf::Vector2f relVector;
};