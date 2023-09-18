#include "jwsShot.h"

const int SHOT_SPEED = 10;

jwsShot::jwsShot()
{
    m_alive = false;
}

jwsShot::~jwsShot()
{
    //dtor
}

int jwsShot::Init(jwsWindow2 *wnd)
{
    if(Load("data/shot.gif", wnd->GetRen(), 255, 0, 255) != 0)
    {
        std::cout << "jwsShot::Init: Failed" << std::endl;
        return -1;
    }

    SetDW(10);
    SetDH(15);

    if(Init() != 0)
    {
       std::cout << "jwsExplode::Load: Failed audio initialization" << std::endl;
       return -1;
    }

    if(LoadWav("data/shot.wav") != 0)
    {
       std::cout << "jwsExplode::Load: Failed audio load" << std::endl;
       return -1;
    }

    return 0;
}

int jwsShot::UpdateAlive(jwsWindow2 *wnd, jwsPlayer *player, bool alive)
{
    int x = 0;

    x = player->GetX() + player->GetW()/2;
    SetDX(x);
    SetDY(player->GetY());

    std::cout << "jwsShot::UpdateAlive: shot x: " << GetDX() << std::endl;

    m_alive = alive;

    PlaySound(SHOT_SOUND_TIME);

    return 0;
}

int jwsShot::UpdateMove()
{
    if(m_alive)
    {
        int y = GetDY()- SHOT_SPEED;
        SetDY(y);
        if(y < 0)
        {
            m_alive = false;
        }
    }

    return 0;
}

void jwsShot::DrawShot()
{
    if(m_alive == true)
    {
        Draw();
        std::cout << "jwsShot::DrawShot" << std::endl;
    }
}
