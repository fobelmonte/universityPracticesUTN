#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

//PROTOTIPOS
void cargarPila(Pila *pilaResultado);
void pasarPila(Pila *pilaPrincipal);
void pasarPilaOrdenada(Pila *pilaPrincipal);
int encontrarMenorValor(Pila *pilaPrincipal);
void ordenarPilaAscendente (Pila *pilaPrincipal, Pila *pilaResultado);
Pila insertarEnOrden(Pila pilaResultado, int numInsertar);
void insertarPilaOrdenada (Pila *pilaPrincipal, Pila *pilaResultado);
int sumarNumeros(Pila pilaPrincipal);

int sumaPromedio(Pila pilaPrincipal);
float divisionPromedio(int pilaSumada);
void promedioPila (Pila pilaPrincipal);

int decimalPila(Pila pilaResultado);

int main()
{
    //VARIABLES
    srand (time(NULL));
    int valorAleatorio=0;
    valorAleatorio=rand()% 100;

    int numeroMenor=0;
    int numerosSuma=0;
    int numInsertar=0;

    int ejercicio;

    Pila pilaPrincipal, pilaResultado;
    inicpila(&pilaPrincipal);
    inicpila(&pilaResultado);

    //CARGAR PILA PRINCIPAL CON 10 NUMEROS ALEATORIOS
    for(int i=0; i<10; i++){
        apilar(&pilaPrincipal, valorAleatorio);
        valorAleatorio=rand()% 100;
    }

    //MENU
    printf("Bienvenido al menu. \n Ingrese el numero de ejercicio que desea consultar.\n \t\n 1.Cargar pila.\n 2.Pasar de una pila a otra desordenada. \n 3.Pasar de una pila a otra en orden\n 4.Encontrar numero menor.\n 5.Ordenar Pila.\n 6.Ordenar pila con insercion.\n 7.Ordenar una pila desordenada por insercion.\n 8.Sumar los dos primeros numeros.\n 9.Calcular promedio de la pila.\n 10.Cargar pila y hacer decimal.\n");
    scanf("%i", &ejercicio);

    system("cls");

    //EJERCICIOS
    switch(ejercicio){

    case 1:
        cargarPila(&pilaResultado);
        break;

    case 2:
        pasarPila(&pilaPrincipal);
        break;

    case 3:
        pasarPilaOrdenada(&pilaPrincipal);
        break;

    case 4:
        numeroMenor=encontrarMenorValor(&pilaPrincipal);

        printf("El numero menor de la pila fue: %i \n", numeroMenor);
        break;

    case 5:
        ordenarPilaAscendente (&pilaPrincipal, &pilaResultado);
        break;

    case 6:
        for(int i=10; i>0; i--){
            apilar(&pilaResultado, i);
        }

        printf("LA PILA FUE CARGADA CON: \n");
        mostrar(&pilaResultado);

        printf("Ingrese el valor que desee cargar a la pila.\n");
        scanf("%i", &numInsertar);

        pilaResultado=insertarEnOrden(pilaResultado, numInsertar);

        printf("LA PILA ORDENADA QUEDO: \n");
        mostrar(&pilaResultado);
        break;

    case 7:

        break;

    case 8:
        numerosSuma=sumarNumeros(pilaPrincipal);
        printf("EL RESULTADO FINAL FUE: %i \n", numerosSuma);
        break;

    case 9:
        promedioPila(pilaPrincipal);
        break;

    case 10:
        decimalPila(pilaResultado);
        break;

    default:
        printf("HA INGRESADO UNA OPCION NO VALIDA\n");
        break;
    }
    return 0;
}

void cargarPila(Pila *pilaResultado){
        char control='s';
        while(control=='s'){
            printf("Ingrese el valor que desee cargar a la pila.\n");
            leer(pilaResultado);
            printf("Desea cargar otro numero?. s/n \n");
                fflush(stdin);
                scanf("%c", &control);
        }
        printf("LA PILA FUE CARGADA CON: \n");
        mostrar(pilaResultado);
}

void pasarPila(Pila *pilaPrincipal){
        Pila pilaSecundaria;
        inicpila(&pilaSecundaria);

        printf("Pila antes del movimiento: \n");
        mostrar(pilaPrincipal);

        while(!pilavacia(pilaPrincipal)){
            apilar(&pilaSecundaria, desapilar(pilaPrincipal));
        }

        printf("Pila despues del pasaje de una pila a la otra: \n");

        printf("CONTENIDO DE LA PILA PRINCIPAL: \n");
        mostrar(pilaPrincipal);

        printf("CONTENIDO DE LA PILA SECUNDARIA: \n");
        mostrar(&pilaSecundaria);
}

void pasarPilaOrdenada(Pila *pilaPrincipal){
        Pila pilaSecundaria, pilaAuxiliar;
        inicpila(&pilaSecundaria);
        inicpila(&pilaAuxiliar);

        printf("Pila antes del movimiento: \n");
        mostrar(pilaPrincipal);

        while(!pilavacia(pilaPrincipal)){
            apilar(&pilaAuxiliar, desapilar(pilaPrincipal));
        }

        while(!pilavacia(&pilaAuxiliar)){
            apilar(&pilaSecundaria, desapilar(&pilaAuxiliar));
        }

        printf("Pila despues del pasaje de una pila a la otra: \n");

        printf("CONTENIDO DE LA PILA PRINCIPAL: \n");
        mostrar(pilaPrincipal);

        printf("CONTENIDO DE LA PILA SECUNDARIA: \n");
        mostrar(&pilaSecundaria);
}

