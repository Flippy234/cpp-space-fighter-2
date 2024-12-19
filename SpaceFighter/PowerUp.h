#pragma once

#include "GameObject.h"

class PlayerShip;  

class PowerUp : public GameObject {
public:
    PowerUp();
    virtual ~PowerUp() {}

    virtual void Update(const GameTime& gameTime) override;
    virtual void Draw(SpriteBatch& spriteBatch) override;

    virtual void OnCollect(PlayerShip* pPlayer) = 0;
    virtual void Activate(const Vector2& position);

    virtual std::string ToString() const override { return "PowerUp"; }
    virtual CollisionType GetCollisionType() const override { return CollisionType::PowerUp; }

    virtual void SetTexture(Texture* pTexture) { m_pTexture = pTexture; }

protected:
    Texture* m_pTexture = nullptr;
    float m_floatSpeed = 50.0f;  
};