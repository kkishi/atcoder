#include <bits/stdc++.h>

#include "macros.h"

using namespace std;

template <typename T>
class Grid {
 public:
  Grid(int height, int width) : grid_(height, std::vector<T>(width)) {}
  void Set(int row, int col, T value) { grid_[row][col] = value; }
  T Distance(int src_row, int src_col) {
    if (grid_[src_row][src_col] < 0) {
      return -1;
    }
    low_priority_queue<std::tuple<T, int, int>> que;
    que.push(make_tuple(0, src_row, src_col));
    std::map<std::pair<int, int>, T> visited;
    visited[{src_row, src_col}] = 0;
    T ret = 0;
    while (!que.empty()) {
      T dist;
      int row, col;
      std::tie(dist, row, col) = que.top();
      que.pop();
      chmax(ret, dist);
      int dr[] = {1, -1, 0, 0};
      int dc[] = {0, 0, 1, -1};
      for (int i = 0; i < 4; ++i) {
        int nrow = row + dr[i];
        int ncol = col + dc[i];
        if (nrow < 0 || grid_.size() <= nrow || ncol < 0 ||
            grid_[0].size() <= ncol || grid_[nrow][ncol] < 0) {
          continue;
        }
        int ndist = dist + grid_[nrow][ncol];
        const auto it = visited.find({nrow, ncol});
        if (it != visited.end() && it->second <= ndist) {
          continue;
        }
        visited[{nrow, ncol}] = ndist;
        que.push(make_tuple(ndist, nrow, ncol));
      }
    }
    return ret;
  }

 private:
  std::vector<std::vector<T>> grid_;
};

int main() {
  rd(int, H, W);
  vector<string> m(H);
  cin >> m;

  int ans = 0;
  rep(sr, H) rep(sc, W) {
    Grid<int> grid(H, W);
    rep(r, H) rep(c, W) grid.Set(r, c, m[r][c] == '.' ? 1 : -1);
    chmax(ans, grid.Distance(sr, sc));
  }
  wt(ans);
}
