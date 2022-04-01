#pragma once
#include"util.h"
#include"IDrawable.h"
class Circle : public IDrawable
{
private:
	float rad;
	float x, y;
	util::Color color;

public:
	Circle(float rad, float x, float y, util::Color color);

	void render();

};
