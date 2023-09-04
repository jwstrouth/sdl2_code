#include "jwsPaddle.h"

jwsPaddle::jwsPaddle()
{
    //ctor
}

jwsPaddle::~jwsPaddle()
{
    //dtor
}

int jwsPaddle::Init(SDL_Renderer *ren, int maxW, int maxH)
{
    if(m_image.Load("p1.bmp", ren, 0, 0, 255) != 0)
    {
        std::cout << "jwsPaddle::Init: Failed" << std::endl;
        return -1;
    }

    m_rect.x = maxW / 2;
    m_rect.y = maxH - 100;
    m_rect.w = m_image.GetDW();
    m_rect.h = m_image.GetDH();

    m_maxW = maxW;
    m_maxH = maxH;

    return 0;
}

int jwsPaddle::Draw()
{
    // set x and y movement
    m_image.SetDX(m_rect.x);
    m_image.SetDY(m_rect.y);
    // draw ball
    m_image.Draw();

    return 0;
}

int jwsPaddle::Update()
{
    int x = 0;
    int y = 0;

    if(m_event.IsLeftButton(&x, &y) == true)
    {
        if(x > (m_maxW - m_rect.w) )
        {
            m_rect.x = m_maxW - m_rect.w;
        }
        else
        {
            m_rect.x = x;
        }

        m_rect.y = y;
    }

    return 0;
}

bool jwsPaddle::Collision(SDL_Rect ballRect)
{
    if( (ballRect.x < (m_rect.x + m_rect.w))
      &&((ballRect.x + ballRect.w) > m_rect.x)
      &&(ballRect.y < (m_rect.y + m_rect.h))
      &&((ballRect.y + ballRect.h) > m_rect.y) )
    {
        return true;
    }
    return false;
}

