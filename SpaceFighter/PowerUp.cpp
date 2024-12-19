#include "PowerUp.h"
#include "Level.h"

PowerUp::PowerUp() 
{
    SetCollisionRadius(15);
}

void PowerUp::Update(const GameTime& gameTime) {
    if (IsActive()) {

        TranslatePosition(0, m_floatSpeed * gameTime.GetElapsedTime());

        if (!IsOnScreen()) {
            Deactivate();
        }
    }
    GameObject::Update(gameTime);
}

void PowerUp::Draw(SpriteBatch& spriteBatch) {
    if (IsActive() && m_pTexture) 
    {
        const float alpha = GetCurrentLevel()->GetAlpha();
        spriteBatch.Draw(m_pTexture, GetPosition(), Color::WHITE * alpha, m_pTexture->GetCenter());
    }
}

void PowerUp::Activate(const Vector2& position) {
    SetPosition(position);
    GameObject::Activate();
}