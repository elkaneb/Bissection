#include <stdio.h>
#include <stdlib.h>

// Définition de la fonction f
double f(double x) {
	return x*x - 5;
}

// Définition de la fonction f'
double _f(double x) {
	return 2*x;
}

// Définition de la fonction valeur absolute
double valabs(double val) {
	return val > 0 ? val : (val * -1);
}

// Dérivée 1 de la fonction f en un point par approximation
double Deriv1(double p) {
	double h = 1e-10; // h = 0.0000000001
	return (f(p + h) - f(p - h))/(2*h);
}

// Dérivée 2 de la fonction f en un point par approximation
double Deriv2(double p) {
	double h = 1e-10; // h = 0.0000000001
	return (_f(p + h) - _f(p - h))/(2*h);
}

// Algorithme de bissection
void bissection(double a, double b) {
	double EPSILON = 1e-10; //0.00001;
    double c;
    int itercount = 0;
    
    while(valabs(a - b) > EPSILON) {
    	c = (a + b)/2;
    	
    	if(Deriv1(c) <= 0) {
    		
    		if(Deriv1(c) == 0 && Deriv2(c) > 0) {
    			printf("min : %f \n", c);
    			break;
			} else if(Deriv2(c) < 0) {
				printf("max : %f \n", c);
				break;
			} else {
				a = c;	
			}
			
		}else {
			b = c;
		}
		
		itercount++;
	}
	
	printf("Le nombre d'iterations: %d\n", itercount);
	printf("[a b] [%f %f] \n", a,b);
	printf("c = %f \n", c);    
}

// Fonction principale
int main() {
	// Initialisation des variables a et b
	double a,b;
	
	printf("Tapez [a,b]\n");
	printf("a = ");
	scanf("%lf", &a);
	
	printf("b = ");
	scanf("%lf", &b);
	
	// Méthode de la Bissection
	bissection(a,b);
	
	return 0;
}
