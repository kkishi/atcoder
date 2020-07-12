#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

using namespace std;

long long A[2000];

long long absolute(long long x) {
  if (x < 0) {
    return -x;
  }
  return x;
}

int main() {
  int N;
  cin >> N;
  REP(i, N) cin >> A[i];

  vector<pair<long long, int>> v;
  REP(i, N) v.push_back({-A[i], i});
  sort(v.begin(), v.end());

  int left = 0, right = N - 1;
  long long ans = 0;
  REP(i, N) {
    int j = v[i].second;
    if (j - left >= right - j) {
      ans += -v[i].first * (j - left);
      ++left;
    } else {
      ans += -v[i].first * (right - j);
      --right;
    }
  }
  cout << ans << endl;
}
