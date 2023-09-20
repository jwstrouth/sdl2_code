/* @file jwsMissile.cpp
 *
 * @brief the jet fighter missile implementation for JWSFighter example
 *        - initialize stl list of missiles in container
 *        - update missiles
 *             use reload for launching missile based on keyboard input
 *                gets position from the fighter's position
 *             moves missile and check bundary to disable missile
 *             also uses collision detection with enemy to disable missile and enemy
 *         - draws missiles
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
            SetDX(0);
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
                if((*it)->IsAlive() == false)
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

            cout << "Reload" << "\n";
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

    //cout << "Collision Detection\n";

    for(list<jwsMissle*>::iterator itm = m_list.begin(); itm != m_list.end(); itm++)
    {
        pM = (*itm);

        //cout << "pM Address: " << pM << "\n";

        for(list<jwsEnemy*>::iterator ite = e.m_list.begin(); ite != e.m_list.end(); ite++)
        {
            pE = (*ite);

            //cout << "pE Address: " << pE << "\n";

            if(pM->IsAlive() && pE->IsAlive())
            {

                if( (pE->GetDY() >= (pM->GetDY() + pM->GetDH()/2)) ||
                    (pE->GetDX() >= (pM->GetDX() + pM->GetDW()/2)) ||
                    (pM->GetDY() >= (pE->GetDY() + pE->GetDH())) ||
                    (pM->GetDX() >= (pE->GetDX() + pE->GetDW())) )
                {
                    // no collision
                    //cout << "Missile and Enemy collison NOT detected\n";
                }
                else
                {
                    pE->SetExplosion(pE->GetDX(), pE->GetDY());
                    pE->SetDead();
                    pM->SetDead();
                    cout << "Missile and Enemy collison detected\n";
                    cout << "Missle (x:y) " << pM->GetDX()+pM->GetDW() << ":" << pM->GetDY() << "\n";
                    cout << "Missle (x:y) " << pE->GetDX()+pE->GetDW() << ":" << pE->GetDY() << "\n";
                }

            }
        }
    }
}
