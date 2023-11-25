#pragma once
#include <windows.h>
#include "Global.h"
#include "ScreenId.h"
#include "Gameplay.h"
#include <string>
enum ButtonState {
	NORMAL, FOCUSED, CLICKED
};
class Button
{
public:
	Button() = default;
	Button(Shape* shape) : m_shape{ shape } {}
	Button(COORD pos, Shape* shape, ButtonState state = NORMAL) 
		: m_pos{ pos }, m_shape{ shape }, m_state{ state } {}

	void render();
	void setState(ButtonState s) {
		m_state = s;
	}
	void setPos(COORD pos);
	bool isInside(POINT p) const;
	bool isHovering() const;
	virtual void onClick() {
		OutputDebugStringA("Clicked");
		m_state = CLICKED;
	}
	virtual void setShowDialog(bool& show) {}
	COORD getPos() const;
	virtual void setFileName(std::string filename) {}
	virtual void setLine(int line) {};
	void getSize(int& w, int& h) {
		m_shape->getSize(w, h);
	}
private:
	COORD m_pos{};
	ButtonState m_state{NORMAL};
	Shape* m_shape;
};

class ChangeScreenButton : public Button {
public:
	ChangeScreenButton(Shape* shape, ScreenId next_screen) : Button(shape), m_next_screen{ next_screen } {}
	void setShowDialog(bool& show) {
		m_show_dialog = &show;
	}
	void onClick();
private:
	bool* m_show_dialog{ nullptr };
	ScreenId m_next_screen{};
};

class NewGameButton : public Button {
public:
	NewGameButton(Shape* shape, Gameplay* gp) : Button(shape), m_gp{ gp } {}
	void onClick() {
		*m_gp = Gameplay{};
		Global::current_screen = GAME_SCREEN;
	}
private:
	Gameplay* m_gp{ nullptr };
};

class PauseButton : public Button {
public:
	void onClick();
};

class QuitButton : public Button {
public:
	QuitButton(Shape* shape) : Button(shape) {}
	void onClick() {
		Global::window_should_close = true;
	}
};

class SaveGameButton : public Button {
public:
	SaveGameButton(Shape* shape, Gameplay*& gp, bool& render_dialog, std::string filename) : Button(shape), m_gp{ gp }, m_show{ &render_dialog }, m_file_name(filename) {}
	void onClick() {
		std::string saveName = m_gp->getUserName();

		std::vector<std::string> saveFiles;
		std::ifstream saveFile("game_save/name.txt");
		for (std::string line; getline(saveFile, line);)
		{
			saveFiles.push_back(line);
		}

		saveFile.close();

		saveFiles[m_line] = saveName;

		std::ofstream out("game_save/name.txt");
		for (int i = 0; i < 3; ++i)
		{
			out << saveFiles[i] << std::endl;
		}
		out.close();

		m_file_name = "game_save/" + saveName + ".txt";
		
		//*m_gp = Gameplay();
		m_gp->saveGame(m_file_name);
		OutputDebugString(L"Clicked\n");
		*m_show = false;
		Global::current_screen = MENU_SCREEN;

	}
	
	std::string getFileName() const {
		return m_file_name;
	}

	void setLine(int line) {
		m_line = line;
	}

private:
	Gameplay* m_gp{ nullptr };
	bool* m_show{ nullptr };
	std::string m_file_name = "";
	int m_line = 0;
};

class LoadGameButton : public Button {
public:
	LoadGameButton(Shape* shape, Gameplay*& gp, std::string filename): 
		Button(shape), m_gp{ gp }, m_file_name(filename){}
	
	void onClick() {
		/*WCHAR Filestring[1000]{0};
		OPENFILENAME opf = { 0 };
		opf.lStructSize = sizeof(OPENFILENAME);
		opf.lpstrFile = Filestring;
		opf.nMaxFile = MAX_PATH;
		opf.lpstrInitialDir = NULL;
		if (GetOpenFileName(&opf) != 0) {
			std::string delimiter = "\\";
			std::wstring ws(Filestring);
			std::string s(ws.begin(), ws.end());

			size_t pos = 0;
			std::string token;
			while ((pos = s.find(delimiter)) != std::string::npos) {
				token = s.substr(0, pos);
				s.erase(0, pos + delimiter.length());
			}
			
			m_gp->loadGame(s);
			Global::current_screen = GAME_SCREEN;
		}*/

		if (m_file_name != "empty") {
			*m_gp = Gameplay();
			m_gp->loadGame("game_save/" + m_file_name + ".txt");
		}
		Global::current_screen = GAME_SCREEN;
	}

	std::string getFileName() const {
		return m_file_name;
	}

	void setFileName(std::string filename) {
		m_file_name = filename;
	}
private:
	std::string m_file_name = "empty";
	Gameplay* m_gp{ nullptr };
};

class OpenDialogButton : public Button {
public:
	OpenDialogButton(Shape* shape, bool& show) : Button(shape), m_show{ &show } {}
	void onClick() {
		*m_show = true;
	}
private:
	bool *m_show;
};

class CloseDialogButton : public Button {
public:
	CloseDialogButton(Shape* shape, bool& show, Gameplay*& gp) : Button(shape), m_show{ &show }, m_gp{ gp } {}
	void onClick() {
		*m_show = false;
		if (!m_gp->getIsNewGame()) m_gp->setPause(false);
	}
private:
	Gameplay* m_gp;
	bool* m_show;
};
