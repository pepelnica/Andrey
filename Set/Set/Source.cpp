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
#include "set.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;

int main() {
  int n1, n2;
  string op;
  cin >> n1 >> n2 >> op;

  vector<int64_t> v1(n1), v2(n2), v3;
  for (int i = 0; i < n1; i++) {
    cin >> v1[i];
  }
  for (int i = 0; i < n2; i++) {
    cin >> v2[i];
  }

  Set s1(v1), s2(v2), s3;

  if (op == "union") {
    s3 = s1.Union(s2);
  }

  if (op == "intersection") {
    s3 = s1.Intersection(s2);
  }

  if (op == "difference") {
    s3 = s1.Difference(s2);
  }

  if (op == "symmetricDifference") {
    s3 = s1.SymmetricDifference(s2);
  }

  if (op == "add") {
    for (auto k : v2) {
      s1.Add(k);
    }
    s3 = s1;
  }

  if (op == "remove") {
    for (auto k : v2) {
      s1.Remove(k);
    }
    s3 = s1;
  }

  if (op == "contains") {
    for (auto k : v2) {
      if (s1.Contains(k)) {
        s1.Add(k * k);
      }
    }
    s3 = s1;
  }

  v3 = s3.Data();

  cout << v3.size() << endl;
  sort(v3.begin(), v3.end());
  for (auto k : v3) {
    cout << k << ' ';
  }
}
