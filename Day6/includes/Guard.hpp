/* Copyright [2024] ysengoku */

#ifndef DAY6_INCLUDES_GUARD_HPP_
#define DAY6_INCLUDES_GUARD_HPP_

#include <string>
#include <vector>

class Guard {
 public:
  Guard(const std::vector<std::string> &map);

  void patrol(void);

 private:
  struct Direction {
    int x;
    int y;
  };

  std::vector<std::string> _map;
  int _mapWidth;
  int _mapHeight;
  int _x;
  int _y;
  Direction _direction;

  void _initialize(void);
  void _move(void);
  void _turnRight(void);
  void _printVisitedPositionsCount(void) const;
};

#endif // DAY6_INCLUDES_GUARD_HPP_
