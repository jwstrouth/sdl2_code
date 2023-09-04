#include "jwsEvent.h"

jwsEvent::jwsEvent()
{
    //ctor
}

jwsEvent::~jwsEvent()
{
    //dtor
}

bool jwsEvent::PollEvent(SDL_Event *event, Uint32 eventType)
{
    while(SDL_PollEvent(event))
    {
        if(event->type == eventType)
        {
            return true;
        }
    }

    return false;
}

bool jwsEvent::GetKeyboardState(Uint8 *key, Uint32 scanCode)
{
    key = const_cast <Uint8 *> (SDL_GetKeyboardState(NULL));
    if(key[scanCode])
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool jwsEvent::GetMouseState(int *x, int *y, Uint32 buttonType)
{
    Uint8 mstate = SDL_GetMouseState(x, y);

    if(mstate&SDL_BUTTON(SDL_BUTTON_LEFT))
    {
        return true;
    }

    return false;
}

bool jwsEvent::IsQuit()
{
    SDL_Event event;
    return PollEvent(&event, SDL_QUIT);
}

bool jwsEvent::IsEscape()
{
    Uint8 *key = 0;
    return GetKeyboardState(key, SDL_SCANCODE_ESCAPE);
}

bool jwsEvent::IsLeftButton(int *x, int *y)
{
    return GetMouseState(x, y, SDL_BUTTON_LEFT);
}

bool jwsEvent::IsSpace()
{
    Uint8 *key = 0;
    return GetKeyboardState(key, SDL_SCANCODE_SPACE);
}

