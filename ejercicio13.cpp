#include<iostream>

using namespace std;

void productoM(double **n,double **m , double **r, int N)
{
	
 for (int k = 0;k<N;k++)
 {
	
    for(int i = 0; i<N; i++)
    {
	double suma = 0.00;
		
		for(int j = 0; j < N; j++)
		{
            suma = suma + m[k][j]*n[j][i];
		}
	r[k][i] = suma;
    }
 }
}

void imprime(int l,double **m)
{
    for (int j = 0; j<l; j++)
    {
        for ( int i = 0; i<l; i++)
        {
            cout<<" "<<m[i][j]<<" ";
        }
        cout<<endl;
    }
}

void relleno(int l,int **m)
{
    for(int i = 0; i<l; i++)
    {
        for(int j = 0; j < l; j++)
        {
            m[i][j] = i + j;
        }  
    }
}


void nilpoten(int l,double **m)
{
    for(int i = 0; i<l; i++)
    {
        for(int j = 0; j < l; j++)
        {
			if( i == 0 && j != l-1)
			{
				m[j][i] = 2;
			}
			else if(i == 0 && j == l-1)
			{
				m[j][i] = 1-l;
			}
			else if(i != 0 && j == l-1)
			{
				m[j][i] = -l;
			}
			else if(j+1 == i )
			{
				m[j][i] = l+2;
			}
			else
			{
			m[j][i] = 1;	
			}
        }  
    }
}


void cauchy(int l,double **m)
{
    for(int i = 0; i<l; i++)
    {
        for(int j = 0; j < l; j++)
        {
            m[i][j] = 1.000/((i+1) + (j+1)-1); //i,j de 1 en adelante
        }  
    }
}

int main()
{
    cout<<"Escriba la longitud de la Matriz N*N"<<endl;
    int l=0;
    cin>>l;
	
    double ** matriz = new double *[l];
	
    for (int i = 0; i < l; i++)
    {
        matriz[i] = new double[l];
    }
	
	double ** matriz1 = new double *[l];
	
    for (int i = 0; i < l; i++)
    {
        matriz1[i] = new double[l];
    }
	
	 double ** matriz2 = new double *[l];
	
    for (int i = 0; i < l; i++)
    {
        matriz2[i] = new double[l];
    }
	
		//relleno(l,matriz);
	nilpoten(l,matriz);
	cout<<"Primera Matriz Nilpotent"<<endl;
	imprime(l,matriz);
	//relleno(l,matriz1);
	nilpoten(l,matriz1);
	cout<<"Segunda Matriz Nipotent"<<endl;
	imprime(l,matriz1);
    productoM(matriz,matriz1,matriz2,l);
    cout<<"Resultado del producto matricial Nilpotent"<<endl;
	imprime(l,matriz2);
	
	cout.precision(16);
    cout.setf(std::ios::scientific);
	cauchy(l,matriz);
	cout<<"Primera Matriz Cauchy"<<endl;
	imprime(l,matriz);
	//relleno(l,matriz1);
	cauchy(l,matriz1);
	cout<<"Segunda Matriz Cauchy"<<endl;
	imprime(l,matriz1);
    productoM(matriz,matriz1,matriz2,l);
    cout<<"Resultado del producto matricial Cauchy"<<endl;
	imprime(l,matriz2);
	
    
    return 0;
}



