// ADS101 Algoritmer og datastrukturer 181022
// mergesort eksempel

#include "insertionsort.h"
#include "mergesort.h"
#include "randomizer.h"
#include "selectionsort.h"
#include "treenode.h"
#include <chrono>
#include <iostream>
#include <vector>

void RunSortingCalls(int vectorSize);

using namespace std;
using namespace ADS101;

int main()
{
    for (int i = 10; i <= 10000; i *= 10)
    {
        std::cout << "\nSorting " << i << " random numbers.\n";
        RunSortingCalls(i);
    }
    return 0;
}

void RunSortingCalls(int vectorSize)
{
    std::cout << "\nInts:\n";
    // MergeSort using ints
    randomizer<int> randomInts;
    vector<int> randomizedVector = randomInts.generateVector(vectorSize);
    MergeSort<int> IntMSort(&randomizedVector, vectorSize);

    // InsertionSort using ints
    randomizedVector = randomInts.generateVector(vectorSize);
    InsertionSort<int> IntISort(&randomizedVector, vectorSize);

    // SelectionSort using ints
    randomizedVector = randomInts.generateVector(vectorSize);
    SelectionSort<int> IntSSort(&randomizedVector, vectorSize);

    // Binary Search Tree using ints
    TreeNode<int> IntBSTSort;
    std::cout << "\n========== Binary Search Tree =========\n";
    std::chrono::system_clock::time_point starttid = std::chrono::system_clock::now();
    for (size_t i = 0; i < randomizedVector.size(); i++)
    {
        IntBSTSort.addNode(randomizedVector[i]);
    }
    std::chrono::system_clock::time_point sluttid = std::chrono::system_clock::now();
    std::chrono::duration<double> varighet = sluttid - starttid;
    std::cout << "Elapsed time: " << varighet.count() << "\n";

    // std::sort using ints
    std::cout << "\n========== std::sort =========\n";
    starttid = std::chrono::system_clock::now();
    std::sort(randomizedVector.begin(), randomizedVector.end());
    sluttid = std::chrono::system_clock::now();
    varighet = sluttid - starttid;
    std::cout << "Elapsed time: " << varighet.count() << "\n";

    // std::sort_heap using ints
    std::cout << "\n========== std::sort_heap =========\n";
    std::make_heap(randomizedVector.begin(), randomizedVector.end());
    starttid = std::chrono::system_clock::now();
    std::sort_heap(randomizedVector.begin(), randomizedVector.end());
    sluttid = std::chrono::system_clock::now();
    varighet = sluttid - starttid;
    std::cout << "Elapsed time: " << varighet.count() << "\n";

    std::cout << "\nFloats:\n";

    // MergeSort using floats
    randomizer<double> randomFloats;
    vector<double> randVector = randomFloats.generateVector(vectorSize);
    MergeSort<double> DoubleMSort(&randVector, vectorSize);

    // InsertionSort using floats
    randVector = randomFloats.generateVector(vectorSize);
    InsertionSort<double> DoubleISort(&randVector, vectorSize);

    // SelectionSort using floats
    randVector = randomFloats.generateVector(vectorSize);
    SelectionSort<double> DoubleSSort(&randVector, vectorSize);

    // Binary Search Tree using ints
    TreeNode<int> DoubleBSTSort;
    std::cout << "\n========== Binary Search Tree =========\n";
    starttid = std::chrono::system_clock::now();
    for (size_t i = 0; i < randomizedVector.size(); i++)
    {
        DoubleBSTSort.addNode(randomizedVector[i]);
    }
    sluttid = std::chrono::system_clock::now();
    varighet = sluttid - starttid;
    std::cout << "Elapsed time: " << varighet.count() << "\n";

    // std::sort using floats
    randVector = randomFloats.generateVector(vectorSize);
    std::cout << "\n========== std::sort =========\n";
    starttid = std::chrono::system_clock::now();
    std::sort(randVector.begin(), randVector.end());
    sluttid = std::chrono::system_clock::now();
    varighet = sluttid - starttid;
    std::cout << "Elapsed time: " << varighet.count() << "\n";

    // std::sort_heap using floats
    std::cout << "\n========== std::sort_heap =========\n";
    std::make_heap(randVector.begin(), randVector.end());
    starttid = std::chrono::system_clock::now();
    std::sort_heap(randVector.begin(), randVector.end());
    sluttid = std::chrono::system_clock::now();
    varighet = sluttid - starttid;
    std::cout << "Elapsed time: " << varighet.count() << "\n";
}
