// Declaracion de variables globales
Nodo *lista = NULL;

// Atributos globales de la libreria
string *ptrPalabra;
string aux;
char letra;

// Inicializando funciones de libreria funciones (ESTRUCTURA DINAMICA LISTA)
void agregarPalabra(Nodo *&, Palabra&);
void buscarPalabra(string);
bool eliminarPalabra(Nodo *&, string);
bool modificarPalabra(Nodo *&, string);
void buscarLetra(string l);
void agregarRegistro(Palabra&);

// Inicializando funciones de libreria funciones_fichero
bool cargarRegistros(ifstream &);
void crearFichero(ofstream &);
void actualizarFichero(Nodo *, ofstream&);

// Funcion principal imprime el menu y da acceso a todas las opciones
void menu()
{
    // Creamos los objetos de las clases de ficheros
    ofstream txtEscribir;
    ifstream txtLeer;
    // Creamos un objeto de la clase Palabra (servira para el envio y obtencion de datos)
    Palabra unaPalabra = Palabra();
    // Eliminamos todo el contenido de la consola
    system("cls");
    // Utilizamos la funcion cargarRegistros para cargar los datos del fichero en la Lista (Estructura dinamica)
    if (!cargarRegistros(txtLeer))
    {
        // En caso que el fichero no se pueda abrir creamos el fichero
        crearFichero(txtEscribir);
    }
    // Declaramos las variables locales del menu
    string respuesta;
    int opcion;
    // Ciclo Do while para imprimir el menu hasta que el usuario desee salir
    do
    {
        // Cambiamos el color del texto blanco (texto normal)
        SetConsoleTextAttribute(color, 15);
        // Imprimimos la cabecera del menu
        cout << "-----------------> MENU <-----------------" << endl;
        cout << "Bienvenido a tu diccionario!!!!" << endl;
        cout << "Lea detenidamente las opciones disponibles:" << endl << endl;
        // Cambiamos el color del texto morado (opciones disponibles)
        SetConsoleTextAttribute(color, 13);
        cout << "\t1. Agregar una palabra" << endl;
        cout << "\t2. Eliminar una palabra" << endl;
        cout << "\t3. Buscar una palabra" << endl;
        cout << "\t4. Modificar una palabra" << endl;
        cout << "\t5. Mostrar palabras de una letra" << endl;
        cout << "\t6. Salir del programa" << endl << endl;
        // Cambiamos el color del texto blanco (texto normal)
        SetConsoleTextAttribute(color, 15);
        cout << "Seleccione la accion que desea realizar: ";
        cin >> respuesta;
        // Funcion de validacion enviamos la cadena de parametro si el dato no es valido retorna opcion 7 (muestra mensaje opcion no valida)
        opcion = soloNumeros(respuesta);
        // Enviamos la opcion para evaluar que opcion selecciono el usuario
        switch (opcion)
        {
        // Agregar palabra
        case 1:
            do
            {
                // Cambiamos el color del texto blanco (texto normal)
                SetConsoleTextAttribute(color, 15);
                // Borramos el contenido que hay en la consola
                system("cls");
                // Hacemos una separacion dentro de la consola para mayor legibilidad
                cout << "-----------------------------------------------------" << endl;
                cout << "\tAGREGAR UNA PALABRA" << endl;
                cout << "-----------------------------------------------------" << endl;
                // Evitamos que el buffer del teclado se salte el siguiente getline
                cin.ignore();
                // Solicitamos los datos al usuario y lo guardamos en el auxiliar
                cout << "Ingrese el nombre de la palabra: ";
                getline(cin, aux);
                // Validamos que la palabra tenga el formato correcto
                if (unaPalabra.setPalabra(aux))
                {
                    // Obtenemos el primer caracter de la cadena de texto (letra inicial)
                    unaPalabra.setLetra(aux);
                    // Validamos que no existan mas de 5 palabras con la misma letra inicial y que no se repita la palabra en la lista
                    if (validarMaximo(lista, unaPalabra.getLetra(), unaPalabra.getPalabra()))
                    {
                        // Solicitamos el significado y lo guardamos
                        cout << "Ingrese el significado: ";
                        getline(cin, aux, '\n');
                        // Validamos que el significado tenga el formato correcto
                        if (unaPalabra.setSignificado(aux))
                        {
                            // Solicitamos el sinonimo y lo guardamos
                            cout << "Ingrese el sinonimo: ";
                            getline(cin, aux, '\n');
                            // Validamos que el sinonimo tenga el formato correcto
                            if (unaPalabra.setSinonimo(aux))
                            {
                                // Solicitamos el antonimo y lo guardamos en posicion 3
                                cout << "Ingrese el antonimo: ";
                                getline(cin, aux, '\n');
                                // Validamos que el antonimo tenga el formato correcto
                                if (unaPalabra.setAntonimo(aux))
                                {
                                    // Enviamos la informacion ingresada como parametro y la lista
                                    agregarPalabra(lista, unaPalabra);
                                    // Guardaremos el registro (nodo) dentro de un fichero para respaldarlo
                                    agregarRegistro(unaPalabra);
                                    // Cambiamos el color del texto a verde (exito)
                                    SetConsoleTextAttribute(color, 10);
                                    // Mostramos mensaje de exito y realizamos un salto de linea para mejorar estetica
                                    cout << endl << "----> Palabra agregada correctamente al diccionario <----" << endl << endl;
                                }
                            }
                        }
                    }
                }
                // Cambiamos el color del texto a celeste (confirmacion/pregunta)
                SetConsoleTextAttribute(color, 11);
                // Preguntamos si desea realizar nuevamente la accion
                cout << "Desea ingresar otra palabra del diccionario? (s/n): ";
                cin >> letra;
            } while (letra == 's' || letra == 'S');
            break;
        // Eliminar palabra
        case 2:
            do
            {
                // Cambiamos el color del texto blanco (texto normal)
                SetConsoleTextAttribute(color, 15);
                // Borramos el contenido que hay en la consola
                system("cls");
                // Hacemos una separacion dentro de la consola para mayor legibilidad
                cout << "-----------------------------------------------------" << endl;
                cout << "\tELIMINAR UNA PALABRA" << endl;
                cout << "-----------------------------------------------------" << endl;
                // Evitamos que el buffer del teclado se salte el siguiente getline
                cin.ignore();
                cout << "Ingrese la palabra que desea eliminar del diccionario: ";
                getline(cin, aux, '\n');
                // Asignamos el valor del aux al puntero
                ptrPalabra = &aux;
                // Cambiamos el color del texto a celeste (confirmacion/pregunta)
                SetConsoleTextAttribute(color, 11);
                cout << endl << "Esta seguro de que desea eliminar la palabra -> " << aux << " <- del diccionario? (s/n): ";
                cin >> letra;
                // Cambiamos el color del texto blanco (texto normal)
                SetConsoleTextAttribute(color, 15);
                // Verificadmos que la respuesta del usuario haya sido S o s
                if (letra == 's' || letra == 'S')
                {
                    // Hacemos la letra Mayuscula
                    letra = toupper(letra);
                    // Ejecutamos funcion para eliminar la palabra de la lista
                    if (eliminarPalabra(lista, *ptrPalabra))
                    {
                        // Cambiamos el color del texto a verde (exito)
                        SetConsoleTextAttribute(color, 10);
                        cout << endl << "La palabra -> " << aux << " <- se ha eliminado correctamente del diccionario" << endl << endl;
                        // Funcion para actualizar los registros dentro del fichero (actualizar en base a la lista)
                        actualizarFichero(lista,txtEscribir);
                    }
                }
                else
                {
                    // Cambiamos el color del texto a celeste (confirmacion/pregunta)
                    SetConsoleTextAttribute(color, 11);
                    cout << endl << "No hay problema! No se eliminara la palabra -> " << aux << " <- del diccionario" << endl << endl;
                }
                // Cambiamos el color del texto a celeste (confirmacion/pregunta)
                SetConsoleTextAttribute(color, 11);
                // Preguntamos si desea realizar nuevamente la accion
                cout << "Desea eliminar otra palabra del diccionario? (s/n): ";
                cin >> letra;
            } while (letra == 's' || letra == 'S');
            break;
        // Buscar palabra
        case 3:
            do
            {
                // Borramos el contenido que hay en la consola
                system("cls");
                // Cambiamos el color del texto blanco (texto normal)
                SetConsoleTextAttribute(color, 15);
                // Hacemos una separacion dentro de la consola para mayor legibilidad
                cout << "-----------------------------------------------------" << endl;
                cout << "\tBUSCAR UNA PALABRA" << endl;
                cout << "-----------------------------------------------------" << endl;
                // Evitamos que el buffer del teclado se salte el siguiente getline
                cin.ignore();
                cout << "Ingrese la palabra que desea buscar: ";
                getline(cin, aux);
                // Asignamos el valor del aux al puntero
                ptrPalabra = &aux;
                // Validamos que la palabra ingresada
                if (unaPalabra.setPalabra(*ptrPalabra))
                {
                    // Ejecutamos la funcion buscar palabra con el atributo de la clase como parametro
                    buscarPalabra(unaPalabra.getPalabra());
                }
                // Cambiamos el color del texto celeste (pregunta/informacion)
                SetConsoleTextAttribute(color, 11);
                // Preguntamos si desea realizar nuevamente la accion
                cout << endl << "Desea buscar otra palabra en el diccionario? (s/n): ";
                cin >> letra;
            } while (letra == 's' || letra == 'S');
            break;
        // Modificar palabra
        case 4:
            do
            {
                // Borramos el contenido que hay en la consola
                system("cls");
                // Cambiamos el color del texto blanco (texto normal)
                SetConsoleTextAttribute(color, 15);
                // Hacemos una separacion dentro de la consola para mayor legibilidad
                cout << "-----------------------------------------------------" << endl;
                cout << "\tMODIFICAR UNA PALABRA" << endl;
                cout << "-----------------------------------------------------" << endl;
                // Evitamos que el buffer del teclado se salte el siguiente getline
                cin.ignore();
                cout << "Ingrese la palabra que desea modificar: ";
                getline(cin, aux);
                // Asignamos el valor del aux al puntero
                ptrPalabra = &aux;
                // Ejecutamos la funcion modificar palabra con la lista y aux (palabra a modificar)
                if (modificarPalabra(lista, *ptrPalabra))
                {
                    // Cambiamos el color del texto verde (exito)
                    SetConsoleTextAttribute(color, 10);
                    cout << endl << "----> La palabra se ha modificado correctamente <----" << endl << endl;
                    actualizarFichero(lista,txtEscribir);
                }
                // Cambiamos el color del texto celeste (pregunta/informacion)
                SetConsoleTextAttribute(color, 11);
                cout << "Desea modificar otra palabra del diccionario? (s/n): ";
                cin >> letra;
            } while (letra == 's' || letra == 'S');
            break;
        // Buscar palabra por letra
        case 5:
            do
            {
                // Cambiamos el color del texto blanco (texto normal)
                SetConsoleTextAttribute(color, 15);
                // Borramos el contenido que hay en la consola
                system("cls");
                cout << "-----------------------------------------------------" << endl;
                cout << "\tBUSCAR PALABRAS POR LETRA" << endl;
                cout << "-----------------------------------------------------" << endl;
                // Evitamos que el buffer se salte el siguiente getline
                cin.ignore();
                // Solicitamos que se ingrese la letra
                cout << "Ingrese la letra que desea buscar: ";
                getline(cin, aux);
                // Hacemos mayuscula la primera letra
                aux = toupper(aux.at(0));
                // Ejecutamos la funcion buscar letra enviando de parametro la letra
                buscarLetra(aux);
                // Cambiamos el color del texto celeste (pregunta/informacion)
                SetConsoleTextAttribute(color, 11);
                // Preguntamos si desea realizar nuevamente la accion
                cout << endl << "Desea consultar las palabras de otra letra? (s/n): ";
                cin >> letra;
                // Borramos el contenido que hay en la consola
                system("cls");
            } while (letra == 's' || letra == 'S');
            break;
        // Salir del programa
        case 6:
            // Cambiamos el color del texto blanco (texto normal)
            SetConsoleTextAttribute(color, 15);
            cout << "Saliendo del programa!!!!" << endl;
            break;
        default:
            // Cambiamos el color del texto a anaranjado para mostrar la advertencia
            SetConsoleTextAttribute(color, 6);
            // Mostramos mensaje de validacion
            cout << endl << "----> Advertencia: La opcion seleccionada no es valida <----" << endl << endl;
            // Cambiamos el color del texto blanco (texto normal)
            SetConsoleTextAttribute(color, 15);
            system("pause");
            break;
        }
        system("cls");
    } while (opcion != 6);
}

