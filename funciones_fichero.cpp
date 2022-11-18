// Funcion para crear el fichero donde se almacenaran los registros (archivo txt)
void crearFichero()
{
    // Creamos un objeto de la clase ofstream 
    ofstream archivo;
    // Creamos variable donde almacenaremos todo el contenido de fichero
    string texto;
    // Abrimos el fichero con el objeto creado anteriormente y enviamos de parametro el nombre del txt
    archivo.open("registros.txt", ios::out);
    // Validamos que no haya fallado abrir el archivo
    if (archivo.fail())
    {
        // En caso de fallar mostrarmos el siguiente mensaje y detenemos la ejecucion del programa
        cout << "No se pudo crear el archivo, deteniendo programa......";
        exit(1);
    }
    // Cerramos el fichero 
    archivo.close();
}

// Funcion para agregar un registro dentro del fichero con un puntero tipo string (arreglo) de parametro
void agregarRegistro(string *datos)
{
    // Creamos un objeto de la clase ofstream 
    ofstream archivo;
    // Creamos una variable para almacenar la cadena que contendra que contendra el registro
    string registro;
    // Abrimos el fichero con el objeto archivo 
    archivo.open("registros.txt", ios::app);
    // Validamos que no haya fallado abrir el archivo
    if (archivo.fail())
    {
        // En caso de fallar mostrarmos el siguiente mensaje y detenemos la ejecucion del programa
        cout << "No se pudo abrir el archivo, deteniendo programa......";
        exit(1);
    }
    // Concatenamos los daots utilizando caracteres especiales para facilitar su identificacion al realizar la lectura
    registro = datos[0] + "?" + datos[1] + "&" + datos[2] + "%" + datos[3] + "$" + datos[4] + "#";
    // Imprimimos el registro dentro del fichero
    archivo << registro;
    // Cerramos el fichero
    archivo.close();
}

// Funcion para actualizar los registros dentro del fichero en base a la lista del programa
void actualizarFichero(Nodo *lista){
    // Reseteamos el contenido del fichero
    crearFichero();
    // Arreglo donde guardaremos los datos de cada nodo cargado de la lista
    string datos[5];
    // Creamos un nodo auxiliar para recorrer la lista
    Nodo * actual = new Nodo();
    actual = lista;
    // Recorremos el contenido actualizado de la lista y lo agregamos al fichero
    while (actual != NULL)
    {
        // Obtenemos los valores de los atributos del nodo
        datos[0] = actual->letra;
        datos[1] = actual->palabra;
        datos[2] = actual->significado;
        datos[3] = actual->sinonimo;
        datos[4] = actual->antonimo;
        actual = actual->siguiente;
        // Enviamos nodo por nodo a la funcion para agregar los nodos en el fichero (txt)
        agregarRegistro(datos);
    }
    // Mostramos mensaje de exito
    cout << "Fichero actualizado correctamente" << endl;
}

// Funcion para cargar todos los registros del fichero (txt)
bool cargarRegistros()
{
    // Declaramos variable que contendra el valor si se ejecuto o no la funcion
    bool retorno;
    // Creamos objeto de la clase ifstream
    ifstream archivo;
    // Creamos la cadena en la que guardaremos todo el contenido del fichero
    string cadenaDatos;
    // Utilizamos el objeto archivo para abrir el fichero
    archivo.open("registros.txt", ios::in);
    // Validamos que el archivo no haya tenido errores al cargar
    if (archivo.fail())
    {
        // Mostramos mensaje de error y salimos del programa
        cout << "No se pudo abrir el archivo";
        retorno = false;
    }
    else
    {
        // Mientras el archivo no tenga errores ejecutaremos
        while (!archivo.eof())
        {
            // Creamos el arreglo donde iremos guardando los datos que leamos del fichero
            string datos[5];
            // Ingresamos todo el contenido del arreglo dentro de la variable cadenaDatos
            getline(archivo, cadenaDatos);
            // Creamos variables auxiliares para posicionarnos dentro de arreglos 
            int longitud, posicion = 0;
            // Obtenemos el numero de caracteres que posee la cadena de datos
            longitud = cadenaDatos.length();
            // Recorremos caracter por caracter la cadena de datos
            for (int i = 0; i < longitud; i++)
            {
                // Obtenemos el caracter actual y lo guardamos en actual (tipo char)
                char actual = cadenaDatos[i];
                // Creamos un switch para ir asignando los strings dentro del arreglo datos segun posicion 
                switch (posicion)
                {
                // Posicion cadenaDatos[0] correspondiente al string letra
                case 0:
                    // El ? define el fin del string letra
                    if (actual == '?')
                    {
                        // Pasamos a la siguiente posicion del arreglo datos[]
                        posicion = 1;
                    }
                    else
                    {
                        // Asignamos el valor del string letra
                        datos[0] = actual;
                    }
                    break;
                // Posicion cadenaDatos[1] correspondiente al string palabra
                case 1:
                    // El & define el fin del string palabra
                    if (actual == '&')
                    {
                        // Pasamos a la siguiente posicion del arreglo datos[]
                        posicion = 2;
                    }
                    else
                    {
                        // Vamos agregando los caracteres para formar el string 
                        datos[1] = datos[1] + actual;
                    }
                    break;
                // Posicion cadenaDatos[2] correspondiente al string letra
                case 2:
                    // El % define el fin del string significado
                    if (actual == '%')
                    {
                        // Pasamos a la siguiente posicion del arreglo datos[]
                        posicion = 3;
                    }
                    else
                    {
                        // Vamos agregando los caracteres para formar el string 
                        datos[2] = datos[2] + actual;
                    }
                    break;
                // Posicion cadenaDatos[3] correspondiente al string sinonimo
                case 3:
                    // El $ define el fin del string sinonimo
                    if (actual == '$')
                    {
                        // Pasamos a la siguiente posicion del arreglo datos[]
                        posicion = 4;
                    }
                    else
                    {
                        // Vamos agregando los caracteres para formar el string 
                        datos[3] = datos[3] + actual;
                    }
                    break;
                // Posicion cadenaDatos[4] correspondiente al string antonimo
                case 4:
                    // El # define el fin del string antonimo
                    if (actual == '#')
                    {
                        // Creamos un nodo mediante el arreglo obtenido para restaurar el contenido de la lista                     
                        agregarPalabra(lista,datos);
                        // Recorremos el arreglo datos
                        for (int i = 0; i < 5; i++)
                        {
                            // Vaciamos el contenido de cada posicion del arreglo datos
                            datos[i] = "";
                        }
                        // Regresamos a la primera posicion 
                        posicion = 0;
                    }
                    else
                    {
                        // Vamos agregando los caracteres para formar el string 
                        datos[4] = datos[4] + actual;
                    }
                    break;
                }
            }
        }
        // Mostramos mensaje de confirmacion
        cout << "Datos restaurados correctamente del fichero....." << endl;
        retorno = true;
    } 
    // Cerramos la conexion con el fichero
    archivo.close();
    return retorno;
}
