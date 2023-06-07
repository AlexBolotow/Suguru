#pragma once
#include "Window.h"
#include "ui_RulesWindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class RulesWindowClass; };
QT_END_NAMESPACE

class RulesWindow : public Window
{
	Q_OBJECT

public:
	RulesWindow(Window *parent = nullptr);
	~RulesWindow();

signals:
	void signalShowMainWindow();

private slots:
	void slotShowMainWindow();

private:
	Ui::RulesWindowClass *ui;
};
