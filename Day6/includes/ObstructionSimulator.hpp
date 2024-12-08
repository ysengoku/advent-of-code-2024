/* Copyright [2024] ysengoku */

#ifndef DAY6_INCLUDES_OBSTRUCTIONSIMULATOR_HPP_
#define DAY6_INCLUDES_OBSTRUCTIONSIMULATOR_HPP_

#include <string>
#include <vector>

#include "../includes/Guard.hpp"

struct Vector2D;

class ObstructionSimulator : public Guard {
 public:
  ObstructionSimulator(const Guard &guard,
                       const std::vector<std::string> &initialMap);
  virtual ~ObstructionSimulator(void) {}

  void simulate(void);

 private:
  const std::vector<std::string> _initialMap;
  std::vector<Vector2D> _candidates;
  std::vector<Vector2D> _obstructions;

  void _checkCandidate(const Vector2D &candidate);
  void _move(void) override;
  void _printObstructionPositionsCount(void) const;
};

#endif  // DAY6_INCLUDES_OBSTRUCTIONSIMULATOR_HPP_
