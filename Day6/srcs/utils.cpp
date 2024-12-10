#include <iostream>
#include <string>
#include <vector>

#include "../includes/utils.hpp"

std::ostream &operator<<(std::ostream &os, const Vector2D &vec2d) {
    os << "x: " << vec2d.x << ", y: " << vec2d.y;
    return os;
}
