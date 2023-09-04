#ifndef JWSMUSIC_H
#define JWSMUSIC_H

#include "jwsAudio.h"

class jwsMusic
{
    public:
        jwsMusic();
        virtual ~jwsMusic();

        int Init();
        int Term();

        // getters / setters
        void Stop(){ m_audio.StopMusic(); }
        void Start(){ m_audio.PlayMusic(); }

    protected:

    private:
        jwsAudio m_audio;
};

#endif // JWSMUSIC_H
