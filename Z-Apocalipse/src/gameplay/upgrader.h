#ifndef UPGRADER_H
#define UPGRADER_H

#include "upgrader_button.h"
#include "survivor.h"
#include "..\game\button.h"
#include "scene_manager.h"

namespace Z_APOCALIPSE 
{
	class Upgrader
	{
	private:
		const char* titleText = "UPGRADE MENU";
		const char* explanationText = "Touch the circles to upgrade (MAX 6)";

		const int initialPrice = 50;
		const int priceHudSeparation = 50;
		
		const short titleTextAmountLetters = 12;		
		const short explanationTextAmountLetters = 36;				
		const short chargerUpgradeValue = 6;
		const short maxBulletsPlayerUpgradeValue = 18;		
		const short maxLevel = 6;

		const float velocityUpgradeValue = 15.0f;
		const float reloadTimeDecreaserValue = 0.32f;
		const float shootingTimeDecreaserValue = 0.185f;
		const float maxAcelerationUpgradeValue = 50.0f;
		const float damageUpgradeValue = 5.0f;
		const float upgradeTestsOffset = 200.0f;
		const float heightButtonsSeparation = 35.0f;
		const float buttonsRadius = 10.0f;
		const float changeSceneButtonWidth = 200;
		const float changeSceneButtonHeight = 40;			
		const float higherPriceMultiplyer = 0.25f;
		const float playerMoneyCircleRadius = 220;

		const float priceSizeDivider = 35.0f;
		const float playerMoneySizeDivider = 30.0f;
		const float levelSizeDivider = 40.0f;
		const float titleSizeDivider = 15.0f;
		const float explanationTextSizeDivider = 30.0f;

		const Color upgraderButtonsColor = WHITE;
		const Color changeSceneButtonColorOne = YELLOW;
		const Color changeSceneButtonColorTwo = RED;
		const Color backGroundColor = BLACK;
		const Color titleTextColor = RED;
		const Color explanationTextColor = GREEN;
		const Color levelTextColor = GREEN;
		const Color priceHudColor = GREEN;
		const Color playerMoneyColor = BLACK;
		const Color playerMoneyCircleColor = YELLOW;

		const Scenes gameplayScene = Scenes::GAMEPLAY;

		static const short maxButtons = 8;

		int priceHudSize; //20
		int playerMoneyHudSize; //30
		int levelSize; //18
		int titleTextsSize; //35
		int explanationTextSize; //25

		short levels[maxButtons];	

		UpgraderButton* velocityUpdateButton;
		UpgraderButton* maxAcelerationUpdateButton;
		UpgraderButton* maxAmoUpdateButton;
		UpgraderButton* chargerUpdateButton;
		UpgraderButton* fireRateUpdateButton;
		UpgraderButton* reloadSpeedUpdateButton;
		UpgraderButton* extraLifeUpdateButton;
		UpgraderButton* damageUpdateButton;

		Button* changeSceneButton;
	public:
		Upgrader();
		~Upgrader();

		void resetLevels();		

		void setPriceHudSize();
		void setPlayerMoneyHudSize();
		void setLevelSize();
		void setTitleTextsSize();
		void setExplanationTextSize();
		void setButtons();

		int getPriceHudSize();
		int getPlayerMoneyHudSize();
		int getLevelSize();
		int getTitleTextsSize();
		int getExplanationTextSize();
		int getPrice(short index);

		void input(Survivor* survivor, SceneManager* sceneManager);
		
		void draw(Survivor* survivor);
		
		void drawTitle();
		void drawExplanationText();
		void drawButtons();
		void drawPlayerMoney(Survivor* survivor);

		bool allLevelsMaxed();
	};
}

#endif