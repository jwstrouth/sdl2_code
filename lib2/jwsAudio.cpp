#include "jwsAudio.h"

jwsAudio::jwsAudio()
{
    m_mus = 0;
    m_snd = 0;
}

jwsAudio::~jwsAudio()
{
    //dtor
}

int jwsAudio::Init()
{
    if(Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) == -1)
    {
        std::cout << "jwsAudio::Init: failed" << std::endl;
        return -1;
    }

    return 0;
}

int jwsAudio::Term()
{
    if(m_snd)
    {
        Mix_FreeChunk(m_snd);
    }
    Mix_HaltMusic();
    Mix_CloseAudio();
    if(m_mus)
    {
        Mix_FreeMusic(m_mus);
    }

    return 0;
}

int jwsAudio::LoadMusic(jwsString name)
{
    m_mus = Mix_LoadMUS(name.GetData());
    if(m_mus == 0)
    {
        cout << "jwsAudio::LoadMusic: Failed: " << Mix_GetError() << endl;
        return -1;
    }
    return 0;
}

int jwsAudio::PlayMusic()
{
    if(Mix_PlayMusic(m_mus, 0) != 0)
    {
        cout << "jwsAudio::PlayMusic: Failed: " << Mix_GetError() << endl;
        return -1;
    }

    return 0;
}

int jwsAudio::StopMusic()
{
    Mix_HaltMusic();

    return 0;
}

int jwsAudio::SetMusicVolume(int vol)
{
    int ret = Mix_VolumeMusic(vol);
    if(ret != vol)
    {
        cout << "jwsAudio::SetVolume: Failed: " << Mix_GetError() << endl;
        return -1;
    }

    return 0;
}

bool jwsAudio::IsPlayingMusic()
{
    if(Mix_PlayingMusic() == 0)
    {
        return false;
    }

    return true;
}

int jwsAudio::LoadWav(jwsString name)
{
    m_snd = Mix_LoadWAV(name);
    if(m_snd == NULL)
    {
        cout << "jwsAudio::LoadWav: Failed to load %s file " << name << endl;
        return -1;
    }
    return 0;
}

// play the sound for the maximum time in milliseconds
int jwsAudio::PlaySound(int time)
{
    if(m_snd)
    {
        Mix_PlayChannelTimed(-1, m_snd, 0, time);
    }
    return 0;
}

