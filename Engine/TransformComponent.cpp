#include "pch.h"
#include "TransformComponent.h"
#include "Object.h"

TransformComponent::TransformComponent(Object* gameObject) : Component(gameObject)
{
}

void TransformComponent::Update(float deltaTime)
{
}
void TransformComponent::Render()
{
}

void TransformComponent::MoveBy(const Vector2Df& offset)
{
	MoveBy(offset.x, offset.y);
}
void TransformComponent::MoveBy(float offsetX, float offsetY)
{
	localPosition.x += offsetX;
	localPosition.y += offsetY;
	isUpdated = false;
}

// position
void TransformComponent::SetWorldPosition(const Vector2Df& position)
{
	SetWorldPosition(position.x, position.y);
	isUpdated = false;
}
void TransformComponent::SetWorldPosition(float positionX, float positionY)
{
	Vector2Df newPosition = { positionX, positionY };
	if (parent == nullptr)
	{
		localPosition = newPosition;
	}
	else
	{
		Matrix2D newWorldTransform = createTransform(newPosition, GetWorldRotation(), GetWorldScale());
		localTransform = parent->GetWorldTransform().GetInversed() * newWorldTransform;

		SetLocalInfoFrom(localTransform);

		isUpdated = false;
		UpdateLocalTransform();
	}
}
void TransformComponent::SetLocalPosition(const Vector2Df& position)
{
	SetLocalPosition(position.x, position.y);
}
void TransformComponent::SetLocalPosition(float positionX, float positionY)
{
	localPosition.x = positionX;
	localPosition.y = positionY;
	isUpdated = false;
}
const Vector2Df& TransformComponent::GetWorldPosition() const
{
	UpdateLocalTransform();
	if (parent == nullptr)
		return GetLocalPosition();

	SetWorldInfoFrom(parent->GetWorldTransform() * localTransform);
	return position;
}
const Vector2Df& TransformComponent::GetLocalPosition() const
{
	UpdateLocalTransform();
	return localPosition;
}

// rotate
void TransformComponent::RotateBy(float offset)
{
	localRotation += offset;
	while (localRotation >= 360)
	{
		localRotation -= 360;
	}
	while (localRotation < 0)
	{
		localRotation += 360;
	}
	isUpdated = false;
}
void TransformComponent::SetWorldRotation(float angle)
{
	if (parent == nullptr)
	{
		localRotation = angle;
	}
	else
	{
		Matrix2D newWorldTransform = createTransform(GetWorldPosition(), angle, GetWorldScale());
		localTransform = parent->GetWorldTransform().GetInversed() * newWorldTransform;

		SetLocalInfoFrom(localTransform);

		isUpdated = false;
		UpdateLocalTransform();
	}
}
void TransformComponent::SetLocalRotation(float angle)
{
	localRotation = angle;
	while (localRotation >= 360)
	{
		localRotation -= 360;
	}
	while (localRotation < 0)
	{
		localRotation += 360;
	}
	isUpdated = false;
}
const float TransformComponent::GetWorldRotation() const
{
	UpdateLocalTransform();
	if (parent == nullptr)
		return GetLocalRotation();

	SetWorldInfoFrom(parent->GetWorldTransform() * localTransform);
	return rotation;
}
const float TransformComponent::GetLocalRotation() const
{
	UpdateLocalTransform();
	return localRotation;
}

// scale
void TransformComponent::ScaleBy(const Vector2Df& scale)
{
	ScaleBy(scale.x, scale.y);
}
void TransformComponent::ScaleBy(float scaleX, float scaleY)
{
	localScale.x *= scaleX;
	localScale.y *= scaleY;
	isUpdated = false;

}
void TransformComponent::SetWorldScale(const Vector2Df& scale)
{
	SetWorldScale(scale.x, scale.y);
	isUpdated = false;
}
void TransformComponent::SetWorldScale(float scaleX, float scaleY)
{
	Vector2Df newScale = { scaleX, scaleY };

	if (parent == nullptr)
	{
		localScale = newScale;
	}
	else
	{
		Matrix2D newWorldTransform = createTransform(GetWorldPosition(), GetWorldRotation(), newScale);
		localTransform = parent->GetWorldTransform().GetInversed() * newWorldTransform;

		SetLocalInfoFrom(localTransform);

		isUpdated = false;
		UpdateLocalTransform();
	}
}
void TransformComponent::SetLocalScale(const Vector2Df& scale)
{
	SetLocalScale(scale.x, scale.y);
}
void TransformComponent::SetLocalScale(float scaleX, float scaleY)
{
	localScale.x = scaleX;
	localScale.y = scaleY;
	isUpdated = false;
}
const Vector2Df& TransformComponent::GetWorldScale() const
{
	UpdateLocalTransform();
	if (parent == nullptr)
		return GetLocalScale();

	SetWorldInfoFrom(parent->GetWorldTransform() * localTransform);
	return scale;
}
const Vector2Df& TransformComponent::GetLocalScale() const
{
	UpdateLocalTransform();
	return localScale;
}

