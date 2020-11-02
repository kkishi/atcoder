#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  // For each position, count how many times 1 appears on the position in
  // total.
  int ans = 0;
  int ten = 1;
  int r = 0;  // Number on the right.
  while (n) {
    int c = n % 10;  // Digit of the current position.
    int l = n / 10;  // Number on the left.
    // For example, when processing the 3rd position of 12345, the values are
    // l = 12, c = 3, r = 45, ten = 100. And 1 appears on the position for
    // l * ten times (for patterns like yy1xxx) plus ten (1xxx) times.
    if (l > 0) ans += l * ten;
    if (c > 1) {
      ans += ten;
    } else if (c == 1) {
      ans += r + 1;
    }
    r += n % 10 * ten;
    n /= 10;
    ten *= 10;
  }
  wt(ans);
}
