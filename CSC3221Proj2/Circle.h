#pragma once
#include "Vec2.h"
#include "Shape.h"

class Circle : public Shape {
public:

	Circle();
	Circle(float radius);
	Circle(const Circle& circle);

	bool collidesWith(Shape* shape) const;

	void set(float radius);
	float getRadius() const;

	const Circle operator=(const Circle& shape);

private:
	float radius;
};
