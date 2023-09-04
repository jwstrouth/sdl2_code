#ifndef JWSIMAGE2_H
#define JWSIMAGE2_H

#include "SDL_image.h"
#include "jwsString.h"

class jwsImage2
{
    public:
        jwsImage2();
        virtual ~jwsImage2();

        int Load(jwsString name, SDL_Renderer *ren, int r, int g, int b);
        int Draw();
        int SetColor(int r, int g, int b);
        int DrawLine(int x1, int y1, int x2, int y2);

        // setters / getters
        SDL_Texture *GetTex(){ return m_tex; }
        void SetDX(int x){ m_dRect.x = x; }
        void SetDY(int y){ m_dRect.y = y; }
        void SetDW(int w){ m_dRect.w = w; }
        void SetDH(int h){ m_dRect.h = h; }
        int GetDX(){ return m_dRect.x; }
        int GetDY(){ return m_dRect.y; }
        int GetDW(){ return m_dRect.w; }
        int GetDH(){ return m_dRect.h; }
        SDL_Rect GetDRect(){ return m_dRect; }
        void SetDRect(SDL_Rect rect){ m_dRect = rect; }
        void SetSRect(SDL_Rect rect){ m_sRect = rect; }

    protected:

    private:
        SDL_Texture *m_tex;
        SDL_Renderer *m_ren;
        SDL_Rect m_sRect;
        SDL_Rect m_dRect;
};

#endif // JWSIMAGE2_H
