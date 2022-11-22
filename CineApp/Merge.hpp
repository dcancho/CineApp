#pragma once

void Merge(int* A1, int* A2, int* A, int n) {
	int i, j, k;
	i = j = k = 0;
	int mitad = n / 2;
	while (i < mitad && j < n - mitad) {
		if (A1[i] < A2[j])
		{
			A[k] = A1[i];//comparando las 2 listas
			i++; k++;
		}
		else
		{
			A[k] = A2[j];
			j++; k++;
		}
	}
	while (i < mitad) {
		A[k] = A1[i];
		i++; k++;
	}
	while (j < n - mitad) {
		A[k] = A2[j];
		j++; k++;
	}
}