/**     k-esimo menor numero de um vetor de tamanho n.
*
*    g++ kesimo.cpp func.h -o saida -Wall -std=c++11
*     Desta maneira o programa vai gerar um vetor com elementos aleatorios.
*
*   -DSHOWFUNC    : Mostra os passos ocorridos durante a execuçao da funçao deMenor.
*   -DWORSTCASE   : Enche o vetor com numeros naturais de maneira decrescente.
*   
*   -Como executar ./t x y 
*     Onde x e y sao int que definem o tamanho e o k-esimo numero respectivamente. Caso
*     nao informados, assumiram os valores padroes.
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <random>
#include <vector>
#include <chrono>

#include "funcoes.h"


#define N 7 // default array size

using namespace std;


//--------------------------------------------------------------------------------
//
int main( int argc, char * argv[] )
{
    auto n( N );        // Array size.
    auto result(0);     // Stores the result from deMenor.
    auto k(1);          // k-esim smaller element.

    if ( argc > 1 )    {
        std::stringstream( argv[1] ) >> n;
        
        if ( argc > 2 ) {
            std::stringstream( argv[2] ) >> k;
        }
    }

    std::cout << "\n\n>>> Required array size is: " << n << std::endl;

    // Store the data.
    std::vector< int > V( n );

#ifdef WORSTCASE
    // Fill it up with integers from file.
    setFill( V , n);
#endif

#ifndef WORSTCASE
    // Seed with a real random value, if available.
    std::random_device r;
    // Fill it up with random integers.
    randomFill( V, -100, 100, r() );
#endif

    //Printing out the array for test.
    std::cout << ">>> Vet = [ ";
    for( const auto &e : V )
        std::cout << e << " ";
    std::cout << "]\n";

    std::cout << ">>> STARTING computation that needs timing <<<\n";
    auto start = std::chrono::steady_clock::now();
    //================================================================================
    
    result = deMenor( V , n, k );    

    //================================================================================
    auto end = std::chrono::steady_clock::now();
    std::cout << ">>> ENDING computation that needs timing <<<\n";

    cout << ">>> " << k << "º menor de todos: " << result << endl;

    // Store the time difference between start and end
    auto diff = end - start;


    //Printing out the array for test.
    std::cout << ">>> Vet = [ ";
    for( const auto &e : V )
        std::cout << e << " ";
    std::cout << "]\n";

    // Milliseconds (10^-3)
    std::cout << "\t\t>>> " << std::chrono::duration <double, std::milli> (diff).count() << " ms" << std::endl;

    // Nanoseconds (10^-9)
    std::cout << "\t\t>>> " << std::chrono::duration <double, std::nano> (diff).count() << " ns" << std::endl;

    // Seconds
    auto diff_sec = std::chrono::duration_cast<std::chrono::seconds>(diff);
    std::cout << "\t\t>>> " << diff_sec.count() << " s" << std::endl;
        

    return EXIT_SUCCESS;

}