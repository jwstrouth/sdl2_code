#ifndef JWSPADDLE_H
#define JWSPADDLE_H

#include "jwsImage2.h"
#include "jwsEvent.h"

class jwsPaddle
{
    public:
        jwsPaddle();
        virtual ~jwsPaddle();

        int Init(SDL_Renderer *ren, int w, int h);
        int Draw();
        int Update();
        bool Collision(SDL_Rect ballRect);

    protected:

    private:
        jwsImage2 m_image;
        SDL_Rect m_rect;
        jwsEvent m_event;
        int m_maxW;
        int m_maxH;
};

#endif // JWSPADDLE_H
