#ifndef JWSSTATEMANAGER_H
#define JWSSTATEMANAGER_H

#include <stack>
#include "jwsGameState.h"

class jwsGameState;

class jwsStateManager
{
    public:
        jwsStateManager();
        virtual ~jwsStateManager();

        void AddState(jwsGameState *s);
        void PopState();
        void Update();
        void Draw();
        bool IsEmpty();

    protected:

    private:
        std::stack<jwsGameState*> m_states;
};

#endif // JWSSTATEMANAGER_H
