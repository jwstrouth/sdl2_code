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
    if(m_image.Load("data/shot.gif", wnd->GetRen(), 255, 0, 255) != 0)
    {
        std::cout << "jwsShot::Init: Failed" << std::endl;
        return -1;
    }

    m_image.SetDW(10);
    m_image.SetDH(15);

    return 0;
}

int jwsShot::UpdateAlive(jwsWindow2 *wnd, jwsPlayer *player, bool alive)
{
    int x = 0;

    x = player->GetX() + player->GetW()/2;
    m_image.SetDX(x);
    m_image.SetDY(player->GetY());

    std::cout << "jjwsShot::UpdateAlive: shot x: " << m_image.GetDX() << std::endl;

    m_alive = alive;

    return 0;
}

int jwsShot::UpdateMove()
{
    if(m_alive)
    {
        int y = m_image.GetDY()- SHOT_SPEED;
        m_image.SetDY(y);
        if(y < 0)
        {
            m_alive = false;
        }
    }

    return 0;
}

int jwsShot::Draw()
{
    if(m_alive == true)
    {
        m_image.Draw();
    }
    return 0;
}
