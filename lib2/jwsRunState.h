#ifndef JWSRUNSTATE_H
#define JWSRUNSTATE_H

#include <jwsGameState.h>
#include "jwsEvent.h"
#include "jwsImage2.h"

class jwsRunState : public jwsGameState
{
    public:
        jwsRunState();
        virtual ~jwsRunState();

        bool Init(jwsStateManager *m, SDL_Renderer *ren);
        void Term();
        virtual void Update();
        virtual void Draw();

    protected:

    private:
        jwsEvent m_event;
        jwsImage2 m_image1;
        jwsImage2 m_image2;

};

#endif // JWSRUNSTATE_H
