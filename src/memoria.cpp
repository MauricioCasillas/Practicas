#include <iostream>
using namespace std;
class Chorizo{
private:
    bool size;
    bool encendido;
    bool otro;
public:
    void Inicializar(){
        size = 1;
        encendido = true;
        otro = true;
    }
    void Ejecutar(){
        cout<<"Ejecutando Chorizo"<<endl;
    }
};

int main(int argc, char const *argv[])
{
   
    cout<<endl<<"---------------------------------"<<endl;
    cout<<"Tamaño de memoria"<<endl;
    cout<<"---------------------------------"<<endl;
    cout<<"Tamaño int: "<<sizeof(int)<<endl;
    cout<<"Tamaño char: "<<sizeof(char)<<endl;
    cout<<"Tamaño bool: "<<sizeof(bool)<<endl;
    cout<<"Tamaño float:"<<sizeof(float)<<endl;
    cout<<"Tamaño void: "<<sizeof(void)<<endl;
    cout<<"Tamaño double: "<<sizeof(double)<<endl<<endl;

    // 8 375 186 227

    int a = 27;
    int b = 50;
    cout<<endl<<"---------------------------------"<<endl;
    cout<<"Memoria Estatica: "<<endl;
    cout<<"---------------------------------"<<endl;
    cout<<"Direccion a: "<<&a<<endl;
    cout<<"Valor     a: "<<a<<endl;
    cout<<"Tamaño    a: "<<sizeof(a)<<endl;

    cout<<"Direccion b: "<<&b<<endl;
    cout<<"Valor     b: "<<b<<endl;
    cout<<"Tamaño    b: "<<sizeof(b)<<endl<<endl;

    // * = Operador de indireccion
    // & = Operador de direccion

    cout<<endl<<"---------------------------------"<<endl;
    cout<<"Direcciones de memoria: "<<endl;
    cout<<"---------------------------------"<<endl;
    int* direccionA = &a;
    cout<<"Valor de DireccionA: "<<direccionA<<endl;
    cout<<"Tamaño puntero: "<<sizeof(int*)<<endl;
    cout<<"Direccion (&) de direccionA: "<<&direccionA<<endl;
    cout<<"Indireccion (*) de direccionA: "<<*direccionA<<endl;
    
    cout<<endl<<"---------------------------------"<<endl;
    cout<<"Arreglos: "<<endl;
    cout<<"---------------------------------"<<endl;
    int arreglo[10];
    cout<<"Direccion de arreglo: "<<&arreglo<<endl;
    cout<<"Direccion de arreglo[0]: "<<&arreglo[0]<<endl;
    cout<<"Direccion de arreglo[1]: "<<&arreglo[1]<<endl;
    cout<<"Direccion de arreglo + 0: "<<&arreglo + 0<<endl;
    cout<<"Direccion de arreglo + 1: "<<&arreglo + 1<<endl;

    cout<<endl<<"---------------------------------"<<endl;
    cout<<"Objetos :"<<endl;
    cout<<"---------------------------------"<<endl;
    cout<<"Tamaño Chorizo: "<<sizeof(Chorizo)<<endl;
    Chorizo pruebas;
    cout<<"Direccion Chorizo "<<&pruebas<<endl;
    
    cout<<endl<<"---------------------------------"<<endl;
    cout<<"Memoria Dinamica C (Estructurada): "<<endl;
    cout<<"---------------------------------"<<endl;
    cout<<"Malloc: "<<malloc(sizeof(int))<<endl;
    // Guardar direccion libre en un puntero
    void* memoriaDinamica = malloc((sizeof(int)));
   
    // Casteo, convertir una variable en otra variable
    cout<<"---------------------------------"<<endl;
    cout<<"Cast variables: "<<endl;
    int* punteroEntero = (int*)malloc(sizeof(int)); //Convertir de malloc void a entero
    *punteroEntero = 5; //Guardar los datos a donde esta apuntando
    cout<<"Direccion: "<<punteroEntero<<endl; //Imprimir la direccion que guardo el puntero
    cout<<"Valor: "<<*punteroEntero<<endl; //Imprimir el valor de la direccion
    
    //Liberar memoria
    free(punteroEntero); //free(memoria que quiero liberar)

    cout<<endl<<"---------------------------------"<<endl;
    cout<<"Memoria Dinamica C++ (Objetos): "<<endl;
    cout<<"---------------------------------"<<endl;
    cout<<"C: "<<(Chorizo*)malloc(sizeof(Chorizo))<<endl;
    cout<<"C++: "<<new Chorizo()<<endl;

    // C
    Chorizo* punteroC = (Chorizo*)malloc(sizeof(Chorizo));
    (*punteroC).Inicializar();
    free(punteroC);

    // C++
    Chorizo* punteroCXX = new Chorizo();
    delete punteroCXX;

    // Indireccion vs operador ->

    (*punteroCXX).Ejecutar(); //Indicreccion

    punteroCXX->Ejecutar(); // Operador "direccion de memoria"->"accion"

    return 0;
}