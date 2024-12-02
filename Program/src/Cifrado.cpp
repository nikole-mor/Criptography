#include "../include/Cifrado.h"
#include <fstream>
#include <iostream>
using namespace std;

string Cifrado::cifrarMensaje(string dato, int llave) {
  string resultado = "";

  for (char c : dato) {
    if (isalpha(c)) { // Si el carácter es una letra
      char base = islower(c) ? 'a' : 'A';
      resultado += (c - base + llave) % 26 + base;
    } else if (isdigit(c)) { // Si el carácter es un dígito
      resultado += (c - '0' + llave) % 10 + '0';
    } else { // Si el carácter no es una letra ni un dígito
      resultado += c;
    }
  }
  return resultado;
}

string Cifrado::descifrarMensaje(string dato, int llave) {
  string resultado = "";
  for (char c : dato) {
    if (isalpha(c)) { // Si el carácter es una letra
      char base = islower(c) ? 'a' : 'A';
      resultado += (c - base - llave + 26) % 26 + base;
    } else if (isdigit(c)) { // Si el carácter es un dígito
      resultado += (c - '0' - llave + 10) % 10 + '0';
    } else { // Si el carácter no es una letra ni un dígito
      resultado += c;
    }
  }
  return resultado;
}

void Cifrado::cifrarArchivo(const string &inputFile, const string &outputFile,
                            int llave) {
  // Abrir archivo de entrada
  ifstream entrada(inputFile);
  if (!entrada.is_open()) {
    cerr << "Error: No se pudo abrir el archivo de entrada: " << inputFile
         << endl;
    return;
  }

  // Leer archivo de entrada
  string linea, contenido;
  while (getline(entrada, linea)) {
    contenido += linea + "\n";
  }
  entrada.close();

  // Cifrar el contenido leído
  string contenidoCifrado = cifrarMensaje(contenido, llave);

  // Guardar el archivo cifrado
  ofstream salida(outputFile);
  if (!salida.is_open()) {
    cerr << "Error: No se pudo abrir el archivo de salida: " << outputFile
         << endl;
    return;
  }
  salida << contenidoCifrado;
  salida.close();
  cout << "El contenido cifrado se ha guardado en " << outputFile << endl;
}

void Cifrado::descifrarArchivo(const string &inputFile,
                               const string &outputFile, int llave) {
  // Abrir archivo de entrada
  ifstream entrada(inputFile);
  if (!entrada.is_open()) {
    cerr << "Error: No se pudo abrir el archivo de entrada: " << inputFile
         << endl;
    return;
  }

  // Leer archivo de entrada
  string linea, contenido;
  while (getline(entrada, linea)) {
    contenido += linea + "\n";
  }
  entrada.close();

  // Cifrar el contenido leído
  string contenidoDescifrado = descifrarMensaje(contenido, llave);

  // Guardar el archivo cifrado
  ofstream salida(outputFile);
  if (!salida.is_open()) {
    cerr << "Error: No se pudo abrir el archivo de salida: " << outputFile
         << endl;
    return;
  }
  salida << contenidoDescifrado;
  salida.close();
  cout << "El contenido descifrado se ha guardado en " << outputFile << endl;
}