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
    Figure(sf::Vector2f center, FigureSelect fig, FigureAnimation anim);
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
//Puntos de construccion
    sf::Vector2f zero;
    sf::Vector2f firstVector;
    sf::Vector2f secondVector;
    sf::Vector2f thirdVector;

    sf::Vector2f relVector;
//variables de animacion
    bool isAnimated;
};