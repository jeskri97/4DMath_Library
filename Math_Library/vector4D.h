#pragma once
#include <iostream>
#include <cmath>

class Vector4D {
private:
	float arr_values[4];
public:
	// -----< Constructors >---------------------------------------------------
	Vector4D() {
		arr_values[0] = 0;
		arr_values[1] = 0;
		arr_values[2] = 0;
		arr_values[3] = 1;
	}
	Vector4D(float nx, float ny, float nz, float nw = 1) {
		arr_values[0] = nx;
		arr_values[1] = ny;
		arr_values[2] = nz;
		arr_values[3] = nw;
	}

	// -----< Getters >--------------------------------------------------------
	// Returns the value of x in the vector.
	float get_x() { return arr_values[0]; }
	// Returns the value of y in the vector.
	float get_y() { return arr_values[1]; }
	// Returns the value of z in the vector.
	float get_z() { return arr_values[2]; }
	// Returns the value of w in the vector.
	float get_w() { return arr_values[3]; }

	// -----< Setters >--------------------------------------------------------
	// Set the values for all values in the vector.
	void set_components(float nx, float ny, float nz, float nw = 1) {
		arr_values[0] = nx;
		arr_values[1] = ny;
		arr_values[2] = nz;
		arr_values[3] = nw;
	}
	// Set the value of x in the vector.
	void set_x(float nx) { arr_values[0] = nx; }
	// Set the value of y in the vector.
	void set_y(float ny) { arr_values[1] = ny; }
	// Set the value of z in the vector.
	void set_z(float nz) { arr_values[2] = nz; }
	// Set the value of w in the vector.
	void set_w(float nw) { arr_values[3] = nw; }

	// -----< Dot Product >----------------------------------------------------
	float dot_product(Vector4D v) {
		return	arr_values[0] * v.arr_values[0] +
				arr_values[1] * v.arr_values[1] +
				arr_values[2] * v.arr_values[2];
	}

	// -----< Scalar >---------------------------------------------------------
	Vector4D scalar(float s) {
		Vector4D new_v;
		new_v.arr_values[0] = arr_values[0] * s;
		new_v.arr_values[1] = arr_values[1] * s;
		new_v.arr_values[2] = arr_values[2] * s;
		//new_v.arr_values[3] = arr_values[3] * s;
		return new_v;
	}

	// -----< Lenght >---------------------------------------------------------
	float lenght() {
		float len;
		len = sqrt(	pow(arr_values[0], 2) +
					pow(arr_values[1], 2) +
					pow(arr_values[2], 2));
		return len;
	}

	// -----< Normalize >------------------------------------------------------
	Vector4D norm() {
		float len, nx, ny, nz;
		// len becomes the lenght of the vector.
		len = lenght();

		nx = arr_values[0] / len;
		ny = arr_values[1] / len;
		nz = arr_values[2] / len;

		Vector4D v(nx, ny, nz);
		return v;
	}

	// -----< Operators >------------------------------------------------------
	// Operators that makes it possible to use addition, subtraction,
	// multiplication and division on the Vector.
	Vector4D operator+(const Vector4D& v) {
		float nx, ny, nz;
		nx = arr_values[0] + v.arr_values[0];
		ny = arr_values[1] + v.arr_values[1];
		nz = arr_values[2] + v.arr_values[2];
		Vector4D new_v(nx, ny, nz);
		return new_v;
	}
	Vector4D operator-(const Vector4D& v) {
		float nx, ny, nz;
		nx = arr_values[0] - v.arr_values[0];
		ny = arr_values[1] - v.arr_values[1];
		nz = arr_values[2] - v.arr_values[2];
		Vector4D new_v(nx, ny, nz);
		return new_v;
	}
	Vector4D operator/(const Vector4D& v) {
		float nx, ny, nz;
		nx = arr_values[0] / v.arr_values[0];
		ny = arr_values[1] / v.arr_values[1];
		nz = arr_values[2] / v.arr_values[2];
		Vector4D new_v(nx, ny, nz);
		return new_v;
	}
	Vector4D operator*(const Vector4D& v) {
		float nx, ny, nz;
		nx = arr_values[0] * v.arr_values[0];
		ny = arr_values[1] * v.arr_values[1];
		nz = arr_values[2] * v.arr_values[2];
		Vector4D new_v(nx, ny, nz);
		return new_v;
	}

	// Operator that gives a vector the same values as another.
	// new_Vector = old_Vector
	Vector4D& operator=(const Vector4D& v) {
		arr_values[0] = v.arr_values[0];
		arr_values[1] = v.arr_values[1];
		arr_values[2] = v.arr_values[2];
		return *this;
	}

	// Operators that look if two vectors are the same.
	// vector1 == vector2
	// If true:		returns 1
	// If false:	returns 0
	bool operator==(const Vector4D& v) {
		return (arr_values[0] == v.arr_values[0] &&
				arr_values[1] == v.arr_values[1] &&
				arr_values[2] == v.arr_values[2]);
	}
	bool operator==(const Vector4D& v) {
		return !(arr_values[0] == v.arr_values[0] &&
				 arr_values[1] == v.arr_values[1] &&
				 arr_values[2] == v.arr_values[2]);
	}

	// Prints the values of Vector.
	void print() {
		std::cout	<< "x:\t"		<< arr_values[0] << "\n"
					<< "y:\t"		<< arr_values[1] << "\n"
					<< "z:\t"		<< arr_values[2] << "\n"
					<< "w:\t"		<< arr_values[3] << "\n\n";
	}
};