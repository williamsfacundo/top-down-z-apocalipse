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
		Color shapeColorOne;
		Color shapeColorTwo;
		const char* text;
	public:
		Button(Rectangle shape, Color colorOne, Color colorTwo, const char* text);

		void setShape(Rectangle shape);
		void setShapeColorOne(Color color);
		void setShapeColorTwo(Color color);
		void setText(const char* text);

		Rectangle getShape();
		Color getShapeColorOne();
		Color getShapeColorTwo();
		const char* getText();
		
		void changeSceneWhenButtonPress(SceneManager* sceneManager, Scenes newScene);
		void draw();
		bool isMouseOnButton();	
	};
}

#endif
