#include "bits/stdc++.h"

using namespace std;

const int N = 1005;

char s[N];
int a[N][N], b[N][N];

int main () {
  int tc;
  scanf("%d", &tc);
  while (tc--) {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
      scanf("%s", s);
      for (int j = 0; j < n; ++j) {
        a[i][j] = s[j] - '0';
      }
    }
    for (int i = 0; i < n; ++i) {
      scanf("%s", s);
      for (int j = 0; j < n; ++j) {
        b[i][j] = s[j] - '0';
      }
    }
    for (int i = 0; i < n; ++i) {
      if (a[0][i] != b[0][i]) {
        for (int j = 0; j < n; ++j) {
          a[j][i] ^= 1;
        }
      }
    }
    for (int j = 0; j < n; ++j) {
      if (a[j][0] != b[j][0]) {
        for (int i = 0; i < n; ++i) {
          a[j][i] ^= 1;
        }
      }
    }
    int ok = 1;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < n; ++j) {
        ok &= a[i][j] == b[i][j];
      }
    }
    ok ? puts("YES") : puts("NO");
  }
  return 0;
}
