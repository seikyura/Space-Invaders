//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2016 Media Design School.
//
// File Name	: 
// Description	: 
// Author		: Your Name
// Mail			: your.name@mediadesign.school.nz
//

// Library Includes

// Local Includes
//#include "resource.h"
#include "utils.h"

// This Include
#include "Player.h"

// Static Variables

// Static Function Prototypes

// Implementation

CPlayer::CPlayer()
{

}

CPlayer::~CPlayer()
{

}

bool
CPlayer::Initialise()
{
	//PLAYER SPRITES INITIALISE-------------------------------------------
    //VALIDATE(CEntity::Initialise(IDB_PlayerSPRITE, IDB_PlayerMASK)); 

    return (true);
}

void
CPlayer::Draw()
{
    CEntity::Draw();
}

void
CPlayer::Process(float _fDeltaTick)
{
    
	float fHalfPlayerW = m_pSprite->GetWidth() / 2.0f;

	if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
	{
		m_fX += 400.0f * _fDeltaTick;
	}
	else if (GetAsyncKeyState(VK_LEFT) & 0x8000)
	{ 
		m_fX -= 400.0f * _fDeltaTick;
	}
	if (m_fX - fHalfPlayerW <= 0)
	{
		m_fX = fHalfPlayerW;
	}
	else if (m_fX + fHalfPlayerW >= 385)
	{
		m_fX = 385-fHalfPlayerW;
	}
	
	CEntity::Process(_fDeltaTick);
}