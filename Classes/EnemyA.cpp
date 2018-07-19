#include "EnemyA.h"
#include "GameManager.h"
USING_NS_CC;

// ����Monster��С��
EnemyA* EnemyA::createMonster(std::vector<Point> points, int pointCounter) {
	auto monster = new EnemyA();
	if (monster && monster->init()) {
		monster->setPointsVector(points);
		monster->setMaxHp(100);
		monster->setCurrHp(100);
		monster->setMoney(20);
		monster->setForce(15); // ����15
		monster->setArmor(0); // ����0
		monster->setAttackBySoldier(true);
		monster->setAttackByTower(true);
		monster->setRunSpeed(50); // �ƶ��ٶ�50
		monster->pointCounter = pointCounter;
		monster->runNextPoint();
		monster->autorelease();
		return monster;
	}
	CC_SAFE_DELETE(monster);
	return NULL;
}

bool EnemyA::init() {
	if (!BaseMonster::init()) {
		return false;
	}
	setMonsterType(CANIBAL_OFFSPRING);
	//setName("CanibalBoos_Offspring_");
	setName("EnemyA");
	baseSprite = Sprite::createWithSpriteFrameName("monster/image 17016.png");
	addChild(baseSprite);
	createAndSetHpBar();
	lastState = stateNone;
	scheduleUpdate();
	addListener();
	return true;
}

void EnemyA::getHurt() {}

void EnemyA::death() {
	if (GameManager::getInstance()->monsterVector.contains(this)) {
		GameManager::getInstance()->monsterVector.eraseObject(this);
	}
	if (getState() != stateDeath) {
		setState(stateDeath);
		hpBgSprite->setVisible(false);
		baseSprite->stopAllActions();
		unscheduleUpdate();
		GameManager::getInstance()->MONEY = GameManager::getInstance()->MONEY + getMoney();
		// ������������
		baseSprite->runAction(Sequence::create(
			Animate::create(AnimationCache::getInstance()->getAnimation(getName() + "death")),
			CallFuncN::create(CC_CALLBACK_0(BaseMonster::setVisible, this, false))
			, NULL));
	}
}

// ��ը����
void EnemyA::explosion() {
	death();
}