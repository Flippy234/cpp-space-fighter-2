#pragma once

#include "Level.h"

class BossLevel : public Level
{

public:

	/** @brief Instantiate a level object. */
	BossLevel() { }
	virtual ~BossLevel() { }

	/** @brief Load the content for the level, including game objects and resources.
		@param resourceManager A reference to the game's resource manager,
		used for loading and managing game assets (resources). */
	virtual void LoadContent(ResourceManager& resourceManager);
};

