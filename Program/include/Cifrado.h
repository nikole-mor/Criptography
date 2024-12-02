#ifndef CIFRADO_H
#define CIFRADO_H

#include <string>
using namespace std;

class Cifrado {
public:
  string cifrarMensaje(string dato, int llave);
  string descifrarMensaje(string dato, int llave);
  void cifrarArchivo(const string &inputFile, const string &outputFile,
                     int llave);
  void descifrarArchivo(const string &inputFile, const string &outputFile,
                        int llave);
};

#endif