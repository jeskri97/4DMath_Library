#pragma once
#include <iostream>
#include <cmath>
#include <cstdio>

#include "vector4D.h"

#ifndef PI
#define PI 3.14159265358979323846
#endif

class Matrix4D {
private:
	Vector4D line1, line2, line3, line4;
public:
	// -----< Constructors >---------------------------------------------------
	Matrix4D() {
		line1.set_components(0, 0, 0, 0);
		line2.set_components(0, 0, 0, 0);
		line3.set_components(0, 0, 0, 0);
		line4.set_components(0, 0, 0, 1);
	}
	Matrix4D(	float x1, float y1, float z1,
				float x2, float y2, float z2,
				float x3, float y3, float z3) {
		line1.set_components(x1, y1, z1, 0);
		line2.set_components(x2, y2, z2, 0);
		line3.set_components(x3, y3, z3, 0);
		line4.set_components( 0,  0,  0, 1);
	}
	Matrix4D(const Matrix4D& m) {
		line1 = m.line1;
		line2 = m.line2;
		line3 = m.line3;
		line4 = m.line4;
	}

	// -----< Getters >--------------------------------------------------------
	// Returns line1
	Vector4D get_line1() { return line1; }
	// Returns line2
	Vector4D get_line2() { return line2; }
	// Returns line3
	Vector4D get_line3() { return line3; }
	// Returns line4
	Vector4D get_line4() { return line4; }


};