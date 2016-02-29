#include <iostream>
#include <fstream>
#include <sstream>
#include <random>
#include <vector>
#include <chrono>


using namespace std;

//FUNCTIONS:
//

//Fill a vector with random numbers in the range [lower, upper]
void randomFill( std::vector<int> &V, const int lower, const int upper, const unsigned int seed) {

    //use the default random engine and an uniform distribution
    std::default_random_engine eng(seed);
    std::uniform_real_distribution<double> distr(lower, upper);

    for( auto &elem : V){
        elem = distr(eng);
    }
}

//Fill a vector with decreasing positive integers
void setFill( std::vector<int> &V, int size) {

    for (auto &elem : V){
        elem = size--;
    }

}


int deMenor( std::vector<int> &V, const int &size, const int &k) {

    int k_esima = 0;



    #ifdef SHOWFUNC

    int steps(0);   //numero de vezes que a op. dominante vai rodar
    cout << "\n>>> SHOWING FUNCTION deMenor.\n>>>\n";
    cout << ">>> steps = number of times the dominant op will run.\n>>>\n";
    for( /* empty */ ; k_esima < k; k_esima++)
    {
      cout << ">>> k_esima: " << k_esima << " going until " << (k-1) << ".\n>>>\n";
        for (int i = (k_esima + 1); i < size; i++)
        {
            steps++;
            //OPERAÇAO DOMINANTE=================================
            cout << ">>> V[" << k_esima << "] = " << V[k_esima];
            cout << " and V[" << i << "] = " << V[i] << endl;
            if( V[k_esima] > V[i] ) {
                //coloca o menor valor na k-esima casa do vetor.
                swap ( V[k_esima], V[i] );
                cout << ">>> SWAPING VALUES\n";
            }
            //=================================OPERAÇAO DOMINANTE
        }
    }
    cout <<">>>\n>>> steps = " << steps << ", k = " << k << ", size = " << size << endl << endl;
    #endif
    
    #ifndef SHOWFUNC
    for( /* empty */ ; k_esima < k; k_esima++)
    {
        for (int i = (k_esima + 1); i < size; i++)
        {
            if( V[k_esima] > V[i] ) {
                // coloca o menor valor na k-esima casa do vetor.
                swap ( V[k_esima], V[i] );
            }   
        }
    }
    #endif

    // como o k_esima terah seu valor aumentado em 1 unidade sempre que iniciar
    // o para ( k_esima++), deve-se retornar V[k_esima-1].
    return V[k_esima-1];
    

}