#pragma once
#include <iostream>
#include <cmath>
#include <cstdio>

#include "vector4D.h"

// Defines the value of PI.
// Used when calculating degrees to radians.
#ifndef PI
#define PI 3.14159265358979323846
#endif

class Matrix4D {
private:
	Vector4D lines[4];

	// Function wich returns the determinant for a Matrix3D.
	float determinant3(	float a, float b, float c,
						float d, float e, float f,
						float g, float h, float i) {
		return a * ((e * i) - (f * h)) - b * ((d * i) - (g * f)) + c * ((d * h) - (e * g));
	}

public:

	// -----< Constructors >-----------------------------------------------------------------------

	// Create an empty Matrix4D.
	Matrix4D() {
		lines[0].set_components(0, 0, 0, 0);
		lines[1].set_components(0, 0, 0, 0);
		lines[2].set_components(0, 0, 0, 0);
		lines[3].set_components(0, 0, 0, 1); // Last value in the last line is 1 by defult.
	}
	// Create a Matrix4D with inserted values.
	Matrix4D(	float x1, float y1, float z1,
				float x2, float y2, float z2,
				float x3, float y3, float z3) {
		lines[0].set_components(x1, y1, z1, 0);
		lines[1].set_components(x2, y2, z2, 0);
		lines[2].set_components(x3, y3, z3, 0);
		lines[3].set_components( 0,  0,  0, 1);
	}
	// Creates a Matrix4D with the same values as another Matrix4D.
	Matrix4D(const Matrix4D& m) {
		lines[0] = m.lines[0];
		lines[1] = m.lines[1];
		lines[2] = m.lines[2];
		lines[3] = m.lines[3];
	}

	// -----< Getters >----------------------------------------------------------------------------

	// Operator for getting the value on an inserted index.
	//
	// lines[line][value on line]
	//
	// ex)	lines[0][0] = x1
	//		lines[2][1] = y3
	Vector4D& operator[] (int index) {
		return lines[index];
	}

	// -----< Setters >----------------------------------------------------------------------------

	// Set all the values in the matrix.
	void set_components(float x1, float y1, float z1, float w1,
						float x2, float y2, float z2, float w2, 
						float x3, float y3, float z3, float w3, 
						float x4, float y4, float z4, float w4 = 1) {
		// w4 is 1 (one) by default.
		lines[0].set_components(x1, y1, z1, w1);
		lines[1].set_components(x2, y2, z2, w2);
		lines[2].set_components(x3, y3, z3, w3);
		lines[3].set_components(x4, y4, z4, w4);
	}

	/*
	// Individual setters for each value in line 1 in the Matrix4D.
	void set_x1(float nx) { lines[0].set_x(nx); }
	void set_y1(float ny) { lines[0].set_y(ny); }
	void set_z1(float nz) { lines[0].set_z(nz); }
	void set_w1(float nw) { lines[0].set_w(nw); }

	// Individual setters for each value in line 2 in the Matrix4D.
	void set_x2(float nx) { lines[1].set_x(nx); }
	void set_y2(float ny) { lines[1].set_y(ny); }
	void set_z2(float nz) { lines[1].set_z(nz); }
	void set_w2(float nw) { lines[1].set_w(nw); }

	// Individual setters for each value in line 3 in the Matrix4D.
	void set_x3(float nx) { lines[2].set_x(nx); }
	void set_y3(float ny) { lines[2].set_y(ny); }
	void set_z3(float nz) { lines[2].set_z(nz); }
	void set_w3(float nw) { lines[2].set_w(nw); }

	// Individual setters for each value in line 4 in the Matrix4D.
	void set_x4(float nx) { lines[3].set_x(nx); }
	void set_y4(float ny) { lines[3].set_y(ny); }
	void set_z4(float nz) { lines[3].set_z(nz); }
	void set_w4(float nw) { lines[3].set_w(nw); }
	*/

	// -----< Operators >--------------------------------------------------------------------------

	// Operator for matrix multiplication.
	Matrix4D operator*(const Matrix4D& m) {
		Matrix4D new_m;
		new_m.lines[0] = lines[0] * m.lines[0];
		new_m.lines[1] = lines[1] * m.lines[1];
		new_m.lines[2] = lines[2] * m.lines[2];
		new_m.lines[3] = lines[3] * m.lines[3];
		return new_m;
	}
	// Operator for copying the values from one matrix to a new one.
	Matrix4D& operator=(const Matrix4D& m) {
		lines[0] = m.lines[0];
		lines[1] = m.lines[1];
		lines[2] = m.lines[2];
		lines[3] = m.lines[3];
		return *this;
	}


