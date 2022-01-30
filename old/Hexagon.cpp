#include "headers/Hexagon.h"

Hexagon::Hexagon(sf::Vector2f center)
{      
    initVector = center;
    XWindowPos = center.x;
    YWindowPos = center.y;
    InitHexagon();
}

Hexagon::Hexagon()
{      
    initVector = sf::Vector2f(0.f,0.f);
    XWindowPos = 0.f;
    YWindowPos = 0.f;
    InitHexagon();
}


void Hexagon::InitHexagon()
{
    hexagon = sf::CircleShape(0.f, 6U);
    hexagon.setPosition(initVector);
    hexagon.setOrigin(initVector);
    hexagon.setFillColor(sf::Color::Cyan);
}

Hexagon::~Hexagon()
{
    
}

void Hexagon::Update(sf::Vector2f radius)
{
    finalVector =  radius;
    relVector.x = finalVector.x - initVector.y; 
    relVector.y = finalVector.y - initVector.y; 
    pixelRadius = relVector.x > relVector.y ? relVector.y : relVector.x;
    hexagon.setPosition(initVector);
    hexagon.setOrigin(pixelRadius, pixelRadius);
    hexagon.setRadius(pixelRadius);
}


void Hexagon::Render(sf::RenderTarget * target)
{
    target->draw(hexagon);
}