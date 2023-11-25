#pragma once
#include "Screen.h"
#include <algorithm>
#include <filesystem>

struct User {
	std::string name;
	std::string score;
};

bool cmp(const User& a, const User& b);
template <typename TP>
std::time_t to_time_t(TP tp)
{
	using namespace std::chrono;
	auto sctp = time_point_cast<system_clock::duration>(tp - TP::clock::now()
		+ system_clock::now());
	return system_clock::to_time_t(sctp);
}

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
	time_t ftime{0};
};

