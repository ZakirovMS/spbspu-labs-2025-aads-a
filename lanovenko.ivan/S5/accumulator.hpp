#ifndef ACCUMULATOR_HPP
#define ACCUMULATOR_HPP

#include <string>

namespace lanovenko
{
  struct KeyValueAccumulator
  {
    KeyValueAccumulator();
    int keySum;
    std::string values;
    void operator()(const std::pair< int, std::string > & keyValue);
  };
}

#endif
