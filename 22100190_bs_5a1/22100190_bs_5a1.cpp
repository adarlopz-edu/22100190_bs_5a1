#include <iostream>
#include <string>
#include <cmath>
using namespace std;

struct Persona {
    int registro;
    string nombre;
    string apellido;
    int edad;
};

struct Lista {
    Persona persona;
    Lista* siguienteElemento;
};

class MetodoHash {
private:
    string preguntaOpcion;
    string preguntaBusqueda;
    Lista* tablaHash[113];

public:
    MetodoHash();
    void ingresarDatos(Persona& persona);
    void Hash(Persona persona);
    void buscarElemento(int registro);
    void buscarElementoString(string nombre);
};

MetodoHash::MetodoHash() {
    for (int i = 0; i < 113; ++i) {
        tablaHash[i] = 0; //todas las posiciones se van a cero
    }
}

void MetodoHash::ingresarDatos(Persona& persona) {
    cout << endl << "BUSQUEDA SECUENCIAL" << endl;
    cout << "a) Introducir datos" << endl << "b) Buscar" << endl << "c) Salir" << endl;
    cout << "Cual es tu opcion? ";
    cin >> preguntaOpcion;

    for (char& c : preguntaOpcion) {
        c = tolower(c);
    }

    if (preguntaOpcion == "a") {
        cout << endl << "Ingresa tu registro: ";
        cin >> persona.registro;

        cout << "Nombre: ";
        cin >> persona.nombre;
        persona.nombre = persona.nombre.substr(0, 50);

        cout << "Apellido: ";
        cin >> persona.apellido;
        persona.apellido = persona.apellido.substr(0, 50);

        cout << "Edad: ";
        cin >> persona.edad;
        Hash(persona);
    }
    if (preguntaOpcion == "b") {
        cout << endl << "Quieres buscar por nombre?";
        cin >> preguntaBusqueda;

        for (char& c : preguntaBusqueda) {
            c = tolower(c);
        }

        if (preguntaBusqueda == "si") {
            cout << endl << "Ingresa un nombre a buscar: ";
            cin >> persona.nombre;
            buscarElementoString(persona.nombre);
        }
        if (preguntaBusqueda == "no") {
            cout << endl << "Ingresa un registro a buscar: ";
            cin >> persona.registro;
            buscarElemento(persona.registro);
        }
    }
    if (preguntaOpcion == "c") {
        exit(1);
    }
}

void MetodoHash::buscarElemento(int registro) {
    int indice = registro % 113;
    Lista* elemento = tablaHash[indice];

    if (elemento == 0) {
        cout << "No se encontro ningun elemento en la tabla" << endl;
        return;
    }

    // busqueda secuencial posicion por posicion con los punteros de la estructura
    for (Lista* actual = elemento; actual != 0; actual = actual->siguienteElemento) {
        if (actual->persona.registro == registro) {
            cout << "Registro: " << actual->persona.registro << endl;
            cout << "Nombre: " << actual->persona.nombre << endl;
            cout << "Apellido: " << actual->persona.apellido << endl;
            cout << "Edad: " << actual->persona.edad << endl;
            return;
        }
    }
    cout << "No se encontro ningun elemento en la tabla" << endl;
}

void MetodoHash::buscarElementoString(string nombre) {
    for (char& c : nombre) {
        c = tolower(c);
    }

    // recorrer todas las posiciones de la tabla hash
    for (int i = 0; i < 113; ++i) {
        Lista* elemento = tablaHash[i];

        // si el elemento en la posición actual no es nulo, buscar en la lista asociada
        for (; elemento != nullptr; elemento = elemento->siguienteElemento) {
            string nombrePersona = elemento->persona.nombre;

            for (char& c : nombrePersona) {
                c = tolower(c);
            }

            if (nombrePersona == nombre) {
                // Se encontró el elemento, imprimir sus detalles
                cout << "Registro: " << elemento->persona.registro << endl;
                cout << "Nombre: " << elemento->persona.nombre << endl;
                cout << "Apellido: " << elemento->persona.apellido << endl;
                cout << "Edad: " << elemento->persona.edad << endl;
                return;
            }
        }
    }
    // Si no se encontró ningún elemento con el nombre dado
    cout << "No se encontró ninguna persona con el nombre '" << nombre << "'" << endl;
}



void MetodoHash::Hash(Persona persona) {
    int indice = persona.registro % 113;

    // aqui es para crear un nuevo espacio en la lista en caso de colision se declaran antes de
    Lista* nuevoElemento = new Lista;
    nuevoElemento->persona = persona;
    nuevoElemento->siguienteElemento = 0;

    // si en la posicion hay un cero esta vacia, ahi se coloca el elemento
    if (tablaHash[indice] == 0) {
        tablaHash[indice] = nuevoElemento;
    }
    else {
        // si ya hay algo en el espacio que se declaro arriba ahi es donde se posicinara el elemento
        Lista* i = tablaHash[indice];
        while (i->siguienteElemento != 0) {
            i = i->siguienteElemento;
        }
        i->siguienteElemento = nuevoElemento; // añade el elemento al final de la lista en esa misma posicion en la tabla
    }
}


int main() {
    MetodoHash ordenamiento;
    Persona persona;

    while (true) {
        ordenamiento.ingresarDatos(persona);
    }

    cout << endl;
    return 0;
}