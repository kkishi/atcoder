#include <bits/stdc++.h>

// #undef DEBUG  // Uncomment this line to forcefully disable debug print.
#if DEBUG
template <typename T>
void debug(T value) {
  std::cerr << value;
}
template <typename T, typename... Ts>
void debug(T value, Ts... args) {
  std::cerr << value << ", ";
  debug(args...);
}
#define DBG(...)                              \
  do {                                        \
    cerr << #__VA_ARGS__ << ": ";             \
    debug(__VA_ARGS__);                       \
    cerr << " (L" << __LINE__ << ")" << endl; \
  } while (0)
#else
#define DBG(...)
#endif

#define ALL(x) (x).begin(), (x).end()
#define FOR(i, n) for (auto i : (n))
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)

using ll = long long;

using namespace std;

const int kMax = 2 * 100000;
ll tens[kMax];
ll cnt[10000];

int main() {
  ll N, P;
  cin >> N >> P;
  string S;
  cin >> S;

  int p[] = {2, 5};
  REP(i, 2) if (P == p[i]) {
    ll cnt = 0;
    REP(j, S.size()) if ((S[j] - '0') % p[i] == 0) {
      cnt += j + 1;
    }
    cout << cnt << endl;
    return 0;
  }

  //DBG(N, S, P);

  tens[0] = 1;
  for (int i = 1; i < kMax; ++i) {
    tens[i] = tens[i - 1] * 10 % P;
    // DBG(i, tens[i]);
  }

  ll mod = 0;
  map<ll, ll> cnt;
  reverse(ALL(S));
  REP(i, N) {
    mod = (mod + (S[i] - '0') * tens[i]) % P;
    cnt[mod]++;
    DBG(S[i], mod, cnt[mod]);
  }
  ll ans = 0;
  for (auto it : cnt) {
    ll k, v;
    tie(k, v) = it;
    if (k != 0) --v;
    ans += v * (v + 1) / 2;
  }
  cout << ans << endl;
}
