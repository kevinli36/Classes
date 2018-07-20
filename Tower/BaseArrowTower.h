#pragma once
#include "cocos2d.h"
#include "BaseTower.h"
#include "./bullet/Bullet.h"

#define LEFT_ARCHER_SHOT 1
#define RIGHT_ARCHER_SHOT 1

USING_NS_CC;

class BaseArrowTower : public BaseTower
{
public:

protected:
	Sprite * shooter_1;
	Sprite* shooter_2;
	Sprite* towerBase;
	int shootTag;
	void initTower(int level);
	void addTerrain();
	virtual Bullet* ArrowTowerBullet();
	virtual void shoot(float dt);
};