#include<iostream>
#include <iostream>
#include <cstdlib>
#include <ctime>

int main()
{
    // int a,b;
    // std::cout<< "A: ";
    // std::cin>>a;
    // std::cout<< "B: ";
    // std::cin>>b;
    // std::cout<<a/b;
    // std::cout<<std::endl;
    // Initialise la graine pour la génération de nombres aléatoires basée sur le temps
    srand(time(NULL));
    // Génère et affiche trois nombres aléatoires entre 0 et RAND_MAX
    for (int i = 0; i < 3; ++i) {
        int random_number = rand() % 2;
        std::cout << "Random Number " << i + 1 << ": " << random_number << std::endl;
    }

}