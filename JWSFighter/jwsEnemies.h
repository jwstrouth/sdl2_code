/* @file jwsEnemies.h
 *
 * @brief the jet fighter enemy declaration for JWSFighter example
 *        - enemy inherits from image base class to load and draw graphics
 *        - enemies contains stl list of enemies
 *            contains audo point for music and sound
 *            random number generator
 *            friends with missiles class
 *
 * @author James Strouth
 * Contact: jamesstrouth@gmail.com
 *
 */

#ifndef JWSENEMIES_H
#define JWSENEMIES_H

#include <list>

#include <jwsImage2.h>
#include <jwsWindow2.h>
#include <jwsRandomNumber.h>
#include <jwsExplosion.h>

const int MAX_ENEMIES   = 20;
const int JET_SPEED     = 5;

class jwsEnemy: public jwsImage2
{
    public:
        jwsEnemy(jwsWindow2 &wnd, jwsAudio &audio):
        m_wnd(wnd),
        m_audio(audio)
        {
            m_alive = false;
            m_diry = 1;
        }
        virtual ~ jwsEnemy()
        {
        }

        void DrawEnemy()
        {
            if(m_alive)
            {
                Draw();
            }
            m_explosion.DrawExplosion();
        }

        void LoadExplosion()
        {
            if(m_explosion.Load("data/explosion.png", m_wnd.GetRen(), 0, 0, 255) != 0)
            {
                cout << "LoadExplosion Failed\n";
            }
        }

        bool IsAlive(){ return m_alive; }
        void ReverseDirY(){ m_diry *= -1; }
        int GetDirY(){ return m_diry; }
        void SetAlive(){ m_alive = true; }
        void SetDead(){ m_alive = false; }
        void SetExplosion(int x, int y)
        {
            m_explosion.SetTime();
            m_explosion.SetDX(x);
            m_explosion.SetDY(y);
            m_audio.PlaySound(500);
        }


    protected:

    private:
        bool            m_alive;
        int             m_diry;
        jwsWindow2      &m_wnd;
        jwsExplosion    m_explosion;
        jwsAudio        &m_audio;

};

class jwsEnemies
{
    public:
        jwsEnemies(jwsWindow2 &wnd);
        virtual ~jwsEnemies();

        void Draw();
        void Create();
        void Update();

    protected:

    private:
        list<jwsEnemy*> m_list;
        jwsWindow2      &m_wnd;
        jwsRandomNumber m_random;
        friend class jwsMissles;
        jwsAudio        m_audio;
};

#endif // JWSENEMIES_H
