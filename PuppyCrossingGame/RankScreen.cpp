#include "RankScreen.h"

RankScreen::RankScreen() : m_board{ MyShape[LEADERBOARD] }
{
	ifstream in("key.txt");
	in >> m_key;
	in.close();
	setBackground(MyShape[BACKGROUND_EMPTY]);
	m_users.clear();
	
	Shape* homeButtonState = new Shape[2]{ *MyShape[HOME], *MyShape[HOME_HOVER] };
	Button* homeButton = new ChangeScreenButton{ homeButtonState, MENU_SCREEN };
	homeButton->setPos({ 620, 230 });
	addButton(homeButton);
}

void RankScreen::render()
{
	if (ftime == 0 || to_time_t(std::filesystem::last_write_time("score.txt")) != ftime) {
		readScore();
		loadTexts();
		ftime = to_time_t(std::filesystem::last_write_time("score.txt"));
	}
	m_background->render(0, 0);
	m_board->render(350, 190);
	renderText();

	for (auto b : getButtons()) {
		b->render();
	}
}

void RankScreen::readScore()
{
	m_users.clear();
	ifstream in("score.txt");

	while (!in.eof()) {
		std::string name = "", score = "";
		getline(in, name);
		getline(in, score);
		m_users.push_back(User{ decrypt(name, m_key), decrypt(score, m_key) });
	}
	std::sort(m_users.begin(), m_users.end(), cmp);

	in.close();
}

void RankScreen::loadTexts()
{
	clearTexts();
	RECT r{ 600, 210, 700, 310 };
	addText(new Text{ m_users[0].name, r });
	r.top += 50; r.bottom += 50;
	addText(new Text{ m_users[0].score, r });

	r = { 420, 240, 520, 340 };
	addText(new Text{ m_users[1].name, r });
	r.top += 50; r.bottom += 50;
	addText(new Text{ m_users[1].score, r });

	r = { 785, 260, 885, 360 };
	addText(new Text{ m_users[2].name, r });
	r.top += 50; r.bottom += 50;
	addText(new Text{ m_users[2].score, r });
}

bool cmp(const User& a, const User& b)
{
	return std::atoi(a.score.c_str()) > std::atoi(b.score.c_str());
}
