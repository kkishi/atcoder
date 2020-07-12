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

template <typename T>
struct Vector {
  T x, y;
  T Norm() const { return std::sqrt(x * x + y * y); }
  Vector& operator+=(const Vector& v) {
    (*this).x += v.x;
    (*this).y += v.y;
    return *this;
  }
  Vector operator+(const Vector& v) const { return Vector(*this) += v; }
  Vector& operator-=(const Vector& v) {
    (*this).x -= v.x;
    (*this).y -= v.y;
    return *this;
  }
  Vector operator-(const Vector& v) const { return Vector(*this) -= v; }
  Vector& operator*=(T t) {
    (*this).x *= t;
    (*this).y *= t;
    return *this;
  }
  Vector operator*(T t) const { return Vector(*this) *= t; }
  bool operator<(const Vector& v) const {
    if (x != v.x) {
      return x < v.x;
    }
    return y < v.y;
  }
  Vector Rot90() const { return {-y, x}; }

  // TODO:
  // * Rename this struct to Point and add method that treats this struct as
  //   a 2D vector (e.g., dot product) and as a complex number (arc, multiple
  //   number multiplication, ...).
  //   Check the STL functions:
  //   https://ja.cppreference.com/w/cpp/numeric/complex Check the wikipedia
  //   page: https://en.wikipedia.org/wiki/Complex_number
  // * Replace Rot90 with more generic Rotate(arg) function.
  // * Think about a way to visualize these objects for debugging. One idea is
  //   to add an external library that renders these objects using Cairo.
  //   For visualization, WolframAlpha is also extremely useful, for example it
  //   even calculates intersections if provided 2 circles. Try:
  //   (x-1)^2+y^2=5^2, (x+7)^2+y^2=3^2
  // * Add common constants like pi.
};

template <typename T>
std::istream& operator>>(std::istream& is, Vector<T>& v) {
  is >> v.x >> v.y;
  return is;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const Vector<T>& v) {
  os << "(" << v.x << "," << v.y << ")";
  return os;
}

using Vec = Vector<double>;

int main() {
  in(int, n);
  vector<Vec> v(n);
  rep(i, n) cin >> v[i];
  double ans = 0;
}
