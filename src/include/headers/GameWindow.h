#pragma once

#include <locale>
#include <vector>
#include <iostream>
#include "SFML/Graphics.hpp"

#include "headers/Point.h"
#include "headers/Square.h"

enum FigureSelect {square = 0, triangle = 1, circle = 2, hexagon = 3};

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

    //Square sq;
    std::vector<Square> squares;

    unsigned int XScreenResolution = 0U, YScreenResolution = 0U;
    
    bool drawing = false;

};