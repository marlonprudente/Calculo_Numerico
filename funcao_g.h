/*
 * Este sotfware foi feito para a UTFPR - Campus Curitiba;
 * O Código é livre para uso não comercial;
 * Desenvolvido através do Netbeans IDE.
 */

/* 
 * File:   funcao_g.h
 * Author: Marlon Prudente <marlonoliveira@alunos.utfpr.edu.br>
 *
 * Created on March 23, 2017, 5:58 PM
 */

#ifndef FUNCAO_G_H
#define FUNCAO_G_H

class funcao_g {
public:
    funcao_g();
    float valor_y(float x);
    float derivada(float x);
    float bisseccao(float xl, float xu, float es, int imax);
    float falsa_posicao(float xl, float xu, float es, int imax);
    float newton_raphson(float xi, float es, int imax);
    float secante(float xi, float es, int imax);
    funcao_g(const funcao_g& orig);
    virtual ~funcao_g();
private:

};

#endif /* FUNCAO_G_H */

