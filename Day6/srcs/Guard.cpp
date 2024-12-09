/* Copyright [2024] ysengoku */

#include "../includes/Guard.hpp"

#include <iostream>
#include <string>
#include <vector>

#include "../includes/utils.hpp"

Guard::Guard(const std::vector<std::string> &map) : _map(map) { _initialize(); }

void Guard::patrol(void) {
  while (_position.y < _mapHeight && _position.y >= 0 &&
         _position.x < _mapWidth && _position.x >= 0) {
    // std::cout << "Current position: (" << _position.x << ", " << _position.y
    // << ", " << _map[_position.y][_position.x] << ")"
    // 		  << " Direction: (" << _direction.x << ", " << _direction.y
    // 		  << ")" << std::endl;
    Vector2D nextPos = {_position.x + _direction.x, _position.y + _direction.y};
    if (nextPos.y >= _mapHeight || nextPos.y < 0 || nextPos.x >= _mapWidth ||
        nextPos.x < 0) {
      break;
    }
    if (_map[_position.y + _direction.y][_position.x + _direction.x] == '#') {
      _turnRight();
    } else {
      _move();
    }
  }
  _printVisitedPositionsCount();
}

const std::vector<std::string> Guard::getMap(void) const { return (_map); }

void Guard::_initialize(void) {
  _mapWidth = _map[0].size();
  _mapHeight = _map.size();
  for (int y = 0; y < _mapHeight; ++y) {
    for (int x = 0; x < _mapWidth; ++x) {
      if (_map[y][x] != '.' && _map[y][x] != '#') {
        _position.x = x;
        _position.y = y;
        _initialPosition = _position;
        if (_map[y][x] == '^')
          _direction = {0, -1};
        else if (_map[y][x] == 'v')
          _direction = {0, 1};
        else if (_map[y][x] == '<')
          _direction = {-1, 0};
        else if (_map[y][x] == '>')
          _direction = {1, 0};
        _initialDirection = _direction;
        _map[_position.y][_position.x] = 'X';
        // std::cout << "Initial position: (" << _position.x << ", " <<
        // _position.y << ")"
        //           << " Direction: (" << _direction.x << ", " << _direction.y
        //           << ")" << std::endl;
        return;
      }
    }
  }
}

void Guard::_move(void) {
  _position.x += _direction.x;
  _position.y += _direction.y;
  _map[_position.y][_position.x] = 'X';
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
  for (std::vector<std::string>::const_iterator rowIt = _map.begin();
       rowIt != rowItEnd; ++rowIt) {
    std::string::const_iterator colItEnd = rowIt->end();
    for (std::string::const_iterator colIt = rowIt->begin(); colIt != colItEnd;
         ++colIt) {
      if (*colIt == 'X') ++count;
    }
  }
  std::cout << "Visited positions: " << count << std::endl;
}
