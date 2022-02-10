#ifndef CHARACTER_H
#define CHARACTER_H

#include <raylib.h>

namespace Z_APOCALIPSE 
{
	class Character
	{
	private:		
		Color characterColor;
		Vector2 position;
		float radius;
	public:
		Character(Color characterColor, Vector2 position, float radius);

		void setCharacterColor(Color characterColor);
		void setPosition(Vector2 position);
		void setRadius(float radius);
		Color getCharacterColor();
		Vector2 getPosition();
		float getRadius();
						
		virtual void update() = 0;
		void draw();
	};
}

#endif
