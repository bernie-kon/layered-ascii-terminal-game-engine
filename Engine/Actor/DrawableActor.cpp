#include "PreCompiledHeader.h"
#include "DrawableActor.h"
#include "Engine/Engine.h"

DrawableActor::DrawableActor(char image)
	: Actor(), image(image)
{
}

void DrawableActor::Draw()
{
	Super::Draw();

	// 그리기.
	// 1단계: 콘솔 좌표 옮기기.
	//Engine::Get().SetCursorPosition(position);
	Engine::Get().WriteCell((int)position.x, (int)position.y, image);
}

void DrawableActor::SetPosition(const Vector2& newPosition)
{
	// 위치를 새로 옮기기.
	Super::SetPosition(newPosition);
}