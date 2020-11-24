//lab2lib.cpp
//compile with cl /c /EHsc lab2lib.cpp
//post-build command: lib lab2lib.obj

#include <iostream>
#include <vector>
#include "lab2lib.h"

using namespace std;

arr2d::arr2d() {
	row = 0;
	cols = 0;

	int** myArr = NULL;
}
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
arr2d::~arr2d(){
	for (int i = 0; i < row; i++) {
		delete[] myArr[i];
	}
	delete[] myArr;
}
void arr2d::setRowCol(int y, int x) {
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
bool is_palindrome(const char* word) {

	int wordSize = 0;
	bool is_palin = true;
	int i = 0;

	while (word[wordSize] != '\0') wordSize++;
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

	cout << endl;
}
void shrink_array(int* arr, int len) {

	int i = 0;
	int j = 0;

	while (i < len) {

		if (i == len - 1) {
			arr[j] = arr[i];
			j++;
			break;
		}

		arr[j] = arr[i] + arr[i + 1];


		j++;
		i += 2;

	}


	while (j < len) {
		arr[j] = 0;
		j++;
	}
}
void vector_database() {

	vector<string> database;
	bool run = true;
	int iuIn = 0;
	string suIn;

	while (run) {
		cout << endl << "MENU:" << endl << endl;

		cout << " 1. initialise database" << endl;
		cout << " 2. insert" << endl;
		cout << " 3. search" << endl;
		cout << " 4. delete" << endl;
		cout << " 5. print" << endl;
		cout << " 6. quit" << endl << endl;

		cout << "Choose a command: ";
		scanf_s("%d", &iuIn);
		cout << endl;

		switch (iuIn) {

		case 1:
			database.clear();
			cout << "Database has been cleared" << endl;

			break;

		case 2:
			while (1) {
				cout << "Enter name to save in database (exit w/ q/Q): ";
				cin >> suIn;

				if (suIn == "q" || suIn == "Q") break;

				database.push_back(suIn);
			}

			break;

		case 3:

			if (!database.size()) {
				cout << "Database is empty" << endl;
				break;
			}

			cout << "Enter full/part of name to search in database: ";
			cin >> suIn;

			for (int i = 0; i < database.size(); i++) {


				if (database.at(i).find(suIn) != string::npos)
					cout << i << ". " << database.at(i) << endl;

				else
					cout << i << " -------" << endl;

			}

			break;

		case 4:

			if (!database.size()) {
				cout << "Database is empty" << endl;
				break;
			}

			cout << "Enter  name to erase from database: ";
			cin >> suIn;

			for (int i = 0; i < database.size(); i++) {

				if (database.at(i) == suIn) {
					cout << "\"" << database.at(i) << "\"" << " has been erased" << endl;
					database.erase(database.begin() + i);
					break;
				}

			}

			break;

		case 5:

			if (!database.size()) cout << "Database is empty" << endl;

			for (int i = 0; i < database.size(); i++)
				cout << i << ". " << database.at(i) << endl;

			break;

		case 6:
			run = false;

			break;

		default:
			cout << "Sorry, unknown command" << endl;

			break;
		}
	}


}