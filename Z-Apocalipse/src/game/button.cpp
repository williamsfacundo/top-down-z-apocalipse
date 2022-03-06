#include "button.h"

#include "raylib.h"

#include "..\gameplay\scene_manager.h"
#include "..\math\math.h"

namespace Z_APOCALIPSE
{
	Button::Button(Rectangle shape, Color colorOne, Color colorTwo, const char* text)
	{
		setShape(shape);
		setShapeColorOne(colorOne);
		setShapeColorTwo(colorTwo);
		setTextSize();
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

	void Button::setTextSize() 
	{
		textSize = static_cast<int>(vectorMath::getVectorLength({getShape().width, getShape().height }) / textSizeDivider);
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

	int Button::getTextSize() 
	{
		return textSize;
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
		
		DrawText(getText(), getShape().x, getShape().y, getTextSize(), textColor);
	}

	bool Button::isMouseOnButton()
	{
		return CheckCollisionPointRec(GetMousePosition(), getShape());
	}
}