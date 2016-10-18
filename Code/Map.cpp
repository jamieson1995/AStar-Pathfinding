#include "Map.h"


Map::Map(void)
{
}


Map::~Map(void)
{
}

int Map::get_Map_Array(int i, int j){
	return Tile_Type[i][j];
}

void Map::set_Map_Array(int i, int j, int a){
	Tile_Type[i][j] = a;
}

bool Map::get_Start(){
	return Start;
}

void Map::set_Start(bool a){
	Start = a;
}

bool Map::get_Finish(){
	return Finish;
}

void Map::set_Finish(bool a){
	Finish = a;
}