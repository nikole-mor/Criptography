#include "../include/Utils.h"
#include <cctype> // Para isdigit() y isalpha()
using namespace std;

// Función para saber si el dato es una tarjeta
bool Utils::esNumeroTarjeta(const string &dato) {
  // digitos de la tarjeta
  if (dato.length() != 16)
    return false;
  for (char c : dato) {
    if (!isdigit(c))
      return false; // solo acepta numeros
  }
  return true;
}

// Función para validar si el dato es un correo
bool Utils::esCorreo(const string &dato) {
  size_t atPos = dato.find('@');
  size_t dotPos = dato.find('.', atPos);
  return atPos != string::npos && dotPos != string::npos;
}

// Función para validar si el dato es un nombre
bool Utils::esNombre(const string &dato) {
  // comprobar que el dato contenga solo letras y espacios
  for (char c : dato) {
    if (!(isalpha(c) || c == ' '))
      return false;
  }
  return true;
}