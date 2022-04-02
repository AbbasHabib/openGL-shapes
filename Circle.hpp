#pragma once
#include"util.hpp"
#include"IDrawable.hpp"
class Circle : public IDrawable
{
private:
	float rad;
	float x, y;
	util::Color color;

public:
	Circle(float rad, float x, float y, util::Color color);
	
	void updateCircleParamsBy(float rad, float x, float y);

	void render();

	void updateColor(util::Color);
};
