#include "credits.h"

namespace Z_APOCALIPSE 
{
	Credits::Credits() 
	{
		setButtonShape((GetScreenWidth() / 2.0f) - (buttonSize / 2.0f), GetScreenHeight() * 0.3f,
			buttonSize, buttonSize / 4.0f);

		button = new Button( getButtonShape(), buttonColorOne, buttonColorTwo, buttonText );
	}

	Credits::~Credits() 
	{
		delete button;
	}	

	void Credits::setButtonShape(float x, float y, float width, float height) 
	{
		buttonShape.x = x;
		buttonShape.y = y;
		buttonShape.width = width;
		buttonShape.height = height;
	}

	Rectangle Credits::getButtonShape() 
	{
		return buttonShape;
	}
	
	void Credits::input(SceneManager* sceneManager)
	{
		button->changeSceneWhenButtonPress(sceneManager, goBackScene);
	}	
	
	void Credits::draw(MainMenu* mainMenu)
	{
		BeginDrawing();
		ClearBackground(backgroundColor);
		
		mainMenu->drawTitle();

		drawDevName();
		
		button->draw();

		EndDrawing();
	}	

	void Credits::drawDevName() 
	{
		DrawText(developerNameText, GetScreenWidth() / 2 - 10 * creditsFontSize,
			static_cast<int>(GetScreenHeight() * 0.6f), creditsFontSize, BLACK);
	}
}