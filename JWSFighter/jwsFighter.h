/* @file jwsFighter.h
 *
 * @brief the jet fighter declaration for JWSFighter example
 *        - load fighter image
 *        - update fighter movement via keyboard input
 *        - draw fighter
 *        - entry point for collison detection
 *            missile and enemy collision detection
 *
 * @author James Strouth
 * Contact: jamesstrouth@gmail.com
 *
 */

#ifndef JWSFIGHTER_H
#define JWSFIGHTER_H

#include <jwsImage2.h>
#include <jwsAudio.h>
#include <jwsWindow2.h>
#include <jwsEvent.h>
#include <jwsMissle.h>
#include <jwsEnemies.h>

class jwsFighter: public jwsImage2, public jwsAudio, public jwsEvent
{
    public:
        jwsFighter(jwsWindow2 &wnd);
        virtual ~jwsFighter();

        void LoadImage();
        void Update();
        bool IsUp()
        {
            Uint8 *key = 0;
            return GetKeyboardState(key, SDL_SCANCODE_UP);
        }
        bool IsDown()
        {
            Uint8 *key = 0;
            return GetKeyboardState(key, SDL_SCANCODE_DOWN);
        }

        void DrawFighter();
        void Collision(jwsEnemies &e);

    protected:

    private:
        jwsWindow2  &m_wnd;
        jwsMissles  m_missles;
};

#endif // JWSFIGHTER_H
