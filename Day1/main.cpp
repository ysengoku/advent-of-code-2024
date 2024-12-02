#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

static void totalDistance(std::vector<int> numbers_left, std::vector<int> numbers_right);
static void similarityScore(std::vector<int> numbers_left, std::vector<int> numbers_right);

int main(void) {
  std::ifstream file("input.txt");
  std::vector<int> numbers_left;
  std::vector<int> numbers_right;
  std::string line;
  while (std::getline(file, line)) {
   std::stringstream ss(line);
   std::string left, right;
   ss >> left >> right;
   numbers_left.push_back(std::stoi(left));
   numbers_right.push_back(std::stoi(right));
  }

  totalDistance(numbers_left, numbers_right);
  similarityScore(numbers_left, numbers_right);
  return (0);
}

void totalDistance(std::vector<int> numbers_left, std::vector<int> numbers_right) {
  std::sort(numbers_left.begin(), numbers_left.end());
  std::sort(numbers_right.begin(), numbers_right.end());

  int result = 0;
  size_t size = numbers_left.size();
  for (size_t i = 0; i < size; ++i) {
	result += abs(numbers_left[i] - numbers_right[i]);
  }
  std::cout << "total distance: " << result << std::endl;
}

void similarityScore(std::vector<int> numbers_left, std::vector<int> numbers_right) {
  int result = 0;
  size_t size = numbers_left.size();
  for (size_t i = 0; i < size; ++i) {
	int count = 0;
	for (size_t j = 0; j < size; ++j) {
	  if (numbers_left[i] == numbers_right[j])
		++count;
    }
	result += numbers_left[i] * count;
  }
  std::cout << "similarity score: " << result << std::endl;
}
