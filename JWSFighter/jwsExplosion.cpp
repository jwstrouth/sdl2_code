/* @file jwsExplosion.cpp
 *
 * @brief the explosion object implementation for JWSFighter example
 *
 *        - time explosion to be drawn
 *        - draw explosion
 *        - set position of explosion
 *
 *
 * @author James Strouth
 * Contact: jamesstrouth@gmail.com
 *
 */

#include "jwsExplosion.h"

jwsExplosion::jwsExplosion()
{
    m_time = 0;
}

jwsExplosion::~jwsExplosion()
{
    //dtor
}

void jwsExplosion::DrawExplosion()
{
    if(m_time)
    {
        Draw();
        m_time--;
    }
}

void jwsExplosion::SetPosition(int x, int y)
{
    SetDX(x);
    SetDY(y);
}

