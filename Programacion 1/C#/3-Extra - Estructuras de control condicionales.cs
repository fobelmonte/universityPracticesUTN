//CLASE 5 - Extra - Estructuras de control condicionales

int seleccion = 0;

int nivelJugador = 0;
int monedasJugador = 0;
string claseJugador;
float danoTotal = 0f;
int danoBase = 10;
int fuerzaJugador = 0;
int agilidadJugador = 0;
int puntosTotales = 1000;
int modificadorPuntos = 0;
int tiempoJuego = 0;
int enemigosDerrotados = 0;
int escudoJugador = 0;

Console.WriteLine("Ingrese el numero de ejercicio:");

Console.WriteLine("\n1-Nivel del jugador\r\nEscribe un programa que solicite el nivel del jugador. Si el nivel es menor a 5, muestra \"Novato\". Si el nivel está entre 5 y 10, muestra \"Intermedio\". Si es mayor a 10, muestra \"Experto\".");
Console.WriteLine("\n2-Monedas del jugador\r\nEscribe un programa que reciba la cantidad de monedas que tiene el jugador. Si tiene más de 100 monedas, muestra \"Puedes comprar una mejora\". Si tiene exactamente 100 monedas, muestra \"Puedes comprar un arma\". Si tiene menos de 100, muestra \"Necesitas más monedas\".");
Console.WriteLine("\n3-Personaje del jugador\r\nDesarrolla un programa que permita al jugador elegir entre tres personajes: \"Guerrero\", \"Mago\" y \"Arquero\". Utiliza un switch para mostrar en consola estadísticas dependiendo el personaje seleccionado. En caso de que se ingrese un nombre distinto a los solicitados, debe decir que el personaje es inválido.");
Console.WriteLine("\n4-Sistema de Combate\r\nEscribe un programa que simule un sistema de combate. Solicita al jugador su nivel, fuerza y agilidad. Tené en cuenta que:\r\n\r\nEl daño base del jugador es 10.\r\n\r\nSi el nivel es mayor a 10 y la fuerza es mayor a 15, el daño se duplica.\r\n\r\nSi la agilidad es mayor a 20, se añade un 50% al daño. Muestra el daño final.\r\n\r\nEl efecto de los dos bonus pueden darse en simultáneo.");
Console.WriteLine("\n5-Sistema de Puntuación con Bonus\r\nEscribe un programa que calcule la puntuación del jugador. Solicita el tiempo (en minutos) que el jugador tardó en completar un nivel, y la cantidad de enemigos derrotados. Si el tiempo es menor a 5 minutos y se derrotaron más de 10 enemigos, aplica un bonus de 100 puntos.\r\nSi el tiempo es mayor a 10 minutos o menos de 5 enemigos fueron derrotados, aplica una penalización de 50 puntos. Muestra la puntuación total.");
Console.WriteLine("\n6-Escudo y Defensa del Jugador\r\nEscribe un programa que determine el estado de defensa del jugador. Solicita la resistencia del escudo y la agilidad del jugador. Si la resistencia del escudo es mayor a 50 o la agilidad es mayor a 30, muestra \"Defensa Alta\". Si la resistencia del escudo es menor a 20 y la agilidad es menor a 15, muestra \"Defensa Baja\". Si no se cumplen ninguna de estas condiciones, muestra \"Defensa Media\".");

seleccion = int.Parse(Console.ReadLine());

Console.Clear();

