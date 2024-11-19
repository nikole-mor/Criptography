#include "../include/Enmascarado.h"
#include "../include/Utils.h"
#include <cctype> // Para isdigit() y isalpha()
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

string Enmascarado::enmascararTarjeta(string dato, char mascara) {
  string enmascarado = "";
  for (int i = 0; i < dato.length(); i++) { // Recorre el string
    if (i < 12) { // Si son los primeros 12 carácteres de la tarjeta
      enmascarado += mascara; // Agrega la mascara
    } else {                  // De lo contrario, no agrega la mascara
      enmascarado += dato[i];
    }
  }
  return enmascarado;
}

string Enmascarado::enmascararNombre(string dato, char mascara) {
  string enmascarado = "";
  for (int i = 0; i < dato.length(); i++) { // Recorre el string
    if (i == 0 || dato[i] == ' ' ||
        dato[i - 1] == ' ') { // Si es el primer carácter o es un espacio
      enmascarado += dato[i]; // Agrega el carácter
    } else {                  // De lo contrario, agrega la mascara
      enmascarado += mascara;
    }
  }
  return enmascarado;
}

string Enmascarado::enmascararCorreo(string dato, char mascara) {
  string enmascarado = "";
  for (int i = 0; i < dato.length(); i++) { // Recorrer el string
    if (i == 0) {
      enmascarado += dato[i]; // Si es el primer carácter, agregalo
    } else if (dato[i] ==
               '@') { // Si es @, agrega todos los carácteres restantes
      while (i < dato.length()) {
        enmascarado += dato[i];
        i++;
      }
      break;
    } else {
      enmascarado += mascara; // De lo contrario, agrega la mascara
    }
  }
  return enmascarado;
}

void Enmascarado::enmascararArchivo(const string &inputFileName,
                                    const string &outputFileName,
                                    char mascara) {
  ifstream inputFile(inputFileName);
  ofstream outputFile(outputFileName);

  if (!inputFile.is_open()) {
    cerr << "Error abriendo el archivo de entrada: " << inputFileName << endl;
    return;
  }
  if (!outputFile.is_open()) {
    cerr << "Error abriendo el archivo de salida: " << outputFileName << endl;
    return;
  }

  string linea;
  Utils util;
  while (getline(inputFile, linea)) {
    // Determinar el tipo de dato y enmascarar
    string enmascarado;
    if (util.esNumeroTarjeta(linea)) {
      enmascarado = enmascararTarjeta(linea, mascara);
    } else if (util.esCorreo(linea)) {
      enmascarado = enmascararCorreo(linea, mascara);
    } else if (util.esNombre(linea)) {
      enmascarado = enmascararNombre(linea, mascara);
    } else {
      enmascarado = linea; // Si no se reconoce, dejar la línea tal cual
    }
    outputFile << enmascarado
               << endl; // Escribir la línea enmascarada en el archivo de salida
  }
  inputFile.close();
  outputFile.close();
  cout << "El contenido enmascarado se ha guardado en " << outputFileName
       << endl;
}