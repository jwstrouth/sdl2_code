/* @file jwsFighterMgr.h
 *
 * @brief the jet fighter manager declaration for JWSFighter example
 *        - the manager has a fighter, enemies, and background graphics
 *        - it initializes, loads graphics (via other objects), updates
 *          move and collision detection
 *        - draws graphics
 *        - runs music and sound (via other objects)
 *        - inherit from the jwsGame and support game loop
 *
 * @author James Strouth
 * Contact: jamesstrouth@gmail.com
 *
 */

#ifndef JWSFIGHTERMGR_H
#define JWSFIGHTERMGR_H

#include <jwsGame.h>
#include <jwsImage2.h>
#include <jwsFighter.h>
#include <jwsEnemies.h>
#include <jwsMissle.h>

class jwsFighterMgr : public jwsGame
{
    public:
        jwsFighterMgr();
        virtual ~jwsFighterMgr();

        int Init();
        int LoadBG();
        int Draw();
        int Update();
        bool Collison(jwsImage2 *image1, jwsImage2 *image2);

    protected:

    private:
        jwsImage2   m_background;
        jwsFighter  m_fighter;
        jwsEnemies  m_enemies;
};

#endif // JWSFIGHTERMGR_H
