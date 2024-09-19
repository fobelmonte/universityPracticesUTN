//CLASE 3 - Variables
//EJERCICIO 1 - Monedas de Oro, Plata y Bronce. Realice un sistema que permita ingresar la cantidad de monedas de oro, plata y bronce que tiene el jugador. Luego, debe mostrar en consola cuántas monedas tiene en total y cuál es el valor total, sabiendo que las monedas de oro tienen un valor de 5, las de plata valen 3, y las de bronce 1.

int oro = 0;
int plata = 0;
int bronce = 0;
int totalDinero = 0;

Console.WriteLine("MONEDAS");

Console.WriteLine("Ingrese cantidad de monedas de oro:");

oro = int.Parse(Console.ReadLine());

Console.WriteLine("Ingrese cantidad de monedas de plata:");

plata = int.Parse(Console.ReadLine());

Console.WriteLine("Ingrese cantidad de monedas de bronce:");

bronce = int.Parse(Console.ReadLine());

totalDinero = oro * 5 + plata * 3 + bronce;

Console.WriteLine("La cantidad de monedas que tienes es:");
Console.WriteLine("Monedas de oro: " + oro + "\nMonedas de plata: " + plata + "\nMonedas de bronce: " + bronce);

Console.WriteLine("El valor total de dinero que tienes es:" + totalDinero);

Console.ReadKey();
Console.Clear();

//EJERCICIO 2 - Registro de Jugadores. Realice un sistema que solicite al jugador que ingrese su nombre, nivel y clase de personaje. Luego, muestra un mensaje de bienvenida personalizado y su información de personaje.

Console.WriteLine("CREACION DE PERSONAJE");

Console.WriteLine("Ingrese su nombre de personaje:");

string nombre = Console.ReadLine();

Console.WriteLine("Ingrese el nivel de su personaje:");

int nivel = int.Parse(Console.ReadLine());

Console.WriteLine("Ingrese su clase de personaje:");

string clase = Console.ReadLine();

Console.WriteLine("BIENVENIDO AL JUEGO");
Console.WriteLine("Tu nombre es " + nombre + ", eres de nivel " + nivel + " y perteneces a la clase " + clase);

Console.ReadKey();
Console.Clear();

//EJERCICIO 3 - Poder de ataque. Realice un sistema que solicite el nivel del personaje y el daño del arma. Debe calcular el poder de ataque total y mostrarlo en consola. El poder de ataque surgirá de multiplicar ambos valores ingresados.
Console.WriteLine("CALCULADORA DE DAÑO TOTAL");

int totalDamage = 0;

Console.WriteLine("Ingrese el daño del arma:");

int damage = int.Parse(Console.ReadLine());

totalDamage = damage * nivel;

Console.WriteLine("Tu arma causa " + damage + " de daño y tu nivel es " + nivel + "\n El daño total causado es: " + totalDamage);