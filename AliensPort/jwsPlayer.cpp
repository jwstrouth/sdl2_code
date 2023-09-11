#include "jwsPlayer.h"

const int PLAYER_SPEED = 10;

jwsPlayer::jwsPlayer()
{
    //ctor
}

jwsPlayer::~jwsPlayer()
{
    //dtor
}

int jwsPlayer::Init(jwsWindow2 *wnd)
{
    if(m_image.Load("data/player.gif", wnd->GetRen(), 255, 0, 255) != 0)
    {
        std::cout << "jwsBlocksMgr::Init: Failed" << std::endl;
        return -1;
    }

    SetX((wnd->GetW()-m_image.GetDW())/2);
    SetY(wnd->GetH()-m_image.GetDH() - 20);
    m_image.SetDW(50);
    m_image.SetDH(50);

    return 0;
}

int jwsPlayer::Draw()
{
    m_image.Draw();
    return 0;
}

int jwsPlayer::Update(jwsWindow2 *wnd, jwsEvent *event)
{
    int playerX = m_image.GetDX();

    if(event->IsLeft())
    {
        if(playerX < 0)
        {
            playerX = 0;
        }

        playerX -= PLAYER_SPEED;
        m_image.SetDX(playerX);
    }

    if(event->IsRight())
    {
        if(playerX > (wnd->GetW()-m_image.GetDW()))
        {
            playerX = (wnd->GetW()-m_image.GetDW());
        }

        playerX += PLAYER_SPEED;
        m_image.SetDX(playerX);
    }

    return 0;
}
