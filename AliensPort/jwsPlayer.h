#ifndef JWSPLAYER_H
#define JWSPLAYER_H

#include <jwsWindow2.h>
#include <jwsImage2.h>
#include <jwsEvent.h>

class jwsPlayer
{
    public:
        jwsPlayer();
        virtual ~jwsPlayer();

        int Init(jwsWindow2 *wnd);
        int Draw();
        int Update(jwsWindow2 *wnd, jwsEvent *event);

        // getters / setters
        int GetX(){ return m_image.GetDX(); }
        int GetY(){ return m_image.GetDY(); }
        int GetW(){ return m_image.GetDW(); }
        int GetH(){ return m_image.GetDH(); }
        void SetX(int x){ m_image.SetDX(x); }
        void SetY(int y){ m_image.SetDY(y); }
        jwsImage2 *GetImage(){ return & m_image; }

    protected:

    private:
        jwsImage2 m_image;
};

#endif // JWSPLAYER_H
