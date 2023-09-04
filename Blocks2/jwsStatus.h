#ifndef JWSSTATUS_H
#define JWSSTATUS_H

#include "jwsFont.h"
#include "jwsWindow2.h"

class jwsStatus
{
    public:
        jwsStatus();
        virtual ~jwsStatus();

        int Init(jwsWindow2 *wnd, SDL_Rect backgroundRect);
        int Draw(int blocks, int lives);
        int DrawBG();

        // getter / setter
        void SetGameover(bool over){ m_gameover = over; }

    protected:

    private:
        jwsFont m_font;
        jwsWindow2 *m_wnd;
        SDL_Rect m_fontRect;
        SDL_Rect m_bgRect;
        bool m_gameover;
};

#endif // JWSSTATUS_H
