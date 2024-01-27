/*
Desarrollar programa que solicite nombre y cantidad de producto, genere una lista de compras, 
validando si el producto que desea comprar pertenece a la canasta básica, en este caso se 
registra en archivo lista.txt, y los productos que no corresponden a la canasta básica guardarlos 
en Nopermitidos.txt
*/
#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>//Para trasformar a min a mayu o viceversa

//Creamos el struct con los atributos de cantidad de productos que lleva y cantidad de cada producto a comprar
struct producto{
	int cantP;
	int cantidadpro[];
};
producto a;
main(){
	//Definimos el vector canastaBasica con los nombres de los productos basicos
    char canastaBasica[][50] = {
	"maiz", "frijol", "arroz", "azucar", "harina de maiz", "aceite vegetal", "atun", "sardina",
	"leche fluida","chiles enlatados","cafe","sal","avena","pasta","harina de trigo"
	,"chocolate","galletas","lentejas","jabon","jabon de tocador","papel","detergente","pasta de dientes"
	,"carne de res","carne de puerco","carne de pollo","tostadas","pan de caja","huevo","pescado",
	"agua","golosina","pure de tomate","frutas desidratadas","jamaica y tamarindo","concentrados sin azucar",
	"gelatina","leguminosos ","frutas y verduras","pilas"
	};
	int numProductos=40,encontrado=0;

	// Solicitamos el nombre y la cantidad de productos
	printf("Ingrese la cantidad de productos a comprar: ");
	scanf("%d",&a.cantP);
	fflush(stdin); //Para vaciar el bufer de la memoria 
	char nom[a.cantP][50]; //Definimos el tamaño del vector nom
	

	// Solicitar los nombres y cantidades de los productos
    for (int i = 0; i < a.cantP; i++) {
    	printf("\nIngrese el nombre del producto [%d]: ", i + 1);
    	gets(nom[i]);
        printf("Ingrese la cantidad del producto a llevar [%d]: ", i + 1);
        scanf("%d", &a.cantidadpro[i]);
        fflush(stdin);
        printf("\n");
    	
	}
	//Trasforma a minusculas 
	for (int i = 0; i < a.cantP; i++) {
        for (int j = 0; nom[i][j]; j++) {
            nom[i][j] = tolower(nom[i][j]);
        }
    }
	
    printf("\nCompras Realizadas:\n");
    for (int i = 0; i<a.cantP; i++){//Utilizamos el primer for para comparar nom[i] y mostrar la lsita de compras
    	printf("[%d] Nombre producto: %s - Cantidad: %d\n",i+1, nom[i],a.cantidadpro[i]);//Imprimimos la lista de productos en pantalla
    	fflush(stdin);
    	// Validar si el producto pertenece a la canasta básica
        for (int j = 0; j < numProductos; j++) {//Utilizamos el 2 for para recorrer la lista de la canasta básica
            if (strcmp(nom[i], canastaBasica[j]) == 0) {//Comparamos las cadenas 
               //Si las cadenas son identicas se le asigna el valor de 1 y se rompe el bucle
			   encontrado = 1;
                break;
            }
        }
		//Se verifica el valor de la variable encontrado, si es verdadero imprime y guarda el archivo 
        if (encontrado){

        	FILE *m;//Creamos puntero tipo FILE
        	m=fopen("lista.txt","a+");//Abrimos el archivo "lista.txt" en modo a+ para que cree archivo y modifique
            printf("El producto ([%d] %s) pertenece a la lista de canasta basica \n\n",i+1,nom[i]);//Imprimimos en pantalla "si existe el producto" 
            fprintf(m,"El producto ([%d] %s) pertenece a la lista de canasta basica\n",i+1,nom[i]);//Imprimimos en el archivo "si existe el producto" 
            fclose(m);//Cerramos archivo
           
        }else{
        	FILE *m;//Creamos puntero tipo FILE
        	m=fopen("Nopermitidos.txt","a+");//Abrimos el archivo "Nopermitidos.txt" en modo a+ para que cree archivo y modifique
            printf("El producto ([%d] %s) no pertenece a la lista de canasta basica \n\n",i+1,nom[i]);//Imprimimos en pantalla "no existe el producto" 
            fprintf(m,"El producto ([%d] %s) no pertenece a la lista de canasta basica\n",i+1,nom[i]);//Imprimimos en el archivo "no existe el producto" 
            fclose(m);//Cerramos archivo
        }
	}
	return 0;
}
