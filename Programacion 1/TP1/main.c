#include <stdio.h>
#include <stdlib.h>

//PROTOTIPOS
int valorAleatorio(int numeroAleatorio);
void mayorNumero(int *numeroA, int *numeroB, int *numeroC);
int sumarNumeros(int *numeroSumado);
void tablaMultiplicar(int *multiplicando);
void funcionSuma(int *operandoA, int *operandoB);
void funcionResta(int *operandoA, int *operandoB);
void funcionMultiplicacion(int *operandoA, int *operandoB);
void funcionDivision(int *operandoA, int *operandoB);
int cambioNegativo(int *numeroPositivo);
void cargaValores(int *enteroA, int *enteroB);


int main()
{
    //EJERCICIO 1
    srand (time(NULL));

    int numeroAleatorio=valorAleatorio(&numeroAleatorio);

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

    mayorNumero(&numA, &numB, &numC);

    system("pause");
    system("cls");

    //EJERCICIO 3
    int numeroSumado=0;

    printf("Ingrese un numero para sumar sus anteriores:\n");
    scanf("%i", &numeroSumado);

    int resultadoSuma=sumarNumeros(&numeroSumado);
    printf("La suma de sus anteriores es igual a: %i \n", resultadoSuma);

    system("pause");
    system("cls");

    //EJERCICIO 4
    int multiplicando=0;

    printf("Ingrese un numero que quiera multiplicar:\n");
    scanf("%i", &multiplicando);

    tablaMultiplicar(&multiplicando);

    system("pause");
    system("cls");

    //EJERCICIO 5

    int operandoA=0;
    int operandoB=0;

    printf("Ingrese primer operando:\n");
    scanf("%i", &operandoA);

    printf("Ingrese segundo operando:\n");
    scanf("%i", &operandoB);

    funcionSuma(&operandoA, &operandoB);
    funcionResta(&operandoA, &operandoB);
    funcionMultiplicacion(&operandoA, &operandoB);
    funcionDivision(&operandoA, &operandoB);

    system("pause");
    system("cls");

    //EJERCICIO 6
    int numeroPositivo=0;

    printf("Ingrese un numero positivo:\n");
    scanf("%i", &numeroPositivo);

    int numeroNegativo= cambioNegativo(&numeroPositivo);

    printf("El numero negativo es: %i \n", numeroNegativo);

    system("pause");
    system("cls");

    //EJERCICIO 7

    int enteroA=0;
    int enteroB=0;

    cargaValores(&enteroA, &enteroB);

    return 0;
}

//FUNCIONES
int valorAleatorio(int numeroAleatorio){
    numeroAleatorio=rand()% 100;
    return numeroAleatorio;
}

void mayorNumero(int *numeroA, int *numeroB, int *numeroC){
    if(*numeroA >= *numeroB && *numeroA>=*numeroC && *numeroB>=*numeroC){
        printf("El numero mayor es: %i \n", *numeroA);
        printf("El numero menor es: %i \n", *numeroC);
        }
    else if(*numeroA >= *numeroB && *numeroA>=*numeroC && *numeroC>=*numeroB){
        printf("El numero mayor es: %i \n", *numeroA);
        printf("El numero menor es: %i \n", *numeroB);
        }
    else if(*numeroB >= *numeroA && *numeroB>=*numeroC && *numeroA>=*numeroC){
        printf("El numero mayor es: %i \n", *numeroB);
        printf("El numero menor es: %i \n", *numeroC);
        }
    else if(*numeroB >= *numeroA && *numeroB>=*numeroC && *numeroC>=*numeroA){
        printf("El numero mayor es: %i \n", *numeroB);
        printf("El numero menor es: %i \n", *numeroA);
        }
    else if(*numeroC >= *numeroA && *numeroC>=*numeroB && *numeroA>=*numeroB){
        printf("El numero mayor es: %i \n", *numeroC);
        printf("El numero menor es: %i \n", *numeroB);
        }
    else{
        printf("El numero mayor es: %i \n", *numeroC);
        printf("El numero menor es: %i \n", *numeroA);
        }
}

int sumarNumeros(int *numeroSumado){
    int resultadoSuma=0;
    while(*numeroSumado>0){
        *numeroSumado=*numeroSumado-1;
        resultadoSuma=resultadoSuma+*numeroSumado;
    }
    return resultadoSuma;
}

void tablaMultiplicar(int *multiplicando){
    int resultado=0;
    for(int i=1; i<10; i++){
        resultado=*multiplicando*i;
        printf("%i X %i: %i \n", *multiplicando, i, resultado);
    }
}

void funcionSuma(int *operandoA, int *operandoB){
    printf("SUMA: %i \n", *operandoA + *operandoB);
}

void funcionResta(int *operandoA, int *operandoB){
    printf("RESTA: %i \n", *operandoA - *operandoB);
}

void funcionMultiplicacion(int *operandoA, int *operandoB){
    printf("MULTIPLICACION: %i \n", *operandoA * *operandoB);
}

void funcionDivision(int *operandoA, int *operandoB){
    printf("DIVISION: %i \n", *operandoA / *operandoB);
}

int cambioNegativo(int *numeroPositivo){
    *numeroPositivo=*numeroPositivo*(-1);
    return *numeroPositivo;
}

void cargaValores(int *enteroA, int *enteroB){
    printf("Ingrese primer numero entero:\n");
    scanf("%i", &enteroA);

    printf("Ingrese segundo numero entero:\n");
    scanf("%i", &enteroB);

    printf("Usted cargo los enteros: %i y %i \n", enteroA, enteroB);
}
