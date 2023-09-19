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

