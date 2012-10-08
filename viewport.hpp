#ifndef LIERO_VIEWPORT_HPP
#define LIERO_VIEWPORT_HPP

#include "rect.hpp"
#include "worm.hpp"

struct Viewport
{
	Viewport(Rect rect, Worm* worm, int inGameX, int levwidth, int levheight)
	: worm(worm)
	, bannerY(-8)
	, inGameX(inGameX)
	, rect(rect)
	{
		maxX = levwidth - rect.width();
		maxY = levheight - rect.height();
		centerX = rect.width() >> 1;
		centerY = rect.height() >> 1;
		x = 0;
		y = 0;
		shake = 0;
		worm->viewport = this;
	}
	
	int x, y;
	int shake;
	int maxX, maxY;
	int centerX, centerY;
	Worm* worm;
	int bannerY;
	
	int inGameX; // 0 for first, 218 for second
	
	Rect rect;
	
	void setCenter(int x, int y)
	{
		this->x = x - centerX;
		this->y = y - centerY;
	}
	
	void scrollTo(int destX, int destY, int iter)
	{
		for(int c = 0; c < iter; c++)
		{
			if(x < destX - centerX) ++x;
			else if(x > destX - centerX) --x;

			if(y < destY - centerY) ++y;
			else if(y > destY - centerY) --y;
		}
	}
	
	
	void draw();
	void process();

/*
 void Init(BLOCK &vp);
 void Limit();
 void SetCenter(long _x, long _y);
 void ShakeIt();
 void Draw();
 void ScrollTo(long _x, long _y, long iter);
 void BlitLarge(IMAGE img, long _x, long _y);
 void BlitLargeShadow(IMAGE img, long _x, long _y);
*/
};

#endif // LIERO_VIEWPORT_HPP
