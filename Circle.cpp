#include "headers/Circle.h"

Circle::Circle(sf::Vector2f center)
{      
    initVector = center;
    XWindowPos = center.x;
    YWindowPos = center.y;
    InitCircle();
}

Circle::Circle()
{      
    initVector = sf::Vector2f(0.f,0.f);
    XWindowPos = 0.f;
    YWindowPos = 0.f;
    InitCircle();
}


void Circle::InitCircle()
{
    circle = sf::CircleShape(0.f, 30U);
    circle.setPosition(initVector);
    circle.setOrigin(initVector);
    circle.setFillColor(sf::Color::Green);
}

Circle::~Circle()
{
    
}

void Circle::Update(sf::Vector2f radius)
{
    finalVector =  radius;
    relVector.x = finalVector.x - initVector.y; 
    relVector.y = finalVector.y - initVector.y; 
    pixelRadius = relVector.x > relVector.y ? relVector.y : relVector.x;
    circle.setPosition(initVector);
    circle.setOrigin(pixelRadius, pixelRadius);
    circle.setRadius(pixelRadius);
}


void Circle::Render(sf::RenderTarget * target)
{
    target->draw(circle);
}