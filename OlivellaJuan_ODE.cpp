// Solucion de los ejercicios por medio del método numérico de Leap Frog


#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <math.h>


// Define las constantes importantes para el ejercicio


#define M 2.5
#define Q 1.5
#define BX 0.0
#define BY 0.0
#define BZ 3.0



using std::cout;
using std::endl;
using std::abs;
using std::ofstream;


// Declara las funciones necesarias para la resolucion del ejercicio


float velocidadenx(float vvx, float vvy, float vvz);


float velocidadeny(float vvx, float vvy, float vvz);


float velocidadenz(float vvx, float vvy, float vvz);


float aceleracionenx(float vvx, float vvy, float vvz);


float aceleracioneny(float vvx, float vvy, float vvz);


float aceleracionenz(float vvx, float vvy, float vvz);



int main(){


	// Declara los parametros iniciales del problema


	float maxt = 15.0;

	int mint = 0;

	int puntos = 10000;

	float h = (maxt-mint)/(puntos);


	// Declara los arreglos del ejercicio


	float x[puntos];

	float y[puntos];

	float z[puntos];

	float vx[puntos];

	float vy[puntos];

	float vz[puntos];

	float t[puntos];


	// Condiciones iniciales


	t[0] = 0.0;

	x[0] = 1.0;

	y[0] = 0.0;

	z[0] = 0.0;

	vx[0] = 0.0;

	vy[0] = 1.0;

	vz[0] = 2.0;


	// Formula el primer paso necesario para resolver el ejercicio por medio de Leap-Frog


	t[1] = t[0] + h;

	x[1] = x[0] + h*(velocidadenx(vx[0], vy[0], vz[0]));

	y[1] = y[0] + h*(velocidadeny(vx[0], vy[0], vz[0]));

	z[1] = z[0] + h*(velocidadenz(vx[0], vy[0], vz[0]));

	vx[1] = vx[0] + h*(aceleracionenx(vx[0], vy[0], vz[0]));

	vy[1] = vy[0] + h*(aceleracioneny(vx[0], vy[0], vz[0]));

	vz[1] = vz[0] + h*(aceleracionenz(vx[0], vy[0], vz[0]));


	// Genera los siguientes pasos de la solucion numerica


	for(int j = 2; j < puntos; j++)
	{

		t[j] = t[j-1] + h;

		x[j] = x[j-2] + 2*h*(velocidadenx(vx[j-1], vy[j-1], vz[j-1]));

		y[j] = y[j-2] + 2*h*(velocidadeny(vx[j-1], vy[j-1], vz[j-1]));

		z[j] = z[j-2] + 2*h*(velocidadenz(vx[j-1], vy[j-1], vz[j-1]));

		vx[j] = vx[j-2] + 2*h*(aceleracionenx(vx[j-1], vy[j-1], vz[j-1]));

		vy[j] = vy[j-2] + 2*h*(aceleracioneny(vx[j-1], vy[j-1], vz[j-1]));

		vz[j] = vz[j-2] + 2*h*(aceleracionenz(vx[j-1], vy[j-1], vz[j-1]));

	}

	ofstream myfile ("datos.dat");
	myfile.is_open();
	for(int i = 0; i < puntos; i++)
	{

		myfile << t[i] << "  " << x[i] << "  " << y[i] << "  " << z[i] << "\n";

	}
	myfile.close();

  
	return 0;

}


// Inicializa las funciones necesarias para el ejercicio


float velocidadenx(float vvx, float vvy, float vvz)
{

	return vvx;

}

float velocidadeny(float vvx, float vvy, float vvz)
{

	return vvy;

}


float velocidadenz(float vvx, float vvy, float vvz)
{

	return vvz;

}

float aceleracionenx(float vvx, float vvy, float vvz)
{

	return (Q/M)*((vvy*BZ)-(vvz*BY));

}

float aceleracioneny(float vvx, float vvy, float vvz)
{

	return (-1)*(Q/M)*((vvx*BZ)-(vvz*BX));

}


float aceleracionenz(float vvx, float vvy, float vvz)
{

	return (Q/M)*((vvx*BY)-(vvy*BX));

}
