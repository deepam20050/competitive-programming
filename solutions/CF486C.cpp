#include "bits/stdc++.h"

using namespace std;

const int N = 1e5 + 5;

char s[N];

int dist (char x, char y) {
  if (x > y) {
    swap(x, y);
  }
  return min(y - x, 26 - (y - x));
}

int main() {
  int n, c;
  scanf("%d %d %s", &n, &c, s);
  --c;
  if (c + c > n - 1) {
    c = n - 1 - c;
  }
  int l = 0;
  int m = n >> 1;
  while (l < m && s[l] == s[n - 1 - l]) {
    ++l;
  }
  int r = n / 2 - 1;
  while (r >= 0 && s[r] == s[n - 1 - r]) {
    --r;
  }
  if (l > r) {
    puts("0");
    return 0;
  }
  int ans = r - l + min(abs(r - c), abs(l - c));
  while (l <= r) {
    if (s[l] != s[n - 1 - l]) {
      ans += dist(s[l], s[n - 1 - l]);
    }
    ++l;
  }
  printf("%d", ans);
  return 0;
}
