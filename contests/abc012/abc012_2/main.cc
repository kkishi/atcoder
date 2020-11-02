#include <bits/stdc++.h>

#include "atcoder.h"

void Main() {
  ints(n);
  printf("%02d:%02d:%02d", n / 60 / 60, n / 60 % 60, n % 60);
}
