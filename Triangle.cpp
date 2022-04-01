#include"Triangle.hpp"
#include"openGL/glew.h"
#include"openGL/freeglut.h"



Triangle::Triangle(util::Point p1, util::Point p2, util::Point p3, util::Color color) {
	this->p1 = p1;
	this->p2 = p2;
	this->p3 = p3;
	
	this->color.b = color.b;
	this->color.g = color.g;
	this->color.r = color.r;
}



void Triangle::render() {
	glColor3f(this->color.r, this->color.g, this->color.b);
	glBegin(GL_TRIANGLES);

	glVertex2f(this->p1.x, this->p1.y);
	glVertex2f(this->p2.x, this->p2.y);
	glVertex2f(this->p3.x, this->p3.y);
	glEnd();
}