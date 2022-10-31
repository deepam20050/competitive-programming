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
#define lb lower_bound
#define ub upper_bound

using lli = long long;
using pii = pair < int, int >;

const int N = 10;

char s[N][N];

inline bool check (int x, int y) {
  return 0 <= x && x < N && 0 <= y && y < N && s[x][y] == 'X';
}

int main () {
  FOR(i, 0, N) {
    scanf("%s", s[i]);
  }
  FOR(i, 0, N) FOR(j, 0, N) if (s[i][j] == '.') {
    int sum = 1;
    for (int w = j + 1, z = j - 1; ;) {
      bool ok = 0;
      if (check(i, w)) {
        ++w;
        ++sum;
        ok = 1;
      }
      if (check(i, z)) {
        --z;
        ++sum;
        ok = 1;
      }
      if (!ok) break;
    }
    if (sum >= 5) {
      puts("YES");
      exit(0);
    }
    sum = 1;
    for (int w = i + 1, z = i - 1; ;) {
      bool ok = 0;
      if (check(w, j)) {
        ++w;
        ++sum;
        ok = 1;
      }
      if (check(z, j)) {
        --z;
        ++sum;
        ok = 1;
      }
      if (!ok) break;
    }
    if (sum >= 5) {
      puts("YES");
      exit(0);
    }
    sum = 1;
    for (int x1 = i - 1, y1 = j - 1, x2 = i + 1, y2 = j + 1; ;) {
      bool ok = 0;
      if (check(x1, y1)) {
        --x1; --y1;
        ++sum;
        ok = 1;
      }
      if (check(x2, y2)) {
        ++x2; ++y2;
        ++sum;
        ok = 1;
      }
      if (!ok) break;
    }
    if (sum >= 5) {
      puts("YES");
      exit(0);
    }
    sum = 1;
    for (int x1 = i - 1, y1 = j + 1, x2 = i + 1, y2 = j - 1; ;) {
      bool ok = 0;
      if (check(x1, y1)) {
        --x1; ++y1;
        ++sum;
        ok = 1;
      }
      if (check(x2, y2)) {
        ++x2; --y2;
        ++sum;
        ok = 1;
      }
      if (!ok) break;
    }
    if (sum >= 5) {
      puts("YES");
      exit(0);
    }
  }
  puts("NO");
  return 0;
}