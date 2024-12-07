/* Copyright [2024] ysengoku */

#include "../includes/XmasCounter.hpp"

#include <iostream>
#include <string>
#include <vector>

XmasCounter::XmasCounter(const std::vector<std::string> &data)
    : _data(&data), _count(0) {
  _countXmas();
}

int XmasCounter::getCount(void) const { return (_count); }

void XmasCounter::_countXmas(void) {
  size_t rowLoopEnd = _data->size() - 2;
  for (size_t indexRow = 0; indexRow < rowLoopEnd; ++indexRow) {
    size_t columnLoopEnd = (*_data)[indexRow].size() - 2;
    for (size_t indexColumn = 0; indexColumn < columnLoopEnd; ++indexColumn) {
      if (_checkDiagonalLeftToRight(indexColumn, indexRow) &&
          _checkDiagonalRightToLeft(indexColumn + 2, indexRow))
        _count++;
    }
  }
}

bool XmasCounter::_checkDiagonalLeftToRight(size_t indexColumn,
                                            size_t indexRow) {
  std::cout << "LeftToRight - IndexColumn: " << indexColumn
            << " | IndexRow: " << indexRow;
  std::string row1 = (*_data)[indexRow];
  std::string row2 = (*_data)[indexRow + 1];
  std::string row3 = (*_data)[indexRow + 2];
  std::cout << CYAN << row1[indexColumn] << row2[indexColumn + 1]
            << row3[indexColumn + 2] << RESET << std::endl;
  if (row1[indexColumn] == 'M' && row2[indexColumn + 1] == 'A' &&
      row3[indexColumn + 2] == 'S')
    return (true);
  if (row1[indexColumn] == 'S' && row2[indexColumn + 1] == 'A' &&
      row3[indexColumn + 2] == 'M')
    return (true);
  return (false);
}

bool XmasCounter::_checkDiagonalRightToLeft(size_t indexColumn,
                                            size_t indexRow) {
  std::cout << "RightToLeft - IndexColumn: " << indexColumn
            << " | IndexRow: " << indexRow;
  std::string row1 = (*_data)[indexRow];
  std::string row2 = (*_data)[indexRow + 1];
  std::string row3 = (*_data)[indexRow + 2];
  std::cout << CYAN << row1[indexColumn] << row2[indexColumn - 1]
            << row3[indexColumn - 2] << RESET << std::endl;
  if (row1[indexColumn] == 'M' && row2[indexColumn - 1] == 'A' &&
      row3[indexColumn - 2] == 'S')
    return (true);
  if (row1[indexColumn] == 'S' && row2[indexColumn - 1] == 'A' &&
      row3[indexColumn - 2] == 'M')
    return (true);
  return (false);
}
