#include "upgrader.h"

#include "upgrader_button.h"
#include "survivor.h"
#include "..\game\button.h"
#include "scene_manager.h"

namespace Z_APOCALIPSE
{
	Upgrader::Upgrader()
	{
		resetLevels();

		velocityUpdateButton = new UpgraderButton("Velocity", buttonsRadius, upgraderButtonsColor, 
			{ static_cast<float>(GetScreenWidth() / 2), heightButtonsSeparation * 5.0f }, { static_cast<float>((GetScreenWidth() / 2) - upgradeTestsOffset), (heightButtonsSeparation * 5.0f) - buttonsRadius });
		
		maxAcelerationUpdateButton = new UpgraderButton("Max Aceleration", buttonsRadius, upgraderButtonsColor, 
			{ static_cast<float>(GetScreenWidth() / 2), heightButtonsSeparation * 6.0f }, { static_cast<float>((GetScreenWidth() / 2) - upgradeTestsOffset), (heightButtonsSeparation * 6.0f) - buttonsRadius });
		
		maxAmoUpdateButton = new UpgraderButton("Max Amo", buttonsRadius, upgraderButtonsColor, 
			{ static_cast<float>(GetScreenWidth() / 2), heightButtonsSeparation * 7.0f }, { static_cast<float>((GetScreenWidth() / 2) - upgradeTestsOffset), (heightButtonsSeparation * 7.0f) - buttonsRadius });
		
		chargerUpdateButton = new UpgraderButton("Charger", buttonsRadius, upgraderButtonsColor,
			{ static_cast<float>(GetScreenWidth() / 2), heightButtonsSeparation * 8.0f }, { static_cast<float>((GetScreenWidth() / 2) - upgradeTestsOffset), (heightButtonsSeparation * 8.0f) - buttonsRadius });
		
		fireRateUpdateButton = new UpgraderButton("Fire Rate", buttonsRadius, upgraderButtonsColor, 
			{ static_cast<float>(GetScreenWidth() / 2), heightButtonsSeparation * 9.0f }, { static_cast<float>((GetScreenWidth() / 2) - upgradeTestsOffset), (heightButtonsSeparation * 9.0f) - buttonsRadius });
		
		reloadSpeedUpdateButton = new UpgraderButton("Reload Speed", buttonsRadius, upgraderButtonsColor,
			{ static_cast<float>(GetScreenWidth() / 2), heightButtonsSeparation * 10.0f }, { static_cast<float>((GetScreenWidth() / 2) - upgradeTestsOffset), (heightButtonsSeparation * 10.0f) - buttonsRadius });;
		
		extraLifeUpdateButton = new UpgraderButton("Lives", buttonsRadius, upgraderButtonsColor, 
			{ static_cast<float>(GetScreenWidth() / 2), heightButtonsSeparation * 11.0f }, { static_cast<float>((GetScreenWidth() / 2) - upgradeTestsOffset), (heightButtonsSeparation * 11.0f) - buttonsRadius });
		
		damageUpdateButton = new UpgraderButton("Damage", buttonsRadius, upgraderButtonsColor,
			{ static_cast<float>(GetScreenWidth() / 2), heightButtonsSeparation * 12.0f }, { static_cast<float>((GetScreenWidth() / 2) - upgradeTestsOffset), (heightButtonsSeparation * 12.0f) - buttonsRadius });
		
		changeSceneButton = new Button({ static_cast<float>(GetScreenWidth()) - changeSceneButtonWidth, static_cast<float>(GetScreenHeight()) - changeSceneButtonHeight, changeSceneButtonWidth, changeSceneButtonHeight },
			changeSceneButtonColorOne, changeSceneButtonColorTwo, "CONTINUE");
	}

	Upgrader::~Upgrader()
	{
		delete velocityUpdateButton;
		delete maxAcelerationUpdateButton;
		delete maxAmoUpdateButton;
		delete chargerUpdateButton;
		delete fireRateUpdateButton;
		delete reloadSpeedUpdateButton;
		delete extraLifeUpdateButton;
		delete damageUpdateButton;
		delete changeSceneButton;
	}

	void Upgrader::resetLevels() 
	{
		for (short i = 0; i < maxButtons; i++) 
		{
			levels[i] = 1;
		}
	}

