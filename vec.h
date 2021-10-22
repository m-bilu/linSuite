#ifndef _VEC
#define _VEC

#include <iostream>
#include <string>
#include <sstream>
#include <assert.h>


class vec {

	
	int m, n;
	
	public:

	int * items;

	// ACCESS/MODIFY FIELDS
	friend int getm(const vec & vector);
	friend int getn(const vec & vector);
	
	int getitem(const vec & vector, const int row, const int col);
	void modifitem(vec & vector, const int row, const int col, const int val);

	void scale(vec & vector, const int newM, const int newN);
	
	// DEFAULT CONTSTRUCTORS
	explicit vec();
	explicit vec(const int & sm, const int & sn, const int *sitems = nullptr);
			

	//DESTRUCTOR
	~vec();

	// COPY CONSTRUCTORS
	vec(const vec & original);

	// OVERLOADED COPY ASSIGNMENT OPERATOR
	vec & operator= (const vec & other);

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
	vec transpose(const vec & vector);
	int det(const vec & vector);	


};


vec operator+ (const int left, const vec & other); // WILL CREATE NEW OBJECT

vec operator* (const int left, const vec & other);

vec operator- (const int left, const vec & other);

vec & operator+= (const int left, const vec & other); // WILL CREATE NEW OBJECT

vec & operator-= (const int left, const vec & other);

vec & operator*= (const int left, const vec & other);

// Reads input, allocates and returns a new vec object.
vec readVec(const int m, const int n);

std::ostream &operator<< (std::ostream &out, const vec & vector);


#endif


