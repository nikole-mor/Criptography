#include "../include/Truncado.h"
#include "../include/Utils.h"
#include <fstream>
#include <iostream>
using namespace std;

string Truncado::truncarNombre(string nombre, int n) {
  string truncado = "";
  for (int i = 0; i < nombre.length();
       i++) {                       // Recorre los carácteres del nombre
    truncado = nombre.substr(0, n); // Trunca el nombre a n caracteres
  }
  return truncado;
}

string Truncado::truncarCorreo(string correo, int n) {
  string truncado = "";
  int at_pos = correo.find('@');
  string usuario = correo.substr(0, at_pos);

  if (n > usuario.length()) {
    truncado = correo.substr(at_pos, correo.length());
  } else {
    for (int i = 0; i < correo.length(); i++) {
      if (correo[i] == '@') {
        truncado += correo.substr(i, correo.length());
        break;
      } else if (i < at_pos && i < n) {
        truncado += correo[i];
      }
    }
  }
  return truncado;
}

string Truncado::truncarTarjeta(string tarjeta, int n) {
  string truncado = "";
  for (int i = 0; i < n; i++) { // Recorre los carácteres de la tarjeta
    truncado += tarjeta[i];     // Agrega el carácter al truncado final
  }
  return truncado;
}

string Truncado::truncarMensaje(string mensaje, int n) {
  string truncado = "";
  for (int i = 0; i < mensaje.length();
       i++) {                        // Recorre los carácteres del mensaje
    truncado = mensaje.substr(0, n); // Trunca el mensaje a n caracteres
  }
  return truncado;
}

void Truncado::truncarArchivo(const string &inputFileName,
                              const string &outputFileName, int n) {
  ifstream entrada(inputFileName);
  ofstream salida(outputFileName);

  if (!entrada.is_open()) {
    cerr << "Error abriendo el archivo de entrada: " << inputFileName << endl;
    return;
  }
  if (!salida.is_open()) {
    cerr << "Error abriendo el archivo de salida: " << outputFileName << endl;
    return;
  }

  Utils util;
  string linea;
  while (getline(entrada, linea)) {
    // Determinar el tipo de dato y truncar
    string truncado;
    if (util.esNumeroTarjeta(linea)) {
      truncado = truncarTarjeta(linea, n);
    } else if (util.esCorreo(linea)) {
      truncado = truncarCorreo(linea, n);
    } else if (util.esNombre(linea)) {
      truncado = truncarNombre(linea, n);
    } else {
      truncado = linea; // Si no se reconoce, dejar la línea tal cual
    }
    salida << truncado << endl;
  }
  entrada.close();
  salida.close();
  cout << "El contenido truncado se ha guardado en " << outputFileName << endl;
}