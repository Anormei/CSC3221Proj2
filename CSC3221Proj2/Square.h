#pragma once

#include "Vec2.h"
#include "Shape.h"

class Square : public Shape {
public:
	Square();
	Square(float x, float y, float width, float right);
	Square(const Square& square);

	bool collidesWith(Shape* shape) const;

	void set(float x, float y, float width, float right);

	float left() const;
	float up() const;
	float right() const;
	float down() const;

	float getWidth() const;
	float getHeight() const;

	const Square operator=(const Square& shape);

private:
	
	float width;
	float height;
};
