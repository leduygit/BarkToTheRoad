#include "RankScreen.h"

RankScreen::RankScreen() : m_board{ MyShape[LEADERBOARD] }
{
	ifstream in("key.txt");
	in >> m_key;
	in.close();
	setBackground(MyShape[BACKGROUND_EMPTY]);
}

void RankScreen::render()
{
	if (m_users.empty()) {
		readScore();
		loadTexts();
	}
	m_background->render(0, 0);
	m_board->render(405, 220);
	renderText();
}

void RankScreen::readScore()
{
	ifstream in("score.txt");

	while (!in.eof()) {
		std::string name = "", score = "";
		getline(in, name);
		getline(in, score);
		m_users.push_back(User{ decrypt(name, m_key), std::atoi(decrypt(score, m_key).c_str()) });
	}
	std::sort(m_users.begin(), m_users.end(), cmp);

	in.close();
}

void RankScreen::loadTexts()
{
	RECT r;
	r.left = 600;
	r.right = 700;
	r.top = 230;
	r.bottom = 330;
	addText(new Text{ m_users[0].name, r });
}

bool cmp(const User& a, const User& b)
{
	return a.score > b.score;
}
