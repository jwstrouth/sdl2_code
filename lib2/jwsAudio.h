#ifndef JWSAUDIO_H
#define JWSAUDIO_H

#include <iostream>
#include <SDL2/SDL_mixer.h>

#include "jwsString.h"

class jwsAudio
{
    public:
        jwsAudio();
        virtual ~jwsAudio();

        int Init();
        int Term();
        int LoadMusic(jwsString name);
        int PlayMusic();
        int StopMusic();
        int SetMusicVolume(int vol);
        bool IsPlayingMusic();
        int LoadWav(jwsString name);
        int PlaySound(int time);

    protected:

    private:
        Mix_Music *m_mus;
        Mix_Chunk *m_snd;
};

#endif // JWSAUDIO_H
