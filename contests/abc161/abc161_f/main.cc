#include <bits/stdc++.h>

#include "atcoder.h"
#include "factorize.h"

bool OK(int N, int K) {
  while (N != 1) {
    if (N % K == 0) {
      N /= K;
      continue;
    } else if (N > K) {
      N %= K;
      continue;
    }
    return false;
  }
  return true;
}

using iter = map<int, int>::const_iterator;

void dfs(set<int>& s, int K, iter it, iter end) {
  if (it == end) {
    if (K > 1) {
      s.insert(K);
    }
    return;
  }
  auto [k, v] = *it;
  ++it;
  dfs(s, K, it, end);
  rep(i, v) {
    K *= k;
    dfs(s, K, it, end);
  }
}

void Main() {
  ints(N);

  map<int, int> f1 = Factorize(N - 1);
  set<int> s1;
  dfs(s1, 1, all(f1));

  map<int, int> f2 = Factorize(N);
  set<int> s2;
  dfs(s2, 1, all(f2));

  int ans = s1.size();
  for (int x : s2) {
    if (OK(N, x)) {
      ++ans;
    }
  }
  wt(ans);
}
