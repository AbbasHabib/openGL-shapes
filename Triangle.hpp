#pragma once
#include"util.hpp"
#include"IDrawable.hpp"
class Triangle : public IDrawable
{
private:
	util::Point p1, p2, p3;
	util::Color color;
public:
	Triangle(util::Point p1, util::Point p2, util::Point p3, util::Color color);

	void render();
};