#ifndef JWSBLOCKSMGR_H
#define JWSBLOCKSMGR_H

#include "jwsImage2.h"
#include "jwsBall.h"
#include "jwsPaddle.h"
#include "jwsBricks.h"
#include "jwsStatus.h"
#include "jwsMusic.h"
#include "jwsGame.h"

class jwsBlocksMgr: public jwsGame
{
    public:
        jwsBlocksMgr();
        virtual ~jwsBlocksMgr();

        int Init();
        int Term();
        //int Run();
        int ProcEvents();
        int Draw();
        int Update();
        int GameOver();

    protected:

    private:
        //jwsWindow2 m_wnd;
        //jwsString m_name;
        //SDL_Rect m_rect;
        //jwsEvent m_event;
        //SDL_Color m_color;
        //bool m_run;
        jwsImage2 m_area1;
        jwsImage2 m_area2;
        jwsBall m_ball;
        jwsPaddle m_paddle;
        jwsBricks m_bricks;
        jwsStatus m_status;
        int m_lives;
        jwsMusic m_music;
        bool m_gameover;
};

#endif // JWSBLOCKSMGR_H
