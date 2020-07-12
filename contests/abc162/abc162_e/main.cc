#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

using namespace std;

typedef vector<long long> res;

const int kMod = 1000000007;
int N, K;

int gcd(int a, int b) {
  if (a > b) {
    return gcd(b, a);
  }
  if (b % a == 0) {
    return a;
  }
  return gcd(b % a, a);
}

res combine(const res& a, const res& b) {
  res c(K + 1);
  for (int ai = 1; ai <= K; ++ai) {
    for (int bi = 1; bi <= K; ++bi) {
      int g = gcd(ai, bi);
      c[g] += a[ai] * b[bi];
      c[g] %= kMod;
    }
  }
  return c;

  /*
  long long sum = 0;
  for (int i = 1; i <= K; ++i) {
    sum += b[i];
  }
  // cout << sum << endl;
  res c(K + 1);
  for (int ai = 1; ai <= K; ++ai) {
    if (ai == 1) {
      c[1] += a[ai] * sum;
      c[1] %= kMod;
      continue;
    }
    long long used = 0;
    for (int bi = ai; bi <= K; bi += ai) {
      used += b[bi];
      c[ai] += a[ai]* b[bi];
      c[ai] %= kMod;
    }
    c[1] += a[ai] * (sum - used);
    c[1] %= kMod;
  }
  */

  /*
  cout << K << endl;
  cout << "a:" << endl;
  for (int i = 1; i <= K; ++i) {
    cout << i << " " << a[i] << endl;
  }
  cout << endl;
  cout << "b:" << endl;
  for (int i = 1; i <= K; ++i) {
    cout << i << " " << b[i] << endl;
  }
  cout << endl;
  cout << "c:" << endl;
  for (int i = 1; i <= K; ++i) {
    cout << i << " " << c[i] << endl;
  }
  cout << endl;
  */

  return c;
}

map<int, res> memo;

res dp(int n) {
  auto it = memo.find(n);
  if (it != memo.end()) {
    return it->second;
  }
  if (n == 1) {
    res r(K + 1);
    for (int i = 1; i <= K; ++i) {
      r[i] = 1;
    }
    memo[n] = r;
    return r;
  }
  if (n % 2 == 1) {
    res r = combine(dp(1), dp(n - 1));
    memo[n] = r;
    return r;
  }
  res r1 = dp(n / 2);
  res r2 = combine(r1, r1);
  memo[n] = r2;
  return r2;
}

int main() {
  cin >> N >> K;

  /*
  {
    res r1 = dp(1);
    res r = r1;
    for (int i = 2; i <= N; ++i) {
      r = combine(r, r1);
    }
    long long ans = 0;
    for (int i = 1; i <= K; ++i) {
      ans += i * r[i];
      ans %= kMod;
    }
    cout << ans << endl;
  }
  */

  res r = dp(N);

  long long ans = 0;
  for (int i = 1; i <= K; ++i) {
    ans += i * r[i];
    ans %= kMod;
  }
  cout << ans << endl;
}
