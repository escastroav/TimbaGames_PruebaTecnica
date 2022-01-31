#pragma once

#include <locale>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <cstring>
#include "SFML/Graphics.hpp"

#include "headers/Figure.h"
#include "headers/Animation.h"


class FileLoader
{
public:
    FileLoader();
    ~FileLoader();
    int ReadFile(std::string fileName);
    void AssignData();
    void AssignValue();
    void ShowData();
    std::vector<Figure> LoadFigures();
    int figureCount = 0;
private:
    std::string dataLine;
    std::string dataNum;
    char* dataType;
    char* data;


    std::ifstream fileToRead;
    std::vector<Figure> loadedFigures;

    FigureSelect tmpFig;
    FigureAnimation tmpAnim;
    float Rcol, Gcol, Bcol;
    float Xpos, Ypos, size;
    float X1, X2, X3;
    float Y1, Y2, Y3;    
    float tmpAnimSpd;    
    float Xcenter, Ycenter;
    float boxWidth, boxHeight;

};
