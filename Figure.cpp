#include "headers/Figure.h"

Figure::Figure(sf::Vector2f center, FigureSelect fig, FigureAnimation anim, float spd, sf::Color col) : Animation(anim, spd)
{   
    zero = sf::Vector2f(0.f,0.f);   
    figType = fig;
    figAnim = anim;
    color = col;
    firstVector = center;
    secondVector = center;
    thirdVector = center;

    XWindowPos = center.x;
    YWindowPos = center.y;


    InitFigure();
}

Figure::Figure() : Animation(noAnim)
{      
    zero = sf::Vector2f(0.f,0.f);
    figType = square;
    figAnim = noAnim;
    firstVector = zero;
    secondVector = zero;
    thirdVector = zero;
    XWindowPos = 0.f;
    YWindowPos = 0.f;
    InitFigure();
}

Figure::Figure(FigureSelect fig, 
FigureAnimation anim, 
float Rcol, float Gcol, float Bcol, 
float xpos, float ypos, float size, float animSpd,
    float xcenter, float ycenter,
    float bxWidth, float bxHeigth) : Animation(anim, animSpd)
{
    zero = sf::Vector2f(0.f,0.f);
    figType = fig;
    figAnim = anim;
    color.r = Rcol; color.g = Gcol; color.b = Bcol;
    firstVector.x = Xpos; firstVector.y = Ypos;
    secondVector = firstVector;
    thirdVector = firstVector;
    Xpos = xpos;
    Ypos = ypos;
    Xcenter = xcenter; Ycenter = ycenter;
    BoxWidth = bxWidth; BoxHeight = bxHeigth;
    InitFigure();
    SetSize(size);
    SetAnimationSpeed(0.f);
    SetAnimParameters();    
    if(anim == leftRight || anim == box)
        SetDirection(false,true);
    else if(anim == upDown)
        SetDirection(true,false);
    
    SetAnimState(anim != noAnim);
    
}

Figure::Figure(FigureSelect fig, 
    FigureAnimation anim, 
    float Rcol, float Gcol, float Bcol, 
    float X1, float X2, float X3,
    float Y1, float Y2, float Y3,
    float animSpd,
    float xcenter, float ycenter,
    float bxWidth, float bxHeigth) : Animation(anim, animSpd)
{
    zero = sf::Vector2f(0.f,0.f);
    figType = fig;
    figAnim = anim;
    color.r = Rcol; color.g = Gcol; color.b = Bcol;
    firstVector.x = X1; firstVector.y = Y1;
    secondVector.x = X2; secondVector.y = Y2;
    thirdVector.x = X3; thirdVector.y = Y3; 
    XWindowPos = X1; Xpos = X1;
    YWindowPos = Y1; Ypos = Y1;   
    Xcenter = xcenter; Ycenter = ycenter;
    BoxWidth = bxWidth; BoxHeight = bxHeigth;
    InitFigure();
    SetAnimationSpeed(0.f);
    SetAnimParameters();    
    if(anim == leftRight || anim == box)
        SetDirection(false,true);
    else if(anim == upDown)
        SetDirection(true,false);
    
    SetAnimState(anim != noAnim);
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

void Figure::SetSize(float size)
{
    polygon.setRadius(size);
    if(figType == square)
        polygon.setRotation(45.f);
}

void Figure::InitPolygon()
{   
    polygon = sf::CircleShape(0.f, vertexCount);
    polygon.setPosition(firstVector);
    polygon.setOrigin(firstVector);
    polygon.setFillColor(color);
}

void Figure::InitConvex()
{
    convex.setPosition(firstVector);
    convex.setOrigin(firstVector);
    convex.setPointCount(pointCount);
    convex.setPoint(0, firstVector);
    convex.setPoint(1, secondVector);
    convex.setPoint(2, thirdVector);
    convex.setFillColor(color);
}

Figure::~Figure()
{
    
}

void Figure::UpdatePolygon(sf::Vector2f radius)
{
    secondVector =  radius;
    relVector.x = abs(secondVector.x - firstVector.y); 
    relVector.y = abs(secondVector.y - firstVector.y); 
    pixelRadius = relVector.x > relVector.y ? relVector.y : relVector.x;
    polygon.setPosition(firstVector);
    polygon.setOrigin(pixelRadius, pixelRadius);
    polygon.setRadius(pixelRadius);
    if(figType == square)
        polygon.setRotation(45.f);
}

void Figure::UpdateConvex(sf::Vector2f next, int pointCount)
{   
    polygon.setPosition(firstVector);
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
void Figure::SetAnimParameters(float xcenter, float ycenter, float radius, float width, float height, float spd)
{
    speed = spd;  
    Xcenter = xcenter;
    Ycenter = ycenter;
    AnimRadius = radius;
    BoxWidth = width;
    BoxHeight = height;    
}
void Figure::SetAnimParameters(sf::RenderTarget* target, float spd, float MoveScale)
{
    speed = spd;  
    Xcenter = target->getSize().x;
    Ycenter = target->getSize().y;
    AnimRadius = target->getSize().y * MoveScale;
    BoxWidth = target->getSize().x * MoveScale;
    BoxHeight = target->getSize().y * MoveScale;    
}

void Figure::SetDirection(bool vertical, bool horizontal)
{
    SetInitialDirection(polygon, convex, vertical, horizontal);
}

void Figure::SetBoxPosition()
{
    SetPosBox(polygon, convex);
}

void Figure::AnimateFigure()
{
    switch (figAnim)
    {
    case leftRight:        
        LeftRight(polygon,convex);
        break;
    case upDown:        
        UpDown(polygon, convex);
        break; 
    case circular:        
        Circular(polygon, convex);
        break;    
    case box:
        Box(polygon, convex);
        break;    
    }
}

void Figure::Render(sf::RenderTarget * target)
{
    if(figType == triangle)
        target->draw(convex);
    else
        target->draw(polygon);
}