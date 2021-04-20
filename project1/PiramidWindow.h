/*
 * PiramidWindow.h
 *
 *  Created on: 8 апр. 2021 г.
 *      Author:  ирилл
 */

#ifndef PIRAMIDWINDOW_H_
#define PIRAMIDWINDOW_H_

#include "Window.h"

class PiramidWindow final : public Window
{
protected:
double _cube_angle {0. };
public:
	PiramidWindow(int width = DEFAULT_WIDTH, int height = DEFAULT_HEIGHT);
	virtual ~PiramidWindow() = default;

	virtual void setup_gl() override;
	virtual void render() override;
	virtual void update() override;
	virtual void renderCube(double shiftX, double shiftY, double shiftZ);
	virtual void renderPiramid();


};

#endif /* PIRAMIDWINDOW_H_ */
