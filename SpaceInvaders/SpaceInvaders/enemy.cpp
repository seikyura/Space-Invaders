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
//TODO: inclResource
//#include "resource.h"
#include "utils.h"

// This Include
#include "enemy.h"

// Static Variables

// Static Function Prototypes

// Implementation

CEnemy::CEnemy()
: m_bHit(false)
, m_fVelocityX(0.0f)
, m_fVelocityY(0.0f)
, m_bCanShoot(false)
, m_bIsDead(false)
{
	srand(static_cast<unsigned int>(time(NULL)));
}

CEnemy::~CEnemy()
{
}

/********************
* CEnemy Initialiser: 
* - Initialises enemy entity with specified sprite, 
* - Sets each enemy with their own individual points
* @parameter: _spriteType - Sprite to be initialised with entity
* @return bool
*********************/
bool
CEnemy::Initialise(ESprite _spriteType)
{
	SetSpriteType(_spriteType);
    VALIDATE(CEntity::Initialise(_spriteType));
	int pointArray[5] = {10, 20, 30, 50, 100};

	switch(_spriteType)
	{
		case ESprite::ENEMYTOP: //smol squid
		{
			m_iPoints = 30;
			break;
		}
		case ESprite::ENEMYMED: //smol squid
		{
			m_iPoints = 20;
			break;
		}
		case ESprite::ENEMYBOT: //smol squid
		{
			m_iPoints = 10;
			break;
		}
		case ESprite::ENEMYSHIP: //smol squid
		{
			m_iPoints = pointArray[rand() % 4 + 0];
			break;
		}
	}

    return (true);
}

void
CEnemy::Draw()
{
    if (!m_bHit)
    {
        CEntity::Draw();
    }
}

void
CEnemy::Process(float _fDeltaTick)
{
	m_fX += m_fVelocityX;
	m_fY += m_fVelocityY;

    if (!m_bHit)
    {
        CEntity::Process(_fDeltaTick);
    }
}

float
CEnemy::GetVelocityX() const
{
	return (m_fVelocityX);
}

float
CEnemy::GetVelocityY() const
{
	return (m_fVelocityY);
}

void
CEnemy::SetVelocityX(float _fX)
{
	m_fVelocityX = _fX;
}

void
CEnemy::SetVelocityY(float _fY)
{
	m_fVelocityY = _fY;
}

void CEnemy::SetCanShoot(bool _b)
{
	m_bCanShoot = _b;
}

bool CEnemy::GetCanShoot()
{
	return m_bCanShoot;
}

void CEnemy::SetDead(bool _b)
{
	m_bIsDead = _b;
}

bool CEnemy::IsDead() const
{
	return m_bIsDead;
}

void
CEnemy::SetHit(bool _b)
{
    m_bHit = _b;
}

bool
CEnemy::IsHit() const
{
    return (m_bHit);
}

int CEnemy::GetEnemyPoints()
{
	return m_iPoints;
}
