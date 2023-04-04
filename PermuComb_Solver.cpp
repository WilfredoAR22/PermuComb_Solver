#include <iostream>
#include <windows.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <conio.h>

using namespace std;

// Posición 
void gotoxy(int x, int y)
{
	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hCon, dwPos);	
}

double FACTORIAL(int x)
{
	double producto=1;
	for(int i=x; i>0; i--)
	{producto=producto*i;}
	return producto;
}
void menu_permutaciones()
{
	void per_sin_repeticion();
	void permut_con_repeticion();
	void per_sub_conjuntos();
	void per_circular();
	int opcion1;
	do
	{
		gotoxy(11,1);cout<<"PERMUTACIONES"<<endl;
		cout<<"\n1. Permutaciones sin repeticion"<<endl;
		cout<<"\n2. Permutaciones con repeticion"<<endl;
		cout<<"\n3. Permutaciones en subconjuntos divididos"<<endl;
		cout<<"\n4. Permutaciones circulares"<<endl;
		cout<<"\n5. Salir"<<endl;
		gotoxy(6,13); cout<<"Ingrese la opcion que desea: ";
		cin>>opcion1;
		system("cls");
		switch(opcion1)
		{
			case 1:
				{
					per_sin_repeticion();
					cout<<"\nPRESIONE UNA TECLA PARA VOLVER AL MENU PERMUTACIONES"<<endl;
					getch();
					system("cls");
				}break;
			case 2:
				{
					permut_con_repeticion();
					cout<<"\nPRESIONE UNA TECLA PARA VOLVER AL MENU DE PERMUTACIONES"<<endl;
					getch();
					system("cls");
				}break;
			case 3:
				{
					per_sub_conjuntos();
					cout<<"\nPRESIONE UNA TECLA PARA VOLVER AL MENU DE PERMUTACIONES"<<endl;
					getch();
					system("cls");
				}break;
			case 4:
				{
					per_circular();
					cout<<"\nPRESIONE UNA TECLA PARA VOLVER AL MENU DE PERMUTACIONES"<<endl;
					getch();
					system("cls");
				}break;
			default:
				if(opcion1>5)
				{
					cout<<"ERROR!"<<endl;
					cout<<"El numero ingresado no corresponde a ninguno de las opciones"<<endl;
					cout<<"\nPRESIONE UNA TECLA PARA VOLVER AL MENU PERMUTACIONES"<<endl;
					getch();
					system("cls");
				}
				system("cls");
		}
	}while(opcion1!=5);
}

//PERMUTACIONES SIN REPETICION
void per_sin_repeticion()
{
	int val_n = 0;int val_r = 0, respuesta;
	gotoxy(4,0); cout<<"PERMUTACIONES SIN REPETICION"<<endl;							
	cout<<"\nIngrese el valor de n: ";
	cin>>val_n;
	cout<<"Ingrese el valor de r: ";
	cin>>val_r;
	
	if(val_r<=val_n)
	{
		respuesta = (FACTORIAL(val_n))/FACTORIAL((val_n-val_r));
		gotoxy(2,5); cout<<"LA RESPUESTA ES:  "<<"n "<<"P"<<" r "<<"= "<<respuesta<<endl;
	}
	else
	{
		cout<<"\nNOTA:"<<endl;
		cout<<"No es posible realizar la operacion, debido a que n es menor a r."<<endl;
		cout<<"r puede ser menor o igual a n, pero no mayor. "<<endl;
	}}
void permut_con_repeticion()
{
	int val_n = 0;
	int val_r = 0;
	int respuesta = 0;
	gotoxy(4,0); cout<<"PERMUTACIONES CON REPETICION"<<endl;
	cout<<"\nIngrese el valor de n: ";
	cin>>val_n;	
	cout<<"Ingrese el valor de r: ";
	cin>>val_r;
	respuesta = pow(val_n, val_r);
	gotoxy(2,5); cout<<"EL RESULTADO ES:  "<<"n"<<" P' "<<"r"<<" = "<<respuesta<<endl;
}
void per_sub_conjuntos()
{
	int val_n = 0;	
	int acumulador = 0;
	int resultado = 0;
	int cant_sc;
	int r=1;
	
	cout<<"PERMUTACIONES EN SUBCONJUNTOS DIVIDIDOS"<<endl;
	cout<<"\nIngrese el valor de n: ";
	cin>>val_n;
	cout<<"Ingrese la cantidad de sub conjuntos a formar: ";
	cin>>cant_sc;	
	int val_r[cant_sc];
	cout<<"\n";
	for(int i = 0; i <= cant_sc-1; i++)
	{
		cout<<"Ingrese el subconjunto "<<"N"<<i+1<<" : ";
		cin>>val_r [i]; 
		acumulador = acumulador + val_r[i];	
	}
	if(acumulador == val_n)
	{
		for(int y = 0; y <= cant_sc-1; y++)
		{
			r = r * FACTORIAL(val_r[y]);	
		}			 
		resultado = (FACTORIAL(val_n) / r);	
	}
	cout<<"\nEL RESULTADO ES:  "<<"n"<<" P";
	for(int i=0; i<cant_sc; i++)
	{
	cout<<" n"<<i+1<<",";
	}
	cout<<" = "<<resultado<<endl;
}	

