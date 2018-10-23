#ifndef MERGESORT_H
#define MERGESORT_H

#include <iostream>
#include <vector>
#include <conio.h>

const int ARRAYSIZE = 100;

template <class T> class mergeSort
{
public:
    void skrivtab(std::vector<T> tab, int n) {
        for (int k = 0; k < n; k++)
            std::cout << tab[k] << ", ";
        std::cout << "trykk en tast\n";
        _getch();
    }
    void Sorting(std::vector<T> *tab, int n) {
        int i, j, k, lower1, lower2, size, upper1, upper2;
        std::vector<T> hjelp[ARRAYSIZE];

        skrivtab(*tab, n);

        size = 1;
        while (size < n) {
            lower1 = 0;
            k = 0;
            while (lower1 + size < n) {
                upper1 = lower1 + size - 1;
                lower2 = upper1 + 1;
                upper2 = (lower2 + size - 1 < n) ? lower2 + size - 1 : n - 1;
                for (i = lower1, j = lower2; i <= upper1 && j <= upper2; k++) {
                    if (tab[i] < tab[j])
                        hjelp[k] = tab[i++];
                    else
                        hjelp[k] = tab[j++];
                }
                for (; i <= upper1; k++)
                    hjelp[k] = tab[i++];
                for (; j <= upper2; k++)
                    hjelp[k] = tab[j++];

                lower1 = upper2 + 1;
            } // endwhile

            for (i = lower1; k < n; i++)
                hjelp[k++] = tab[i];
            for (i = 0; i < n; i++)
                tab[i] = hjelp[i];

            size = size * 2;

            skrivtab(*tab, n);
        } // endwhile
    }
};

#endif // MERGESORT_H
