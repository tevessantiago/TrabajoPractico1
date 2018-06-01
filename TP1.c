/* Una empresa textil maneja sus ventas por medio de corredores que cobran  comisiones sobre el total de las mismas.
Tiene 4 artículos y son 10 corredores con las siguientes comisiones:
-	corredor 1,2,3 =   5 %
-	corredor 4,5,6 =   8 %
-	corredor 7,8,9 = 10 %
-	corredor 10    = 12 %
el precio de sus artículos son 
-	art 1 = $10
-	art 2 = $15
-	art 3 = $20
-	art 4 = $12
cada vez que realiza una venta sabe 
-	nro de corredor
-	nro de artículo
-	cantidad
-	descuento
Calcular e imprimir
a.	importe total vendido por cada corredor
b.	porcentual que representa sobre la venta de la empresa
c.	comisión a cobrar por cada corredor
d.	cantidad de ventas realizadas por cada corredor
e.	promedio del valor vendido por cada corredor
f.	nro de corredor que vendió más
*/

#include <stdio.h>

struct Venta 
{
	int    idCorredor;
	int    idArticulo;
	double cantidad;
	double descuento;
};

double CalcularVentaDeCorredor(int, int, double, double);
double CalcularImporteDeVenta(struct Venta venta);
double CalcularVenta(double, double, double);
void listaDeVentasDeCorredor(struct Venta[1024],int,int,struct Venta[1024], int[1024]);
double sumarImporteDeVentas(struct Venta[1024],int);
double calcularComisiondeCorredor(double ventaTotaldelCorredor[1024], int idCorredor);
double calcularMejorCorredor(double ListadeVentasTotalesPorCorredor[1024]);

double main()
{
	int NumerodeCorredor, ArticuloVendido, i, j, k, l, m;
	int CantidadVentasporCorredor[1024] = { 0 }; // ordenada del 1 al 10
	double CantidadArticulosVendidos, DescuentoAplicado, ventaDeLaEmpresa, comisionDelCorredor, promedioVendidoporCorredor;
	double ListadeVentasTotalesPorCorredor[1024], ListaPorcentualdeCorredores[1024]; // ordenados del 1 al 10
	struct Venta listaDeVentas[1024];
	struct Venta listaVaciaOutput[1024];

	ventaDeLaEmpresa = 0;
	promedioVendidoporCorredor = 0;
	
	FILE *archivoDeCorredores;
	archivoDeCorredores = fopen("corredores.txt", "r");
	if (!archivoDeCorredores) {
		printf("Error reading corredores.txt file");
		return -1;
	}	
	
	// Lee numero de corredor
	fscanf(archivoDeCorredores, "%d",&NumerodeCorredor);

	while(NumerodeCorredor != 0)
	{
		// Lee numero de articulo
		fscanf(archivoDeCorredores, "%d",&ArticuloVendido);
		// Lee cantidad de articulos vendidos
		fscanf(archivoDeCorredores, "%lf",&CantidadArticulosVendidos);
		// Lee descuento
		fscanf(archivoDeCorredores, "%lf",&DescuentoAplicado);		
		
		struct Venta venta;
		venta.idArticulo = ArticuloVendido;
		venta.cantidad = CantidadArticulosVendidos;
		venta.descuento = DescuentoAplicado;
		venta.idCorredor = NumerodeCorredor;
		listaDeVentas[i] = venta;
		i++;
		
		// Sigue leyendo numero de corredor hasta que sea 0
		fscanf(archivoDeCorredores, "%d",&NumerodeCorredor);
	}
	
	for(j=1;j<11;j++)
	{
			listaDeVentasDeCorredor(listaDeVentas, i, j, listaVaciaOutput, CantidadVentasporCorredor);
			ListadeVentasTotalesPorCorredor[j] = sumarImporteDeVentas(listaVaciaOutput, i);
			ventaDeLaEmpresa =  ventaDeLaEmpresa + ListadeVentasTotalesPorCorredor[j];
			if(CantidadVentasporCorredor[j] != 0)
			{
				promedioVendidoporCorredor = (ListadeVentasTotalesPorCorredor[j] / (double)CantidadVentasporCorredor[j]);
			}			
			else
			{
				promedioVendidoporCorredor = 0;
			}			
			printf("El corredor %d hizo %d ventas y vendio un total de = $%.2lf\n", j, CantidadVentasporCorredor[j], ListadeVentasTotalesPorCorredor[j]);
			printf("Promedio vendido = $%.2lf\n", promedioVendidoporCorredor);	
	}
	
	for(k=1;k<11;k++)
	{
		ListaPorcentualdeCorredores[k] = ListadeVentasTotalesPorCorredor[k] * 100 / ventaDeLaEmpresa;
		printf("Porcentual de venta representado por el corredor %d = %.2lf%%\n", k, ListaPorcentualdeCorredores[k]);
	}
	
	for(l=1;l<11;l++)
	{
		comisionDelCorredor = calcularComisiondeCorredor(ListadeVentasTotalesPorCorredor, l);
		printf("Comision a cobrar por el corredor %d = $%.2lf\n", l, comisionDelCorredor);
	}
	
	calcularMejorCorredor(ListadeVentasTotalesPorCorredor);
	
	//printf("Promedio de ventas de la empresa = $%.2lf\n", (ventaDeLaEmpresa / 10));
	
	return 0;
}

