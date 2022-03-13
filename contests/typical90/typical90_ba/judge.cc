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

void Main() {
  int t = 1;
  wt_flush(t);
  V<int> v = {1, 2, 3, 4, 3, 2};
  wt_flush(sz(v));
  while (true) {
    rd(char, x);
    ints(i);
    if (x == '?') {
      wt_flush(v[i - 1]);
    } else {
      assert(i == max(v));
      break;
    }
  }
}
