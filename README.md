# Programa selector de películas extranjeras

## Funcionamiento
Objetivo: Gracias a este programa un usuario puede buscar la película extranjera más corta del país que elija. Se devuelve el primer resultado que encuentre, porque debido a que es para curiosear, no se quiere gastar mucho tiempo.

Este programa sirve para que un usuario pueda elegir una película de una base de datos
donde se almacenan películas raras y extranjeras.

La información de todas las películas está almacenada en un archivo csv el cuál contiene la información de las películas (título, duración, país, director y calificación), este archivo se leee y posteriormente se ordena respecto a los minutos de menor a mayor y se escriben ordenadas en un nuevo archivo.
Este archivo se lee nuevamente y se pasa a una esetructura de lista ligada simple, en la cuál el usuario puede buscar una película por país o por calificación.

## SICT0302B
### - Selecciona un algoritmo de ordenamiento adecuado al problema
El programa tiene una función de ordenamiento llamada "insertionSort" en el archivo "ordenamiento.h", esta se emplea en el main y tiene el objetivo de ordenar de menor a mayor la duración de las películas, que se mete en un vector de minutos.

### - Selecciona y usa una estructura lineal adecuada al problema
El programa tiene una lista ligada simple que está en el archivo "estructuralineal.h", y tiene el objetivo de almacenar los datos de películas leídas desde el archivo "timeSortedMovies.csv", y posteriormente buscar datos.


## SICT0303B
### - Implementa mecanismos para consultar información de las estructras correctos
Para consultar información de la lista ligada utilicé un método de "string buscaPais(string val)" en el archivo de "estructuralineal.h" y se manda a llamar en el main.cpp después de que el usuario busque un país y la función regrese el título y director de la película del país elegido.

### - Implementa mecanismos de lectura de archivos correctos
El programa lee un archivo csv llamado "imdbMovies.csv" que es donde están almacenadas todas las películas en la función "void read(vector <Pelicula> &minutes)" que se encuentra en el main.cpp y lee cada linea de la información de las películas para meterlas en un vector.

### - Implementa mecanismos de escritura de archivos correctos
El programa implementa una función llamada "void writeSort(vector <Pelicula> &vector)"  que se encuantra en el main.cpp y tiene el objetivo de vaciar el vector ordenado "minutes" y escribir en el archivo "timeSortedMovies.csv" los datos de las películas ordenadas por minutos (de menor a mayor) y tener ese archivo como respaldo y además leerlo para meterlo a la lista ligada.