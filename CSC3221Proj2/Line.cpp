#include "Line.h"
#include <iostream>

using namespace std;

Line::Line()
{

}

Line::Line(float x1, float y1, float x2, float y2)
{
	pos1 = Vec2(x1, y1);
	pos2 = Vec2(x2, y2);
}

Line::Line(Vec2 pos1, Vec2 pos2)
{
	this->pos1 = pos1;
	this->pos2 = pos2;
}

bool Line::intersects(Line line)
{


	float a1 = pos2.y - pos1.y;
	float b1 = pos1.x - pos2.x;
	//float c1 = a1 * (pos1.x) + b1 * (pos1.y);

	float a2 = line.pos2.y - line.pos1.y;
	float b2 = line.pos1.x - line.pos2.x;
	//float c2 = a2 * (line.pos1.x) + b2 * (line.pos1.y);

	return a1 * b2 - a2 * b1 > 0;
}

Vec2 Line::getPos1() const
{
	return pos1;
}

Vec2 Line::getPos2() const
{
	return pos2;
}

std::ostream& operator<<(std::ostream& outStream, const Line& line)
{
	outStream << "pos1: " << line.getPos1() << ", pos2: " << line.getPos2();
	return outStream;
}
