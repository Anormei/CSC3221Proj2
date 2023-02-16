#pragma once
#define _USE_MATH_DEFINES
#include <math.h>
#include <ostream>

class Vec2 {
public:
	const float to_radians = (1.0f / 180.0f) * (float)M_PI;
	const float to_degrees = (1.0f / (float)M_PI) * 180.0f;

	float x;
	float y;

	Vec2();

	Vec2(float x, float y);

	Vec2(const Vec2& v);

	Vec2 set(float x, float y);
	Vec2 add(float x, float y);
	Vec2 sub(float x, float y);

	float length();
	Vec2 nor();

	float angle();
	Vec2 rotate(float angle);
	float dist(Vec2 v);
	float dist(float x, float y);

	const Vec2 operator=(const Vec2& v);
	const bool operator==(Vec2 v);
	const bool operator!=(Vec2 v);

	const Vec2 operator+(Vec2 v);
	const Vec2& operator+=(Vec2 v);

	const Vec2 operator-(Vec2 v);
	const Vec2& operator-=(Vec2 v);

	const Vec2 operator*(float scalar);
	const Vec2 operator*(Vec2 v);
	const Vec2& operator*=(Vec2 v);

	const Vec2 operator/(float scalar);

};

std::ostream& operator<<(std::ostream& outStream, const Vec2& vec);