#pragma once
#include "Screen.h"
#include <algorithm>

struct User {
	std::string name;
	int score;
};

bool cmp(const User& a, const User& b);

class RankScreen : public Screen
{
public:
	RankScreen();
	RankScreen(Shape* background) : Screen{ background } {}
	void render() override;
	void readScore();
	void loadTexts();
private:
	std::vector<User> m_users{};
	std::string m_key{ "" };
	Shape* m_board{};
};

