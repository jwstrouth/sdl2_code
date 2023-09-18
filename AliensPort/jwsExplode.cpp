#include "jwsExplode.h"

jwsExplode::jwsExplode()
{
    m_time = 0;
}

jwsExplode::~jwsExplode()
{
    //dtor
}

void jwsExplode::Load(jwsWindow2 &wnd)
{
    if(Load("data/explosion.gif", wnd.GetRen(), 255, 255, 255) != 0)
    {
        std::cout << "jwsExplode::Load: Failed" << std::endl;
        return;
    }

    SetDW(100/2);
    SetDH(100/2);

    if(Init() != 0)
    {
       std::cout << "jwsExplode::Load: Failed audio initialization" << std::endl;
       return;
    }

    if(LoadWav("data/explode.wav") != 0)
    {
       std::cout << "jwsExplode::Load: Failed audio load" << std::endl;
       return;
    }
}

void jwsExplode::Draw(int x, int y)
{
    if(m_time)
    {
        SetDX(x);
        SetDY(y);
        Draw();
        PlaySound(EXPLOSION_SOUND_TIME);
        cout << "jwsExplode::Draw: draw explosion\n";
        m_time--;
    }
}
