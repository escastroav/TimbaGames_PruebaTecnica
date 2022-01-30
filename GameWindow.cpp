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
                else if(!drawing)
                    SelectFigureToDraw();
                break;

            case sf::Event::MouseButtonPressed:                
                this->mousePosWindow = sf::Mouse::getPosition(*this->mainWindow);
                floatMousePos = sf::Vector2f(mousePosWindow.x,mousePosWindow.y);
                if(evnt.mouseButton.button == sf::Mouse::Left)
                {
                    SpawPoint();
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

void GameWindow::SpawnFigure()
{
    switch (fig)
    {
    case square:
        squares.push_back(Square(floatMousePos));
        std::cout << "Square Spawned at: " << squares.back().GetXPos() << "\t" << squares.back().GetYPos() << "\n";    
        std::cout << "Is drawing:" << drawing << "\n";
        break;
    
    case circle:
        circles.push_back(Circle(floatMousePos));
        std::cout << "Circle Spawned at: " << squares.back().GetXPos() << "\t" << squares.back().GetYPos() << "\n";    
        std::cout << "Is drawing:" << drawing << "\n";
        break;
    }
    
       
}

void GameWindow::DrawFigure()
{
    
    switch (fig)
    {
    case square:
        squares.back().Update(floatMousePos);
        std::cout << "Square Final point at: " 
            << squares.back().GetFinalVec().x - squares.back().GetInitVec().x << "\t"
            << squares.back().GetFinalVec().y - squares.back().GetInitVec().y  << "\n";
        break;
    case circle:
        circles.back().Update(floatMousePos);
        std::cout << "Square Final point at: " 
            << circles.back().GetFinalVec().x - circles.back().GetInitVec().x << "\t"
            << circles.back().GetFinalVec().y - circles.back().GetInitVec().y  << "\n";
        break;
    }
}

void GameWindow::FinishFigure()
{
    drawing = false;
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
   /* if(drawing)
            {                    
                    mousePosWindow = sf::Mouse::getPosition(*mainWindow);
                    floatMousePos = sf::Vector2f(mousePosWindow.x,mousePosWindow.y);                
                    DrawFigure();
            }*/
}

void GameWindow::Renderer()
{
    this->mainWindow->clear(*this->backGroundColor);

    for(auto sq : squares)
    {
        sq.Render(mainWindow);
    }

    for(auto cl : circles)
    {
        cl.Render(mainWindow);
    }

    for(auto pt : drawPoints)
    {
        pt.Render(mainWindow);
    }


    this->mainWindow->display();
}

