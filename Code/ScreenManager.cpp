#include "ScreenManager.h"

ScreenManager::ScreenManager(void)
{
	Window = NULL;
	screenSurface = NULL;
	Image = NULL;
	Background = NULL;
	Grass_Tile = NULL;
	Forest_Tile = NULL;
	Water_Tile = NULL;
	Grass_Title = NULL;
	Forest_Title = NULL;
	Water_Title = NULL;
	Start_Flag = NULL;
	Start_Title = NULL;
	Finish_Title = NULL;
	Start_Flag_Grass = NULL;
	Start_Flag_Forest = NULL;
	Finish_Flag_Grass = NULL;
	Finish_Flag_Forest = NULL;
	Start_Flag_UI_Mouse = NULL;
	Finish_Flag_UI_Mouse = NULL;
	Reset_Title = NULL;
	runProgram_Title = NULL;
	Grass_Path_Tile = NULL;
	Forest_Path_Tile = NULL;

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			Map.set_Map_Array(i, j, 1);
		}
	}
	
}


ScreenManager::~ScreenManager(void)
{
}

void ScreenManager::InitialRendering(){

}

void ScreenManager::Update(int mouse_x, int mouse_y){
	 
	//Always put this first because it always needs to be the furthest back.
	Background_Image.setDestPos(0,0,768,900);
	SDL_BlitSurface( Background, NULL, screenSurface, &(Background_Image.getDSTRECT()) );

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			//Checks what each tile value is and sets the correct image accordingly
			Tile_Images[i][j].setDestPos((i*64)+64, (j*64)+64, 64, 64);
			if (Map.get_Map_Array(i, j) == 1){
			SDL_BlitSurface( Grass_Tile, NULL, screenSurface, &(Tile_Images[i][j].getDSTRECT()) );
			}
			if (Map.get_Map_Array(i, j) == 2){
			SDL_BlitSurface( Forest_Tile, NULL, screenSurface, &(Tile_Images[i][j].getDSTRECT()) );
			}
			if (Map.get_Map_Array(i, j) == 3){
			SDL_BlitSurface( Water_Tile, NULL, screenSurface, &(Tile_Images[i][j].getDSTRECT()) );
			}
			if (Map.get_Map_Array(i, j) == 4){
			SDL_BlitSurface( Start_Flag_Grass, NULL, screenSurface, &(Tile_Images[i][j].getDSTRECT()) );
			}
			if (Map.get_Map_Array(i, j) == 5){
			SDL_BlitSurface( Start_Flag_Forest, NULL, screenSurface, &(Tile_Images[i][j].getDSTRECT()) );
			}
			if (Map.get_Map_Array(i, j) == 6){
			SDL_BlitSurface( Finish_Flag_Grass, NULL, screenSurface, &(Tile_Images[i][j].getDSTRECT()) );
			}
			if (Map.get_Map_Array(i, j) == 7){
			SDL_BlitSurface( Finish_Flag_Forest, NULL, screenSurface, &(Tile_Images[i][j].getDSTRECT()) );
			}
			if (Map.get_Map_Array(i, j) == 8){
			SDL_BlitSurface( Grass_Path_Tile, NULL, screenSurface, &(Tile_Images[i][j].getDSTRECT()) );
			}
			if (Map.get_Map_Array(i, j) == 9){
			SDL_BlitSurface( Forest_Path_Tile, NULL, screenSurface, &(Tile_Images[i][j].getDSTRECT()) );
			}
		}
		
	}


	//Sets the buttons and labels, therefore this won't change from the start.
	Grass_Tile_UI.setDestPos(10,820,64,64);
	SDL_BlitSurface( Grass_Tile, NULL, screenSurface, &(Grass_Tile_UI.getDSTRECT()) );
	Forest_Tile_UI.setDestPos(280,820,64,64);
	SDL_BlitSurface( Forest_Tile, NULL, screenSurface, &(Forest_Tile_UI.getDSTRECT()) );
	Water_Tile_UI.setDestPos(550,820,64,64);
	SDL_BlitSurface( Water_Tile, NULL, screenSurface, &(Water_Tile_UI.getDSTRECT()) );
	Grass_Title_UI.setDestPos(84,820,64,128);
	SDL_BlitSurface( Grass_Title, NULL, screenSurface, &(Grass_Title_UI.getDSTRECT()) );
	Forest_Title_UI.setDestPos(354,820,64,128);
	SDL_BlitSurface( Forest_Title, NULL, screenSurface, &(Forest_Title_UI.getDSTRECT()) );
	Water_Title_UI.setDestPos(634,820,64,128);
	SDL_BlitSurface( Water_Title, NULL, screenSurface, &(Water_Title_UI.getDSTRECT()) );
	Start_Flag_UI.setDestPos(150, 730, 64, 64);
	SDL_BlitSurface( Start_Flag_UI_Mouse, NULL, screenSurface, &(Start_Flag_UI.getDSTRECT()) );
	Finish_Flag_UI.setDestPos(450, 730, 64, 64);
	SDL_BlitSurface( Finish_Flag_UI_Mouse, NULL, screenSurface, &(Finish_Flag_UI.getDSTRECT()) );
	Start_Title_UI.setDestPos(224, 730, 64, 64);
	SDL_BlitSurface( Start_Title, NULL, screenSurface, &(Start_Title_UI.getDSTRECT()) );
	Finish_Title_UI.setDestPos(524, 730, 64, 64);
	SDL_BlitSurface( Finish_Title, NULL, screenSurface, &(Finish_Title_UI.getDSTRECT()) );
	Reset_Title_UI.setDestPos(64, 0, 64, 64);
	SDL_BlitSurface( Reset_Title, NULL, screenSurface, &(Reset_Title_UI.getDSTRECT()) );
	runProgram_Title_UI.setDestPos(576, 0, 64, 64);
	SDL_BlitSurface( runProgram_Title, NULL, screenSurface, &(runProgram_Title_UI.getDSTRECT()) );


	//Checks the active tile and puts the correct tile image where the mouse is
	if (Active_Tile != 0){
			Mouse_Tile_Indicator.setDestPos(mouse_x-32, mouse_y-32, 64, 64);

		if (Active_Tile == 1){
			SDL_BlitSurface( Grass_Tile, NULL, screenSurface, &(Mouse_Tile_Indicator.getDSTRECT()) )
		}
		if (Active_Tile == 2){
			SDL_BlitSurface( Forest_Tile, NULL, screenSurface, &(Mouse_Tile_Indicator.getDSTRECT()) );
		}
		if (Active_Tile == 3){
			SDL_BlitSurface( Water_Tile, NULL, screenSurface, &(Mouse_Tile_Indicator.getDSTRECT()) );
		}
		if (Active_Tile == 4){
			SDL_BlitSurface( Start_Flag_UI_Mouse, NULL, screenSurface, &(Mouse_Tile_Indicator.getDSTRECT()) );
		}
		if (Active_Tile == 5){
			SDL_BlitSurface( Finish_Flag_UI_Mouse, NULL, screenSurface, &(Mouse_Tile_Indicator.getDSTRECT()) );
		}
	}

	if ( SDL_GetMouseState(&mouse_x, &mouse_y) ){
		
	}

	SDL_UpdateWindowSurface( Window );
}

