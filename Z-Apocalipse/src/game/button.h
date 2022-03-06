#ifndef BUTTON_H
#define BUTTON_H

#include "raylib.h"

#include "..\gameplay\scene_manager.h"

namespace Z_APOCALIPSE 
{
	class Button
	{
	private:			
		const float textSizeDivider = 8.0f;
		const float buttonTextXPercentage = 0.05f;
		const float buttonTextYPercentage = 0.05f;

		const Color textColor = BLACK;
				
		Rectangle shape;
		
		Color shapeColorOne;
		Color shapeColorTwo;

		int textSize; 

		const char* text;
	public:
		Button(Rectangle shape, Color colorOne, Color colorTwo, const char* text);

		void setShape(Rectangle shape);
		void setShapeColorOne(Color color);
		void setShapeColorTwo(Color color);
		void setTextSize();
		void setText(const char* text);

		Rectangle getShape();
		Color getShapeColorOne();
		Color getShapeColorTwo();
		int getTextSize();
		const char* getText();
		
		void changeSceneWhenButtonPress(SceneManager* sceneManager, Scenes newScene);
		bool isButtonPressed();
		void draw();
		bool isMouseOnButton();	
	};
}

#endif
