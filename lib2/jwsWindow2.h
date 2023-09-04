#ifndef JWSWINDOW2_H
#define JWSWINDOW2_H

#include <iostream>
#include "SDL.h"
#include "jwsString.h"

class jwsWindow2
{
    public:
        jwsWindow2();
        virtual ~jwsWindow2();

        int Init(jwsString name, int x, int y, int w, int h, Uint32 f);
        int Term();

        int WindowPosition(int x, int y);

        // routines to draw to window
        // first, clear drawing area
        // next, set the drawing color
        // then, draw to backbuffer for point, line or rect
        // finally, draw (present) backbuffer to screen
        int DrawClear();
        int DrawColor(SDL_Color color);
        int DrawRect(SDL_Rect rect);
        int Draw();
        int DrawToScreen();

        //setters / getters
        SDL_Renderer *GetRen(){ return m_ren; }
        int GetX(){ return m_rect.x; }
        int GetY(){ return m_rect.y; }
        int GetW(){ return m_rect.w; }
        int GetH(){ return m_rect.h; }

    protected:

    private:
        SDL_Window      *m_win;
        SDL_Rect        m_rect;
        jwsString       m_name;
        SDL_Renderer    *m_ren;
};

#endif // JWSWINDOW2_H
