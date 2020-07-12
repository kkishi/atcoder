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

complex<double> c[50];

int main() {
  in(int,n);
  rep(i,n){
    double x,y;
    cin>>x>>y;
    c[i]={x,y};
  }
  complex<double> cc=c[0];
  double delta=1000.0;
  while(delta>1e-10){
    double dist=0;
    complex<double> dc;
    rep(i,n){
      double d=abs(c[i]-cc);
      if(dist<d){
        dist=d;
        dc=c[i];
      }
    }
    complex<double> dir=dc-cc;
    cc+=dir/abs(dir)*delta;
    delta*=0.999;
  }
  cout<<setprecision(20);
  out(abs(c[0]-cc));
}
