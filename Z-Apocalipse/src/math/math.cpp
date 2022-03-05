#include "math.h"

#include <cmath>
#include <raylib.h>

namespace Z_APOCALIPSE
{
	namespace vectorMath
	{
		double getVectorLength(Vector2 vec) 
		{
			return sqrt(pow(vec.x, 2) + pow(vec.y, 2));
		}

		double getDistanceBetweenTwoVectors(Vector2 vecOne, Vector2 vecTwo) 
		{			
			float distanceX = vecOne.x - vecTwo.x;
			float distanceY = vecOne.y - vecTwo.y;
			Vector2 newVec = { distanceX, distanceY };

			return getVectorLength(newVec);
		}

		void normalizedVec(Vector2& vec) 
		{
			double vecLength = getVectorLength(vec);

			vec = { (static_cast<float>(vec.x / vecLength), static_cast<float>(vec.y / vecLength)) };
		}

		bool circlesCollision(Vector2 centerA, float radiusA, Vector2 centerB, float radiusB, Vector2& normal, float& depth)
		{
			float distance = getDistanceBetweenTwoVectors(centerA, centerB);
			float radii = radiusA + radiusB; 		

			if (distance < radii)
			{
				normal = { centerB.x - centerA.x, centerB.y - centerA.y };

				normalizedVec(normal);
				depth = radii - distance;

				return true;
			}
			else
			{
				return false;
			}
		}

		float getScreenHypotenuse() 
		{
			Vector2 screenSize = { static_cast<float>(GetScreenWidth()), static_cast<float>(GetScreenHeight()) };

			return static_cast<float>(getVectorLength(screenSize));
		}
	}
}