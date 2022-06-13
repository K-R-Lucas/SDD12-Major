#include <definitions.h>
#include <window_manager.h>
#include <loop_manager.h>

int main(int argv, char* argc[]) {
	Window window(1280, 720, 144, "Test Window");
	Loop gameLoop(300);

	while (!WindowShouldClose()) {
		window.render();
		gameLoop.runTicks(window.dt);
	}
}