#pragma once
#if !defined(__ESPRITE_H__)
#define __ESPRITE_H__

enum class ESprite
{
	ENEMYTOP,
	ENEMYMED,
	ENEMYBOT,
	ENEMYSHIP,
	BACKGROUND,
	MAINMENU,
	BARRICADE,
	BULLET,
	PLAYER,
	DEADPLAYER,
	DEADTOP,
	DEADMED,
	DEADBOT

};


enum class EGameState
{
	MENU, GAME, LOST
};

#endif    // __ESPRITE_H__