int encontrarMenorValor(Pila *pilaPrincipal){
        Pila pilaSecundaria, pilaAuxiliar;
        inicpila(&pilaSecundaria);
        inicpila(&pilaAuxiliar);

        printf("La pila fue cargada con los numeros: \n");
        mostrar(pilaPrincipal);

        int menorNumero=tope(pilaPrincipal);

        apilar(&pilaAuxiliar, desapilar(pilaPrincipal));
        while(!pilavacia (pilaPrincipal)){
            int topeActual=tope(&pilaAuxiliar);
            if(menorNumero>=topeActual){
                menorNumero=topeActual;
            }
            apilar(&pilaAuxiliar, desapilar(pilaPrincipal));
        }

        while(!pilavacia(&pilaAuxiliar)){
            if(tope(&pilaAuxiliar)==menorNumero){
                apilar(&pilaSecundaria, desapilar(&pilaAuxiliar));
            }
            else{
                apilar(pilaPrincipal, desapilar(&pilaAuxiliar));
            }
        }

        printf("Luego de extraer el numero menor, la pila quedo cargada con los numeros: \n");
        mostrar(pilaPrincipal);

        return menorNumero;
}

void ordenarPilaAscendente (Pila *pilaPrincipal, Pila *pilaResultado){
        while (!pilavacia(pilaPrincipal)){
            apilar(pilaResultado, encontrarMenorValor(pilaPrincipal));
        }
        printf("EL RESULTADO FINAL FUE: \n");
        mostrar(pilaResultado);
}

Pila insertarEnOrden(Pila pilaResultado, int numInsertar)
{
        Pila pilaAuxiliar;
        inicpila(&pilaAuxiliar);

        while (!pilavacia(&pilaResultado) && (tope(&pilaResultado)<numInsertar)){
            apilar(&pilaAuxiliar, desapilar(&pilaResultado));
        }

        apilar(&pilaResultado, numInsertar);

        while (!pilavacia(&pilaAuxiliar))
        {
            apilar(&pilaResultado, desapilar(&pilaAuxiliar));
        }

        return pilaResultado;
}

int sumarNumeros(Pila pilaPrincipal){
        Pila pilaAuxiliar;
        inicpila(&pilaAuxiliar);

        int resultado=0;
        int num=0;

        printf("ANTES de la suma la PILA PRINCIPAL CONTIENE: \n");
        mostrar(&pilaPrincipal);

        for(int i=0; i<2; i++){
            num=tope(&pilaPrincipal);
            apilar(&pilaAuxiliar, desapilar(&pilaPrincipal));
            resultado=num+resultado;
        }

        while (!pilavacia(&pilaPrincipal)){
            apilar(&pilaAuxiliar, desapilar(&pilaPrincipal));
        }
        while(!pilavacia(&pilaAuxiliar)){
            apilar(&pilaPrincipal, desapilar(&pilaAuxiliar));
        }

        printf("DESPUES de la suma la PILA PRINCIPAL CONTIENE: \n");
        mostrar(&pilaPrincipal);

        return resultado;
}

int sumaPromedio (Pila pilaPrincipal){
        Pila pilaAuxiliar;
        inicpila(&pilaAuxiliar);

        int num=0;
        int resultado=0;

        printf("La pila CONTIENE: \n");
        mostrar(&pilaPrincipal);

        while (!pilavacia(&pilaPrincipal)){
            num=tope(&pilaPrincipal);
            apilar(&pilaAuxiliar, desapilar(&pilaPrincipal));
            resultado=num+resultado;
        }

        printf("\t\n EL RESULTADO FINAL DE LA SUMA FUE: %i \n", resultado);

        return resultado;
}

float divisionPromedio (int pilaSumada){
        float promedio=pilaSumada/10;
        return promedio;
}

void promedioPila(Pila pilaPrincipal){
        int pilaSumada=0;
        float pilaPromedio=0;

        pilaSumada = sumaPromedio(pilaPrincipal);
        pilaPromedio=divisionPromedio(pilaSumada);

        printf("\t\n EL PROMEDIO ES: %.2f \n", pilaPromedio);
}

int decimalPila(Pila pilaResultado){
        char control='s';
        int multiplicador=1;
        int resultado=0;

        while(control=='s'){
            printf("Ingrese el valor de un solo digito que desee cargar a la pila.\n");
            leer(&pilaResultado);

            resultado=tope(&pilaResultado)*multiplicador+resultado;
            multiplicador=multiplicador*10;

            printf("Desea cargar otro numero?. s/n \n");
                fflush(stdin);
                scanf("%c", &control);
        }

        system("cls");

        printf("LA PILA FUE CARGADA CON: \n");
        mostrar(&pilaResultado);

        printf("EL RESULTADO FINAL FUE: %i \n", resultado);
}
