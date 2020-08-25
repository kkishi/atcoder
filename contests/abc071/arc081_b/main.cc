#include <bits/stdc++.h>

#include "macros.h"
#include "modint.h"

using mint = ModInt<>;

using namespace std;

int main() {
  ints(n);
  strings(s1, s2);
  mint ans = 1;
  rep(i, n) {
    if (s1[i] == s2[i]) {
      if (i == 0) {
        ans = 3;
      } else {
        if (s1[i - 1] == s2[i - 1]) {
          ans *= 2;
        }
      }
    } else {
      if (i == 0) {
        ans = 6;
      } else {
        if (s1[i - 1] == s2[i - 1]) {
          ans *= 2;
        } else {
          ans *= 3;
        }
      }
      ++i;
    }
  }
  wt(ans);
}
