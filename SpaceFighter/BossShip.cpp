
#include "BossShip.h"
#include "Level.h"


BossShip::BossShip()
{
	SetSpeed(32);
	SetMaxHitPoints(32);
	SetCollisionRadius(150);
}


void BossShip::Update(const GameTime& gameTime)
{
	if (IsActive())
	{
		float x = 21*sin(gameTime.GetTotalTime() * Math::PI + GetIndex())-.2;
		x *= GetSpeed() * gameTime.GetElapsedTime() * 1.4f;
		TranslatePosition(x, GetSpeed() * gameTime.GetElapsedTime());

		GetPosition().Display();

		if (!IsOnScreen())
		{
			Deactivate();
		}
	}

	EnemyShip::Update(gameTime);
}

void BossShip::BossWeapon()
{
	FireWeapons();
}


void BossShip::Draw(SpriteBatch& spriteBatch)
{
	if (IsActive())
	{
		const float alpha = GetCurrentLevel()->GetAlpha();
		spriteBatch.Draw(m_pTexture, GetPosition(), Color::WHITE * alpha, m_pTexture->GetCenter(), Vector2::ONE, Math::PI, 1);
	}
}
