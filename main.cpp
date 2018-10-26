// ADS101 Algoritmer og datastrukturer 181022
// mergesort eksempel

#include "insertionsort.h"
#include "mergesort.h"
#include "randomizer.h"
#include "selectionsort.h"
#include <chrono>
#include <iostream>
#include <vector>

void RunSortingCalls();

using namespace std;

int main() {

  RunSortingCalls();
  return 0;
}

void RunSortingCalls() {
  int vectorSize{10};
  // MergeSort using ints
  randomizer<int> randomInts;
  mergeSort<int> IntMSort(vectorSize);
  vector<int> randomizedVector = randomInts.generateVector(vectorSize);
  IntMSort.Sorting(&randomizedVector);

  // InsertionSort using ints
  InsertionSort<int> IntISort(vectorSize);
  randomizedVector = randomInts.generateVector(vectorSize);
  IntISort.Sorting(&randomizedVector);

  // SelectionSort using ints
  selectionsort<int> IntSSort(vectorSize);
  randomizedVector = randomInts.generateVector(vectorSize);
  IntSSort.Sorting(&randomizedVector);

  // MergeSort using floats
  mergeSort<double> DoubleMSort(vectorSize);
  randomizer<double> randomFloats;
  vector<double> randVector = randomFloats.generateVector(vectorSize);
  DoubleMSort.Sorting(&randVector);

  // InsertionSort using floats
  InsertionSort<double> DoubleISort(vectorSize);
  randVector = randomFloats.generateVector(vectorSize);
  DoubleISort.Sorting(&randVector);

  // SelectionSort using floats
  selectionsort<double> DoubleSSort(vectorSize);
  randVector = randomFloats.generateVector(vectorSize);
  DoubleSSort.Sorting(&randVector);
}
