#include "jwsGame.h"

jwsGame::jwsGame()
{
    m_name = "GAME";
    m_rect = {FS_X, FS_Y, FS_W-FS_W_OS, FS_H-FS_H_OS};
    m_run = true;
    m_color = {FS_RED, FS_GREEN, FS_BLUE, FS_COLOR_MASK};
}

jwsGame::~jwsGame()
{
    //dtor
}

int jwsGame::Init()
{
    std::cout << "jwsGame::Init: >>>" << std::endl;

    // window's field
    if(m_wnd.Init(m_name, m_rect.x, m_rect.y, m_rect.w, m_rect.h, 0) != 0)
    {
        std::cout << "jwsGame::Init: Failed" << std::endl;
        return -1;
    }

    return 0;
}

int jwsGame::Run()
{
    // the game loop

    std::cout << "jwsGame::Run: >>>" << std::endl;

    if(Init() != 0)
    {
        std::cout << "jwsGame::Run: Failed" << std::endl;
        return -1;
    }

    while(m_run == true)
    {
        Uint32 fstart = SDL_GetTicks();

        ProcEvents();
        Update();
        Draw();
        m_wnd.DrawToScreen();

        Uint32 ftime = SDL_GetTicks() - fstart;
        if(ftime < FRAME_DELAY)
        {
            SDL_Delay(FRAME_DELAY - ftime);
        }
    }

    Term();

    return 0;
}

int jwsGame::Draw()
{
    // setup window drawing
    m_wnd.DrawClear();
    m_wnd.DrawColor(m_color);
    m_wnd.Draw();

    return 0;
}

int jwsGame::ProcEvents()
{
    // window's top-right 'x' to close application
    if(m_event.IsQuit() == true)
    {
        m_run = false;
    }

    // escape (esc) key to close application
    if(m_event.IsEscape() == true)
    {
        m_run = false;
    }

    if(m_event.IsSpace() == true)
    {

    }

    return 0;
}

int jwsGame::Update()
{
    return 0;
}

int jwsGame::Term()
{
    m_wnd.Term();

    return 0;
}

