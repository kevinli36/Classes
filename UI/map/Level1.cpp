#include "Level1.h"

USING_NS_CC;

Level1::Level1()
{};

Level1::~Level1(){};

bool Level1::initWithDifficulty(int difficulty)
{
	CCLOG("level init with difficulty");
    if ( !Layer::init() )
    {
        return false;
    }
	SpriteFrameCache::getInstance()->addSpriteFramesWithFile("sprite_level1_2-hd.plist");
	setLevel(1);
	this->difficulty = difficulty;
	initMap();

	std::vector<Point> points;
	//road 0��ʾ
	points.push_back(Point(980,40));
	//road 1 ��ʾ
	points.push_back(Point(40,270));
	addWaveProgressBars(points);
	waveFlags.at(0)->restartWaveFlag();
	waveFlags.at(1)->restartWaveFlag();
//	SoundManager::playDesertBattle();
	return true;
}

Level1* Level1::createGame(int difficulty)
{  
	CCLOG("level1 create game");
   auto layer = new Level1();
	if(layer && layer->initWithDifficulty(difficulty)){
		layer->autorelease();
		return layer;
	}
	CC_SAFE_DELETE(layer);

    return NULL;
}

void Level1::addOrnament()
{

}

/*void Level1::onExit()
{
	CCLOG("level1 on exit");
	SpriteFrameCache::getInstance()->removeSpriteFrameByName("sprite_level1_2-hd.plist");
}*/

void Level1::addTerrains()
{
	auto terrain1 = KRTerrain::createTerrain(1);
	terrain1->setPosition(Point(455,535));//�յ�
	terrain1->setTag(1);
	addChild(terrain1,2);

	auto terrain13 = KRTerrain::createTerrain(1);
	terrain13->setPosition(Point(340,520));//�յ���
	terrain13->setTag(13);
	addChild(terrain13,3);

	auto terrain12 = KRTerrain::createTerrain(1);
	terrain12->setPosition(Point(670,530));//ˮͰ����
	terrain12->setTag(12);
	addChild(terrain12,4);

	auto terrain3 = KRTerrain::createTerrain(1);
	terrain3->setPosition(Point(325,500));//ˮͰ��
	terrain3->setTag(3);
	addChild(terrain3,4);

/*	auto terrain10 = KRTerrain::createTerrain(1);
	terrain10->setPosition(Point(430,440));//��Բ���Թս��������
	terrain10->setTag(10);
	addChild(terrain10,5);

	auto terrain7 = KRTerrain::createTerrain(1);
	terrain7->setPosition(Point(480,340));//��Բ���Թս����
	terrain7->setTag(7);
	addChild(terrain7,6);

	auto terrain9 = KRTerrain::createTerrain(1);
	terrain9->setPosition(Point(200,320));//���ɽ��2
	terrain9->setTag(9);
	addChild(terrain9,6);

	auto terrain6 = KRTerrain::createTerrain(1);
	terrain6->setPosition(Point(790,320));//��ţ���Թս����
	terrain6->setTag(6);
	addChild(terrain6,6);

	auto terrain2 = KRTerrain::createTerrain(1);
	terrain2->setPosition(Point(160,120));//��ɽ�Ե�һ�ս�
	terrain2->setTag(2);
	addChild(terrain2,7);

	auto terrain8 = KRTerrain::createTerrain(1);
	terrain8->setPosition(Point(140,240));//���ɽ��1
	terrain8->setTag(8);
	addChild(terrain8,7);

	auto terrain4 = KRTerrain::createTerrain(1);
	terrain4->setPosition(Point(480,180));//Բ���Թս�
	terrain4->setTag(4);
	addChild(terrain4,7);

	auto terrain5 = KRTerrain::createTerrain(1);
	terrain5->setPosition(Point(810,140));//ţ���Թս�
	terrain5->setTag(5);
	addChild(terrain5,8);

	auto terrain11 = KRTerrain::createTerrain(1);
	terrain11->setPosition(Point(420,100));//Բ���Թս���
	terrain11->setTag(11);
	addChild(terrain11,8);*/


}