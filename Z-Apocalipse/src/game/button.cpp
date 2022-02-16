#include "button.h"

#include "raylib.h"

#include "..\gameplay\scene_manager.h"

namespace Z_APOCALIPSE
{
	Button::Button(Rectangle shape, Color colorOne, Color colorTwo, const char* text)
	{
		setShape(shape);
		setShapeColorOne(colorOne);
		setShapeColorTwo(colorTwo);
		setText(text);
	}

	void Button::setShape(Rectangle shape)
	{
		this->shape = shape;
	}

	void Button::setShapeColorOne(Color color) 
	{
		this->shapeColorOne = color;
	}

	void Button::setShapeColorTwo(Color color) 
	{
		this->shapeColorTwo = color;
	}
	
	void Button::setText(const char* text) 
	{
		this->text = text;
	}

	Rectangle Button::getShape()
	{
		return shape;
	}

	Color Button::getShapeColorOne() 
	{
		return shapeColorOne;
	}

	Color Button::getShapeColorTwo()
	{
		return shapeColorTwo;
	}

	const char* Button::getText() 
	{
		return text;
	}

	void Button::changeSceneWhenButtonPress(SceneManager* sceneManager, Scenes newScene)
	{
		if (isMouseOnButton() && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) 
		{
			sceneManager->setCurrentScene(newScene);
		}		
	}

	void Button::draw()
	{
		if (isMouseOnButton()) 
		{
			DrawRectangleRec(getShape(), getShapeColorOne());
		}
		else 
		{
			DrawRectangleRec(getShape(), getShapeColorTwo());
		}
		
		DrawText(getText(), getShape().x, getShape().y, textSize, textColor);
	}

	bool Button::isMouseOnButton()
	{
		return CheckCollisionPointRec(GetMousePosition(), getShape());
	}
}