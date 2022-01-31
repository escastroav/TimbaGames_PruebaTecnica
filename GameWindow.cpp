#include "headers/GameWindow.h"

GameWindow::GameWindow()
{
    InitGameVariables();
    InitWindow();
}

GameWindow::GameWindow(unsigned int XRes, unsigned int YRes, unsigned int RGBcolor[3], const char * title)
{   
    InitGameVariables(XRes, YRes, RGBcolor, title); 
    InitWindow();
}

void GameWindow::InitGameVariables()
{
    XScreenResolution = 800U;
    YScreenResolution = 600U;
    this->gameTitle = new sf::String("Test Program");
    this->backGroundColor = new sf::Color(20U, 20U, 70U);
    this->mainWindow = nullptr;

    pointCount = 0;
    maxCount = ChooseMaxCount();

}

int GameWindow::ChooseMaxCount()
{   
    if(fig == triangle)
        return 3;
    else    
        return 2;
}       

void GameWindow::InitGameVariables(unsigned int XRes, unsigned int YRes, unsigned int RGBcolor[3], const char * title)
{
    XScreenResolution = XRes;
    YScreenResolution = YRes;
    this->gameTitle = new sf::String(title, std::locale());
    this->backGroundColor = new sf::Color(RGBcolor[0], RGBcolor[1], RGBcolor[2]);
    this->mainWindow = nullptr;
}

GameWindow::~GameWindow()
{
    delete this->mainWindow;
    delete this->gameTitle;
    delete this->backGroundColor;
}

void GameWindow::InitWindow()
{   
    if(XScreenResolution != 0U && YScreenResolution != 0U) 
        this->videoMode = sf::VideoMode(XScreenResolution, YScreenResolution);
    else
        this->videoMode = sf::VideoMode::getDesktopMode();

    this->mainWindow = new sf::RenderWindow(this->videoMode, *this->gameTitle);

    this->mainWindow->setFramerateLimit(60);
}

const bool GameWindow::IsRunning() const
{
    return this->mainWindow->isOpen();    
}

void GameWindow::GameEventsHandler()
{
    while(this->mainWindow->pollEvent(this->evnt))
    {
        switch(this->evnt.type)
        {
            case sf::Event::Closed:
                this->mainWindow->close();
                break;
            
            case sf::Event::KeyPressed:
                if(evnt.key.code == sf::Keyboard::Escape)
                    this->mainWindow->close();
                else if(!drawing){
                    SelectFigureToDraw();
                    SelectAnimation();
                    }
                break;

            case sf::Event::MouseButtonPressed:                
                this->mousePosWindow = sf::Mouse::getPosition(*this->mainWindow);
                floatMousePos = sf::Vector2f(mousePosWindow.x,mousePosWindow.y);
                if(evnt.mouseButton.button == sf::Mouse::Left)
                {
                    SpawPoint();
                    maxCount = ChooseMaxCount();
                    drawing = (pointCount > 0 && pointCount < maxCount);   
                    if(pointCount == 1)
                        SpawnFigure();                    
                    if(pointCount == maxCount)
                        FinishFigure();       
                }
                break;
            case sf::Event::MouseMoved:
                if(drawing)
                {                    
                    mousePosWindow = sf::Mouse::getPosition(*mainWindow);
                    floatMousePos = sf::Vector2f(mousePosWindow.x,mousePosWindow.y);                
                    DrawFigure();
                }
                break;            
        }        
    }    
}

void GameWindow::SelectFigureToDraw()
{   
    switch (evnt.key.code)
    {
    case sf::Keyboard::Q:
        fig = square;
        std::cout << "Dibujando cuadrados.\n";
        break;
    case sf::Keyboard::W:
        fig = circle;
        std::cout << "Dibujando circulos.\n";
        break;
    case sf::Keyboard::E:
        fig = hexagon;
        std::cout << "Dibujando hexagonos.\n";
        break;
    case sf::Keyboard::R:
        fig = triangle;
        std::cout << "Dibujando triangulos.\n";
        break;    
    }
}

void GameWindow::SelectAnimation()
{
    switch (evnt.key.code)
    {
    case sf::Keyboard::G:
        anim = noAnim;
        std::cout << "Animacion: ninguna.\n";
        break;
    case sf::Keyboard::A:
        anim = leftRight;
        std::cout << "Animacion: Left-right.\n";
        break;
    case sf::Keyboard::S:
        anim = upDown;
        std::cout << "Animacion: Up-Down.\n";
        break;
    case sf::Keyboard::D:
        anim = circular;
        std::cout << "Animacion: Circular.\n";
        break;
    case sf::Keyboard::F:
        anim = box;
        std::cout << "Animacion: Box.\n";
        break;    
    }
}

void GameWindow::SpawnFigure()
{
    std::cout << "max Points To draw: " << maxCount << "\n";
    figures.push_back(Figure(floatMousePos, fig, anim));
    std::cout << "figure spawned: " << fig 
    << ", x = " << figures.back().GetXPos() << ", "
    << ", y = " << figures.back().GetYPos() << "\n";    
}

void GameWindow::DrawFigure()
{    
    if(fig == triangle)
    {
        figures.back().UpdateConvex(floatMousePos, pointCount);    
        std::cout << figures.back().GetFirstVec().x << ","
         << figures.back().GetFirstVec().y << ","
           << figures.back().GetSecondVec().x << ","
            << figures.back().GetSecondVec().y << ","
             << figures.back().GetThirdVec().x << ","
             << figures.back().GetThirdVec().x << "\n";    
    }
    else
    {
        figures.back().UpdatePolygon(floatMousePos);
        std::cout << "Polygon Final point rel: " 
            << figures.back().GetSecondVec().x - figures.back().GetFirstVec().x << "\t"
            << figures.back().GetSecondVec().y - figures.back().GetFirstVec().y  << "\n";
    }    
    if(figures.back().GetFigAnim() != noAnim)
        figures.back().SetAnimState(false);    
}

void GameWindow::FinishFigure()
{
    drawing = false;
    figures.back().SetAnimParameters();
    FigureAnimation tmpAnim = figures.back().GetFigAnim();

    if(tmpAnim != noAnim)
        {   
            switch(tmpAnim)
            {
                case leftRight:
                figures.back().SetDirection(false, true);
                break;
                case upDown:
                figures.back().SetDirection(true, false);
                break;
                case box:
                figures.back().SetBoxPosition();
                figures.back().SetDirection(false, true);
                break;
            }
            figures.back().SetAnimState(true);
        }
    ClearPoints();
}


void GameWindow::SpawPoint()
{
    drawPoints.push_back(Point(mousePosWindow.x, mousePosWindow.y));
    pointCount = static_cast<int>(drawPoints.size());
    std::cout << "Points count: " << pointCount << "\n";   
}
void GameWindow::ClearPoints()
{
    for(auto pt : drawPoints)
    {
        pt.Erease(*backGroundColor);
    }
    drawPoints.clear();

    pointCount = static_cast<int>(drawPoints.size());
    std::cout << "Points count: " << pointCount << "\n";

}

void GameWindow::Updater()
{
    GameEventsHandler();    
    for(int ii = 0; ii < static_cast<int>(figures.size());ii++)
    {
        if(figures.at(ii).IsAnimated())
        {
            figures.at(ii).AnimateFigure();
        }
    }
    
    
}

void GameWindow::Renderer()
{
    this->mainWindow->clear(*this->backGroundColor);

    for(auto fg : figures)
    {
        fg.Render(mainWindow);
    }

    for(auto pt : drawPoints)
    {
        pt.Render(mainWindow);
    }


    this->mainWindow->display();
}

