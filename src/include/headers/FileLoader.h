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

    const char* figureName = "figure";
const char* AnimName = "animation";
const char* SpeedName = "speed";
const char* RcolName = "color_R";
const char* GcolName = "color_G";
const char* BcolName = "color_B";
const char* XposName = "Xpos";
const char* YposName = "Ypos";
const char* sizeName = "size";
const char* X1Name = "X1";
const char* X2Name = "X2";
const char* X3Name = "X3";
const char* Y1Name = "Y1";
const char* Y2Name = "Y2";
const char* Y3Name = "Y3";


};
