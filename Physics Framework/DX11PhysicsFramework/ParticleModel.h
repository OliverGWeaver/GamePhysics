
#include "PhysicsModel.h"
class ParticleModel : public PhysicsModel
{
	virtual void AddRelativeForce(Vector force, Vector point) override { AddForce(force); }
};
