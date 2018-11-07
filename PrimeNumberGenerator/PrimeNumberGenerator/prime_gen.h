#include <iostream>
class PrimeNumberGenerator {
 private:
  int start_number;

 public:
  explicit PrimeNumberGenerator(int start) {
    if (start == 1) {
      start_number = 2;
    } else {
      start_number = start;
    }
  }

  bool IsPrime(int number_) {
    int summ_ = 0;
    for (int i = 2; i < number_; i++) {
      if (number_ % i == 0) {
        summ_++;
        break;
      }
    }
    if (summ_ == 0) {
      return true;
    } else {
      return false;
    }
  }
  int GetNextPrime() {
    while (!IsPrime(start_number)) {
      start_number++;
    }
    int p = start_number;
    start_number++;
    return p;
  }
};
