#include "jwsFont.h"

jwsFont::jwsFont()
{
    m_rect = {0, 0, 20, 20};
    m_color = {255, 255, 255, 0};
    m_font = 0;
}

jwsFont::~jwsFont()
{
    if(m_font)
    {
        TTF_CloseFont(m_font);
    }

    TTF_Quit();
}

int jwsFont::Init(jwsString name, SDL_Renderer *ren)
{
    if(ren == 0)
    {
        std::cout << "jwsFont::Init: ren is NULL" << std::endl;
        return -1;
    }

    m_ren = ren;

    if(TTF_Init() != 0)
    {
        std::cout << "jwsFont::Init: " << SDL_GetError() << std::endl;
        return -1;
    }


    m_font = TTF_OpenFont(name.GetData(), 10);
    if(m_font == NULL)
    {
        std::cout << "jwsFont::Init: " << SDL_GetError() << std::endl;
        return -1;
    }

    return 0;
}

int jwsFont::Draw()
{
    SDL_Surface *textSur = TTF_RenderText_Solid(m_font, m_text, m_color);
    if(textSur == 0)
    {
        std::cout << "jwsFont::Draw: " << SDL_GetError() << std::endl;
        return -1;
    }

    SDL_Texture *tex = SDL_CreateTextureFromSurface(m_ren, textSur);
    if(tex == 0)
    {
        SDL_FreeSurface(textSur);
        std::cout << "jwsFont::Draw: " << SDL_GetError() << std::endl;
        return -1;
    }

    m_rect.w = textSur->w;
    m_rect.h = textSur->h;

    SDL_RenderCopy(m_ren, tex, NULL, &m_rect);

    SDL_DestroyTexture(tex);
    SDL_FreeSurface(textSur);

    return 0;
}

