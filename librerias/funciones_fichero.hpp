// Funcion para crear el fichero donde se almacenaran los registros (archivo txt)
void crearFichero(ofstream &fichero)
{
    // Creamos variable donde almacenaremos todo el contenido de fichero
    string texto;
    // Abrimos el fichero con el objeto creado anteriormente y enviamos de parametro el nombre del txt
    fichero.open("registros.txt", ios::out);
    // Validamos que no haya fallado abrir el archivo
    if (fichero.fail())
    {
        // En caso de fallar mostrarmos el siguiente mensaje y detenemos la ejecucion del programa
        cout << "No se pudo crear el archivo, deteniendo programa......";
        exit(1);
    }
    // Finalizamos la conexion con el fichero
    fichero.close();
}

// Funcion para agregar un registro dentro del fichero con un puntero tipo string (arreglo) de parametro
void agregarRegistro(Palabra &objeto)
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
    registro = objeto.getLetra() + "?" + objeto.getPalabra() + "&" + objeto.getSignificado() + "%" + objeto.getSinonimo() + "$" + objeto.getAntonimo() + "#";
    // Imprimimos el registro dentro del fichero
    archivo << registro;
    // Cerramos el fichero
    archivo.close();
}

// Funcion para actualizar los registros dentro del fichero en base a la lista del programa
void actualizarFichero(Nodo *lista, ofstream &fichero)
{
    // Reseteamos el contenido del fichero
    crearFichero(fichero);
    // Arreglo donde guardaremos los datos de cada nodo cargado de la lista
    Palabra objeto = Palabra();
    // Creamos un nodo auxiliar para recorrer la lista
    Nodo *actual = new Nodo();
    actual = lista;
    // Recorremos el contenido actualizado de la lista y lo agregamos al fichero
    while (actual != NULL)
    {
        // Almacenamos los valores de los atributos del nodo en los atributos de la clase Palabra
        objeto.setLetra(actual->letra);
        objeto.setPalabra(actual->palabra);
        objeto.setSignificado(actual->significado);
        objeto.setSinonimo(actual->sinonimo);
        objeto.setAntonimo(actual->antonimo);
        actual = actual->siguiente;
        // Enviamos el objeto con los atributos llenos a la funcion para agregar los datos en el fichero (txt)
        agregarRegistro(objeto);
    }
}

// Funcion para cargar todos los registros del fichero (txt)
bool cargarRegistros(ifstream& fichero)
{
    // Declaramos variable que contendra el valor si se ejecuto o no la funcion
    bool retorno;
    // Creamos la cadena en la que guardaremos todo el contenido del fichero
    string cadenaDatos;
    // Utilizamos el objeto archivo para abrir el fichero
    fichero.open("registros.txt", ios::in);
    // Validamos que el archivo no haya tenido errores al cargar
    if (fichero.fail())
    {
        // Mostramos mensaje de error y salimos del programa
        cout << "No se pudo abrir el archivo";
        retorno = false;
    }
    else
    {
        // Mientras no se haya llegado al final del archivo
        while (!fichero.eof())
        {
            // Creamos el objeto de la clase Palabra
            Palabra objeto = Palabra();
            // Creamos variable auxiliar para almacenar cada palabra (String)
            string aux;
            // Ingresamos todo el contenido del arreglo dentro de la variable cadenaDatos
            getline(fichero, cadenaDatos);
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
                // String letra
                case 0:
                    // El ? define el fin del string letra
                    if (actual == '?')
                    {
                        // Asignamos el valor del string letra
                        objeto.setLetra(aux);
                        // Borramos el contenido del auxiliar
                        aux = "";
                        // Pasamos al siguiente string (palabra)
                        posicion = 1;
                    }
                    else
                    {
                        aux = actual;
                    }
                    break;
                // String palabra
                case 1:
                    // El & define el fin del string palabra
                    if (actual == '&')
                    {
                        // Asignamos el valor del string palabra
                        objeto.setPalabra(aux);
                        // Borramos el contenido del auxiliar
                        aux = "";
                        // Pasamos al siguiente string (significado)
                        posicion = 2;
                    }
                    else
                    {
                        // Vamos agregando los caracteres para formar el string
                        aux = aux + actual;
                    }
                    break;
                // String letra
                case 2:
                    // El % define el fin del string significado
                    if (actual == '%')
                    {
                        // Asignamos el valor del string significado
                        objeto.setSignificado(aux);
                        // Borramos el contenido del auxiliar
                        aux = "";
                        // Pasamos al siguiente string (sinonimo)
                        posicion = 3;
                    }
                    else
                    {
                        // Vamos agregando los caracteres para formar el string
                        aux = aux + actual;
                    }
                    break;
                // String sinonimo
                case 3:
                    // El $ define el fin del string sinonimo
                    if (actual == '$')
                    {
                        // Asignamos el valor del string sinonimo
                        objeto.setSinonimo(aux);
                        // Borramos el contenido del auxiliar
                        aux = "";
                        // Pasamos al siguiente string (antonimo)
                        posicion = 4;
                    }
                    else
                    {
                        // Vamos agregando los caracteres para formar el string
                        aux = aux + actual;
                    }
                    break;
                // String antonimo
                case 4:
                    // El # define el fin del string antonimo
                    if (actual == '#')
                    {
                        // Asignamos el valor del string antonimo
                        objeto.setAntonimo(aux);
                        // Borramos el contenido del auxiliar
                        aux = "";
                        // Creamos un nodo mediante el arreglo obtenido para restaurar el contenido de la lista
                        agregarPalabra(lista, objeto);
                        // Regresamos a la primera posicion
                        posicion = 0;
                    }
                    else
                    {
                        // Vamos agregando los caracteres para formar el string
                        aux = aux + actual;
                    }
                    break;
                }
            }
        }
        retorno = true;
    }
    // Finalizamos la conexion con el fichero
    fichero.close();
    return retorno;
}
