#ifndef TOKENIZADO_H
#define TOKENIZADO_H

#include <string>
using namespace std;

class Tokenizado {
public:
  string tokenizarString(string dato);
  void tokenizarArchivo(const string &inputFileName,
                        const string &outputFileName, char mascara);
};

#endif