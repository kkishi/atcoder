#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
#define int ll
  ints(t1, t2, a1, a2, b1, b2);
  if (a1 > b1) {
    swap(a1, b1);
    swap(a2, b2);
  }
  int A1 = t1 * a1, A2 = t2 * a2;
  int B1 = t1 * b1, B2 = t2 * b2;
  // A1 < B1
  if (A2 < B2) {
    wt(0);
    return 0;
  }
  // A2 > B2
  int A = A1 + A2;
  int B = B1 + B2;
  if (A == B) {
    wt("infinity");
    return 0;
  }
  if (A < B) {
    wt(0);
    return 0;
  }
  int C = A - B;
  int D = (B1 - A1) / C * 2;
  if ((B1 - A1) % C == 0) --D;
  wt(1 + D);
}
