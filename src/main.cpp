
#include "vector.hpp"
#include "plane.hpp"
#include "image.hpp"
#include "texture.hpp"

#include <iostream>
#include <stdio.h>
#include <stdint.h>
#include <assert.h>
#include "SDL.h"
#include "SDL_opengl.h"
#include <GL/gl.h>

#define WinWidth 1720
#define WinHeight 720

int main (int ArgCount, char **Args) {

    unsigned int WindowFlags = SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE;
    SDL_Window * Window = SDL_CreateWindow("OpenGL Test", 0, 0, WinWidth, WinHeight, WindowFlags);
    assert(Window);
    SDL_GLContext Context = SDL_GL_CreateContext(Window);

    src::Image img;
    img.load_bmp("../res/hello.bmp");
    src::Texture texture;
    texture.create(img);
    img.destroy();

    std::cout << texture.texture << std::endl;

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
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0.0f, WinWidth, WinHeight, 0.0f, -1.0f, 1.0f);
        glClearColor(1.f, 1.f, 1.f, 1.f);
        glClear(GL_COLOR_BUFFER_BIT);
        glBindTexture(GL_TEXTURE_2D, texture.texture);
        glEnable(GL_TEXTURE_2D);
        glTranslatef(0.0f, 0.0f, 0.0f);
        glBegin(GL_QUADS);
        glColor3f(1.0f, 1.0f, 1.0f);
        glTexCoord2f(0,1);
        glVertex2i(0, 0);
        glTexCoord2f(1,1);
        glVertex2i(WinWidth, 0);
        glTexCoord2f(1,0);
        glVertex2i(WinWidth, WinHeight);
        glTexCoord2f(0,0);
        glVertex2i(0, WinHeight);
        glEnd();

        SDL_GL_SwapWindow(Window);
    }
    
    texture.destroy();

    return 0;
}
