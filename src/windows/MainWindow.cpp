#include "MainWindow.h"
extern Theme theme;

void MainWindow::setBackgroundColor() {
	QPixmap background;
	if (theme.getThemeState() == Theme::Dark) {
		background.load("img/backgroundMainWindowDark.png");
	}
	else {
		background.load("img/backgroundMainWindowLight.png");
	}

	background = background.scaled(this->size(), Qt::IgnoreAspectRatio);
	QPalette palette;
	palette.setBrush(QPalette::Background, background);
	this->setPalette(palette);
}

MainWindow::MainWindow(Window* parent) : Window(parent), ui(new Ui::MainWindowClass()) {
	ui->setupUi(this);
	setThemeWindow();
	rulesWindow = new RulesWindow();
	connect(rulesWindow, &RulesWindow::signalShowMainWindow, this, &MainWindow::slotShowMainWindow);
	levelsWindow = new LevelsWindow();
	connect(levelsWindow, &LevelsWindow::signalShowMainWindow, this, &MainWindow::slotShowMainWindow);
}

MainWindow::~MainWindow() {
	delete ui;
}

void MainWindow::slotShowMainWindow() {
	setThemeWindow();
	this->show();
}

void MainWindow::slotShowLevelsWindow() {
	levelsWindow->setThemeWindow();
	levelsWindow->show();
	this->close();
}

void MainWindow::slotShowRulesWindow() {
	rulesWindow->setThemeWindow();
	rulesWindow->show();
	this->close();
}