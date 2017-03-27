/*
 * Este sotfware foi feito para a UTFPR - Campus Curitiba;
 * O Código é livre para uso não comercial;
 * Desenvolvido através do Netbeans IDE.
 */

/* 
 * File:   funcao_f.cpp
 * Author: Marlon Prudente <marlonoliveira@alunos.utfpr.edu.br>
 * 
 * Created on March 23, 2017, 5:57 PM
 */
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include "funcao_f.h"
#include <math.h>

using namespace std;

funcao_f::funcao_f() {

}

float funcao_f::valor_y(float x) {

    float aux = (667.38 / x)*(1 - exp(-0.146843 * x)) - 40;
    return aux;

}

float funcao_f::derivada(float x) {
    float aux;
    if (x == 0) {
        return -1;
    } else {
        aux = (exp(-0.146843 * x)*(98.0001 * x - (667.38 * exp(0.146843 * x)) + 667.38)) / (x * x);
    }
    return aux;
}

float funcao_f::bisseccao(float xl, float xu, float es, int imax) {
    float auxl, auxu, xr, auxr, ea, xrold;
    xr = 0.5 * (xl + xu);
    ofstream file;
    file.open("saida.txt", ofstream::app);
    file << "F -> Bisseccao: " << endl;
    int i = 0;
    while ((ea > es) || (i != imax)) {
        auxl = (667.38 / xl)*(1 - exp(-0.146843 * xl)) - 40;
        auxu = (667.38 / xu)*(1 - exp(-0.146843 * xu)) - 40;
        xrold = xr;
        xr = 0.5 * (xl + xu);
        auxr = (667.38 / xr)*(1 - exp(-0.146843 * xr)) - 40;
        
        if (auxr == 0) {
            return xr;
        }
        else if (auxr*auxu < 0) {
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

float funcao_f::falsa_posicao(float xl, float xu, float es, int imax) {
    float auxl, auxu, xr, auxr, ea, xrold;
    ofstream file;
    file.open("saida.txt", ofstream::app);
    file << "F -> Falsa Posição: " << endl;
    int i = 0;
    while ((ea > es) || (i != imax)) {
        auxl = (667.38 / xl)*(1 - exp(-0.146843 * xl)) - 40;
        auxu = (667.38 / xu)*(1 - exp(-0.146843 * xu)) - 40;        
       // xr = (xu - (auxu*(xl-xu)))/(auxl-auxu);
        xr = (xl*auxu - xu*auxl)/(auxu - auxl);
        xrold = xr;
        auxr = (667.38 / xr)*(1 - exp(-0.146843 * xr)) - 40;
        
        if (auxr == 0) {
            return xr;
        }
        else if (auxr*auxu < 0) {
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

float funcao_f::newton_raphson(float xi, float es, int imax) {
    float xr, iter[imax] ;
    int  i = 0;
    ofstream file;
    file.open("saida.txt", ofstream::app);
    file << "F -> Newton - Raphson: " << endl;
    iter[0] = xi;
    while(((667.38 / iter[i])*(1 - exp(-0.146843 * iter[i])) - 40) > es){
        if(i > imax){
            cout << "ERRO" << endl;
        }
        iter[i + 1] = iter[i] - ((667.38 / iter[i])*(1 - exp(-0.146843 * iter[i])) - 40)/((exp(-0.146843 * iter[i])*(98.0001 * iter[i] - (667.38 * exp(0.146843 * iter[i])) + 667.38)) / (iter[i] * iter[i]));
        i++;
        file << "i = " << i << ", Xr = " << iter[i] << endl;
    }
    file.close();
    xr = iter[i];
    
    return xr;
};

float funcao_f::secante(float xi, float es, int imax) {
    float xr, iter[imax] ;
    int  i = 0;
    ofstream file;
    file.open("saida.txt", ofstream::app);
    file << "F -> Secante: " << endl;
    iter[0] = xi;
    while(((667.38 / iter[i])*(1 - exp(-0.146843 * iter[i])) - 40) > es){
        if(i > imax){
            cout << "ERRO" << endl;
        }
        iter[i + 1] = iter[i] - (((667.38 / iter[i])*(1 - exp(-0.146843 * iter[i])) - 40)*(iter[i] - iter[i+1]))/((((667.38 / iter[i])*(1 - exp(-0.146843 * iter[i])) - 40)) - ((667.38 / iter[i + 1])*(1 - exp(-0.146843 * iter[i + 1])) - 40));
        i++;
        file << "i = " << i << ", Xr = " << iter[i] << endl;
    }
    file.close();
    xr = iter[i];
    
    return xr;
};

funcao_f::funcao_f(const funcao_f& orig) {
}

funcao_f::~funcao_f() {
}

