#include"openGL/glew.h"
#include<cmath>
#include"openGL/freeglut.h"
#include "Circle.h"



Circle::Circle(float rad, float x, float y, util::Color color)
{
	this->rad = rad;
	this->x = x;
	this->y = y;
	this->color.b = color.b;
	this->color.g = color.g;
	this->color.r = color.r;
}

void Circle::render()
{
	float x1, y1, x2, y2;
	float angle;
	double radius = this->rad;

	x1 = this->x, y1 = this->y;
	glColor3f(this->color.r, this->color.g, this->color.b);

	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x1, y1);

	for (angle = 1.0f; angle < 361.0f; angle += 0.2)
	{
		x2 = x1 + sin(angle) * radius;
		y2 = y1 + cos(angle) * radius;
		glVertex2f(x2, y2);
	}

	glEnd();

}
