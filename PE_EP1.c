/*Un sanatorio posee la atención de 4 obras sociales o prepagas en sus 50 consultorios externos de
cada servicio.
Cuando un paciente se acerca a atenderse se registran los siguientes datos que finalizan con número
de atención = 0
- Numero de atención (NA)
- Apellido y nombre del paciente (apynom)
- Servicio en el que se atenderá (serv)
- Obra social que presenta (os)
- Valor de la consulta (VC)
Se desea saber:
1. Monto total a cobrar a cada OS
2. Valor promedio total de las consultas realizadas*/

#include <stdio.h>

double main(){
	int numeroAatencion, servicio, obraSocial;
	double valorDeConsulta, montoTotalOS1, montoTotalOS2, montoTotalOS3, montoTotalOS4;
	char apellidoYNombre[200];
	
	int consultaRealizada = 0;
	double valorPromedioDeConsultas = 0;
	
	printf("Ingrese numero de atencion o presione 0 para salir");
	scanf("%d", numeroAatencion);
	
	while(numeroAatencion != 0){
		printf("Ingrese apellido y nombre sin espacios\n"); // No encontré la forma de leer con espacios
		scanf("%s",&apellidoYNombre);
		printf("Ingrese numero de servicio\n");
		scanf("%d",&servicio);
		printf("Ingrese numero de obra social o prepaga\n");
		scanf("%d",&obraSocial);
		printf("Ingrese valor de la consulta\n");
		scanf("$lf",&valorDeConsulta);
		
		switch(obraSocial){
			case 1: montoTotalOS1 = montoTotalOS1 + valorDeConsulta; break;
			case 2: montoTotalOS2 = montoTotalOS2 + valorDeConsulta; break;
			case 3: montoTotalOS3 = montoTotalOS3 + valorDeConsulta; break;
			case 4: montoTotalOS4 = montoTotalOS4 + valorDeConsulta; break;
		}
		
		consultaRealizada++;
		
		printf("Ingrese numero de atencion o presione 0 para salir");
		scanf("%d", numeroAatencion);
	}
	
	valorPromedioDeConsultas = (montoTotalOS1 + montoTotalOS2 + montoTotalOS3 + montoTotalOS4) / consultaRealizada;
	
	printf("Monto total a cobrar a OS1 = $%.2lf",montoTotalOS1);
	printf("Monto total a cobrar a OS2 = $%.2lf",montoTotalOS2);
	printf("Monto total a cobrar a OS3 = $%.2lf",montoTotalOS3);
	printf("Monto total a cobrar a OS4 = $%.2lf",montoTotalOS4);
	printf("Valor promedio total de las consultas realizadas",valorPromedioDeConsultas);
}