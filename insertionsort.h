#ifndef INSERTIONSORT_H
#define INSERTIONSORT_H
#include <chrono>
#include <iomanip>
#include <iostream>
#include <vector>

namespace ADS101
{
template <class T>
class InsertionSort
{
private:
    const int m_size;

    // Prints the vector to console
    void skrivtab(std::vector<T> tab)
    {
        for (auto temp : tab)
            std::cout << temp << ", ";
        std::cout << "\n";
    }
    // Default sorting function
    void Sorting(std::vector<T> *tab)
    {
        std::cout << "\n========== Insertion Sort ==========\n";

        if (m_size <= 10)
        {
            std::cout << "Unsorted vector: ";
            skrivtab(*tab); // Printing unsorted vector
        }

        T temp;
        std::chrono::system_clock::time_point starttid = std::chrono::system_clock::now();
        for (int i = 1; i < m_size; i++)
        {
            for (int j = i; j > 0 && tab->at(j - 1) > tab->at(j); j--)
            {
                temp = tab->at(j);
                tab->at(j) = tab->at(j - 1);
                tab->at(j - 1) = temp;
            }
        }
        std::chrono::system_clock::time_point sluttid = std::chrono::system_clock::now();
        std::chrono::duration<double> varighet = sluttid - starttid;
        if (m_size <= 10)
        {
            std::cout << "Sorted vector: ";
            skrivtab(*tab); // Printing sorted vector
        }
        std::cout << "Elapsed time: " << varighet.count() << "\n";
    }

public:
    // Constructor runs the sorting function
    InsertionSort(std::vector<T> *tab, int size) : m_size(size) { Sorting(tab); }
};
} // namespace ADS101
#endif // INSERTIONSORT_H
