#include "Efreeti.h"
#include "GameManager.h"
USING_NS_CC;

// ����
Efreeti* Efreeti::createMonster(std::vector<Point> points, int pointCounter) {
	auto monster = new Efreeti();
	if (monster && monster->init()) {
		monster->setPointsVector(points);
		monster->setMaxHp(100);
		monster->setCurrHp(100);
		monster->setMoney(20);
		monster->setForce(15); // ����15
		monster->setArmor(0); // ����0
		monster->setAttackBySoldier(true);
		monster->setAttackByTower(true);
		monster->setRunSpeed(50); // �ٶ�50
		monster->pointCounter = pointCounter + 10;
		monster->runNextPoint();
		monster->autorelease();
		return monster;
	}
	CC_SAFE_DELETE(monster);
	return NULL;
}