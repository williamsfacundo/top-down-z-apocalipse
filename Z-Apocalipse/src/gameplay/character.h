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
		Rectangle gameplayMap;
	public:
		Character(Color characterColor, Vector2 position, float radius, Rectangle gameplayMap);

		void setCharacterColor(Color characterColor);
		void setPosition(Vector2 position);
		void move(Vector2 distance);
		void setRadius(float radius);
		void setGameplayMap(Rectangle gameplayMap);

		Color getCharacterColor();
		Vector2 getPosition();
		float getRadius();
		Rectangle getGameplayMap();
						
		virtual void update(Rectangle gameplayDimensions) = 0;
		virtual void movementUpdate() = 0;
		virtual void draw() = 0;
	};
}

#endif
