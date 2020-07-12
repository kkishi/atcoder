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
#define dbg(...)                              \
  do {                                        \
    cerr << #__VA_ARGS__ << ": ";             \
    debug(__VA_ARGS__);                       \
    cerr << " (L" << __LINE__ << ")" << endl; \
  } while (0)
#else
#define dbg(...)
#endif

void read_from_cin() {}
template <typename T, typename... Ts>
void read_from_cin(T& value, Ts&... args) {
  std::cin >> value;
  read_from_cin(args...);
}
#define in(type, ...) \
  type __VA_ARGS__;   \
  read_from_cin(__VA_ARGS__);

template <typename T>
void write_to_cout(const T& value) {
  std::cout << value << std::endl;
}
template <typename T, typename... Ts>
void write_to_cout(const T& value, const Ts&... args) {
  std::cout << value << ' ';
  write_to_cout(args...);
}
#define out(...) write_to_cout(__VA_ARGS__);

#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)

using ll = long long;

using namespace std;

int main() {
  in(ll, a, b, q);
  vector<ll> s(a);
  rep(i, a) cin >> s[i];
  set<ll> ss(all(s));
  vector<ll> t(b);
  rep(i, b) cin >> t[i];
  set<ll> ts(all(t));
  while (q--) {
    in(ll, x);
    auto lohi = [](const set<ll>& s, ll x) {
      vector<ll> v;
      auto it = s.lower_bound(x);
      if (it == s.end()) {
        --it;
        v.push_back(*it);
      } else {
        v.push_back(*it);
        if (it != s.begin()) {
          --it;
          v.push_back(*it);
        }
      }
      /*
      dbg(x);
      for (ll sx : s) cerr << sx << " ";
      cerr << endl;
      for (ll sx : v) cerr << sx << " ";
      cerr << endl;
      */
      return v;
    };
    ll ans = numeric_limits<ll>::max();
    for (ll sx : lohi(ss, x)) {
      for (ll tx : lohi(ts, x)) {
        ans = min(ans, abs(x - sx) + abs(sx - tx));
        ans = min(ans, abs(x - tx) + abs(tx - sx));
      }
    }
    out(ans);
  }
}