// transform
const Matrix2D TransformComponent::GetWorldTransform() const
{
	UpdateLocalTransform();

	if (parent == nullptr)
	{
		return localTransform;
	}
	return parent->GetWorldTransform() * localTransform;
}
void TransformComponent::UpdateLocalTransform() const
{
	if (!isUpdated)
	{
		localTransform = createTransform(localPosition, localRotation, localScale);
		isUpdated = true;
	}
}
void TransformComponent::UpdateLocalTransform(const Vector2Df& position, float rotation, const Vector2Df& scale) const
{
	if (!isUpdated)
	{
		localTransform = createTransform(position, rotation, scale);
		isUpdated = true;
	}
}
Matrix2D TransformComponent::createTransform(const Vector2Df& position, float rotation, const Vector2Df& scale) const
{
	return Matrix2D(position, rotation, scale);
}

// parent
void TransformComponent::SetParent(TransformComponent* newParent)
{
	if (parent == nullptr && newParent != nullptr)
	{
		newParent->GameObject->AddChild(GameObject);
		localTransform = newParent->GetWorldTransform().GetInversed() * localTransform;
	}
	else if (parent != nullptr && newParent == nullptr)
	{
		parent->GameObject->RemoveChild(GameObject);
		localTransform = parent->GetWorldTransform() * localTransform;
	}
	else if (parent != nullptr && newParent != nullptr)
	{
		parent->GameObject->RemoveChild(GameObject);
		newParent->GameObject->AddChild(GameObject);
		localTransform = newParent->GetWorldTransform().GetInversed() * (parent->GetWorldTransform()) * localTransform;
	}

	SetLocalInfoFrom(localTransform);

	parent = newParent;
	isUpdated = false;
}
TransformComponent* TransformComponent::GetParent() const
{
	return parent;
}

// info from
void TransformComponent::SetWorldInfoFrom(const Matrix2D& transform) const
{
	position.x = transform.GetMatrix()[0][2];
	position.y = transform.GetMatrix()[1][2];

	scale.x = std::sqrt(transform.GetMatrix()[0][0] * transform.GetMatrix()[0][0] + transform.GetMatrix()[1][0] * transform.GetMatrix()[1][0]);
	scale.y = std::sqrt(transform.GetMatrix()[0][1] * transform.GetMatrix()[0][1] + transform.GetMatrix()[1][1] * transform.GetMatrix()[1][1]);

	rotation = std::atan2(transform.GetMatrix()[0][1], transform.GetMatrix()[0][0]) * 180 / (float)3.14159265;
}
void TransformComponent::SetLocalInfoFrom(const Matrix2D& transform) const
{
	localPosition.x = transform.GetMatrix()[0][2];
	localPosition.y = transform.GetMatrix()[1][2];

	localScale.x = std::sqrt(transform.GetMatrix()[0][0] * transform.GetMatrix()[0][0] + transform.GetMatrix()[1][0] * transform.GetMatrix()[1][0]);
	localScale.y = std::sqrt(transform.GetMatrix()[0][1] * transform.GetMatrix()[0][1] + transform.GetMatrix()[1][1] * transform.GetMatrix()[1][1]);

	localRotation = std::atan2(transform.GetMatrix()[0][1], transform.GetMatrix()[0][0]) * 180 / (float)3.14159265;
}

void TransformComponent::Print() const
{
	std::cout << "Transform name : " << GameObject->GetName() << std::endl;

	std::cout << "-Position " << std::endl;
	std::cout << "--World: " << GetWorldPosition().x << "  " << GetWorldPosition().y << std::endl;
	std::cout << "--Local: " << GetLocalPosition().x << "  " << GetLocalPosition().y << std::endl;

	std::cout << "-Rotation " << std::endl;
	std::cout << "--World: " << GetWorldRotation() << std::endl;
	std::cout << "--Local: " << GetLocalRotation() << std::endl;

	std::cout << "-Scale " << std::endl;
	std::cout << "--World: " << GetWorldScale().x << "  " << GetWorldScale().y << std::endl;
	std::cout << "--Local: " << GetLocalScale().x << "  " << GetLocalScale().y << std::endl;

}