// Metodo para ingresar una palabra dentro de la lista
void agregarPalabra(Nodo *&lista, Palabra &objeto)
{
    // Creamos un nuevo nodo
    Nodo *nodo_agregar = new Nodo();
    // Asignamos los valores a los atributos del nodo
    nodo_agregar->letra = objeto.getLetra();
    nodo_agregar->palabra = objeto.getPalabra();
    nodo_agregar->significado = objeto.getSignificado();
    nodo_agregar->sinonimo = objeto.getSinonimo();
    nodo_agregar->antonimo = objeto.getAntonimo();
    // Creamos nodos auxiliares
    Nodo *nodo1 = lista;
    Nodo *nodo2;
    // Ingresamos los elementos de forma ordenada dentro de la lista (orden alfabetico)
    while ((nodo1 != NULL) && (nodo1->letra < objeto.getLetra()))
    {
        // Igualamos nodo1 al nodo2
        nodo2 = nodo1;
        // Avanzamos una posicion el nodo 1
        nodo1 = nodo1->siguiente;
    }
    // Si la lista es igual al nodo auxiliar 1
    if (lista == nodo1)
    {
        // Agregamos el nuevo contenido a la lista
        lista = nodo_agregar;
    }
    else
    {
        // Agregamos el contenido del nodo agregar a la siguiente posicion del nodo aux2
        nodo2->siguiente = nodo_agregar;
    }
    // Igualamos la siguiente posicion del nodo al valor del nodo aux1
    nodo_agregar->siguiente = nodo1;
}

