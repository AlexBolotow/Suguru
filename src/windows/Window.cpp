#include "Window.h"
extern Theme theme;

Window::Window(QWidget* parent) : QWidget(parent), ui(new Ui::Form()) {
	ui->setupUi(this);
	this->setFixedSize(800, 600);
	this->setWindowFlags(Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint);
}

Window::~Window() {
	delete ui;
}


void Window::setBackgroundColor() {
	QPixmap background;
	if (theme.getThemeState() == Theme::Dark) {
		background.load("img/backgroundWindowDark.png");
	}
	else {
		background.load("img/backgroundWindowLight.png");
	}

	background = background.scaled(this->size(), Qt::IgnoreAspectRatio);
	QPalette palette;
	palette.setBrush(QPalette::Background, background);
	this->setPalette(palette);
}

void Window::setThemeWindow() {
	setBackgroundColor();
	setThemeButton();
}

void Window::changeThemeWindow() {
	if (theme.getThemeState() == Theme::Dark) {
		theme.setThemeState(Theme::Light);
	}
	else {
		theme.setThemeState(Theme::Dark);
	}
	setThemeWindow();
}

void Window::slotUpdateThemeWindow() {
	changeThemeWindow();
}

void Window::setThemeButton() {
	QPixmap pixmap;
	if (theme.getThemeState() == Theme::Dark) {
		pixmap.load("img/lightSun.jpg");
	}
	else {
		pixmap.load("img/darkSun.jpg");
	}
	QIcon icon(pixmap);
	ui->themeButton->setIcon(icon);
}