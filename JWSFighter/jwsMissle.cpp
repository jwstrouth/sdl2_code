/* @file jwsMissile.cpp
 *
 * @brief the jet fighter missile implementation for JWSFighter example
 *
 * @author James Strouth
 * Contact: jamesstrouth@gmail.com
 *
 */

#include "jwsMissle.h"

jwsMissle::jwsMissle(jwsWindow2 &wnd):
m_wnd(wnd)
{
    m_alive = false;
}

jwsMissle::~jwsMissle()
{
    //dtor
}

void jwsMissle::Update()
{
    if(m_alive)
    {
        int x = GetDX() + MISSLE_SPEED;
        SetDX(x);
        if(x > m_wnd.GetW())
        {
            m_alive = false;
        }
    }
}


// jwsMissles

jwsMissles::jwsMissles(jwsWindow2 &wnd):
m_wnd(wnd)
{
    for(int i=0;i<MAX_MISSLES;i++)
    {
        jwsMissle *m = new jwsMissle(wnd);
        m_list.push_back(m);
    }

    m_reload = false;
}

jwsMissles::~jwsMissles()
{
    m_list.clear();
}

void jwsMissles::Init()
{
    for(list<jwsMissle*>::iterator it = m_list.begin(); it != m_list.end(); it++)
    {
        (*it)->Load("data/missle.png", m_wnd.GetRen(), 0, 0, 0);
    }
}

void jwsMissles::Update(int x, int y)
{
    jwsMissle *pM = 0;

    if(m_reload == false)
    {
        if(IsSpace() == true)
        {
            for(list<jwsMissle*>::iterator it = m_list.begin(); it != m_list.end(); it++)
            {
                if(!(*it)->IsAlive())
                {
                    pM = (*it);
                    break;
                }
            }

            if(pM)
            {
                pM->SetDX(x);
                pM->SetDY(y);

                //cout << "(x:y) " << x << ":" << y << "\n";

                pM->SetAlive();
            }

            //cout << "<SPACE BAR>" << "\n";
        }
    }
    m_reload = IsSpace();

    for(list<jwsMissle*>::iterator it = m_list.begin(); it != m_list.end(); it++)
    {
       (*it)->Update();
    }
}

void jwsMissles::Draw()
{
    for(list<jwsMissle*>::iterator it = m_list.begin(); it != m_list.end(); it++)
    {
        (*it)->DrawMissle();
    }
}

void jwsMissles::Collision(jwsEnemies &e)
{
    jwsMissle *pM = 0;
    jwsEnemy  *pE = 0;

    for(list<jwsMissle*>::iterator itm = m_list.begin(); itm != m_list.end(); itm++)
    {
        pM = (*itm);

        for(list<jwsEnemy*>::iterator ite = e.m_list.begin(); ite != e.m_list.end(); ite++)
        {
            pE = (*ite);

        }
    }
}
