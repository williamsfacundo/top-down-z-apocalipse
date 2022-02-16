#include "button.h"

namespace Z_APOCALIPSE
{
	Button::Button(Rectangle shape, Color color)
	{
		setShape(shape);
		setColor(color);
	}

	void Button::setShape(Rectangle shape)
	{
		this->shape = shape;
	}

	void Button::setColor(Color color) 
	{
		this->shapeColor = color;
	}
	
	void Button::setText(const char* text) 
	{
		this->text = text;
	}

	Rectangle Button::getShape()
	{
		return shape;
	}

	Color Button::getColor() 
	{
		return shapeColor;
	}

	const char* Button::getText() 
	{
		return text;
	}

	void Button::changeSceneWhenButtonPress(SceneManager* sceneManager, Scenes newScene)
	{
		sceneManager->setCurrentScene(newScene);
	}

	void Button::draw()
	{
		DrawRectangleRec(getShape(), getColor());
		DrawText(getText(), getShape().x, getShape().y - (getShape().y / 2.0f), textSize, textColor);
	}
}