// Programa que resuelve integrales definidas
// haciendo uso del Metodo del Trapecio, para n trapecios.
#include<stdio.h>
#include<conio.h>
#include<iostream>
#include<windows.h>
#include<iomanip>  // Manipuladores de flujo parametrizados
#include<math.h>

double fx(double);

void gotoxy(int column, int line)
{
	COORD coord;
	coord.X=column;
	coord.Y=line;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

using namespace std;

int main()
{
	double Area, fa, fb, s, h, a, b, x;
	int i, n;
	
	system("cls");
	gotoxy(15, 2);
	cout<<"Programa que resuelve una Integral Definida";
	gotoxy(15, 3);
	cout<<"utilizando el Metodo de integracion Trapezoidal.";
	gotoxy(15, 5);
	cout<<"Escribe los limites de integracion:";
	gotoxy(15, 7);
	cout<<"a = "; cin>> a;
	gotoxy(15,8);
	cout<<"b = "; cin>> b;
	gotoxy(15, 10);
	cout<<"Escribe el numero de trapecios: ";
	gotoxy(15, 12);
	cout<<"n = "; cin>> n;
	h = (b-a)/n;
	fa = fx(a);
	fb = fx(b);
	s = 0;
	for (i = 1; i <= n-1; i++)
	{
		x = a + i * h;
    	s = s + fx(x);
	}
	Area = h/2*(fa+2*s+fb);
	gotoxy(15, 14);
	cout<<"La solucion es: "<< setprecision(8)<<fixed << Area <<" u^2";
	
	gotoxy(15, 16);
	system("pause");
	return 0;
}

double fx(double x)
{
	//return sqrt(1+pow(cos(x),2));//el primer problema resulto
	return exp(x)*sin(x)/(1+x*x);//problema 22.3
	//return (9+4*pow(cos(0.4*x),2))*(5*exp(-0.5*x)+2*exp(0.15*x));//problema 22.14
	//22.9
}

