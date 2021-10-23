#include "vec.h"
#include <iostream>


using namespace std;

int main() {

	int bruh[6] = { 1, 2, 3, 4, 5, 6 };
	vec v{3, 2, bruh};
	vec w{ v };
	vec z = w;
	cout << v << endl;
	cout << "Copy: " << endl << w << endl;
	cout << "Assigned: " << endl << z << endl;

	vec v_t = v.transpose();

	cout << "Transposed: " << endl << v_t << endl;

	vec sum = v + w;

	cout << "Sum: " << endl << sum << endl;

}

