/*
Compilar:
g++ -std=c++11 -o main src/*.cpp -I include

Ejecutar:
./main
*/
#include "../include/Cifrado.h"
#include "../include/Enmascarado.h"
#include "../include/Tokenizado.h"
#include "../include/Truncado.h"
#include <iostream>
using namespace std;

void menu() {
  cout << "===================================" << endl;
  cout << "|     Selecciona una opción       |" << endl;
  cout << "===================================" << endl;
  cout << "| [1] Cifrado                     |" << endl;
  cout << "| [2] Descifrado                  |" << endl;
  cout << "| [3] Enmascarado                 |" << endl;
  cout << "| [4] Tokenizado                  |" << endl;
  cout << "| [5] Truncado                    |" << endl;
  cout << "| [6] Salir                       |" << endl;
  cout << "-----------------------------------" << endl;
}

int main() {
  Enmascarado enmascarado;
  Tokenizado tokenizado;
  Truncado truncado;
  Cifrado cifrado;

  int opcion;

  do {
    menu();
    cout << "--> ";
    cin >> opcion;

    switch (opcion) {
    case 1: {
      // Cifrado
      int llave;
      cout << "Ingrese la llave de cifrado (Número entero): ";
      cin >> llave;
      cifrado.cifrarArchivo("archivo.txt", "archivo_cifrado.txt", llave);
      break;
      cout<< "en proceso";
    }
    case 2: {
      // Descifrado
      string nombreArchivo;
      int llave;
      cout << "Ingrese el nombre del archivo a descifrar (incluyendo "
              "extensión): ";
      cin >> nombreArchivo;
      cout << "Ingrese la llave de descifrado: ";
      cin >> llave;
      cifrado.descifrarArchivo(nombreArchivo, "archivo_descifrado.txt", llave);
      break;
    }
    case 3: {
      // Enmascarado
      enmascarado.enmascararArchivo("archivo.txt", "archivo_enmascarado.txt",
                                    '*');
      break;
    }
    case 4: {
      // Tokenizado
      tokenizado.tokenizarArchivo("archivo.txt", "archivo_tokenizado.txt", '*');
      break;
    }
    case 5: {
      // Truncado
      int num_caracteres;
      cout << "Ingrese el número de caracteres a truncar (Número entero): ";
      cin >> num_caracteres;
      truncado.truncarArchivo("archivo.txt", "archivo_truncado.txt",
                              num_caracteres);
      break;
    }
    case 6:
      // Finaliza la ejecución del programa
      cout << "Ejecución finalizada." << endl;
      // Muestra una figura de despedida
      cout << " O/" << endl;
      cout << "/|   ¡Hasta pronto!" << endl;
      cout << " /\\" << endl;
      break;
    default:
      cout << "Opción no válida. Por favor, ingresa una opción entre 1 y 5."
           << endl;
      break;
    }
  } while (opcion != 6); // Continuar hasta que se elija la opción 5 (Salir)
  return 0;
}