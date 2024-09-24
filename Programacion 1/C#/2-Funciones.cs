//CLASE 4 - Funciones
//EJERCICIO 1 Un sistema que solicite el ingreso del nombre del personaje. Luego, el sistema debe mostrar la inicial del nombre ingresado. Por lo tanto, si se ingresa el nombre “Juan” el sistema debe mostrar la letra “J”.

Console.WriteLine("PRIMERA LETRA PERSONAJE");

Console.WriteLine("Ingrese nombre de personaje:");

string nombrePersonaje = Console.ReadLine();

Console.WriteLine("El nombre del personaje es: " + nombrePersonaje);

Console.WriteLine("La primera letra es: " + nombrePersonaje.Substring(0,1));

Console.ReadKey();
Console.Clear();

//EJERCICIO 2 Un sistema que solicite el ingreso de 3 números enteros. Esos 3 números enteros deben ser enviados a una función que los sume, y muestre en pantalla el resultado de la suma.

Console.WriteLine("FUNCION SUMAR NUMEROS");

int numero1 = 0;
int numero2 = 0;
int numero3 = 0;
int resultadoSuma = 0;

Console.WriteLine("Ingrese el numero 1:");

numero1 = int.Parse(Console.ReadLine());

Console.WriteLine("Ingrese el numero 2:");

numero2 = int.Parse(Console.ReadLine());

Console.WriteLine("Ingrese el numero 3:");

numero3 = int.Parse(Console.ReadLine());

resultadoSuma = Suma(numero1, numero2, numero3);

Console.WriteLine("El resultado de la suma es: " + resultadoSuma);

int Suma(int num1, int num2, int num3)
{
    int resultado = num1 + num2 + num3;
    return resultado;
}

Console.ReadKey();
Console.Clear();

//EJERCICIO 3 Un sistema que solicite el ingreso de la edad del personaje. Luego, el sistema debe mostrar la edad ingresada multiplicada por 2.
Console.WriteLine("EDAD DEL PERSONAJE MULTIPLICADA x2");

int edadPersonaje = 0;

Console.WriteLine("Ingrese la edad del personaje:");

edadPersonaje = int.Parse(Console.ReadLine());

MultiplicarEdad(edadPersonaje);

void MultiplicarEdad(int edad)
{
    int multiplicacion = edad * 2;
    Console.WriteLine("La edad del personaje multiplicada x 2: " + multiplicacion);
}

Console.ReadKey();
Console.Clear();

//EJERCICIO 4 Un sistema que solicite el ingreso del nombre del juego. Luego, el sistema debe mostrar el nombre en mayúsculas.

Console.WriteLine("NOMBRE DEL JUEGO");

Console.WriteLine("Ingrese nombre del juego:");

string nombreJuego = Console.ReadLine();

Console.WriteLine("El nombre del juego es: " + nombreJuego.ToUpper());

Console.ReadKey();
Console.Clear();

//EJERCICIO 5 Un sistema que solicite el ingreso de dos números enteros. Esos dos números deben ser enviados a una función que calcule el producto y muestre en pantalla el resultado.

Console.WriteLine("MULTIPLICACION NUMEROS ENTEROS");

int entero1 = 0;
int entero2 = 0;

Console.WriteLine("Ingrese primer numero entero:");

entero1 = int.Parse(Console.ReadLine());

Console.WriteLine("Ingrese segundo numero entero:");

entero2 = int.Parse(Console.ReadLine());

MultiplicarEnteros(entero1, entero2);

void MultiplicarEnteros(int entero1, int entero2)
{
    int resultado = entero1 * entero2;
    Console.WriteLine("El resultado de la multiplicacion es: " + resultado);
}

Console.ReadKey();
Console.Clear();

//EJERCICIO 6 Un sistema que solicite el ingreso del puntaje de tres niveles del juego. Luego, el sistema debe mostrar el puntaje total sumando los tres valores ingresados.

Console.WriteLine("FUNCION SUMAR PUNTOS");

int puntajeNivel1 = 0;
int puntajeNivel2 = 0;
int puntajeNivel3 = 0;

