// Declaracion de variables globales
Nodo *lista = NULL;
// Arreglo para almacenar los campos (palabra, significado, sinonimo y antonimo) 
string datos[5], palabra;
char letra;

// Inicializando funciones
void agregarPalabra(Nodo *&, string[5]);
void buscarPalabra(string);
bool eliminarPalabra(Nodo *&, string);
bool cargarRegistros();
void agregarRegistro(string*);
void crearFichero();
void actualizarFichero(Nodo*);

void menu()
{
    system("cls");
    if (!cargarRegistros())
    {
        crearFichero();
    }
    
    int opcion;
    char rpt;
    do
    {
        cout << "MENU" << endl;
        cout << "1. Agregar una palabra" << endl;
        cout << "2. Eliminar una palabra" << endl;
        cout << "3. Buscar una palabra" << endl;
        cout << "4. Salir del programa" << endl;
        cout << "Seleccione la accion que desea realizar: ";
        cin >> opcion;
        switch (opcion)
        {
        // Agregar palabra
        case 1:
            do
            {
                // Hacemos una separacion dentro de la consola para mayor legibilidad
                cout << "-----------------------------------------------------"<<endl;
                // Solicitamos los datos al usuario y lo guardamos en un arreglo
                cout << "Ingrese el nombre de la palabra: ";
                cin >> datos[1];
                // Obtenemos el primer caracter de la cadena de texto (letra inicial)
                datos[0] = datos[1].at(0);
                // Validamos que no existan mas de 5 palabras con la misma letra inicial y que no se repita la palabra en la lista
                if (validarMaximo(lista, datos[0], datos[1]))
                {
                    // Para evitar el salto del siguiente cout ocupamos la funcion cin.ignore()
                    cin.ignore();
                    // Solicitamos el significado y lo guardamos en posicion 1
                    cout << "Ingrese el significado: ";
                    getline(cin, datos[2], '\n');
                    // Solicitamos el sinonimo y lo guardamos en posicion 2
                    cout << "Ingrese el sinonimo: ";
                    getline(cin, datos[3], '\n');
                    // Solicitamos el antonimo y lo guardamos en posicion 3
                    cout << "Ingrese el antonimo: ";
                    getline(cin, datos[4], '\n');
                    // Enviamos la informacion ingresada como parametro y la lista
                    agregarPalabra(lista, datos);
                    // Guardaremos el registro (nodo) dentro de un fichero para respaldarlo
                    agregarRegistro(datos);
                    // Mostramos mensaje de exito
                    cout << "Palabra agregada correctamente al diccionario!!! " << endl;
                }    
                cout<<"Desea ingresar otra palabra del diccionario? (s/n): ";
                cin >> rpt;
            } while(rpt=='s' || rpt=='S'); 
            system("pause");
            break;
        // Eliminar palabra
        case 2:
            do
            {
                cout<<"Ingrese la palabra que desea eliminar: ";
                cin>>palabra;
                cout<<"Esta seguro de que desea eliminar la palabra "<<palabra<<" del diccionario? (s/n): ";
                cin>>rpt;
                if (rpt != 's' || rpt != 'S')
                {
                    if (eliminarPalabra(lista,palabra))
                    {
                        cout<<endl;
                        cout<<"La palabra ->"<<palabra<<"<-"<<" se ha eliminado correctamente del diccionario"<<endl<<endl;
                        actualizarFichero(lista);
                    }
                }
                cout<<"Desea eliminar otra palabra del diccionario? (s/n): ";
                cin >> rpt;
            } while(rpt=='s' || rpt=='S');
            system("pause");
            break;
        // Buscar palabra
        case 3:
            cin.ignore();
            cout<<"Ingrese la palabra que desea buscar"<<endl;
            getline(cin, palabra);
            buscarPalabra(palabra);
            system("pause");
            break;
        // Mostrar todas las palabras del diccionario
        case 4:
            
        break;
        // Salir del programa
        case 5:
            cout << "Saliendo del programa....." << endl;
            break;
        default:
            cout << "La opcion seleccionada no es valida" << endl;
            system("pause");
            break;
        }
        system("cls");
    } while (opcion != 5);
}

// Metodo para ingresar una palabra dentro de la lista
void agregarPalabra(Nodo *&lista,  string datos[5])
{
    // Creamos un nuevo nodo
    Nodo *nodo_agregar = new Nodo();
    // Asignamos los valores a los atributos del nodo
    nodo_agregar->letra = datos[0];
    nodo_agregar->palabra = datos[1];
    nodo_agregar->significado = datos[2];
    nodo_agregar->sinonimo = datos[3];
    nodo_agregar->antonimo = datos[4];
    // Creamos nodos auxiliares
    Nodo *nodo1 = lista;
    Nodo *nodo2;
    // Ingresamos los elementos de forma ordenada dentro de la lista (orden alfabetico)
    while ((nodo1 != NULL) && (nodo1->letra < datos[0]))
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
bool eliminarPalabra(Nodo *&lista, string palabra){
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
            cout << "El elemento no ha sido encontrado" << endl;;
        } else if (anterior == NULL) {
            lista = lista->siguiente;
            delete aux_borrar;
            retorno = true;
        } else {
            anterior-> siguiente = aux_borrar->siguiente;
            delete aux_borrar;
            retorno = true;
        }   
    }
    return retorno;
}

// Función para buscar y mostrar la información por palabra
void buscarPalabra(string p){
 struct Nodo *temporal = lista;
  
    if (lista != NULL)
    {
        while (temporal != NULL)
        {
            if (temporal->palabra == p)
            {
                
                cout<<"Informacion relacionada a la palabra "<<temporal->palabra<<endl;
                cout<<"-----------------------------------------------------"<<endl;
                cout<<"Letra: "<<temporal->letra<<endl;
                cout<<"Significado: "<<temporal->significado<<endl;
                cout<<"Sinonimo: "<<temporal->sinonimo<<endl;
                cout<<"Antonimo: "<<temporal->antonimo<<endl;

                temporal = NULL;
            }
            else
            {
                if (temporal->siguiente == NULL)
                {
                    cout<<"La palabra ingresada no se encuentra en el diccionario."<<endl;
                }            
                temporal = temporal->siguiente;
            }
            
        }
    }
    else
    {
        cout << "No hay palabras en el diccionario"<<endl;
    }
}
