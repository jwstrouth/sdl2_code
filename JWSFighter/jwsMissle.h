/* @file jwsMissile.h
 *
 * @brief the jet fighter missile declaration for JWSFighter example
 *
 * @author James Strouth
 * Contact: jamesstrouth@gmail.com
 *
 */

#ifndef JWSMISSLE_H
#define JWSMISSLE_H

#include <list>

#include <jwsImage2.h>
#include <jwsWindow2.h>
#include <jwsEvent.h>
#include <jwsEnemies.h>

const int MAX_MISSLES   = 3;
const int MISSLE_SPEED  = 20;

class jwsMissle: public jwsImage2
{
    public:
        jwsMissle(jwsWindow2 &wnd);
        virtual ~jwsMissle();

        bool IsAlive(){ return m_alive; }
        void SetAlive(){ m_alive = true; }
        void SetDead(){ m_alive = false; }
        void DrawMissle()
        {
            if(m_alive)
            {
                Draw();
            }
        }
        void Update();

    protected:

    private:
        jwsWindow2  &m_wnd;
        bool        m_alive;
};

class jwsMissles: public jwsEvent
{
    public:
        jwsMissles(jwsWindow2 &wnd);
        virtual ~jwsMissles();

        void Init();
        void Draw();
        void Update(int x, int y);
        void Collision(jwsEnemies &e);

    protected:

    private:
        jwsWindow2          &m_wnd;
        list<jwsMissle*>    m_list;
        bool                m_reload;

};


#endif // JWSMISSLE_H
