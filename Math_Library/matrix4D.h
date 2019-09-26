#pragma once
#include <iostream>
#include <cmath>
#include <cstdio>
#include <vector>

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

	// Create a Matrix4D with inserted values.
	Matrix4D(	float x1 = 1, float y1 = 0, float z1 = 0, float w1 = 0,
				float x2 = 0, float y2 = 1, float z2 = 0, float w2 = 0,
				float x3 = 0, float y3 = 0, float z3 = 1, float w3 = 0,
				float x4 = 0, float y4 = 0, float z4 = 0, float w4 = 1) {
		lines[0].set_components(x1, y1, z1, w1);
		lines[1].set_components(x2, y2, z2, w2);
		lines[2].set_components(x3, y3, z3, w3);
		lines[3].set_components(x4, y4, z4, w4);
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
	Vector4D operator[] (int index) const {
		return lines[index];
	}

	// Returns all the values from the Matrix4D
	// in a vector of floats.
	std::vector<float> get_all() {
		std::vector<float> result;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				result.push_back(lines[i][j]);
			}
		}
		return result;
	}

	// -----< Setters >----------------------------------------------------------------------------

	// Set all the values in the matrix.
	void set_components(float x1 = 1, float y1 = 0, float z1 = 0, float w1 = 0,
						float x2 = 0, float y2 = 1, float z2 = 0, float w2 = 0,
						float x3 = 0, float y3 = 0, float z3 = 1, float w3 = 0,
						float x4 = 0, float y4 = 0, float z4 = 0, float w4 = 1) {
		lines[0] = Vector4D(x1, y1, z1, w1);
		lines[1] = Vector4D(x2, y2, z2, w2);
		lines[2] = Vector4D(x3, y3, z3, w3);
		lines[3] = Vector4D(x4, y4, z4, w4); // w4 is 1 (one) by default.
	}

	// -----< Operators >--------------------------------------------------------------------------

	// Operator for multiplication between two Matrix4D.
	Matrix4D operator*(const Matrix4D& m) {
		float	x1, y1, z1, w1,
				x2, y2, z2, w2,
				x3, y3, z3, w3,
				x4, y4, z4, w4;

		x1 = lines[0][0] * m[0][0] + lines[0][1] * m[1][0] + lines[0][2] * m[2][0] + lines[0][3] * m[3][0];
		y1 = lines[0][0] * m[0][1] + lines[0][1] * m[1][1] + lines[0][2] * m[2][1] + lines[0][3] * m[3][1];
		z1 = lines[0][0] * m[0][2] + lines[0][1] * m[1][2] + lines[0][2] * m[2][2] + lines[0][3] * m[3][2];
		w1 = lines[0][0] * m[0][3] + lines[0][1] * m[1][3] + lines[0][2] * m[2][3] + lines[0][3] * m[3][3];

		x2 = lines[1][0] * m[0][0] + lines[1][1] * m[1][0] + lines[1][2] * m[2][0] + lines[1][3] * m[3][0];
		y2 = lines[1][0] * m[0][1] + lines[1][1] * m[1][1] + lines[1][2] * m[2][1] + lines[1][3] * m[3][1];
		z2 = lines[1][0] * m[0][2] + lines[1][1] * m[1][2] + lines[1][2] * m[2][2] + lines[1][3] * m[3][2];
		w2 = lines[1][0] * m[0][3] + lines[1][1] * m[1][3] + lines[1][2] * m[2][3] + lines[1][3] * m[3][3];

		x3 = lines[2][0] * m[0][0] + lines[2][1] * m[1][0] + lines[2][2] * m[2][0] + lines[2][3] * m[3][0];
		y3 = lines[2][0] * m[0][1] + lines[2][1] * m[1][1] + lines[2][2] * m[2][1] + lines[2][3] * m[3][1];
		z3 = lines[2][0] * m[0][2] + lines[2][1] * m[1][2] + lines[2][2] * m[2][2] + lines[2][3] * m[3][2];
		w3 = lines[2][0] * m[0][3] + lines[2][1] * m[1][3] + lines[2][2] * m[2][3] + lines[2][3] * m[3][3];

		x4 = lines[3][0] * m[0][0] + lines[3][1] * m[1][0] + lines[3][2] * m[2][0] + lines[3][3] * m[3][0];
		y4 = lines[3][0] * m[0][1] + lines[3][1] * m[1][1] + lines[3][2] * m[2][1] + lines[3][3] * m[3][1];
		z4 = lines[3][0] * m[0][2] + lines[3][1] * m[1][2] + lines[3][2] * m[2][2] + lines[3][3] * m[3][2];
		w4 = lines[3][0] * m[0][3] + lines[3][1] * m[1][3] + lines[3][2] * m[2][3] + lines[3][3] * m[3][3];


		return Matrix4D(
			x1, y1, z1, w1,
			x2, y2, z2, w2,
			x3, y3, z3, w3,
			x4, y4, z4, w4
		);
	}

	// Operator for copying the values from one matrix to a new one.
	Matrix4D operator=(const Matrix4D& m) {
		Matrix4D new_m;
		new_m[0] = lines[0] = m[0];
		new_m[1] = lines[1] = m[1];
		new_m[2] = lines[2] = m[2];
		new_m[3] = lines[3] = m[3];
		return new_m;
	}

	// Operator for multiplication between a Matrix4D and a Vector4D.
	Vector4D operator*(const Vector4D& v) {
		Vector4D new_v(
			lines[0][0] * v[0] + lines[0][1] * v[1] + lines[0][2] * v[2] + lines[0][3] * v[3],	// x value
			lines[1][0] * v[0] + lines[1][1] * v[1] + lines[1][2] * v[2] + lines[1][3] * v[3],	// y value
			lines[2][0] * v[0] + lines[2][1] * v[1] + lines[2][2] * v[2] + lines[2][3] * v[3],	// z value
			lines[3][0] * v[0] + lines[3][1] * v[1] + lines[3][2] * v[2] + lines[3][3] * v[3]	// w value
		);
		return new_v;
	}

	// -----< Translate >--------------------------------------------------------------------------

	// 1, 0, 0, x
	// 0, 1, 0, y
	// 0, 0, 1, z
	// 0, 0, 0, 1
	void translate(float nx = 0, float ny = 0, float nz = 0) {
		lines[0][3] = nx;
		lines[1][3] = ny;
		lines[2][3] = nz;
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
		det += lines[0][0] * determinant3(lines[1][1], lines[1][2], lines[1][3],
			lines[2][1], lines[2][2], lines[2][3],
			lines[3][1], lines[3][2], lines[3][3]);

		det -= lines[0][1] * determinant3(lines[1][0], lines[1][2], lines[1][3],
			lines[2][0], lines[2][2], lines[2][3],
			lines[3][0], lines[3][2], lines[3][3]);

		det += lines[0][2] * determinant3(lines[1][0], lines[1][1], lines[1][3],
			lines[2][0], lines[2][1], lines[2][3],
			lines[3][0], lines[3][1], lines[3][3]);

		det -= lines[0][3] * determinant3(lines[1][0], lines[1][1], lines[1][2],
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
			inverse_m.set_components(x1, y1, z1, w1,
				x2, y2, z2, w2,
				x3, y3, z3, w3,
				x4, y4, z4, w4);
			// Returns the inverce Matrix4D.
			return inverse_m;
		}
	}

	// -----< Rotation >---------------------------------------------------------------------------

	// Function for returnin a Matrix4D with a 
	// rotation around the x-axis.
	Matrix4D rotate_x(float degrees) {
		// Radians.
		float radians = degrees * (PI / 180);
		// Declare Cos and Sin for simplicity.
		float c = cos(radians), s = sin(radians);
		// The rotation matrix.
		Matrix4D rotation(
			1, 0,  0, 0,
			0, c, -s, 0,
			0, s,  c, 0,
			0, 0,  0, 1
		);
		// Return the rotation matrix.
		return rotation;
	}

	// Function for returnin a Matrix4D with a 
	// rotation around the y-axis.
	Matrix4D rotate_y(float degrees) {
		// Radians.
		float radians = degrees * (PI / 180);
		// Declare Cos and Sin for simplicity.
		float c = cos(radians), s = sin(radians);
		// The rotation matrix.
		Matrix4D rotation(
			 c, 0, s, 0,
			 0, 1, 0, 0,
			-s, 0, c, 0,
			 0, 0, 0, 1
		);
		// Return the rotation matrix.
		return rotation;
	}

	// Function for returnin a Matrix4D with a 
	// rotation around the z-axis.
	Matrix4D rotate_z(float degrees) {
		// Radians.
		float radians = degrees * (PI / 180);
		// Declare Cos and Sin for simplicity.
		float c = cos(radians), s = sin(radians);
		// The rotation matrix.
		Matrix4D rotation(
			c, -s, 0, 0,
			s,  c, 0, 0,
			0,  0, 1, 0,
			0,  0, 0, 1
		);
		return rotation;
	}

	// -----< Print / Debug >----------------------------------------------------------------------

	// Prints the values of the Matrix4D. 
	void print() {
		std::cout << "Line1:\t";
		lines[0].print_line();
		std::cout << "\nLine2:\t";
		lines[1].print_line();
		std::cout << "\nLine3:\t";
		lines[2].print_line();
		std::cout << "\nLine4:\t";
		lines[3].print_line();
		std::cout << "\n\n";
	}
};