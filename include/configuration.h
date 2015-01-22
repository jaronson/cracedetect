#ifndef CONFIGURATION_H
#define CONFIGURATION_H

#include <string>
#include <iostream>
#include <fstream>
#include "json.h"

class Configuration {
  private:
    std::string filepath;

  public:
    Configuration(const std::string filepath);
    void readConfig();
};

#endif
