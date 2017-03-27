/*
 * Este sotfware foi feito para a UTFPR - Campus Curitiba;
 * O Código é livre para uso não comercial;
 * Desenvolvido através do Netbeans IDE.
 */

/* 
 * File:   main.cpp
 * Author: Marlon Prudente <marlonoliveira@alunos.utfpr.edu.br>
 *
 * Created on March 23, 2017, 5:57 PM
 */

#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <fstream>
#include "funcao_f.h"
#include "funcao_g.h"

using namespace std;

/*
 * 
 */

int main(int argc, char** argv) {
    
    funcao_f f ;
    funcao_g g;
    ofstream file;
    file.open("saida.txt");
    file << "Calculo Numérico - Métodos para encontrar raizes da função: " << endl;
    file.close();
    cout <<"Funcao F:"<<endl;
    cout << "Bisseccao:"<< endl;
    cout << f.bisseccao(12,16,0.5,10) << endl;
    cout << "Falsa Posição:"<< endl;
    cout << f.falsa_posicao(12,16,0.5,10) << endl;
    cout << "Newton-Raphson:"<< endl;
    cout << f.newton_raphson(12,0.5,10) << endl;
    cout << "Secante:"<< endl;
    cout << f.secante(12,0.5,10) << endl;
    
    cout <<"Funcao G:"<<endl;
    cout << "Bisseccao:"<< endl;
    cout << g.bisseccao(14,16,0.5,10) << endl;
    cout << "Falsa Posição:"<< endl;
    cout << g.falsa_posicao(12,16,0.5,10) << endl;
    cout << "Newton-Raphson:"<< endl;
    cout << g.newton_raphson(12,0.5,10) << endl;
    cout << "Secante:"<< endl;
    cout << g.secante(12,0.5,10) << endl;

    return 0;
}

