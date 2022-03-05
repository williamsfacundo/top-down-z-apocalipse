#ifndef MATH_H
#define MATH_H

#include <raylib.h>

namespace Z_APOCALIPSE 
{
	namespace vectorMath 
	{
		double getVectorLength(Vector2 vec);
		double getDistanceBetweenTwoVectors(Vector2 vecOne, Vector2 vecTwo);
		void normalizedVec(Vector2& vec);
		bool circlesCollision(Vector2 centerA, float radiusA, Vector2 centerB, float radiusB, Vector2& normal, float& depth);
		float getScreenHypotenuse();
	}
}

#endif
