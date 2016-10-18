#pragma once

class Map
{
private:

//for each tile: Grass = 1, Forest = 2, Water = 3, Grass_Start = 4, Forest_Start = 5, Grass_End = 6, Forest_End = 7;
int Tile_Type[10][10];
bool Start;
bool Finish;

public:

	Map(void);
	~Map(void);

	int get_Map_Array(int i, int j);
	void set_Map_Array(int i, int j, int a);

	bool get_Start();
	void set_Start(bool a);

	bool get_Finish();
	void set_Finish(bool a);
};

