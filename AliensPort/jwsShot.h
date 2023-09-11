#ifndef JWSSHOT_H
#define JWSSHOT_H

#include <jwsImage2.h>
#include <jwsWindow2.h>
#include <jwsEvent.h>
#include <jwsPlayer.h>

class jwsShot
{
    public:
        jwsShot();
        virtual ~jwsShot();

        int Init(jwsWindow2 *wnd);
        int UpdateAlive(jwsWindow2 *wnd, jwsPlayer *player, bool alive);
        int UpdateMove();
        int Draw();

        // getters / setters
        bool IsAlive(){ return m_alive; }
        jwsImage2 *GetImage(){ return & m_image; }
        void SetDead(){ m_alive = false; }

    protected:

    private:
        jwsImage2   m_image;
        bool        m_alive;
};

#endif // JWSSHOT_H
