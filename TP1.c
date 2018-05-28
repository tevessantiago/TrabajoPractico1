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
	Tengo que calcular el importe total vendido (asumo que eso es la venta de la empresa) y despues calcular qué porcentaje pertenece a cada corredor (asumiendo que está implícito)
	Se me ocurre hacer una suma de todos los importes vendidos por cada corredor para representar la venta de la empresa. Luego calcular el porcentual.
c.	comisión a cobrar por cada corredor
d.	cantidad de ventas realizadas por cada corredor
e.	promedio del valor vendido por cada corredor
f.	nro de corredor que vendió más
*/

#include <stdio.h>

struct Venta {
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
	int NumerodeCorredor, ArticuloVendido;
	double CantidadArticulosVendidos, DescuentoAplicado, totalVendidoporCorredor;
	struct Venta listaVaciaOutput[1024];
	
	FILE *archivoDeCorredores;
	archivoDeCorredores = fopen("corredores.txt", "r");
	if (!archivoDeCorredores) {
		printf("Error reading corredores.txt file");
		return -1;
	}
	
	struct Venta listaDeVentas[1024];
	// Lee numero de corredor
	fscanf(archivoDeCorredores, "%d",&NumerodeCorredor);
	int i = 0;
	int j = 0;
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

	
	//listaDeVentasDeCorredor(listaDeVentas, i, 3, listaVaciaOutput);
	//printf("%.2lf",sumarImporteDeVentas(listaDeVentas,i));
	//printf("%lf",CalcularImporteDeVenta(venta));
	//printf("Total de venta = %.2lf\n",CalcularVentaDeCorredor(NumerodeCorredor, ArticuloVendido, CantidadArticulosVendidos, DescuentoAplicado));
	/*
	int lista[1024];
	listaDeVentasDeCorredor(lista);
	printf("%d",lista[4]);
	*/
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

/*
	Necesito una funcion que dada una lista de ventas devuelva la suma de los importes de las ventas
	Input: struct venta listaDeVentas 
	Output: double totalImportedeVentas
		*/
		
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

/*
	Necesito una funcion que dada la lista de ventas devuelva una lista de venta mas chicas que contenga todas las ventas de un corredor especifico
	Input: struct Venta listaDeVentas, int idCorredor
	Output: struct Venta listaDeVentasPorCorredor*/

void listaDeVentasDeCorredor(struct Venta listaDeVentas[1024],int sizeLista,int idCorredor,struct Venta listaOutput[1024])
{
	int i;
	int j = 0;
	for(i= 0;i<sizeLista;i++)
	{
		if(listaDeVentas[i].idCorredor == idCorredor)
		{
			listaOutput[j] = listaDeVentas[i];
			j++;
		}
	}
}

/*double CalcularVentaDeCorredor(int Corredor, int Articulo, double Cantidad, double Descuento)
{ 
	
	switch(Corredor)
	{
		case 1 ... 3: return CalcularVentaDeArticulos(Articulo, Cantidad, Descuento); break;
		case 4 ... 6: return CalcularVentaDeArticulos(Articulo, Cantidad, Descuento); break;
		case 7 ... 9: return CalcularVentaDeArticulos(Articulo, Cantidad, Descuento); break;
		case 	  10: return CalcularVentaDeArticulos(Articulo, Cantidad, Descuento); break;	
		
	}
	
}*/
