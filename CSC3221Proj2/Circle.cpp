#include "Circle.h"
#include <math.h>
#include <typeinfo>
#include "Line.h"
#include "Square.h"
#include <iostream>

using namespace std;

Circle::Circle() : Shape()
{
	radius = 0;
}

Circle::Circle(float radius) : Shape()
{
	this->radius = radius;
}

Circle::Circle(const Circle& circle) : Shape(circle)
{
	radius = circle.radius;
}

bool Circle::collidesWith(Shape* shape) const
{
	Circle* circle;
	Square* square;

	if (typeid(*shape) == typeid(Circle)) {
		circle = dynamic_cast<Circle*>(shape);
		Vec2 v = Vec2(*pos - *circle->pos);
		cout << "circle collision" << endl;
		return powf(v.x + v.y, 2) * 2 <= powf(radius + circle->radius, 2);
	}
	else if (typeid(*shape) == typeid(Square)) {
		square = dynamic_cast<Square*>(shape);

		Line line_top = Line(square->left(), square->up(), square->right(), square->up());
		Line line_right = Line(square->right(), square->up(), square->right(), square->down());
		Line line_bottom = Line(square->right(), square->down(), square->left(), square->down());
		Line line_left = Line(square->left(), square->down(), square->left(), square->up());

		Vec2 pos1 = *pos;
		Vec2 pos2 = Vec2(radius, 0);

		Vec2 mid = Vec2(square->pos->x + ((square->right() - square->left()) / 2.0f), square->pos->y + ((square->down() - square->up()) / 2.0f));

		Vec2 direction = pos1 - mid;

		float angle = direction.angle();

		pos2.rotate(angle);

		pos2 += pos1;

		Line line_circle = Line(pos1, pos2);

		cout << line_circle << ", square = " << *square->pos << ", angle = " << angle << ", mid = " << mid << endl;;

		return line_circle.intersects(line_top) || line_circle.intersects(line_right) || line_circle.intersects(line_bottom) || line_circle.intersects(line_left);
	}
	return false;
}

void Circle::set(float radius)
{
	this->radius = radius;
}

float Circle::getRadius() const
{
	return radius;
}

const Circle Circle::operator=(const Circle& shape)
{
	this->pos->x = shape.pos->x;
	this->pos->y = shape.pos->y;
	this->radius = shape.radius;

	return *this;
}
