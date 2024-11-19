#ifndef ENMASCARADO_H
#define ENMASCARADO_H

#include <string>
using namespace std;

class Enmascarado {
public:
  string enmascararTarjeta(string dato, char mascara);
  string enmascararNombre(string dato, char mascara);
  string enmascararCorreo(string dato, char mascara);
  void enmascararArchivo(const string& inputFileName, const string& outputFileName, char mascara);

};

#endif 