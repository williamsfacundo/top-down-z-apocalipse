#ifndef CHARACTER_H
#define CHARACTER_H

#include <raylib.h>

namespace Z_APOCALIPSE 
{
	class Character
	{
	private:		
		const Color characterColor = YELLOW;
		Vector2 position;
		float radius;
	public:
		Character(Vector2 position, float radius);

		void setPosition(Vector2 position);
		void setRadius(float radius);
		Vector2 getPosition();
		float getRadius();
				
		virtual void update() = 0;
		void draw();
	};
}

#endif
