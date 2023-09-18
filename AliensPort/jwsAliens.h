#ifndef JWSALIENS_H
#define JWSALIENS_H

#include <jwsImage2.h>
#include <jwsWindow2.h>
#include <jwsEvent.h>
#include <jwsPlayer.h>
#include <jwsExplode.h>

const int MAX_ALIENS = 30;
//const int EXPLOSION_TIME = 4;

class jwsAlien
{
    public:
        jwsAlien()
        {
            m_dirx = 1;
            m_alive = false;
            m_explosionTime = 0;
        }
        ~jwsAlien(){}

        int Init(jwsWindow2 *wnd);
        int Draw();
        void SetExplosion(){ m_explode.SetTime(); cout << "jwsAlien::SetExplosion\n"; };
        void DrawExplosion();

        void ReverseDirx(){ m_dirx *= -1; }

        // getters / setters
        void SetX(int x){ m_image.SetDX(x); }
        void SetY(int y){ m_image.SetDY(y); }
        void SetW(int w){ m_image.SetDW(w); }
        void SetH(int h){ m_image.SetDH(h); }
        int GetX(){ return m_image.GetDX(); }
        int GetY(){ return m_image.GetDY(); }
        int GetW(){ return m_image.GetDW(); }
        int GetH(){ return m_image.GetDH(); }
        bool IsAlive(){ return m_alive; }
        void SetAlive(){ m_alive = true; }
        void SetDead(){ m_alive = false; }
        int GetDirx(){ return m_dirx; }
        jwsImage2 *GetImage(){ return & m_image; }

    protected:

    private:
        jwsImage2   m_image;
        int         m_dirx;
        bool        m_alive;
        jwsExplode  m_explode;
        int         m_explosionTime;
};

class jwsAliens
{
    public:
        jwsAliens();
        virtual ~jwsAliens();

        int Init(jwsWindow2 *wnd);
        int Draw();
        int Create(jwsWindow2 *wnd);
        int Move(jwsWindow2 *wnd);

        // getter / setters
        jwsImage2 *GetImage(int i){ return m_aliens[i].GetImage(); }
        bool IsAlive(int i){ return m_aliens[i].IsAlive(); }
        void SetDead(int i){ m_aliens[i].SetDead(); }
        void SetExplosion(int i);

    protected:

    private:
        jwsAlien    m_aliens[MAX_ALIENS];
};

#endif // JWSALIENS_H
