all: compile link

compile:
	g++ -I src/include/ -c main.cpp GameWindow.cpp Point.cpp Figure.cpp Animation.cpp FileLoader.cpp
link:
	g++ -std=c++11 main.o GameWindow.o Point.o Figure.o Animation.o FileLoader.o -o main -L src/lib -l sfml-graphics -l sfml-window -l sfml-system