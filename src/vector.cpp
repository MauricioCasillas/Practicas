#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <list>
#include <set>

using namespace std;

enum Columnas{
    INDICE,
    NOMBRE,
    NUMERO,
    TIPO,
    ETAPA,
    ANTECESOR,
    ANTECESOR_NO
};

enum TipoPokemon{   //Lista de etiquetas ordenadas que se les da un numero
    FUEGO, //Tambien FUEGO = 5
    AGUA,
    PLANTA,
    ELECTRICIDAD,
    VENENO
};

class Pokemon{
    private:
        string nombre;
        set<TipoPokemon> tipos;
        int nivel;
    public:
        Pokemon(string nombre, set<TipoPokemon> tipos, int nivel){
            this->nombre = nombre;
            this->tipos = tipos;
            this->nivel = nivel;
        }
        string GetNombre(){
            return this->nombre;
        }
};

int main(int argc, char const *argv[])
{

    //Arreglos clasicos
    string frases[10];  // No se puede modificar en tiempo de ejecucion
    frases[0] = "Frase 1";
    frases[1] = "Frase 2";
    
    // vector libreria estandar
    vector<string> vFrases; //Se pueden agregar mas en tiempo ejecucion
    vFrases.push_back("Primera Frase");
    vFrases.push_back("Segunda Frase");
    vFrases.push_back("Tercera Frase");
    vFrases.push_back("Cuarta Frase");

    vector<int> vEnteros; // Remplazar tipo entre <> para cambiar el valor del vector
    vEnteros.push_back(3);
    vEnteros.push_back(5);
    vEnteros.push_back(1);
    vEnteros.push_back(9);

    

    fstream pokeCSV("assets/pokedex.csv");    
    if(!pokeCSV){
        cerr << "Error leyendo archivo del pokedex"<<endl;
        return EXIT_FAILURE;
    }

    // Cargar pokemones desde el archivo
    string linea;
    vector<Pokemon> pokedex;
   
    pokedex.push_back(Pokemon("Misigno",{TipoPokemon::VENENO},999));

    while(getline(pokeCSV,linea)){
        cout<< linea <<endl;

        //Convertir a un stream de cadena
        stringstream ss(linea);
       
        //Crear lista temporal para las ListaColumnas
        vector<string> ListaColumnas;
       
        //Extraer un valor y guardar en la lista
        string valor;
        while(getline(ss,valor,',' )){
            ListaColumnas.push_back(valor);
        }  

        try
        {
            //Crear el pokemon
        Pokemon p(
            ListaColumnas.at(Columnas::NOMBRE),
            { TipoPokemon::AGUA },
            stoi(ListaColumnas.at(Columnas::ETAPA))
        );
            // Agregar pokemon al pokedex
            pokedex.push_back(p);
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
        }
        
    }

    cout<<"Pokemons cargados al pokedex = "<<pokedex.size()<<endl;
    cout<<" El pokemon 5 es "<<pokedex.at(5).GetNombre()<<endl;


    return EXIT_SUCCESS;
}
