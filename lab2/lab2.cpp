#include <iostream>
#include "lab2lib.h"

using namespace std;

int main()
{	
	string usIn;
	string rowcol[2] = { "rows", "collumns" };
	arr2d usArr;
	int rowCol[2] = {};
	int b[5] = { 2, 4, 1, 3, 4 };
	int val[4] = { 0 };
	int task;
	bool run = true;
	
	cout << "Enter which task to run (\"-1\" to exit): ";

	while (run) {

		cin >> task;

		switch (task) {
		
		case -1:
			run = false;
			break;

		case 1:

			cout << "Enter 4 integer values" << endl;

			for (int i = 0; i < 4; i++)
				cin >> val[i];


			if (is_sorted(val, sizeof(val) / sizeof(val[0])))
				cout << "Item's are sorted" << endl;
			else
				cout << "Item's are unsorted" << endl;
			break;
			
		case 2:
			cout << "Write yor word: ";
			cin >> usIn;

			if (is_palindrome(usIn.c_str()))
				cout << "Word is palindrome" << endl;
			else
				cout << "Word is not palindrome" << endl;

			break;

		case 3:

			for (int i = 0; i < 2; i++) {
				cout << "Enter numbers of " << rowcol[i] << ": ";
				cin >> rowCol[i];
			}

			usArr.setRowCol(rowCol[0], rowCol[1]);

			array_rows_cols(&usArr);

			break;
		case 4:

			while (run)
			{
				string quest[4] = { "Give a: ", "Give b: ", "Give c: ", "Sort ascend/decsend (1/0): " };
				int val[3];
				bool ascDec = false;
				int temp;

				for (int i = 0; i < 4; i++) {
					cout << quest[i];
					cin >> temp;

					if (temp != 0 && i < 3)
						val[i] = temp;
					else if (i == 3)
						ascDec = temp;

					else {
						run = false;
						break;
					}
				}

				if (run)
					swap_sort(&val[0], &val[1], &val[2], ascDec);

			}
			run = true;
			break;
		case 5:

			cout << "Input array: ";

			for (int i = 0; i < 5; i++)
				cout << b[i] << " ";

			shrink_array(b, sizeof(b) / sizeof(b[0]));

			cout << endl << "Output array: ";

			for (int i = 0; i < 5; i++)
				cout << b[i] << " ";

			break;
		
		case 6:
			vector_database();
			break;

		default:
			cout << "Sorry, unknown task" << endl;
			break;
		}

		cout << endl << "Enter which task to run (\'-1\' to exit): ";
	}
}