// Funcion para eliminar una palabra de la lista
bool eliminarPalabra(Nodo *&lista, string palabra)
{
    bool retorno = false;
    // Preguntar si la lista no esta vacia
    if (lista != NULL)
    {
        Nodo *aux_borrar;
        Nodo *anterior = NULL;
        aux_borrar = lista;
        while ((aux_borrar != NULL) && (aux_borrar->palabra != palabra))
        {
            anterior = aux_borrar;
            aux_borrar = aux_borrar->siguiente;
        }
        if (aux_borrar == NULL)
        {
            // Cambiamos el color del texto a anaranjado en caso se active alguna validacion (advertencia)
            SetConsoleTextAttribute(color, 6);
            cout << endl
                 << "----> La palabra no ha sido encontrada <----" << endl
                 << endl;
            // Cambiamos el color del texto a celeste (confirmacion/pregunta)
            SetConsoleTextAttribute(color, 11);
        }
        else if (anterior == NULL)
        {
            lista = lista->siguiente;
            delete aux_borrar;
            retorno = true;
        }
        else
        {
            anterior->siguiente = aux_borrar->siguiente;
            delete aux_borrar;
            retorno = true;
        }
    }
    return retorno;
}

// Función para buscar y mostrar la información por palabra
void buscarPalabra(string p)
{
    struct Nodo *temporal = lista;
    if (lista != NULL)
    {
        while (temporal != NULL)
        {
            if (temporal->palabra == p)
            {
                // Cambiamos el color del texto a verde (exito)
                SetConsoleTextAttribute(color, 6);
                cout << endl
                     << "----> La palabra " << temporal->palabra << " ha sido encontrada dentro del diccionario <----" << endl;
                // Cambiamos el color del texto a celeste (informacion/pregunta)
                SetConsoleTextAttribute(color, 11);
                cout << endl
                     << "Informacion relacionada a la palabra: " << temporal->palabra << endl;
                cout << "-----------------------------------------------------" << endl;
                cout << "Letra: " << temporal->letra << endl;
                cout << "Significado: " << temporal->significado << endl;
                cout << "Sinonimo: " << temporal->sinonimo << endl;
                cout << "Antonimo: " << temporal->antonimo << endl;
                temporal = NULL;
            }
            else
            {
                if (temporal->siguiente == NULL)
                {
                    // Cambiamos el color del texto a anaranjado para mostrar la advertencia
                    SetConsoleTextAttribute(color, 6);
                    cout << endl
                         << "----> La palabra " << p << " no se encuentra dentro de el diccionario <----" << endl;
                }
                temporal = temporal->siguiente;
            }
        }
    }
    else
    {
        // Cambiamos el color del texto a anaranjado para mostrar la advertencia
        SetConsoleTextAttribute(color, 6);
        cout << endl << "----> No hay palabras en el diccionario <----" << endl << endl;
    }
    // Cambiamos el color del texto a blanco
    SetConsoleTextAttribute(color, 15);
}

