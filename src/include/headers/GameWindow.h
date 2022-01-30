#pragma once

#include <locale>
#include <vector>
#include <iostream>
#include "SFML/Graphics.hpp"

#include "headers/Point.h"
#include "headers/Figure.h"
//#include "headers/Square.h"
//#include "headers/Circle.h"
//#include "headers/Hexagon.h"
//#include "headers/Triangle.h"


class GameWindow 
{
public:
    GameWindow();
    GameWindow(unsigned int XRes, unsigned int YRes, unsigned int RGBcolor[3], const char * title);
    virtual ~GameWindow();

    void InitGameVariables();
    void InitGameVariables(unsigned int XRes, unsigned int YRes, unsigned int RGBcolor[3], const char * title);
    void InitWindow();
    int ChooseMaxCount();
    const bool IsRunning() const;
    void GameEventsHandler();
    void SelectFigureToDraw();
    void SpawnFigure();  
    void DrawFigure();
    void FinishFigure();
    void SpawPoint();
    void ClearPoints();
    void Updater();
    void Renderer();    
    
private:
    sf::RenderWindow* mainWindow;
    sf::String* gameTitle;
    sf::Color* backGroundColor;
    sf::VideoMode videoMode;
    sf::Event evnt;

    FigureSelect fig = square;

    sf::Vector2i mousePosWindow;
    sf::Vector2f floatMousePos;

    std::vector<Point> drawPoints;
    int pointCount;
    int maxCount;

    //std::vector<Square> squares;
    //std::vector<Circle> circles;
    //std::vector<Hexagon> hexagons;
    //std::vector<Triangle> triangles;

    std::vector<Figure> figures;

    unsigned int XScreenResolution = 0U, YScreenResolution = 0U;
    
    bool drawing = false;

};