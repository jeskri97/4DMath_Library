
#include <iostream>

#include "matrix4D.h"
#include "vector4D.h"

using namespace std;

int main() {
	Vector4D test1(1, 2, 3), test2;
	test1.print();
	test2 = test1.norm();
	test2.print();
	//float dot_ptr = test1.dot_product(test2);
	//cout << "Dotproduct of test1 test2:\t" << dot_ptr;
}
