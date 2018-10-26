#ifndef MERGESORT_H
#define MERGESORT_H

#include <chrono>
#include <conio.h>
#include <iostream>
#include <vector>

template <class T> class mergeSort {
private:
  void skrivtab(std::vector<T> tab) {
    for (auto temp : tab)
      std::cout << temp << ", ";
    std::cout << "\n";
  }
  const int m_size;

public:
  mergeSort(int size) : m_size(size) {}
  // Default sorting function
  void Sorting(std::vector<T> *tab) {
    std::cout << "\n========== Merge Sort ==========\n";
    if (m_size <= 10) {
      std::cout << "Unsorted vector: ";
      skrivtab(*tab); // Printing unsorted vector
    }
    size_t i, j, k, lower1, lower2, size, upper1, upper2;
    std::vector<T> hjelp(m_size);

    size = 1;
    std::chrono::system_clock::time_point starttid =
        std::chrono::system_clock::now();
    while (size < m_size) {
      lower1 = 0;
      k = 0;
      while (lower1 + size < m_size) {
        upper1 = lower1 + size - 1;
        lower2 = upper1 + 1;
        upper2 = (lower2 + size - 1 < m_size) ? lower2 + size - 1 : m_size - 1;
        for (i = lower1, j = lower2; i <= upper1 && j <= upper2; k++) {
          if (tab->at(i) < tab->at(j))
            hjelp.at(k) = tab->at(i++);
          else
            hjelp.at(k) = tab->at(j++);
        }
        for (; i <= upper1; k++)
          hjelp.at(k) = tab->at(i++);
        for (; j <= upper2; k++)
          hjelp.at(k) = tab->at(j++);

        lower1 = upper2 + 1;
      } // endwhile

      for (i = lower1; k < m_size; i++)
        hjelp.at(k++) = tab->at(i);
      for (i = 0; i < m_size; i++)
        tab->at(i) = hjelp.at(i);

      size = size * 2;

    } // endwhile
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

#endif // MERGESORT_H
