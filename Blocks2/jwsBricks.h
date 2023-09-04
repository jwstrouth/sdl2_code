#ifndef JWSBRICKS_H
#define JWSBRICKS_H

#include "jwsBrick.h"

const int NAMES_MAX = 20;
const int BOARD_ROW = 12;
const int BOARD_COL = 12;

class jwsBricks
{
    public:
        jwsBricks();
        virtual ~jwsBricks();

        int Init(SDL_Renderer *ren);
        int Draw();
        bool Collision(SDL_Rect rect);
        void Reset();
        int BricksAlive();

    protected:

    private:
        jwsBrick m_bricks[BOARD_ROW][BOARD_COL];
        SDL_Renderer *m_ren;
};

#endif // JWSBRICKS_H
