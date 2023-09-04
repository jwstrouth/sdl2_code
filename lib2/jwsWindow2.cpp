#include "jwsWindow2.h"

jwsWindow2::jwsWindow2()
{
    //ctor
}

jwsWindow2::~jwsWindow2()
{
    //dtor
}

int jwsWindow2::Init(jwsString name, int x, int y, int w, int h, Uint32 flag)
{
    Uint32 winF = SDL_WINDOW_OPENGL;
    Uint32 renF = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;

    if(name.GetData() != 0)
    {
        m_name = name;

        if(flag == 0)
        {
            flag = SDL_WINDOW_OPENGL;
        }

        if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
        {
            std::cout << "jwsWindow2::Init: SDL_Init Failed" << std::endl;
            return -1;
        }

        m_rect = {x, y, w, h};
        m_win = SDL_CreateWindow(m_name, x, y, w, h, winF);
        if(m_win == 0)
        {
            std::cout << "jwsWindow2::Init: SDL_CreateWindow Failed" << std::endl;
            return -1;
        }

        m_ren = SDL_CreateRenderer(m_win, -1, renF);
        if(m_ren == NULL)
        {
            printf("SDL_CreateRenderer Failed: %s\n", SDL_GetError());
            return -1;
        }
    }

    return 0;
}

int jwsWindow2::Term()
{
    SDL_DestroyWindow(m_win);
    SDL_Quit();
    return 0;
}

int jwsWindow2::DrawClear()
{
    SDL_RenderClear(m_ren);

    return 0;
}

int jwsWindow2::DrawColor(SDL_Color color)
{
    SDL_SetRenderDrawColor(m_ren, color.r, color.g, color.b, 255);

    return 0;
}

int jwsWindow2::DrawRect(SDL_Rect rect)
{
    if(m_ren == 0)
    {
        std::cout << "jwsWindow2::DrawRect: ren is NULL" << std::endl;
        return -1;
    }

    m_rect = rect;

    SDL_RenderFillRect(m_ren, &m_rect);

    return 0;
}

int jwsWindow2::DrawToScreen()
{
    SDL_RenderPresent(m_ren);
    return 0;
}

int jwsWindow2::Draw()
{
    DrawRect(m_rect);

    return 0;
}
