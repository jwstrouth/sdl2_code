#ifndef JWSGAME_H
#define JWSGAME_H

#include "jwsWindow2.h"
#include "jwsEvent.h"
#include "jwsAudio.h"
#include "jwsGlobals.h"

class jwsGame
{
    public:
        jwsGame();
        virtual ~jwsGame();

        virtual int Init();
        virtual int Term();
        virtual int Run();
        virtual int ProcEvents();
        virtual int Draw();
        virtual int Update();

    protected:
        jwsWindow2 m_wnd;
        jwsString m_name;
        jwsEvent m_event;
        jwsAudio m_audio;
        SDL_Rect m_rect;
        bool m_run;
        SDL_Color m_color;

    private:

};

#endif // JWSGAME_H
