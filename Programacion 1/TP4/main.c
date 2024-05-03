#include <stdio.h>
#include <stdlib.h>
#define ESC 27
#define DIMENSION 10

//PROTOTIPOS
void cargaManual(int matriz [DIMENSION] [DIMENSION]);
void cargaAutomatica(int matriz [DIMENSION] [DIMENSION]);
void cargaAleatoria(int matriz [DIMENSION] [DIMENSION]);
void mostrarMatriz(int matriz[DIMENSION] [DIMENSION]);
int sumarMatriz(int matriz[DIMENSION] [DIMENSION], int *resultadoSuma);
int promedioMatriz(int matriz[DIMENSION] [DIMENSION], int *resultadoSuma, float *promedio);
void buscarElemento (int matriz[DIMENSION] [DIMENSION], int elementoBuscado);
int cargarStrings (char matrizCaracteres[DIMENSION] [DIMENSION]);
void mostrarArreglo (char matrizCaracteres[DIMENSION] [DIMENSION]);
void cargaAutomaticaStrings(char matrizCaracteres[DIMENSION] [DIMENSION]);
int encontrarString(char matrizCaracteres[DIMENSION] [DIMENSION], char buscarString[DIMENSION][DIMENSION]);
void mostrarMatrizStrings(char matrizCaracteres[DIMENSION] [DIMENSION]);
void ordenamientoSeleccionStrings(char matrizCaracteres[DIMENSION][DIMENSION]);
int buscarPosicionPalabraMenor (char matrizCaracteres[DIMENSION][DIMENSION], int indice);
void intercambioPalabra(char matrizCaracteres[DIMENSION][DIMENSION], int posicionMenor, int indice);

int main()
{
    //VARIABLES
    srand(time(NULL));
    int ejercicio;
    int matriz [DIMENSION] [DIMENSION];
    char matrizCaracteres [DIMENSION] [DIMENSION];
    int validos=0;
    int resultadoSuma=0;
    float promedio=0;
    int elementoBuscado=0;
    int contarPalabras=0;
    char buscarString[DIMENSION][DIMENSION];
    int stringEncontrado=0;

    //MENU
    printf("Ingrese numero de ejercicio: \n");
    printf("\t 1.Cargar matriz manualmente. \n");
    printf("\t 2.Mostrar matriz en formato matricial. \n");
    printf("\t 3.Cargar numeros aleatorios. \n");
    printf("\t 4.Sumar contenido de la Matriz. \n");
    printf("\t 5.Calcular promedio de la Matriz. \n");
    printf("\t 6.Buscar elemento en la Matriz. \n");
    printf("\t 7.Cargar Matriz de Strings. \n");
    printf("\t 8.Cargar palabra y mostrarla. \n");
    printf("\t 9.Buscar string en la Matriz. \n");
    printf("\t 10.Buscar string en arreglo ordenado. \n");
    printf("\t 11.Ordenar matriz alfabeticamente. \n");
    scanf("%i", &ejercicio);

    system("cls");

    switch(ejercicio){

    case 1:
        printf("EJERCICIO 1: \n");
        cargaManual(matriz);
    break;

    case 2:
        printf("EJERCICIO 2: \n");
        cargaAutomatica(matriz);
    break;

    case 3:
        printf("EJERCICIO 3: \n");
        cargaAleatoria(matriz);
    break;

    case 4:
        printf("EJERCICIO 4: \n");
        resultadoSuma=sumarMatriz(matriz, &resultadoSuma);
        printf("El resultado final de suma de la matriz es: %i \n", resultadoSuma);
    break;

    case 5:
        printf("EJERCICIO 5: \n");
        promedio=promedioMatriz(matriz, &promedio, &resultadoSuma);
        printf("El promedio de la matriz es: %.2f \n", promedio);
    break;

    case 6:
        printf("EJERCICIO 6: \n");

        printf("Ingrese el numero que desea buscar en la Matriz: \n");
        fflush(stdin);
        scanf("%i", &elementoBuscado);

        buscarElemento (matriz, elementoBuscado);
    break;

    case 7:
        printf("EJERCICIO 7: \n");
        contarPalabras=cargarStrings (matrizCaracteres);
        printf("La cantidad de palabras ingresadas es: %i \n", contarPalabras);
    break;

    case 8:
        printf("EJERCICIO 8: \n");
        mostrarArreglo (matrizCaracteres);
    break;

    case 9:
        printf("EJERCICIO 9: \n");
        //cargaAutomaticaStrings(matrizCaracteres);
        contarPalabras=cargarStrings (matrizCaracteres);
        mostrarMatrizStrings(matrizCaracteres);

        printf("Ingrese la palabra que quiere buscar: \n");
        fflush(stdin);
        gets(buscarString);

        stringEncontrado=encontrarString(matrizCaracteres, buscarString);

        if(stringEncontrado==-1){
            printf("La palabra buscada %s NO se encuentra en el arreglo\n", buscarString);
        }
        else{
            printf("La palabra buscada %s se encuentra en la posicion %d del arreglo\n", buscarString, stringEncontrado);
        }
    break;

    case 10:
        printf("EJERCICIO 10: \n");
        contarPalabras=cargarStrings (matrizCaracteres);
        mostrarMatrizStrings(matrizCaracteres);

        printf("Ingrese la palabra que quiere buscar: \n");
        fflush(stdin);
        gets(buscarString);

        stringEncontrado=encontrarString(matrizCaracteres, buscarString);

        if(stringEncontrado==-1){
            printf("La palabra buscada %s NO se encuentra en el arreglo\n", buscarString);
        }
        else{
            printf("La palabra buscada %s se encuentra en la posicion %d del arreglo ordenado. \n", buscarString, stringEncontrado);
        }
    break;

    case 11:
            printf("EJERCICIO 11: \n");
            contarPalabras=cargarStrings(matrizCaracteres);

            ordenamientoSeleccionStrings(matrizCaracteres);

            mostrarMatrizStrings(matrizCaracteres);
    break;

    default:
    break;
    }

    return 0;
}

