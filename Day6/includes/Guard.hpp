/* Copyright [2024] ysengoku */

#ifndef DAY6_INCLUDES_GUARD_HPP_
#define DAY6_INCLUDES_GUARD_HPP_

#include <iostream>
#include <string>
#include <vector>

struct Vector2D {
  int x;
  int y;

  bool operator==(const Vector2D &other) const {
    return (x == other.x && y == other.y);
  }

// Dummy definition
  bool operator>(const Vector2D &other) const {
    return (y > other.y || (y == other.y && x > other.x));
  }
  bool operator<(const Vector2D &other) const {
    return (y < other.y || (y == other.y && x < other.x));
  }
};

class Guard {
 public:
  Guard(const std::vector<std::string> &map);
  virtual ~Guard(void) {}

  void patrol(void);
  const std::vector<std::string> getMap(void) const;


 protected:
  std::vector<std::string> _map;
  int _mapWidth;
  int _mapHeight;
  Vector2D _initialPosition;
  Vector2D _initialDirection;
  Vector2D _position;
  Vector2D _direction;
  int _visitedPositionsCount;

  void _initialize(void);
  virtual void _move(void);
  void _turnRight(void);
  void _printVisitedPositionsCount(void) const;
};

#endif // DAY6_INCLUDES_GUARD_HPP_
