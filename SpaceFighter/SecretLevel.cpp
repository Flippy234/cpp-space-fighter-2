

#include "SecretLevel.h"
#include "BioEnemyShip.h"


void SecretLevel::LoadContent(ResourceManager& resourceManager)
{
	// Setup enemy ships
	Texture* pTexture = resourceManager.Load<Texture>("Textures\\BioEnemyShipSecret.png");

	const int COUNT = 21;

	double xPositions[COUNT] =
	{
		0.1, 0.2, 0.3,
		0.4, 0.5, 0.6,
		0.7, 0.8, 0.9, 0.8, 0.7,
		0.6, 0.5, 0.4, 0.3, 0.2,
		0.1, 0.2, 0.3, 0.4, 0.5
	};

	double delays[COUNT] =
	{
		0.0, 0.5, 0.5,
		0.5, 0.5, 0.5,
		0.5, 0.5, 0.5, 0.5, 0.5,
		0.5, 0.5, 0.5, 0.5, 0.5,
		0.5, 0.5, 0.5, 0.5, 0.5
	};

	float delay = 3.0; // start delay
	Vector2 position;

	for (int i = 0; i < COUNT; i++)
	{
		delay += delays[i];
		position.Set(xPositions[i] * Game::GetScreenWidth(), -pTexture->GetCenter().Y);

		BioEnemyShip* pEnemy = new BioEnemyShip();
		pEnemy->SetTexture(pTexture);
		pEnemy->SetCurrentLevel(this);
		pEnemy->Initialize(position, (float)delay);
		AddGameObject(pEnemy);
	}

	// Setup background
	SetBackground(resourceManager.Load<Texture>("Textures\\SpaceBackground02.png"));

	Level::LoadContent(resourceManager);
}

