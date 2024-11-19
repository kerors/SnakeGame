#pragma once
#ifndef UTILS_H
#define UTILS_H

#include <cstdlib>
#include <ctime>

inline int randInt(int min, int max) {
    static bool initialized = false;
    if (!initialized) {
        srand(static_cast<unsigned>(time(nullptr)));
        initialized = true;
    }
    return rand() % (max - min + 1) + min;
}

#endif
