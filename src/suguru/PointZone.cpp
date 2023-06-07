#include "PointZone.h"

PointZone::PointZone(std::string point, size_t numberZone) : QPoint() {
	setY((int)(point[0] - 'A'));
	setX(atoi(&point[1]) - 1);
	this->numberZone = numberZone;
}

void PointZone::setNumberZone(size_t numberZone) {
	this->numberZone = numberZone;
}

size_t PointZone::getNumberZone() {
	return numberZone;
}
