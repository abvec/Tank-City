
#include "vector.hpp"
#include "plane.hpp"

#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include "SDL.h"
#include "SDL_opengl.h"
#include <GL/gl.h>

#define WinWidth 640
#define WinHeight 480

int main (int ArgCount, char **Args)
{

    unsigned int WindowFlags = SDL_WINDOW_OPENGL;
    SDL_Window * Window = SDL_CreateWindow("OpenGL Test", 0, 0, WinWidth, WinHeight, WindowFlags);
    assert(Window);
    SDL_GLContext Context = SDL_GL_CreateContext(Window);

    int Running = 1;

    while (Running) {

        SDL_Event Event;

        while (SDL_PollEvent(&Event)) {

            if (Event.type == SDL_KEYDOWN) {

                switch (Event.key.keysym.sym) {

                    case SDLK_ESCAPE:
                    Running = 0;
                    break;
                }
            }

            else if (Event.type == SDL_QUIT) {
                Running = 0;
            }
        }

        glViewport(0, 0, WinWidth, WinHeight);
        glClearColor(1.f, 0.f, 1.f, 0.f);
        glClear(GL_COLOR_BUFFER_BIT);

        SDL_GL_SwapWindow(Window);
    }

    return 0;
}
