/* Contoh Program Dalam C++ */

#include <iostream>
#include <cmath>
#include <cfenv>
#include <conio.h>

#pragma STDC FENV_ACCESS ON

/*	Source by Programiz
*	Modified for Learn by Rizky Khapidsyah
*/

using namespace std;

void print_exceptions() {
	cout << "Raised exceptions: ";

	if (fetestexcept(FE_ALL_EXCEPT)) {
		if (fetestexcept(FE_DIVBYZERO)) {
			cout << "FE_DIVBYZERO ";
		}
			
		if (fetestexcept(FE_INEXACT)) {
			cout << "FE_INEXACT ";
		}
			
		if (fetestexcept(FE_INVALID)) {
			cout << "FE_INVALID ";
		}
			
		if (fetestexcept(FE_OVERFLOW)) {
			cout << "FE_OVERFLOW ";
		}
			
		if (fetestexcept(FE_UNDERFLOW)) {
			cout << "FE_UNDERFLOW ";
		}
	} else {
		cout << "None";
	}
		
	cout << endl;
}

void print_current_rounding_direction() {
	cout << "Current rounding method: ";

	switch (fegetround()) {
	case FE_TONEAREST:
		cout << "FE_TONEAREST";
		break;
	case FE_DOWNWARD:
		cout << "FE_DOWNWARD";
		break;
	case FE_UPWARD:
		cout << "FE_UPWARD";
		break;
	case FE_TOWARDZERO:
		cout << "FE_TOWARDZERO";
		break;
	default:
		cout << "unknown";
	};
	
	cout << endl;
}

void print_environment() {
	print_exceptions();
	print_current_rounding_direction();
}

int main(void) {
	cout << "Initial environment " << endl;
	print_environment();
	fenv_t envp;

	/* Save current environment */
	fegetenv(&envp);
	feraiseexcept(FE_INVALID | FE_DIVBYZERO);
	fesetround(FE_DOWNWARD);
	cout << "After changing environment " << endl;
	print_environment();

	/* Restores previous environment */
	fesetenv(&envp);
	cout << "Restoring initial environment " << endl;
	print_environment();
	
	_getch();
	return 0;
}