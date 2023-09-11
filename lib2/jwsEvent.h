#ifndef JWSEVENT_H
#define JWSEVENT_H

#include <iostream>
#include "SDL.h"

class jwsEvent
{
    public:
        jwsEvent();
        virtual ~jwsEvent();

        bool PollEvent(SDL_Event *event, Uint32 eventType);
        bool GetKeyboardState(Uint8 *key, Uint32 scanCode);
        bool GetMouseState(int *x, int *y, Uint32 buttonType);

        bool IsQuit();
        bool IsEscape();
        bool IsLeftButton(int *x, int *y);
        bool IsSpace();
        bool IsLeft();
        bool IsRight();

    protected:

    private:
};

#endif // JWSEVENT_H
