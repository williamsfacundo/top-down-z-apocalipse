#ifndef GAME_H
#define GAME_H

class Game
{
private:
	int screenWidth;
	int screenHeight;
	const char* title = "Z-APOCALIPSE";
	const short fps = 60;
public:
	Game(int screenWidth, int screenHeight);
	~Game();

	void setScreenWidth(int screenWidth);
	void setScreenHeight(int screenHeight);

	void init();
	void input();
	void update();
	void draw();
	void deinit();

	void runGame();
};

#endif
