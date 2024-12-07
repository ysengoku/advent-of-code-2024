/* Copyright [2024] ysengoku */

#include "../includes/Guard.hpp"
#include "../includes/utils.hpp"

#include <iostream>
#include <string>
#include <vector>

Guard::Guard(const std::vector<std::string> &map) : _map(map) { _initialize(); }

void Guard::patrol(void) {
  while (_y < _mapHeight && _y >= 0 && _x < _mapWidth && _x >= 0) {
	// std::cout << "Current position: (" << _x << ", " << _y << ", " << _map[_y][_x] << ")"
	// 		  << " Direction: (" << _direction.x << ", " << _direction.y
	// 		  << ")" << std::endl;
	if (_map[_y + _direction.y][_x + _direction.x] == '#') {
	  _turnRight();
	} else {
	  _move();
	}
  }
  _printVisitedPositionsCount();
}

void Guard::_initialize(void) {
  _mapWidth = _map[0].size();
  _mapHeight = _map.size();
  for (int y = 0; y < _mapHeight; ++y) {
    for (int x = 0; x < _mapWidth; ++x) {
      if (_map[y][x] != '.' && _map[y][x] != '#') {
        _x = x;
        _y = y;
        if (_map[y][x] == '^')
          _direction = {0, -1};
        else if (_map[y][x] == 'v')
          _direction = {0, 1};
        else if (_map[y][x] == '<')
          _direction = {-1, 0};
        else if (_map[y][x] == '>')
          _direction = {1, 0};
		_map[_y][_x] = 'X';
        // std::cout << "Initial position: (" << _x << ", " << _y << ")"
        //           << " Direction: (" << _direction.x << ", " << _direction.y
        //           << ")" << std::endl;
        return;
      }
    }
  }
}

void Guard::_move(void) {
  _map[_y][_x] = 'X';
  _x += _direction.x;
  _y += _direction.y;
}

void Guard::_turnRight(void) {
  if (_direction.x == 0 && _direction.y == -1)
    _direction = {1, 0};
  else if (_direction.x == 1 && _direction.y == 0)
	_direction = {0, 1};
  else if (_direction.x == 0 && _direction.y == 1)
	_direction = {-1, 0};
  else if (_direction.x == -1 && _direction.y == 0)
	_direction = {0, -1};
}

void Guard::_printVisitedPositionsCount(void) const {
//   printVector(_map);
  int count = 0;
  std::vector<std::string>::const_iterator rowItEnd = _map.end();
  for (std::vector<std::string>::const_iterator rowIt = _map.begin(); rowIt != rowItEnd; ++rowIt) {
	std::string::const_iterator colItEnd = rowIt->end();
	for (std::string::const_iterator colIt = rowIt->begin(); colIt != colItEnd; ++colIt) {
	  if (*colIt == 'X')
		++count;
	}
  }
  std::cout << "Visited positions: " << count << std::endl;
}
