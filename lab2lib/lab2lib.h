//lab2lib.h
#pragma once

class arr2d {
public:

	int** myArr;

	arr2d(int y, int x);
	~arr2d();

	int get_rows();
	int get_cols();

private:

	int row, cols;
};

bool is_sorted(int val[], int size);
bool is_palindrome(char word[]);
void array_rows_cols(arr2d* arr);
void swap_sort(int* a, int* b, int* c, bool ascDes);