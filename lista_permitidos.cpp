/*
Desarrolo un programa que genere un alista de invitados, validando 
si el invitado que desea entrar pertenece a la lista de los permitidos.txt
en caso contrario gurdarlos en Nopermitidos.txt
Utilizando arreglos y archivos de texto
*/
#include <stdio.h>
#include <string.h>
#include <conio.h>
struct invitado{
	char nombres[5][50];
	char nomC[50];
};
invitado a;
bool Consu(int numInvi){
	for (int i = 0; i < numInvi; i++) {
        if (strcmp(a.nombres[i], a.nomC) == 0) {
            return true;
        }
    }
    return false;
}
int main() {
	int numInvi;
	char r[2];
	printf("Ingrese cuantos invitados:");
	scanf("%d",&numInvi);
	fflush(stdin);
    // Solicitar nombres al usuario
    printf("Por favor ingrese los nombres:\n");
    for (int i = 0; i < numInvi; i++) {
        printf("Nombre %d: ", i + 1);
        scanf("%s", a.nombres[i]);
        
    }
	fflush(stdin);
    // Mostrar los nombres en pantalla
    printf("\nLos nombres de la lista de invitados son:\n");
    for (int i = 0; i < numInvi; i++) {
        printf("%d. %s\n", i + 1, a.nombres[i]);
    }
    printf("\n\n");
    //Consultar invitados y almacenar en el archivo
    do {
		printf("Ingrese su nombre del invitado a buscar: ");
		scanf("%s",&a.nomC);
		if (Consu(numInvi)){
			FILE *m;
			printf("%s puede entrar. ¡Bienvenido!\n",a.nomC);
			m=fopen("Invitados.txt","a+");
			fprintf(m,"\nLista de invitados\n%s",a.nomC);
			fclose(m);
			
		}else{
			FILE *m;
			printf("%s no está en la lista de invitados permitidos. Lo siento.\n", a.nomC);
			m=fopen("NoInvitados.txt","a+");
			fprintf(m,"\nLista de no Invitados: \n%s",a.nomC);
			fclose(m);
		}
		printf("\nQuieres buscar a alguien mas si/no: ");
		scanf("%s",&r);
	}while (strcmp(r,"si")==0 || strcmp(r,"SI")==0|| strcmp(r,"Si")==0);
    
}
