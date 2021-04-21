#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

struct datos_de_camas{
    int fecha;
    int codigo_hospital;
    int numero_de_cama;
    struct datos_de_camas *next;

} ;
typedef datos_de_camas *Lista;//Crea una lista vacia

void leeArchivo(datos_de_camas *&Lista)
{
    ifstream archivo;
    int i=0;
    vector<string> datos;
    string linea;
    archivo.open("camas_ocupadas.csv",ios::in);
    getline(archivo,linea);

    if(archivo.is_open())
    {
        datos_de_camas *new_nodo = new datos_de_camas();
        while(getline(archivo,linea))
        {
            stringstream ss(linea);
            string temp;
            while(getline(ss,temp,';'))
            {
                datos.push_back(temp);
            }
            int fecha = atoi(datos[0].c_str());
            int codigo_hospital = atoi(datos[1].c_str());
            int numero_de_cama = atoi(datos[2].c_str());
            new_nodo->fecha = fecha;
            new_nodo->codigo_hospital = codigo_hospital;
            new_nodo->numero_de_cama = numero_de_cama;

            while(new_nodo!=NULL)
            {
                cout << new_nodo->fecha << endl;
                cout << new_nodo->codigo_hospital << endl;
                cout << new_nodo->numero_de_cama << endl;
            }

        }
    }
}

int main()
{
    string nombrearchivo;
    int eleccion;
    int i=0;
    datos_de_camas *Lista=NULL;
    leeArchivo(Lista);
    /*do
    {
        cout<<"Digite 1 Informacion de las camas"<<endl;
        cout<<"Digite 2 Generar archivo con disponibilidad de camas"<<endl;
        cout<<"Digite 3 Salir"<<endl;
        cout<<endl;
        cout<<"Ingrese una opcion..."<<endl;
        cin>>eleccion;

        switch(eleccion)
        {
            case 1: cout<<"Opcion 1"<<endl;
                    leeArchivo();
                    break;
            case 2: cout<<"Opcion 2"<<endl;
                    break;
            case 3: cout<<"Programa finalizado"<<endl;
                    break;
        }
    }while(eleccion!=3);*/
}
