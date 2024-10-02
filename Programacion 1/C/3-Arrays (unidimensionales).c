#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

/* 3-Arrays/Arreglos Vectores
ACLARACION: Libreria de pilas no incluida en github.

1. Hacer una función que reciba como parámetro un arreglo de números enteros y permita que
el usuario ingrese valores al mismo por teclado. La función debe retornar la cantidad de
elementos cargados en el arreglo (o pueden utilizar como puntero válidos).
2. Hacer una función que reciba como parámetro un arreglo y la cantidad de elementos (válidos)
cargados en él y los muestre por pantalla.
3. Hacer una función que reciba como parámetro un arreglo y la cantidad de elementos (válidos)
cargados en él y calcule la suma de sus elementos.
4. Hacer una función que reciba como parámetro un arreglo, la cantidad de elementos (válidos)
cargados en él y una Pila. La función debe copiar los elementos del arreglo en la pila.
5. Realizar una función que sume los elementos de un arreglo de números reales (float) de
dimensión 100. (se recomienda hacer una función para cargar y otra para mostrar para este
tipo de dato asociado al arreglo)
6. Realizar una función que indique si un elemento dado se encuentra en un arreglo de
caracteres.
7. Realizar una función que inserte un carácter en un arreglo ordenado alfabéticamente,
conservando el orden.
8. Realizar una función que obtenga el máximo carácter de un arreglo dado.
9. Realizar una función que determine si un arreglo es capicúa.
10. Realizar una función que invierta los elementos de un arreglo. (sin utilizar un arreglo auxiliar)
11. Ordenar un arreglo según los siguientes métodos:
a. Selección
b. Inserción
12. Dados dos arreglos ordenados alfabéticamente, crear un tercer arreglo con los elementos de
los dos primeros intercalados, de manera que quede un arreglo también ordenado
alfabéticamente.
*/

///////////

//PROTOTIPOS
int cargararreglo (int A [], int cantidad);
int cargararreglochar (char B [], int cantidad);
int cargaArregloReales (float D [], int cantidad);
void mostrararreglo (int A[], int validos);
int sumar (int A[], int validos);
float sumareal (float D[], int validosR);
char buscarMayor (char B [], int validos2);
void invertirArreglo (int A [], int C [], int validos);
void invertirArreglo2 (char A [], int validos);
void copiarapila (int A[], Pila *P, int validos);
int buscarChar (char B [], int validos2, char dato);
int insertarChar (char B [], int validos, char elemento);
void mostrarArregloChar (char B[], int validos2);
int capicua (int A[], int validos);
int posicionMenor (int A[], int pos, int validos);
void ordenacionSeleccion (int A[], int validos);
void insertar(int A[], int u, int dato);
void ordenacionInsercion (int A[], int validos);
int CharIntercalado (char F[], int validosF, char G [], int validosG, char H[], int cantidadH);

