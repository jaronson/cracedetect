#ifndef SRC_ERRORS_H_
#define SRC_ERRORS_H_

#include <exception>

using std::exception;

class StandardError : public exception {
 public:
    StandardError(){}
};

class DetectorError : public StandardError {
  using StandardError::StandardError;
};

#endif  // SRC_ERRORS_H_
