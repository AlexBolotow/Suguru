#pragma once
#include <QPoint>
#include <string>

class PointZone : public QPoint {
public:
	PointZone() : QPoint() {};
	PointZone(int x, int y, size_t numberZone) : QPoint(x, y), numberZone(numberZone) {};
	PointZone(std::string point, size_t numberZone);
	void setNumberZone(size_t numberZone);
	size_t getNumberZone();

private:
	size_t numberZone;
};

