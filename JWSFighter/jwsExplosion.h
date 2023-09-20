/* @file jwsExplosion.h
 *
 * @brief the explosion object declaration for JWSFighter example
 *
 *        - draw explosion
 *        - times how long explosion is drawn
 *        - set explosions position (collision with enemy point)
 *
 * @author James Strouth
 * Contact: jamesstrouth@gmail.com
 *
 */

#ifndef JWSEXPLOSION_H
#define JWSEXPLOSION_H

#include <jwsImage2.h>
#include <jwsAudio.h>

const int MAX_TIME = 4;

class jwsExplosion: public jwsImage2
{
    public:
        jwsExplosion();
        virtual ~jwsExplosion();

        void DrawExplosion();
        void SetPosition(int x, int y);

        void SetTime(){ m_time = MAX_TIME; }

    protected:

    private:
        int     m_time;
};

#endif // JWSEXPLOSION_H
