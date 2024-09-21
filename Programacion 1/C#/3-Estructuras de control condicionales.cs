//CLASE 5

int seleccion = 0;

int vidaJugador = 0;
int seleccionArma = 0;

Console.WriteLine("Ingrese el numero de ejercicio:");

Console.WriteLine("1-Vida del jugador. \n Escribe un programa que te solicite el ingreso por consola de la vida del jugador. Si la vida es de 0 o menos, debe imprimirse un mensaje de derrota. Si la vida es superior a 0, debe imprimirse que el jugador está vivo.");
Console.WriteLine("2-Arma del jugador. \n Desarrolla un programa donde el jugador pueda ingresar por consola un arma. Elige entre las siguientes armas: \"Espada\", \"Arco\" y \"Magia\". Utiliza una estructura switch para mostrar un mensaje dependiendo del arma seleccionada, indicando las características y habilidades especiales de cada una.");

seleccion = int.Parse(Console.ReadLine());

Console.Clear();

switch (seleccion)
{
    //EJERCICIO 1

    case 1:
        Console.WriteLine("VIDA DEL JUGADOR");

        Console.WriteLine("Ingrese cantidad de vida:");

        vidaJugador = int.Parse(Console.ReadLine());

        if (vidaJugador > 0)
        {
            Console.WriteLine("El jugador esta vivo.");
        }
        else
        {
            Console.WriteLine("El jugador ha sido derrotado. \nGAME OVER");
        }

        Console.ReadKey();
        Console.Clear();
        break;

    case 2:
        Console.WriteLine("ARMA DEL JUGADOR");

        Console.WriteLine("Seleccione un arma:");
        Console.WriteLine("1-Espada");
        Console.WriteLine("2-Arco");
        Console.WriteLine("3-Magia");

        seleccionArma = int.Parse(Console.ReadLine());

        switch (seleccionArma)
        {
            case 1:
                Console.WriteLine("Has seleccionado la Espada. Este arma causa 10 de daño y tiene alcance corto.");
                break;

            case 2:
                Console.WriteLine("Has seleccionado el arco. Este arma causa 5 de daño y tiene alcance largo.");
                break;

            case 3:
                Console.WriteLine("Has seleccionado la magia. Este poder causa 7 de daño y tiene alcance medio.");
                break;

            default:
                Console.WriteLine("Ha ingresado un número inválido.");
                break;
        }
        Console.ReadKey();
        Console.Clear();
        break;

    default:
        Console.WriteLine("Ha ingresado un número inválido.");
        break;

}