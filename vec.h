#ifndef _VEC
#define _VEC

#include <iostream>
#include <string>
#include <sstream>
#include <assert.h>


struct vec {

	
	int m, n;

	int * items;

	// ACCESS/MODIFY FIELDS
	friend int getm(const vec & vector);
	friend int getn(const vec & vector);
	
	int getitem(const vec & vector, const int row, const int col);
	void modifitem(vec & vector, const int row, const int col, const int val);

	void scale(vec & vector, const int newM, const int newN);
	
	// DEFAULT CONTSTRUCTOR	
	explicit vec(const int & sm = 1, const int & sn = 1, const int *sitems = nullptr);
			

	//DESTRUCTOR
	~vec();

	// COPY CONSTRUCTORS
	vec(const vec & original);

	// OVERLOADED COPY ASSIGNMENT OPERATOR
	vec & operator= (const vec & other);

	// MOVE CONSTRUCTOR
	vec(vec && other);
	vec & operator= (vec && other);

	// BOOLEAN CHECKERS
	bool operator== (const vec & other);
	bool sumDefined(const vec & a, const vec & b);
	bool multDefined(const vec & a, const vec & b);

	// OVERLOADED +, *, -
	// +
	vec operator+ (const vec & other);
	vec operator+ (const int other);

	// -
	vec operator- (const vec & other);
	vec operator- (const int other);

	// *
	vec operator* (const vec & other);
	vec operator* (const int other);

	// +=
	vec & operator+= (const vec & other);
	vec & operator+= (const int other);

	// -=
	vec & operator-= (const vec & other);
	vec & operator-= (const int other);

	// *=
	vec & operator*= (const vec & other);
	vec & operator*= (const int other);

	// MATRIX METHODS
	vec transpose();
	int det(const vec & vector);	


};


vec operator+ (const int left, const vec & other); // WILL CREATE NEW OBJECT

vec operator* (const int left, const vec & other);

vec operator- (const int left, const vec & other);

vec & operator+= (const int left, const vec & other); // WILL CREATE NEW OBJECT

vec & operator-= (const int left, const vec & other);

vec & operator*= (const int left, const vec & other);

// Reads input, allocates and returns a new vec object.
std::ostream &operator<< (std::ostream &out, const vec & vector);


#endif


