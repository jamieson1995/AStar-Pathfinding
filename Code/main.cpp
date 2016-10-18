#include <SDL.h>
#include <iostream>
#include <math.h>
#include "Images.h"
#include "ScreenManager.h"

bool init(const int SCREEN_HEIGHT, const int SCREEN_WIDTH);
void close();

ScreenManager Screen;

int main(int argc, char** argv){

	bool quit = false;
	SDL_Event event;

	int Active_Tile = 0;

	const int SCREEN_HEIGHT = 900;
	const int SCREEN_WIDTH = 768;

	if( !init(SCREEN_HEIGHT, SCREEN_WIDTH) ){
		std::cout << "Failed to initialise" << std::endl;
	}
	else
	{
		if ( !Screen.loadMedia() )
		{
			std::cout << "Failed to load media" << std::endl;
		}
		else
		{
			Screen.Update(NULL, NULL);			
		}
	}

	int mouse_x, mouse_y;

	while (!quit){
		while(SDL_PollEvent(&event))
		{
		if ( ( SDL_GetMouseState(&mouse_x, &mouse_y) ) && ( event.type == SDL_MOUSEBUTTONDOWN ) ){
			Screen.Mouse_Controller(mouse_x, mouse_y);
		}

		Screen.Update(mouse_x, mouse_y);

		if (event.type == SDL_QUIT)
			quit = true;
		}
	}

	close();

	return 0;
}

bool init(const int SCREEN_HEIGHT, const int SCREEN_WIDTH){
	bool success = true;

	if (SDL_Init( SDL_INIT_VIDEO ) < 0){
		std::cout << "SDL not initialized! SDL_Error: " << SDL_GetError() << std::endl;
		success = false;
	}
	else
	{
		Screen.setWindow( SDL_CreateWindow( "AI Pathfinding Assignment", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN ) );
        if( Screen.getWindow() == NULL )
        {
            std::cout << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
            success = false;
        }
        else
        {
			Screen.setScreen(SDL_GetWindowSurface( Screen.getWindow() ) );
        }
    }

	return success;
	
}

void close(){

	Screen.Close();
	SDL_Quit();
}