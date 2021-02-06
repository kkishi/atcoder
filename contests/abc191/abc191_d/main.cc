#include <bits/stdc++.h>

#include "atcoder.h"
#include "binary_search.h"

void Main() {
  rd(long double, X, Y, R);
  const int c = 10000;
  auto sign = [](double x) { return x < 0 ? -1 : x > 0 ? 1 : 0; };
  int x = X * c + sign(X) * 0.5;
  int y = Y * c + sign(Y) * 0.5;
  int r = R * c + sign(R) * 0.5;
  auto roundup = [&c](int x) {
    if (x < 0) {
      x = -x;
      x -= x % c;
      return -x;
    } else {
      x += c - 1;
      return x - x % c;
    }
  };
  assert(roundup(9999) == 10000);
  assert(roundup(10000) == 10000);
  assert(roundup(10001) == 20000);
  assert(roundup(-9999) == 0);
  assert(roundup(-10000) == -10000);
  assert(roundup(-10001) == -10000);
  auto rounddown = [&c](int x) {
    if (x < 0) {
      x = -x;
      x += c - 1;
      x -= x % c;
      return -x;
    }
    return x - x % c;
  };
  assert(rounddown(9999) == 0);
  assert(rounddown(10000) == 10000);
  assert(rounddown(10001) == 10000);
  assert(rounddown(-9999) == -10000);
  assert(rounddown(-10000) == -10000);
  assert(rounddown(-10001) == -20000);
  int lx = roundup(x - r);
  int hx = rounddown(x + r);
  int ans = 0;
  for (int xi = lx; xi <= hx; xi += c) {
    int d = abs(x - xi);
    int y2 = r * r - d * d;
    double dy = sqrt((double)y2);
    double eps = 1e-6;
    int ly = roundup(y - dy - eps) / c;
    {
      while (true) {
        int z = y - (ly - 1) * c;
        if (z * z <= y2) {
          --ly;
        } else {
          break;
        }
      }
      while (true) {
        int z = y - ly * c;
        if (z * z > y2) {
          ++ly;
        } else {
          break;
        }
      }
    }
    int hy = rounddown(y + dy + eps) / c;
    {
      while (true) {
        int z = (hy + 1) * c - y;
        if (z * z <= y2) {
          ++hy;
        } else {
          break;
        }
      }
      while (true) {
        int z = y - hy * c;
        if (z * z > y2) {
          --hy;
        } else {
          break;
        }
      }
    }
    if (hy >= ly) {
      ans += (hy - ly) + 1;
    }
  }
  wt(ans);
}
