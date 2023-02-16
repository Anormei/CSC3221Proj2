#include "Square.h"
#include <typeinfo>
#include "Line.h"
#include "Circle.h"

Square::Square() : Shape()
{
	pos->x = 0;
	pos->y = 0;
	width = 0;
	height = 0;
}

Square::Square(float x, float y, float width, float height) : Shape(x, y)
{
	pos->x = x;
	pos->y = y;
	this->width = width;
	this->height = height;
}

Square::Square(const Square& square) : Shape(square)
{
	width = square.width;
	height = square.height;
}

bool Square::collidesWith(Shape* shape) const
{
	Square* square;
	Circle* circle;

	if (typeid(*shape) == typeid(Square)) {
		square = dynamic_cast<Square*>(shape);
		return left() <= square->right() &&
			up() >= square->down() &&
			right() >= square->left() &&
			down() <= square->up();
	}
	else if (typeid(*shape) == typeid(Circle)) {
		circle = dynamic_cast<Circle*>(shape);

		Line line_top = Line(left(), up(), right(), up());
		Line line_right = Line(right(), up(), right(), down());
		Line line_bottom = Line(right(), down(), left(), down());
		Line line_left = Line(left(), down(), left(), up());

		Vec2 pos1 = *circle->pos;
		Vec2 pos2 = Vec2(circle->pos->x + circle->getRadius(), circle->pos->y);

		Vec2 mid = Vec2(pos->x + ((right() - left()) / 2.0f), pos->y + ((down() - up()) / 2.0f));

		Vec2 direction = pos1 - mid;

		float angle = direction.angle();

		pos2.rotate(angle);

		Line line_circle = Line(pos1, pos2);

		return line_circle.intersects(line_top) || line_circle.intersects(line_right) || line_circle.intersects(line_bottom) || line_circle.intersects(line_left);
	}
	return false;
}

void Square::set(float x, float y, float width, float height)
{
	pos->x = x;
	pos->y = y;
	this->width = width;
	this->height = height;
}

float Square::left() const
{
	return pos->x;
}

float Square::up() const
{
	return pos->y;
}

float Square::right() const
{
	return pos->x + width;
}

float Square::down() const
{
	return pos->y + height;
}


float Square::getWidth() const
{
	return width;
}

float Square::getHeight() const
{
	return height;
}

const Square Square::operator=(const Square& shape)
{
	this->pos->x = shape.pos->x;
	this->pos->y = shape.pos->y;
	this->width = shape.width;
	this->height = shape.height;

	return *this;
}