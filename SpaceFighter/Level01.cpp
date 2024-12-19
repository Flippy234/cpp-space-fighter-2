

#include "Level01.h"
#include "BioEnemyShip.h"
#include "RapidFirePowerUp.h"
#include "PowerUp.h"

void Level01::LoadContent(ResourceManager& resourceManager)
{
	// Setup enemy ships
	Texture *pTexture = resourceManager.Load<Texture>("Textures\\BioEnemyShip.png");

	const int COUNT = 21;

	double xPositions[COUNT] =
	{
		0.25, 0.2, 0.3,
		0.75, 0.8, 0.7,
		0.3, 0.25, 0.35, 0.2, 0.4,
		0.7, 0.75, 0.65, 0.8, 0.6,
		0.5, 0.4, 0.6, 0.45, 0.55
	};
	
	double delays[COUNT] =
	{
		0.0, 0.25, 0.25,
		3.0, 0.25, 0.25,
		3.25, 0.25, 0.25, 0.25, 0.25,
		3.25, 0.25, 0.25, 0.25, 0.25,
		3.5, 0.3, 0.3, 0.3, 0.3
	};

	float delay = 3.0; // start delay
	Vector2 position;

	for (int i = 0; i < COUNT; i++)
	{
		delay += delays[i];
		position.Set(xPositions[i] * Game::GetScreenWidth(), -pTexture->GetCenter().Y);

		BioEnemyShip *pEnemy = new BioEnemyShip();
		pEnemy->SetTexture(pTexture);
		pEnemy->SetCurrentLevel(this);
		pEnemy->Initialize(position, (float)delay);
		AddGameObject(pEnemy);
	}

	// setup Powerups
	RapidFirePowerUp* pPowerUp = new RapidFirePowerUp();
	pPowerUp->SetTexture(resourceManager.Load<Texture>("Textures\\PowerUp.png"));
	Vector2 powerUpPosition(Game::GetScreenWidth() / 2, 100); // Center of screen, 100 pixels from top
	pPowerUp->Activate(powerUpPosition);
	AddGameObject(pPowerUp);


	// Setup background
	SetBackground(resourceManager.Load<Texture>("Textures\\SpaceBackground01.png"));

	Level::LoadContent(resourceManager);
}