	// -----< Transpose >--------------------------------------------------------------------------

	// Returns the Transpose of a Matrix
	void transpose() {
		float	x1, y1, z1, w1,
				x2, y2, z2, w2,
				x3, y3, z3, w3, 
				x4, y4, z4, w4;

		// The values from line 1.
		x1 = lines[0][0];
		y1 = lines[0][1];
		z1 = lines[0][2];
		w1 = lines[0][3];

		// The values from line 2.
		x2 = lines[1][0];
		y2 = lines[1][1];
		z2 = lines[1][2];
		w2 = lines[1][3];

		// The values from line 3.
		x3 = lines[2][0];
		y3 = lines[2][1];
		z3 = lines[2][2];
		w3 = lines[2][3];

		// The values from line 4.
		x4 = lines[3][0];
		y4 = lines[3][1];
		z4 = lines[3][2];
		w4 = lines[3][3];

		// Updates the values in the Matrix4D.
		// Result is the transpose om the original Matrix4D.
		set_components(	x1, x2, x3, x4,
						y1, y2, y3, y4,
						z1, z2, z3, z4,
						w1, w2, w3, w4);
	}

	// -----< Inverse >----------------------------------------------------------------------------

	// Function for returning the determinant of a Matrix4D.
	float determinant() {
		// The determinant start at 0
		float det = 0;

		// The values in the first line multiplicated with
		// the determinant of a Matrix3D made of the values 
		// From the Matrix4D minus the first line and the 
		// columb that the number comes from. 
		det += lines[0][0] * determinant3(	lines[1][1], lines[1][2], lines[1][3],
											lines[2][1], lines[2][2], lines[2][3],
											lines[3][1], lines[3][2], lines[3][3]);

		det -= lines[0][1] * determinant3(	lines[1][0], lines[1][2], lines[1][3],
											lines[2][0], lines[2][2], lines[2][3],
											lines[3][0], lines[3][2], lines[3][3]);

		det += lines[0][2] * determinant3(	lines[1][0], lines[1][1], lines[1][3],
											lines[2][0], lines[2][1], lines[2][3],
											lines[3][0], lines[3][1], lines[3][3]);

		det -= lines[0][3] * determinant3(	lines[1][0], lines[1][1], lines[1][2],
											lines[2][0], lines[2][1], lines[2][2],
											lines[3][0], lines[3][1], lines[3][2]);

		return det;
	}

