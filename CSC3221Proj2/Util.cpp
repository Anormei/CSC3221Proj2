#include "Util.h"
#include <math.h>
#include <stdlib.h>
#include "Shape.h"
#include <iostream>

using namespace utils;
using namespace std;

float utils::randFloat(float min, float max) {
	float random = ((float)rand()) / (float)RAND_MAX;

	return (random * (max - min)) + min;
}

int utils::randInt(int min, int max) {
	return rand() % max + min;
}

float utils::to360(float d) {
	float degrees360 = d;

	if (degrees360 > 360.0f) {
		degrees360 = fmodf(degrees360, 360.0f);
	}

	if (degrees360 < 0.0f) {
		degrees360 = 360.0f - fmodf(fabsf(degrees360), 360.0f);
	}

	return degrees360;
}

vector<Shape*> utils::detectCollision(const Shape &shape, vector<Shape*> shapes)
{
	vector<Shape*> collisions;

	for (int i = 0; i < shapes.size(); i++) {
		//cout << "index = " << i << endl;
		bool result = shape.collidesWith(shapes[i]);
		cout << "result: " << result << endl;
		if (result) {

			collisions.emplace_back(shapes[i]);
		}
	}
	return collisions;
}
