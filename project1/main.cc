#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_main.h>

#include "PiramidWindow.h"

int main(int,char **)
{
	std::cout <<"Program started!"<< std::endl;

	SDL_Init(SDL_INIT_EVERYTHING);

	try {
		PiramidWindow w;

		w.main_loop();
	} catch (const std::exception& e) {
		std::cerr <<"При выполнении программы возникла ошибка: \n" <<
				e.what() <<std::endl;
		return 1;
	}
	std::cout <<"Program ended!"<< std::endl;
	return 0;
}
