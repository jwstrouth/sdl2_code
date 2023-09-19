/* @file main.cpp
 *
 * @brief the main entry point for JWSFighter example
 *
 * @author James Strouth
 * Contact: jamesstrouth@gmail.com
 *
 */

#include <SDL2/SDL.h>
#include <iostream>

#include <jwsFighterMgr.h>

int main(int argc, char* args[])
{
    jwsFighterMgr jwsFM;
    return jwsFM.Run();
}


