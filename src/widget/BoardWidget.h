#pragma once
#include <QWidget>
#include <QTableWidget>
#include <QHeaderView>
#include "BoardSuguru.h"

QT_BEGIN_NAMESPACE
namespace Ui { class BoardWidgetClass; };
QT_END_NAMESPACE

class BoardWidget : public QTableWidget {
	Q_OBJECT

public:
	BoardWidget(QWidget* parent = nullptr) {};
	void initTableWidget(size_t rowCount, size_t columnCount);
	void setZoneCellsToTableWidget(BoardSuguru& boardSuguru, ZoneSuguru zoneSuguru);
	void setBoardWidget(BoardSuguru& boardSuguru);
	void getBoardSuguru(BoardSuguru& boardSuguru);

private:
	std::vector<QColor> colors = { Qt::darkYellow, Qt::darkGreen, Qt::darkCyan, Qt::darkMagenta, Qt::blue,
	Qt::gray, Qt::green, Qt::darkRed,  Qt::cyan, Qt::yellow, Qt::darkBlue, Qt::magenta };
};