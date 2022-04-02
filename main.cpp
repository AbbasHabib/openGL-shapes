/* C++ standard libs */
#include <iostream>
#include <vector>


/* Frame work (openGL)*/
#include"openGL/glew.h"
#include"openGL/freeglut.h"


/* Custom made libs */
#include"util.hpp"
#include"IDrawable.hpp"
#include"Circle.hpp"
#include"Triangle.hpp"


/* Passing lib files to linker*/
#pragma comment(lib, "./openGL/glew32.lib")
#pragma comment(lib, "./openGL/glew32s.lib")
#pragma comment(lib, "./openGL/freeglut.lib")


std::vector<IDrawable*> objectsToRender;


// View
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

	for (IDrawable* objectToRender : objectsToRender)
	{
		objectToRender->render();
	}
	glutSwapBuffers();
}


// Controller
void timeOutNextUpdate(int x)
{
	glutPostRedisplay(); // Mark the normal plane of current window as needing to be redisplayed. 
	glutTimerFunc(1000 / 60, timeOutNextUpdate, 0);

	for (IDrawable* objectToGetUpdate : objectsToRender) 
	{
		if (dynamic_cast<Circle*>(objectToGetUpdate) != 0) 
		{	//  it's a circle
			((Circle*)objectToGetUpdate)->updateCircleParamsBy(0, 0.01f, 0);
		}
		else if (dynamic_cast<Triangle*>(objectToGetUpdate) != 0) 
		{	//  it's a triangle
			
		}
	}

}



int main(int argc, char* argv[])
{

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
	glutTimerFunc(0, timeOutNextUpdate, 0); //registers the timer callback func to be triggered msecs milliseconds

	glutMainLoop();
	return 0;
}