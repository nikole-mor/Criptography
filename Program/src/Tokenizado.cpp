#include "../include/Tokenizado.h"
#include <fstream>
#include <iostream>
using namespace std;

string Tokenizado::tokenizarString(string dato) {
  string token = "";
  int longitud = 16;
  string alphanum =
      "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

  // token aleatorio
  for (int i = 0; i < longitud; i++) {
    token += alphanum[rand() % alphanum.length()];
  }
  return token;
}

void Tokenizado::tokenizarArchivo(const string &inputFileName,
                                  const string &outputFileName, char mascara) {
  ifstream entrada(inputFileName);  
  ofstream salida(outputFileName);

  if (!entrada.is_open()) {
    cerr << "Error abriendo el archivo de entrada: " << inputFileName << endl;
    return;
  }
  // Leer el contenido del archivo
  string linea, contenido;
  while (getline(entrada, linea)) {
    contenido += linea + "\n";
  }
  entrada.close();

  // Tokenizar el contenido
  string contenidoTokenizado = tokenizarString(contenido);

  // Guardar el contenido tokenizado en el archivo de salida
  if (!salida.is_open()) {
    cerr << "Error abriendo el archivo de salida: " << outputFileName << endl;
    return;
  }
  salida << contenidoTokenizado;
  salida.close();
  cout << "El contenido tokenizado se ha guardado en " << outputFileName << endl;
}
