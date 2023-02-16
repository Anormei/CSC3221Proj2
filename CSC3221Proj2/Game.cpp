
#include "Util.h"
#include <iostream>
#include <time.h>
#include <vector>
#include "Square.h"
#include "Circle.h"

using namespace std;
using namespace utils;

/*
*	Extending the program to work in 3  dimensions.
*	
*	1. To extend this program to work with 3 dimensions, the program will need
*	   to implement a Vector3 class that will include a 3rd axis: the z-axis.
* 
*	2. The program will also need to consider other additional values to supplement
*	   the 3rd dimension. For example, the game board size will need to be extended on
*	   the z-axis, random movement must include movement on the z-axis, and size must be
*	   distributed on the z-axis.
* 
*	3. Collision detection would need major work in to extend to the z-axis, although not too complex
	   since most of it is just line collisions, but on a 3d-axis. But essentially:
*	   
	   For sphere-to-sphere collision: similar to circle-to-circle collision, the program would only
*	   have to calculate the distance between the sphere's centers and then calculate whether or not
*	   these points overlap the sphere's radii.
* 
*	   For cube-to-cube collision: The program would have to check every line segments that create the
*	   cube instead of checking 4 sides of a square. So for a cube, that would be 12(?) line segments.
* 
*	   For cube-to-sphere collision: The program would do something similar to square-to-circle collision,
*	   except this time, it compares all the line segments of the cube.
*	   
*/

int main() {
	srand(time(NULL));

	vector<Shape*> shapes;
	cout << "GAME_START" << endl;

	cout << "Initializing squares..." << endl;

	for (int i = 0; i < max_pieces / 5; i++) {
		Square* square = new Square(randFloat(0, board_size), randFloat(0, board_size), 10, 10);
		cout << "running" << endl;
		cout << *square->pos << endl;
		while (detectCollision(*square, shapes).size() > 0) {
			square->pos->set(randFloat(0, board_size), randFloat(0, board_size));
			cout << " " << *square->pos <<  endl;
		}

		shapes.emplace_back(square);
		square = nullptr;
	}

	cout << "Initializing circles..." << endl;

	for (int i = 0; i < max_pieces / 4; i++) {
		Circle* circle = new Circle(5.0f);
		circle->pos->set(randFloat(0, board_size), randFloat(0, board_size));
		int size = detectCollision(*circle, shapes).size();
		while (size > 0) {
			float x = randFloat(0, board_size);
			float y = randFloat(0, board_size);
			circle->pos->set(x, y);

			//cout << size << " " << *circle->pos << " " << Vec2(x, y) << endl;
			size = size = detectCollision(*circle, shapes).size();
		}

		shapes.emplace_back(circle);
		circle = nullptr;
	}

	cout << "Playing game..." << endl;

	for (int i = 0; i < max_moves && shapes.size() > 1; i++) {
		vector<Shape*>::iterator it = shapes.begin();

		cout << "Move[" << i << "]" << endl;

		while (it != shapes.end()) {
			int index = std::distance(shapes.begin(), it);
			cout << "Shape[" << index << "] " << endl;
			Vec2 move = (*it)->move();

			string name = (typeid(it) == typeid(Square) ? "Square" : "Circle");

			cout << name << " has moved by (" << move << ")" << endl;
			vector<Shape*> collisions = detectCollision(*(*it), collisions);
			cout << "Shape[" << index << "] (" << name << ") " << "has collided with " << collisions.size() << " shapes." << endl;
			for (int j = 0; j < collisions.size(); j++) {
				vector<Shape*>::iterator pos = std::find(shapes.begin(), shapes.end(), collisions[i]);
				if (pos != shapes.end()) {
					shapes.erase(pos);
				}
			}

			it = std::next(it, 1);
		}

	}

	cout << "Finished game" << endl;
}