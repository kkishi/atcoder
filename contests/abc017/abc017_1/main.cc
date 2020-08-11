#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  int ans = 0;
  rep(i, 3) {
    rd(int, s, c);
    ans += s * c;
  }
  wt(ans / 10);
}
