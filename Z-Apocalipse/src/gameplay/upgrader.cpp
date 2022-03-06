#include "upgrader.h"

#include <raylib.h>

#include "upgrader_button.h"
#include "survivor.h"
#include "..\game\button.h"
#include "scene_manager.h"
#include "..\math\math.h"

namespace Z_APOCALIPSE
{
	Upgrader::Upgrader()
	{
		resetLevels();

		setPlayerMoneyCircleRadius();

		setPriceHudSize();

		setPlayerMoneyHudSize();

		setLevelSize();

		setTitleTextsSize();

		setExplanationTextSize();

		setButtons();
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

	void Upgrader::setPlayerMoneyCircleRadius()
	{
		playerMoneyCircleRadius = vectorMath::getScreenHypotenuse() / playerMoneyCircleRadiusDivider;
	}

	void Upgrader::setPriceHudSize()
	{
		priceHudSize = static_cast<int>(vectorMath::getScreenHypotenuse() / priceSizeDivider);
	}

	void Upgrader::setPlayerMoneyHudSize()
	{
		playerMoneyHudSize = static_cast<int>(vectorMath::getScreenHypotenuse() / playerMoneySizeDivider);
	}

	void Upgrader::setLevelSize()
	{
		levelSize = static_cast<int>(vectorMath::getScreenHypotenuse() / levelSizeDivider);
	}

	void Upgrader::setTitleTextsSize()
	{
		titleTextsSize = static_cast<int>(vectorMath::getScreenHypotenuse() / titleSizeDivider);
	}

	void Upgrader::setExplanationTextSize()
	{
		explanationTextSize = static_cast<int>(vectorMath::getScreenHypotenuse() / explanationTextSizeDivider);
	}

	void Upgrader::setButtons() 
	{
		float buttonsXPos = static_cast<float>((GetScreenWidth() / 2) - (GetScreenWidth() * upgradeTestsOffsetPercentage));
		float buttonsRadius = vectorMath::getScreenHypotenuse() / buttonsRadiusDivider;
		float buttonsYPos = static_cast<float>(GetScreenHeight() * buttonsYPercentage);
		float buttonsHeightSeparation = static_cast<float>(GetScreenHeight() * heightButtonsSeparationPercentage);

		velocityUpdateButton = new UpgraderButton("Velocity", buttonsRadius, upgraderButtonsColor,
			{ static_cast<float>(GetScreenWidth() / 2), buttonsYPos + (buttonsHeightSeparation * 0.0f) }, { buttonsXPos, (buttonsYPos + (buttonsHeightSeparation * 0.0f)) - buttonsRadius });

		maxAcelerationUpdateButton = new UpgraderButton("Max Aceleration", buttonsRadius, upgraderButtonsColor,
			{ static_cast<float>(GetScreenWidth() / 2), buttonsYPos + (buttonsHeightSeparation * 1.0f) }, { buttonsXPos, (buttonsYPos + (buttonsHeightSeparation * 1.0f)) - buttonsRadius });

		maxAmoUpdateButton = new UpgraderButton("Max Amo", buttonsRadius, upgraderButtonsColor,
			{ static_cast<float>(GetScreenWidth() / 2), buttonsYPos + (buttonsHeightSeparation * 2.0f) }, { buttonsXPos, (buttonsYPos + (buttonsHeightSeparation * 2.0f)) - buttonsRadius });

		chargerUpdateButton = new UpgraderButton("Charger", buttonsRadius, upgraderButtonsColor,
			{ static_cast<float>(GetScreenWidth() / 2), buttonsYPos + (buttonsHeightSeparation * 3.0f) }, { buttonsXPos, (buttonsYPos + (buttonsHeightSeparation * 3.0f)) - buttonsRadius });

		fireRateUpdateButton = new UpgraderButton("Fire Rate", buttonsRadius, upgraderButtonsColor,
			{ static_cast<float>(GetScreenWidth() / 2), buttonsYPos + (buttonsHeightSeparation * 4.0f) }, { buttonsXPos, (buttonsYPos + (buttonsHeightSeparation * 4.0f)) - buttonsRadius });

		reloadSpeedUpdateButton = new UpgraderButton("Reload Speed", buttonsRadius, upgraderButtonsColor,
			{ static_cast<float>(GetScreenWidth() / 2), buttonsYPos + (buttonsHeightSeparation * 5.0f) }, { buttonsXPos, (buttonsYPos + (buttonsHeightSeparation * 5.0f)) - buttonsRadius });;

		extraLifeUpdateButton = new UpgraderButton("Lives", buttonsRadius, upgraderButtonsColor,
			{ static_cast<float>(GetScreenWidth() / 2), buttonsYPos + (buttonsHeightSeparation * 6.0f) }, { buttonsXPos, (buttonsYPos + (buttonsHeightSeparation * 6.0f)) - buttonsRadius });

		damageUpdateButton = new UpgraderButton("Damage", buttonsRadius, upgraderButtonsColor,
			{ static_cast<float>(GetScreenWidth() / 2), buttonsYPos + (buttonsHeightSeparation * 7.0f) }, { buttonsXPos, (buttonsYPos + (buttonsHeightSeparation * 7.0f)) - buttonsRadius });

		changeSceneButton = new Button({ static_cast<float>(GetScreenWidth() - (GetScreenWidth() * changeSceneButtonWidthPercentage)), 
			static_cast<float>(GetScreenHeight() * changeSceneButtonYPercentage), 
			GetScreenWidth() * changeSceneButtonWidthPercentage, GetScreenHeight() * changeSceneButtonHeightPercentage },
			changeSceneButtonColorOne, changeSceneButtonColorTwo, "CONTINUE");
	}

	float Upgrader::getPlayerMoneyCircleRadius() 
	{
		return playerMoneyCircleRadius;
	}

	int Upgrader::getPriceHudSize()
	{
		return priceHudSize;
	}

	int Upgrader::getPlayerMoneyHudSize()
	{
		return playerMoneyHudSize;
	}

	int Upgrader::getLevelSize()
	{
		return levelSize;
	}

	int Upgrader::getTitleTextsSize()
	{
		return titleTextsSize;
	}

	int Upgrader::getExplanationTextSize()
	{
		return explanationTextSize;
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

		
		drawTitle();

		drawExplanationText();		

		drawButtons();

		changeSceneButton->draw();

		drawPlayerMoney(survivor);
		
		EndDrawing();
	}	

	void Upgrader::drawTitle()
	{
		DrawText(titleText, static_cast<int>((GetScreenWidth() / 2) - getTitleTextsSize() * (titleTextAmountLetters / 2)),
			static_cast<int>(GetScreenHeight() * titleTextYPercentage), getTitleTextsSize(), titleTextColor);
	}

	void Upgrader::drawExplanationText()
	{
		DrawText(explanationText, static_cast<int>((GetScreenWidth() / 2) - getExplanationTextSize() * (explanationTextAmountLetters / 3)),
			static_cast<int>((GetScreenHeight() * explanationTextYPercentage)), getExplanationTextSize(), explanationTextColor);
	}

	void Upgrader::drawButtons()
	{
		int priceXPos = (GetScreenWidth() / 2) + static_cast<int>((GetScreenWidth() * priceHudSeparationPercentage));
		float buttonsRadius = vectorMath::getScreenHypotenuse() / buttonsRadiusDivider;
		float buttonsYPos = static_cast<float>(GetScreenHeight() * buttonsYPercentage);
		float buttonsHeightSeparation = static_cast<float>(GetScreenHeight() * heightButtonsSeparationPercentage);		

		velocityUpdateButton->drawButton();
		DrawText(TextFormat("%i", levels[0]), static_cast<int>(GetScreenWidth() / 2 - (buttonsRadius / 2)), static_cast<int>(buttonsYPos + (buttonsHeightSeparation * 0.0f)) - static_cast<int>(buttonsRadius), getLevelSize(), levelTextColor);
		DrawText(TextFormat("$ %i", getPrice(0)), priceXPos, static_cast<int>(buttonsYPos + (buttonsHeightSeparation * 0.0f) - buttonsRadius), getPriceHudSize(), priceHudColor);

		maxAcelerationUpdateButton->drawButton();
		DrawText(TextFormat("%i", levels[1]), static_cast<int>(GetScreenWidth() / 2 - (buttonsRadius / 2)), static_cast<int>(buttonsYPos + (buttonsHeightSeparation * 1.0f)) - static_cast<int>(buttonsRadius), getLevelSize(), levelTextColor);
		DrawText(TextFormat("$ %i", getPrice(1)), priceXPos, static_cast<int>(buttonsYPos + (buttonsHeightSeparation * 1.0f) - buttonsRadius), getPriceHudSize(), priceHudColor);

		maxAmoUpdateButton->drawButton();
		DrawText(TextFormat("%i", levels[2]), static_cast<int>(GetScreenWidth() / 2 - (buttonsRadius / 2)), static_cast<int>(buttonsYPos + (buttonsHeightSeparation * 2.0f)) - static_cast<int>(buttonsRadius), getLevelSize(), levelTextColor);
		DrawText(TextFormat("$ %i", getPrice(2)), priceXPos, static_cast<int>(buttonsYPos + (buttonsHeightSeparation * 2.0f) - buttonsRadius), getPriceHudSize(), priceHudColor);

		chargerUpdateButton->drawButton();
		DrawText(TextFormat("%i", levels[3]), static_cast<int>(GetScreenWidth() / 2 - (buttonsRadius / 2)), static_cast<int>(buttonsYPos + (buttonsHeightSeparation * 3.0f)) - static_cast<int>(buttonsRadius), getLevelSize(), levelTextColor);
		DrawText(TextFormat("$ %i", getPrice(3)), priceXPos, static_cast<int>(buttonsYPos + (buttonsHeightSeparation * 3.0f) - buttonsRadius), getPriceHudSize(), priceHudColor);

		fireRateUpdateButton->drawButton();
		DrawText(TextFormat("%i", levels[4]), static_cast<int>(GetScreenWidth() / 2 - (buttonsRadius / 2)), static_cast<int>(buttonsYPos + (buttonsHeightSeparation * 4.0f)) - static_cast<int>(buttonsRadius), getLevelSize(), levelTextColor);
		DrawText(TextFormat("$ %i", getPrice(4)), priceXPos, static_cast<int>(buttonsYPos + (buttonsHeightSeparation * 4.0f) - buttonsRadius), getPriceHudSize(), priceHudColor);

		reloadSpeedUpdateButton->drawButton();
		DrawText(TextFormat("%i", levels[5]), static_cast<int>(GetScreenWidth() / 2 - (buttonsRadius / 2)), static_cast<int>(buttonsYPos + (buttonsHeightSeparation * 5.0f)) - static_cast<int>(buttonsRadius), getLevelSize(), levelTextColor);
		DrawText(TextFormat("$ %i", getPrice(5)), priceXPos, static_cast<int>(buttonsYPos + (buttonsHeightSeparation * 5.0f) - buttonsRadius), getPriceHudSize(), priceHudColor);

		extraLifeUpdateButton->drawButton();
		DrawText(TextFormat("%i", levels[6]), static_cast<int>(GetScreenWidth() / 2 - (buttonsRadius / 2)), static_cast<int>(buttonsYPos + (buttonsHeightSeparation * 6.0f)) - static_cast<int>(buttonsRadius), getLevelSize(), levelTextColor);
		DrawText(TextFormat("$ %i", getPrice(6)), priceXPos, static_cast<int>(buttonsYPos + (buttonsHeightSeparation * 6.0f) - buttonsRadius), getPriceHudSize(), priceHudColor);

		damageUpdateButton->drawButton();
		DrawText(TextFormat("%i", levels[7]), static_cast<int>(GetScreenWidth() / 2 - (buttonsRadius / 2)), static_cast<int>(buttonsYPos + (buttonsHeightSeparation * 7.0f)) - static_cast<int>(buttonsRadius), getLevelSize(), levelTextColor);
		DrawText(TextFormat("$ %i", getPrice(7)), priceXPos, static_cast<int>(buttonsYPos + (buttonsHeightSeparation * 7.0f) - buttonsRadius), getPriceHudSize(), priceHudColor);
	}

	void Upgrader::drawPlayerMoney(Survivor* survivor)
	{
		DrawCircleV({ 1.0f, static_cast<float>(GetScreenHeight() + (getPlayerMoneyCircleRadius() / 2.0f)) }, getPlayerMoneyCircleRadius(), playerMoneyCircleColor);
		DrawText(TextFormat("$ %i", survivor->getMoney()), static_cast<int>(GetScreenWidth() * moneyTextXPercentage), static_cast<int>(GetScreenHeight() * moneyTextYPercentage), getPlayerMoneyHudSize(), playerMoneyColor);
	}

	bool Upgrader::allLevelsMaxed()
	{
		bool levelsMaxed = true;

		for (short i = 0; i < maxButtons; i++)
		{
			if (levels[i] != maxLevel)
			{
				levelsMaxed = false;
				i = maxButtons;
			}
		}

		return levelsMaxed;
	}
}