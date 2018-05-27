/*1. En una empresa los empleados cobran un sueldo según la categoria, son 50
empleados y 3 categorías
Categoría 1 = $ 1500
Categoría 2 = $ 2000
Categoría 3 = $ 2500
Al sueldo se le suman $ 100 por cada año trabajado.
Si se ingresa el nombre, categoría y antiguedad de cada empleado, calcular:
A. Cuantos empleados hay por categoría
B. Total de sueldos pagados por categoría
C. Sueldo promedio general
D. Sueldo maximo y a quien pertenece
E. Que porcentual sobre el total de sueldos representa cada total de sueldos
de las categorías*/

#include <stdio.h>
#include <string.h>

int categoria1 = 1500;
int categoria2 = 2000;
int categoria3 = 2500;

int main()
{
	char nombre[20], EmpleadoRico[20];
	int empleado, categoria, antiguedad, Sueldo, cantidadEmpleadosCategoria1, cantidadEmpleadosCategoria2, cantidadEmpleadosCategoria3, SueldosPorCategoria1, SueldosPorCategoria2, SueldosPorCategoria3, SueldoPromedio, SueldoMaximo, TotaldeSueldos;
	double PorcentualCategoria1, PorcentualCategoria2, PorcentualCategoria3;
	cantidadEmpleadosCategoria1 = 0;
	cantidadEmpleadosCategoria2 = 0;
	cantidadEmpleadosCategoria3 = 0;
	SueldosPorCategoria1 = 0;
	SueldosPorCategoria2 = 0;
	SueldosPorCategoria3 = 0;
	SueldoMaximo = 0;
	Sueldo = 0;
	PorcentualCategoria1 = 0;
	PorcentualCategoria2 = 0;
	PorcentualCategoria3 = 0;
	TotaldeSueldos = 0;
	for(empleado=0;empleado<50;empleado++)
    {
        printf("Ingrese nombre y apellido del empleado sin espacios\n"); // No encontré la forma de leer con espacios
		scanf("%s",&nombre);
		printf("Ingrese categoria del empleado\n");
		scanf("%d",&categoria);
		printf("Ingrese antiguedad en anos trabajados del empleado\n");
		scanf("%d",&antiguedad);
		switch(categoria)
		{
			case 1 : cantidadEmpleadosCategoria1 = cantidadEmpleadosCategoria1 + 1;
					 Sueldo						 = (categoria1 + (antiguedad * 100));
					 SueldosPorCategoria1		 = SueldosPorCategoria1 + Sueldo;
					 break;
			case 2 : cantidadEmpleadosCategoria2 = cantidadEmpleadosCategoria2 + 1;
					 Sueldo						 = (categoria2 + (antiguedad * 100));
					 SueldosPorCategoria2		 = SueldosPorCategoria2 + Sueldo;
					 break;
			case 3 : cantidadEmpleadosCategoria3 = cantidadEmpleadosCategoria3 + 1;
					 Sueldo						 = (categoria3 + (antiguedad * 100));
					 SueldosPorCategoria3		 = SueldosPorCategoria3 + Sueldo;
					 break;
		}
		if (SueldoMaximo < Sueldo)
		{
			SueldoMaximo = Sueldo;
			memcpy(&EmpleadoRico, &nombre, sizeof EmpleadoRico); // Le asigno el valor completo de nombre a EmpleadoRico
		}
    }
    TotaldeSueldos = (SueldosPorCategoria1 + SueldosPorCategoria2 + SueldosPorCategoria3);
	SueldoPromedio = TotaldeSueldos / (cantidadEmpleadosCategoria1 + cantidadEmpleadosCategoria2 + cantidadEmpleadosCategoria3);
	PorcentualCategoria1 = (double)SueldosPorCategoria1 * 100 / (double)TotaldeSueldos;
	PorcentualCategoria2 = (double)SueldosPorCategoria2 * 100 / (double)TotaldeSueldos;
	PorcentualCategoria3 = (double)SueldosPorCategoria3 * 100 / (double)TotaldeSueldos;
	printf("Empleados por categoria 1 = %d\n",cantidadEmpleadosCategoria1);
	printf("Empleados por categoria 2 = %d\n",cantidadEmpleadosCategoria2);
	printf("Empleados por categoria 3 = %d\n",cantidadEmpleadosCategoria3);
	printf("Total de sueldo pagado por categoria 1 = %d\n",SueldosPorCategoria1);
	printf("Total de sueldo pagado por categoria 2 = %d\n",SueldosPorCategoria2);
	printf("Total de sueldo pagado por categoria 3 = %d\n",SueldosPorCategoria3);
	printf("Sueldo promedio general = %d\n",SueldoPromedio);
	printf("El sueldo maximo es de = %d y pertenece a %s\n",SueldoMaximo,EmpleadoRico);
	printf("Porcentaje de sueldos:\n Categoria 1 = %.2lf\n Categoria 2 = %.2lf\n Categoria 3 = %.2lf\n",PorcentualCategoria1,PorcentualCategoria2,PorcentualCategoria3);
    return 0;
}

