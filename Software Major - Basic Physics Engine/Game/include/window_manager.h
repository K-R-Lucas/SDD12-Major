#pragma once
#include <extras/raygui.h>
#include <environment.h>
#include <string>

using std::string, sspe::Environment;

class Window
{
	public:
		int width{}, height{}, fps{};
		double dt{};
		Color bg;
		string title;

		Window(int w, int h, int FPS, string Title);
		~Window();

		void clear();
		void drawEnvironments(Environment* envs, int n);
		void render();
};