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

double comisionPorcentual123 = 5;
double comisionPorcentual456 = 8;
double comisionPorcentual789 = 10;
double comisionPorcentual10  = 12;
double CalcularVentaDeCorredor(int, int, double, double);
double CalcularImporteDeVenta(struct Venta venta);
double CalcularVenta(double, double, double);
void listaDeVentasDeCorredor(struct Venta[1024],int,int,struct Venta[1024]);
double sumarImporteDeVentas(struct Venta[1024],int);

double main()
{
	int NumerodeCorredor, ArticuloVendido, i, j;
	double CantidadArticulosVendidos, DescuentoAplicado, totalVendidoporCorredor;
	struct Venta listaDeVentas[1024];
	struct Venta listaVaciaOutput[1024];
	
	FILE *archivoDeCorredores;
	archivoDeCorredores = fopen("corredores.txt", "r");
	if (!archivoDeCorredores) {
		printf("Error reading corredores.txt file");
		return -1;
	}	
	
	// Lee numero de corredor
	fscanf(archivoDeCorredores, "%d",&NumerodeCorredor);
	i = 0;
	j = 0;
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
	
	/*listaDeVentasDeCorredor(listaDeVentas, i, 10, listaVaciaOutput);
	totalVendidoporCorredor = sumarImporteDeVentas(listaVaciaOutput, i); 
	printf("Total vendido por Corredor 10 = %.2lf",totalVendidoporCorredor);*/
	
	for(j=1;j<11;j++)
	{
			listaDeVentasDeCorredor(listaDeVentas, i, j, listaVaciaOutput);
			totalVendidoporCorredor = sumarImporteDeVentas(listaVaciaOutput, i); 
			printf("Total vendido por Corredor %d = %.2lf\n",j, totalVendidoporCorredor);
	}
	
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
void listaDeVentasDeCorredor(struct Venta listaDeVentas[1024],int sizeLista,int Corredor,struct Venta listaOutput[1024])
{
	int i;
	int j = 0, flag=0;
	for(i= 0;i<sizeLista;i++)
	{
		if(listaDeVentas[i].idCorredor == Corredor)
		{
			listaOutput[j] = listaDeVentas[i];
			j++;
			flag=1;
		}
	}
	
	if(!flag)
		listaOutput[0].idCorredor = 0;
	
}
