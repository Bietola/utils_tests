#pragma once

#include <string>

auto greet(const std::string& thing) {
    return std::string("hello ") + thing + std::string("!!");
}

