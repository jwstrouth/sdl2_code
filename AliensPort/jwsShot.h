#ifndef JWSSHOT_H
#define JWSSHOT_H

#include <jwsImage2.h>
#include <jwsWindow2.h>
#include <jwsEvent.h>
#include <jwsPlayer.h>
#include <jwsAudio.h>

const int SHOT_SOUND_TIME  = 500;

class jwsShot: public jwsImage2, public jwsAudio
{
    public:
        jwsShot();
        virtual ~jwsShot();

        using jwsAudio::Init;
        int Init(jwsWindow2 *wnd);
        int UpdateAlive(jwsWindow2 *wnd, jwsPlayer *player, bool alive);
        int UpdateMove();
        void DrawShot();

        // getters / setters
        bool IsAlive(){ return m_alive; }
        jwsImage2 *GetImage(){ return this; }
        void SetDead(){ m_alive = false; }

    protected:

    private:
        //jwsImage2   m_image;
        bool        m_alive;
};

#endif // JWSSHOT_H
