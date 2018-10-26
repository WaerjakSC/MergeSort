#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include <chrono>
#include <iostream>
#include <vector>

template <class T> class selectionsort {
private:
  void skrivtab(std::vector<T> tab) {
    for (auto temp : tab)
      std::cout << temp << ", ";
    std::cout << "\n";
  }
  const int m_size;

public:
  selectionsort(int size) : m_size(size) {}
  // Default sorting function
  void Sorting(std::vector<T> *tab) {
    std::cout << "\n========== Selection Sort ==========\n";
    if (m_size <= 10) {
      std::cout << "Unsorted vector: ";
      skrivtab(*tab); // Printing unsorted vector
    }
    T temp;
    std::chrono::system_clock::time_point starttid =
        std::chrono::system_clock::now();
    for (int i = 0; i < m_size - 1; i++) {
      int j = i;
      for (j = i + 1; j < m_size; j++) {
        if (tab->at(j) < tab->at(i)) {
          temp = tab->at(i);
          tab->at(i) = tab->at(j);
          tab->at(j) = temp;
        }
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

#endif // SELECTIONSORT_H
