
#include <iostream>

#include "matrix4D.h"
#include "vector4D.h"

using namespace std;

int main() {
	Matrix4D test1(1, 2, 3, 4, 5, 6, 7, 8, 9);
	test1.print();
	test1.rotateX(180);
	test1.print();
}
