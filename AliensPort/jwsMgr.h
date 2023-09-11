#ifndef JWSMGR_H
#define JWSMGR_H

#include <jwsImage2.h>
#include <jwsGame.h>
#include <jwsPlayer.h>
#include <jwsShot.h>
#include <jwsAliens.h>

const int MAX_SHOTS = 10;

class jwsMgr: public jwsGame
{
    public:
        jwsMgr();
        virtual ~jwsMgr();

        int Init();
        int LoadData();
        int Draw();
        int Update();
        bool Collison(jwsImage2 *image1, jwsImage2 *image2);

    protected:

    private:
        jwsImage2   m_background;
        jwsPlayer   m_player;
        jwsShot     m_shots[MAX_SHOTS];
        bool        m_reloading;
        jwsAliens   m_aliens;
};

#endif // JWSMGR_H
