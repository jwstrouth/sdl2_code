#ifndef JWSBRICK_H
#define JWSBRICK_H

#include "jwsImage2.h"
//#include "jwsString.h"

class jwsBrick
{
    public:
        jwsBrick();
        virtual ~jwsBrick();

        int Init(jwsString name, SDL_Renderer *ren, int x, int y);
        int Draw();

        // getters / setters
        void SetEnabled(bool enabled){ m_enabled = enabled; }
        bool GetEnabled(){ return m_enabled; }
        SDL_Rect GetRect(){ return m_rect; }

    protected:

    private:
        jwsImage2 m_image;
        SDL_Rect m_rect;
        //jwsString m_name;
        bool m_enabled;
};

#endif // JWSBRICK_H
