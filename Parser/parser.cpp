#include "parser.h"
#include <filesystem>
#include <fstream>
#include <iostream>

json getJsonFromFile(string fileName) {
  ifstream ifs;
  filesystem::current_path("../Parser/Data");
  ifs.open(fileName, ifstream::in);
  json result = json::parse(ifs);
  return result;
}
