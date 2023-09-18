#include "jwsAliens.h"

const int ALIEN_SPEED = 5;

// jwsAlien

int jwsAlien::Init(jwsWindow2 *wnd)
{
    if(m_image.Load("data/alien.gif", wnd->GetRen(), 255, 255, 255) != 0)
    {
        std::cout << "jwsAlien::Init: Failed" << std::endl;
        return -1;
    }
    m_image.SetDW(100/2);
    m_image.SetDH(100/2);

    m_explode.Load(*wnd);

    return 0;
}

int jwsAlien::Draw()
{
    m_image.Draw();
    return 0;
}

void jwsAlien::DrawExplosion()
{
    m_explode.Draw(m_image.GetDX(), m_image.GetDY());
}

//jwsAliens

jwsAliens::jwsAliens()
{
    //ctor
}

jwsAliens::~jwsAliens()
{
    //dtor
}

int jwsAliens::Init(jwsWindow2 *wnd)
{
    for(int i=0;i<MAX_ALIENS;i++)
    {
        if(m_aliens[i].Init(wnd) != 0)
        {
            std::cout << "jwsAliens::Init: Failed" << std::endl;
            return -1;
        }
    }

    return 0;
}

int jwsAliens::Draw()
{
    for (int i=0; i<MAX_ALIENS; ++i )
    {
		if ( m_aliens[i].IsAlive() )
		{
			m_aliens[i].Draw();
        }

        m_aliens[i].DrawExplosion();
	}

    return 0;
}

int jwsAliens::Create(jwsWindow2 *wnd)
{
    int dirx = 0;
    int x = 0;
    int i = 0;

    for ( i=0; i<MAX_ALIENS; ++i )
    {
		if ( !m_aliens[i].IsAlive() )
		{
			break;
        }
	}

	if ( i == MAX_ALIENS )
	{
        std::cout << "jwsAliens::Create: Exceeded Alien Max " << x << std::endl;
		return -1;
	}

    do
    {
        dirx = (rand()%3)-1;
        std::cout << "jwsMgr::Init: random x: " << x << std::endl;
    }
    while(dirx == 0);

    m_aliens[i].SetY(0);
    if ( dirx < 0 )
    {
        x = wnd->GetW() - m_aliens[i].GetW() - 1;
    }
    else
    {
        x = 0;
    }

    m_aliens[i].SetX(x);
    m_aliens[i].SetAlive();

    std::cout << "jwsAliens::Create: New Alien (i:x) " << i << "," << x << std::endl;

    return 0;
}

int jwsAliens::Move(jwsWindow2 *wnd)
{
    for (int i=0; i<MAX_ALIENS; ++i )
    {
		if ( m_aliens[i].IsAlive() )
		{
            int x = m_aliens[i].GetX() + ALIEN_SPEED*m_aliens[i].GetDirx();
            int y = m_aliens[i].GetY() + m_aliens[i].GetH()/10;

            //std::cout << "jwsAliens::Move: (x:y) " << x << "," << y << std::endl;

            if(x < 0)
            {
                x = 0;
                m_aliens[i].ReverseDirx();
            }

            if(x >= (wnd->GetW() - m_aliens[i].GetW()))
            {
                x = (wnd->GetW() - m_aliens[i].GetW()) -1;
                m_aliens[i].ReverseDirx();
            }

            if(y >= (wnd->GetH() - m_aliens[i].GetH()))
            {
                y = 0;
            }

            m_aliens[i].SetX(x);
            m_aliens[i].SetY(y);
        }
	}

    return 0;
}

void jwsAliens::SetExplosion(int i)
{
    m_aliens[i].SetExplosion();
}
