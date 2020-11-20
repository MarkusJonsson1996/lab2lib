//lab2lib.cpp
//compile with cl /c /EHsc lab2lib.cpp
//post-build command: lib lab2lib.obj

#include <iostream>
#include "lab2lib.h"

using namespace std;

arr2d::arr2d(int y, int x) {

	row = y;
	cols = x;

	myArr = new int* [y];

	for (int i = 0; i < y; i++) {
		myArr[i] = new int[x];
	}

	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			myArr[i][j] = rand() % 10;
		}
	}

}

int arr2d::get_rows() { return row; }
int arr2d::get_cols() { return cols; }

bool is_sorted(int val[], int size) {

	bool isSorted = true;
	int count = 1;

	do {

		//cout << val[count];

		if (val[count - 1] > val[count]) {

			isSorted = false;
			break;
		}

		count++;

	} while (count < size);


	return isSorted;
}
bool is_palindrome(char word[]) {

	int wordSize = 0;
	bool is_palin = true;
	int i = 0;

	while (word[wordSize] != '\n') wordSize++;
	wordSize--;


	while (i <= wordSize - i) {

		if (word[i] != word[wordSize - i]) {
			is_palin = false;
			break;
		}

		i++;
	}

	return is_palin;

}
void array_rows_cols(arr2d* arr) {

	int rowSum;
	int rowColSum = 0;
	int* colSum = new int[arr->get_cols()];

	for (int i = 0; i < arr->get_cols(); i++)
		colSum[i] = 0;

	for (int row = 0; row < arr->get_rows(); row++) {

		rowSum = 0;

		for (int col = 0; col < arr->get_cols(); col++) {

			colSum[col] += arr->myArr[row][col];
			rowSum += arr->myArr[row][col];

			cout << arr->myArr[row][col] << "  ";
		}



		cout << rowSum;
		cout << endl;

		rowColSum += rowSum;
	}

	for (int i = 0; i < arr->get_cols(); i++) {
		rowColSum += colSum[i];
		cout << colSum[i] << "  ";
	}

	if (rowColSum)
		cout << rowColSum << endl;
	else
		cout << endl;

}
void swap_sort(int* a, int* b, int* c, bool ascDec) {

	int sort[3] = { *a, *b, *c };
	int temp;

	for (int i = 0; i < 2; i++) {
		for (int j = 1; j < 3; j++) {

			if (sort[i] > sort[j] && ascDec) {
				temp = sort[i];
				sort[i] = sort[j];
				sort[j] = temp;
			}

			else if (sort[i] < sort[j] && !ascDec) {
				temp = sort[i];
				sort[i] = sort[j];
				sort[j] = temp;
			}

		}

	}

	for (int i = 0; i < 3; i++)
		cout << sort[i] << "  ";

	cout << endl << endl;
}