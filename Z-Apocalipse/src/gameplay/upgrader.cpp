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

	int Upgrader::getPrice(short index) 
	{
		return (initialPrice * levels[index]) + static_cast<int>(initialPrice * levels[index] * higherPriceMultiplyer);
	}

	void Upgrader::input(Survivor* survivor, SceneManager* sceneManager)
	{		
		if (velocityUpdateButton->buttonPressed() && levels[0] < maxLevel && survivor->getMoney() >= getPrice(0)) //survivor->getStartingRoundVelocity() + velocityUpgradeValue <= survivor->getMaxVelocity()
		{
			survivor->addMoney(-getPrice(0));
			survivor->addStartingRoundVelocity(velocityUpgradeValue);
			survivor->setVelocity(survivor->getStartingRoundVelocity());
			levels[0] += 1;
		}
		else if (maxAcelerationUpdateButton->buttonPressed() && levels[1] < maxLevel && survivor->getMoney() >= getPrice(1)) //survivor->getStartingRoundMaxAceleration() + maxAcelerationUpgradeValue <= survivor->getMaxAceleration()
		{
			survivor->addMoney(-getPrice(1));
			survivor->addStartingRoundMaxAceleration(maxAcelerationUpgradeValue);
			survivor->setAceleration(survivor->getStartingRoundMaxAceleration());
			levels[1] += 1;
		}
		else if (maxAmoUpdateButton->buttonPressed() && levels[2] < maxLevel && survivor->getMoney() >= getPrice(2)) //survivor->getStartingRoundRemainingBullets() + maxBulletsPlayerUpgradeValue <= survivor->getMaxBulletsPlayerCanHave()
		{
			survivor->addMoney(-getPrice(2));
			survivor->addStartingRoundRemainingBullets(maxBulletsPlayerUpgradeValue);
			survivor->setRemainingBullets(survivor->getStartingRoundRemainingBullets());
			levels[2] += 1;			
		}
		else if (chargerUpdateButton->buttonPressed() && levels[3] < maxLevel && survivor->getMoney() >= getPrice(3)) //survivor->getStartingRoundMaxBulletsInCharger() + chargerUpgradeValue <= survivor->getMaxBulletsChargerSupports()
		{
			survivor->addMoney(-getPrice(3));
			survivor->addStartingRoundMaxBulletsInCharger(chargerUpgradeValue);
			survivor->setBulletsInCharger(survivor->getStartingRoundMaxBulletsInCharger());
			levels[3] += 1;			
		}
		else if (fireRateUpdateButton->buttonPressed() && levels[4] < maxLevel && survivor->getMoney() >= getPrice(4)) //survivor->getStartingRoundShootingTime() - shootingTimeDecreaserValue > survivor->getMinShootingTime()
		{
			survivor->addMoney(-getPrice(4));
			survivor->addStartingRoundShootingTime(-shootingTimeDecreaserValue);
			survivor->setShootingTimer(survivor->getStartingRoundShootingTime());
			levels[4] += 1;			
		}
		else if (reloadSpeedUpdateButton->buttonPressed() && levels[5] < maxLevel && survivor->getMoney() >= getPrice(5)) //survivor->getStartingRoundReloadTime() - reloadTimeDecreaserValue > survivor->getMinReloadTime()
		{
			survivor->addMoney(-getPrice(5));
			survivor->addStartingRoundReloadTime(-reloadTimeDecreaserValue);
			survivor->setReloadTimer(survivor->getStartingRoundReloadTime());
			levels[5] += 1;			
		}
		else if (extraLifeUpdateButton->buttonPressed() && levels[6] < maxLevel && survivor->getMoney() >= getPrice(6)) //survivor->getRoundStartingLives() + 1 <= survivor->getMaxLives()
		{
			survivor->addMoney(-getPrice(6));
			survivor->addRoundStartingLive();
			survivor->setLives(survivor->getRoundStartingLives());
			levels[6] += 1;					
		}
		else if (damageUpdateButton->buttonPressed() && levels[7] < maxLevel && survivor->getMoney() >= getPrice(7)) //survivor->getStartingRoundDamage() + damageUpgradeValue <= survivor->getMaxDamage()
		{
			survivor->addMoney(-getPrice(7));
			survivor->addStartingRoundDamage(damageUpgradeValue);
			survivor->setDamage(survivor->getStartingRoundDamage());
			levels[7] += 1;		
		}
		
		changeSceneButton->changeSceneWhenButtonPress(sceneManager, gameplayScene);
	}

	
	void Upgrader::draw(Survivor* survivor)
	{
		BeginDrawing();
		ClearBackground(backGroundColor);

		DrawText(titleText, static_cast<int>((GetScreenWidth() / 2) - titleTextsSize * (titleTextAmountLetters / 2)), 
			static_cast<int>(heightButtonsSeparation), titleTextsSize, titleTextColor);

		DrawText(explanationText, static_cast<int>((GetScreenWidth() / 2) - explanationTextSize * (explanationTextAmountLetters / 3)),
			static_cast<int>(heightButtonsSeparation * 3.0f), explanationTextSize, explanationTextColor);

		velocityUpdateButton->drawButton();
		DrawText(TextFormat("%i", levels[0]), static_cast<int>(GetScreenWidth() / 2 - (buttonsRadius / 2)), static_cast<int>(heightButtonsSeparation * 5) - buttonsRadius, levelSize, levelTextColor);
		DrawText(TextFormat("$ %i", getPrice(0)), (GetScreenWidth() / 2) + priceHudSeparation, heightButtonsSeparation * 5.0f, priceHudSize, priceHudColor);
		
		maxAcelerationUpdateButton->drawButton();
		DrawText(TextFormat("%i", levels[1]), static_cast<int>(GetScreenWidth() / 2 - (buttonsRadius / 2)), static_cast<int>(heightButtonsSeparation * 6) - buttonsRadius, levelSize, levelTextColor);
		DrawText(TextFormat("$ %i", getPrice(1)), (GetScreenWidth() / 2) + priceHudSeparation, heightButtonsSeparation * 6.0f, priceHudSize, priceHudColor);

		maxAmoUpdateButton->drawButton();
		DrawText(TextFormat("%i", levels[2]), static_cast<int>(GetScreenWidth() / 2 - (buttonsRadius / 2)), static_cast<int>(heightButtonsSeparation * 7) - buttonsRadius, levelSize, levelTextColor);
		DrawText(TextFormat("$ %i", getPrice(2)), (GetScreenWidth() / 2) + priceHudSeparation, heightButtonsSeparation * 7.0f, priceHudSize, priceHudColor);

		chargerUpdateButton->drawButton();
		DrawText(TextFormat("%i", levels[3]), static_cast<int>(GetScreenWidth() / 2 - (buttonsRadius / 2)), static_cast<int>(heightButtonsSeparation * 8) - buttonsRadius, levelSize, levelTextColor);
		DrawText(TextFormat("$ %i", getPrice(3)), (GetScreenWidth() / 2) + priceHudSeparation, heightButtonsSeparation * 8.0f, priceHudSize, priceHudColor);

		fireRateUpdateButton->drawButton();
		DrawText(TextFormat("%i", levels[4]), static_cast<int>(GetScreenWidth() / 2 - (buttonsRadius / 2)), static_cast<int>(heightButtonsSeparation * 9) - buttonsRadius, levelSize, levelTextColor);
		DrawText(TextFormat("$ %i", getPrice(4)), (GetScreenWidth() / 2) + priceHudSeparation, heightButtonsSeparation * 9.0f, priceHudSize, priceHudColor);

		reloadSpeedUpdateButton->drawButton();
		DrawText(TextFormat("%i", levels[5]), static_cast<int>(GetScreenWidth() / 2 - (buttonsRadius / 2)), static_cast<int>(heightButtonsSeparation * 10) - buttonsRadius, levelSize, levelTextColor);
		DrawText(TextFormat("$ %i", getPrice(5)), (GetScreenWidth() / 2) + priceHudSeparation, heightButtonsSeparation * 10.0f, priceHudSize, priceHudColor);

		extraLifeUpdateButton->drawButton();
		DrawText(TextFormat("%i", levels[6]), static_cast<int>(GetScreenWidth() / 2 - (buttonsRadius / 2)), static_cast<int>(heightButtonsSeparation * 11) - buttonsRadius, levelSize, levelTextColor);
		DrawText(TextFormat("$ %i", getPrice(6)), (GetScreenWidth() / 2) + priceHudSeparation, heightButtonsSeparation * 11.0f, priceHudSize, priceHudColor);

		damageUpdateButton->drawButton();
		DrawText(TextFormat("%i", levels[7]), static_cast<int>(GetScreenWidth() / 2 - (buttonsRadius / 2)), static_cast<int>(heightButtonsSeparation * 12) - buttonsRadius, levelSize, levelTextColor);
		DrawText(TextFormat("$ %i", getPrice(7)), (GetScreenWidth() / 2) + priceHudSeparation, heightButtonsSeparation * 12.0f, priceHudSize, priceHudColor);

		changeSceneButton->draw();

		DrawCircleV({ 1.0f, static_cast<float>(GetScreenHeight() + (playerMoneyCircleRadius / 2.0f)) }, playerMoneyCircleRadius, playerMoneyCircleColor );
		DrawText(TextFormat("$ %i", survivor->getMoney()), 1, GetScreenHeight() - 30, playerMoneyHudSize, playerMoneyColor);
		
		EndDrawing();
	}	
}