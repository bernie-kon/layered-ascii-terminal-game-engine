#include "Player.h"
#include "Engine/Engine.h"
#include "Math/Vector2.h"

Player::Player(char image)
	: Super(image)
{
}

void Player::Update(float deltaTime)
{
	// 부모 함수 호출.
	Super::Update(deltaTime);

	// 새 위치
	Vector2 newPosition = position;

	if (Engine::Get().GetKey(VK_LEFT))  --newPosition.x;
	if (Engine::Get().GetKey(VK_RIGHT)) ++newPosition.x;
	if (Engine::Get().GetKey(VK_UP))    --newPosition.y;
	if (Engine::Get().GetKey(VK_DOWN))  ++newPosition.y;

	// 테두리 안으로 이동 범위 제한
	int GameWidth	= Engine::Get().GetScreenWidth();
	int GameHeight	= Engine::Get().GetScreenHeight();

	if (newPosition.x < 1)                newPosition.x = 1;
	if (newPosition.x > GameWidth - 2) newPosition.x = GameWidth - 2;
	if (newPosition.y < 1)                newPosition.y = 1;
	if (newPosition.y > GameHeight - 2) newPosition.y = GameHeight - 2;
	
	SetPosition(newPosition);
}