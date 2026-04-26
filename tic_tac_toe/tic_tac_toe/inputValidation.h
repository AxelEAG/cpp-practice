#ifndef INPUT_VALIDATION_H
#define INPUT_VALIDATION_H
#include <string_view>

int getValidInput(std::string_view type, int max, int min = 1);

#endif