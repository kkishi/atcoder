#include <bits/stdc++.h>

#include "macros.h"
#include "segment_tree.h"

using namespace std;

int Gcd(int a, int b) {
  if (a == 0) return b;
  if (b == 0) return a;
  assert(a != 0 && b != 0);
  return gcd(a, b);
}

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  cin >> A;

  SegmentTree<int> t(N, Gcd);
  rep(i, N) { t.Set(i, A[i]); }

  int ans = 0;
  rep(i, N) chmax(ans, Gcd(t.Aggregate(0, i), t.Aggregate(i + 1, N)));
  cout << ans << endl;
}
