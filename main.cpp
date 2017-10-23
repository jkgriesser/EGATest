#include <iostream>
#include <fstream>
#include <vector>

#include "SDL2/SDL.h"
#include "DrawPixel.h"

using namespace std;

const int REGEN_SIZE = 28000;

int main(int argc, char *argv[]) {
    ifstream f("C:\\MEMDUMP.BIN",
               ios::binary | ios::in);
    char c;

    if (SDL_Init(SDL_INIT_EVERYTHING) == -1) {
        cout << "Something went wrong! " << SDL_GetError() << endl;
    }

    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_CreateWindowAndRenderer(640, 350, 0, &window, &renderer);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);

    const int WIDTH = 640;
    const int HEIGHT = 350;
    unsigned char pixels[WIDTH][HEIGHT];
    for (int plane = 0; plane < 4; plane++) {
        for (short y = 0; y < HEIGHT; y++) {
            for (short x = 0; x < WIDTH; x += 8) {
                char pixel;
                f.get(pixel);
                for (int i = 0; i < 8; i++) {
                    unsigned char pixelBit = (pixel >> i) & 1;
                    pixels[x + 7 - i][y] += (pixelBit << plane);
                }
            }
        }
    }

    for (int x = 0; x < WIDTH; x++) {
        for (int y = 0; y < HEIGHT; y++) {
            unsigned char color = pixels[x][y];
            Uint8 red = 85 * (((color >> 4) & 2) | (color >> 2) & 1);
            Uint8 green = 85 * (((color >> 3) & 2) | (color >> 1) & 1);
            Uint8 blue = 85 * (((color >> 2) & 2) | color & 1);
            SDL_SetRenderDrawColor(renderer, red, green, blue, 255);
            SDL_RenderDrawPoint(renderer, x, y);
        }
    }

    SDL_RenderPresent(renderer);

    bool quit = false;
    SDL_Event event;
    while (!quit)
    {
        SDL_WaitEvent(&event);

        switch (event.type)
        {
            case SDL_QUIT:
                quit = true;
                break;
        }
    }
    SDL_Delay(2000);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}