#ifndef ERRORS_H
#define ERRORS_H

#include <exception>

using namespace std;

class StandardError : public exception {
  public:
    explicit StandardError(){};
};

class DetectorError : public StandardError {
  using StandardError::StandardError;
};

#endif
