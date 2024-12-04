/* Copyright [2024] ysengoku */

#ifndef DAY4_INCLUDES_OCCURRENCESCOUNTER_HPP_
#define DAY4_INCLUDES_OCCURRENCESCOUNTER_HPP_

#include <string>
#include <vector>

#define stringVector std::vector<std::string>

class OccurrencesCounter {
 public:
  OccurrencesCounter(stringVector const &data, std::string const &word);
  int getCount(void) const;

 private:
  stringVector _data;
  std::string _word;
  int _wordLen;
  int _count;

  void _countOccurrences(void);
  int _countHorizontals(stringVector::iterator rowIt, int colomnIndex);
  int _countVerticals(stringVector::iterator rowIt, int colomnIndex);
  int _countDiagonals(stringVector::iterator rowIt, int colomnIndex);
};

#endif  // DAY4_INCLUDES_OCCURRENCESCOUNTER_HPP_
