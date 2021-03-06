#pragma once

#include <cmath>
#include "SFML/Graphics.hpp"

#include "headers/Animation.h"

enum FigureSelect {square = 0, triangle = 1, circle = 2, hexagon = 3};

class Figure : public Animation
{
public:
//Constructores
    Figure();
    Figure(sf::Vector2f center, FigureSelect fig, FigureAnimation anim, float spd, sf::Color col = sf::Color::Green);
    Figure(FigureSelect fig, 
    FigureAnimation anim, 
    float Rcol, float Gcol, float Bcol, 
    float xpos, float ypos, 
    float size, float animSpd,
    float xcenter, float ycenter,
    float bxWidth, float bxHeigth);
    Figure(FigureSelect fig, 
    FigureAnimation anim, 
    float Rcol, float Gcol, float Bcol, 
    float X1, float X2, float X3,
    float Y1, float Y2, float Y3,
    float animSpd,
    float xcenter, float ycenter,
    float bxWidth, float bxHeigth);
//Destructores
    ~Figure();
//Inicializacion
    void InitFigure();
    void InitPolygon();
    void InitConvex();
//Update logico
    void UpdatePolygon(sf::Vector2f radius);
    void UpdateConvex(sf::Vector2f next, int pointCount);
//Animar
    void SetSize(float size);
    void SetAnimParameters(float xcenter = 400.f, float ycenter = 300.f, float radius = 200.f, float width = 400.f, float height = 300.f, float spd = 10.f);
    void SetAnimParameters(sf::RenderTarget* target, float spd = 100.f, float MoveScale = 0.5f);
    void SetDirection(bool vertical, bool horizontal);
    void SetBoxPosition();
    void AnimateFigure();    
//Update renderizado
    void Render(sf::RenderTarget * target);
//Accesores
    FigureSelect GetFigType(){return figType;};
    FigureAnimation GetFigAnim(){return figAnim;};
    float GetXPos(){return XWindowPos;};
    float GetYPos(){return YWindowPos;};
    float GetSize(){return pixelRadius;};
    sf::Vector2f GetFirstVec(){return firstVector;};
    sf::Vector2f GetSecondVec(){return secondVector;};
    sf::Vector2f GetThirdVec(){return thirdVector;};
    sf::Vector2f GetRelVec(){return relVector;};
    bool IsAnimated(){return isAnimated;};
//Modificadores
    void SetFigType(FigureSelect fig){figType = fig;};
    void SetAnimState(bool state){isAnimated = state;};
private:
//Propiedades
    FigureSelect figType;
    FigureAnimation figAnim;
    float XWindowPos, YWindowPos;
    float pixelRadius;
//Figura (render)
    int pointCount = 2;
    unsigned int vertexCount;
    sf::CircleShape polygon;
    sf::ConvexShape convex;
    sf::Color color;
//Puntos de construccion
    sf::Vector2f zero;
    sf::Vector2f firstVector;
    sf::Vector2f secondVector;
    sf::Vector2f thirdVector;

    sf::Vector2f relVector;
//variables de animacion
    bool isAnimated;
};