#include "TestLevel.h"
#include "Engine/Engine.h"
#include "Actor/Player.h"

TestLevel::TestLevel()
{
	Player* player = new Player('P');
	player->SetPosition({ 1, 1 });
	AddActor(player);

}

TestLevel::~TestLevel()
{
}

void TestLevel::Update(float deltaTime)
{
	Super::Update(deltaTime);

	// ESC 키로 종료.
	if (Engine::Get().GetKeyDown(VK_ESCAPE))
	{
		Engine::Get().QuitGame();
	}
}

void TestLevel::Draw()
{
	Super::Draw();

	// 가로 테두리
	for (int x = 0; x < SCREEN_WIDTH; ++x)
	{
		Engine::Get().WriteCell(x, 0, '#');
		Engine::Get().WriteCell(x, SCREEN_HEIGHT - 1, '#');
	}

	// 세로 테두리
	for (int y = 1; y < SCREEN_HEIGHT - 1; ++y)
	{
		Engine::Get().WriteCell(0, y, '#');
		Engine::Get().WriteCell(SCREEN_WIDTH - 1, y, '#');
	}
}