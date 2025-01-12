/*
 * Window.h
 *
 *  Created on: 7 ���. 2021 �.
 *      Author: ������
 */

#ifndef WINDOW_H_
#define WINDOW_H_

#include <memory>
#include <SDL2/Sdl.h>
#include <GL/gl.h>
#include <GL/glu.h>

class Window
{
public:
	static constexpr int DEFAULT_WIDTH = 1920;
	static constexpr int DEFAULT_HEIGHT = 1080;
	static constexpr int DEFAULT_X = SDL_WINDOWPOS_CENTERED;
	static constexpr int DEFAULT_Y = SDL_WINDOWPOS_CENTERED;
protected:
	std::shared_ptr<SDL_Window> _window; //����
	std::shared_ptr<void> _gl_context; //�������� OpenGL
	int _width, _height; //������ � ������ ����
public:
	Window(int width = DEFAULT_WIDTH, int height = DEFAULT_HEIGHT);
	virtual ~Window() = default;

	int height() const { return _height; }
	int width() const  { return _width;  }

	void main_loop();

	virtual void setup() {}
	virtual void setup_gl() {}
	virtual void update() {}
	virtual void render() {}
	virtual void handle_event(const SDL_Event& event) {}
	virtual void handle_keys(const Uint8 * keys) {}
};

#endif /* WINDOW_H_ */
