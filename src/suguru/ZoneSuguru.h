#pragma once
#include <vector>
#include <fstream>
#include "PointZone.h"

class ZoneSuguru {
public:
	ZoneSuguru(size_t size) : size(size) {};
	ZoneSuguru(std::ifstream& fileIn, size_t numberZone);
	size_t getSize();
	PointZone getCoordinate(size_t index);

private:
	std::vector<PointZone> coordinates;
	size_t size;
};

