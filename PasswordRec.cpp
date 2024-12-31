#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// Función para generar una contraseña aleatoria
string generarContrasena(int longitud, bool incluirSimbolos)
{
    string minusculas = "abcdefghijklmnopqrstuvwxyz";
    string mayusculas = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string numeros = "0123456789";
    string simbolos = "@#$&%][.{}";

    string caracteres = minusculas + mayusculas + numeros;
    if (incluirSimbolos)
    {
        caracteres += simbolos;
    }

    string contrasena = "";

    // Asegurarse de incluir al menos un carácter de cada tipo requerido
    if (incluirSimbolos)
    {
        contrasena += simbolos[rand() % simbolos.length()];
    }
    contrasena += minusculas[rand() % minusculas.length()];
    contrasena += mayusculas[rand() % mayusculas.length()];
    contrasena += numeros[rand() % numeros.length()];

    // Completar el resto de la contraseña con caracteres aleatorios
    for (int i = contrasena.length(); i < longitud; i++)
    {
        contrasena += caracteres[rand() % caracteres.length()];
    }

    // Mezclar los caracteres para que el orden sea aleatorio
    for (int i = 0; i < contrasena.length(); i++)
    {
        swap(contrasena[i], contrasena[rand() % contrasena.length()]);
    }

    return contrasena;
}

int main()
{
    srand(time(0)); // Inicializar la semilla para la generación aleatoria

    int opcion;
    do
    {
        cout << "\n=== Generador de Contra ===" << endl;
        cout << "1. Generar contra con simbolos" << endl;
        cout << "2. Generar contra sin simbolos" << endl;
        cout << "3. Salir" << endl;
        cout << "Elige una opcion: ";
        cin >> opcion;

        if (opcion == 1 || opcion == 2)
        {
            int longitud;
            cout << "Ingresa la longitud de la contra: ";
            cin >> longitud;

            if (longitud < 4)
            {
                cout << "La longitud debe ser al menos 4 para incluir todos los tipos de caracteres." << endl;
                continue;
            }

            bool incluirSimbolos = (opcion == 1);
            string contrasena = generarContrasena(longitud, incluirSimbolos);
            cout << "Contra generada: " << contrasena << endl;
        }
        else if (opcion != 3)
        {
            cout << "Opcion invalida. Intenta de nuevo." << endl;
        }

    } while (opcion != 3);

    cout << "Saliendo del programa.\n";
    return 0;
}
