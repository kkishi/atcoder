#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

using namespace std;

int dp[4000][3];

int toInt(int c) { return string("RGB").find(c); }

int rem(char a, char b) {
  string s = "RGB";
  REP(i, 3) if (s[i] != a && s[i] != b) return i;
}

int main() {
  int N;
  string S;
  cin >> N >> S;

  for (int i = N - 1; i >= 0; --i) {
    int c = toInt(S[i]);
    REP(j, 3) { dp[i][j] = (i == N - 1 ? 0 : dp[i + 1][j]) + (c == j ? 1 : 0); }
  }
  long long ans = 0;
  REP(i, N) {
    for (int j = i + 1; j + 1 < N; ++j) {
      if (S[i] == S[j]) {
        continue;
      }
      int c = rem(S[i], S[j]);
      int cnt = dp[j + 1][c];
      int k = j + (j - i);
      if (k < N && toInt(S[k]) == c) {
        --cnt;
      }
      ans += cnt;
    }
  }
  cout << ans << endl;
}
