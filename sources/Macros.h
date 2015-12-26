#ifndef DARKNESS_MACROS_H
#define DARKNESS_MACROS_H

#include <iostream>

#define ERRORC(__MESSAGE__, __CLEAN__) std::cerr << __MESSAGE__ << std::endl; __CLEAN__ exit(1);
#define ERROR(__MESSAGE__) std::cerr << __MESSAGE__ << std::endl; exit(1);

#endif //DARKNESS_MACROS_H
