/* Copyright [2024] ysengoku */

#include "../includes/ObstructionSimulator.hpp"

#include <iostream>
#include <set>
#include <string>
#include <utility>
#include <vector>

#include "../includes/Guard.hpp"
#include "../includes/utils.hpp"

#define CYAN "\033[36m"
#define MAGENTA "\033[35m"
#define RESET "\033[0m"

ObstructionSimulator::ObstructionSimulator(
    const Guard &guard, const std::vector<std::string> &initialMap)
    : Guard(guard), _initialMap(initialMap) {
  for (int y = 0; y < _mapHeight; ++y) {
    for (int x = 0; x < _mapWidth; ++x) {
      if (_map[y][x] == 'X' &&
          !(_initialPosition.x == x && _initialPosition.y == y))
        _candidates.push_back({x, y});
    }
  }
  _position = _initialPosition;
  _direction = _initialDirection;
  // DEBUG data check
  //   printVector(_candidates);
  //   std::cout << "candidate count: " << _candidates.size() << std::endl;
  //   std::cout << "initial map" << std::endl;
  //   printVector(_initialMap);
  //   std::cout << "map size: " << _mapWidth << " " << _mapHeight << std::endl;
  //   std::cout << "initial position: " << _position.x << " "
  // 			<< _position.y << std::endl;
  //   std::cout << "initial direction: " << _direction.x << " "
  //             << _direction.y << std::endl;
}

void ObstructionSimulator::simulate(void) {
  std::vector<Vector2D>::iterator itEnd = _candidates.end();
  int i = 1;
  for (std::vector<Vector2D>::iterator it = _candidates.begin(); it != itEnd;
       ++it) {
    std::cout << "=== Checking candidate " << i << " of "
              << _candidates.size() << " ===" << std::endl;
    _checkCandidate(*it);
    ++i;
  }
  _printObstructionPositionsCount();
}

void ObstructionSimulator::_checkCandidate(const Vector2D &candidate) {
  std::vector<std::string> testMap = _initialMap;
  testMap[candidate.y][candidate.x] = '#';
  _position = _initialPosition;
  _direction = _initialDirection;
  std::vector<std::pair<Vector2D, Vector2D> >
      visitedPlaces;  // pair of position and direction

  //   std::cout << "Before checking candidate: " << candidate << std::endl;
  //   std::cout << CYAN;
  //   printVector(testMap);
  //   std::cout << RESET << std::endl;

  //   while (_position.y < _mapHeight && _position.y >= 0 &&
  //          _position.x < _mapWidth && _position.x >= 0) {
  while (true) {
    std::pair<Vector2D, Vector2D> currentPlace =
        std::make_pair(_position, _direction);
    if (std::find(visitedPlaces.begin(), visitedPlaces.end(), currentPlace) !=
        visitedPlaces.end()) {
      _obstructions.push_back(candidate);
      std::cout << MAGENTA "Success!" RESET << std::endl;
      return;
    }
    visitedPlaces.push_back(currentPlace);
    Vector2D nextPos = _position;
    nextPos.x += _direction.x;
    nextPos.y += _direction.y;
    if (nextPos.y >= _mapHeight || nextPos.y < 0 || nextPos.x >= _mapWidth ||
        nextPos.x < 0) {
	  std::cout << "Out of bounds! " << nextPos.y << ", " << nextPos.x << std::endl;
      return;
    } else if (_initialMap[nextPos.y][nextPos.x] == '#') {
	  _turnRight();
	} else {
	  _move();
	}
  }
}

void ObstructionSimulator::_move(void) {
  _position.x += _direction.x;
  _position.y += _direction.y;
}

void ObstructionSimulator::_printObstructionPositionsCount(void) const {
  std::cout << "Obstruction positions count: " << _obstructions.size()
            << std::endl;
}
