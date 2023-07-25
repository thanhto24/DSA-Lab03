#pragma once
#ifndef MY_LAB_03
#define MY_LAB_03

#include "DataGenerator.cpp"
#include <cstring>
#include <sstream>
#include <chrono>

// ----------------------------------------------------------------
// TÔ QUỐC THANH_22127388:
// Selection Sort:
void selectionSortVerComp(int arr[], int n, long long &count_compare);  // Counting the number of comparisons
void selectionSortVerTime(int arr[], int n, double &time_use);  // Calculating the time of algorithm

// Insertion Sort:
void insertionSortVerComp(int arr[], int n, long long &count_compare);  // Counting the number of comparisons
void insertionSortVerTime(int arr[], int n, double &time_use);  // Calculating the time of algorithm

// Bubble Sort:
void bubbleSortVerComp(int arr[], int n, long long &count_compare); // Counting the number of comparisons
void bubbleSortVerTime(int arr[], int n, double &time_use); // Calculating the time of algorithm

// ----------------------------------------------------------------
// NGÔ VĂN KHẢI_22127174
// Heap Sort:
void heapRebuildVerComp(int start, int arr[], int n, long long &count_compare);
void heapSortVerComp(int arr[], int n, long long &count_compare);   // Counting the number of comparisons
void heapRebuildVerTime(int start, int arr[], int n);
void heapSortVerTime(int arr[], int n, double &time_use);   // Calculating the time of algorithm

// Merge Sort:
void mergeSortRebuildVerComp(int arr[], int first, int mid, int last, long long &count_compare);
void mergeSortDoVerComp(int arr[], int first, int last, long long &count_compare);
void mergeSortVerComp(int arr[], int n, long long &count_compare);  // Counting the number of comparisons
void mergeSortRebuildVerTime(int arr[], int first, int mid, int last);
void mergeSortDoVerTime(int arr[], int first, int last);
void mergeSortVerTime(int arr[], int n, double &time);  // Calculating the time of algorithm

// Quick Sort:
void quickSortDoVerComp(int arr[], int first, int last, long long &count_compare);
void quickSortVerComp(int arr[], int n, long long &count_compare);  // Counting the number of comparisons
void quickSortDoVerTime(int arr[], int first, int last);
void quickSortVerTime(int arr[], int n, double &time);  // Calculating the time of algorithm

// ----------------------------------------------------------------
// THÁI HUYỄN TÙNG_22127441:
// Radix Sort:
void radixSortVerComp(int arr[], int n, long long &count_compare);  // Counting the number of comparisons
void radixSortVerTime(int arr[], int n, double &time_use);  // Calculating the time of algorithm

// Shaker Sort:
void shakerSortVerComp(int arr[], int n, long long &count_compare); // Counting the number of comparisons
void shakerSortVerTime(int arr[], int n, double &time_use); // Calculating the time of algorithm

// Shell Sort:
void shellSortVerComp(int arr[], int n, long long &count_compare);  // Counting the number of comparisons
void shellSortVerTime(int arr[], int n, double &time_use);  // Calculating the time of algorithm

// ----------------------------------------------------------------
// LÊ PHƯỚC PHÁT_22127322:
// Counting Sort:
void countingSortVerComp(int arr[], int n, long long &count_compare);   // Counting the number of comparisons
void countingSortVerTime(int arr[], int n, double &time_use);   // Calculating the time of algorithm

// Flash Sort:
void flashSortVerComp(int arr[], int n, long long &count_compare);  // Counting the number of comparisons
void flashSortVerTime(int arr[], int n, double &time_use);   // Calculating the time of algorithm

#endif
