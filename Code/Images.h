#pragma once

#include <SDL.h>

class Images
{
private:
	SDL_Rect dstrect;

public:
	Images(void);
	~Images(void);

	void setDestPos(int x, int y, int h, int w);
	SDL_Rect getDSTRECT();
	int getx();
	int gety();
};

