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
	Vector4D lines[4];
public:
	// -----< Constructors >---------------------------------------------------
	Matrix4D() {
		lines[0].set_components(0, 0, 0, 0);
		lines[1].set_components(0, 0, 0, 0);
		lines[2].set_components(0, 0, 0, 0);
		lines[3].set_components(0, 0, 0, 1);
	}
	Matrix4D(	float x1, float y1, float z1,
				float x2, float y2, float z2,
				float x3, float y3, float z3) {
		lines[0].set_components(x1, y1, z1, 0);
		lines[1].set_components(x2, y2, z2, 0);
		lines[2].set_components(x3, y3, z3, 0);
		lines[3].set_components( 0,  0,  0, 1);
	}
	Matrix4D(const Matrix4D& m) {
		lines[0] = m.lines[0];
		lines[1] = m.lines[1];
		lines[2] = m.lines[2];
		lines[3] = m.lines[3];
	}

	// -----< Getters >--------------------------------------------------------

	Vector4D& operator[] (int index) {
		return lines[index];
	}

	// -----< Setters >--------------------------------------------------------
	// Set all the values in the matrix.
	void set_components(float x1, float y1, float z1, float w1,
						float x2, float y2, float z2, float w2, 
						float x3, float y3, float z3, float w3, 
						float x4, float y4, float z4, float w4 = 1) {
		lines[0].set_components(x1, y1, z1, w1);
		lines[1].set_components(x2, y2, z2, w2);
		lines[2].set_components(x3, y3, z3, w3);
		lines[3].set_components(x4, y4, z4, w4);
	}

	// Individual setters for each value in the matrix.
	void set_x1(float nx) { lines[0].set_x(nx); }
	void set_y1(float ny) { lines[0].set_y(ny); }
	void set_z1(float nz) { lines[0].set_z(nz); }
	void set_w1(float nw) { lines[0].set_w(nw); }

	void set_x2(float nx) { lines[1].set_x(nx); }
	void set_y2(float ny) { lines[1].set_y(ny); }
	void set_z2(float nz) { lines[1].set_z(nz); }
	void set_w2(float nw) { lines[1].set_w(nw); }

	void set_x3(float nx) { lines[2].set_x(nx); }
	void set_y3(float ny) { lines[2].set_y(ny); }
	void set_z3(float nz) { lines[2].set_z(nz); }
	void set_w3(float nw) { lines[2].set_w(nw); }

	void set_x4(float nx) { lines[3].set_x(nx); }
	void set_y4(float ny) { lines[3].set_y(ny); }
	void set_z4(float nz) { lines[3].set_z(nz); }
	void set_w4(float nw) { lines[3].set_w(nw); }

	// -----< Operators >------------------------------------------------------
	Matrix4D operator*(const Matrix4D& m) {
		Matrix4D new_m;
		new_m.lines[0] = lines[0] * m.lines[0];
		new_m.lines[1] = lines[1] * m.lines[1];
		new_m.lines[2] = lines[2] * m.lines[2];
		new_m.lines[3] = lines[3] * m.lines[3];
		return new_m;
	}
	Matrix4D& operator=(const Matrix4D& m) {
		lines[0] = m.lines[0];
		lines[1] = m.lines[1];
		lines[2] = m.lines[2];
		lines[3] = m.lines[3];
		return *this;
	}


	// -----< Transpose >------------------------------------------------------
	// Returns the Transpose of a Matrix
	Matrix4D transpose() {
		Matrix4D new_m;
		float	x1, y1, z1,
			x2, y2, z2,
			x3, y3, z3;

		x1 = lines[0][0];
		y1 = lines[0][1];
		z1 = lines[0][2];

		x2 = lines[1][0];
		y2 = lines[1][1];
		z2 = lines[1][2];

		x3 = lines[2][0];
		y3 = lines[2][1];
		z3 = lines[2][2];

		new_m.lines[0].set_components(x1, x2, x3);
		new_m.lines[1].set_components(y1, y2, y3);
		new_m.lines[2].set_components(z1, z2, z3);

		return new_m;
	}

	// -----< Rotation >-------------------------------------------------------
	// Rotation around the x-axis
	Matrix4D rotateX(float degrees) {
		float radians = degrees * (PI / 180);
		Matrix4D rotated_m;
		float	x2, y2, z2,
			x3, y3, z3;

		x2 = lines[1][0];
		y2 = lines[1][1] * cos(radians);
		z2 = lines[1][2] * -sin(radians);

		x3 = lines[2][0];
		y3 = lines[2][1] * sin(radians);
		z3 = lines[2][2] * cos(radians);

		rotated_m.lines[0] = lines[0];
		rotated_m.lines[1].set_components(x2, y2, z2);
		rotated_m.lines[2].set_components(x3, y3, z3);
		rotated_m.lines[3] = lines[3];

		return rotated_m;
	}
	// Rotation around the y-axis
	Matrix4D rotateY(float degrees) {
		float radians = degrees * (PI / 180);
		Matrix4D rotated_m;
		float	x1, y1, z1,
			x3, y3, z3;

		x1 = lines[0][0] * cos(radians);
		y1 = lines[0][1];
		z1 = lines[0][2] * sin(radians);

		x3 = lines[2][0] * -sin(radians);
		y3 = lines[2][1];
		z3 = lines[2][2] * cos(radians);

		rotated_m.lines[0].set_components(x1, y1, z1);
		rotated_m.lines[1] = lines[1];
		rotated_m.lines[2].set_components(x3, y3, z3);
		rotated_m.lines[3] = lines[3];

		return rotated_m;
	}
	// Rotation around the z-axis
	Matrix4D rotateZ(float degrees) {
		float radians = degrees * (PI / 180);
		Matrix4D rotated_m;
		float	x1, y1, z1,
			x2, y2, z2;

		x1 = lines[0][0] * cos(radians);
		y1 = lines[0][1] * -sin(radians);
		z1 = lines[0][2];

		x2 = lines[1][0] * sin(radians);
		y2 = lines[1][1] * cos(radians);
		z2 = lines[1][2];

		rotated_m.lines[0].set_components(x1, y1, z1);
		rotated_m.lines[1].set_components(x2, y2, z2);
		rotated_m.lines[2] = lines[2];
		rotated_m.lines[3] = lines[3];

		return rotated_m;
	}

	void print() {
		std::cout << "Line1:\t";
		lines[0].print_line();
		std::cout << "\nLine2:\t";
		lines[1].print_line();
		std::cout << "\nLine3:\t";
		lines[2].print_line();
		std::cout << "\nLine4:\t";
		lines[3].print_line();
		std::cout << "\n";
	}
};