// Funcion para modificar una palabra dentro del diccionario
bool modificarPalabra(Nodo *&lista, string palabra)
{
    // Creamos un nuevo nodo para recorrer la lista
    Nodo *actual = new Nodo();
    actual = lista;
    // Creamos un objeto de la clase Palabra para obtener los datos y validarlos
    Palabra obj = Palabra();
    bool retorno = false;
    // Validamos si la lista no este vacia
    if (lista != NULL)
    {
        // Recorremos el nodo Actual y validamos que el retorno no sea true (si es true ya se encontro la palabra)
        while (actual != NULL && retorno != true)
        {
            // Verificamos si la palabra en el nodo actual es igual a la ingresada
            if (actual->palabra == palabra)
            {
                // Cambiamos el color del texto a anaranjado para mostrar exito
                SetConsoleTextAttribute(color, 10);
                cout << endl << "----> La palabra " << palabra << " ha sido encontrada en el diccionario <----" << endl << endl;
                // Cambiamos el color del texto a celeste para mostrar confirmacion
                SetConsoleTextAttribute(color, 11);
                cout << "Esta seguro de que desea modificarla? (s/n): ";
                cin >> letra;
                // Verificamos que el usuario haya ingresado S
                if (letra != 's' || letra != 'S')
                {
                    // Borramos contenido de la consola
                    system("cls");
                    // Cambiamos el color del texto a verde para mostrar exito
                    SetConsoleTextAttribute(color, 10);
                    // Mostramos el nombre de la palabra que sera modificada
                    cout << "----> Modificando la palabra del diccionario: " << palabra << " <----" << endl << endl;
                    // Para evitar el salto del siguiente cout ocupamos la funcion cin.ignore()
                    cin.ignore();
                    // Cambiamos el color del texto a celeste para mostrar confirmacion
                    SetConsoleTextAttribute(color, 11);
                    cout << "Desea modificar el significado? (s/n): ";
                    cin >> letra;
                    // Cambiamos el color del texto blanco (texto normal)
                    SetConsoleTextAttribute(color, 15);
                    if (letra == 'S' || letra == 's')
                    {
                        // Para evitar el salto del siguiente cout ocupamos la funcion cin.ignore()
                        cin.ignore();
                        // Solicitamos el significado y lo guardamos en posicion 2
                        cout << "Ingrese el nuevo significado: ";
                        getline(cin, aux, '\n');
                        obj.setSignificado(aux);
                    }
                    // Cambiamos el color del texto a celeste para mostrar confirmacion
                    SetConsoleTextAttribute(color, 11);
                    cout << "Desea modificar el sinonimo? (s/n): ";
                    cin >> letra;
                    // Cambiamos el color del texto blanco (texto normal)
                    SetConsoleTextAttribute(color, 15);
                    if (letra == 'S' || letra == 's')
                    {
                        // Para evitar el salto del siguiente cout ocupamos la funcion cin.ignore()
                        cin.ignore();
                        // Solicitamos el significado y lo guardamos en posicion 3
                        cout << "Ingrese nuevo sinonimo: ";
                        getline(cin, aux, '\n');
                        obj.setSinonimo(aux);
                    }
                    // Cambiamos el color del texto a celeste para mostrar confirmacion
                    SetConsoleTextAttribute(color, 11);
                    cout << "Desea modificar el antonimo? (s/n): ";
                    cin >> letra;
                    // Cambiamos el color del texto blanco (texto normal)
                    SetConsoleTextAttribute(color, 15);
                    if (letra == 'S' || letra == 's')
                    {
                        // Para evitar el salto del siguiente cout ocupamos la funcion cin.ignore()
                        cin.ignore();
                        // Solicitamos el significado y lo guardamos en posicion 4
                        cout << "Ingrese el nuevo antonimo: ";
                        getline(cin, aux, '\n');
                        obj.setAntonimo(aux);
                    }
                    // Asignamos los nuevos valores utilizando los getters
                    if (obj.getSignificado() != "")
                    {
                        actual->significado = obj.getSignificado();
                    }
                    if (obj.getSinonimo() != "")
                    {
                        actual->sinonimo = obj.getSinonimo();
                    }
                    if (obj.getAntonimo() != "")
                    {
                        actual->antonimo = obj.getAntonimo();
                    }
                    retorno = true;
                }
                else
                {
                    // Cambiamos el color del texto a celeste para mostrar informacion
                    SetConsoleTextAttribute(color, 6);
                    cout << endl << "----> No se modificara la palabra <----" << endl << endl;
                }
            }
            actual = actual->siguiente;
        }
        if (!retorno)
        {
            // Cambiamos el color del texto a anaranjado para mostrar la advertencia
            SetConsoleTextAttribute(color, 6);
            cout << endl << "----> La palabra no ha sido encontrada <----" << endl << endl;
        }
    }
    else
    {
        // Cambiamos el color del texto a anaranjado para mostrar la advertencia
        SetConsoleTextAttribute(color, 6);
        cout << "----> El diccionario se encuentra vacio <----" << endl;
    }
    return retorno;
}

