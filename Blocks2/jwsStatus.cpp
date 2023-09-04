#include "jwsStatus.h"

jwsStatus::jwsStatus()
{
    m_gameover = false;
}

jwsStatus::~jwsStatus()
{
    //dtor
}

int jwsStatus::Init(jwsWindow2 *wnd, SDL_Rect backgroundRect)
{
    if(wnd == 0)
    {
        std::cout << "jwsStatus::Init: wnd is NULL" << std::endl;
        return -1;
    }

    m_wnd = wnd;

    if(m_font.Init("FreeMonoBold.ttf", wnd->GetRen()) != 0)
    {
        std::cout << "jwsStatus::Init: failed" << std::endl;
        return -1;
    }

    m_bgRect = backgroundRect;
    m_fontRect.x = m_bgRect.x;
    m_fontRect.y = m_bgRect.y;
    m_fontRect.w = m_bgRect.w;
    m_fontRect.h = 20;

    return 0;
}

int jwsStatus::DrawBG()
{
    SDL_Rect r;
    SDL_Color c = {0, 0, 0, 255};

    r.x = m_fontRect.x;
    r.y = m_fontRect.y;
    r.w = m_fontRect.w;
    r.h = 400;

    m_wnd->DrawColor(c);
    m_wnd->DrawRect(r);

    return 0;
}

int jwsStatus::Draw(int blocks, int lives)
{
    char text[200];
    SDL_Rect fr = m_fontRect;

    DrawBG();

    sprintf(text,"STATUS");
    m_font.SetRect(fr);
    m_font.SetText(text);
    m_font.Draw();

    sprintf(text,"BLOCKS: %d", blocks);
    fr.y += 40;
    m_font.SetRect(fr);
    m_font.SetText(text);
    m_font.Draw();

    sprintf(text,"LIVES: %d", lives);
    fr.y += 40;
    m_font.SetRect(fr);
    m_font.SetText(text);
    m_font.Draw();

    if(m_gameover == true)
    {
        sprintf(text,"GAME OVER");
        fr.y += 40;
        m_font.SetRect(fr);
        m_font.SetText(text);
        m_font.Draw();

        sprintf(text,"PRESS SPACE BAR");
        fr.y += 40;
        m_font.SetRect(fr);
        m_font.SetText(text);
        m_font.Draw();

        sprintf(text,"TO CONTINUE");
        fr.y += 40;
        m_font.SetRect(fr);
        m_font.SetText(text);
        m_font.Draw();
    }

    return 0;
}
