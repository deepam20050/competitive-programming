// AC
#include "bits/stdc++.h"
using namespace std;

#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define F first
#define S second
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)

using lli = long long;
using pii = pair < int, int >;

const int N = 2e5 + 5;

int x[N], xsuff[N], y[N], ysuff[N];
int n;
char str[N];
int h, k;

inline bool f (int len) {
  for (int i = 1; i + len - 1 <= n; ++i) {
    int l = i, r = i + len - 1;
    int dx = h - xsuff[r + 1] - x[l - 1];
    int dy = k - ysuff[r + 1] - y[l - 1];
    int tot = abs(dx) + abs(dy);
    if (tot <= len && tot % 2 == len % 2) return 1;
  }
  return 0;
}

int main () {
  scanf("%d", &n);
  scanf("%s", str + 1);
  scanf("%d %d", &h, &k);
  FOR(i, 1, n + 1) {
    x[i] += x[i - 1];
    y[i] += y[i - 1];
    if (str[i] == 'U') ++y[i];
    if (str[i] == 'D') --y[i];
    if (str[i] == 'L') --x[i];
    if (str[i] == 'R') ++x[i];
  }
  for (int i = n; i >= 1; --i) {
    xsuff[i] += xsuff[i + 1];
    ysuff[i] += ysuff[i + 1];
    if (str[i] == 'U') ++ysuff[i];
    if (str[i] == 'D') --ysuff[i];
    if (str[i] == 'L') --xsuff[i];
    if (str[i] == 'R') ++xsuff[i];
  }
  if (x[n] == h && y[n] == k) {
    puts("0");
    exit(0);
  }
  if (!f(n)) {
    puts("-1");
    return 0;
  }
  int l = 0, r = n; 
  FOR(i, 0, 20) {
    int m = l + r >> 1;
    if (f(m)) {
      r = m;
    } else {
      l = m;
    }
  }
  printf("%d\n", r);
  return 0;
}
