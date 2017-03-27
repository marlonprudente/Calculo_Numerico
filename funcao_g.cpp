/*
 * Este sotfware foi feito para a UTFPR - Campus Curitiba;
 * O Código é livre para uso não comercial;
 * Desenvolvido através do Netbeans IDE.
 */

/* 
 * File:   funcao_g.cpp
 * Author: Marlon Prudente <marlonoliveira@alunos.utfpr.edu.br>
 * 
 * Created on March 23, 2017, 5:58 PM
 */

#include "funcao_g.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <math.h>

using namespace std;

funcao_g::funcao_g() {
}

float funcao_g::valor_y(float x) {

    return log(x);
}

float funcao_g::derivada(float x) {
    if (x == 0) {
        return -1;
    } else {
        return (1 / x);
    }
}

float funcao_g::bisseccao(float xl, float xu, float es, int imax) {
    float auxl, auxu, xr, auxr, ea, xrold;
    xr = 0.5 * (xl + xu);
    ofstream file;
    file.open("saida.txt", ofstream::app);
    file << "G -> Bisseccao: " << endl;
    int i = 0;
    while ((ea > es) || (i != imax)) {
        auxl = log(xl);
        auxu = log(xu);
        xrold = xr;
        xr = 0.5 * (xl + xu);
        auxr = log(xr);

        if (auxr == 0) {
            return xr;
        } else if (auxr * auxu < 0) {
            xl = xr;
            i++;
        } else {
            xu = xr;
            i++;
        }
        ea = fabs((xr - xrold) / xr);
        file << "i = " << i - 1 << ", Ea = " << ea << ", Xr = " << xr << endl;
        // cout << "I: " << i << " Ea: " << ea << endl;
    }
    file.close();
    //ea = ea*100;
    // cout << "I: " << i << " Ea: " << ea << endl;

    return xr;
};

float funcao_g::falsa_posicao(float xl, float xu, float es, int imax) {
    float auxl, auxu, xr, auxr, ea, xrold;
    ofstream file;
    file.open("saida.txt", ofstream::app);
    file << "G -> Falsa Posição: " << endl;
    int i = 0;
    while ((ea > es) || (i != imax)) {
        auxl = log(xl);
        auxu = log(xu);
        // xr = (xu - (auxu*(xl-xu)))/(auxl-auxu);
        xr = (xl * auxu - xu * auxl) / (auxu - auxl);
        xrold = xr;
        auxr = log(xr);

        if (auxr == 0) {
            return xr;
        } else if (auxr * auxu < 0) {
            xl = xr;
            i++;
        } else {
            xu = xr;
            i++;
        }
        ea = fabs(xu - xl);
        // cout << "I: " << i << " Ea: " << ea << endl;
        file << "i = " << i - 1 << ", Ea = " << ea << ", Xr = " << xr << endl;
    }
    file.close();
    //ea = ea*100;
    // cout << "I: " << i << " Ea: " << ea << endl;



    return xr;
};

float funcao_g::newton_raphson(float xi, float es, int imax) {
    float xr, iter[imax];
    int i = 0;
    ofstream file;
    file.open("saida.txt", ofstream::app);
    file << "G -> Newton - Raphson: " << endl;
    iter[0] = xi;
    while ((log(iter[i])) > es) {
        if (i > imax) {
            cout << "ERRO" << endl;
        }
        if (iter[i] != 0) {
            iter[i + 1] = iter[i] - (log(iter[i])) / (1 / iter[i]);
            i++;
            file << "i = " << i << ", Xr = " << iter[i] << endl;
        } else {
            cout << "Erro: Divisão por Zero" << endl;
        }

    }
    file.close();
    xr = iter[i];

    return xr;
};

float funcao_g::secante(float xi, float es, int imax) {
    float xr, iter[imax] ;
    int  i = 0;
    ofstream file;
    file.open("saida.txt", ofstream::app);
    file << "G -> Secante: " << endl;
    iter[0] = xi;
    while((log(iter[i])) > es){
        if(i > imax){
            cout << "ERRO" << endl;
        }
        iter[i + 1] = iter[i] - ((log(iter[i]))*(iter[i] - iter[i+1]))/((log(iter[i])) - (log(iter[i + 1])));
        i++;
        file << "i = " << i << ", Xr = " << iter[i] << endl;
    }
    file.close();
    xr = iter[i];
    
    return xr;
};

funcao_g::funcao_g(const funcao_g& orig) {
}

funcao_g::~funcao_g() {
}

