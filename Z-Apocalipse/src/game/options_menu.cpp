#include "options_menu.h"

#include <raylib.h>

#include "button.h"
#include "..\gameplay\scene_manager.h"

#include "..\math\math.h"

namespace Z_APOCALIPSE
{
	OptionsMenu::OptionsMenu(const char* texts[maxOptionsMenuButtons])
	{
		setTitleTextSize(vectorMath::getScreenHypotenuse() / titleSizeDivider);

		setTitlePosition();

		createButtons(texts);
	}

	OptionsMenu::~OptionsMenu()
	{
		for (short i = 0; i < maxOptionsMenuButtons; i++)
		{
			delete button[i];
		}
	}

	void OptionsMenu::setTitleTextSize(short titleTextSize)
	{
		this->titleTextSize = titleTextSize;
	}

	void OptionsMenu::setTitlePosition()
	{
		titlePosition = { static_cast<float>((GetScreenWidth() / 2) - ((titleAmountOfLetters / 3) * titleTextSize)),
			static_cast<float>(GetScreenHeight() * tittleYPercentage) };
	}

	short OptionsMenu::getTitleTextSize()
	{
		return titleTextSize;
	}

	Vector2 OptionsMenu::getTitlePosition()
	{
		return titlePosition;
	}

	void OptionsMenu::input(SceneManager* sceneManager, Vector2& resolution)
	{
		for (short i = 0; i < maxOptionsMenuButtons; i++)
		{
			if (button[i]->isButtonPressed() && i != 3) 
			{
				switch (i)
				{
				case 0:

					resolution = lowResolution;
					i = maxOptionsMenuButtons;
					break;
				case 1:

					resolution = middleResolution;
					i = maxOptionsMenuButtons;
					break;
				case 2:

					resolution = { static_cast<float>(GetMonitorWidth(GetMonitorCount() - 1)), static_cast<float>(GetMonitorHeight(GetMonitorCount() - 1)) };
					i = maxOptionsMenuButtons;
					break;				
				}
			}

			if (i == 3) 
			{
				button[i]->changeSceneWhenButtonPress(sceneManager, menuScene);
				i = maxOptionsMenuButtons;
			}
		}
	}

	void OptionsMenu::draw()
	{
		BeginDrawing();
		ClearBackground(backgroundColor);

		drawTitle();

		drawButtons();
	}

	void OptionsMenu::drawTitle()
	{
		DrawText(titleText, static_cast<int>(getTitlePosition().x), static_cast<int>(getTitlePosition().y), titleTextSize, titleTextColor);
	}

	void OptionsMenu::drawButtons()
	{
		for (short i = 0; i < maxOptionsMenuButtons; i++)
		{
			button[i]->draw();
		}
	}

	void OptionsMenu::createButtons(const char* texts[maxOptionsMenuButtons])
	{
		float width = static_cast<float>(GetScreenWidth() * buttonsWidthPercentage);
		float height = static_cast<float>(GetScreenHeight() * buttonsHeightPercentage);
		float xPos = static_cast<float>((GetScreenWidth() / 2) - (width / 2.0f));
		float initialYPos = static_cast<float>(GetScreenWidth() * buttonsYPercentage);
		float separation = static_cast<float>(GetScreenHeight() * separationPercentage);

		for (short i = 0; i < maxOptionsMenuButtons; i++)
		{
			button[i] = new Button({ xPos, initialYPos + (separation * (i)) + (height * i),
				width, height }, buttonColorOne, buttonColorTwo, texts[i]);
		}
	}
}