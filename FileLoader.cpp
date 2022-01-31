#include "headers/FileLoader.h"

FileLoader::FileLoader()
{
    tmpFig = square;
    tmpAnim = noAnim;
    Rcol = 0.f; Gcol = 0.f; Bcol = 0.f;
    Xpos = 0.f; Ypos = 0.f; size = 0.f;
    X1 = 0.f; X2 = 0.f; X3 = 0.f;
    Y1 = 0.f; Y2 = 0.f; Y3 = 0.f;    
    tmpAnimSpd = 1.f;
}
FileLoader::~FileLoader()
{
    fileToRead.close();
}
int FileLoader::ReadFile(std::string fileName)
{
    fileToRead.open(fileName);
    size_t delim;
    size_t end;
    if(!fileToRead)
    {
        std::cout << "Fatal! file could not be open.\n";
        return 1;
    }
    while(std::getline(fileToRead, dataLine))
    {        
        delim = dataLine.find(":");
        end = dataLine.length();
        dataType = (char*)dataLine.substr(0, delim).c_str();
        data = (char*)dataLine.substr(delim+1,end).c_str();
        AssignData();   
    }
        ShowData(); 

}

void FileLoader::AssignData()
{
    if(strcmp(dataType,"figure") == 0)
    {
        if(strcmp(data,"square") == 0)
            tmpFig = square;
        if(strcmp(data,"circle") == 0)
            tmpFig = circle;
        if(strcmp(data,"hexagon") == 0)
            tmpFig = hexagon;
        if(strcmp(data,"triangle") == 0)
            tmpFig = triangle;        
    }
    if(strcmp(dataType,"animation") == 0)
    {
        if(strcmp(data,"left-right") == 0)
            tmpAnim = leftRight;
        if(strcmp(data,"up-down") == 0)
            tmpAnim = upDown;
        if(strcmp(data,"circular") == 0)
            tmpAnim = circular;
        if(strcmp(data,"box") == 0)
            tmpAnim = box;        
    }
    if(strcmp(dataType,"speed") == 0)
    {
        dataNum = std::string(data);
        tmpAnimSpd = std::stof(dataNum);
    }
    if(strcmp(dataType,"color_R") == 0)
    {
        dataNum = std::string(data);
        Rcol = std::stof(dataNum);
    }
    if(strcmp(dataType,"color_G") == 0)
    {
        dataNum = std::string(data);
        Gcol = std::stof(dataNum);
    }
    if(strcmp(dataType,"color_B") == 0)
    {
        dataNum = std::string(data);
        Bcol = std::stof(dataNum);
    }
    if(strcmp(dataType,"Xpos") == 0)
    {
        dataNum = std::string(data);
        Xpos = std::stof(dataNum);
    }
    if(strcmp(dataType,"Ypos") == 0)
    {
        dataNum = std::string(data);
        Ypos = std::stof(dataNum);
    }   
    if(strcmp(dataType,"size") == 0)
    {
        dataNum = std::string(data);
        size = std::stof(dataNum);
    }
    if(strcmp(dataType,"X1") == 0)
    {
        dataNum = std::string(data);
        X1 = std::stof(dataNum);
    }
    if(strcmp(dataType,"X2") == 0)
    {
        dataNum = std::string(data);
        X2 = std::stof(dataNum);
    }
    if(strcmp(dataType,"X3") == 0)
    {
        dataNum = std::string(data);
        X3 = std::stof(dataNum);
    }
    if(strcmp(dataType,"Y1") == 0)
    {
        dataNum = std::string(data);
        Y1 = std::stof(dataNum);
    }
    if(strcmp(dataType,"Y2") == 0)
    {
        dataNum = std::string(data);
        Y2 = std::stof(dataNum);
    }
    if(strcmp(dataType,"Y3") == 0)
    {
        dataNum = std::string(data);
        Y3 = std::stof(dataNum);
    }
}

void FileLoader::AssignValue()
{
    
}   

void FileLoader::ShowData()
{
    std::cout << "figure: " << tmpFig << "\n"
    << "anim: " << tmpAnim << "\n"
    << "speed: " << tmpAnimSpd << "\n"
    << "Xpos: " << Xpos << "\n"
    << "Ypos: " << Xpos << "\n"
    << "size: " << size << "\n"
    << "X1: " << X1  << "\n" 
    << "X2: " << X2   << "\n" 
    << "X3: " << X1 << "\n"
    << "Y1: " << Y1  << "\n"
    << "Y2: " << Y2   << "\n"
    << "Y3: " << Y1 << "\n"
    << "\n";
}

std::vector<Figure> FileLoader::LoadFigures()
{

}