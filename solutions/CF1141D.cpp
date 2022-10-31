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

const int N = 1.5e5 + 5;
const int MX = 30;
const int LN = 30;

char a[N], b[N];
queue < int > av[MX], bv[MX];

int get (char c) {
  return c == '?' ? MX - 1 : c - 'a';
}

int main () {
  int n; scanf("%d", &n);
  scanf("%s", a + 1);
  scanf("%s", b + 1);
  FOR(i, 1, n + 1) {
    av[get(a[i])].em(i);
  }
  FOR(i, 1, n + 1) {
    bv[get(b[i])].em(i);
  }
  vector < pii > ans;
  FOR(i, 0, LN - 1) {
    while (!av[i].empty() && !bv[i].empty()) {
      int x = av[i].front();
      int y = bv[i].front();
      av[i].pop();
      bv[i].pop();
      ans.eb(x, y);
    }
  }
  FOR(i, 0, LN - 1) {
    int j = LN - 1;
    while (!av[i].empty() && !bv[j].empty()) {
      int x = av[i].front();
      int y = bv[j].front();
      av[i].pop();
      bv[j].pop();
      ans.eb(x, y);
    }
  }
  FOR(i, 0, LN - 1) {
    int j = LN - 1;
    while (!av[j].empty() && !bv[i].empty()) {
      int x = av[j].front();
      int y = bv[i].front();
      av[j].pop();
      bv[i].pop();
      ans.eb(x, y);
    }
  }
  while (!av[LN - 1].empty() && !bv[LN - 1].empty()) {
    int x = av[LN - 1].front();
    int y = bv[LN - 1].front();
    av[LN - 1].pop();
    bv[LN - 1].pop();
    ans.eb(x, y);
  }
  printf("%d\n", sz(ans));
  for (auto [x, y] : ans) {
    printf("%d %d\n", x, y);
  }
  return 0;
}
