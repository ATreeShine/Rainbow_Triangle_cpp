#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengles2.h>
#include "triangle_renderer.hpp"

int main(int argc, char *argv[])
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		fprintf(stderr, "SDL_Init Error: %s\n", SDL_GetError());
		return 1;
	}

	// We use OpenGL ES 2.0
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);

	// We want at least 8 bits per color
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);

	SDL_Window *window = SDL_CreateWindow("Hello SDL2 OpenGL ES", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_OPENGL);
	if (window == NULL)
	{
		fprintf(stderr, "SDL_CreateWindow Error: %s\n", SDL_GetError());
		return 1;
	}

	// We will not actually need a context created, but we should create one
	SDL_GL_CreateContext(window);

	// Initialize triangle renderer
	triangle_init();

	while (true)
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			// Process events so the app doesn't hang
		}
		// Draw triangle
		triangle_render(SDL_GetTicks());
		// Swap buffers
		SDL_GL_SwapWindow(window);
	}

	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
