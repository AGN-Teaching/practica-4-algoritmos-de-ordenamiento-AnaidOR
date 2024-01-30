#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <chrono>
#include <cmath>
#include <iostream>
#include <fstream>

#include "ordenamiento_t.h"

using namespace std;
using namespace std::chrono;


duration<double> crear_arreglo(int *A, int TAM_ARREGLO, int RANGO_MAX) {
    high_resolution_clock::time_point inicio = high_resolution_clock::now();
    for (int i = 0; i < TAM_ARREGLO; i++) {
        int x = rand() % RANGO_MAX;
        A[i] = x;
    }
    high_resolution_clock::time_point fin = high_resolution_clock::now();
    duration<double> tiempo = duration_cast<duration<double> >(fin - inicio);
    return tiempo;
}


duration<double> ordenar_insertion_sort(int* A, int TAM_ARREGLO) {
    high_resolution_clock::time_point inicio = high_resolution_clock::now();
    insertion_sort(A, TAM_ARREGLO);
    high_resolution_clock::time_point fin = high_resolution_clock::now();
    duration<double> tiempo = duration_cast<duration<double> >(fin - inicio);
    return tiempo;
}


duration<double> ordenar_selection_sort(int* A, int TAM_ARREGLO) {
    high_resolution_clock::time_point inicio = high_resolution_clock::now();
    selection_sort(A, TAM_ARREGLO);
    high_resolution_clock::time_point fin = high_resolution_clock::now();
    duration<double> tiempo = duration_cast<duration<double> >(fin - inicio);
    return tiempo;
}


duration<double> ordenar_bubblesort(int* A, int TAM_ARREGLO) {
    high_resolution_clock::time_point inicio = high_resolution_clock::now();
    bubblesort(A, TAM_ARREGLO);
    high_resolution_clock::time_point fin = high_resolution_clock::now();
    duration<double> tiempo = duration_cast<duration<double> >(fin - inicio);
    return tiempo;
}


int* copiar_arreglo(int A[], int n) {
    int *aux = new int[n];
    for (int i = 0; i < n; i++) {
        aux[i] = A[i];
    }
    return aux;
}


void mostrar_arreglo(int *A, int n) {
    for (int i = 0; i < n; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

duration<double> ordenar_merge_sort(int* A, int TAM_ARREGLO) {
    high_resolution_clock::time_point inicio = high_resolution_clock::now();
    merge_sort(A, 0, TAM_ARREGLO-1);
    high_resolution_clock::time_point fin = high_resolution_clock::now();
    duration<double> tiempo = duration_cast<duration<double> >(fin - inicio);
    return tiempo;
}


duration<double> ordenar_quicksort(int* A, int TAM_ARREGLO) {
    high_resolution_clock::time_point inicio = high_resolution_clock::now();
    quicksort(A, 0, TAM_ARREGLO-1);
    high_resolution_clock::time_point fin = high_resolution_clock::now();
    duration<double> tiempo = duration_cast<duration<double> >(fin - inicio);
    return tiempo;
}

int probar() {
    
    int N, M;

    std:: cout << "Ingrese N: ";
    std :: cin >> N; 

    std:: cout << "Ingrese M: ";
    std :: cin >> M; 
    int RANGO_MAX = 10 * N;


   double t_prom_is = 0.0; // prom insertion
   double t_prom_ms = 0.0; // prom merge
   double t_prom_qs = 0.0; // prom quick
   double t_prom_ss = 0.0; // prom selection
   double t_prom_bs = 0.0; // prom bubble

    for (int i =0; i < M ; i++ ) {
        // Crea arreglo
        int *A = new int[N];
        crear_arreglo(A, N, RANGO_MAX);

        // Prueba alg 1
	    int*  aux = copiar_arreglo(A, N);

        duration<double> tiempo = ordenar_insertion_sort(aux, N);
        cout << "\tOrdenado Insertion. ";
        cout << "\tTiempo: " << tiempo.count() << "s" << endl;
        t_prom_is = t_prom_is + tiempo.count();

        // Prueba alg 2
	    aux = copiar_arreglo(A, N);

    tiempo = ordenar_merge_sort(aux, N);
        cout << "\tOrdenado merge. ";
        cout << "\tTiempo: " << tiempo.count() << "s" << endl;
        t_prom_ms = t_prom_ms + tiempo.count();

        //Prueba alg 3
        aux = copiar_arreglo(A, N);

    tiempo = ordenar_quicksort(aux, N);
        cout << "\tOrdenado quick. ";
        cout << "\tTiempo: " << tiempo.count() << "s" << endl;
        t_prom_qs = t_prom_qs + tiempo.count();   

        //Prueba alg 4 
         
	    aux = copiar_arreglo(A, N);

    tiempo = ordenar_selection_sort(aux, N);
        cout << "\tOrdenado selection. ";
        cout << "\tTiempo: " << tiempo.count() << "s" << endl;
        t_prom_ss = t_prom_ss + tiempo.count();

        //Prueba alg 5

	    aux = copiar_arreglo(A, N);

    tiempo = ordenar_bubblesort(aux, N);
        cout << "\tOrdenado bubble. ";
        cout << "\tTiempo: " << tiempo.count() << "s" << endl;
        t_prom_bs = t_prom_bs + tiempo.count();
        
    }

    std::ofstream archivoSalida("resultados.txt", std::ios::app);

    archivoSalida << "N: "<< N <<"\nM: "<< M  <<endl;

    archivoSalida << "Promedio Insertion sort: " << t_prom_is / M << "\n"
                  << "Promedio Merge sort: " << t_prom_ms / M << "\n"
                  << "Promedio Quick sort: " << t_prom_qs / M << "\n"
                  << "Promedio Selection sort: " << t_prom_ss / M << "\n"
                  << "Promedio Bubble sort: " << t_prom_bs / M << std::endl;

    archivoSalida << "Desviacion Insertion sort: " << sqrt(pow(t_prom_is - (t_prom_is / M), 2) / M) << "\n"
                  << "Desviacion Merge sort: " << sqrt(pow(t_prom_ms - (t_prom_ms / M), 2) / M) << "\n"
                  << "Desviacion Quick sort: " << sqrt(pow(t_prom_qs - (t_prom_qs / M), 2) / M) << "\n"
                  << "Desviacion Selection sort: " << sqrt(pow(t_prom_ss - (t_prom_ss / M), 2) / M) << "\n"
                  << "Desviacion Bubble sort: " << sqrt(pow(t_prom_bs - (t_prom_bs / M), 2) / M) << std::endl;

    // Cierra el archivo
    archivoSalida.close();

    return 0; 
}



