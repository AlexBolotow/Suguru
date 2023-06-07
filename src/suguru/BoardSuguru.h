#pragma once
#include "ZoneSuguru.h"
#include <iostream>

class BoardSuguru {
public:
	BoardSuguru() {};
	BoardSuguru(std::string pathLevel);
	size_t getSizeBoard();
	size_t getSizeZones();
	ZoneSuguru getZoneSuguru(size_t index);
	int getBoardValue(size_t rowIndex, size_t columnIndex);
	int getBoardValue(PointZone point);
	void setBoardValue(int value, size_t rowIndex, size_t columnIndex);
	bool isEmptyBoardCell(PointZone point);
	bool findEmptyBoardCell(PointZone* point);
	bool isBoardFilled();
	bool isSoluton();
	void outputOnlyBoard();
	void solveBoard();

private:
	bool isValueEqualToUpperNeighbor(PointZone point, int value);
	bool isValueEqualToLowerNeighbor(PointZone point, int value);
	bool isValueEqualToRightNeighbor(PointZone point, int value);
	bool isValueEqualToLeftNeighbor(PointZone point, int value);
	bool isValueEqualToNeighbor(PointZone point, int value);
	bool isValueValidInZone(PointZone point, int value);
	bool isValidBoard(PointZone point, int value);

	std::vector<std::vector<int>> board;
	size_t sizeBoard;
	std::vector<ZoneSuguru> zones;
	size_t sizeZones;
};

