//Salvador Santana Blanco - A01703523

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>

#include "ordenamiento.h"
#include "peliculas.h"
#include "estructuralineal.h"

using namespace std;

void read(vector <Pelicula> &minutes){
    ifstream archivo("imdbMovies.csv");
    string linea;
    Pelicula p;
    
    getline(archivo, linea);
    
    while (getline(archivo, linea)){
        stringstream stream(linea);
        string Title,Duration,Country,Director,Avg_vote;

        getline(stream, Title, ',');
        getline(stream, Duration, ',');
        getline(stream, Country, ',');
        getline(stream, Director, ',');
        getline(stream, Avg_vote, ',');

        int mins = stoi(Duration);
        p.nuevaPelicula(Title,Duration,Country,Director,Avg_vote);
        minutes.push_back(p);
    }
}

void writeSort(vector <Pelicula> &vector){
    ofstream pel_ordenadas("timeSortedMovies.csv");
    pel_ordenadas << "Title,Duration,Country,Director,Avg_vote" << endl;
    for(int i = 0; i < vector.size(); i++){
        pel_ordenadas <<vector[i].getTitle()<<","<<vector[i].getDuration()<<","<<vector[i].getCountry()<<","<<vector[i].getDirector()<<","<<vector[i].getAvg_vote()<<endl;
    } 
    pel_ordenadas.close();
}

void read2(vector <Pelicula> &minutes){
    ifstream archivo("timeSortedMovies.csv");
    string linea;
    Pelicula p;
    
    getline(archivo, linea);
    
    while (getline(archivo, linea)){
        stringstream stream(linea);
        string Title,Duration,Country,Director,Avg_vote;

        getline(stream, Title, ',');
        getline(stream, Duration, ',');
        getline(stream, Country, ',');
        getline(stream, Director, ',');
        getline(stream, Avg_vote, ',');

        int mins = stoi(Duration);
        p.nuevaPelicula(Title,Duration,Country,Director,Avg_vote);
        minutes.push_back(p);
    }
}

int main(){

    cout<<"\n\nHola! Bienvenido a su programa para ver peliculas extranjeras cortas!"<<endl;
    cout<<"Elija un pais del que quisiera ver una pelicula corta."<<endl;
    cout<<"Para desplegar la lista presione 1, para salir presione 2:  ";
    int continuar;
    cin>>continuar;
    if(continuar==1){
        cout<<"\n";
        Pelicula p1;
        vector<Pelicula> minutes;
        read(minutes);

        Sorts <Pelicula> min;
        min.insertionSort(minutes); 
        for(int i = 0; i < minutes.size(); i++){
            cout << minutes[i].getDuration() << " minutos - " << minutes[i].getCountry() << endl;
        }

        cout<<"\nEscriba su eleccion tal cual aparece: ";
        string eleccion;
        cin >> eleccion;  
 
        writeSort(minutes);
        List<Pelicula> list1;
        list1.read2();
        cout<<list1.buscaPais(eleccion);

        cout<<"\nSi quieres ver la lista de peliculas completas,\npuedes consultar el archivo de timeSortedMovies.csv\n\n";

    }
    else{
        cout<<"Operacion cancelada. Vuelva pronto!"<<endl;
    }
    return 0;
}