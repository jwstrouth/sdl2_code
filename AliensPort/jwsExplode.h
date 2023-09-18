#ifndef JWSEXPLODE_H
#define JWSEXPLODE_H

#include <jwsImage2.h>
#include <jwsString.h>
#include <jwsWindow2.h>
#include <jwsAudio.h>

const int EXPLOSION_TIME        = 4;
const int EXPLOSION_SOUND_TIME  = 500;

class jwsExplode : public jwsImage2, public jwsAudio
{
    public:
        jwsExplode();
        virtual ~jwsExplode();

        // overloading issue
        using jwsImage2::Load; // this is needed so compiler searches base class for other overload function
        void Load(jwsWindow2 &wnd);
        using jwsImage2::Draw;
        void Draw(int x, int y);

        // getter / setter
        void SetTime(){ m_time =  EXPLOSION_TIME; }

    protected:

    private:
        int m_time;
};

#endif // JWSEXPLODE_H
