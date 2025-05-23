#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Persona
{
    char nombre[50];
    int edad;
};


int main(int argc, char const *argv[])
{
    //ifstream archivoEntrada; //archivo de entrada
    ofstream archivoSalida;  //archivo de salida

    //Abrir el archivo de entrada
    archivoSalida.open("archivo_salida.bin",ios::binary);
    if(!archivoSalida){
        cerr << "Error al abrir el archivo de salida." <<endl;
        return 1;
    }
    
    Persona p1 = {"Juan", 30};
    Persona p2 = {"Maria", 25};
    
    // Escribir en el archivo de salida 
    archivoSalida.write((const char*)(&p1),sizeof(Persona));
    archivoSalida.write((const char*)(&p2),sizeof(Persona));
    
    //cerrar el archivo de salida
    archivoSalida.close();

    // -------------------------------
    ifstream archivoEntrada;
    Persona p;
    //Abrir el archivo de entrada
    archivoEntrada.open("archivo_salida.bin", ios::binary);
    if(!archivoEntrada){
         cerr << "Error al abrir el archivo de Entrada." <<endl;
         return 1;
    }
    // Leer el archivo de entrada
    while(archivoEntrada.read((char*)(&p), sizeof(Persona))) {
         cout << "Nombre: " << p.nombre << ", Edad: " << p.edad <<endl;
    }    
    
    //Cerrar el archivo de entrada
    archivoEntrada.close();

    return 0;
}