/*
 * DemoWindow.cpp
 *
 *  Created on: 7 ���. 2021 �.
 *      Author: ������
 */

#include "DemoWindow.h"
DemoWindow::DemoWindow(int width, int height)
: Window(width, height)
{
	SDL_SetWindowTitle(_window.get(), "OpenGL Demo Window");
}

void DemoWindow::setup_gl()
{
	glEnable(GL_DEPTH_TEST);
	glClearColor(0.2f, 0.4f, 0.7f, 1.0f);
	glMatrixMode(GL_PROJECTION);
	gluPerspective(
			45.0, 									  // ���� ������ �� ���������
			double(width()) / double(height()), // ����������� ������
			0.1,								      // ���������� �� ������� ��������� ���������
			20.0);									  // ���������� �� ������� ��������� ���������
	glMatrixMode(GL_MODELVIEW);

}

void DemoWindow::render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //�������

	glLoadIdentity(); // MV = ��������� �������
	gluLookAt(	3.0, 4.0, 2.0,  //���������� ������
				0.0, 0.0, 0.0,  //���������� ������
				0.0, 0.0, 1.0); // ����������� �����
	glRotated(_cube_angle, 0.0, 0.0, 0.1);

	glBegin(GL_QUADS);


	glColor3d(1.0,0.0,0.0); 		//������ �����, �������
	glVertex3d(-1.0,1.0,-1.0);
	glVertex3d(1.0,1.0,-1.0);
	glVertex3d(1.0,-1.0,-1.0);
	glVertex3d(-1.0,-1.0,-1.0);

	glColor3d(0.0,1.0,1.0); 		//������� �����, ���������
	glVertex3d(-1.0,-1.0,1.0);
	glVertex3d(1.0,-1.0,1.0);
	glVertex3d(1.0,1.0,1.0);
	glVertex3d(-1.0,1.0,1.0);

	glColor3d(0.0,1.0,0.0); 		//������� ����� 1, �������
	glVertex3d(-1.0,1.0,-1.0);
	glVertex3d(-1.0,1.0,1.0);
	glVertex3d(1.0,1.0,1.0);
	glVertex3d(1.0,1.0,-1.0);

	glColor3d(0.0,0.0,1.0); 		//������� ����� 2, �����
	glVertex3d(1.0,1.0,1.0);
	glVertex3d(1.0,1.0,-1.0);
	glVertex3d(1.0,-1.0,-1.0);
	glVertex3d(1.0,-1.0,1.0);

	glColor3d(1.0,0.0,1.0); 		//������� ����� 3, �������
	glVertex3d(1.0,-1.0,1.0);
	glVertex3d(1.0,-1.0,-1.0);
	glVertex3d(-1.0,-1.0,-1.0);
	glVertex3d(-1.0,-1.0,1.0);

	glColor3d(1.0,1.0,0.0); 		//������� ����� 4, ������
	glVertex3d(-1.0,-1.0,1.0);
	glVertex3d(-1.0,-1.0,-1.0);
	glVertex3d(-1.0,1.0,-1.0);
	glVertex3d(-1.0,1.0,1.0);


	glEnd();
}


void DemoWindow::update(){
	_cube_angle +=1;
	if (_cube_angle>=360.0)
		_cube_angle-=360.0;
}


