#include "Vec2.h"

Vec2::Vec2()
{
	x = 0;
	y = 0;
}

Vec2::Vec2(float x, float y) {
	this->x = x;
	this->y = y;
}

Vec2::Vec2(const Vec2& v)
{
	x = v.x;
	y = v.y;
}

Vec2 Vec2::set(float x, float y)
{
	this->x = x;
	this->y = y;
	return *this;
}

Vec2 Vec2::add(float x, float y)
{
	this->x += x;
	this->y += y;
	return *this;
}

Vec2 Vec2::sub(float x, float y)
{
	this->x -= x;
	this->y -= y;
	return Vec2();
}

float Vec2::length()
{
	return sqrtf(x * x + y * y);
}

Vec2 Vec2::nor()
{
	float len = length();
	if (len != 0) {
		this->x /= len;
		this->y /= len;
	}
	return *this;
}


float Vec2::angle()
{
	float angle = atan2f(y, x) * to_degrees;
	if (angle < 0) {
		angle += 360.0f;
	}
	return angle;
}

Vec2 Vec2::rotate(float angle)
{
	float rad = angle * to_radians;
	float cos = cosf(rad);
	float sin = sinf(rad);

	float newX = this->x * cos - this->y * sin;
	float newY = this->x * sin + this->y * cos;

	this->x = newX;
	this->y = newY;

	return *this;
}

float Vec2::dist(Vec2 v)
{
	float distX = this->x - v.x;
	float distY = this->y - v.y;
	return sqrtf(distX * distX + distY * distY);
}

float Vec2::dist(float x, float y)
{
	float distX = this->x - x;
	float distY = this->y - y;
	return sqrtf(distX * distX + distY * distY);
}

const Vec2 Vec2::operator=(const Vec2& v)
{
	this->x = v.x;
	this->y = v.y;
	return *this;
}

const bool Vec2::operator==(Vec2 v)
{
	return this->x == v.x && this->y == v.y;
}

const bool Vec2::operator!=(Vec2 v)
{
	return this->x != v.x && this->y != v.y;
}

const Vec2 Vec2::operator+(Vec2 v)
{
	return Vec2(this->x + v.x, this->y + v.y);
}

const Vec2& Vec2::operator+=(Vec2 v)
{
	this->x = this->x + v.x;
	this->y = this->y + v.y;
	return *this;
}

const Vec2 Vec2::operator-(Vec2 v)
{
	return Vec2(this->x - v.x, this->y - v.y);
}

const Vec2& Vec2::operator-=(Vec2 v)
{
	this->x = this->x - v.x;
	this->y = this->y - v.y;
	return *this;
}

const Vec2 Vec2::operator*(float scalar)
{
	return Vec2(this->x * scalar, this->y * scalar);
}

const Vec2 Vec2::operator*(Vec2 v)
{
	return Vec2(this->x * v.x, this->y * v.y);
}

const Vec2& Vec2::operator*=(Vec2 v)
{
	this->x = this->x * v.x;
	this->y = this->y * v.y;
	return *this;
}

const Vec2 Vec2::operator/(float scalar)
{
	if (scalar == 0) {
		return Vec2(this->x, this->y);
	}
	return Vec2(this->x / scalar, this->y / scalar);
}

std::ostream& operator<<(std::ostream& outStream, const Vec2& vec)
{
	outStream << "x: " << vec.x << ", y: " << vec.y;

	return outStream;
}
