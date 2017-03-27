/*
 * Este sotfware foi feito para a UTFPR - Campus Curitiba;
 * O Código é livre para uso não comercial;
 * Desenvolvido através do Netbeans IDE.
 */

/* 
 * File:   funcao_f.h
 * Author: Marlon Prudente <marlonoliveira@alunos.utfpr.edu.br>
 *
 * Created on March 23, 2017, 5:57 PM
 */

#ifndef FUNCAO_F_H
#define FUNCAO_F_H

class funcao_f {
public:
    funcao_f();
    float valor_y(float x);
    float derivada(float x);
    float bisseccao(float xl, float xu, float es, int imax);
    float falsa_posicao(float xl, float xu, float es, int imax);
    float newton_raphson(float xi, float es, int imax);
    float secante(float xi, float es, int imax);
    funcao_f(const funcao_f& orig);
    virtual ~funcao_f();
private:

};

#endif /* FUNCAO_F_H */

