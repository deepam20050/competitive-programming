#include "bits/stdc++.h"

using namespace std;

const int H = 2e5 + 5;

long long h[H];
int n, k, mini = 1e9, maxo;

int main () {
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    ++h[x];
    mini = min(mini, x);
    maxo = max(maxo, x);
  }
  for (int i = maxo; i >= 0; --i) {
    h[i] += h[i + 1];
  }
  for (int i = maxo; i >= 0; --i) {
    h[i] += h[i + 1];
  }
  long long rem = 0;
  int cuts = 0;
  int req = maxo;
  for (int i = maxo; i >= mini; --i) {
    if (h[i + 1] - rem > 1ll * k) {
      rem = h[i + 2];
      req = i + 1;
      ++cuts;
    }
  }
  cuts += req != mini;
  printf("%d\n", cuts);
  return 0;
}