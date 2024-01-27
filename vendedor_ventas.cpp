/*
3. Desarrollar programa que solicite Numero de vendedor y nombre, así como sus ventas correspondientes a : 
Mayo, Junio y Julio, las almacene en un archivo “VentasTunombre.txt”. 
Utilizar un menú para: 
a. Registrar vendedor y ventas 
b. Mostrar mejor venta del último vendedor 
c. Mostrar venta promedio del último vendedor 
d. Mostrar todos los vendedores y sus ventas (almacenadas en el archivo) 
*/
#include <stdio.h>
#include<conio.h>
//Creamos el struct  
struct empleado{
	char nom[30];
	float ventas[3];
	float sutotal;
	int numVend;
};
empleado a;
//Procedimiento registar
void registrar(void){
	float precioP[100],sutotal=0,promedio=0;
	//Archivo
	FILE *m;
	m=fopen("Ventas_DelaCruzContrerasUriel.txt","a+");
	printf("Ingrese el numero de vendedor: ");
	scanf("%d",&a.numVend);
	fflush(stdin);
	fprintf(m,"[%d]",a.numVend);
	printf("Ingresa nombre del empleado: ");
	gets(a.nom);
	fflush(stdin);
	fprintf(m,"Nombre empleado: %s",a.nom);
	for(int i=0;i<3;i++){
		printf("Ingrese las ventas de [0]Mayo, [1]Junio, [2]Julio: [%d]",i);
		scanf("%f",&a.ventas[i]);
		a.sutotal+= a.ventas[i];
		//Imprimimos los datos del prograna en el archivo 
		fprintf(m,"\nVenta de [0]Mayo, [1]Junio, [2]Julio:[%d] $%f ",i,a.ventas[i]);//Guarda ventas en archivo
	}
	fclose(m);
}
//Procedimiento de Mejor venta del empleado
void mostrarMejorVenta(void){
	FILE *m;
	//Maximo 
	float mayor=0,menor;
	m=fopen("Ventas_DelaCruzContrerasUriel.txt","a+");
	mayor = a.ventas[0]; //Le asignamos el primer elemento del array
	menor = a.ventas[0]; //Así empezamos a comparar
		for (int i=0; i<3; i++){
    		if (a.ventas[i]> mayor){
    			mayor=a.ventas[i];
    		}
    		if (a.ventas[i]< menor){
    			menor=a.ventas[i];
    		}
    	}
    	printf("\nLa mejor venta del empleado es de: %.2f\n",mayor);
    	fprintf(m,"\nLa mejor venta del empleado es de: %.2f\n", mayor);
    	fclose(m);
}
//procedimiento de ventas promedio
void ventaPromedio(){
	FILE *m;
	float promedio=0;
	m=fopen("Ventas_DelaCruzContrerasUriel.txt","a+");
	promedio=(a.sutotal/3);
	printf("\nEl promedio de las ventas del empleado [%d]%s es de: %.2f \n",a.numVend,a.nom,promedio);
	fprintf(m,"El promedio de las ventas del empleado [%d]%s es de: %.2f \n",a.numVend,a.nom,promedio);
	fclose(m);
}

//Procedimiento consultar
void consultar(void){
	char linea[100];
	FILE *m;
	m=fopen("Ventas_DelaCruzContrerasUriel.txt","r");
	while(!feof(m)){
		fgets(linea,100,m);
		printf("\n%s",linea);
	}
	fclose(m);
}

main (){
	int op;
	do{
		puts("\n-----------Menu-----------");
		printf("\n1)Registrar vendedor y ventas ");
		printf("\n2)Mostrar mejor venta del último vendedor");
		printf("\n3)Mostrar venta promedio del último vendedor");
		printf("\n4)Mostrar todos los vendedores y sus ventas(Consultar)");
		printf("\n5)Salir");
		printf("\nIngrese la opcion:  ");scanf("%d",&op);
		fflush(stdin);
		switch(op){
			case 1: registrar();
			break;
			case 2: mostrarMejorVenta();
			break;
			case 3: ventaPromedio();
			break;
			case 4: consultar();
			break;
			case 5: 
				puts("Saliendo del programa");
			break;
			default: 
				puts("Opcion no valida");
		}
	}while(op!=5);
}
