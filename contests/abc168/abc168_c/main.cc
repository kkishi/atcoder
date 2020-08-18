#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

double sq(double x) { return x * x; }

int main() {
  rd(double, A, B, H, M);

  double pi = 3.141592653589793;
  double at = (H + M / 60) / 12 * 2 * pi;
  double ax = cos(at) * A;
  double ay = sin(at) * A;
  double bt = (M / 60) * 2 * pi;
  double bx = cos(bt) * B;
  double by = sin(bt) * B;
  printf("%.20f\n", sqrt(sq(ax - bx) + sq(ay - by)));
}
