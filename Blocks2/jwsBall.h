#ifndef JWSBALL_H
#define JWSBALL_H

#include "jwsImage2.h"

class jwsBall
{
    public:
        jwsBall();
        virtual ~jwsBall();

        int Init(SDL_Renderer *ren, int w, int h);
        int Draw();
        bool Update();
        void ReverseY(){ m_diry *= -1; }
        int DrawLine();

        // getters / setters
        SDL_Rect GetRect(){ return m_rect; }

    protected:

    private:
        jwsImage2 m_image;
        int m_dirx;
        int m_diry;
        SDL_Rect m_rect;
        int m_maxW;
        int m_maxH;
};

#endif // JWSBALL_H
