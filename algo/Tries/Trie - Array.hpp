const int M = 7e6;
const int LN = 30;

int trie[M][2];
int idx = 1;

void insert (int x) {
  int curr = 1;
  for (int i = LN - 1; i >= 0; --i) {
    int b = x >> i & 1;
    if (!trie[curr][b]) {
      trie[curr][b] = ++idx;
    }
    curr = trie[curr][b];
  }
}

int query (int x) {
  int ret = 0;
  int curr = 1;
  for (int i = LN - 1; i >= 0; --i) {
    int b = x >> i & 1;
    if (trie[curr][b ^ 1]) {
      ret |= 1 << i;
      curr = trie[curr][b ^ 1]; 
    } else {
      curr = trie[curr][b];
    }
  }
  return ret;
}