	void Upgrader::input(Survivor* survivor, SceneManager* sceneManager)
	{		
		if (velocityUpdateButton->buttonPressed() && levels[0] < maxLevel && survivor->getMoney() >= (initialPrice * levels[0]) + (initialPrice * levels[0] * higherPriceMultiplyer)) //survivor->getStartingRoundVelocity() + velocityUpgradeValue <= survivor->getMaxVelocity()
		{
			survivor->addMoney(-((initialPrice * levels[0]) + (initialPrice * levels[0] * higherPriceMultiplyer)));
			survivor->addStartingRoundVelocity(velocityUpgradeValue);
			survivor->setVelocity(survivor->getStartingRoundVelocity());
			levels[0] += 1;
		}
		else if (maxAcelerationUpdateButton->buttonPressed() && levels[1] < maxLevel && survivor->getMoney() >= (initialPrice * levels[1]) + (initialPrice * levels[1] * higherPriceMultiplyer)) //survivor->getStartingRoundMaxAceleration() + maxAcelerationUpgradeValue <= survivor->getMaxAceleration()
		{
			survivor->addMoney(-((initialPrice * levels[1]) + (initialPrice * levels[1] * higherPriceMultiplyer)));
			survivor->addStartingRoundMaxAceleration(maxAcelerationUpgradeValue);
			survivor->setAceleration(survivor->getStartingRoundMaxAceleration());
			levels[1] += 1;
		}
		else if (maxAmoUpdateButton->buttonPressed() && levels[2] < maxLevel && survivor->getMoney() >= (initialPrice * levels[2]) + (initialPrice * levels[2] * higherPriceMultiplyer)) //survivor->getStartingRoundRemainingBullets() + maxBulletsPlayerUpgradeValue <= survivor->getMaxBulletsPlayerCanHave()
		{
			survivor->addMoney(-((initialPrice * levels[2]) + (initialPrice * levels[2] * higherPriceMultiplyer)));
			survivor->addStartingRoundRemainingBullets(maxBulletsPlayerUpgradeValue);
			survivor->setRemainingBullets(survivor->getStartingRoundRemainingBullets());
			levels[2] += 1;			
		}
		else if (chargerUpdateButton->buttonPressed() && levels[3] < maxLevel && survivor->getMoney() >= (initialPrice * levels[3]) + (initialPrice * levels[3] * higherPriceMultiplyer)) //survivor->getStartingRoundMaxBulletsInCharger() + chargerUpgradeValue <= survivor->getMaxBulletsChargerSupports()
		{
			survivor->addMoney(-((initialPrice * levels[3]) + (initialPrice * levels[3] * higherPriceMultiplyer)));
			survivor->addStartingRoundMaxBulletsInCharger(chargerUpgradeValue);
			survivor->setBulletsInCharger(survivor->getStartingRoundMaxBulletsInCharger());
			levels[3] += 1;			
		}
		else if (fireRateUpdateButton->buttonPressed() && levels[4] < maxLevel && survivor->getMoney() >= (initialPrice * levels[4]) + (initialPrice * levels[4] * higherPriceMultiplyer)) //survivor->getStartingRoundShootingTime() - shootingTimeDecreaserValue > survivor->getMinShootingTime()
		{
			survivor->addMoney(-((initialPrice * levels[4]) + (initialPrice * levels[4] * higherPriceMultiplyer)));
			survivor->addStartingRoundShootingTime(-shootingTimeDecreaserValue);
			survivor->setShootingTimer(survivor->getStartingRoundShootingTime());
			levels[4] += 1;			
		}
		else if (reloadSpeedUpdateButton->buttonPressed() && levels[5] < maxLevel && survivor->getMoney() >= (initialPrice * levels[5]) + (initialPrice * levels[5] * higherPriceMultiplyer)) //survivor->getStartingRoundReloadTime() - reloadTimeDecreaserValue > survivor->getMinReloadTime()
		{
			survivor->addMoney(-((initialPrice * levels[5]) + (initialPrice * levels[5] * higherPriceMultiplyer)));
			survivor->addStartingRoundReloadTime(-reloadTimeDecreaserValue);
			survivor->setReloadTimer(survivor->getStartingRoundReloadTime());
			levels[5] += 1;			
		}
		else if (extraLifeUpdateButton->buttonPressed() && levels[6] < maxLevel && survivor->getMoney() >= (initialPrice * levels[6]) + (initialPrice * levels[6] * higherPriceMultiplyer)) //survivor->getRoundStartingLives() + 1 <= survivor->getMaxLives()
		{
			survivor->addMoney(-((initialPrice * levels[6]) + (initialPrice * levels[6] * higherPriceMultiplyer)));
			survivor->addRoundStartingLive();
			survivor->setLives(survivor->getRoundStartingLives());
			levels[6] += 1;					
		}
		else if (damageUpdateButton->buttonPressed() && levels[7] < maxLevel && survivor->getMoney() >= (initialPrice * levels[7]) + (initialPrice * levels[7] * higherPriceMultiplyer)) //survivor->getStartingRoundDamage() + damageUpgradeValue <= survivor->getMaxDamage()
		{
			survivor->addMoney(-((initialPrice * levels[7]) + (initialPrice * levels[7] * higherPriceMultiplyer)));
			survivor->addStartingRoundDamage(damageUpgradeValue);
			survivor->setDamage(survivor->getStartingRoundDamage());
			levels[7] += 1;		
		}
		
		changeSceneButton->changeSceneWhenButtonPress(sceneManager, gameplayScene);
	}

	
	void Upgrader::draw() 
	{
		BeginDrawing();
		ClearBackground(backGroundColor);

		DrawText(titleText, static_cast<int>((GetScreenWidth() / 2) - titleTextsSize * (titleTextAmountLetters / 2)), 
			static_cast<int>(heightButtonsSeparation), titleTextsSize, titleTextColor);

		DrawText(explanationText, static_cast<int>((GetScreenWidth() / 2) - explanationTextSize * (explanationTextAmountLetters / 3)),
			static_cast<int>(heightButtonsSeparation * 3.0f), explanationTextSize, explanationTextColor);

		velocityUpdateButton->drawButton();
		DrawText(TextFormat("%i", levels[0]), static_cast<int>(GetScreenWidth() / 2 - (buttonsRadius / 2)), static_cast<int>(heightButtonsSeparation * 5) - buttonsRadius, levelSize, levelTextColor);
		maxAcelerationUpdateButton->drawButton();
		DrawText(TextFormat("%i", levels[1]), static_cast<int>(GetScreenWidth() / 2 - (buttonsRadius / 2)), static_cast<int>(heightButtonsSeparation * 6) - buttonsRadius, levelSize, levelTextColor);
		maxAmoUpdateButton->drawButton();
		DrawText(TextFormat("%i", levels[2]), static_cast<int>(GetScreenWidth() / 2 - (buttonsRadius / 2)), static_cast<int>(heightButtonsSeparation * 7) - buttonsRadius, levelSize, levelTextColor);
		chargerUpdateButton->drawButton();
		DrawText(TextFormat("%i", levels[3]), static_cast<int>(GetScreenWidth() / 2 - (buttonsRadius / 2)), static_cast<int>(heightButtonsSeparation * 8) - buttonsRadius, levelSize, levelTextColor);
		fireRateUpdateButton->drawButton();
		DrawText(TextFormat("%i", levels[4]), static_cast<int>(GetScreenWidth() / 2 - (buttonsRadius / 2)), static_cast<int>(heightButtonsSeparation * 9) - buttonsRadius, levelSize, levelTextColor);
		reloadSpeedUpdateButton->drawButton();
		DrawText(TextFormat("%i", levels[5]), static_cast<int>(GetScreenWidth() / 2 - (buttonsRadius / 2)), static_cast<int>(heightButtonsSeparation * 10) - buttonsRadius, levelSize, levelTextColor);
		extraLifeUpdateButton->drawButton();
		DrawText(TextFormat("%i", levels[6]), static_cast<int>(GetScreenWidth() / 2 - (buttonsRadius / 2)), static_cast<int>(heightButtonsSeparation * 11) - buttonsRadius, levelSize, levelTextColor);
		damageUpdateButton->drawButton();
		DrawText(TextFormat("%i", levels[7]), static_cast<int>(GetScreenWidth() / 2 - (buttonsRadius / 2)), static_cast<int>(heightButtonsSeparation * 12) - buttonsRadius, levelSize, levelTextColor);
		
		changeSceneButton->draw();

		EndDrawing();
	}
}