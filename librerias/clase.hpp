#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <fstream>
#include <string>
#include <windows.h>
HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);

using namespace std;

// Inicializando funciones de la libreria validaciones.hpp
int soloLetrasSinEspacio(string);
int soloLetras(string);
bool validarLongitud(string, size_t);
string estandarizarString(string);

// Creando estructura de la Lista Simplemente Enlazada
struct Nodo
{
    // Atributos de la estructura
    string letra;
    string palabra;
    string significado;
    string sinonimo;
    string antonimo;
    Nodo *siguiente;
};

// Creando la clase Palabra
class Palabra
{
    // Declaro los atributos como privados accederemos a ellos con los metodos/funciones
    private:
    string letra;
    string palabra;
    string significado;
    string sinonimo;
    string antonimo;

    // Metodos de la clase publicos
    public:
    // Declaro el constructor vacio para inicializar la clase con atributos vacios
    Palabra();
    // Declaro el constructor con parametros para inicializar la clase con atributos completos
    Palabra(string letra,string palabra,string significado,string sinonimo,string antonimo);
    
    // Metodos setter y getter

    // Get y set de letra
    bool setLetra(string);
    string getLetra();

    // Get y set de palabra
    bool setPalabra(string);
    string getPalabra();

    // Get y set de significado
    bool setSignificado(string);
    string getSignificado();

    // Get y set de sinonimo
    bool setSinonimo(string);
    string getSinonimo();

    // Get y set de antonimo
    bool setAntonimo(string);
    string getAntonimo();
};

// Constructor vacio
Palabra::Palabra()
{

}

// Constructor con parametros
Palabra::Palabra(string letra,string palabra,string significado,string sinonimo,string antonimo)
{
    // Asigno el valor de cada parametro a cada atributo de la clase
    this->letra = letra;
    this->palabra = palabra;
    this->significado = significado;
    this->sinonimo = sinonimo;
    this->antonimo = antonimo;
}

// Set letra asignar un valor al atributo letra (se obtiene de la palabra porque la letra no se ingresa manualmente)
bool Palabra::setLetra(string palabra)
{
    // Validamos la letra(Solo letras sin espacios) retornos 0 == false 1 == true
    if (soloLetrasSinEspacio(palabra) != 0)
    {
        // Validamos que la longitud de la cadena no sea mayor a la indicada (30 caracteres max) 
        if (validarLongitud(palabra,30))
        {
            // Obtenemos la primera posicion de la cadena y lo asignamos al atributo letra y lo hacemos Mayuscula
            this->letra = toupper(palabra.at(0));
            return true;
        }
    }
    return false;
}

// Get letra retorna el valor del atributo letra
string Palabra::getLetra()
{
    return this->letra;
}

// Set palabra asignar un valor al atributo palabra
bool Palabra::setPalabra(string palabra)
{
    // Validamos la palabra (Solo letras sin espacios) retornos 0 == false 1 == true
    if (soloLetrasSinEspacio(palabra) != 0)
    {
        // Validamos que la longitud de la cadena no sea mayor a la indicada (30 caracteres max)
        if (validarLongitud(palabra,30))
        {
            // Estandarizamos la cadena (String) primera letra Mayuscula resto minuscula
            palabra = estandarizarString(palabra);
            // Asignamos el valor al atributo 
            this->palabra = palabra;
            return true;
        }
    }
    return false;
}

// Get palabra retorna el valor del atributo palabra
string Palabra::getPalabra()
{
    return this->palabra;
}

// Set palabra asignar un valor al atributo significado
bool Palabra::setSignificado(string significado)
{
    // Validamos el significado retornos 0 == false 1 == true
    if (soloLetras(significado) != 0)
    {
        // Validamos que la longitud de la cadena no sea mayor a la indicada (150 caracteres max)
        if (validarLongitud(significado,200))
        {
            // Estandarizamos la cadena (String) primera letra Mayuscula resto minuscula
            significado = estandarizarString(significado);
            // Asignamos el valor al atributo 
            this->significado = significado;
            return true;
        }
    }
    return false;
}

// Get palabra retorna el valor del atributo significado
string Palabra::getSignificado()
{
    return this->significado;
}

// Set palabra asignar un valor al atributo sinonimo
bool Palabra::setSinonimo(string sinonimo)
{
    // Validamos el sinonimo retornos 0 == false 1 == true
    if (soloLetras(sinonimo) != 0)
    {
        // Validamos que la longitud de la cadena no sea mayor a la indicada (30 caracteres max)
        if (validarLongitud(sinonimo,30))
        {
            // Estandarizamos la cadena (String) primera letra Mayuscula resto minuscula
            sinonimo = estandarizarString(sinonimo);
            // Asignamos el valor al atributo 
            this->sinonimo = sinonimo;
            return true;
        }
    }
    return false;
}

// Get palabra retorna el valor del atributo sinonimo
string Palabra::getSinonimo()
{
    return this->sinonimo;
}

// Set palabra asignar un valor al atributo sinonimo
bool Palabra::setAntonimo(string antonimo)
{
    // Validamos el antonimo retornos 0 == false 1 == true
    if (soloLetras(antonimo) != 0)
    {
        // Validamos que la longitud de la cadena no sea mayor a la indicada (30 caracteres max)
        if (validarLongitud(antonimo,30))
        {
            // Estandarizamos la cadena (String) primera letra Mayuscula resto minuscula
            antonimo = estandarizarString(antonimo);
            // Asignamos el valor al atributo 
            this->antonimo = antonimo;
            return true;
        }
    }
    return false;
}

// Get palabra retorna el valor del atributo antonimo
string Palabra::getAntonimo()
{
    return this->antonimo;
}

// Importamos las librerias 
#include "nominacion.hpp"
#include "funciones.hpp"
#include "funciones_fichero.hpp"
