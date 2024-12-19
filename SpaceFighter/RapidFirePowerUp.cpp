#include "RapidFirePowerUp.h"

RapidFirePowerUp::RapidFirePowerUp()
{

}

void RapidFirePowerUp::OnCollect(PlayerShip* pPlayer) {
    Weapon* pWeapon = pPlayer->GetWeapon("Main Blaster");
    Blaster* pBlaster = dynamic_cast<Blaster*>(pWeapon);

    if (pBlaster)
    {
        float currentCooldown = pBlaster->GetCooldownSeconds();
        pBlaster->SetCooldownSeconds(currentCooldown * COOLDOWN_REDUCTION);
    }
    Deactivate();
}
