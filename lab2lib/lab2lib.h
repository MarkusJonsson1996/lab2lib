//lab2lib.h
#pragma once

class arr2d {
public:

	int** myArr;

	arr2d();
	arr2d(int y, int x);
	~arr2d();

	int get_rows();
	int get_cols();
	void setRowCol(int y, int x);

private:

	int row, cols;
};

bool is_sorted(int val[], int size);
bool is_palindrome(const char* word);
void array_rows_cols(arr2d* arr);
void swap_sort(int* a, int* b, int* c, bool ascDes);
void shrink_array(int* arr, int len);
void vector_database();