#include "bits/stdc++.h"

using namespace std;

const int N = 1e5 + 2;

int arr[N];
int many[N];

struct FenwickTree {
  int bit[N];
  void init () {
    memset(bit, 0, sizeof bit);
  }
  void update (int idx, int n, int add) {
    while (idx <= n) {
      bit[idx] += add;
      idx += idx & -idx;
    }
  }
  int query (int idx) {
    int ret = 0;
    while (idx) {
      ret += bit[idx];
      idx -= idx & -idx;
    }
    return ret;
  }
};

FenwickTree tree1;

int main () {
  int n;
  scanf("%d", &n);
  int record = 0;
  for (int i = 1; i <= n; ++i) {
    scanf("%d", arr + i);
    int cnt = tree1.query(arr[i]);
    many[i] = i - 1 - cnt;
    if (cnt == i - 1) {
      ++record;
    }
    tree1.update(arr[i], n, 1);
  }
  if (record == n) {
    puts("1");
    return 0;
  }
  tree1.init();
  int ans = record;
  int rem = 1 << 30;
  for (int i = n; i > 1; --i) {
    int x = tree1.query(arr[i]);
    int del = (many[i] == 0);
    if (ans == x + record - del && arr[i] < rem) {
      rem = arr[i];
    }
    if (ans < x + record - del) {
      ans = x + record - del;
      rem = arr[i];
    }
    if (many[i] == 1) {
      tree1.update(arr[i], n, 1);
    }
  }
  {
    int x = tree1.query(arr[1]);
    int del = (arr[2] < arr[1]);
    if (ans == x + record - 1 && arr[1] < rem) {
      rem = arr[1];
    }
    if (ans < x + record - 1) {
      ans = x + record - 1;
      rem = arr[1];
    }
  }
  printf("%d\n", rem);
  return 0;
}
