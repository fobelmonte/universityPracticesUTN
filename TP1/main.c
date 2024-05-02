#include <stdio.h>
#include <stdlib.h>

//PROTOTIPO
//int valorAleatorio(int numeroAleatorio);
//void mayorNumero(int numA, int numB, int numC);

int main()
{
    //EJERCICIO 1
    srand (time(NULL));
    int numeroAleatorio;

    int valorAleatorio(int numeroAleatorio);

    printf("El numero aleatorio es: %i\n", numeroAleatorio);

    system("pause");
    system("cls");

    //EJERCICIO 2
    int numA=0;
    int numB=0;
    int numC=0;

    printf("Ingrese primer numero:\n");
    scanf("%i", &numA);

    printf("Ingrese segundo numero:\n");
    scanf("%i", &numB);

    printf("Ingrese tercer numero:\n");
    scanf("%i", &numC);

    mayorNumero();



    return 0;
}

//FUNCIONES
int valorAleatorio(int numeroAleatorio){
    numeroAleatorio=rand()% 100;
    return numeroAleatorio;
}

void mayorNumero(int numA, int numB,int numC){
    if(numA >= numB && numA>=numC && numB>=numC){
        printf("El numero mayor es: %i \n", numA);
        printf("El numero menor es: %i \n", numC);
        }
    else if(numA >= numB && numA>=numC && numC>=numB){
        printf("El numero mayor es: %i \n", numA);
        printf("El numero menor es: %i \n", numB);
        }
    else if(numB >= numA && numB>=numC && numA>=numC){
        printf("El numero mayor es: %i \n", numB);
        printf("El numero menor es: %i \n", numC);
        }
    else if(numB >= numA && numB>=numC && numC>=numA){
        printf("El numero mayor es: %i \n", numB);
        printf("El numero menor es: %i \n", numA);
        }
    else if(numC >= numA && numC>=numB && numA>=numB){
        printf("El numero mayor es: %i \n", numC);
        printf("El numero menor es: %i \n", numB);
        }
    else{
        printf("El numero mayor es: %i \n", numC);
        printf("El numero menor es: %i \n", numA);
        }
}
