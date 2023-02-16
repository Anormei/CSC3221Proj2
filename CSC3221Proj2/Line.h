#pragma once
#include "Vec2.h"

class Line {
public:
	Line();
	Line(float x1, float y1, float x2, float y2);
	Line(Vec2 pos1, Vec2 pos2);

	bool intersects(Line line);

	Vec2 getPos1() const;
	Vec2 getPos2() const;

private:
	Vec2 pos1;
	Vec2 pos2;
};

std::ostream& operator<<(std::ostream& outStream, const Line& line);