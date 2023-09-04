#ifndef JWSGAMESTATE_H
#define JWSGAMESTATE_H

#include "jwsStateManager.h"

class jwsStateManager;

class jwsGameState
{
    public:
        jwsGameState();
        virtual ~jwsGameState();

        virtual void Update();
        virtual void Draw();

        // getters / setters
        jwsStateManager *GetStateMgr(){ return m_stateMgr; }
        void SetStateMgr(jwsStateManager *stateMgr){ m_stateMgr = stateMgr; }

    protected:

    private:
        jwsStateManager *m_stateMgr;
};

#endif // JWSGAMESTATE_H
