#ifndef UTILS_H
#define UTILS_H

#include <string>
using namespace std;

class Utils {
public:
  bool esNumeroTarjeta(const string &dato);
  bool esCorreo(const string &dato);
  bool esNombre(const string &dato);
};

#endif