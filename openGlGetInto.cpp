#include"openGL/glew.h"
#include"openGL/freeglut.h"
#include <iostream>
#include <vector>

#include"util.hpp"
#include"IDrawable.hpp"
#include"Circle.hpp"
#include"Triangle.hpp"


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

	//glBegin(GL_TRIANGLES);
	//glColor3f(0.1, 0.2, 0.3);
	//glVertex3f(0, 0, 0);
	//glVertex3f(1, 0, 0);
	//glVertex3f(0, 1, 0);
	//glEnd();


	glutSwapBuffers();
}


int main(int argc, char* argv[]) {

	glutInit(&argc, argv);

	
	objectsToRender.push_back(new Circle(0.1f, 0.3f, 0.5f, util::Color{1, 0, 0}));
	objectsToRender.push_back(new Circle(0.1f, 0.5f, 0.2f, util::Color{ 1, 0, 0 }));
	objectsToRender.push_back(new Circle(0.1f, -0.2f, -0.2f, util::Color{ 1, 0, 0 }));
	objectsToRender.push_back(new Circle(0.1f, -0.4f, -0.4f, util::Color{ 0, 0, 1 }));


	objectsToRender.push_back(new Triangle(
		util::Point{ 0, 0 },
		util::Point{ 1, 0 },
		util::Point{ 0, 1 },
		util::Color{ 0, 1, 0 }));







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