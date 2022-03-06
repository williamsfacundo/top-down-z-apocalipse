#ifndef OPTIONS_MENU_H
#define OPTIONS_MENU_H

#include <raylib.h>

#include "button.h"
#include "..\gameplay\scene_manager.h"

namespace Z_APOCALIPSE
{
	const short maxOptionsMenuButtons = 4;

	const Vector2 initialResolution = { 800.0f, 450.0f };

	class OptionsMenu
	{
	private:
		const float buttonsYPercentage = 0.2f;
		const float buttonsWidthPercentage = 0.3f;
		const float buttonsHeightPercentage = 0.1f;
		const float separationPercentage = 0.05f;
		const float tittleYPercentage = 0.1f;
		const float titleSizeDivider = 20.0f;

		const Color backgroundColor = BLACK;
		const Color buttonColorOne = YELLOW;
		const Color buttonColorTwo = RED;
		const Color titleTextColor = GRAY;

		const char* titleText = "OPTIONS";

		const short titleAmountOfLetters = 12;

		int titleTextSize;

		const Vector2 lowResolution = { 800.0f, 450.0f }; //800 450
		const Vector2 middleResolution = { 1280.0f, 720.0f };		

		const Scenes menuScene = Scenes::MAIN_MENU;

		Vector2 titlePosition;

		Button* button[maxOptionsMenuButtons];
	public:
		OptionsMenu(const char* texts[maxOptionsMenuButtons]);
		~OptionsMenu();

		void setTitleTextSize(short titleTextSize);
		void setTitlePosition();

		short getTitleTextSize();
		Vector2 getTitlePosition();

		void input(SceneManager* sceneManager, Vector2& resolution);

		void draw();
		void drawTitle();
		void drawButtons();

		void createButtons(const char* texts[maxOptionsMenuButtons]);
	};
}

#endif
