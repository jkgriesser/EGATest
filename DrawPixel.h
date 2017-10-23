//
// Created by ididn on 13/09/2016.
//

#include <SDL2/SDL_surface.h>

#ifndef EGA_DRAWPIXEL_H
#define EGA_DRAWPIXEL_H

#endif //EGA_DRAWPIXEL_H

void PutPixel32_nolock(SDL_Surface * surface, int x, int y, Uint32 color);

void PutPixel24_nolock(SDL_Surface * surface, int x, int y, Uint32 color);

void PutPixel16_nolock(SDL_Surface * surface, int x, int y, Uint32 color);

void PutPixel8_nolock(SDL_Surface * surface, int x, int y, Uint32 color);

void PutPixel32(SDL_Surface * surface, int x, int y, Uint32 color);

void PutPixel24(SDL_Surface * surface, int x, int y, Uint32 color);

void PutPixel16(SDL_Surface * surface, int x, int y, Uint32 color);

void PutPixel8(SDL_Surface * surface, int x, int y, Uint32 color);