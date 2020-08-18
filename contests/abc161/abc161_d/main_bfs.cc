#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

int main() {
  ints(K);

  queue<string> que;
  rep(i, 9) que.push(string(1, '1' + i));
  rep(i, K) {
    string here = que.front();
    if (i == K - 1) {
      wt(here);
      break;
    }
    que.pop();
    int x = here.back() - '0';
    for (int i = x - 1; i <= x + 1; ++i) {
      if (i < 0 || 10 <= i) {
        continue;
      }
      que.push(here + (char)('0' + i));
    }
  }
}
