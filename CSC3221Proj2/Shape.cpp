#include "Shape.h"
#include "Util.h"

using namespace utils;

Shape::Shape()
{
	pos = new Vec2(0, 0);
}

Shape::Shape(float x, float y)
{
	pos = new Vec2(x, y);
}

Shape::Shape(Vec2 v)
{
	pos = new Vec2(v);
}

Shape::Shape(const Shape& shape)
{
	pos = new Vec2(shape.pos->x, shape.pos->y);
}


Shape::~Shape()
{
	if (pos != nullptr) {
		delete pos;
		pos = nullptr;
	}
}

Vec2 Shape::move() {
	return Vec2(randFloat(0, 1.0f), randFloat(0, 1.0f));
}