#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  rd(int, a, b, c, k);
  bool ok = false;
  rep(ai, k + 1) rep(bi, k + 1) rep(ci, k + 1) if (ai + bi + ci <= k) {
    int A = a << ai, B = b << bi, C = c << ci;
    if (A < B && B < C) ok = true;
  }
  wt(ok);
}
