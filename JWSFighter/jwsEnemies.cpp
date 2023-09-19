/* @file jwsEnemies.cpp
 *
 * @brief the jet fighter enemy implementation for JWSFighter example
 *
 * @author James Strouth
 * Contact: jamesstrouth@gmail.com
 *
 */

#include "jwsEnemies.h"

const int CREATE_ODDS = 100;

jwsEnemies::jwsEnemies(jwsWindow2 &wnd):
m_wnd(wnd)
{
    for(int i=0;i<MAX_ENEMIES;i++)
    {
        jwsEnemy *e = new jwsEnemy(wnd);
        m_list.push_back(e);
    }
}

jwsEnemies::~jwsEnemies()
{
    m_list.clear();
}

void jwsEnemies::Create()
{
    list<jwsEnemy*>::iterator it;
    jwsEnemy *pE = 0;
    int y = 0;
    static int count = 0;

    if(m_random.RandNum(CREATE_ODDS) == 0)
    {
        for(it = m_list.begin(); it != m_list.end(); it++)
        {
            if(!(*it)->IsAlive())
            {
                pE = (*it);
                count++;
                cout << "jwsEnemies::Create: " << count << endl;
                break;
            }
        }

        if(pE)
        {
            int diry;

            do
            {
                diry = m_random.RandNum(3)-1;
                cout << "diry: " << diry << endl;
            }
            while(diry == 0);

            //pE->Load("data/jet_enemy.jpeg", m_wnd.GetRen(), 0, 0, 0);
            pE->Load("data/jet_enemy_1.png", m_wnd.GetRen(), 0, 0, 0);

            if(diry < 0)
            {
                y = m_wnd.GetH()-pE->GetDH();
                pE->SetDY(y);
                cout << "y: " << y << endl;
            }
            else
            {
                y = 0;
                pE->SetDY(y);
                cout << "y: " << y << endl;
            }

            pE->SetDX(m_wnd.GetW()-pE->GetDW());
            pE->SetDW(100);
            pE->SetDH(100);
            pE->SetAlive();
        }
    }
}

void jwsEnemies::Update()
{
    Create();

    for(list<jwsEnemy*>::iterator it = m_list.begin(); it != m_list.end(); it++)
    {
        if((*it)->IsAlive())
        {
            int x = (*it)->GetDX() - (*it)->GetDW()/20;
            int y = (*it)->GetDY() + (*it)->GetDirY()*JET_SPEED;

            if(y > (m_wnd.GetH()- (*it)->GetDH()))
            {
               y =  (m_wnd.GetH()- (*it)->GetDH());
               (*it)->ReverseDirY();
            }

            if(y < 0)
            {
                y = 0;
                (*it)->ReverseDirY();
            }

            if((x+(*it)->GetDW()) < 0)
            {
                x = m_wnd.GetW()-(*it)->GetDW();
            }

            (*it)->SetDX(x);
            (*it)->SetDY(y);
        }
    }
}

void jwsEnemies::Draw()
{
    for(list<jwsEnemy*>::iterator it = m_list.begin(); it != m_list.end(); it++)
    {
        (*it)->DrawEnemy();
    }
}
