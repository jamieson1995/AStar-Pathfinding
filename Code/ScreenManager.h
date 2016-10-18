#pragma once

#include <iostream>
#include <SDL.h>
#include <string.h>
#include <cstring>
#include "Images.h"
#include "Map.h"
#include "A_Star_Algorithm.h"

class ScreenManager
{

private:
SDL_Window* Window;
SDL_Surface *screenSurface;
SDL_Surface *Image;
SDL_Surface *Background;
SDL_Surface *Grass_Tile;
SDL_Surface *Forest_Tile;
SDL_Surface *Water_Tile;
SDL_Surface *Grass_Title;
SDL_Surface *Forest_Title;
SDL_Surface *Water_Title;
SDL_Surface *Start_Flag;
SDL_Surface *Start_Title;
SDL_Surface *Finish_Title;
SDL_Surface *Start_Flag_Grass;
SDL_Surface *Start_Flag_Forest;
SDL_Surface *Finish_Flag_Grass;
SDL_Surface *Finish_Flag_Forest;
SDL_Surface *Start_Flag_UI_Mouse;
SDL_Surface *Finish_Flag_UI_Mouse;
SDL_Surface *Reset_Title;
SDL_Surface *runProgram_Title;
SDL_Surface *Grass_Path_Tile;
SDL_Surface *Forest_Path_Tile;

Images Grass_Tile_UI;
Images Forest_Tile_UI;
Images Water_Tile_UI;
Images Grass_Title_UI;
Images Forest_Title_UI;
Images Water_Title_UI;
Images Start_Flag_UI;
Images Finish_Flag_UI;
Images Start_Title_UI;
Images Finish_Title_UI;
Images Mouse_Tile_Indicator;
Images Reset_Title_UI;
Images runProgram_Title_UI;

Images Tile_Images[10][10];
Images Background_Image;
Map Map;
A_Star_Algorithm Algorithm;

int Active_Tile;
public:

	ScreenManager(void);
	~ScreenManager(void);

	void InitialRendering();

	SDL_Window* getWindow();
	void setWindow(SDL_Window* a);

	SDL_Surface* getScreen();
	void setScreen(SDL_Surface* a);

	bool loadMedia();

	void Close();

	void Update(int mouse_x, int mouse_y);

	void Mouse_Controller(int mouse_x, int mouse_y);
};

