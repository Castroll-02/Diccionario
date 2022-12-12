// Funcion para validar la longitud maxima de un String (cadena)
bool validarLongitud(string cadena, size_t longitud)
{
    // Cambiamos el color del texto a anaranjado en caso se active alguna validacion (advertencia)
    SetConsoleTextAttribute(color, 6);
    // Si la longitud es correcta se mantendra el valor true
    bool retorno = true;
    // Validamos que el tamaño de la cadena sea menor a la longitud ingresada
    if (cadena.length() > longitud)
    {
        // Mostramos mensaje de validacion en caso de ser verdadera la condicion
        cout << endl << "----> Advertencia: Has superado la longitud maxima de caracteres: " << longitud << "<----" << endl << endl;
        cout << cadena;
        // Retornamos false para que no se siga ejecutando la accion
        retorno = false;
    }
    // Cambiamos el color del texto blanco (texto normal)
    SetConsoleTextAttribute(color, 15);
    return retorno;
}

// Funcion para validar que no se ingresen mas de 5 palabras por letra
bool validarMaximo(Nodo *lista, string letra, string palabra)
{
    // Cambiamos el color del texto a anaranjado en caso se active alguna validacion (advertencia)
    SetConsoleTextAttribute(color, 6);
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
            cout << endl << "----> Advertencia: La palabra ya se encuentra registrada en el diccionario <----" << endl << endl;
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
        cout << endl << "----> Advertencia: Se ha alcanzado el limite de 5 palabras por letra <----" << endl << endl;
    }
    // Cambiamos el color del texto blanco (texto normal)
    SetConsoleTextAttribute(color, 15);
    return retorno;
}

// Funcion para validar una cadena de texto (No debe tener caracteres numericos)
int soloLetras(string cadena)
{
    // Cambiamos el color del texto a anaranjado en caso se active alguna validacion (advertencia)
    SetConsoleTextAttribute(color, 6);
    // Creo auxiliar para ir guardando cada caracter del String (cadena)
    char aux;
    // Recorremos cada posicion dentro de la cadena para validar caracter por caracter
    for (size_t i = 0; i < cadena.size(); i++)
    {
        // Asignamos el valor de la cadena en la posicion i al aux
        aux = cadena[i];
        // Validamos si el caracter no es una letra (A-Z sin contar Ñ) isalpha(char) == 0
        if (isalpha(aux) == 0)
        {
            // Al Ñ y ñ no ser parte de las letras en c++ validamos su existencia con su codigo ASCII Ñ(165) y ñ(164)
            if (aux == char(164) || aux == char(165) || aux == char(160) || aux == char(161) || aux == char(162) || aux == char(163) || aux == char(44) || aux == char(239)|| aux == char(191)|| aux == char(189)|| aux == char(250)|| aux == char(58)|| aux == char(59)|| aux == char(63))
            {
                // El caracter actual es Ñ o ñ por ende es valido
            }
            else
            {
                // En caso que el caracter no sea un espacio vacio (soloLetras permite espacios vacios)
                if (aux != ' ')
                {
                    // Mostramos mensaje de validacion
                    cout << endl << "----> Advertencia: El caracter " << aux << " no es valido ingrese solo letras <----" << endl << endl;
                    return 0;
                }
            }
        }
    }
    // Validamos que la cadena no este vacia
    if (cadena.size() == 0)
    {
        // Mostramos mensaje de validacion
        cout << endl << "----> Advertencia: No puedes dejar el campo vacio <----" << endl << endl;
        return 0;
    }
    // Cambiamos el color del texto blanco (texto normal)
    SetConsoleTextAttribute(color, 15);
    // El retorno 1 equivale a true
    return 1;
}

// Funcion para validar numeros (Solo numeros seleccion menu)
int soloNumeros(string cadena)
{
    // Cambiamos el color del texto a anaranjado en caso se active alguna validacion (advertencia)
    SetConsoleTextAttribute(color, 6);
    // Creo auxiliar para ir guardando cada caracter del String (cadena)
    char aux;
    // Recorremos cada posicion dentro de la cadena para validar caracter por caracter
    for (size_t i = 0; i < cadena.size(); i++)
    {
        // Asignamos el valor de la cadena en la posicion i al aux
        aux = cadena[i];
        // Validamos si el caracter es una letra 
        if (isalpha(aux) == 1)
        {
            return 7;
        }
    }
    // Validamos que la cadena no este vacia
    if (cadena.size() == 0)
    {
        // Mostramos mensaje de validacion
        cout << endl << "----> Advertencia: No puedes dejar el campo vacio <----" << endl << endl;
        return 7;
    }
    // Declaramos la variable que retornara la seleccion
    int retorno;
    // Validamos que el caracter sea una letra
    if (isalpha(aux) == 0)
    {
        // Convertimos la cadena (string) al retorno (cadena)
        retorno = stoi(cadena);
    }
    // Cambiamos el color del texto blanco (texto normal)
    SetConsoleTextAttribute(color, 15);
    // El retorno 1 equivale a true
    return retorno;
}

// Funcion para validar una cadena de texto (No debe tener caracteres numericos)
int soloLetrasSinEspacio(string cadena)
{
    // Cambiamos el color del texto a anaranjado en caso se active alguna validacion (advertencia)
    SetConsoleTextAttribute(color, 6);
    // Creo auxiliar para ir guardando cada caracter del String (cadena)
    char aux;
    // Recorremos cada posicion dentro de la cadena para validar caracter por caracter
    for (size_t i = 0; i < cadena.size(); i++)
    {
        // Asignamos el valor de la cadena en la posicion i al string aux
        aux = cadena[i];
        // Validamos que el caracter no sea un espacio en blanco (Aca no se permite dejar espacios en blanco)
        if (aux == ' ')
        {
            // Mostramos mensaje de validacion
            cout << endl << "----> Advertencia: No puedes dejar espacios vacios <----" << endl << endl;
            return 0;
        }
        // Validamos si el caracter no es una letra (A-Z sin contar Ñ) isalpha(char) == 0
        if (isalpha(aux) == 0)
        {
            // Al Ñ y ñ no ser parte de las letras en c++ validamos su existencia con su codigo ASCII Ñ(165) y ñ(164)
            if (aux == char(164) || aux == char(165))
            {
                // El caracter actual es Ñ o ñ por ende es valido
            }
            else
            {
                // Mostramos mensaje de validacion
                cout << endl << "----> Advertencia: El caracter " << aux << " no es valido ingrese solo letras <----" << endl << endl;
                cout << cadena << endl;
                return 0;
            }
        }
    }
    // Validamos que la cadena no este vacia
    if (cadena.size() == 0)
    {
        // Mostramos mensaje de validacion
        cout << endl <<  "----> Advertencia: No puedes dejar el campo vacio <----" << endl << endl;
        return 0;
    }
    // Cambiamos el color del texto blanco (texto normal)
    SetConsoleTextAttribute(color, 15);
    // El retorno 1 equivale a true
    return 1;
}

// Funcion para estandarizar todos los Strings primera letra Mayuscula resto minuscula
string estandarizarString(string cadena)
{
    // Recorremos la cadena caracter por caracter
    for(int i = 0; i < cadena.length(); i++)
    {
        // Si es la primera posicion (primera letra) 
        if(i == 0)
        {
            // Convertimos el caracter a mayuscula
            cadena[i] = toupper(cadena[i]);
        }
        else
        {
            // Convertimos el caracter a minuscula
            cadena[i] = tolower(cadena[i]);
        }
    }
    return cadena;
}