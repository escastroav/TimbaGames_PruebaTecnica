#include "headers/Square.h"

Square::Square(sf::Vector2f center)
{      
    initVector = center;
    XWindowPos = center.x;
    YWindowPos = center.y;
    InitSquare();
}

Square::Square()
{      
    initVector = sf::Vector2f(0.f,0.f);
    XWindowPos = 0.f;
    YWindowPos = 0.f;
    InitSquare();
}


void Square::InitSquare()
{
    square = sf::CircleShape(0.f,4);
    square.setPosition(initVector);
    square.setOrigin(initVector);
    square.setFillColor(sf::Color::Red);
}

Square::~Square()
{
    
}

void Square::Update(sf::Vector2f radius)
{
    finalVector =  radius;
    relVector.x = abs(finalVector.x - initVector.y); 
    relVector.y = abs(finalVector.y - initVector.y); 
    pixelSize = relVector.x > relVector.y ? relVector.y : relVector.x;
    //pixelSize = sqrt(relVector.x*relVector.x + relVector.y*relVector.y);
    square.setPosition(initVector);
    square.setOrigin(pixelSize, pixelSize);
    square.setRadius(pixelSize);
    square.setRotation(45.f);
}


void Square::Render(sf::RenderTarget * target)
{
    target->draw(square);
}