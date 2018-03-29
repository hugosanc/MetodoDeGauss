#include<stdio.h>
#include<stdlib.h>
#include<math.h>

FILE *leitura;

double **ler( char *nome, int *dim)
{	
	int a, i, j;
        double **M;
	leitura = fopen(nome,"r");
	i = fscanf(leitura,"%d",dim);

	M = malloc( *dim *sizeof(double *));
	for( i = 0 ; i < *dim ; i++ )
		M[i] = malloc((*dim+1)*sizeof(double) );
	    
	i = j = 0;

	while ( fscanf(leitura,"%d",&a) != EOF) 
	{
		M[i][j] = a;
		j++;
		if (j == *dim+1) 
		{	j = 0;
			i++;
		}
	}		

	return M;
}

void imprime( double **M, int dim)
{
	int i, j;
	for(i=0;i<dim;i++)
	{
		for(j=0;j<dim+1;j++)
			printf("%3g ",M[i][j]);
			  
		puts("");
	}	
}

void main(int argc, char **argv)
{
	double **L;
	int dim;

	L = ler(argv[1],&dim);
	imprime(L,dim);
   
}
