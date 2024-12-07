/* Copyright [2024] ysengoku */

#include "../includes/OccurrencesCounter.hpp"

#include <iostream>
#include <string>

OccurrencesCounter::OccurrencesCounter(const stringVector &data,
                                       const std::string &word)
    : _data(data), _word(word), _wordLen(word.length()), _count(0) {
  _countOccurrences();
  //   std::cout << "Colomn size: " << _data.size() << std::endl;
  //   std::cout << "Row size: " << _data.at(0).size() << std::endl;
  //   std::cout << "Word length: " << _wordLen << std::endl;
}

int OccurrencesCounter::getCount(void) const { return (_count); }

void OccurrencesCounter::_countOccurrences(void) {
  stringVector::iterator rowItEnd = _data.end();
  for (stringVector::iterator rowIt = _data.begin(); rowIt != rowItEnd;
       ++rowIt) {
    // std::cout << "----- Row " << rowIt - _data.begin() << " ----- "
    // <<std::endl;
    int rowSize = rowIt->size();
    for (int pos = 0; pos < rowSize; ++pos) {
      // std::cout << "--- Position: " << pos << " ---" << std::endl;
      _count += _countHorizontals(rowIt, pos);
      _count += _countVerticals(rowIt, pos);
      _count += _countDiagonals(rowIt, pos);
    }
  }
}

int OccurrencesCounter::_countHorizontals(stringVector::iterator rowIt,
                                          int colomnIndex) {
  int count = 0;
  int rowSize = rowIt->size();

  if (colomnIndex + _wordLen <= rowSize) {
    // std::cout << "Target: " << rowIt->substr(colomnIndex, _wordLen) <<
    // std::endl;
    if (rowIt->substr(colomnIndex, _wordLen) == _word) ++count;
  }
  if (colomnIndex - _wordLen >= -1) {
    std::string target;
    for (int i = 0; i < _wordLen; ++i)
      target.push_back((*rowIt)[colomnIndex - i]);
    // std::cout << "Target: " << target << std::endl;
    if (target == _word) ++count;
  }
  // std::cout << "Horizontal count: " << count << std::endl;
  return (count);
}

int OccurrencesCounter::_countVerticals(stringVector::iterator rowIt,
                                        int colomnIndex) {
  int count = 0;
  int columnSize = _data.size();
  int rowIndex = std::distance(_data.begin(), rowIt);

  if (rowIndex + _wordLen <= columnSize) {
    std::string target;
    for (int i = 0; i < _wordLen; ++i) {
      target.push_back(_data[rowIndex + i][colomnIndex]);
    }

    if (target == _word) ++count;
  }
  if (rowIndex - _wordLen >= -1) {
    std::string target;
    for (int i = 0; i < _wordLen; ++i) {
      target.push_back(_data[rowIndex - i][colomnIndex]);
    }
    if (target == _word) ++count;
  }
  // std::cout << "Vertical count: " << count << std::endl;
  return (count);
}

int OccurrencesCounter::_countDiagonals(stringVector::iterator rowIt,
                                        int colomnIndex) {
  int count = 0;
  int rowSize = rowIt->size();
  int columnSize = _data.size();
  int rowIndex = std::distance(_data.begin(), rowIt);

  // From right-top to left-bottom
  if (rowIndex + _wordLen <= columnSize && colomnIndex + _wordLen <= rowSize) {
    std::string target;
    for (int i = 0; i < _wordLen; ++i)
      target.push_back(_data[rowIndex + i][colomnIndex + i]);
    if (target == _word) ++count;
  }
  // From left-top to right-bottom
  if (rowIndex - _wordLen >= -1 && colomnIndex - _wordLen >= -1) {
    std::string target;
    for (int i = 0; i < _wordLen; ++i)
      target.push_back(_data[rowIndex - i][colomnIndex - i]);
    if (target == _word) ++count;
  }
  // From right-bottom to left-top
  if (rowIndex - _wordLen >= -1 && colomnIndex + _wordLen <= rowSize) {
    std::string target;
    for (int i = 0; i < _wordLen; ++i)
      target.push_back(_data[rowIndex - i][colomnIndex + i]);
    if (target == _word) ++count;
  }
  // From left-bottom to right-top
  if (rowIndex + _wordLen <= columnSize && colomnIndex - _wordLen >= -1) {
    std::string target;
    for (int i = 0; i < _wordLen; ++i)
      target.push_back(_data[rowIndex + i][colomnIndex - i]);
    if (target == _word) ++count;
  }
  // std::cout << "Diagonal count: " << count << std::endl;
  return (count);
}
