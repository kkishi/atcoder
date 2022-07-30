#include <bits/stdc++.h>

#include "atcoder.h"

int leap(int y) {
  if (y % 400 == 0) return true;
  if (y % 100 == 0) return false;
  if (y % 4 == 0) return true;
  return false;
}

int days(int y, int m) {
  switch (m) {
    case 2:
      return leap(y) ? 29 : 28;
    case 4:
    case 6:
    case 9:
    case 11:
      return 30;
  }
  return 31;
}

void Main() {
  strings(s);
  int y = stoi(s.substr(0, 4));
  int m = stoi(s.substr(5, 2));
  int d = stoi(s.substr(8, 2));
  while (y % (m * d)) {
    if (d < days(y, m)) {
      ++d;
    } else {
      d = 1;
      if (m < 12) {
        ++m;
      } else {
        m = 1;
        ++y;
      }
    }
  }
  printf("%02ld/%02ld/%02ld\n", y, m, d);
}
