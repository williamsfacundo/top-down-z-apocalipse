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
		const short titleTextAmountLetters = 12;
		const char* explanationText = "Touch the circles to upgrade (MAX 6)";
		const short explanationTextAmountLetters = 36;
		const short titleTextsSize = 35;
		const short explanationTextSize = 25;
		const Color titleTextColor = RED;
		const Color explanationTextColor = GREEN;

		const float velocityUpgradeValue = 15.0f;
		const float reloadTimeDecreaserValue = 0.32f;
		const float shootingTimeDecreaserValue = 0.185f;
		const float maxAcelerationUpgradeValue = 50.0f;
		const float damageUpgradeValue = 5.0f;
		const short chargerUpgradeValue = 6;
		const short maxBulletsPlayerUpgradeValue = 18;				

		const float upgradeTestsOffset = 200.0f;
		const float heightButtonsSeparation = 35.0f;
		const float buttonsRadius = 10.0f;
		const float changeSceneButtonWidth = 200;
		const float changeSceneButtonHeight = 40;
		const Color upgraderButtonsColor = WHITE;
		const Color changeSceneButtonColorOne = YELLOW;
		const Color changeSceneButtonColorTwo = RED;
		const Color backGroundColor = BLACK;
		const Scenes gameplayScene = Scenes::GAMEPLAY;

		static const short maxButtons = 8;
		short levels[maxButtons];
		const short levelSize = 18;
		const short maxLevel = 6;
		const Color levelTextColor = GREEN;

		const int initialPrice = 50;
		const int priceHudSize = 20;
		const int playerMoneyHudSize = 30;		
		const int priceHudSeparation = 50;
		const float higherPriceMultiplyer = 0.25f;
		const float playerMoneyCircleRadius = 220;
		const Color priceHudColor = GREEN;	
		const Color playerMoneyColor = BLACK;
		const Color playerMoneyCircleColor = YELLOW;

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

		int getPrice(short index);

		void input(Survivor* survivor, SceneManager* sceneManager);
		void draw(Survivor* survivor);		
	};
}

#endif