#pragma once
#include "cocos2d.h"
USING_NS_CC;

// �������˶�
class ParabolaTo
{
public:
	/*����һ�������߶���
	������
	t					ʱ��
	startPoint		��ʼ��
	endPoint		������
	height			�߶ȣ�Ӱ�������ߵĸ߶ȣ�
	angle			�Ƕȣ������������������Ƶ���y��ļнǣ�ֱ��Ӱ�쾫����׳��Ƕȣ�
	*/
	static CCEaseInOut* create(float t, CCPoint startPoint, CCPoint endPoint, float height , float angle = 60);
	static float getAngle(Vec2 source, Vec2 end);
	static CCEaseInOut* create(float t, CCPoint startPoint, CCPoint endPoint);
};
