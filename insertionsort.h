#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H
#include <chrono>
#include <iomanip>
#include <iostream>
#include <vector>

template <class T> class InsertionSort {
private:
  void skrivtab(std::vector<T> tab) {
    for (auto temp : tab)
      std::cout << temp << ", ";
    std::cout << "\n";
  }
  const int m_size;

public:
  InsertionSort(int size) : m_size(size) {}
  // Default sorting function
  void Sorting(std::vector<T> *tab) {
    std::cout << "\n========== Insertion Sort ==========\n";

    if (m_size <= 10) {
      std::cout << "Unsorted vector: ";
      skrivtab(*tab); // Printing unsorted vector
    }

    T temp;
    std::chrono::system_clock::time_point starttid =
        std::chrono::system_clock::now();
    for (int i = 1; i < m_size; i++) {
      for (int j = i; j > 0 && tab->at(j - 1) > tab->at(j); j--) {
        temp = tab->at(j);
        tab->at(j) = tab->at(j - 1);
        tab->at(j - 1) = temp;
      }
    }
    std::chrono::system_clock::time_point sluttid =
        std::chrono::system_clock::now();
    std::chrono::duration<double> varighet = sluttid - starttid;
    if (m_size <= 10) {
      std::cout << "Sorted vector: ";
      skrivtab(*tab); // Printing sorted vector
    }
    std::cout << "Elapsed time: " << varighet.count() << "\n";
  }
};

#endif // INSERTIONSORT_H
