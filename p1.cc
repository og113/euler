/* project euler problem 1
find the sum of all multiples of 3 or 5 below 1000
or the generalization, find the sum of all the multiples of a and b below N
where a<b<N
input arguments via argv to change a, b and N from 3, 5 and 1000
*/
#include <cstdlib>
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main(int argc, char** argv)
{
/*--------------------------------------------------------------------------------------
defining main parameters
	allowing user input via argv
--------------------------------------------------------------------------------------*/
unsigned int a=3, b=5, N=1000, result = 0;
if (argc>1){
	a = atoi(argv[1]);
	b = atoi(argv[2]);
	N = atoi(argv[3]);
}
if (a>b){
	int temp = a;
	a = b;
	b = temp;
}
cout << "N = " << N << ", a = " << a << ", b = " << b << endl;
if (N<a || N<b){
	cout << "must have N>a and N>b" << endl;
	return 1;
}

/*--------------------------------------------------------------------------------------
calculating result
	printing sum if not too long
--------------------------------------------------------------------------------------*/
bool print = true;
if (N>1e4*b) print = false;
unsigned int p = (int)(N/a), q = (int)(N/b), r = 0, s = 0, t, u;
if (p*a==N) r=1;
if (q*b==N) s=1;
if (print) cout << "sum: ";
for (unsigned int j=1; j<=(p-r); j++){
	t = j*a;
	u = j*b;
	if (print) cout << t << " ";
	result += t;
	if (u%a!=0 && j<=(q-s)){
		if (print) cout << u << " ";
		result += u;
	}
}
if (print) cout << endl;

/*--------------------------------------------------------------------------------------
printing result
--------------------------------------------------------------------------------------*/
cout << "result = " << result << endl;
	
return 0;
}
