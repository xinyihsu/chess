#pragma once
#include <vector>

enum EndStatus {
	CHECKMATE, //�N��
	TIME_UP, //�ɶ���
	DRAW, //�M��(�L�l�i�ʡA���S�Q�N�x)
	SURRENDER, //�{��
};

//�B�z�C�����A
class GameManager
{
private:
public:
	int turns; //�����
};
