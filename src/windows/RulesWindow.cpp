#include "RulesWindow.h"
extern Theme theme;
RulesWindow::RulesWindow(Window *parent) : Window(parent), ui(new Ui::RulesWindowClass())
{
	ui->setupUi(this);
}

RulesWindow::~RulesWindow()
{
	delete ui;
}

void RulesWindow::slotShowMainWindow() {
	this->close();
	emit signalShowMainWindow();
}
