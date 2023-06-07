#include "BoardWidget.h"

void BoardWidget::initTableWidget(size_t rowCount, size_t columnCount) {
	this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	this->setGeometry(150, 50, 500, 500);
	this->setRowCount(rowCount);
	this->setColumnCount(columnCount);
	this->verticalHeader()->hide();
	this->horizontalHeader()->hide();
	double cellSize = 500. / rowCount;
	for (size_t i = 0; i < rowCount; i++) {
		this->setColumnWidth(i, cellSize);
		this->setRowHeight(i, cellSize);
	}
}

void BoardWidget::setZoneCellsToTableWidget(BoardSuguru& boardSuguru, ZoneSuguru zoneSuguru) {
	PointZone pointZone;
	QTableWidgetItem* tableWidgetItem;
	for (size_t i = 0; i < zoneSuguru.getSize(); i++) {
		pointZone = zoneSuguru.getCoordinate(i);
		tableWidgetItem = new QTableWidgetItem();
		if (!boardSuguru.isEmptyBoardCell(pointZone)) {
			tableWidgetItem->setText(QString::number(boardSuguru.getBoardValue(pointZone)));
			tableWidgetItem->setFlags(Qt::ItemIsDragEnabled | Qt::ItemIsUserCheckable | Qt::ItemIsSelectable);
			tableWidgetItem->setTextColor(Qt::red);
		}
		tableWidgetItem->setTextAlignment(Qt::AlignVCenter | Qt::AlignHCenter);
		this->setItem(pointZone.x(), pointZone.y(), tableWidgetItem);
		tableWidgetItem->QTableWidgetItem::setBackgroundColor(colors[pointZone.getNumberZone()]);
	}
}

void BoardWidget::setBoardWidget(BoardSuguru& boardSuguru) {
	initTableWidget(boardSuguru.getSizeBoard(), boardSuguru.getSizeBoard());
	for (size_t i = 0; i < boardSuguru.getSizeZones(); i++) {
		setZoneCellsToTableWidget(boardSuguru, boardSuguru.getZoneSuguru(i));
	}
}

void BoardWidget::getBoardSuguru(BoardSuguru& boardSuguru) {
	QString cellValue;
	QTableWidgetItem* tableWidgetItem;
	for (size_t i = 0; i < boardSuguru.getSizeBoard(); i++) {
		for (size_t j = 0; j < boardSuguru.getSizeBoard(); j++) {
			tableWidgetItem = this->item(i, j);
			if (tableWidgetItem != NULL) {
				cellValue = tableWidgetItem->text();
				boardSuguru.setBoardValue(cellValue.toInt(), i, j);
			}
			else {
				boardSuguru.setBoardValue(0, i, j);
			}
		}
	}
}