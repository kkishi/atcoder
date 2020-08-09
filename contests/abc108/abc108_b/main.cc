#include <bits/stdc++.h>

#include "geometry.h"
#include "macros.h"

using namespace std;

int main() {
  rd(int, x1, y1, x2, y2);
  Vector<int> v1 = {x1, y1}, v2 = {x2, y2};
  Vector<int> v = v2 - v1;
  Vector<int> v3 = v2 + v.Rot90();
  Vector<int> v4 = v3 + v.Rot90().Rot90();
  wt(v3.x, v3.y, v4.x, v4.y);
}
