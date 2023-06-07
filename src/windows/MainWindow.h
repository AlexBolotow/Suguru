#pragma once
#include "RulesWindow.h"
#include "LevelsWindow.h"
#include "ui_MainWindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindowClass; };
QT_END_NAMESPACE

class MainWindow : public Window {
	Q_OBJECT

public:
	void setBackgroundColor() override;
	MainWindow(Window* parent = nullptr);
	~MainWindow();

private slots:
	void slotShowRulesWindow();
	void slotShowLevelsWindow();
	void slotShowMainWindow();

private:
	Ui::MainWindowClass* ui;
	RulesWindow* rulesWindow;
	LevelsWindow* levelsWindow;
};
