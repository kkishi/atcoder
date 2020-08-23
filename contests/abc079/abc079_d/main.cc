#include <bits/stdc++.h>

#include "macros.h"
#include "warshall_floyd.h"

using namespace std;

int main() {
  ints(h, w);
  VV<int> c(10, V<int>(10));
  cin >> c;
  WarshallFloyd(c);
  int ans = 0;
  rep(i, h * w) {
    ints(a);
    if (a != -1) ans += c[a][1];
  }
  wt(ans);
}
