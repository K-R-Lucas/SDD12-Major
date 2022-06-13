#include <extras/raygui.h>
#include <window_manager.h>

Window::Window(int w, int h, int FPS, string Title) : width(w), height(h), fps(FPS), title(Title) {
	InitWindow(width, height, title.c_str());
	SetTargetFPS(fps);
	dt = 1.0 / fps;
	bg = {0, 0, 0, 255};
}

Window::~Window() {
	CloseWindow();
}

void Window::clear() {
	ClearBackground(bg);
}

void Window::render() {
	BeginDrawing();
	Window::clear();
	// General rendering

	DrawFPS(0, 0);
	EndDrawing();
	dt = GetFrameTime();
}

void Window::drawEnvironments(Environment* envs, int n) {
	for (int i = 0; i < n; i++) {
		// Draw all environments

	}
}