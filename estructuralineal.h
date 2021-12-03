#ifndef ESTRUCTURALINEAL_H
#define ESTRUCTURALINEAL_H

#include <string>
#include <sstream>
#include "peliculas.h"

template <class T>
class List {
public:
	List();
	List(const List<T>&);

	std::string toString() const;
	void agregar(string,string,string,string,string);
	string buscaPais(string val);
	void agregaPrimero(string,string,string,string,string);
	bool empty() const;
	void read2();

private:
	Pelicula *head;
	int 	size;
};

template <class T>
List<T>::List() : head(0), size(0) {}

template <class T>
bool List<T>::empty() const {
	return (head==0);
}

//Lee el archivo ordenado y agrega los elementos a la lista ligada
template <class T>
void List<T>::read2(){
    ifstream archivo("timeSortedMovies.csv");
    string linea;
    Pelicula *p = new Pelicula();
    
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
        p->nuevaPelicula(Title,Duration,Country,Director,Avg_vote);
		agregar(Title,Duration,Country,Director,Avg_vote);
    }
}

template <class T>
void List<T>::agregaPrimero(string Ti,string Dur, string Co, string Dir, string avgg) {
	Pelicula *newLink;
	newLink = new Pelicula();
	newLink->nuevaPelicula(Ti,Dur,Co,Dir,avgg);

	newLink->next = head;
	head = newLink;
	size++;
}

//Añade elementos a la lista ligada
template <class T>
void List<T>::agregar(string Ti,string Dur, string Co, string Dir, string avgg) {
	Pelicula *newLink, *p;
	newLink = new Pelicula();
	newLink->nuevaPelicula(Ti,Dur,Co,Dir,avgg);
	if(empty()){
		agregaPrimero(Ti,Dur,Co,Dir,avgg);
		return;
	}
	p = head;
	while(p->next != 0){
		p = p->next;
	}
	newLink->next = 0;
	p->next = newLink;
	size++;
}

//Busca en toda la lista el país ingresado por el 
// usuario en el main y regresa el título y director.
template <class T>
string List<T>::buscaPais(string val){
	int index = 0;
	Pelicula *p = new Pelicula();

	p = head;
	while(p != 0){
		if(p->getCountry() == val){
			return (p->getTitle()+", dirigida por: "+p->getDirector()+" es la pelicula que te recomendamos ver!\n\nEncuentrala en Rakuten.tv o Vix.com !\n");
		}
		index++;
		p = p->next;
	}
	return "Desafortunadamente, su pelicula no existe :( ";
}

template <class T>
std::string List<T>::toString() const {
	std::stringstream aux;
	Pelicula *p;

	p = head;
	aux << "[";
	while (p != 0) {
		aux << p->getTitle()<<p->getCountry();
		if (p->next != 0) {
			aux << ", ";
		}
		p = p->next;
	}
	aux << "]";
	return aux.str();
}

#endif