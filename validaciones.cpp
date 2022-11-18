struct Nodo
{
    string letra;
    string palabra;
    string significado;
    string sinonimo;
    string antonimo;
    Nodo *siguiente;
};

// Funcion para validar que no se ingresen mas de 5 palabras por letra
bool validarMaximo(Nodo *lista, string letra, string palabra)
{
    // Declaramos variables de retorno y contador de palabras
    bool retorno = true;
    int nLetras = 0;
    // Creamos un nuevo nodo para recorrer la lista
    Nodo *nodo_leer = new Nodo();
    nodo_leer = lista;
    // Mientras haya contenido en la lista se seguira leyendo
    while (nodo_leer != NULL)
    {
        // Cada vez que se encuentre una palabra con la misma letra se sumara uno al contador
        if (nodo_leer->letra == letra)
        {
            // Sumamos uno al contador
            nLetras++;
        }
        // Validamos que la palabra no exista ya dentro del diccionario (lista)
        if (nodo_leer->palabra == palabra)
        {
            // Mostramos mensaje de validacion y retornamos un valor falso ya que no se completo la accion
            cout << "La palabra ya se encuentra registrada en el diccionario" << endl;
            retorno = false;
        }
        // Avanzamos una posicion en la lista
        nodo_leer = nodo_leer->siguiente;
    }
    // Validamos si se encontraron mas de 4 palabras
    if (nLetras >= 5 && retorno != false)
    {
        // Si es el caso retornamos un valor falso ya que no se completo la accion
        retorno = false;
        // Imprimimos mensaje de validacion
        cout << "Se ha alcanzado el limite de 5 palabras por letra" << endl;
    }
    return retorno;
}

bool validarString(string cadena, string campo) {
    bool retorno = true;
    // Verifica si hay un espacio vacío 
    if (cadena == "")
    {
        retorno = false;
        //Si esta vacio se envia mensaje de que no es permitido
        cout << "No puedes dejar el " << campo << " vacio" << endl;

    } else {
        //Si no esta vacio se verifica si solo hay letras
        for (int i = 0; i < cadena.length(); i++)
        {
            // Guardamos la posicion actual dentro de un char
            char letra = cadena[i];
            // Verificamos que el caracter no sea letras 
            if (isalpha(letra)) {
                //cout << "Todo correcto" << endl;
            } else {
                //Si hay numeros se envia mensaje de que no es permitido
                cout << "No debes incluir numeros dentro del campo " << campo << endl;
                retorno = false;
            }
        }
    }
    return retorno;
}

bool validarLongitud(string cadena, size_t longitud) {
    bool retorno = true;
    if (cadena.length() > longitud)
    {
        cout << "Has superado la longitud maxima" << endl; 
        retorno = false;
    }
    return retorno;
}

