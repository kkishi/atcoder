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

ll a[100000];

template <typename T>
T Gcd(T a, T b) {
  if (b == 0) {
    return a;
  }
  return Gcd(b, a % b);
}

int main() {
  in(ll,n,m);
  rep(i,n)cin>>a[i];

  rep(i,n){
    a[i]/=2;
  }
  ll l=1;
  rep(i,n){
    l=l*a[i]/Gcd(l,a[i]);
    if(l>m){
      out(0);
      return 0;
    }
  }
  dbg(l,m);
  rep(i,n)if(l/a[i]%2==0){
    out(0);
    return 0;
  }
  ll ans=0;
  if (m >= l) {
    ++ans;
    m -= l;
  }
  ans+=m/(2*l);
  out(ans);
}
