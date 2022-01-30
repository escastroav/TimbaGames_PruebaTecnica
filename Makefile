all: compile link

compile:
	g++ -I src/include/ -c main.cpp GameWindow.cpp Point.cpp Figure.cpp
link:
	g++ main.o GameWindow.o Point.o Figure.o -o main -L src/lib -l sfml-graphics -l sfml-window -l sfml-system