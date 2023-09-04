#include "jwsBall.h"

const int BALL_SPEED = 10;

jwsBall::jwsBall()
{
    // ball moves down-right
    m_dirx = 1;
    m_diry = -1;
}

jwsBall::~jwsBall()
{
    //dtor
}

int jwsBall::Init(SDL_Renderer *ren, int maxW, int maxH)
{
    // ball's BMP
    if(m_image.Load("blocksBall.bmp", ren, 0, 0, 255) != 0)
    {
        std::cout << "jwsBall::Init: failed" << std::endl;
        return -1;
    }

    // ball's rectangle
    //m_rect.x = m_image.GetX();
    m_rect.x = maxW / 2;
    //m_rect.y = m_image.GetY();
    m_rect.y = (maxH * 2)/3;
    m_rect.w = m_image.GetDW();
    m_rect.h = m_image.GetDH();

    // ball's field (width and height)
    m_maxW = maxW;
    m_maxH = maxH;

    return 0;
}

int jwsBall::Draw()
{
    // set x and y movement
    m_image.SetDX(m_rect.x);
    m_image.SetDY(m_rect.y);
    // draw ball
    m_image.Draw();
    DrawLine();

    return 0;
}

bool jwsBall::Update()
{
    // update ball's x and y movement

    m_rect.x += m_dirx*BALL_SPEED;

    // left boundary
    if( (m_rect.x < 0) )
    {
        // change direction and set ball to left
        m_dirx *= -1;
        m_rect.x = 0;
    }

    // right boundary - left part of ball meets right boundary
    if( (m_rect.x + m_rect.w) >= m_maxW )
    {
        // change balls direction and set ball to right
        m_dirx *= -1;
        m_rect.x = m_maxW - m_rect.w;
    }

    m_rect.y += m_diry*BALL_SPEED;

    // top boundary
    if(m_rect.y < 0)
    {
        // change direction and set ball to top
        m_diry *= -1;
        m_rect.y = 0;
    }

    // bottom boundary
    if( (m_rect.y + m_rect.h) >= m_maxH )
    {
        // change direction and set ball to bottom
        m_diry *= -1;
        m_rect.y = m_maxH - m_rect.h;

        // this can be used by game for scoring
        return true;
    }

    return false;
}

int jwsBall::DrawLine()
{
    int x1 = m_rect.x + m_rect.w/2;
    int y1 = m_rect.y + m_rect.h/2;
    int x2 = y1 - m_maxH;
    int y2 = 0;

    if( (m_dirx == 1) && (m_diry == 1) )
    {
        x2 = x1 + (m_maxH - y1);
        y2 = m_maxH;
    }

    if( (m_dirx == 1) && (m_diry == -1) )
    {
        x2 = x1 + y1;
        y2 = 0;
    }

    if( (m_dirx == -1) && (m_diry == 1) )
    {
        x2 = x1 - (m_maxH - y1);
        y2 = m_maxH;
    }

    if( (m_dirx == -1) && (m_diry == -1) )
    {
        x2 = x1 - y1;
        y2 = 0;
    }

    m_image.SetColor(255, 255, 255);
    m_image.DrawLine(x1, y1, x2, y2);

    return 0;
}


