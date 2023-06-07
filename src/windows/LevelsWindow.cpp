#include "LevelsWindow.h"

LevelsWindow::LevelsWindow(Window *parent) : Window(parent), ui(new Ui::LevelsWindowClass())
{
	ui->setupUi(this);
	gameWindow = new GameWindow();
	connect(gameWindow, &GameWindow::signalShowLevelsWindow, this, &LevelsWindow::slotShowLevelsWindow);
}

LevelsWindow::~LevelsWindow()
{
	delete ui;
}

void LevelsWindow::slotShowMainWindow() {
	this->close();
	emit signalShowMainWindow();
}

void LevelsWindow::slotShowLevelsWindow() {
	setThemeWindow();
	this->show();
}

void LevelsWindow::slotShowGameWindowLevel1() {
	gameWindow->setPathLevel("levelsSuguru/level1.txt");
	gameWindow->setThemeWindow();
	gameWindow->printBoard();
	gameWindow->show();
	this->close();
}

void LevelsWindow::slotShowGameWindowLevel2() {
	gameWindow->setPathLevel("levelsSuguru/level2.txt");
	gameWindow->setThemeWindow();
	gameWindow->printBoard();
	gameWindow->show();
	this->close();
}

void LevelsWindow::slotShowGameWindowLevel3() {
	gameWindow->setPathLevel("levelsSuguru/level3.txt");
	gameWindow->setThemeWindow();
	gameWindow->printBoard();
	gameWindow->show();
	this->close();
}

void LevelsWindow::slotShowGameWindowLevel4() {
	gameWindow->setPathLevel("levelsSuguru/level4.txt");
	gameWindow->setThemeWindow();
	gameWindow->printBoard();
	gameWindow->show();
	this->close();
}

void LevelsWindow::slotShowGameWindowLevel5() {
	gameWindow->setPathLevel("levelsSuguru/level5.txt");
	gameWindow->setThemeWindow();
	gameWindow->printBoard();
	gameWindow->show();
	this->close();
}

void LevelsWindow::slotShowGameWindowLevel6() {
	gameWindow->setPathLevel("levelsSuguru/level6.txt");
	gameWindow->setThemeWindow();
	gameWindow->printBoard();
	gameWindow->show();
	this->close();
}