//PERMUTACIONES CIRCULARES
void per_circular()
{
	int val_n = 0;
	double ope, residuo=1;
	int resultado=0;
	gotoxy(2,0); cout<<"PERMUTACIONES CIRCULARES"<<endl;
	cout<<"\nIngrese el valor de n: ";
	cin>>val_n;
	ope=val_n-residuo;
	resultado = FACTORIAL((ope));		
	
	cout<<"\nEL RESULTADO ES:  "<<"n PC n"<<" = "<<resultado<<endl;
}

//MENU DE COMBINACIONES.......
void menu_combinaciones()
{
	void sinrepeticion();
	void con_repeticion();
	int opcion;
	do
	{
		gotoxy(11,1);cout<<"COMBINACIONES"<<endl;
		cout<<"\n1. Combinaciones sin repeticion"<<endl;
		cout<<"\n2. Combinaciones con repeticion"<<endl;
		cout<<"\n3. Salir"<<endl;
		gotoxy(6,9); cout<<"Ingrese la opcion que desea: ";
		cin>>opcion;
		system("cls");
		switch(opcion)
		{
			case 1:
				{
					sinrepeticion();
					cout<<"\nPRESIONE UNA TECLA PARA VOLVER AL MENU COMBINACIONES"<<endl;
					getch();
					system("cls");
				}break;
			case 2:
				{
					con_repeticion();
					cout<<"\nPRESIONE UNA TECLA PARA VOLVER AL MENU DE COMBINACIONES"<<endl;
					getch();
					system("cls");
				}
			default:
			if(opcion>3)
			{
				cout<<"ERROR!"<<endl;
				cout<<"El numero ingresado no corresponde a ninguno de las opciones"<<endl;
				cout<<"\nPRESIONE UNA TECLA PARA VOLVER AL MENU COMBINACIONES"<<endl;
				getch();
				system("cls");
			}
			system("cls");
		}
	}while(opcion!=3);
}


//COMBINACIONES SIN REPETICION
void sinrepeticion()
{
	int n=0;
	int r=0;
	int resta=0;
	int resultado;
	gotoxy(5,0); cout<<"COMBINACIONES SIN REPETICION"<<endl;
	cout<<"\nIngrese el valor de n: "; cin>>n;
	cout<<"Ingrese el valor de r: "; cin>>r;
	
	if(r<=n)
	{
		resta=n-r;
		resultado=(FACTORIAL(n))/((FACTORIAL(resta))*(FACTORIAL(r)));
		gotoxy(0,5); cout<<"LA RESPUESTA ES:  "<<"n "<<"C"<<" r "<<" = "<<resultado<<endl;
	}
	else
	{
		cout<<"\nNOTA:"<<endl;
		cout<<"No es posible realizar la operacion, debido a que n es menor a r."<<endl;
		cout<<"r puede ser menor o igual a n, pero no mayor. "<<endl;
	}
}
//COMBINACIONES CON REPETICION
void con_repeticion()
{
	int n=0;
	int r=0;
	int a=0, b=0;
	int resultado=0;
	gotoxy(5,0); cout<<"COMBINACIONES CON REPETICION"<<endl;
	cout<<"\nIngrese el valor de n: "; cin>>n;
	cout<<"Ingrese el valor de r: "; cin>>r;
	
	a=n+r-1;
	b=n-1;
	resultado=(FACTORIAL(a)/((FACTORIAL(r))*(FACTORIAL(b))));
	gotoxy(0,5); cout<<"LA RESPUESTA ES:  "<<"n "<<"C'"<<" r "<<" = "<<resultado<<endl;
}



int main()
{
	int opcion;
	do{
	for(int x=0; x<50; x++)
	{
	gotoxy(x,0); cout<<"*";gotoxy(x,20); cout<<"*";}
	for(int y=1; y<20; y++)
	{
gotoxy(0,y); cout<<"*";gotoxy(49,y); cout<<"*";	}
gotoxy(20,2); cout<<"BIENVENIDO"<<endl;
gotoxy(5,5); cout<<"Digite su opcion"<<endl;
gotoxy(5,7); cout<<"1. Permutaciones"<<endl;
gotoxy(5,9); cout<<"2. Combinaciones"<<endl;
gotoxy(5,11); cout<<"3. Salir"<<endl;
gotoxy(12,18); cout<<"Ingrese la opcion que desea: "; cin>>opcion;
system("cls");
		switch(opcion)
		{
		case 1:
				{
				menu_permutaciones();
				cout<<"\nDigitar tecla para regresar"<<endl;
				system("cls");
				}break;
		case 2:
				{
				menu_combinaciones();
				cout<<"\nDigitar tecla para regresar"<<endl;
				system("cls");
				}break;
		default:
				if(opcion>2)
				{
				gotoxy(12,25);cout<<"\nDigitar tecla para SALIR"<<endl;
				}
				getch();
				system("cls");
			break;
		}	
	}while(opcion!=3);
}
