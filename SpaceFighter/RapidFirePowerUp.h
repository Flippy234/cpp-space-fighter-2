#pragma once
#include "PowerUp.h"
#include "PlayerShip.h"
#include "Blaster.h"
class RapidFirePowerUp : public PowerUp {
public:
    RapidFirePowerUp();
    virtual ~RapidFirePowerUp() {}

    virtual void OnCollect(PlayerShip* pPlayer) override;
    virtual std::string ToString() const override { return "RapidFire PowerUp"; }

private:
	const float COOLDOWN_REDUCTION = 0.5f; // 50% reduction
};