#pragma once
#include <vector>

enum EndStatus {
	CHECKMATE, //將死
	TIME_UP, //時間到
	DRAW, //和局(無子可動，但沒被將軍)
	SURRENDER, //認輸
};

//處理遊戲狀態
class GameManager
{
private:
public:
	int turns; //輪到誰
};
