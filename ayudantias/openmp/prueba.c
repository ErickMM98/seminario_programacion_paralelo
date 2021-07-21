#include <stdio.h>
#include <omp.h>

int main(){
	omp_set_num_threads(10);

	#pragma omp parallel
	{
		//Usar el hilo que llegue primero
		#pragma omp single
		{
			#pragma omp taskwait
			printf("Ahuevooooooooooo");
			printf(" un \n");
			#pragma omp task
			{printf(" bonito \n");}
			#pragma omp task
			{printf(" carro \n");}
		}

	}
	return 0;	
}