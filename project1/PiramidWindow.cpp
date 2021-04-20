#include "PiramidWindow.h"
PiramidWindow::PiramidWindow(int width, int height)
: Window(width, height)
{
	SDL_SetWindowTitle(_window.get(), "OpenGL Piramid Window");
}

void PiramidWindow::setup_gl()
{

	glEnable(GL_DEPTH_TEST);
	glClearColor(0.2f, 0.4f, 0.7f, 1.0f);
	glMatrixMode(GL_PROJECTION);
	gluPerspective(
			45.0, 									  // угол обзора по вертикали
			double(width()) / double(height()), // соотношение сторон
			0.1,								      // расстояние до ближней плоскости отсечения
			20.0);									  // расстояние до дальней плоскости отсечения
	glMatrixMode(GL_MODELVIEW);

}
void PiramidWindow::renderCube(double shiftX = 0.0, double shiftY = 0.0, double shiftZ = 0.0)//создание метода рисования 1 кубика
{
		glNormal3d(  0.,  0.,  1.);// Верхняя грань кубика
		glColor3d(0.0, 0.0, 1.0); //Синяя
		glVertex3d( -1. + shiftX,  1. + shiftY,  1. + shiftZ);
		glVertex3d(  1. + shiftX,  1. + shiftY,  1. + shiftZ);
		glVertex3d(  1. + shiftX, -1. + shiftY,  1. + shiftZ);
		glVertex3d( -1. + shiftX, -1. + shiftY,  1. + shiftZ);

		glNormal3d(  0.,  0., -1.);// Нижняя грань кубика
		glColor3d(0.0, 0.0, 0.0); // Черная , потому что не видно
		glVertex3d(  1. + shiftX,  1. + shiftY, -1. + shiftZ);
		glVertex3d( -1. + shiftX,  1. + shiftY, -1. + shiftZ);
		glVertex3d( -1. + shiftX, -1. + shiftY, -1. + shiftZ);
		glVertex3d(  1. + shiftX, -1. + shiftY, -1. + shiftZ);

		glNormal3d(  1.,  0.,  0.);// Боковая грань кубика 1
		glColor3d(1.0, 0.0, 0.0); //Красная
		glVertex3d(  1. + shiftX, -1. + shiftY,  1. + shiftZ);
		glVertex3d(  1. + shiftX,  1. + shiftY,  1. + shiftZ);
		glVertex3d(  1. + shiftX,  1. + shiftY, -1. + shiftZ);
		glVertex3d(  1. + shiftX, -1. + shiftY, -1. + shiftZ);

		glNormal3d( -1.,  0.,  0.);// Боковая грань кубика 2
		glColor3d(1.0, 0.0, 1.0); //Красная
		glVertex3d( -1. + shiftX,  1. + shiftY,  1. + shiftZ);
		glVertex3d( -1. + shiftX, -1. + shiftY,  1. + shiftZ);
		glVertex3d( -1. + shiftX, -1. + shiftY, -1. + shiftZ);
		glVertex3d( -1. + shiftX,  1. + shiftY, -1. + shiftZ);

		glNormal3d(  0.,  1.,  0.);// Боковая грань кубика 3
		glColor3d(1.0, 1.0, 0.0); //Жёлтая
		glVertex3d( -1. + shiftX,  1. + shiftY,  1. + shiftZ);
		glVertex3d(  1. + shiftX,  1. + shiftY,  1. + shiftZ);
		glVertex3d(  1. + shiftX,  1. + shiftY, -1. + shiftZ);
		glVertex3d( -1. + shiftX,  1. + shiftY, -1. + shiftZ);

		glNormal3d(  0., -1.,  0.);// Боковая грань кубика 4
		glColor3d(0.0, 1.0, 1.0);//Бирюзовая
		glVertex3d(  1. + shiftX, -1. + shiftY,  1. + shiftZ);
		glVertex3d( -1. + shiftX, -1. + shiftY,  1. + shiftZ);
		glVertex3d( -1. + shiftX, -1. + shiftY, -1. + shiftZ);
		glVertex3d(  1. + shiftX, -1. + shiftY, -1. + shiftZ);


	}
void PiramidWindow::renderPiramid()//описываем метод рисования всей пирамиды из отдельных кубиков
{								   //с определенным смещением от центрального
	// Рисуем нижний слой пирамиды
	renderCube(0.0, -2.5, 0.0);
	renderCube(0.0, 0.0, 0.0);//центральный кубик
	renderCube(0.0, 2.5, 0.0);


	// Рисуем средний слой пирамиды
	renderCube(0.0, -1.25, 2.0);
	renderCube(0.0, 1.25, 2.0);

	// Рисуем верхний слой пирамиды (1 кубик)
	renderCube(0.0, 0.0, 4.0);
}

void PiramidWindow::render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //Очистка

	glLoadIdentity(); // MV = единичная матрица
	gluLookAt(	9.0, 12.0, 6.0,  //Координаты камеры
				0.0, 0.0, 0.0,  //Координаты центра
				0.0, 0.0, 1.0); // Направление вверх
	glRotated(_cube_angle, 0.0, 0.0, 0.1);


	glBegin(GL_QUADS);
	renderPiramid();//рисуем пирамиду
	glEnd();

}



void PiramidWindow::update(){
	_cube_angle +=1;
	if (_cube_angle>=360.0)
		_cube_angle-=360.0;
}