// Funcion para mostrar palabras por una letra en especifico
void buscarLetra(string letra)
{
    struct Nodo *temporal = lista;
    int c = 0;

    if (lista != NULL)
    {
        while (temporal != NULL)
        {
            // Se verifica que la letra de la palabra coincida con la que ingresa el usuario
            if (temporal->letra == letra)
            {
                if (c == 0)
                {
                    // Cambiamos el color del texto a verde (exito)
                    SetConsoleTextAttribute(color, 6);
                    cout << endl << "----> Se han encontrado las siguientes palabras con la letra: " << letra << " <----" << endl << endl;
                }
                // Cambiamos el color del texto a azul (informacion/pregunta)
                SetConsoleTextAttribute(color, 11);
                // Imprimimos los resultados (atributos del nodo)
                cout << "-----------------------------------------------------" << endl;
                cout << "Palabra: " << temporal->palabra << endl;
                cout << "Significado: " << temporal->significado << endl;
                cout << "Sinonimo: " << temporal->sinonimo << endl;
                cout << "Antonimo: " << temporal->antonimo << endl;
                temporal = temporal->siguiente;
                c = 1;
            }
            else
            {
                // Validamos que no exista siguiente nodo y que el contador de palabras sea 0
                if (temporal->siguiente == NULL && c == 0)
                {
                    // Cambiamos el color del texto a anaranjado (advertencia)
                    SetConsoleTextAttribute(color, 6);
                    cout << endl << "----> Advertencia: No hay palabras con la letra ingresada <----" << endl << endl;
                }
                temporal = temporal->siguiente;
            }
        }
    }
    else
    {
        // Cambiamos el color del texto a anaranjado (advertencia)
        SetConsoleTextAttribute(color, 6);
        cout << endl << "----> Advertencia: No hay palabras en el diccionario <----" << endl << endl;
    }
}