//FUNCIONES
void cargaManual(int matriz [DIMENSION] [DIMENSION]){
    int numeroIngresado=0;
    int salir;

    for (int i=0; i<DIMENSION; i++ && salir!=ESC){
        for(int j=0; j<DIMENSION; j++ && salir!=ESC){
            printf("Ingrese un numero para cargar la matriz: \n");
            fflush(stdin);
            scanf("%i", &numeroIngresado);

            matriz[i][j]=numeroIngresado;

            printf("Presione cualquier tecla para continuar o presione ESC para salir. \n");
            fflush(stdin);
            salir=getch();
            }
        }
        if(salir==ESC){
            printf("EL PROGRAMA HA SIDO CERRADO");
        }
    mostrarMatriz(matriz);
}

void mostrarMatriz(int matriz[DIMENSION] [DIMENSION]){
    system("cls");
    printf("La matriz fue cargada con: \n");

    for(int i=0; i<DIMENSION; i++){

        for(int j=0; j<DIMENSION; j++){
            printf("[%i]|", matriz[i][j]);
        }
            printf("\n_________________________________________\n\n");
    }
}

void cargaAutomatica(int matriz [DIMENSION] [DIMENSION]){
    int numeroIngresado=0;

    for (int i=0; i<DIMENSION; i++){
            for(int j=0; j<DIMENSION; j++){
                matriz[i][j]=numeroIngresado;
                numeroIngresado++;
            }
        }
    mostrarMatriz(matriz);
}

void cargaAleatoria(int matriz [DIMENSION] [DIMENSION]){
    int numeroAleatorio=rand()%100;

    for (int i=0; i<DIMENSION; i++){
            for(int j=0; j<DIMENSION; j++){
                matriz[i][j]=numeroAleatorio;
                numeroAleatorio=rand()%100;
                }
            }
    mostrarMatriz(matriz);
}

int sumarMatriz(int matriz[DIMENSION] [DIMENSION], int *resultadoSuma){
    cargaAleatoria(matriz);

    for(int i=0; i<DIMENSION; i++){
        for(int j=0; j<DIMENSION; j++){
            *resultadoSuma=matriz[i][j]+*resultadoSuma;
        }
    }
    return *resultadoSuma;
}

int promedioMatriz(int matriz[DIMENSION] [DIMENSION], int *resultadoSuma, float *promedio){
    cargaAleatoria(matriz);

    for(int i=0; i<DIMENSION; i++){
        for(int j=0; j<DIMENSION; j++){
            *resultadoSuma=matriz[i][j]+*resultadoSuma;
        }
    }
    *promedio=*resultadoSuma/(DIMENSION*2);

    return *promedio;
}

