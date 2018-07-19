#include "cocos2d.h"
#include "terrain.h"


USING_NS_CC;

class BaseMap : public Layer
{
public:
	CREATE_FUNC(BaseMap);
	//��ǰ�ؿ�
	CC_SYNTHESIZE(int, level, Level);
	//��ͼ����
	Sprite* mapSprite;
protected:
	void initTouchLayer();
	//��Ļ�ߴ�
	Size winSize;
	//���ó�ʼ��ͼλ��
	void setMapPosition();
	//��ʼ����ͼ
	void initMap();
	//��ӽ�����
	virtual void addTerrains() {};
	virtual void onExit() {};
};