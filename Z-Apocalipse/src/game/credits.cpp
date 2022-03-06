#include "credits.h"

#include <raylib.h>

#include "button.h"
#include "main_menu.h"
#include "..\math\math.h"

namespace Z_APOCALIPSE 
{
	Credits::Credits() 
	{
		setCreditsFontSize();	

		setButton();

		setCreditsTextsPosition();
	}

	Credits::~Credits() 
	{
		delete button;
	}

	void Credits::setCreditsFontSize()
	{
		creditsFontSize = vectorMath::getScreenHypotenuse() / creditsFontSizeDivider;
	}

	void Credits::setButton() 
	{
		float width = static_cast<float>(GetScreenWidth() * buttonWidthPercentage);
		float height = static_cast<float>(GetScreenHeight() * buttonHeightPercentage);
		float xPos = static_cast<float>((GetScreenWidth() / 2.0f) - (width / 2.0f));
		float yPos = static_cast<float>(GetScreenHeight() * buttonYPercentage);
		
		setButtonShape(xPos, yPos, width, height);

		button = new Button(getButtonShape(), buttonColorOne, buttonColorTwo, buttonText);
	}

	void Credits::setButtonShape(float x, float y, float width, float height) 
	{
		buttonShape.x = x;
		buttonShape.y = y;
		buttonShape.width = width;
		buttonShape.height = height;
	}

	void Credits::setCreditsTextsPosition() 
	{
		creditsTextsPosition = { static_cast<float>((GetScreenWidth() / 2) - ((developerNameTextAmountOfLetters / 3) * getCreditsFontSize())),
			static_cast<float>(GetScreenHeight() * creditsTextYPercentage) };
	}

	int Credits::getCreditsFontSize() 
	{
		return creditsFontSize;
	}

	Rectangle Credits::getButtonShape() 
	{
		return buttonShape;
	}

	Vector2 Credits::getCreditsTextsPosition() 
	{
		return creditsTextsPosition;
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

		drawToolsText();
		
		button->draw();		
	}	

	void Credits::drawDevName() 
	{
		DrawText(developerNameText, static_cast<int>(getCreditsTextsPosition().x), static_cast<int>(getCreditsTextsPosition().y), getCreditsFontSize(), developerTextColor);
	}

	void Credits::drawToolsText() 
	{
		DrawText(toolsText, static_cast<int>(getCreditsTextsPosition().x), static_cast<int>(getCreditsTextsPosition().y + (GetScreenHeight() * creditsSeparationPercentage)), getCreditsFontSize(), developerTextColor);
	}
}