#pragma once
#include"util.hpp"
class IDrawable
{
public:
	virtual void render() = 0;
	virtual void updateColor(util::Color) = 0;
};

