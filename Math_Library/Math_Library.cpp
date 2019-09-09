
#include <iostream>

#include "matrix4D.h"
#include "vector4D.h"

using namespace std;

int main() {
	Matrix4D test1(1, 2, 3, 4, 5, 6, 7, 8, 9), test2;
	float det = test1.determinant();
	cout << "det:\t" << det << "\n";
	test2.print();
	test2 = test1.inverse();
	test2.print();
}
