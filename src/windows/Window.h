#pragma once
#include "ui_Window.h"
#include "Theme.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Form; };
QT_END_NAMESPACE

class Window : public QWidget
{
	Q_OBJECT

public:
	Window(QWidget* parent = nullptr);
	~Window();
	virtual void setBackgroundColor();
	virtual void setThemeWindow();
	virtual void changeThemeWindow();
	void setThemeButton();

private slots:
	void slotUpdateThemeWindow();

private:
	Ui::Form *ui;
};