	// Function for returning (if possible) the inverse of a Matrix4D.
	Matrix4D inverse() {
		float	x1, y1, z1, w1,
				x2, y2, z2, w2,
				x3, y3, z3, w3,
				x4, y4, z4, w4;

		float det = determinant();

		// check if the determinant is 0 (zero).
		if (det == 0) {
			std::cout << "\nError: Determinant = 0\n\n";
		}
		else {
			// Set all the values to be incerted to the inverce Matrix4D.
			// Solution found online 
			// https://www.euclideanspace.com/maths/algebra/matrix/functions/inverse/fourD/index.htm 
			x1 = 1 / det * (lines[1][2] * lines[2][3] * lines[3][1] 
				- lines[1][3] * lines[2][2] * lines[3][1] 
				+ lines[1][3] * lines[2][1] * lines[3][2] 
				- lines[1][1] * lines[2][3] * lines[3][2] 
				- lines[1][2] * lines[2][1] * lines[3][3] 
				+ lines[1][1] * lines[2][2] * lines[3][3]);

			y1 = 1 / det * (lines[0][3] * lines[2][2] * lines[3][1] 
				- lines[0][2] * lines[2][3] * lines[3][1] 
				- lines[0][3] * lines[2][1] * lines[3][2] 
				+ lines[0][1] * lines[2][3] * lines[3][2] 
				+ lines[0][2] * lines[2][1] * lines[3][3] 
				- lines[0][1] * lines[2][2] * lines[3][3]);

			z1 = 1 / det * (lines[0][2] * lines[1][3] * lines[3][1] 
				- lines[0][3] * lines[1][2] * lines[3][1] 
				+ lines[0][3] * lines[1][1] * lines[3][2] 
				- lines[0][1] * lines[1][3] * lines[3][2] 
				- lines[0][2] * lines[1][1] * lines[3][3] 
				+ lines[0][1] * lines[1][2] * lines[3][3]);

			w1 = 1 / det * (lines[0][3] * lines[1][2] * lines[2][1] 
				- lines[0][2] * lines[1][3] * lines[2][1] 
				- lines[0][3] * lines[1][1] * lines[2][2] 
				+ lines[0][1] * lines[1][3] * lines[2][2] 
				+ lines[0][2] * lines[1][1] * lines[2][3] 
				- lines[0][1] * lines[1][2] * lines[2][3]);

			x2 = 1 / det * (lines[1][3] * lines[2][2] * lines[3][0] 
				- lines[1][2] * lines[2][3] * lines[3][0] 
				- lines[1][3] * lines[2][0] * lines[3][2] 
				+ lines[1][0] * lines[2][3] * lines[3][2] 
				+ lines[1][2] * lines[2][0] * lines[3][3] 
				- lines[1][0] * lines[2][2] * lines[3][3]);

			y2 = 1 / det * (lines[0][2] * lines[2][3] * lines[3][0] 
				- lines[0][3] * lines[2][2] * lines[3][0] 
				+ lines[0][3] * lines[2][0] * lines[3][2] 
				- lines[0][0] * lines[2][3] * lines[3][2] 
				- lines[0][2] * lines[2][0] * lines[3][3] 
				+ lines[0][0] * lines[2][2] * lines[3][3]);

			z2 = 1 / det * (lines[0][3] * lines[1][2] * lines[3][0] 
				- lines[0][2] * lines[1][3] * lines[3][0] 
				- lines[0][3] * lines[1][0] * lines[3][2] 
				+ lines[0][0] * lines[1][3] * lines[3][2] 
				+ lines[0][2] * lines[1][0] * lines[3][3] 
				- lines[0][0] * lines[1][2] * lines[3][3]);

			w2 = 1 / det * (lines[0][2] * lines[1][3] * lines[2][0] 
				- lines[0][3] * lines[1][2] * lines[2][0] 
				+ lines[0][3] * lines[1][0] * lines[2][2] 
				- lines[0][0] * lines[1][3] * lines[2][2] 
				- lines[0][2] * lines[1][0] * lines[2][3] 
				+ lines[0][0] * lines[1][2] * lines[2][3]);

			x3 = 1 / det * (lines[1][1] * lines[2][3] * lines[3][0] 
				- lines[1][3] * lines[2][1] * lines[3][0] 
				+ lines[1][3] * lines[2][0] * lines[3][1] 
				- lines[1][0] * lines[2][3] * lines[3][1] 
				- lines[1][1] * lines[2][0] * lines[3][3] 
				+ lines[1][0] * lines[2][1] * lines[3][3]);

			y3 = 1 / det * (lines[0][3] * lines[2][1] * lines[3][0] 
				- lines[0][1] * lines[2][3] * lines[3][0] 
				- lines[0][3] * lines[2][0] * lines[3][1] 
				+ lines[0][0] * lines[2][3] * lines[3][1] 
				+ lines[0][1] * lines[2][0] * lines[3][3] 
				- lines[0][0] * lines[2][1] * lines[3][3]);

			z3 = 1 / det * (lines[0][1] * lines[1][3] * lines[3][0] 
				- lines[0][3] * lines[1][1] * lines[3][0] 
				+ lines[0][3] * lines[1][0] * lines[3][1] 
				- lines[0][0] * lines[1][3] * lines[3][1] 
				- lines[0][1] * lines[1][0] * lines[3][3] 
				+ lines[0][0] * lines[1][1] * lines[3][3]);

			w3 = 1 / det * (lines[0][3] * lines[1][1] * lines[2][0] 
				- lines[0][1] * lines[1][3] * lines[2][0] 
				- lines[0][3] * lines[1][0] * lines[2][1] 
				+ lines[0][0] * lines[1][3] * lines[2][1] 
				+ lines[0][1] * lines[1][0] * lines[2][3] 
				- lines[0][0] * lines[1][1] * lines[2][3]);

			x4 = 1 / det * (lines[1][2] * lines[2][1] * lines[3][0] 
				- lines[1][1] * lines[2][2] * lines[3][0] 
				- lines[1][2] * lines[2][0] * lines[3][1] 
				+ lines[1][0] * lines[2][2] * lines[3][1] 
				+ lines[1][1] * lines[2][0] * lines[3][2] 
				- lines[1][0] * lines[2][1] * lines[3][2]);

			y4 = 1 / det * (lines[0][1] * lines[2][2] * lines[3][0] 
				- lines[0][2] * lines[2][1] * lines[3][0] 
				+ lines[0][2] * lines[2][0] * lines[3][1] 
				- lines[0][0] * lines[2][2] * lines[3][1] 
				- lines[0][1] * lines[2][0] * lines[3][2] 
				+ lines[0][0] * lines[2][1] * lines[3][2]);

			z4 = 1 / det * (lines[0][2] * lines[1][1] * lines[3][0] 
				- lines[0][1] * lines[1][2] * lines[3][0] 
				- lines[0][2] * lines[1][0] * lines[3][1] 
				+ lines[0][0] * lines[1][2] * lines[3][1] 
				+ lines[0][1] * lines[1][0] * lines[3][2] 
				- lines[0][0] * lines[1][1] * lines[3][2]);

			w4 = 1 / det * (lines[0][1] * lines[1][2] * lines[2][0] 
				- lines[0][2] * lines[1][1] * lines[2][0] 
				+ lines[0][2] * lines[1][0] * lines[2][1] 
				- lines[0][0] * lines[1][2] * lines[2][1] 
				- lines[0][1] * lines[1][0] * lines[2][2] 
				+ lines[0][0] * lines[1][1] * lines[2][2]);

			Matrix4D inverse_m;
			// Incert all the values to the inverse Matrix4D.
			inverse_m.set_components(	x1, y1, z1, w1,
										x2, y2, z2, w2,
										x3, y3, z3, w3,
										x4, y4, z4, w4);
			// Returns the inverce Matrix4D.
			return inverse_m;
		}
	}