void buscarElemento (int matriz[DIMENSION] [DIMENSION], int elementoBuscado){

    cargaAutomatica(matriz);

    int elementoEncontrado=0;

    for(int i=0; i<DIMENSION; i++){
        for(int j=0; j<DIMENSION; j++){
            if(elementoBuscado==matriz[i][j]){
                elementoEncontrado=1;
            }
        }
    }
    if (elementoEncontrado==1){
        printf("El numero %i se encuentra dentro de la matriz. \n", elementoBuscado);
        }
    else{
        printf("El numero %i NO ha sido encontrado. \n", elementoBuscado);
        }
}

int cargarStrings (char matrizCaracteres[DIMENSION] [DIMENSION]){
    int numero= 0;
    char control= 's';

    while ((numero<DIMENSION) && (control=='s'))
    {
          printf("Ingrese una palabra para ser cargada en la matriz: \n");
          fflush(stdin);
          gets (matrizCaracteres[numero]);

          printf("\n Desea continuar cargando palabras? s/n \n");
          fflush(stdin);
          scanf("%c", &control);

          numero++;
      }
      return numero;
}

void mostrarArreglo (char matrizCaracteres[DIMENSION] [DIMENSION]){
        int indice=0;

        printf("\n Ingrese una palabra para ser cargada en la matriz: \n");
        fflush(stdin);
        gets (matrizCaracteres[indice]);

        printf("\n La palabra que usted ingreso fue: %s \n", matrizCaracteres[indice]);
}

void cargaAutomaticaStrings(char matrizCaracteres[DIMENSION][DIMENSION]){
        int i,j=0;

        //gets (matrizCaracteres[i]);
        matrizCaracteres[i][j]='PERRO';
        i++;

        matrizCaracteres[i][j]='GATO';
        i++;

        matrizCaracteres[i][j]='RATON';
        i++;

        matrizCaracteres[i][j]='PAJARO';
        i++;

        matrizCaracteres[i][j]='PEZ';
        i++;

        matrizCaracteres[i][j]='DELFIN';
        i++;
}

void mostrarMatrizStrings(char matrizCaracteres[DIMENSION] [DIMENSION]){
    system("cls");
    printf("La matriz fue cargada con: \n");

    for(int i=0; i<DIMENSION; i++){
            printf("%s", matrizCaracteres[i]);
            printf("\n_________________________________________\n\n");
        }
}

int encontrarString(char matrizCaracteres[DIMENSION] [DIMENSION], char buscarString[DIMENSION][DIMENSION]){
    int stringEncontrado=-1;
    int indice= 0;

    while ((indice<DIMENSION) && (stringEncontrado==-1)){
        if (strcmpi(buscarString, matrizCaracteres[indice])==0)
        {
            stringEncontrado = indice;
        }
        indice ++;
    }
    return stringEncontrado;
}

void ordenamientoSeleccionStrings(char matrizCaracteres[DIMENSION][DIMENSION]){
    int indice;
    int posicionMenor;

    for (indice=0; indice<DIMENSION; indice++)
    {
        posicionMenor=buscarPosicionPalabraMenor (matrizCaracteres, indice);
        intercambioPalabra(matrizCaracteres, posicionMenor, indice);
    }
}

int buscarPosicionPalabraMenor (char matrizCaracteres[DIMENSION][DIMENSION], int indice){
    int posicionMenor=indice;
    char palabraMenor[DIMENSION][DIMENSION];
    strcpy(palabraMenor, matrizCaracteres[indice]);

    for (int i=indice+1; i<DIMENSION; i++){
        if(strcmpi(palabraMenor, matrizCaracteres[i])>0)
        {
            strcpy (palabraMenor, matrizCaracteres[i]);
            posicionMenor=i;
        }
    }
    return posicionMenor;
}

void intercambioPalabra(char matrizCaracteres[DIMENSION][DIMENSION], int posicionMenor, int indice){
    char matrizAuxiliar[DIMENSION][DIMENSION];
    strcpy(matrizAuxiliar, matrizCaracteres[posicionMenor]);
    strcpy(matrizCaracteres[posicionMenor],matrizCaracteres[indice]);
    strcpy(matrizCaracteres[indice], matrizAuxiliar);
}
