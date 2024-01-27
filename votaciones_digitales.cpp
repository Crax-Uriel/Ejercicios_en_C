/*
Para las próximas votaciones, ha sido contratado para desarrollar un programa para 
gestionar los votos digitales, el objetivo es leer los votos de n cantidad de personas. Cada 
voto es un número 1, 2, o 3 correspondiente a tres candidatos. Si el dato es 0 es un voto en 
blanco. Si es otro número es un voto nulo. Determine el total de votos de cada candidato y 
el total de votos blancos y nulos. Indicar en términos de % la cantidad de simpatizantes por
cada candidato. Mostrar al candidato ganado

D.E: Ingresar Numero de votos (n) 
Procesos: Suma de votos de cada candidato , votos blancos y votos nulos
D.S: total de votos de cada candidato y el total de votos blancos y nulos.
-Candidato ganado
-% la cantidad de simpatizantes po candidato
*/
#include <stdio.h>
#include <conio.h>
main (){
	int opc,i=1,n,can1=0,can2=0,can3=0,votoB=0,votoN=0,candiG=0;
	printf("Ingresa el numero de votos: ");
	scanf("%d",&n);
	do{
		fflush(stdin);
		puts("\n-----Eliga a un Candidato-----");
		puts("0.Voto en blanco");
		puts("1.Candidato 1");
		puts("2.Candidato 2");
		puts("3.Candidato 3");
		scanf("%d",&opc);
		switch (opc){
			case 0:
				votoB ++;
			break; 
			case 1:
				can1++;
			break;
			case 2:
				can2++;
			break;
			case 3:
				can3++;
			break;
			default: 
				votoN++;
		}
	i++;
	}while (i<=n);
	puts("\n----------Finalizo la votacion----------");
	if (can1>can2 && can1> can3 && can1>votoB && can1>votoN){
		puts("\n\n El candidato 1 es el ganador");
	}else if(can2>can1 && can2>can3 && can2>votoB && can2>votoN){
		puts("\n\n El candidato 2 es el ganador");
	}else if(can3>can1 && can3< can2 && can3>votoB && can3>votoN){
		puts("\n\n El candidato 3 es el ganador");
	}else {
		puts("\n\n Ninguno de los candidatos gano");
	}
	printf("\n El total de votos blancos es de: %d",votoB);
	printf("\n El total de votos del candidato 1 es de: %d",can1);
	printf("\n El total de votos del candidato 2 es de: %d",can2);
	printf("\n El total de votos del candidato 3 es de: %d",can3);
	printf("\n El total de votos nulos es de: %d \n",votoN);
	printf("\n La cantidad de simpatizantes por Candidato 1 es: %d ",(can1*100)/n,"%");
	printf("\n La cantidad de simpatizantes por Candidato 2 es: %d ",(can2*100)/n,"%");
	printf("\n La cantidad de simpatizantes por Candidato 3 es: %d ",(can3*100)/n,"%");
	printf("\n La cantidad de simpatizantes por voto en blanco es: %d ",(votoB*100)/n,"%");
	printf("\n La cantidad de simpatizantes por voto nulo es: %d",(votoN*100)/n,"%");
	return 0;
}
