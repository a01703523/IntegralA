#ifndef PELICULAS_H
#define PELICULAS_H 

#include <iostream>
#include <vector>
#include <list>
using namespace std;

class Pelicula {
private:
    string Title,Duration,Country,Director,Avg_vote;
public:
    string getTitle();
    int getDuration();
    string getCountry();
    string getDirector();
    float getAvg_vote();
    Pelicula *next;

    void nuevaPelicula(string,string,string,string,string);
};

void Pelicula::nuevaPelicula(string tit,string dur,string ctry,string dir,string avg){
    Title = tit;
    Duration = dur;
    Country = ctry;
    Director = dir;
    Avg_vote = avg;
}

string Pelicula::getTitle(){
    return Title;
}

int Pelicula::getDuration(){
    int minutes = stoi(Duration);
    return minutes;
}

string Pelicula::getCountry(){
    return Country;
}

string Pelicula::getDirector(){
    return Director;
}

float Pelicula::getAvg_vote(){
    float avg = stof(Avg_vote);
    return avg;
}

#endif