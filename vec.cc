#include <iostream>
#include <string>
#include <sstream>
#include <assert.h>
#include "vec.h"

// Field Getters
int getm(const vec & vector) {
	return vector.m;
}

int getn(const vec & vector) {
	return vector.n;
}



// CONSTRUCTOR O(m*n)
vec::vec(const int & sm, const int & sn, const int * sitems) : m{ sm }, n{ sn } {

	items = new int[sm*sn];

	if (sitems == nullptr) {

		for (int i = 0; i < sm * sn; ++i) {
			items[i] = 0;
		}

	} else {

		for (int i = 0; i < m*n; ++i) {
			items[i] = sitems[i];
		}
	}

}	

// // // // // // // //
// DESTRUCTOR
vec::~vec() {
	
	delete [] items;

}


///////////////////////
// COPY CONSTRUCTOR
vec::vec(const vec & original) {

	m = original.m;
	n = original.n;

	items = new int[m*n];

	if (original.items == nullptr) {

		for (int i = 0; i < m * n; ++i) {
			items[i] = 0;
		}

	} else {

		for (int i = 0; i < m*n; ++i) {
			items[i] = original.items[i];
		}
	}

}

////////////////////////////////////
// COPY ASSIGNMENT OPERATOR

vec & vec::operator= (const vec & other) {

	m = other.m;
	n = other.n;
	
	items = new int[m * n];

	if (other.items == nullptr) {

		for (int i = 0; i < m * n; ++i) {
			items[i] = 0;
		}

	} else {

		for (int i = 0; i < m*n; ++i) {
			items[i] = other.items[i];
		}
	}
	
	return *this;

}

// MOVE CONSTRUCTOR
//
vec::vec(vec && other) : m{other.m}, n{other.n} {
       
	items = new int[m * n];

	for (int i = 0; i < m * n; ++i) {

		items[i] = other.items[i];

	}

	other.m = 0;
	other.n = 0;
	delete [] other.items;
	other.items = nullptr;

}	       

// MOVE ASSIGNMENT OPERATOR
//
vec & vec::operator=(vec && other) {

	if (this != &other) {

		delete [] items;

		m = other.m;
		n = other.n;

		items = new int[m * n];

		for (int i = 0; i < m * n; ++i) {
			items[i] = other.items[i];
		}

		delete [] other.items;
		other.items = nullptr;
		other.m = 0;
		other.n = 0;

	}	

	return *this;

}


/////////////////////////////////////
// BOOLEAN OPERATORS

bool vec::operator== (const vec & other) {

	if (m != other.m || n != other.n) {
		return false;
	}

	for (int i = 0; i < other.m * other.n; ++i) {

		if (items[i] != other.items[i]) { return false;}

	}

	return true;

}

bool vec::sumDefined(const vec & a, const vec & b) { // TWO VECTORS A, B can be added

	if (a.m == b.m && a.n == b.n) {return true;}

	return false;

}

bool vec::multDefined(const vec & a, const vec & b) {

	if (a.n == b.m) {
	       	return true; 
	}

	return false;	

}

///////////////////////////////////
// ARITHMETIC OPERATORS
//
// ASSUMING THAT OPERATION IS POSSIBLE HERE

vec vec::operator+ (const vec & other) {

	vec sum{m, n};

	for (int i = 0; i < m * n; ++i) {

		sum.items[i] = items[i] + other.items[i];

	}

	return sum;

}

vec vec::operator+ (const int other) {

	vec sum{m, n};

	for (int i = 0; i < m * n; ++i) {

		sum.items[i] = items[i] + other;

	}

	return sum;

}

vec vec::operator- (const vec & other) {

	vec diff{m, n};

	for (int i = 0; i < m * n; ++i) {

		diff.items[i] = items[i] - other.items[i];

	}

	return diff;

}

vec vec::operator- (const int other) {

	vec diff{m, n};

	for (int i = 0; i < m * n; ++i) {

		diff.items[i] = items[i] - other;

	}

	return diff;

}

vec & vec::operator+= (const vec & other) {

	for (int i = 0; i < m * n; ++i) {
		items[i] += other.items[i];
	}
	
	return *this;

}

vec & vec::operator+= (const int other) {

	for (int i = 0; i < m * n; ++i) {
		items[i] += other;
	}
	
	return *this;

}

vec & vec::operator-= (const vec & other) {

	for (int i = 0; i < m * n; ++i) {
		items[i] -= other.items[i];
	}
	
	return *this;

}

vec & vec::operator-= (const int other) {

	for (int i = 0; i < m * n; ++i) {
		items[i] -= other;
	}
	
	return *this;

}

///////////////////////////////////////////////
// MATRIX FUNCTIONS

vec vec::transpose() {

	vec a_t{n, m};

	int s = 0;

	for (int j = 0; j < a_t.n; ++j) {
		for (int i = j; i < a_t.m * a_t.n; i += a_t.n) {
			a_t.items[i] = items[s];
			++s;
		}
	}

	return a_t;

}




////////////////////////////////////////////////////////////////////////////////////////////
// STDOUT OPERATOR 
//
// HELPER:

int getDigits(const int n) {

	int bruh = n;
	int count = 1;

	while (bruh / 10 > 0) {

		++count;
		bruh /= 10;
	

	}

	return count;

}

std::ostream &operator<< (std::ostream &out, const vec & vector) {
	
	// FIRST FIND LARGEST DIGITS NUM
	
	int largest = 1;

	for (int i = 0; i < getm(vector) * getn(vector); ++i) {

		const int digits = getDigits(vector.items[i]);
		
		if (digits > largest) {largest = digits;}

	}

	out << "LARGEST " << largest << std::endl; 

	for (int j = 0; j < getm(vector); ++j) {

		out << "[";
	
		for (int i = 0; i <  getn(vector); ++i) {

			const int val = vector.items[j*getn(vector) + i];

			for (int k = 0; k < largest - getDigits(val); ++k) {
				out << " ";
			}
		
			out << val;

			if (i != getn(vector) - 1) {
				out << ",";
			}

		}

		out << "]" << std::endl;

	}

	return out;

}

////////////////////////////////////////////////////////////////////////////////////////
// READ VECTOR FROM INPUT
// ASSUMING CORRECT NUM OF INTS ARE PUT IN
