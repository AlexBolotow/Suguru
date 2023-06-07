#include "GameWindow.h"

GameWindow::GameWindow(Window *parent) : Window(parent), ui(new Ui::GameWindowClass())
{
	ui->setupUi(this);
}

GameWindow::~GameWindow()
{
	delete ui;
}

std::string GameWindow::getPathLevel() {
	return pathLevel;
}

void GameWindow::setPathLevel(std::string pathLevel) {
	this->pathLevel = pathLevel;
}

void GameWindow::slotShowLevelsWindow() {
	this->close();
	emit signalShowLevelsWindow();
}

void GameWindow::printBoard() {
	boardSuguru = new BoardSuguru(pathLevel);
	ui->tableWidget->setBoardWidget(*boardSuguru);
	ui->tableWidget->setParent(this);
}

bool GameWindow::checkUserSolutuion() {
	ui->tableWidget->getBoardSuguru(*boardSuguru);
	if (boardSuguru->isSoluton()) {
		return true;
	}
	return false;
}

void GameWindow::slotCheckUserSolutuion() {
	setlocale(LC_ALL, "ru");
	if (checkUserSolutuion()) {
		QMessageBox::about(this, "Результат", "Решение верно");
		boardSuguru = nullptr;
		this->close();
		emit signalShowLevelsWindow();
	}
	else {
		QMessageBox::StandardButton reply = QMessageBox::question(this, "Результат", "Решение неверно. Хотите продолжить?",
			QMessageBox::Yes | QMessageBox::No);
		if (reply == QMessageBox::No) {
			boardSuguru = nullptr;
			this->close();
			emit signalShowLevelsWindow();
		}
	}
}