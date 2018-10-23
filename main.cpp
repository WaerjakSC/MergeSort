// ADS101 Algoritmer og datastrukturer 181022
// mergesort eksempel

#include <chrono>
#include <iostream>
#include <vector>
#include "mergesort.h"

using namespace std;

int main() {
  vector<int> tab {9, 7, 1, 5, 4, 6, 8, 9, 7};
  const int n = 9;
  auto starttid = chrono::system_clock::now();
  mergeSort<int> IntSort;
  IntSort.Sorting(&tab, n);
  auto sluttid = chrono::system_clock::now();
  chrono::duration<double> varighet = sluttid - starttid;
  cout << varighet.count() << " er ikke imponerende, men tastetrykkene tok tid."
       << endl;
  vector<int> t[12];
  for (;;) {
    cout << "12 heltall: ";
    for (int i = 0; i < 12; i++)
      cin >> t->at(i);
    {
      starttid = chrono::system_clock::now();
      IntSort.Sorting(t, 12);
      sluttid = chrono::system_clock::now();
      chrono::duration<double> varighet = sluttid - starttid;
      cout << "elapsed time: " << varighet.count() << endl;
    }
    break;
  }
  return 0;
}
