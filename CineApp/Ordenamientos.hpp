#pragma once
#include <iostream>
#include "Merge.hpp"
using namespace std;

void MergeSort(int* A, int n)
{
	if (n > 1)
	{
		int mitad = n / 2;
		int* A1 = new int[mitad];
		int* A2 = new int[n - mitad];
		for (int i = 0; i < mitad; i++)
		{
			A1[i] = A[i];
		}
		for (int i = mitad; i < n; i++)
		{
			A2[i - mitad] = A[i];
		}
		MergeSort(A1, mitad);
		MergeSort(A2, n - mitad);
		Merge(A1, A2, A, n);
	}
};
int partition(int* A, int p, int r) {
	int x = A[r];
	int i = p - 1;
	for (int j = p; j < r; j++)
	{
		if (A[j] <= x)
		{
			i++;
			swap(A[i], A[j]);
		}
	}
	swap(A[i + 1], A[r]);
	return i + 1;
}

void quicksort(int* A, int p, int r) {
	int q;
	if (p < r) {
		q = partition(A, p, r);
		quicksort(A, p, q - 1);
		quicksort(A, q + 1, r);
	}
}


int QuickSelect(int* A, int p, int r, int k) {
	if (p == r) return A[p];
	int q = partition(A, p, r);
	int l = q - p + 1;
	if (k == l) return A[q];
	else if (k < l) return QuickSelect(A, p, q - 1, k);
	else return QuickSelect(A, q + 1, r, k - l);
}