///////////
// MAIN:
int main()
{
    int A [5]={0};
    char B [10]={0};
    int C [5]={0};
    float D [100]={0};
    int E [5]={0};
    char F [4]={0};
    char G [5]={0};
    char H [20]={0};

//Ejercicio 1

    int validos=cargararreglo (A, 5);
    printf("Cantidad de elementos cargados en el arreglo: %d", validos);

//Ejercicio 2
    mostrararreglo (A, validos);

//Ejercicio 3

    int res=sumar (A, validos);
    printf("\n La suma de todos los elementos incluidos en la lista A es: %d\n", res);

//Ejercicio 4

    Pila Mipila;
    inicpila(&Mipila);
    copiarapila (A, &Mipila, validos);
    mostrararreglo(A, validos);
    printf("\nPila 'Mipila':   \n");
    mostrar (&Mipila);

//Ejercicio 5

    int validosR=cargaArregloReales (D, 100);
    float resR=sumareal (D, validosR);
    printf("\nLa suma de todos los elementos de la lista D es: %f\n", resR);

//Ejercicio 6

    int validos2=cargararreglochar (B, 5);
    char dato3=0;
    printf("\nIngrese la letra a buscar en el arreglo: ");
    fflush(stdin);
    scanf("%c",&dato3);
    int flag = buscarChar (B, validos2, dato3);
    if (flag==1) {
        printf("\nLa letra %c si se encuentra en el arreglo\n", dato3);
    }
    else {
        printf("\nLa letra %c no se encuentra en el arreglo\n", dato3);
    }

//Ejercicio 7
   char dato=0;
   printf("\n\nIngrese el caracter a insertar en el arreglo ordenado alfabeticamente: ");
   fflush(stdin);
   scanf("%c",&dato);
   validos2=insertarChar (B, validos2, dato);
   printf("\nArreglo luego de la insercion:  ");
   mostrarArregloChar (B, validos2);

//Ejercicio 8
    char mayor=buscarMayor (B, validos2);
    printf("\nEl mayor de los elementos de la lista B es:  %c\n", mayor);

//Ejercicio 9
    int validosC=cargararreglo (E, 5);
    int flag2 = capicua (E, validosC);
    if (flag2==0)
        printf("\nEl arreglo es capicua");
    else
        printf("\nEl arreglo no es capicua");

//Ejercicio 10
    invertirArreglo2 (A, validos);
    printf("\nLos elementos de la lista A luego de la inversion son:   \n");
    mostrararreglo (A, validos);

//Ejercicio 11
    printf("\n Ordenar por seleccion el arreglo...");
    int arregloOrdenSeleccion[]= {4,1,2,45,2,1,22,9};
    mostrararreglo(arregloOrdenSeleccion,8);
    ordenacionSeleccion(arregloOrdenSeleccion, 8);
    mostrararreglo(arregloOrdenSeleccion,8);

    printf("\n Ordenar por insercion el arreglo...");
    int arregloOrdenInsercion[]= {4,1,2,45,2,1,22,9};
    mostrararreglo(arregloOrdenInsercion,8);
    ordenacionInsercion(arregloOrdenInsercion, 8);
    mostrararreglo(arregloOrdenInsercion, 8);

//Ejercicio 12

    int validosF= cargararreglochar (F, 4);
    printf("Arreglo F");
    mostrarArregloChar(F, validosF);

    int validosG= cargararreglochar (G, 5);
    printf("Arreglo G");
    mostrarArregloChar(G, validosG);

    int validosH=CharIntercalado (F, validosF, G, validosG, H, 20);

    printf("\nArreglo H\n");
    mostrarArregloChar (H, validosH);
    return 0;
}

// FUNCIONES:

//Ejercicio 1

int cargararreglo (int A [], int dimension)
{
    char letra='s';
    int validos=0;
    while ((letra=='s') && (validos<dimension))
    {
        printf("\nIngrese un Nro entero  ");
        fflush(stdin);
        scanf("%d", &A[validos]);
        validos++;
        printf("\ndesea ingresar mas elementos a la lista? (s/n) \n");
        fflush(stdin);
        scanf("%c", &letra);
    }
    return validos;
}

int cargararreglochar (char B [], int dimension)
{
    int validos2=0;
    while (validos2 < dimension)
    {
        printf("\nIngrese una letra  ");
        fflush(stdin);
        scanf("%c", &B[validos2]);
        validos2++;
    }
    return validos2;
}

int cargaArregloReales(float D [], int dimension)
{
    char letra='s';
    int validosR=0;
    while ((letra=='s') && (validosR<dimension))
    {
        printf("\nIngrese un Nro real  ");
        fflush(stdin);
        scanf("%f", &D[validosR]);
        validosR++;
        printf("\ndesea ingresar mas Nros reales a la lista? (s/n) ");
        fflush(stdin);
        scanf("%c", &letra);
    }
    return validosR;
}

//Ejercicio 2

void mostrararreglo (int A[], int validos)
{
    int i=0;
    printf("\nContenido del arreglo:  ");
    for (i=0; i<validos; i++)
    {
        printf(" | %d | ", A[i]);
    }
}

void mostrarArregloChar (char B[], int validos2)
{
    int i=0;
    printf("\nContenido del arreglo:  ");
    for (i=0; i<validos2; i++)
    {
        printf("%c  ", B[i]);
    }
}

