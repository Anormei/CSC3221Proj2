#pragma once

#include "Vec2.h"
#include <string>

class Shape {
public:

	Shape();
	Shape(float x, float y);
	Shape(Vec2 v);
	Shape(const Shape &shape);
	~Shape();

	virtual bool collidesWith(Shape* shape) const = 0;
	Vec2 move();

	Vec2* pos;
};