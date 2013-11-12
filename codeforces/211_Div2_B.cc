// http://codeforces.com/contest/363/problem/B
#include <iostream>

using namespace std;

int Find(int* arr, int n, int k) {
  int* aux = new int[n - k + 1];
  aux[0] = 0;
  for (int i = 0; i < k; ++i) {
    aux[0] += arr[i];
  }
  int min = aux[0], ix = 0;
  for (int i = 1; i < n - k + 1; ++i) {
    aux[i] = aux[i - 1] - arr[i - 1] + arr[i + k - 1];
    if (aux[i] < min) {
      min = aux[i];
      ix = i;
    }
  }
  delete[] aux;
  return ix + 1;
}

int main() {
  int n, k, i = 0;
  int arr[150000 + 10];
  cin >> n >> k;
  while (cin >> arr[i++]) continue;
  cout << Find(arr, n, k) << endl;
  return 0;
}