SDL_Window* ScreenManager::getWindow(){
	return Window;
}

void ScreenManager::setWindow(SDL_Window* a){
	Window = a;
}

SDL_Surface* ScreenManager::getScreen(){
	return screenSurface;
}

void ScreenManager::setScreen(SDL_Surface* a){
	screenSurface = a;
}

bool ScreenManager::loadMedia(){
	
	//Loads all images
	bool success = true;
	Background = SDL_LoadBMP("Assets/Images/White_Background.BMP");
	Grass_Tile = SDL_LoadBMP("Assets/Images/Grass_Tile.BMP");
	Forest_Tile = SDL_LoadBMP("Assets/Images/Forest_Tile.BMP");
	Water_Tile = SDL_LoadBMP("Assets/Images/Water_Tile.BMP");
	Grass_Title = SDL_LoadBMP("Assets/Images/Grass_Title.BMP");
	Forest_Title = SDL_LoadBMP("Assets/Images/Forest_Title.BMP");
	Water_Title = SDL_LoadBMP("Assets/Images/Water_Title.BMP");
	Start_Flag_Grass = SDL_LoadBMP("Assets/Images/Start_Flag_Grass.BMP");
	Start_Flag_Forest = SDL_LoadBMP("Assets/Images/Start_Flag_Forest.BMP");
	Finish_Flag_Grass = SDL_LoadBMP("Assets/Images/Finish_Flag_Grass.BMP");
	Finish_Flag_Forest = SDL_LoadBMP("Assets/Images/Finish_Flag_Forest.BMP");
	Start_Flag_UI_Mouse = SDL_LoadBMP("Assets/Images/Start_Flag_UI.BMP");
	Finish_Flag_UI_Mouse = SDL_LoadBMP("Assets/Images/Finish_Flag_UI.BMP");
	Start_Title = SDL_LoadBMP("Assets/Images/Start_Title.BMP");
	Finish_Title = SDL_LoadBMP("Assets/Images/Finish_Title.BMP");
	Reset_Title = SDL_LoadBMP("Assets/Images/Reset_Title.BMP");
	runProgram_Title = SDL_LoadBMP("Assets/Images/runProgram_Title.BMP");
	Grass_Path_Tile = SDL_LoadBMP("Assets/Images/Grass_Path_Tile.BMP");
	Forest_Path_Tile = SDL_LoadBMP("Assets/Images/Forest_Path_Tile.BMP");

	if (Background == NULL){
		std::cout << "Unable to load image! SDL error: " << SDL_GetError() << std::endl;
		success = false;
	}
	
	return success;
}

