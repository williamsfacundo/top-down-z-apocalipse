#ifndef UPGRADER_H
#define UPGRADER_H

#include <raylib.h>

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
		
		const short titleTextAmountLetters = 12;		
		const short explanationTextAmountLetters = 36;				
		const short chargerUpgradeValue = 6;
		const short maxBulletsPlayerUpgradeValue = 18;		
		const short maxLevel = 6;		
		const float reloadTimeDecreaserValue = 0.32f;
		const float shootingTimeDecreaserValue = 0.185f;
		const float damageUpgradeValue = 5.0f;
		const float upgradeTestsOffsetPercentage = 0.3f;		
		const float buttonsRadiusDivider = 80.0f;
		const float changeSceneButtonYPercentage = 0.9f;
		const float changeSceneButtonWidthPercentage = 0.3f;
		const float changeSceneButtonHeightPercentage = 0.1f;
		const float higherPriceMultiplyer = 0.25f;
		const float priceHudSeparationPercentage = 0.05f;
		const float playerMoneyCircleRadiusDivider = 4.3f;
		const float priceSizeDivider = 35.0f;
		const float playerMoneySizeDivider = 30.0f;
		const float levelSizeDivider = 40.0f;
		const float titleSizeDivider = 15.0f;
		const float explanationTextSizeDivider = 30.0f;
		const float titleTextYPercentage = 0.06f;
		const float explanationTextYPercentage = 0.25f;
		const float buttonsYPercentage = 0.4f;
		const float heightButtonsSeparationPercentage = 0.07f;	
		const float moneyTextXPercentage = 0.01f;
		const float moneyTextYPercentage = 0.90f;
		const float maxAcelerationUpgradeValueDivider = 30.0f;
		const float velocityUpgradeValueDivider = 75.0f;

		const Color upgraderButtonsColor = BLUE;
		const Color changeSceneButtonColorOne = YELLOW;
		const Color changeSceneButtonColorTwo = RED;
		const Color backGroundColor = BLACK;
		const Color titleTextColor = GRAY;
		const Color explanationTextColor = WHITE;
		const Color levelTextColor = GREEN;
		const Color priceHudColor = GREEN;
		const Color playerMoneyColor = BLACK;
		const Color playerMoneyCircleColor = YELLOW;

		const Scenes gameplayScene = Scenes::GAMEPLAY;

		static const short maxButtons = 8;

		float playerMoneyCircleRadius; 

		float velocityUpgradeValue;
		float maxAcelerationUpgradeValue;

		int priceHudSize; 
		int playerMoneyHudSize;
		int levelSize; 
		int titleTextsSize; 
		int explanationTextSize; 

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

		void setPlayerMoneyCircleRadius();
		void setMaxAcelerationUpgradeValue();
		void setVelocityUpgradeValue();
		void setPriceHudSize();
		void setPlayerMoneyHudSize();
		void setLevelSize();
		void setTitleTextsSize();
		void setExplanationTextSize();
		void setButtons();

		float getPlayerMoneyCircleRadius();
		float getMaxAcelerationUpgradeValue();
		float getVelocityUpgradeValue();
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