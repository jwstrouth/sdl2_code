#ifndef JWSFONT_H
#define JWSFONT_H

#include "SDL.h"
#include "SDL_ttf.h"
#include "jwsString.h"

class jwsFont
{
    public:
        jwsFont();
        virtual ~jwsFont();

        int Init(jwsString name, SDL_Renderer *ren);
        int Draw();

        // getters / setters
        void SetRect(SDL_Rect rect){ m_rect = rect; }
        void SetText(char *text){ sprintf(m_text, "%s", text); }
        void SetColor(int r, int g, int b, int a)
        {
            m_color.r = r;
            m_color.g = g;
            m_color.b = b;
            m_color.a = a;
        }

    protected:

    private:
        TTF_Font *m_font;
        SDL_Renderer *m_ren;
        SDL_Rect m_rect;
        jwsString m_text;
        SDL_Color m_color;
};

#endif // JWSFONT_H
