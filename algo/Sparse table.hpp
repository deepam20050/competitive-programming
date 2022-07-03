const int N = 1e5 + 5;
const int LN = 18;

int table[LN][N];
int a[N];
int n;

void build () {
  for (int i = 0; (1 << i) < n; ++i) {
    int curr_len = 1 << i;
    for (int j = 0; j + curr_len - 1 < n; ++j) {
      if (i == 0) {
        table[i][j] = a[j];
      } else {
        table[i][j] = min(table[i - 1][j], table[i - 1][j + curr_len / 2]);
      }
    } 
  }
}

int query (int l, int r) {
  if (l > r) return 0;
  int p = __lg(r - l + 1);
  return min(table[p][l], table[p][r - (1 << p) + 1]);
}