	// -----< Rotation >---------------------------------------------------------------------------

	// Function for updating the Matrix4D with a 
	// rotation around the x-axis.
	void rotateX(float degrees) {
		// Radians.
		float radians = degrees * (PI / 180);

		// Line 2 and 3 are the only lines thats effected.
		float	x2, y2, z2,
				x3, y3, z3;

		 // Update the values for line 2.
		x2 = lines[1][0];
		y2 = lines[1][1] * cos(radians);
		z2 = lines[1][2] * -sin(radians);

		// Update the values for line 3.
		x3 = lines[2][0];
		y3 = lines[2][1] * sin(radians);
		z3 = lines[2][2] * cos(radians);

		// Update the Matrix4D with the new values.
		lines[0] = lines[0];
		lines[1].set_components(x2, y2, z2);
		lines[2].set_components(x3, y3, z3);
		lines[3] = lines[3];
	}

	// Function for updating the Matrix4D with a 
	// rotation around the y-axis.
	void rotateY(float degrees) {
		// Radians.
		float radians = degrees * (PI / 180);

		// Line 1 and 3 are the only lines thats effected.
		float	x1, y1, z1,
				x3, y3, z3;

		// Update the values for line 1.
		x1 = lines[0][0] * cos(radians);
		y1 = lines[0][1];
		z1 = lines[0][2] * sin(radians);

		// Update the values for line 3.
		x3 = lines[2][0] * -sin(radians);
		y3 = lines[2][1];
		z3 = lines[2][2] * cos(radians);

		// Update the Matrix4D with the new values.
		lines[0].set_components(x1, y1, z1);
		lines[1] = lines[1];
		lines[2].set_components(x3, y3, z3);
		lines[3] = lines[3];
	}

	// Function for updating the Matrix4D with a 
	// rotation around the z-axis.
	void rotateZ(float degrees) {
		// Radians.
		float radians = degrees * (PI / 180);

		// Line 1 and 2 are the only lines thats effected.
		float	x1, y1, z1,
				x2, y2, z2;

		// Update the values for line 1.
		x1 = lines[0][0] * cos(radians);
		y1 = lines[0][1] * -sin(radians);
		z1 = lines[0][2];

		// Update the values for line 2.
		x2 = lines[1][0] * sin(radians);
		y2 = lines[1][1] * cos(radians);
		z2 = lines[1][2];

		// Update the Matrix4D with the new values.
		lines[0].set_components(x1, y1, z1);
		lines[1].set_components(x2, y2, z2);
		lines[2] = lines[2];
		lines[3] = lines[3];
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