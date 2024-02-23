#include "GameObject.h"

GameObject::GameObject(string type, Geometry geometry, Material material) : _type(type), _appearance(new appearance(geometry,material))
{
	_parent = nullptr;
	_transform = new Transform();
	_physics = new Rigidbody(_transform,2.0f);
}

GameObject::~GameObject()
{
	_parent = nullptr;
	delete _transform;

}

void GameObject::Update(float dt)
{

	_transform->Update(dt);
	_physics->Update(dt);
}



