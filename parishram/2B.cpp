#include "bits/stdc++.h"
using namespace std;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define eb emplace_back
#define em emplace
#define mp make_pair
#define F first
#define S second
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

using lli = long long;
using pii = pair < int, int >;

const int N = 1005;

int n;
int arr[N][N];
int dp2[N][N];
int dp5[N][N];
int to[N][N];
int two[N][N];
int five[N][N];
const int dx[] = {0, 1};
const int dy[] = {1, 0};

inline void get (int x, int y) {
  int ans = 1e9;
  FOR(i, 0, 2) {
    int x_ = x + dx[i], y_ = y + dy[i];
    if (x_ < n && y_ < n) {
      int zz = two[x][y] + dp2[x_][y_];
      int yy = five[x][y] + dp5[x_][y_];
      if (ans > min(zz, yy)) {
        ans = min(zz, yy);
        dp2[x][y] = zz;
        dp5[x][y] = yy;
        to[x][y] = i;
      }
    }
  }
}

int main() {
  scanf("%d", &n);
  FOR(i, 0, n) FOR(j, 0, n) {
    int x;
    scanf("%d", &x);
    if (x == 0) {
      two[i][j] = 1;
      five[i][j] = 1;
      continue;
    }
    while (x % 2 == 0) {
      ++two[i][j];
      x >>= 1;
    }
    while (x % 5 == 0) {
      ++five[i][j];
      x /= 5;
    }
  }
  for (int i = n - 1; i >= 0; --i) {
    for (int j = n - 1; j >= 0; --j) {
      if (i == n - 1 && j == n - 1) {
        dp2[i][j] = two[i][j];
        dp5[i][j] = five[i][j];
      } else {
        get(i, j);
      }
    }
  }
  printf("%d\n", min(dp2[0][0], dp5[0][0]));
  int x = 0, y = 0;
  while (!(x == n - 1 && y == n - 1)) {
    if (to[x][y] == 1) {
      printf("D");
      ++x;
    }
    else if (to[x][y] == 0) {
      printf("R");
      ++y;
    }
  }
  return 0;
}
