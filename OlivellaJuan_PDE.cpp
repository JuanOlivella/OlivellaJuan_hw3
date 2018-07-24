// Solucion de los ejercicios por medio del método de diferencias finitas


#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <math.h>


using namespace std;


// Define las constantes importantes para el ejercicio


#define C 300.0
#define L 1.0


int main()
{


	// Declara los parametros iniciales del problema para x


	float deltax = 0.01;

	float maxx = L/2.0;

	float minx = (-1)*(L/2.0);

	int puntosx = (maxx-minx)/(deltax);

	float x[puntosx];

	x[0] = minx;

	for (int a = 1; a < puntosx; a++)
	{

	x[a] = x[a-1] + deltax;

	}


	// Declara los parametros iniciales del problema para y


	float deltay = 0.01;

	float maxy = L/2.0;

	float miny = (-1)*(L/2.0);

	int puntosy = (maxy-miny)/(deltay);

	float y[puntosy];

	y[0] = miny;

	for (int b = 1; b < puntosy; b++)
	{

	y[b] = y[b-1] + deltay;

	}


	// Declara los parametros iniciales del problema para t

	
	float deltat = (deltax)/(C*1.5);

	float maxt = 0.6;

	float mint = 0;

	int puntost = (maxt-mint)/(deltat);

	int tt = 26500;


	// Declara los arreglos del ejercicio para bordes fijos


	float phi_pasado[puntosx][puntosy];

 	float phi_pasado2[puntosx][puntosy];

	float phi_presente[puntosx][puntosy];

	float phi_futuro[puntosx][puntosy];

	
	float r = pow((deltat/(deltax*deltay)),2);


	// Declara las condiciones de frontera para el caso de los bordes fijos


	for (int d = 0; d < puntosx; d++)
	{
		for (int e = 0; e < puntosy; e++)
		{

			phi_futuro[0][e] = 0;

			phi_futuro[puntosx-1][e] = 0;

			phi_futuro[d][0] = 0;

			phi_futuro[d][puntosy-1] = 0;

		}

	}


	// Iniciativa los pasos para la solución de la ecuación diferencial parcial


	int total = puntosx*puntosy;

	int contador = 0;

	ifstream file;

	file.open("init.dat"); 

	float data[total];

	for(int i = 0; i < total; i++)
	{
		file >> data[i];
	}

	file.close();


	ofstream myfile ("inicial.dat");
	myfile.is_open();
	
	
	for (int i = 0; i < puntosx; i++)
	{

		for (int j = 0; j < puntosy; j++)
		{

			phi_pasado[i][j] = data[contador];
			phi_pasado2[i][j] = data[contador];
			contador = contador +1;
			myfile << x[i] << "  " << y[j] << "  " << phi_pasado[i][j] << "\n";
			

		}

	}
	myfile.close();

	


	for (int g = 1; g < puntosx-1; g++)
	{

		for (int h = 1; h < puntosy-1; h++)
		{

			phi_presente[g][h] = ((r)*(((deltay*deltay)*(phi_pasado[g+1][h]-2*phi_pasado[g][h]+phi_pasado[g-1][h]))+((deltax*deltax)*(phi_pasado[g][h+1]-2*phi_pasado[g][h]+phi_pasado[g][h-1])))+(2.0)*phi_pasado[g][h])/(2.0);

		}

	}

	ofstream myfil ("60.dat");
        myfil.is_open();
	ofstream myfi ("corte.dat");
        myfi.is_open();
	
	for (int f = 0; f < puntost; f++)
	{

		for (int g = 1; g < puntosx-1; g++)
		{

			for (int h = 1; h < puntosy-1; h++)
			{

				phi_futuro[g][h] = (r)*(((deltay*deltay)*(phi_pasado[g+1][h]-2*phi_pasado[g][h]+phi_pasado[g-1][h]))+((deltax*deltax)*(phi_pasado[g][h+1]-2*phi_pasado[g][h]+phi_pasado[g][h-1])))+(2)*phi_presente[g][h] - phi_pasado[g][h];

			}


		}

		for (int o = 0; o < puntosx; o++)
		{

			for (int p = 0; p < puntosy; p++)
			{
				
				phi_pasado[o][p] = phi_presente[o][p];

				phi_presente[o][p] = phi_futuro[o][p];

				if(f==tt)
				  {

				    myfil << x[o] << "  " << y[p] << "  " << phi_pasado[o][p] <<  "\n";

				  }
 
			}


		}

      		for (int o = 0; o < puntosx; o++)
		{

		         for (int p = 0; p < puntosy; p++)
		         {
				

			        if(f%1500 == 0  && o == (puntosx/2))
				{

				     myfi  << y[p] << "  " << phi_pasado[o][p] <<  "\n";

				}
 
			  }


		}
		

	}

	myfil.close();

	myfi.close();


	// Declara los arreglos del ejercicio para bordes fijos

	

	float phi_presente2[puntosx][puntosy];

	float phi_futuro2[puntosx][puntosy];

	
	ofstream myf ("inicial2.dat");
	
	myf.is_open();
		
	
	for (int i = 0; i < puntosx; i++)
	{

		for (int j = 0; j < puntosy; j++)
		{

			phi_presente2[i][j] = phi_pasado2[i][j];
			
			myf << x[i] << "  " << y[j] << "  " << phi_pasado2[i][j] << "\n";	

		}

	}
	myf.close();


	

	for (int g = 1; g < puntosx-1; g++)
	{

		for (int h = 1; h < puntosy-1; h++)
		{
		  
			
			phi_presente2[g][h] = ((r)*(((deltay*deltay)*(phi_pasado2[g+1][h]-2*phi_pasado2[g][h]+phi_pasado2[g-1][h]))+((deltax*deltax)*(phi_pasado2[g][h+1]-2*phi_pasado2[g][h]+phi_pasado2[g][h-1])))+(2.0)*phi_pasado2[g][h])/(2.0);

		}

	}


	ofstream my ("602.dat");
        my.is_open();
	ofstream m ("corte2.dat");
        m.is_open();
	
	for (int f = 0; f < puntost; f++)
	{
	

		for (int g = 1; g < puntosx-1; g++)
		{

			for (int h = 1; h < puntosy-1; h++)
			{
			  

				phi_futuro2[g][h] = (r)*(((deltay*deltay)*(phi_pasado2[g+1][h]-2*phi_pasado2[g][h]+phi_pasado2[g-1][h]))+((deltax*deltax)*(phi_pasado2[g][h+1]-2*phi_pasado2[g][h]+phi_pasado2[g][h-1])))+(2)*phi_presente2[g][h] - phi_pasado2[g][h];


				
			}


		}

		// Condicion de frontera para los bordes abiertos

		
	for (int d = 0; d < puntosx; d++)
	{
		for (int e = 0; e < puntosy; e++)
		{

			phi_futuro2[0][e] = phi_futuro2[1][e];

			phi_futuro2[puntosx-1][e] = phi_futuro2[puntosx-2][e];

			phi_futuro2[d][0] = phi_futuro2[d][1];

			phi_futuro2[d][puntosy-1] = phi_futuro2[d][puntosy-2];

		}

	}


		for (int o = 0; o < puntosx; o++)
		{

			for (int p = 0; p < puntosy; p++)
			{

			  if(f==tt)
			  {

			   my << x[o] << "  " << y[p] << "  " << phi_pasado2[o][p] <<  "\n";

			  }
			  	  phi_pasado2[o][p] = phi_presente2[o][p];

				  phi_presente2[o][p] = phi_futuro2[o][p];
				  
				  	



 
			}


		}


	
      		for (int o = 0; o < puntosx; o++)
		{

		         for (int p = 0; p < puntosy; p++)
		         {
				

			        if(f%1500 == 0  && o == (puntosx/2))
				{

				     m  << y[p] << "  " << phi_pasado2[o][p] <<  "\n";

				}
 
			  }


		}
		

	}

	my.close();

	m.close();






	
	return 0;

}
