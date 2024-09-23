//CLASE 6 - Estructuras de control repetitivas

int seleccion = 0;

int experienciaTotal = 0;
int nivelJugador = 0;
int nivelesSubidos = 0;
string nombreJugador;
int ratioCritico = 0;
int contadorCritico = 0;
int numeroIngresado = 0;
int numeroCorrecto = 7;
bool victoria = false;
int intentos = 0;
int energiaActual = 0;
int energiaMaxima = 100;

Console.WriteLine("Ingrese el numero de ejercicio:");

Console.WriteLine("\n1-Subir de nivel\r\nEscribe un programa que permita al jugador subir de nivel. Solicita al jugador que ingrese la cantidad de experiencia acumulada. Si la experiencia es mayor a 100, el jugador sube de nivel y se resta 100 puntos de experiencia. El proceso se repite hasta que la experiencia sea menor a 100. Muestra cuántos niveles subió el jugador y la experiencia restante.");
Console.WriteLine("\n2-Solicitar Nombre del Jugador\r\nEscribe un programa que solicite al jugador ingresar su nombre. Si el nombre tiene menos de 8 caracteres, el programa debe pedir nuevamente el ingreso del nombre hasta que cumpla con la longitud requerida.");
Console.WriteLine("\n3-Contar golpes críticos\r\nEscribe un programa que simule un jugador golpeando a un enemigo 10 veces. Utiliza un bucle for para representar los golpes. En cada golpe, genera un número aleatorio entre 1 y 10. Si el número es 8, 9 o 10, cuenta como un golpe crítico. Muestra cuántos golpes críticos realizó el jugador al final.");
Console.WriteLine("\n4-Adivina el Número de Enemigos\r\nEscribe un programa en el que el jugador tenga que adivinar la cantidad de enemigos en una habitación. El número correcto de enemigos es 7. Utiliza un bucle while para permitirle al jugador intentar adivinar hasta que ingrese el número correcto. Después de cada intento, informa si el número ingresado es incorrecto y pide otro intento.");
Console.WriteLine("\n5-Cargar Energía del Jugador\r\nEscribe un programa que simule la carga de energía de un jugador. La energía se carga en intervalos de 10 unidades. La energía máxima es 100. Utiliza un bucle for para incrementar la energía del jugador en intervalos de 10, mostrando el progreso en cada paso. Cuando la energía llega a 100, el bucle debe detenerse y mostrar que la energía está completa.");

seleccion = int.Parse(Console.ReadLine());

Console.Clear();

switch (seleccion)
{
    case 1:
        Console.WriteLine("SUBIR DE NIVEL");

        nivelJugador = 1;

        Console.WriteLine("Ingrese los puntos de experiencia totales:");
        experienciaTotal = int.Parse(Console.ReadLine());

        while (experienciaTotal > 100)
        {
            nivelJugador++;
            experienciaTotal -= 100;
            nivelesSubidos++;
        }
        Console.WriteLine("El personaje ha subido " + nivelesSubidos + " niveles.");
        Console.WriteLine("El nivel del jugador es: " + nivelJugador);
        Console.WriteLine("Los puntos de experiencia restantes son: " + experienciaTotal);

        break;

    case 2:
        do
        {
            Console.WriteLine("NOMBRE JUGADOR");
            Console.WriteLine("Ingrese el nombre del personaje. Debe contener al menos 8 caracteres.");
            nombreJugador = Console.ReadLine();

            Console.Clear();
        } while (nombreJugador.Length < 8);

        Console.WriteLine("El nombre del jugador es: " + nombreJugador + ".");
        break;

    case 3:
        Console.WriteLine("CONTAR GOLPES CRÍTICOS");
        for(int i=0; i<10; i++)
        {
            Console.WriteLine("El jugador ha dado un golpe.");

            ratioCritico = GenerarAleatorio();

            if (ratioCritico >= 8)
            {
                Console.WriteLine("¡HAS ASESTADO UN GOLPE CRITICO!");
                contadorCritico++;
            }
        }

        Console.WriteLine("Cantidad total de golpes criticos: " + contadorCritico);

        int GenerarAleatorio()
        {
            Random rnd = new Random();
            return rnd.Next(1, 11);
        }

        break;

    case 4:
        while (victoria == false)
        {
            Console.WriteLine("ADIVINA EL NUMERO DE ENEMIGOS");
            Console.WriteLine("Adivina cuántos enemigos hay en la habitación...");

            numeroIngresado = int.Parse(Console.ReadLine());

            intentos++;

            if (numeroIngresado == numeroCorrecto)
            {
                victoria = true;
            }

            Console.Clear();
        }

        Console.WriteLine("¡Ganaste! La respuesta correcta es: " + numeroCorrecto);
        Console.WriteLine("Cantidad de intentos: " + intentos);
        break;

    case 5:
        Console.WriteLine("CARGAR ENERGIA DEL JUGADOR");
        for(int i=0; energiaActual<energiaMaxima; i++)
        {
            energiaActual += 10;
            Console.WriteLine("\n\nHas cargado 10 de energia.");
            Console.WriteLine("Ahora tienes " + energiaActual + " de energia.");
        }
        Console.WriteLine("¡LA ENERGIA ESTÁ COMPLETA!");
        break;

    default:
        Console.WriteLine("Usted ha ingresado una opción inválida.");
        break;
}