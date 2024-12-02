#ifndef TRUNCADO_H
#define TRUNCADO_H

#include <string>
using namespace std;

class Truncado {
public:
  string truncarNombre(string nombre, int n);
  string truncarCorreo(string correo, int n);
  string truncarTarjeta(string tarjeta, int n);
  string truncarMensaje(string mensaje, int n);
  void truncarArchivo(const string &inputFileName, const string &outputFileName, int n);
};

#endif