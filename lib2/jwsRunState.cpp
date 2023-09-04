#include "jwsRunState.h"

jwsRunState::jwsRunState()
{
    //ctor
}

jwsRunState::~jwsRunState()
{
    //dtor
}

bool jwsRunState::Init(jwsStateManager *m, SDL_Renderer *ren)
{
    SetStateMgr(m);

    if(m_image1.Load("js1.bmp", ren, 255, 0, 255) != 0)
    {
        std::cout << "jwsRunState::Init: Failed to load js1.bmp" << std::endl;
        return false;
    }

    if(m_image2.Load("js2.bmp", ren, 255, 0, 255) != 0)
    {
        std::cout << "jwsRunState::Init: Failed to load js2.bmp" << std::endl;
        return false;
    }

    return true;
}

void jwsRunState::Term()
{

}

void jwsRunState::Update()
{
    if(m_event.IsEscape() == true)
    {
        std::cout << "jwsRunState::Update: Escape" << std::endl;
        GetStateMgr()->PopState();
    }
}

void jwsRunState::Draw()
{
    std::cout << "jwsRunState::Draw" << std::endl;
    m_image1.SetDX(0);
    m_image1.SetDY(0);
    m_image1.Draw();
    m_image2.SetDX(640);
    m_image2.SetDY(480);
    m_image2.Draw();
}
