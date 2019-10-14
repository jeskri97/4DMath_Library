#pragma once
#include <iostream>
#include <cmath>

class Vector4D {
private:
	float arr_values[4];
public:

	// -----< Constructors >-----------------------------------------------------------------------

	Vector4D(float nx = 0, float ny = 0, float nz = 0, float nw = 1) {
		arr_values[0] = nx;
		arr_values[1] = ny;
		arr_values[2] = nz;
		arr_values[3] = nw; // w is 1 by default. 
	}

	Vector4D(const Vector4D& v) {
		arr_values[0] = v[0];
		arr_values[1] = v[1];
		arr_values[2] = v[2];
		arr_values[3] = v[3];
	}

	// -----< Getters >----------------------------------------------------------------------------

	// Operator that returns the value of the inserted index. 
	float operator[] (int index) const {
		return arr_values[index];
	}
	float& operator[] (int index) {
		return arr_values[index];
	}

	// -----< Setters >----------------------------------------------------------------------------

	// Set the values for all values in the vector.
	void set_components(float nx = 0, float ny = 0, float nz = 0, float nw = 1) {
		arr_values[0] = nx;
		arr_values[1] = ny;
		arr_values[2] = nz;
		arr_values[3] = nw; // w is 1 by default. 
	}

	// -----< Dot Product >------------------------------------------------------------------------

	// Returns the Dot Product as a float.
	float dot_product(Vector4D v) {
		return	arr_values[0] * v[0] +
				arr_values[1] * v[1] +
				arr_values[2] * v[2] +
				arr_values[3] * v[3];
	}

	// -----< Scalar >-----------------------------------------------------------------------------

	// Returns the Scalar vector ar a new Vector4D.
	Vector4D scalar(float s) {
		Vector4D new_v;
		new_v[0] = arr_values[0] * s;
		new_v[1] = arr_values[1] * s;
		new_v[2] = arr_values[2] * s;
		new_v[3] = arr_values[3] * s;
		return new_v;
	}

	// -----< Lenght >-----------------------------------------------------------------------------

	// Returns the Lenght of the Vector4D as a float.
	float lenght() {
		float len;
		// Lenght is the squarroot of ( x^2 + y^2 + z^2 ).
		len = sqrt(	pow(arr_values[0], 2) +
					pow(arr_values[1], 2) +
					pow(arr_values[2], 2) +
					pow(arr_values[3], 2));
		// Returns the lenght of the vector.
		return len;
	}

	// -----< Normalize >--------------------------------------------------------------------------

	// Returns a normalized vector as a Vector4D.
	Vector4D norm() {
		float len, nx, ny, nz, nw;
		// len becomes the lenght of the vector.
		len = lenght();

		nx = arr_values[0] / len;
		ny = arr_values[1] / len;
		nz = arr_values[2] / len;
		nw = arr_values[3] / len;

		return Vector4D(nx, ny, nz, nw);
	}

	// -----< Operators >--------------------------------------------------------------------------

	// Operator for addition between two Vector4D.
	Vector4D operator+(const Vector4D& v) {
		float nx, ny, nz, nw;
		nx = arr_values[0] + v[0];	// x value
		ny = arr_values[1] + v[1];	// y value
		nz = arr_values[2] + v[2];	// z value
		nw = arr_values[3] + v[3];	// w value
		return Vector4D(nx, ny, nz, nw);
	}

	// Operator for subtraction between two Vector4D.
	Vector4D operator-(const Vector4D& v) {
		float nx, ny, nz, nw;
		nx = arr_values[0] - v[0];	// x value
		ny = arr_values[1] - v[1];	// y value
		nz = arr_values[2] - v[2];	// z value
		nw = arr_values[3] - v[3];	// w value
		return Vector4D(nx, ny, nz, nw);
	}

	// Operator for division between two Vector4D.
	Vector4D operator/(const Vector4D& v) {
		float nx, ny, nz, nw;
		nx = arr_values[0] / v[0];	// x value
		ny = arr_values[1] / v[1];	// y value
		nz = arr_values[2] / v[2];	// z value
		nw = arr_values[3] / v[3];	// w value
		return Vector4D(nx, ny, nz, nw);
	}

	// Operator for multiplication between two Vector4D.
	Vector4D operator*(const Vector4D& v) {
		float nx, ny, nz, nw;
		nx = arr_values[0] * v[0];	// x value
		ny = arr_values[1] * v[1];	// y value
		nz = arr_values[2] * v[2];	// z value
		nw = arr_values[3] * v[3];	// w value
		return Vector4D(nx, ny, nz, nw);
	}

	// Operator that gives a vector the same values as another.
	// new_Vector = old_Vector
	Vector4D operator=(const Vector4D& v) {
		float nx, ny, nz, nw;
		nx = arr_values[0] = v[0];	// x value
		ny = arr_values[1] = v[1];	// y value
		nz = arr_values[2] = v[2];	// z value
		nw = arr_values[3] = v[3];	// w value
		return Vector4D(nx, ny, nz, nw);
	}

	// Operators that look if two vectors are the same.
	// vector1 == vector2
	// If true:		returns 1
	// If false:	returns 0
	bool operator==(const Vector4D& v) {
		return (arr_values[0] == v[0] &&
				arr_values[1] == v[1] &&
				arr_values[2] == v[2] &&
				arr_values[3] == v[3]);
	}
	bool operator!=(const Vector4D& v) {
		return !(arr_values[0] == v[0] &&
				 arr_values[1] == v[1] &&
				 arr_values[2] == v[2] &&
				 arr_values[3] == v[3]);
	}

	// -----< Print / Debug >----------------------------------------------------------------------

	// Prints the values of Vector4D in a list.
	void print() {
		std::cout	<< "x:\t" << arr_values[0] << "\n"
					<< "y:\t" << arr_values[1] << "\n"
					<< "z:\t" << arr_values[2] << "\n"
					<< "w:\t" << arr_values[3] << "\n\n";
	}

	// Prints the values of the Vector4D in a line.
	void print_line() {
		std::cout << arr_values[0] << "\t" << arr_values[1] << "\t" << arr_values[2] << "\t" << arr_values[3] << "\n";
	}
};