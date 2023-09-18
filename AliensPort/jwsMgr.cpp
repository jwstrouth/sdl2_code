#include "jwsMgr.h"

const int ALIEN_ODDS = 50;

jwsMgr::jwsMgr()
{
    m_rect = {FS_X, FS_Y, 640, 480};
    m_reloading = false;
}

jwsMgr::~jwsMgr()
{
    //dtor
}

int jwsMgr::LoadData()
{
    if(m_background.Load("data/background.gif", m_wnd.GetRen(), 255, 0, 255) != 0)
    {
        std::cout << "jwsMgr::LoadData: Failed" << std::endl;
        return -1;
    }

    m_background.SetDW(640);

    if(m_player.Init(&m_wnd) != 0)
    {
        std::cout << "jwsMgr::LoadData: Failed" << std::endl;
        return -1;
    }

    for(int i=0;i<MAX_SHOTS;i++)
    {
        if(m_shots[i].Init(&m_wnd) != 0)
        {
            std::cout << "jwsMgr::LoadData: Failed" << std::endl;
            return -1;
        }
    }

    if(m_aliens.Init(&m_wnd) != 0)
    {
        std::cout << "jwsMgr::LoadData: Failed" << std::endl;
        return -1;
    }

    return 0;
}

int jwsMgr::Init()
{
    int x = 0;

    do
    {
        x = (rand()%3)-1;
        std::cout << "jwsMgr::Init: random x: " << x << std::endl;
    }
    while(x == 0);

    jwsGame::Init();

    LoadData();

    return 0;
}

int jwsMgr::Draw()
{
    m_color = {255, 255, 255, FS_COLOR_MASK};

    // setup window drawing
    m_wnd.DrawClear();
    m_wnd.DrawColor(m_color);
    m_wnd.Draw();

    m_background.Draw();
    m_player.Draw();
    for(int i=0; i<MAX_SHOTS; i++)
    {
        m_shots[i].Draw();
    }
    m_aliens.Draw();

    return 0;
}

int jwsMgr::Update()
{
    int i = MAX_SHOTS;

    m_player.Update(&m_wnd, &m_event);

    if(m_reloading == false)
    {
        if(m_event.IsSpace() == true)
        {
            for(i=0;i<MAX_SHOTS;i++)
            {
                if(m_shots[i].IsAlive() == false)
                {
                    break;
                }
            }
        }

        if(i != MAX_SHOTS)
        {
            m_shots[i].UpdateAlive(&m_wnd, &m_player, true);
            std::cout << "jwsMgr::Update: player (i:x): " << i << ":" << m_player.GetX() << std::endl;
        }
    }
    m_reloading = m_event.IsSpace();

    for(int i=0; i<MAX_SHOTS; i++)
    {
        if(m_shots[i].IsAlive() == true)
        {
            m_shots[i].UpdateMove();
        }
    }

    if ( (rand()%ALIEN_ODDS) == 0 )
    {
        m_aliens.Create(&m_wnd);
    }

    m_aliens.Move(&m_wnd);

    // detect collions

    for(int j=0; j<MAX_SHOTS; j++)
    {
        for(int i=0; i<MAX_ALIENS; i++)
        {
            if(m_shots[j].IsAlive() && m_aliens.IsAlive(i) && Collison(m_shots[j].GetImage(), m_aliens.GetImage(i)) == true)
            {
                //std::cout << "jwsMgr::Update: shot:alians (j:i): " << j << ":" << i << std::endl;
                m_aliens.SetExplosion(i);
                m_aliens.SetDead(i);
                m_shots[j].SetDead();
            }
        }
    }

    return 0;
}

bool jwsMgr::Collison(jwsImage2 *image1, jwsImage2 *image2)
{
    if ( (image1->GetDY() >= (image2->GetDY()+image2->GetDH())) ||
	     (image1->GetDX() >= (image2->GetDX()+image2->GetDW())) ||
	     (image2->GetDY() >= (image1->GetDY()+image1->GetDH())) ||
	     (image2->GetDX() >= (image1->GetDX()+image1->GetDW())) )
    {
		return false;
	}

    return true;
}


