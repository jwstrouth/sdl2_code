#include "jwsMusic.h"

jwsMusic::jwsMusic()
{
    //ctor
}

jwsMusic::~jwsMusic()
{
    //dtor
}

int jwsMusic::Init()
{
    if(m_audio.Init() != 0)
    {
        cout << "jwsMusic::Init: Failed: " << endl;
        return -1;
    }

    if(m_audio.LoadMusic("ideas.mp3") != 0)
    {
        cout << "jwsMusic::Init: Failed: " << endl;
        return -1;
    }

    if(m_audio.SetMusicVolume(MIX_MAX_VOLUME) != 0)
    {
        cout << "jwsMusic::Init: Failed: " << endl;
        return -1;
    }

    if(m_audio.PlayMusic() != 0)
    {
        cout << "jwsMusic::Init: Failed: " << endl;
        return -1;
    }

    return 0;
}

int jwsMusic::Term()
{
    m_audio.StopMusic();
    m_audio.Term();

    return 0;
}


