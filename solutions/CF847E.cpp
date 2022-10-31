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

const int N = 1e5 + 5;

char str[N];
vector < int > pacman, food;
int n;

int main () {
  scanf("%d", &n);
  scanf("%s", str + 1);
  FOR(i, 1, n + 1) {
    if (str[i] == 'P') {
      pacman.eb(i);
    } else if (str[i] == '*') {
      food.eb(i);
    }
  }
  int l = 1, r = 3 * n;
  FOR(i, 0, 19) {
    int mid = l + r >> 1;
    int ptr = 0;
    for (auto &x : pacman) {
      int from = x, to = x;
      while (ptr < sz(food)) {
        from = min(from, food[ptr]);
        to = max(to, food[ptr]);
        int need = to - from + min(x - from, to - x);
        if (need > mid) break;
        ++ptr;
      }
    }
    if (ptr == sz(food)) {
      r = mid;
    } else {
      l = mid;
    }
  }
  printf("%d\n", r);
  return 0;
}
