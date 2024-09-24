//CLASE 7 - Arrays (Vectores y matrices)

int seleccion = 0;

int[] puntosSaludEnemigos = new int[5];
int dano = 10;
int[] posicionEnemigos = new int[10];

Console.WriteLine("Ingrese el numero de ejercicio:");

Console.WriteLine("\n1-Ataque por área\r\nUn código que utilice un array para almacenar los puntos de salud de varios enemigos. Luego, a través de bucle for se le reste un número fijo de salud a cada uno de los enemigos.");
Console.WriteLine("\n2-Actualización de Posiciones de Enemigos\r\nUn código que utilice un array para almacenar las posiciones de varios enemigos en el juego (número entero). Luego, a través de un bucle for, simular la actualización la posición de cada enemigo sumándole 5 puntos.");

seleccion = int.Parse(Console.ReadLine());

Console.Clear();

switch (seleccion)
{
    case 1:
        //ASIGNO PUNTOS DE SALUD
        for (int i=0; i<5; i++)
        {
            puntosSaludEnemigos[i] = 100 * (i+1);
        }

        //RESTO PUNTOS DE SALUD
        for (int i=0; i < 5; i++)
        {
            puntosSaludEnemigos[i] -= dano;
            Console.WriteLine("El enemigo "+ i + " ha quedado con " + puntosSaludEnemigos[i] + " puntos de vida.");
        }
        break;

    case 2:
        for (int i = 0; i < 5; i++)
        {
            posicionEnemigos[i] += i * 3;
            Console.WriteLine("El enemigo " + i + " se ha desplazado " + posicionEnemigos[i] + " metros.");
        }

        break;
    default:
        Console.WriteLine("Usted ha ingresado una opción inválida.");
        break;
}