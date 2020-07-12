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

/*
struct B {
  ll p, b;
};

B Burger(int n) {

struct Result {
  ll p, b;
};

ll rec(int n, ll x) {

}
*/

int main() {
  in(ll, n, x);
  vector<ll> p(n + 1);
  vector<ll> b(n + 1);
  p[0] = 1;
  rep(i, n) {
    p[i + 1] = p[i] * 2 + 1;
    b[i + 1] = b[i] * 2 + 2;
  }
  function<ll(ll, ll)> rec = [&p, &b, &rec](ll n, ll x) {
    if (n == 0) return 1LL;
    if (x <= 1) return 0LL;
    --x;
    ll pb = p[n - 1] + b[n - 1];
    if (x <= pb) {
      return rec(n - 1, x);
    }
    x -= pb;
    ll ps = p[n - 1];
    if (x <= 1) {
      return x + ps;
    }
    --x;
    ++ps;
    if (x <= pb) {
      return ps + rec(n - 1, x);
    }
    return ps + p[n - 1];
  };
  out(rec(n, x));
}
