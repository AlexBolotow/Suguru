#pragma once
#include "GameWindow.h"
#include "ui_LevelsWindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class LevelsWindowClass; };
QT_END_NAMESPACE

class LevelsWindow : public Window
{
	Q_OBJECT

public:
	LevelsWindow(Window *parent = nullptr);
	~LevelsWindow();

signals:
	void signalShowMainWindow();

private slots:
	void slotShowMainWindow();
	void slotShowLevelsWindow();
	void slotShowGameWindowLevel1();
	void slotShowGameWindowLevel2();
	void slotShowGameWindowLevel3();
	void slotShowGameWindowLevel4();
	void slotShowGameWindowLevel5();
	void slotShowGameWindowLevel6();

private:
	Ui::LevelsWindowClass *ui;
	GameWindow* gameWindow;
};
