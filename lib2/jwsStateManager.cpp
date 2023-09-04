#include "jwsStateManager.h"
#include <iostream>

jwsStateManager::jwsStateManager()
{
    //ctor
}

jwsStateManager::~jwsStateManager()
{
    //dtor
}

void jwsStateManager::AddState(jwsGameState *s)
{
    s->SetStateMgr(this);
    m_states.push(s);
}

void jwsStateManager::PopState()
{
    m_states.pop();
}

void jwsStateManager::Update()
{
    if(!m_states.empty())
    {
        if(m_states.top() != 0)
        {
            m_states.top()->Update();
        }
    }
}

void jwsStateManager::Draw()
{
    if(!m_states.empty())
    {
        if(m_states.top() != 0)
        {
            std::cout << "jwsStateManager::Draw" << std::endl;
            m_states.top()->Draw();
        }
    }
}

bool jwsStateManager::IsEmpty()
{
    return m_states.empty();
}

