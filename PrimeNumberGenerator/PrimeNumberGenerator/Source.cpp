#include <algorithm>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>
#include "prime_gen.h"

int main() {
  int start, num;
  std::cin >> start >> num;
  PrimeNumberGenerator gen(start);
  for (int i = 0; i < num; ++i) {
    std::cout << gen.GetNextPrime() << " ";
  }
  system("pause");
};