switch (seleccion)
{
    case 1:
        Console.WriteLine("NIVEL DEL JUGADOR");

        Console.WriteLine("Ingrese el nivel del jugador:");

        nivelJugador = int.Parse(Console.ReadLine());

        if (nivelJugador < 5)
        {
            Console.WriteLine("El nivel del jugador es NOVATO.");
        }
        else if(nivelJugador <=10 && nivelJugador>=5 )
        {
            Console.WriteLine("El nivel del jugador es INTERMEDIO.");
        }
        else
        {
            Console.WriteLine("El nivel del jugador es EXPERTO.");
        }

        Console.ReadKey();
        Console.Clear();
        break;

    case 2:
        Console.WriteLine("MONEDAS DEL JUGADOR");

        Console.WriteLine("Ingrese las monedas del jugador:");

        monedasJugador = int.Parse(Console.ReadLine());

        if (monedasJugador > 100)
        {
            Console.WriteLine("Puedes comprar una mejora.");
        }
        else if (monedasJugador == 100)
        {
            Console.WriteLine("Puedes comprar un arma.");
        }
        else
        {
            Console.WriteLine("Necesitas más monedas.");
        }

        Console.ReadKey();
        Console.Clear();
        break;
    case 3:
        Console.WriteLine("CLASE DEL JUGADOR");

        Console.WriteLine("Ingrese el nombre de la clase elegida:");

        claseJugador = Console.ReadLine();

        claseJugador = claseJugador.ToUpper();

        switch (claseJugador)
        {
            case "GUERRERO":
                Console.WriteLine("Has elegido al Guerrero.");
                Console.WriteLine("\nESTADISTICAS:\n\nFUERZA:20\n\nAgilidad:10\n\nEnergia:5");
                break;

            case "MAGO":
                Console.WriteLine("Has elegido al Mago.");
                Console.WriteLine("\nESTADISTICAS:\n\nFUERZA:5\n\nAgilidad:10\n\nEnergia:20");
                break;

            case "ARQUERO":
                Console.WriteLine("Has elegido al Arquero.");
                Console.WriteLine("\nESTADISTICAS:\n\nFUERZA:10\n\nAgilidad:20\n\nEnergia:5");
                break;
            default:
                Console.WriteLine("Seleccionaste una opción incorrecta.");
                break;

        }
        Console.ReadKey();
        Console.Clear();
        break;

    case 4:
        Console.WriteLine("SISTEMA DE COMBATE");

        Console.WriteLine("Ingrese el nivel del jugador:");

        nivelJugador = int.Parse(Console.ReadLine());

        Console.WriteLine("Ingrese la fuerza del jugador:");

        fuerzaJugador = int.Parse(Console.ReadLine());

        Console.WriteLine("Ingrese la agilidad del jugador:");

        agilidadJugador = int.Parse(Console.ReadLine());

        bool bonusFuerza = false;

        if (nivelJugador > 10 && fuerzaJugador >15)
        {
            Console.WriteLine("Bonus por nivel y fuerza.");
            danoTotal = danoBase * 2;
            danoBase = 0;

            bonusFuerza = true;
        }
        if (agilidadJugador > 20)
        {
            if (bonusFuerza = true)
            {
                danoBase = 0;
            }
            Console.WriteLine("Bonus por agilidad.");
            danoTotal = (danoTotal + danoBase) * 1.5f;
        }
        else
        {
            danoTotal = danoBase;
        }

        Console.WriteLine("El daño total causado fue: " +danoTotal);

        Console.ReadKey();
        Console.Clear();
        break;

    case 5:
        Console.WriteLine("PUNTUACION CON BONUS");

        Console.WriteLine("Tienes " + puntosTotales + " puntos! Pero pueden ser modificados...");

        Console.WriteLine("Ingrese los minutos de juego:");

        tiempoJuego = int.Parse(Console.ReadLine());

        Console.WriteLine("Ingrese la cantidad de enemigos derrotados:");

        enemigosDerrotados = int.Parse(Console.ReadLine());

        if (tiempoJuego < 5 && enemigosDerrotados > 10)
        {
            modificadorPuntos = 100;
            Console.WriteLine("Obtuviste un bonus de puntuacion.");
        }
        else if (tiempoJuego > 10 || enemigosDerrotados < 5)
        {
            modificadorPuntos = -50;
            Console.WriteLine("Obtuviste una penalizacion.");
        }

        puntosTotales = puntosTotales + modificadorPuntos;

        Console.WriteLine("Tu puntuacion total fue: " + puntosTotales);

        Console.ReadKey();
        Console.Clear();
        break;
    case 6:
        Console.WriteLine("ESCUDO Y DEFENSA DEL JUGADOR");

        Console.WriteLine("Ingrese la resistencia del escudo del jugador:");

        escudoJugador = int.Parse(Console.ReadLine());

        Console.WriteLine("Ingrese la defensa del jugador:");

        agilidadJugador = int.Parse(Console.ReadLine());

        if (escudoJugador > 50 || agilidadJugador > 30)
        {
            Console.WriteLine("Defensa ALTA.");
        }
        else if (escudoJugador < 20 && agilidadJugador < 15)
        {
            modificadorPuntos = -50;
            Console.WriteLine("Defensa BAJA.");
        }
        else
        {
            Console.WriteLine("Defensa MEDIA.");
        }

        Console.ReadKey();
        Console.Clear();
        break;

    default:
        Console.WriteLine("Usted ha ingresado una opción inválida.");
        break;
}