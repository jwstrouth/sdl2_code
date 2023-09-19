/* @file jwsFighter.cpp
 *
 * @brief the jet fighter implementation for JWSFighter example
 *
 * @author James Strouth
 * Contact: jamesstrouth@gmail.com
 *
 */

#include "jwsFighter.h"

const int FIGHTER_SPEED = 20;

jwsFighter::jwsFighter(jwsWindow2 &wnd):
m_wnd(wnd),
m_missles(wnd)
{
    //ctor
}

jwsFighter::~jwsFighter()
{
    //dtor
}

void jwsFighter::LoadImage()
{
    Load("data/jet.png", m_wnd.GetRen(), 0, 0, 0);
    //Load("data/fighter.png", m_wnd.GetRen(), 0, 0, 0);
    SetDX(20);
    SetDY(20);
    SetDW(100);
    SetDH(100);

    m_missles.Init();
}

void jwsFighter::Update()
{
    int y = GetDY();
    int x = GetDX();

    if(IsUp() == true)
    {
        if(y < 0)
        {
            y = 0;
        }

        y -= FIGHTER_SPEED;
        SetDY(y);
    }

    if(IsDown() == true)
    {
        if(y > (m_wnd.GetH()-GetDH()))
        {
            y = (m_wnd.GetH()-GetDH());
        }

        y += FIGHTER_SPEED;
        SetDY(y);
    }

    if(IsLeft() == true)
    {
        if(x < 0)
        {
            x = 0;
        }

        x -= FIGHTER_SPEED;
        SetDX(x);
    }

    if(IsRight() == true)
    {
        if(x > (m_wnd.GetW()-GetDW()))
        {
            x = (m_wnd.GetW()-GetDW());
        }

        x += FIGHTER_SPEED;
        SetDX(x);
    }

    m_missles.Update((GetDX()+GetDW()), (GetDY()+(GetDH()/2)-10));
}

void jwsFighter::DrawFighter()
{
    Draw();

    m_missles.Draw();
}

void jwsFighter::Collision(jwsEnemies &e)
{
    m_missles.Collision(e);
}
