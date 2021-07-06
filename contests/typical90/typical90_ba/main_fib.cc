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
  ints(n);
  map<int, int> cache;
  auto ask = [&](int i) -> int {
    if (i > n) return n - i;
    if (cache.count(i)) return cache[i];
    wt_flush("?", i);
    ints(x);
    cache[i] = x;
    return x;
  };
  if (n == 1) {
    wt_flush("!", ask(1));
    return;
  }

  V<int> fib(17);
  rep(i, sz(fib)) fib[i] = i < 2 ? 1 : fib[i - 1] + fib[i - 2];

  int ans = -big;
  int lo = 0, hi = fib[16];
  rrep(i, 15) {
    int l = lo + fib[i];
    int L = ask(l);
    int r = hi - fib[i];
    int R = ask(r);
    chmax(ans, max(L, R));
    if (L < R) {
      lo = l;
    } else {
      hi = r;
    }
  }
  wt_flush("!", ans);
}

void Main() {
  ints(t);
  rep(t) Solve();
}
