#include "BoardSuguru.h"

BoardSuguru::BoardSuguru(std::string pathLevel) {
    std::ifstream fileIn;
    fileIn.open(pathLevel);
    std::string buffer;
    fileIn >> sizeBoard;
    fileIn >> sizeZones;

    //Инициализация zones
    for (size_t i = 0; i < sizeZones; i++) {
        zones.push_back(ZoneSuguru(fileIn, i));
    }

    //Инициализация board
    board.resize(sizeBoard);
    for (size_t i = 0; i < sizeBoard; i++) {
        board[i].resize(sizeBoard);
        for (size_t j = 0; j < sizeBoard; j++) {
            fileIn >> board[i][j];
        }
    }
}

size_t BoardSuguru::getSizeBoard() {
    return sizeBoard;
}

size_t BoardSuguru::getSizeZones() {
    return sizeZones;
}

ZoneSuguru BoardSuguru::getZoneSuguru(size_t index) {
    return zones[index];
}

int BoardSuguru::getBoardValue(size_t rowIndex, size_t columnIndex) {
    return board[rowIndex][columnIndex];
}

int BoardSuguru::getBoardValue(PointZone point) {
    return board[point.x()][point.y()];
}
void BoardSuguru::setBoardValue(int value, size_t rowIndex, size_t columnIndex) {
    board[rowIndex][columnIndex] = value;
}

bool BoardSuguru::isEmptyBoardCell(PointZone point) {
    if (board[point.x()][point.y()] == 0) {
        return true;
    }
    return false;
}

bool BoardSuguru::findEmptyBoardCell(PointZone* point) {
    for (size_t i = 0; i < sizeZones; i++) {
        for (size_t j = 0; j < zones[i].getSize(); j++) {
            if (isEmptyBoardCell(zones[i].getCoordinate(j))) {
                *point = zones[i].getCoordinate(j);
                return true;
            }
        }
    }
    return false;
}

bool BoardSuguru::isValueEqualToUpperNeighbor(PointZone point, int value) {
    if (point.x() > 0) {
        if (value == board[point.x() - 1][point.y()]) {
            return true;
        }

        if ((point.y() > 0) && (value == board[point.x() - 1][point.y() - 1])) {
            return true;
        }

        if ((point.y() < sizeBoard - 1) && (value == board[point.x() - 1][point.y() + 1])) {
            return true;
        }
    }
    return false;
}

bool BoardSuguru::isValueEqualToLowerNeighbor(PointZone point, int value) {
    if (point.x() < sizeBoard - 1) {
        if (value == board[point.x() + 1][point.y()]) {
            return true;
        }

        if ((point.y() > 0) && (value == board[point.x() + 1][point.y() - 1])) {
            return true;
        }

        if ((point.y() < sizeBoard - 1) && (value == board[point.x() + 1][point.y() + 1])) {
            return true;
        }
    }
    return false;
}

bool BoardSuguru::isValueEqualToRightNeighbor(PointZone point, int value) {
    if ((point.y() > 0) && (value == board[point.x()][point.y() - 1])) {
        return true;
    }
    return false;
}

bool BoardSuguru::isValueEqualToLeftNeighbor(PointZone point, int value) {
    if ((point.y() < sizeBoard - 1) && (value == board[point.x()][point.y() + 1])) {
        return true;
    }
    return false;
}

bool BoardSuguru::isValueEqualToNeighbor(PointZone point, int value) {
    return isValueEqualToUpperNeighbor(point, value)
           || isValueEqualToLowerNeighbor(point, value)
           || isValueEqualToRightNeighbor(point, value)
           || isValueEqualToLeftNeighbor(point, value);
}

bool BoardSuguru::isValueValidInZone(PointZone point, int value) {
    if (value > 0 && value <= zones[point.getNumberZone()].getSize()) {
        for (size_t i = 0; i < zones[point.getNumberZone()].getSize(); i++) {
            if ((point != zones[point.getNumberZone()].getCoordinate(i)) && (getBoardValue(zones[point.getNumberZone()].getCoordinate(i)) == value)) {
                return false;
            }
        }
    }
    else {
        return false;
    }
    return true;
}

bool BoardSuguru::isValidBoard(PointZone point, int value) {
    if (!isValueValidInZone(point, value)) {
        return false;
    }

    if (isValueEqualToNeighbor(point, value)) {
        return false;
    }
    return true;
}

bool BoardSuguru::isBoardFilled() {
    for (size_t i = 0; i < sizeBoard; i++) {
        for (size_t j = 0; j < sizeBoard; j++) {
            if (board[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
}

bool BoardSuguru::isSoluton() {
    for (size_t i = 0; i < sizeZones; i++) {
        for (size_t j = 0; j < zones[i].getSize(); j++) {
            PointZone point = zones[i].getCoordinate(j);
            if (!isValidBoard(point, getBoardValue(point))) {
                return false;
            }
        }
    }
    return true;
}

void BoardSuguru::outputOnlyBoard() {
    for (size_t i = 0; i < board.size(); i++) {
        for (size_t j = 0; j < board.size(); j++) {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void BoardSuguru::solveBoard() {
    outputOnlyBoard();
    PointZone point;
    if (findEmptyBoardCell(&point)) {
        for (size_t i = 1; i < zones[point.getNumberZone()].getSize() + 1; i++) {
            if (isValidBoard(point, i)) {
                board[point.x()][point.y()] = i;
                outputOnlyBoard();
                solveBoard();
                if (!isBoardFilled()) {
                    board[point.x()][point.y()] = 0;
                }
            }
        }
    }
}