Console.WriteLine("Ingrese el puntaje del nivel 1:");

puntajeNivel1 = int.Parse(Console.ReadLine());

Console.WriteLine("Ingrese el puntaje del nivel 2:");

puntajeNivel2 = int.Parse(Console.ReadLine());

Console.WriteLine("Ingrese el puntaje del nivel 3:");

puntajeNivel3 = int.Parse(Console.ReadLine());

SumarPuntajes(puntajeNivel1, puntajeNivel2, puntajeNivel3);

void SumarPuntajes(int punt1, int punt2, int punt3)
{
    int resultadoSuma = punt1 + punt2 + punt3;
    Console.WriteLine("El resultado total de puntos es: " + resultadoSuma);
}

Console.ReadKey();
Console.Clear();

//EJERCICIO 7 Un sistema que solicite el ingreso de la cantidad de enemigos derrotados. Luego, el sistema debe mostrar el puntaje obtenido, sabiendo que cada enemigo derrotado otorga 10 puntos.

Console.WriteLine("ENEMIGOS DERROTADOS");

int enemigosDerrotados = 0;
int puntosEnemigoDerrotado = 10;

Console.WriteLine("El numero de enemigos derrotados fue: ");

enemigosDerrotados = int.Parse(Console.ReadLine());

PuntosObtenidos(enemigosDerrotados, puntosEnemigoDerrotado);

void PuntosObtenidos(int enemigos, int puntos)
{
    int resultado = enemigos * puntos;
    Console.WriteLine("El puntaje obtenido fue: " + resultado);
}

Console.ReadKey();
Console.Clear();

//EJERCICIO 8 Un sistema que solicite el ingreso del nombre del personaje y su salud actual. Luego, el sistema debe mostrar la salud como porcentaje de la salud máxima que es de 100.

Console.WriteLine("SALUD TOTAL");

string nombrePersonaje2;
int saludMaxima = 100;
int saludActual = 0;

Console.WriteLine("Ingrese nombre de personaje:");

nombrePersonaje2 = Console.ReadLine();

Console.WriteLine("El nombre del personaje es: " + nombrePersonaje2);

Console.WriteLine("La salud maxima es: " + saludMaxima);

Console.WriteLine("La salud actual es: ");

saludActual = int.Parse(Console.ReadLine());

CalcularPorcentaje(saludActual, saludMaxima);

void CalcularPorcentaje(int sActual, int sMaxima)
{
    float porcentajeSalud = 0f;
    porcentajeSalud = (sActual * 100) / sMaxima;

    Console.WriteLine("El porcentaje de salud es: " + porcentajeSalud + " % ");
}

Console.ReadKey();
Console.Clear();

//EJERCICIO 9 Un sistema que solicite el ingreso de la cantidad de enemigos derrotados por un jugador en tres niveles distintos. Luego, el sistema debe calcular y mostrar el promedio de enemigos derrotados por nivel.

Console.WriteLine("PROMEDIO ENEMIGOS DERROTADOS POR NIVEL");

int derrotadosNivel1 = 0;
int derrotadosNivel2 = 0;
int derrotadosNivel3 = 0;
float promedio = 0f;

Console.WriteLine("Ingrese la cantidad de enemigos derrotados en el nivel 1:");

derrotadosNivel1 = int.Parse(Console.ReadLine());

Console.WriteLine("Ingrese la cantidad de enemigos derrotados en el nivel 2:");

derrotadosNivel2 = int.Parse(Console.ReadLine());

Console.WriteLine("Ingrese la cantidad de enemigos derrotados en el nivel 3:");

derrotadosNivel3 = int.Parse(Console.ReadLine());

promedio = CalcularPromedio(derrotadosNivel1, derrotadosNivel2, derrotadosNivel3);

Console.WriteLine("El promedio de enemigos derrotados por nivel es: " + promedio);

float CalcularPromedio(int derrotados1, int derrotados2, int derrotados3)
{
    float resultado = (derrotados1 + derrotados2 + derrotados3) / 3;
    return resultado;
}