double valorDeArticulo(int idArticulo){
	double valorDeArticulo;
	switch(idArticulo)
	{
		case 1: valorDeArticulo = 10; break;
		case 2: valorDeArticulo = 15; break;
		case 3: valorDeArticulo = 20; break;
		case 4: valorDeArticulo = 12; break;
	}
	return valorDeArticulo;
}

double comisionCorrespondiente(int idCorredor){
	double comisionCorrespondiente;
	switch(idCorredor)
	{
		case 1 ... 3: comisionCorrespondiente = 5; break;
		case 4 ... 6: comisionCorrespondiente = 8; break;
		case 7 ... 9: comisionCorrespondiente = 10; break;
		case 10		: comisionCorrespondiente = 12; break;
	}
	return comisionCorrespondiente;
}

double CalcularImporteDeVenta(struct Venta venta)
{
	
	double valorVenta = venta.cantidad * valorDeArticulo(venta.idArticulo);
	double valorVentaDescontada = valorVenta * (1-(venta.descuento/100));
	return valorVentaDescontada;
}
		
double sumarImporteDeVentas(struct Venta listaDeVentas[1024],int sizeLista)
{
	int i;
	double sumaImporteDeVentas = 0;
	for(i=0;i<sizeLista;i++)
	{
		double x = CalcularImporteDeVenta(listaDeVentas[i]);
		sumaImporteDeVentas = sumaImporteDeVentas + x;
	}
	return sumaImporteDeVentas;
}

// Esta función no devuelve ningún valor, se encarga de llenar una lista vacía con las ventas de un corredor determinado
void listaDeVentasDeCorredor(struct Venta listaDeVentas[1024],int sizeLista,int Corredor,struct Venta listaOutput[1024], int CantidadVentasporCorredor[1024])
{
	int i, flag;
	int j = 0;
	for(i= 0;i<sizeLista;i++)
	{
		flag = 0;
		if(listaDeVentas[i].idCorredor == Corredor)
		{
			listaOutput[j] = listaDeVentas[i];
			j++;
			flag=1;
		}
		if(!flag)
		{
			listaOutput[i].idCorredor = 0;
			listaOutput[i].idArticulo = 0;
			listaOutput[i].cantidad = 0;
			listaOutput[i].descuento = 0;
		}
	}
	CantidadVentasporCorredor[Corredor] = j;
}

double calcularComisiondeCorredor(double ventaTotaldelCorredor[1024], int idCorredor)
{
	double comision = 0;
	comision = ventaTotaldelCorredor[idCorredor] * (comisionCorrespondiente(idCorredor) / 100);
	return comision;
}

double calcularMejorCorredor(double ListadeVentasTotalesPorCorredor[1024])
{
	int i, mejorCorredor;
	double ventaMayor;
	ventaMayor = 0;
	for(i=0;i<10;i++)
	{
		if(ventaMayor < ListadeVentasTotalesPorCorredor[i])
		{
			ventaMayor = ListadeVentasTotalesPorCorredor[i];
			mejorCorredor = i;
		}
	}
	return printf("El corredor %d es el que mas vendio\n", mejorCorredor);
}
