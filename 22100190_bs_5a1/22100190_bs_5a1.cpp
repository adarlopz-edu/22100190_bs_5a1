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

struct Nodo {
    Persona persona;
    Nodo* siguiente;
};

class MetodoHash {
private:
    string preguntaOpcion;
    string preguntaBusqueda;
    Nodo* tablaHash[113];

public:
    MetodoHash();
    void ingresarDatos(Persona& persona);
    void Hash(Persona persona);
    void buscarElemento(int registro);
    void buscarElementoString(string nombre);
};

MetodoHash::MetodoHash() {
    for (int i = 0; i < 113; ++i) {
        tablaHash[i] = 0;
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
    Nodo* elemento = tablaHash[indice];

    if (elemento == nullptr) {
        cout << "No se encontro ningun elemento en la tabla" << endl;
        return;
    }

    while (elemento != nullptr) {
        if (elemento->persona.registro == registro) {
            cout << "Registro: " << elemento->persona.registro << endl;
            cout << "Nombre: " << elemento->persona.nombre << endl;
            cout << "Apellido: " << elemento->persona.apellido << endl;
            cout << "Edad: " << elemento->persona.edad << endl;
        }
        elemento = elemento->siguiente;
    }
}

void MetodoHash::buscarElementoString(string nombre) {
    for (int i = 0; i < 113; ++i) {
        Nodo* elemento = tablaHash[i];
        while (elemento != 0) {
            if (elemento->persona.nombre == nombre) {
                cout << "Registro: " << elemento->persona.registro << endl;
                cout << "Nombre: " << elemento->persona.nombre << endl;
                cout << "Apellido: " << elemento->persona.apellido << endl;
                cout << "Edad: " << elemento->persona.edad << endl;
            }
            elemento = elemento->siguiente;
        }
    }
}

void MetodoHash::Hash(Persona persona) {
    int indice = persona.registro % 113;

    Nodo* nuevoNodo = new Nodo;
    nuevoNodo->persona = persona;
    nuevoNodo->siguiente = 0;

    if (tablaHash[indice] == 0) {
        tablaHash[indice] = nuevoNodo;
    }
    else {
        Nodo* actual = tablaHash[indice];
        while (actual->siguiente != 0) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevoNodo;
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
