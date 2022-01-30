all: compile link

compile:
	g++ -I src/include/ -c main.cpp GameWindow.cpp Point.cpp Square.cpp Circle.cpp Hexagon.cpp
link:
	g++ main.o GameWindow.o Point.o Square.o Circle.o Hexagon.o -o main -L src/lib -l sfml-graphics -l sfml-window -l sfml-system