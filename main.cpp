//Salvador Santana Blanco
//A01703523

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>
#include <string>

#include "ordenamiento.h"
using namespace std;


vector<string> minutes;

void read(vector <string> &minutes){
    ifstream archivo("IMDB-Movie-Data.csv");
    string linea;
    getline(archivo, linea);
    
    while (getline(archivo, linea)){

        stringstream stream(linea);
        string Rank,Title,Director,Year,Runtime,Rating,Votes,Revenue;

        getline(stream, Rank, ',');
        getline(stream, Title, ',');
        getline(stream, Director, ',');
        getline(stream, Year, ',');
        getline(stream, Runtime, ',');

        stoi(Runtime);
        minutes.push_back(Runtime);

        getline(stream, Rating, ',');
        getline(stream, Votes, ',');
        getline(stream, Revenue, ',');
  
    }
    for(int i = 0; i < minutes.size(); i++){
        cout << "Min. en desorden: "<<minutes[i] << endl;
    }
    
    
    }


int main(){
    
    vector<string> minutes;
    read(minutes);
    Sorts <string> min;
    min.insertionSort(minutes);
    for(int i = 0; i < min.insertionSort(minutes).size(); i++){
        cout << "Min. de menor a mayor: " << min.insertionSort(minutes)[i] << endl;
    }

    return 0;
}