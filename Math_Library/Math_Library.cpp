
#include <iostream>

#include "matrix4D.h"
#include "vector4D.h"

using namespace std;

int main() {
	Matrix4D test1(1, 2, 3, 4, 5, 6, 7, 8, 9), test2;
	test1.print();
	test2 = test1.rotateY(180);
	test2.print();
}
