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
#include <jwsRandomNumber.h>

int main(int argc, char* args[])
{
    jwsRandomNumber rn;
    for(int i=0;i<100;i++)
    {
        cout << "Random Number (0-10): " << rn.RandNum(10) << "\n";
    }
    jwsFighterMgr jwsFM;
    return jwsFM.Run();
}


