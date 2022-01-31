#pragma once

#include <locale>
#include <vector>
#include <iostream>
#include "SFML/Graphics.hpp"

#include "headers/Point.h"
#include "headers/Figure.h"
#include "headers/FileLoader.h"

class GameWindow 
{
public:
//Constructores
    GameWindow();
    GameWindow(unsigned int XRes, unsigned int YRes, unsigned int RGBcolor[3], const char * title);
//Destructor
    virtual ~GameWindow();
//Inicializacion
    void InitGameVariables();
    void InitGameVariables(unsigned int XRes, unsigned int YRes, unsigned int RGBcolor[3], const char * title);
    void InitWindow();
//Revisa que el juego este abierto
    const bool IsRunning() const;
//Administrador de eventos
    void GameEventsHandler();
//Cambiar parametros de dibujo y animacion
    int ChooseMaxCount();
    void SelectFigureToDraw();
    void SelectAnimation();
//Crear y dibujar figuras
    void SpawnFigure();  
    void DrawFigure();
    void FinishFigure();
    void SpawPoint();
    void ClearPoints();
//Funcion de actualizacion logica
    void Updater();
//Funcion de actualizacion grafica
    void Renderer();    
    
private:
//Objetos de ventaka
    sf::RenderWindow* mainWindow;
    sf::String* gameTitle;
    sf::Color* backGroundColor;
    sf::VideoMode videoMode;
//Objeto de eventos
    sf::Event evnt;
//Tipo de figura a dibujar
    FigureSelect fig = square;
//Tipo de animacion a correr
    FigureAnimation anim = noAnim;
//Posicion del mouse en la ventana
    sf::Vector2i mousePosWindow;
    sf::Vector2f floatMousePos;
//Puntos auxiliares de dibujo
    std::vector<Point> drawPoints;
    int pointCount;
    int maxCount;
//Figuras que existen en el programa
    std::vector<Figure> figures;
//Resolución de pantalla
    unsigned int XScreenResolution = 0U, YScreenResolution = 0U;
//Revisar si el usuario esta dibujando    
    bool drawing = false;
//Parametros de animacion
    float XScreenSize, YScreensize;    
    float animSpeed;
    float Xcenter, Ycenter, AnimRadius;
    float XBoxPos, YBoxPos, BoxWidth, BoxHeight;
//Objeto para cargar archivos
    FileLoader gameFileLoader;
};