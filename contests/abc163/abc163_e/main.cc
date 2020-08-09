#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

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
  rep(i, N) cin >> A[i];

  long long ans = 0;
  for (int i = 0; i <= N; ++i) {
    vector<pair<long long, int>> left;
    for (int j = 0; j < i; ++j) {
      left.push_back(make_pair(A[j], -j));
    }
    sort(left.begin(), left.end());

    vector<pair<long long, int>> right;
    for (int j = i; j < N; ++j) {
      right.push_back(make_pair(-A[j], -j));
    }
    sort(right.begin(), right.end());

    long long sum = 0;
    for (int i = 0; i < left.size(); ++i) {
      sum += left[i].first * absolute(-left[i].second - (right.size() + i));
    }
    for (int i = 0; i < right.size(); ++i) {
      sum += -right[i].first * absolute(-right[i].second - i);
    }
    if (ans < sum) {
      ans = sum;
    }
  }
  cout << ans << endl;
}
