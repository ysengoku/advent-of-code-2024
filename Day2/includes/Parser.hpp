#ifndef INCLUDES_PARSER_HPP_
#define INCLUDES_PARSER_HPP_

#include <vector>
#include <string>

class Parser {
  public:
    Parser(const std::string &filename);
    std::vector< std::vector<int> > getData() const;

  private:
    std::vector< std::vector<int> > _data;

	void _parseData(std::ifstream &file);
};

#endif // INCLUDES_PARSER_HPP_
