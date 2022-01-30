#include "headers/Figure.h"

Figure::Figure(sf::Vector2f center, FigureSelect fig)
{      
    figType = fig;
    firstVector = center;
    secondVector = center;
    thirdVector = center;

    XWindowPos = center.x;
    YWindowPos = center.y;
    InitFigure();
}

Figure::Figure()
{      
    zero = sf::Vector2f(0.f,0.f);
    figType = square;
    firstVector = zero;
    secondVector = zero;
    thirdVector = zero;
    XWindowPos = 0.f;
    YWindowPos = 0.f;
    InitFigure();
}


void Figure::InitFigure()
{
    switch (figType)
    {
    case square:
        vertexCount = 4U;
        pointCount = 2;
        break;
    case circle:
        vertexCount = 30U;
        pointCount = 2;
        break;
    case hexagon:
        vertexCount = 6U;
        pointCount = 2;
        break;
    case triangle:
        vertexCount = 3U;
        pointCount = 3;
        break;    
    } 
    if(figType == triangle)
        InitConvex();   
    else
        InitPolygon();
}

void Figure::InitPolygon()
{   
    polygon = sf::CircleShape(0.f, vertexCount);
    polygon.setPosition(firstVector);
    polygon.setOrigin(firstVector);
    polygon.setFillColor(sf::Color::Green);
}

void Figure::InitConvex()
{
    convex.setPointCount(pointCount);
    convex.setPoint(0, firstVector);
    convex.setPoint(1, secondVector);
    convex.setPoint(2, thirdVector);
    convex.setFillColor(sf::Color::Green);
}

Figure::~Figure()
{
    
}

void Figure::UpdatePolygon(sf::Vector2f radius)
{
    secondVector =  radius;
    relVector.x = secondVector.x - firstVector.y; 
    relVector.y = secondVector.y - firstVector.y; 
    pixelRadius = relVector.x > relVector.y ? relVector.y : relVector.x;
    polygon.setPosition(firstVector);
    polygon.setOrigin(pixelRadius, pixelRadius);
    polygon.setRadius(pixelRadius);
    if(figType == square)
        polygon.setRotation(45.f);
}

void Figure::UpdateConvex(sf::Vector2f next, int pointCount)
{   
    if(pointCount == 1)
    {
        secondVector = next;    
        convex.setPoint(1, secondVector);                    
    }
    else if(pointCount == 2);
    {
        thirdVector = next; 
        convex.setPoint(2, thirdVector);    
    }

}

void Figure::Render(sf::RenderTarget * target)
{
    if(figType == triangle)
        target->draw(convex);
    else
        target->draw(polygon);
}