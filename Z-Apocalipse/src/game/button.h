#ifndef BUTTON_H
#define BUTTON_H

#include "raylib.h"

#include "..\gameplay\scene_manager.h"

namespace Z_APOCALIPSE 
{
	class Button
	{
	private:
		const short textSize = 20;
		const Color textColor = BLACK;
		Rectangle shape;
		Color shapeColor;
		const char* text;
	public:
		Button(Rectangle shape, Color color);

		void setShape(Rectangle shape);
		void setColor(Color color);
		void setText(const char* text);

		Rectangle getShape();
		Color getColor();
		const char* getText();
		
		void changeSceneWhenButtonPress(SceneManager* sceneManager, Scenes newScene);
		void draw();
	};
}

#endif
