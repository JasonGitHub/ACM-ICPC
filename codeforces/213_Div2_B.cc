#include <iostream>

using namespace std;

inline int len(int l, int r) {
  return r - l + 1;
}

int FindLongestSeg(int* a, int n) {
  if (n <= 2) return n;
  bool in_seg = false;
  int max = 0;
  for (int l = 2, r = 2; r < n; ++r) {
    if (!in_seg) l = r;
    if (in_seg && a[r] != a[r - 1] + a[r - 2]) in_seg = false;
    if (!in_seg && a[r] == a[r - 1] + a[r - 2]) in_seg = true;
    if (in_seg) max = (len(l, r) > max) ? len(l, r) : max;
  }
  return max + 2;
}

int main() {
  int n;
  int a[100000 + 10];
  cin >> n;
  for (int i = 0; i < n; ++i) cin >> a[i];
  cout << FindLongestSeg(a, n) << endl;
  return 0;
}
