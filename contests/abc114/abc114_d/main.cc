#include <bits/stdc++.h>

#include "factorize.h"
#include "macros.h"

using namespace std;

int main() {
  rd(int, n);
  map<int, int> fs;
  for (int i = 2; i <= n; ++i) {
    for (auto [k, v] : Factorize(i)) fs[k] += v;
  }
  // 3 * 5 * 5
  // 15 * 5
  // 3 * 25
  // 75
  vector<int> cand = {3, 5, 15, 25, 75};
  map<int, int> m;
  for (auto [_, v] : fs) {
    for (int c : cand) {
      if (v >= c - 1) {
        m[c]++;
      }
    }
  }
  int ans = m[5] * (m[5] - 1) / 2 * (m[3] - 2) + m[15] * (m[5] - 1) +
            m[25] * (m[3] - 1) + m[75];
  wt(ans);
}
