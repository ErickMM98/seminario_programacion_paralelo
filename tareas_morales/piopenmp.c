#include <stdio.h>
#include <omp.h>
#include <math.h>

//Tarea moral del pseudocódigo para aproximar pi


int main(int argc, char const *argv[]){
	/* code */
	int n;
	//double start_time, final_time;
	long double x,sum,pi,my_pi,delta;

	//Ahorita definimos valores

	n = 100000000000000000;
	delta = 1/(long double)n;
	printf("%.18Lf \n",delta);

	//omp_set_num_threads(10);

	//Integración por el punto medio
	#pragma omp parallel for reduction(+:sum)
		for (int i = 1; i <= n; i++){
			x = delta * (long double)(i - 0.5);
			sum += sqrt(1 - x*x);
		}
	pi = sum * delta * 4.0;
	printf("Pi en parallel for reduction \t %.10Lf \n", pi);

	//Integración por el punto medio
	sum = 0;
	#pragma omp parallel for
		for (int i = 1; i <= n; i++){
			x = delta * (long double)(i - 0.5);
			sum += sqrt(1 - x*x);
		}
	pi = sum * delta * 4.0;
	printf("Pi en parallel for \t\t %.10Lf \n", pi);

	printf("Pi real chido \t\t %.10f \n", M_PI);



	return 0;
}