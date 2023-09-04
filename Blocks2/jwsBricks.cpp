#include "jwsBricks.h"

jwsBricks::jwsBricks()
{
    //ctor
}

jwsBricks::~jwsBricks()
{
    //dtor
}

int jwsBricks::Init(SDL_Renderer *ren)
{
    if(ren == 0)
    {
        std::cout << "jwsBricks::Init: Failed: ren is NULL" << endl;
        return -1;
    }

    m_ren = ren;

    for(int i=0; i<BOARD_COL; i++)
    {
        char p[100];
        sprintf(p, "b%d.bmp", i+1);
        jwsString name = p;

        for(int j=0; j<BOARD_ROW; j++)
        {
            if(m_bricks[i][j].Init(name, m_ren, (i*108), (j*50+10)) != 0)
            {
                std::cout << "jwsBricks::Init: Failed" << endl;
                return -1;
            }
        }
    }

    return 0;
}

int jwsBricks::Draw()
{
    for(int i=0;i<BOARD_COL;i++)
    {
        for(int j=0; j<BOARD_ROW; j++)
        {
            m_bricks[i][j].Draw();
        }
    }
    return 0;
}

bool jwsBricks::Collision(SDL_Rect rect)
{
    SDL_Rect br;
    int bxc = rect.x + rect.w/2;
    int byc = rect.y + rect.h/2;

    for(int i=0; i<BOARD_COL; i++)
    {
        for(int j=0; j<BOARD_ROW; j++)
        {
            if(m_bricks[i][j].GetEnabled() == false)
            {
                continue;
            }

            br.x = m_bricks[i][j].GetRect().x;
            br.w = m_bricks[i][j].GetRect().w;
            br.h = m_bricks[i][j].GetRect().h;
            br.y = m_bricks[i][j].GetRect().y;

            if( (byc > br.y) && (byc < (br.y + br.h)) )
            {
                if( (bxc > br.x) && (bxc < (br.x + br.w)) )
                {
                    m_bricks[i][j].SetEnabled(false);

                    return true;
                }
            }
        }
    }

    return false;
}

void jwsBricks::Reset()
{
    for(int i=0; i<BOARD_COL; i++)
    {
        for(int j=0; j<BOARD_ROW; j++)
        {
            m_bricks[i][j].SetEnabled(true);
        }
    }
}

int jwsBricks::BricksAlive()
{
    int alive = 0;

    for(int i=0; i<BOARD_COL; i++)
    {
        for(int j=0; j<BOARD_ROW; j++)
        {
            if(m_bricks[i][j].GetEnabled() == true)
            {
                alive++;
            }
        }
    }

    return alive;
}

