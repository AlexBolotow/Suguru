#include "ZoneSuguru.h"

ZoneSuguru::ZoneSuguru(std::ifstream& fileIn, size_t numberZone) {
    fileIn >> size;
    std::string buffer;
    for (size_t i = 0; i < size; i++) {
        fileIn >> buffer;
        coordinates.push_back(PointZone(buffer, numberZone));
    }
}

size_t ZoneSuguru::getSize() {
    return size;
}

PointZone ZoneSuguru::getCoordinate(size_t index) {

    return coordinates[index];
}

