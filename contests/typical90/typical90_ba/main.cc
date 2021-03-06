#include <bits/stdc++.h>

#include <iomanip>

#include "macros.h"

void Main();

int main() {
  Main();
  return 0;
}

using namespace std;

#define int i64

#define wt_flush(...) \
  do {                \
    wt(__VA_ARGS__);  \
    cout.flush();     \
  } while (0)

void Solve() {
  auto ask = [](int i) {
    wt_flush("?", i);
    ints(x);
    return x;
  };
  ints(n);
  if (n == 1) {
    wt_flush("!", ask(1));
    return;
  }
  int ans = -big;
  int lo = 1, hi = n;
  rep(11) {
    int mid = (lo + hi) / 2;
    int l = ask(mid);
    int r = ask(mid + 1);
    chmax(ans, max(l, r));
    if (l < r) {
      lo = mid;
    } else {
      hi = mid;
    }
  }
  wt_flush("!", ans);
}

void Main() {
  ints(t);
  rep(t) Solve();
}
