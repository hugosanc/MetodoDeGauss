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

double **triangulacao( double **M, int dim)
{
        double l;
        int i,j,k;
        for(j=0;j<dim+1;j++)
        {      
		for(i=0;i<dim;i++)
		{
			if(i>j)
			{
	                	l = M[i][j]/M[j][j];       
                		for(k=0;k<dim+1;k++)
                        		M[i][k] -= l*M[j][k]; 
        		} 
		}
	}       
        return M;
}

void subreversa( double **M, double *x, int dim)
{
	int i,k;
	double sum;

	for( i=dim-1; i>=0; i-- )
	{
		sum=0;
		for( k=i+1; k<dim; k++)
			sum += M[i][k]* x[k];

		x[i] = ( M[i][dim] - sum )/M[i][i];
	}
}	

void main(int argc, char **argv)
{
	double **L, *raiz;
	int dim,i;

	L = ler(argv[1],&dim);
	printf("\nMatriz lida do arquivo\n");
	imprime(L,dim);

	printf("\nTriagulação\n");
        L = triangulacao(L,dim);
        imprime(L,dim);
	
	raiz = malloc( dim* sizeof(double));
	subreversa(L,raiz,dim);
	printf("\nRaizes");
	for( i=0; i<dim; i++)
		printf("\nv[%d]: %g",i,raiz[i]);
	puts(" ");   
}
