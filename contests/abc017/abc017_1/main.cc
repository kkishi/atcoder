#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int ans = 0;
  rep(i, 3) {
    rd(int, s, c);
    ans += s * c;
  }
  wt(ans / 10);
}
