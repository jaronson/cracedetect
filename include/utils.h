#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <glob.h>

namespace utils {
  std::vector<std::string> glob(const std::string& pattern);
  std::vector<std::string> readFile(const std::string& path);
}

#endif
