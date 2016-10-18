#include "Images.h"


Images::Images(void)
{
}


Images::~Images(void)
{
}

void Images::setDestPos(int x, int y, int h, int w){

	dstrect.x = x;
	dstrect.y = y;
	dstrect.h = h;
	dstrect.w = w;
}

SDL_Rect Images::getDSTRECT(){
	return dstrect;
}

int Images::getx(){
	return dstrect.x;
}

int Images::gety(){
	return dstrect.y;
}
