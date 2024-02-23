#pragma once

#include <directxmath.h>
#include <d3d11_1.h>
#include <string>
#include "Vector.h"
#include "Transform.h"
#include "PhysicsModel.h"
#include "Rigidbody.h"
#include "appearance.h"

using namespace DirectX;
using namespace std;



class GameObject
{
public:
	GameObject(string type, Geometry geometry, Material material);
	~GameObject();

	string GetType() const { return _type; }

	void SetParent(GameObject * parent) { _parent = parent; }

	// Setters and Getters for position/rotation/scale
	


	// Rendering information

	
	Transform* GetTransform() { return _transform; }
	Rigidbody* GetPhysics() { return _physics; }
	appearance* GetAppearance() { return _appearance; }



	void Update(float dt);
	
	float _rad;
private:
	GameObject* _parent = nullptr;

	string _type;
	XMFLOAT4X4 _world;

	appearance* _appearance;
	Transform* _transform;
	Rigidbody* _physics;

	
};

