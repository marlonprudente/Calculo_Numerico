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
    float xl = 12;
    float xu = 16;
    float xi = 12;
    float es = 0.05;
    int imax = 10;
    
     
    
    funcao_f f ;
    funcao_g g;
    ofstream file;
    file.open("saida.txt");
    file << "Calculo Numérico - Métodos para encontrar raizes da função: " << endl;
    file.close();
    cout <<"Funcao F:"<<endl;
    cout << "Bisseccao:"<< endl;
    cout << f.bisseccao(xl,xu,es,imax) << endl;
    cout << "Falsa Posição:"<< endl;
    cout << f.falsa_posicao(xl,xu,es,imax) << endl;
    cout << "Newton-Raphson:"<< endl;
    cout << f.newton_raphson(xi,es,imax) << endl;
    cout << "Secante:"<< endl;
    cout << f.secante(xi,es,imax) << endl;
    
    cout <<"Funcao G:"<<endl;
    cout << "Bisseccao:"<< endl;
    cout << g.bisseccao(xl,xu,es,imax) << endl;
    cout << "Falsa Posição:"<< endl;
    cout << g.falsa_posicao(xl,xu,es,imax) << endl;
    cout << "Newton-Raphson:"<< endl;
    cout << g.newton_raphson(xi,es,imax) << endl;
    cout << "Secante:"<< endl;
    cout << g.secante(xi,es,imax) << endl;
    return 0;
}

