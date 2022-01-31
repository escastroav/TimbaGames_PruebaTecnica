#include "headers/GameWindow.h"

int main()
{
    unsigned int X_Resolution = 512U;
    unsigned int Y_Resolution = 512U;
    unsigned int RGB_color [3] = {20U, 20U, 70U};
    const char * title = "Game Title";

    GameWindow game;

    std::cout << "Bienvenido a la aplicacion\n" 
    << "Seleccionar figura:" 
    << "Q = cuadrado, W = circulo, E = hexagono, R = triangulo \n" 
    << "Seleccionar Animacion" 
    << "A = izq-der, S = arr-abj, D = circular, F = caja \n" 
    << "Para cargar el archivo presione Enter en cualquier momento." << "\n";

    while(game.IsRunning())
    {
        game.Updater();

        game.Renderer();
    }

    return 0;
}