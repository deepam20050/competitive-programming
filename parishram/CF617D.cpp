#include "bits/stdc++.h"

using namespace std;

int x[3], y[3];

bool in_between (int a, int b, int c) {
  return c <= min(a, b) || c >= max(a, b);
}

bool f (int i, int j, int k) {
  return (x[i] == x[j] && in_between(y[i], y[j], y[k])) || (y[i] == y[j] && in_between(x[i], x[j], x[k]));
}

int main () {
  for (int i = 0; i < 3; ++i) {
    scanf("%d %d", x + i, y + i);
  }
  if ((x[0] == x[1] && x[1] == x[2]) || (y[0] == y[1] && y[1] == y[2])) {
    puts("1");
  } else {
    int per[] = {0, 1, 2};
    bool ok = 0;
    do {
      ok |= f(per[0], per[1], per[2]);
    } while (next_permutation(per, per + 3));
    ok ? puts("2") : puts("3");
  }
  return 0;
}
