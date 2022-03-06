#ifndef upgrader_button
#define upgrader_button

#include <raylib.h>

namespace Z_APOCALIPSE 
{
	class UpgraderButton
	{
	private:
		const MouseButton button = MouseButton::MOUSE_BUTTON_LEFT;

		const short fontSize = 20;

		const char* text;

		float radius;

		Color color;

		Vector2 circlePosition;
		Vector2 titlePosition;
	public:
		UpgraderButton(const char* text, float radius, Color color, Vector2 circlePosition, Vector2 titlePosition);

		void setText(const char* text);
		void setRadius(float radius);
		void setColor(Color color);
		void setCirclePosition(Vector2 position);
		void setTitlePosition(Vector2 position);

		const char* getText();
		float getRadius();
		Color getColor();
		Vector2 getCirclePosition();
		Vector2 getTitlePosition();

		bool buttonPressed();
		void drawButton();
	};
}

#endif
