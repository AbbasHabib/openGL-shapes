#include"openGL/glew.h"
#include"openGL/freeglut.h"
#include <iostream>
#include <vector>

#include"IDrawable.hpp"
#include"Circle.hpp"
#include"util.hpp"


#pragma comment(lib, "glew32.lib")
#pragma comment(lib, "glew32s.lib")
#pragma comment(lib, "freeglut.lib")



std::vector<IDrawable*> objectsToRender;

void initDrawing() 
{
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(600, 600);
	glutCreateWindow("hello");
	glClearColor(0, 0, 0, 1);
}

void drawLoop()
{
	glClear(GL_COLOR_BUFFER_BIT);

	for (IDrawable *objectToRender : objectsToRender) {
		objectToRender->render();
	}

	glutSwapBuffers();
}


int main(int argc, char* argv[]) {

	glutInit(&argc, argv);

	
	objectsToRender.push_back(new Circle(0.5f, 0.2f, 0.2f, util::Color{1, 0, 0}));

	initDrawing();

	glutDisplayFunc(drawLoop);


	glutMainLoop();
	return 0;
}











/*

		glPointSize(5);

		//glBegin(GL_POINTS);

		//	glVertex2f(-0.1f, 0.1f);
		//	glVertex2f(0.1f, 0.1f);
		//	glVertex2f(0.1f, -0.1f);
		//	glVertex2f(-0.1f, -0.1f);

		//glEnd();


		//glBegin(GL_POINTS);

		//	glVertex2f(-0.5f, 0.5f);
		//	glVertex2f(0.5f, 0.5f);
		//	glVertex2f(0.5f, -0.5f);
		//	glVertex2f(-0.5f, -0.5f);

		//glEnd();
		//glBegin(GL_QUADS);

		//glVertex2f(x1, y1);
		//glVertex2f(x2, y1);
		//glVertex2f(x2, y2);
		//glVertex2f(x1, y2);

		//glEnd();
*/