void ScreenManager::Close(){

	//Resets all the images back to NULL
	SDL_FreeSurface( Background );
	SDL_FreeSurface( Grass_Tile );
	SDL_FreeSurface( Forest_Tile );
	SDL_FreeSurface( Water_Tile );
	Window = NULL;
	screenSurface = NULL;
	Image = NULL;
	Background = NULL;
	Grass_Tile = NULL;
	Forest_Tile = NULL;
	Water_Tile = NULL;
	Grass_Title = NULL;
	Forest_Title = NULL;
	Water_Title = NULL;
	Start_Flag = NULL;
	Start_Title = NULL;
	Finish_Title = NULL;
	Start_Flag_Grass = NULL;
	Start_Flag_Forest = NULL;
	Finish_Flag_Grass = NULL;
	Finish_Flag_Forest = NULL;
	Start_Flag_UI_Mouse = NULL;
	Finish_Flag_UI_Mouse = NULL;
	Reset_Title = NULL;
	runProgram_Title = NULL;
	Grass_Path_Tile = NULL;
	Forest_Path_Tile = NULL;

	SDL_DestroyWindow( Window );
	Window = NULL;

}

void ScreenManager::Mouse_Controller(int mouse_x, int mouse_y){

	//Set Active Tile
	if ( ( (mouse_x > 10) && (mouse_x < 74) ) && ( (mouse_y > 820) && (mouse_y < 884) ) ){
				if (Active_Tile == 1){
					Active_Tile = 0;
				}
				else
				{
				Active_Tile = 1;
				}
			}
			if ( ( (mouse_x > 280) && (mouse_x < 349) ) && ( (mouse_y > 820) && (mouse_y < 884) ) ){
				if (Active_Tile == 2){
					Active_Tile = 0;
				}
				else
				{
				Active_Tile = 2;
				}
			}
			if ( ( (mouse_x > 550) && (mouse_x < 614) ) && ( (mouse_y > 820) && (mouse_y < 884) ) ){
				if (Active_Tile == 3){
					Active_Tile = 0;
				}
				else
				{
				Active_Tile = 3;
				}
			}
			if ( ( (mouse_x > 150) && (mouse_x < 214) ) && ( (mouse_y > 730) && (mouse_y < 794) ) ){
				if (Active_Tile == 4){
					Active_Tile = 0;
				}
				else
				{
				Active_Tile = 4;
				}
			}
			if ( ( (mouse_x > 450) && (mouse_x < 514) ) && ( (mouse_y > 730) && (mouse_y < 794) ) ){
				if (Active_Tile == 5){
					Active_Tile = 0;
				}
				else
				{
				Active_Tile = 5;
				}
			}

	//Change Tiles on map
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if ( ( (mouse_x > (i*64)+64) && (mouse_x < ((i+1)*64)+64) ) && ( (mouse_y > (j*64)+64) && ( (mouse_y < ((j+1)*64)+64) ) ) ){
				if (Active_Tile == 1){
					if ( (Map.get_Map_Array(i, j) == 4) || (Map.get_Map_Array(i, j) == 5))
						Map.set_Start(false);
					if ( (Map.get_Map_Array(i, j) == 6) || (Map.get_Map_Array(i, j) == 7))
						Map.set_Finish(false);
					Map.set_Map_Array(i, j, 1);
				}
				if (Active_Tile == 2){
					if ( (Map.get_Map_Array(i, j) == 4) || (Map.get_Map_Array(i, j) == 5))
						Map.set_Start(false);
					if ( (Map.get_Map_Array(i, j) == 6) || (Map.get_Map_Array(i, j) == 7))
						Map.set_Finish(false);
					Map.set_Map_Array(i, j, 2);
				}
				if (Active_Tile == 3){
					if ( (Map.get_Map_Array(i, j) == 4) || (Map.get_Map_Array(i, j) == 5))
						Map.set_Start(false);
					if ( (Map.get_Map_Array(i, j) == 6) || (Map.get_Map_Array(i, j) == 7))
						Map.set_Finish(false);
					Map.set_Map_Array(i, j, 3);
				}
				if (Active_Tile == 4){
					if (!Map.get_Start()){
						if (Map.get_Map_Array(i, j) == 1){
							Map.set_Map_Array(i, j, 4);
							Map.set_Start(true);
						}
						else if(Map.get_Map_Array(i, j) == 2)
						{
							Map.set_Map_Array(i, j, 5);
							Map.set_Start(true);
						}
						else if(Map.get_Map_Array(i, j) == 3)
						{
							std::cout << "WARNING: Trying to place start on water" << std::endl;
						}
					}
					else
						std::cout << "WARNING: Start already placed" << std::endl;
				}
				if (Active_Tile == 5){
					if (!(Map.get_Finish())){
						if (Map.get_Map_Array(i, j) == 1){
							Map.set_Map_Array(i, j, 6);
							Map.set_Finish(true);
						}
						else if(Map.get_Map_Array(i, j) == 2)
						{
							Map.set_Map_Array(i, j, 7);
							Map.set_Finish(true);
						}
						else if(Map.get_Map_Array(i, j) == 3)
						{
							std::cout << "WARNING: Trying to place finish on water" << std::endl;
						}
					}
					else
						std::cout << "WARNING: Finish already placed" << std::endl;
				}
			}
		}
	}

	//Reset Map
	if ( ( (mouse_x > 64) && (mouse_x < 192) ) && ( (mouse_y > 0) && (mouse_y < 64) ) ){
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				Map.set_Map_Array(i, j, 1);
				Map.set_Start(false);
				Map.set_Finish(false);
			}
		}
		std::cout << "Map Reset" << std::endl;
		Active_Tile = 0;
	}

	//Runs Program
	if ( ( (mouse_x > 576) && (mouse_x < 704) ) && ( (mouse_y > 0) && (mouse_y < 64) ) ){
		if ( !Map.get_Start() ){
			std::cout << "WARNING: No Start Tile!" << std::endl;
		}
		else if ( !Map.get_Finish() ){
			std::cout << "WARNING: No End Tile!" << std::endl;
		}
		else
		{
			int map[10][10];
			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < 10; j++)
				{
					if (Map.get_Map_Array(i, j) == 8)
					{
						Map.set_Map_Array(i, j, 1);
					}
					if (Map.get_Map_Array(i, j) == 9)
					{
						Map.set_Map_Array(i, j, 2);
					}
					map[i][j] = Map.get_Map_Array(i, j);
				}
			}
			std::cout << std::endl;
			std::cout << "Running Program." << std::endl;
			Active_Tile = 0;
			//This runs the algorithm, and returns an updated version of the map, which is then used to update the screen correctly.
			map[10][10] = Algorithm.Algorithm(map);
			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < 10; j++)
				{
					if (map[i][j] == 8)
					{
					Map.set_Map_Array(i, j, 8);
					}
					if (map[i][j] == 9)
					{
					Map.set_Map_Array(i, j, 9);
					}
				}
			}
		}
	}
}
