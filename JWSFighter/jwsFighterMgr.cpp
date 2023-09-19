/* @file jwsFighterMgr.cpp
 *
 * @brief the jet fighter manager implementation for JWSFighter example
 *
 * @author James Strouth
 * Contact: jamesstrouth@gmail.com
 *
 */

#include "jwsFighterMgr.h"

jwsFighterMgr::jwsFighterMgr():
m_fighter(m_wnd),
m_enemies(m_wnd)
{
    //ctor
}

jwsFighterMgr::~jwsFighterMgr()
{
    //dtor
}

int jwsFighterMgr::Init()
{
    if(m_wnd.Init(m_name, m_rect.x, m_rect.y, m_rect.w, m_rect.h, 0) != 0)
    {
        std::cout << "jwsFighterMgr::Init: Failed" << std::endl;
        return -1;
    }

    if(m_background.Load("data/background.png", m_wnd.GetRen(), 0, 0, 0) != 0)
    {
        std::cout << "jwsFighterMgr::Init: Failed" << std::endl;
        return -1;
    }

    m_background.SetDX(FS_X);
    m_background.SetDY(FS_Y);
    m_background.SetDW(FS_W-40);
    m_background.SetDH(FS_H-40);

    m_fighter.LoadImage();

    return 0;
}

int jwsFighterMgr::Draw()
{
    // setup window drawing
    m_wnd.DrawClear();
    m_wnd.DrawColor(m_color);
    m_wnd.Draw();

    m_background.Draw();
    m_fighter.DrawFighter();
    m_enemies.Draw();

    return 0;
}

int jwsFighterMgr::Update()
{
    m_fighter.Update();

    m_enemies.Update();

    return 0;
}

bool jwsFighterMgr::Collison(jwsImage2 *image1, jwsImage2 *image2)
{
    if ( (image1->GetDY() >= (image2->GetDY()+image2->GetDH())) ||
	     (image1->GetDX() >= (image2->GetDX()+image2->GetDW())) ||
	     (image2->GetDY() >= (image1->GetDY()+image1->GetDH())) ||
	     (image2->GetDX() >= (image1->GetDX()+image1->GetDW())) )
    {
		return false;
	}

    return true;
}
