#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  strings(t);
  int dx[] = {1, 0, -1, 0};
  int dy[] = {0, -1, 0, 1};
  int x = 0, y = 0;
  int i = 0;
  each(e, t) {
    if (e == 'S') {
      x += dx[i];
      y += dy[i];
    } else {
      i = (i + 1) % 4;
    }
  }
  wt(x, y);
}