//Ejercicio 3

int sumar (int A[], int validos)
{
    int rta=0;
    int i=0;
    for (i=0; i<validos; i++)
    {
        rta= rta + A[i];
    }
    return rta;
}

//Ejercicio 4

void copiarapila (int A[], Pila* PDestino, int validos)
{
    int i=0;
    while (i<validos && i<50)
    {
        apilar(PDestino, A[i]);
        i++;
    }
}

//Ejercicio 5

float sumareal (float D[], int validosR)
{
    float rta=0;
    int i=0;
    for (i=0; i<validosR; i++)
    {
        rta= rta+D[i];
    }
    return rta;
}

//Ejercicio 6

int buscarChar (char B[], int validos, char dato)
{
    int i = 0;
    int flag = 0;

    while ((i < validos) && (flag == 0))
    {
        if (dato == B[i]) {
            flag =1;
        }
        else {
            i++;
        }
    }
  return flag;
}

//Ejercicio 7

int insertarChar (char B [], int validos, char dato)
{
    int ult = validos-1;
    while (ult>=0 && dato < B[ult])
    {
        B[ult+1]=B[ult];
        ult--;
    }
    B[ult+1]=dato;
return validos+1;
}


//Ejercicio 8
char buscarMayor (char B [], int validos2)
{
    char miMayor= B[0];
    int i=1;
    for (i=1; i<validos2; i++)
    {
        if (miMayor < B[i])
        {
            miMayor= B[i];
        }
    }
return miMayor;
}

int buscarMenor (int B[], int validos)
{
    int miMenor= B[0];
    int i=1;

    for (i=1; i<validos; i++)
    {
        if (miMenor > B[i])
        {
            miMenor= B[i];
        }
    }
return miMenor;
}

//Ejercicio 9

int capicua (int A[], int validos)
{
    int flag = 0;
    int i=0;
    int ult = validos-1;

    while(i<ult && flag ==0)
    {
        if (A[i]==A[ult])
        {
            i++;
            ult--;
        }
        else
            flag =1;
        }
    return flag;
}


//Ejercicio 10

void invertirArreglo (int A [], int C [], int validos)
{
    int iA=0;
    int iC=validos-1;
    for (iA=0; iA<validos; iA++)
        {
        C[iC]=A [iA];
        iC --;
        }
}

//Ejercicio 11
//Metodo de ordenamiento por seleccion.

int posicionMenor (int A[], int pos, int validos)
{
    char menor = A[pos];
    int posmenor = pos;
    int i = pos +1;
    while (i<validos) {
        if (menor < A[i]) {
            menor = A[i];
            posmenor = i;
        }
        i++;
    }
    return posmenor;
}

void ordenacionSeleccion (int A[], int validos)
{
    int posmenor;
    int aux;
    int i = 0;
    while (i<validos-1) {
        posmenor = posicionMenor(A,i,validos);
        aux = A[posmenor];
        A[posmenor]=A[i];
        A[i]= aux;
        i++;
    }
}

//Metodo de Ordenamiento por Insercion.

void insertar(int A[], int u, int dato)
{
    while(u>=0 && dato<A[u])
    {
        A[u+1]=A[u];
        u--;
    }
    A[u+1]=dato;
}


void ordenacionInsercion (int A[], int validos)
{
    int i = 0;
    while (i<validos-1)
    {
        insertar(A,i,A[i+1]);
        i++;
    }
}

//Ejercicio 12

int CharIntercalado (char F[], int validosF, char G[], int valG, char H[], int dimH)
{
     int iF=0;
     int iG=0;
     int iH=0;

     while((iF<validosF) && (iG<valG) && (iH<dimH))
     {
        if (F[iF]<G[iG])
        {
            H[iH]=F[iF];
            iH++;
            iF++;
        }
        else
        {
            H[iH]=G[iG];
            iH++;
            iG++;
        }
    }
    while(iF<validosF)
    {
        H[iH]=F[iF];
        iH++;
        iF++;
    }
    while(iG<valG)
    {
        H[iH]=G[iG];
        iH++;
        iG++;
    }
return iH;
}
