#pragma once
#pragma execution_character_set("utf-8")
#include "QMessageBox"
#include "Window.h"
#include "BoardWidget.h"
#include "ui_GameWindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class GameWindowClass; };
QT_END_NAMESPACE

class GameWindow : public Window
{
	Q_OBJECT

public:
	GameWindow(Window *parent = nullptr);
	~GameWindow();
	std::string getPathLevel();
	void setPathLevel(std::string pathLevel);
	void printBoard();
	bool checkUserSolutuion();

signals:
	void signalShowLevelsWindow();

private slots:
	void slotShowLevelsWindow();
	void slotCheckUserSolutuion();

private:
	Ui::GameWindowClass *ui;
	BoardSuguru* boardSuguru;
	//BoardWidget* boardWidget;
	std::string pathLevel;
};
