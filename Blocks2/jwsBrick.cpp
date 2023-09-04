#include "jwsBrick.h"

jwsBrick::jwsBrick()
{
    m_enabled = true;
}

jwsBrick::~jwsBrick()
{
    //dtor
}

int jwsBrick::Init(jwsString name, SDL_Renderer *ren, int x, int y)
{
    if(m_image.Load(name, ren, 255, 0, 255) != 0)
    {
        std::cout << "jwsBrick::Init: Failed" << endl;
        return -1;
    }

    m_image.SetDX(x);
    m_image.SetDY(y);

    m_rect.x = m_image.GetDX();
    m_rect.y = m_image.GetDY();
    m_rect.w = m_image.GetDW();
    m_rect.h = m_image.GetDH();

    return 0;
}

int jwsBrick::Draw()
{
    if(m_enabled)
    {
        m_image.Draw();
    }

    return 0;
}

