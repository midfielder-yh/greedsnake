#include<iostream>
#include"windowdesign.h"
#include"food.h"

class Progress
{
public:
	Progress():speed(200), key(1), score(0) {}
	void Start();
	void Select();
	void DrawMap();
	int Game();
	int Menu();
	void UpdateScore();
	void AllGame();
	int GameOver();
private:
	int key;
	int speed;
	int score;
};
