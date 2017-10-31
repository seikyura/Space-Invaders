//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2016 Media Design School
//
// File Name	: "Game.h"
// Description	: Declaration file for Game
// Author		: Vivian Ngo
// Mail			: vivian.ngo7572@mediadesign.school.nz
//

#if !defined(__GAME_H__)
#define __GAME_H__

// Library Includes
#include <Windows.h>

// Local Includes
#include "clock.h"
#include "level.h"
#include "utils.h"
#include "LevelLogic.h"

// Types

// Constants

// Prototypes
class CBackBuffer;

enum EGameState
{
	MENU, GAME, LOST
};

class CGame
{
    // Member Functions
public:
    ~CGame();

    bool Initialise(HINSTANCE _hInstance, HWND _hWnd, int _iWidth, int _iHeight);

    void Draw();
    void Process(float _fDeltaTick);

    void ExecuteOneFrame();
	void GameOverWon();
	void GameOverLost();

    CBackBuffer* GetBackBuffer();
    HINSTANCE GetAppInstance();
    HWND GetWindow();

    // Singleton Methods
	static CLevel& GetLevelInstance();
	static CLevelLogic& GetLevelController();

    static CGame& GetInstance();
    static void DestroyInstance();

protected:

private:
    CGame();
    CGame(const CGame& _kr);
    CGame& operator= (const CGame& _kr);
	EGameState m_gameState;


    // Member Variables
public:

protected:
    CClock* m_pClock;
	static CLevel* m_pLevel;
	CBackGround* m_pMenu;
    CBackBuffer* m_pBackBuffer;
	
    //Application data
    HINSTANCE m_hApplicationInstance;
    HWND m_hMainWindow;

    // Singleton Instance
    static CGame* s_pGame;

private:

};

#endif    // __GAME_H__
