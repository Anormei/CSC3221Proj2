#pragma once
#include <vector>
#include "Shape.h"

namespace utils {
	const float board_size = 200.0f;
	const float diagonal = 45.0f;
	const float straight = 0.0f;
	const float next_angle = 90.0f;
	const int max_pieces = 30;
	const int max_moves = 100;


	float randFloat(float min, float max);
	int randInt(int min, int max);
	float to360(float d);
	std::vector<Shape*> detectCollision(const Shape &shape, std::vector<Shape*> shapes);

}