#include "ParabolaTo.h"


CCEaseInOut* ParabolaTo::create(float t, CCPoint startPoint, CCPoint endPoint, float height  , float angle /* = 60 */) {

	// �ѽǶ�ת��Ϊ����
	float radian = angle * 3.14159 / 180.0;
	// ��һ�����Ƶ�Ϊ��������뻡���е�
	float q1x = startPoint.x + (endPoint.x - startPoint.x) / 4.0;
	CCPoint q1 = ccp(q1x, height + startPoint.y + cos(radian)*q1x);
	// �ڶ������Ƶ�Ϊ���������ߵ��е�
	float q2x = startPoint.x + (endPoint.x - startPoint.x) / 2.0;
	CCPoint q2 = ccp(q2x, height + startPoint.y + cos(radian)*q2x);

	//��������
	ccBezierConfig cfg;
	cfg.controlPoint_1 = q1;
	cfg.controlPoint_2 = q2;
	cfg.endPosition = endPoint;
	//ʹ��CCEaseInOut�������˶���һ����������ı仯���Եø���Ȼ
	return CCEaseInOut::create(CCBezierTo::create(t, cfg), 0.5);
}

CCEaseInOut * ParabolaTo::create(float t, CCPoint startPoint, CCPoint endPoint)
{
	double height = endPoint.y - startPoint.y;
	double angle = getAngle(startPoint, endPoint);
	return create(t, startPoint, endPoint, height, angle);
}
float ParabolaTo::getAngle(Vec2 source, Vec2 end)
{
	auto dx = end.x - source.x;
	auto dy = end.y - source.y;
	auto t = dx / dy;
	if (t >= -2 && t <= 2) {
		if (dy >= 0) {
			return 90;
		}
		else {
			if (dx <= 0) {
				return 0;
			}
			else {
				return 45;
			}
		}
	}
	else {
		if (dx >= 0) {
			return 70;
		}
		return 45;
	}
}

