#include "headers/Triangle.h"

/*Triangle::Triangle()
{
    zero = sf::Vector2f(0.f, 0.f);
    firstVector = zero;
    secondVector = zero;
    thirdVector = zero;
    InitTriangle();
}
*/
Triangle::Triangle(sf::Vector2f first)
{
    firstVector = first;
    secondVector = first;
    thirdVector = first;
    InitTriangle();
}   

void Triangle::InitTriangle()
{
    triangle.setPointCount(3);
    triangle.setPoint(0, firstVector);
    triangle.setPoint(1, firstVector);
    triangle.setPoint(2, firstVector);
    triangle.setFillColor(sf::Color::Yellow);
    vectorCount=1;
}

void Triangle::SetPoints()
{
    triangle.setPoint(0, firstVector);
    triangle.setPoint(1, secondVector);
    triangle.setPoint(2, thirdVector);    
}

void Triangle::Update(sf::Vector2f next, int pointCount)
{   
    if(pointCount == 1)
    {
        secondVector = next;    
        triangle.setPoint(1, secondVector);  
        vectorCount = 2;          
    }
    else if(pointCount == 2);
    {
        thirdVector = next;        
        triangle.setPoint(2, thirdVector);
        vectorCount = 3;        
    }

}

void Triangle::Render(sf::RenderTarget* target)
{
    target->draw(triangle);
}

Triangle::~Triangle()
{

}