Console.ReadKey();
Console.Clear();

//EJERCICIO 10 Un sistema que solicite el ingreso del nombre de un jugador y la cantidad de puntos obtenidos en cinco partidas diferentes. Luego, el sistema debe mostrar el nombre del jugador y el puntaje total obtenido.

Console.WriteLine("PUNTAJE TOTAL PARTIDA");

string nombreJugador;

int puntajePartida = 0;
int resultadoTotalPartidas = 0;

Console.WriteLine("Ingrese nombre del jugador:");

nombreJugador = Console.ReadLine();

Console.WriteLine("El nombre del personaje es: " + nombreJugador);

for (int i=1; i<6; i++)
{
    Console.WriteLine("Ingrese el puntaje obtenido en el nivel " + i + " : ");

    puntajePartida = int.Parse(Console.ReadLine());

    resultadoTotalPartidas = resultadoTotalPartidas + puntajePartida;
}

Console.WriteLine("El resultado total es: " + resultadoTotalPartidas);

Console.ReadKey();
Console.Clear();

//EJERCICIO 11 Un sistema que solicite el ingreso del nombre del juego y el tiempo jugado en minutos. Luego, el sistema debe convertir y mostrar el tiempo jugado en horas y minutos.

Console.WriteLine("TIEMPO JUGADO");

int tiempoJugado = 0;
int resultadoHoras = 0;
int resultadoMinutos = 0;

Console.WriteLine("Ingrese la cantidad de tiempo jugado en minutos: ");

tiempoJugado = int.Parse(Console.ReadLine());

resultadoHoras = tiempoJugado / 60;
resultadoMinutos = tiempoJugado % 60;

Console.WriteLine("La cantidad de tiempo jugado en horas y minutos es: ");
Console.WriteLine(resultadoHoras + " horas y " + resultadoMinutos + " minutos.");

Console.ReadKey();
Console.Clear();

//EJERCICIO 12 Un sistema que solicite el ingreso de los nombres de tres personajes. Luego, el sistema debe mostrar los nombres en orden inverso al ingreso.

Console.WriteLine("TRES PERSONAJES INVERSOS");

string nombreJugador1;
string nombreJugador2;
string nombreJugador3;

Console.WriteLine("Ingrese nombre del jugador 1:");

nombreJugador1 = Console.ReadLine();

Console.WriteLine("Ingrese nombre del jugador 2:");

nombreJugador2 = Console.ReadLine();

Console.WriteLine("Ingrese nombre del jugador 3:");

nombreJugador3 = Console.ReadLine();

Console.WriteLine("Los nombres de los personajes en orden inverso son: ");
Console.WriteLine("3: " + nombreJugador3);
Console.WriteLine("2: " + nombreJugador2);
Console.WriteLine("1: " + nombreJugador1);

Console.ReadKey();
Console.Clear();

//EJERCICIO 13 Un sistema que solicite la cantidad de enemigos comunes derrotados, y la cantidad de enemigos de tipo Boss. Luego debe devolver el puntaje total, sabiendo que los enemigos comunes suman 10 puntos y los bosses 50 puntos.

Console.WriteLine("PUNTOS ENEMIGOS COMUNES Y BOSS");

int derrotadosEnemigosComunes = 0;
int derrotadosEnemigosBoss = 0;
int puntosTotales = 0;

Console.WriteLine("Ingrese la cantidad de enemigos comunes derrotados: ");

derrotadosEnemigosComunes = int.Parse(Console.ReadLine());

Console.WriteLine("Ingrese la cantidad de enemigos boss derrotados: ");

derrotadosEnemigosBoss = int.Parse(Console.ReadLine());

puntosTotales = calcularPuntosTotales(derrotadosEnemigosComunes, derrotadosEnemigosBoss);

Console.WriteLine("El resultado total de puntos es: " + puntosTotales);

int calcularPuntosTotales(int comunes, int boss)
{
    int puntosComunes = 10;
    int puntosBoss = 50;
    int resultado = boss * puntosBoss + comunes * puntosComunes;

    return resultado;
}
