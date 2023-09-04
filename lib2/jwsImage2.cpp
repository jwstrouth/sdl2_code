#include "jwsImage2.h"

jwsImage2::jwsImage2()
{
    //ctor
}

jwsImage2::~jwsImage2()
{
    //dtor
}

int jwsImage2::Load(jwsString name, SDL_Renderer *ren, int r, int g, int b)
{
    SDL_Surface *image = 0;
    Uint32 colorKey;

    if(ren == 0)
    {
        std::cout << "jwsImage2::Load: Failed: ren is NULL" << std::endl;
        return -1;
    }

    image = IMG_Load((char*)name.GetData());
    if(image == 0)
    {
        std::cout << "jwsImage2::Load: Failed: " << SDL_GetError() << std::endl;
        return -1;
    }

    m_dRect.x = 0;
    m_dRect.y = 0;
    m_dRect.w = image->w;
    m_dRect.h = image->h;

    m_sRect.x = 0;
    m_sRect.y = 0;
    m_sRect.w = image->w;
    m_sRect.h = image->h;

    m_ren = ren;

    colorKey = SDL_MapRGB(image->format, r, g, b);
    SDL_SetColorKey(image, SDL_TRUE, colorKey);

    m_tex = SDL_CreateTextureFromSurface(ren, image);
    if(m_tex == 0)
    {
        std::cout << "jwsImage2::Load: Failed: " << SDL_GetError() << std::endl;
        SDL_FreeSurface(image);
        return -1;
    }
    SDL_FreeSurface(image);

    return 0;
}

int jwsImage2::Draw()
{
    if(SDL_RenderCopy(m_ren, m_tex, &m_sRect, &m_dRect) != 0)
    {
        std::cout << "jwsImage2::Draw: Failed: " << SDL_GetError() << std::endl;
        return -1;
    }

    return 0;
}

int jwsImage2::SetColor(int r, int g, int b)
{
    SDL_SetRenderDrawColor(m_ren, r, g, b, 255);

    return 0;
}

int jwsImage2::DrawLine(int x1, int y1, int x2, int y2)
{
    SDL_RenderDrawLine(m_ren, x1, y1, x2, y2);

    return 0;
}

