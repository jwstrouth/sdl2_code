#include "jwsBlocksMgr.h"
#include "jwsGlobals.h"

jwsBlocksMgr::jwsBlocksMgr()
{
    m_name = "BLOCKS 2";
    m_rect = {FS_X, FS_Y, FS_W-FS_W_OS, FS_H-FS_H_OS};
    m_run = true;
    m_color = {FS_RED, FS_GREEN, FS_BLUE, FS_COLOR_MASK};
    m_lives = 3;
    m_gameover = false;
}

jwsBlocksMgr::~jwsBlocksMgr()
{
    //dtor
}

int jwsBlocksMgr::Init()
{
    // window's field
    if(m_wnd.Init(m_name, m_rect.x, m_rect.y, m_rect.w, m_rect.h, 0) != 0)
    {
        std::cout << "jwsBlocksMgr::Init: Failed" << std::endl;
        return -1;
    }

    // main field - ball's field
    if(m_area1.Load("blocksArea1.bmp", m_wnd.GetRen(), 255, 0, 255) != 0)
    {
        std::cout << "jwsBlocksMgr::Init: Failed" << std::endl;
        return -1;
    }

    // score keep field
    if(m_area2.Load("blocksArea2.bmp", m_wnd.GetRen(), 255, 0, 255) != 0)
    {
        std::cout << "jwsBlocksMgr::Init: Failed" << std::endl;
        return -1;
    }

    // put scoring to the right of playing field
    m_area2.SetDX(m_area1.GetDW());

    // set ball's field based on playing field...keep in mind the FS_H_OS offset
    if(m_ball.Init(m_wnd.GetRen(), m_area1.GetDW(), (m_area1.GetDH() - FS_H_OS)) != 0)
    {
        std::cout << "jwsBlocksMgr::Init: Failed" << std::endl;
        return -1;
    }

    // paddle field based on area1
    if(m_paddle.Init(m_wnd.GetRen(), m_area1.GetDW(), (m_area1.GetDH() - FS_H_OS)) != 0)
    {
        std::cout << "jwsBlocksMgr::Init: Failed" << std::endl;
        return -1;
    }

    // bricks used for area1
    if(m_bricks.Init(m_wnd.GetRen()) != 0)
    {
        std::cout << "jwsBlocksMgr::Init: Failed" << std::endl;
        return -1;
    }

    // game status that is displayed in area2
    if(m_status.Init(&m_wnd, m_area2.GetDRect())!= 0)
    {
        std::cout << "jwsBlocksMgr::Init: Failed" << std::endl;
        return -1;
    }

    // music that playes and repeats for game
    if(m_music.Init() != 0)
    {
        std::cout << "jwsBlocksMgr::Init: Failed" << std::endl;
        return -1;
    }

    return 0;
}

int jwsBlocksMgr::ProcEvents()
{
    // window's top-right 'x' to close application
    if(m_event.IsQuit() == true)
    {
        m_run = false;
    }

    // escape (esc) key to close application
    if(m_event.IsEscape() == true)
    {
        m_run = false;
    }

    if(m_event.IsSpace() == true)
    {
        m_gameover = false;
        m_lives = 3;
        m_status.SetGameover(false);
        m_music.Start();
    }

    return 0;
}

int jwsBlocksMgr::Draw()
{
    // setup window drawing
    m_wnd.DrawClear();
    m_wnd.DrawColor(m_color);
    m_wnd.Draw();

    // other objects drawing
    m_area1.Draw();
    m_area2.Draw();
    m_ball.Draw();
    m_paddle.Draw();
    m_bricks.Draw();
    m_status.Draw(m_bricks.BricksAlive(), m_lives);

    return 0;
}

int jwsBlocksMgr::Term()
{
    m_music.Term();
    m_wnd.Term();

    return 0;
}

int jwsBlocksMgr::Update()
{
    if(m_gameover == false)
    {
    if( (m_ball.Update() == true) )
    {
        // check to see paddle missed ball

        m_bricks.Reset();
        if(--m_lives == 0)
        {
            //m_lives = 3;
            GameOver();
        }
    }
    }

    m_paddle.Update();

    // paddle, ball, and bricks collision checking

    if(m_paddle.Collision(m_ball.GetRect()) == true)
    {
        m_ball.ReverseY();
    }

    if(m_bricks.Collision(m_ball.GetRect()) == true)
    {
        m_ball.ReverseY();
    }

    if(m_bricks.BricksAlive() == 0)
    {
        GameOver();
        m_bricks.Reset();
    }

    return 0;
}

int jwsBlocksMgr::GameOver()
{
    m_gameover = true;
    m_status.SetGameover(true);
    m_music.Stop();
    return 0;
}

