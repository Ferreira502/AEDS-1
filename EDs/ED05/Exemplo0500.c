/*
 Exemplo0300 - v0.0. - 14 / 03 / 2025
 Author: Gabriel Ferreira Pereira
*/

// dependencias
#include "io.h" // para definicoes proprias
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

/** 
   Method_01a - Mostrar certa quantidade de valores. 
   @param x - quantidade de valores a serem mostrados 
 */ 
void method_01a ( int x ) 
{ 
 // definir dado local 
    int y = 1;  // controle 
 
 // repetir enquanto controle menor que a quantidade desejada 
    while ( y <= x ) 
    { 
     // mostrar valor 
        IO_printf ( "%s%d\n", "Valor = ", y ); 
     // passar ao proximo 
        y = y + 1; 
    } // end if 
} // end method_01a( ) 
 
/** 
   Method_01 - Mostrar certa quantidade de valores. 
            OBS.:   Preparacao e disparo de outro metodo. 
 */ 
void method_01 ( ) 
{ 
 // identificar 
    IO_id ( " Method_01 - v0.0" ); 
 
 // executar o metodo auxiliar 
    method_01a ( 5 ); 
 
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" ); 
} // end method_01 ( ) 

 
/** 
   Method_02a - Mostrar certa quantidade de valores pares. 
   @param x - quantidade de valores a serem mostrados 
 */ 
void method_02a ( int x ) 
{ 
 // definir dado local 
    int y = 1;  // controle 
    int z = 2; 
 
 // repetir enquanto controle menor que a quantidade desejada 
    while ( y <= x ) 
    { 
     // mostrar valor 
        IO_printf ( "%d: %d\n", y, z ); 
     // passar ao proximo par 
        z = z + 2; 
     // passar ao proximo valor controlado 
        y = y + 1; 
    } // end while 
} // end method_02a( ) 
 
/** 
   Method_02. 
 */ 
void method_02 ( ) 
{ 
 // identificar 
    IO_id ( "Method_02 - v0.0" ); 
 
 // executar o metodo auxiliar 
    method_02a ( 5 ); 
 
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" ); 
} // end method_02 ( ) 

/** 
   Method_03a - Mostrar certa quantidade de valores pares. 
   @param x - quantidade de valores a serem mostrados 
 */ 
void method_03a ( int x ) 
{ 
 // definir dado local 
    int y = 1;  // controle 
    int z = 0; 
 
 // repetir enquanto controle menor que a quantidade desejada 
    while ( y <= x ) 
    { 
     // vincular o valor a ser mostrado ao controle 
        z = 2 * y; 
     // mostrar valor 
        IO_printf ( "%d: %d\n", y, z ); 
     // passar ao proximo valor controlado 
        y = y + 1; 
    } // end while 
} // end method_03a( )

/** 
   Method_03. 
 */ 
void method_03 ( ) 
{ 
 // identificar 
    IO_id ( " Method_03 - v0.0" ); 
 
 // executar o metodo auxiliar 
    method_03a ( 5 ); 
 
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" ); 
} // end method_03 ( )


/** 
   Method_04a - Mostrar certa quantidade de valores pares. 
   @param x - quantidade de valores a serem mostrados 
 */ 
void method_04a ( int x ) 
{ 
 // definir dado local 
    int y = x;  // controle 
    int z = 0; 
 
 // repetir enquanto controle menor que a quantidade desejada 
    while ( y > 0 ) 
    { 
     // vincular o valor a ser mostrado ao controle 
        z = 2 * y; 
     // mostrar valor 
        IO_printf ( "%d: %d\n", y, z ); 
     // passar ao proximo valor controlado 
        y = y - 1; 
    } // end while 
} // end method_04a( ) 

/** 
   Method_04. 
 */ 
void method_04 ( ) 
{ 
 // identificar 
    IO_id ( "Method_04 - v0.0" ); 
 
 // executar o metodo auxiliar 
    method_04a ( 5 ); 
 
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" ); 
} // end method_04 ( ) 

/** 
   Method_05a - Mostrar certa quantidade de valores pares. 
   @param x - quantidade de valores a serem mostrados 
 */ 
void method_05a ( int x ) 
{ 
 // definir dado local 
    int y = 0;  // controle 
 
 // repetir enquanto controle menor que a quantidade desejada 
    for ( y = x; y > 0; y = y-1 ) 
    { 
     // mostrar valor 
        IO_printf ( "%d: %d\n", y, (2*y) ); 
    } // end for 
} // end method_05a( )

/** 
   Method_05. 
 */ 
void method_05 ( ) 
{ 
 // identificar 
    IO_id ( "Method_05 - v0.0" ); 
 
 // executar o metodo auxiliar 
    method_05a ( 5 ); 
 
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" ); 
} // end method_05 ( ) 
 
/** 
   somarValores - funcao para somar certa quantidade de pares. 
   @return soma dos valores 
   @param x - quantidade de valores a serem mostrados 
 */ 
int somarValores ( int x ) 
{ 
 // definir dados locais 
    int soma = 1; 
    int y        = 0;  // controle 
 
 // repetir enquanto controle menor que a quantidade desejada 
    for ( y = 1; y <= (x-1); y = y+1 ) 
    { 
     // mostrar valor 
        IO_printf ( "%d: %d\n", y, (2*y) ); 
     // somar valor 
        soma = soma + (2*y); 
    } // end for 
 // retornar resultado 
    return ( soma ); 
} // end somarValores ( ) 
 
/** 
   Method_06. 
 */ 
void method_06 ( ) 
{ 
 // definir dado 
    int soma = 0; 
 
 // identificar 
    IO_id ( "Method_06 - v0.0" ); 
 
 // chamar e receber resultado da funcao 
    soma = somarValores ( 5 ); 
  
 // mostrar resultado 
    IO_printf ( "soma de pares = %d\n", soma ); 
 
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" ); 
} // end method_06 ( )

/** 
   somarFracao1 - funcao para somar certa quantidade de fracoes. 
   @return soma dos valores 
   @param x - quantidade de valores a serem mostrados 
 */ 
double somarFracao1 ( int x ) 
{ 
 // definir dados locais 
    double soma              = 1.0; 
    double numerador     = 0.0; 
    double denominador = 0.0; 
    int y                             =  0  ;  // controle 
 
 // repetir enquanto controle menor que a quantidade desejada 
    for ( y = 1; y <= (x-1); y = y+1 ) 
    { 
     // calcular numerador 
        numerador     = 1.0; 
     // calcular denominador 
        denominador = 2.0*y; 
     // mostrar valor 
        IO_printf ( "%d: %7.4lf/%7.4lf = %lf\n", 
                          y, numerador, denominador, (numerador/denominador) ); 
     // somar valor 
        soma = soma + (1.0)/(2.0*y); 
    } // end for 
 // retornar resultado 
    return ( soma ); 
} // end somarFracao1 ( ) 
 
/** 
   Method_07. 
 */ 
void method_07 ( ) 
{ 
 // definir dado 
    double soma = 0.0; 
 
 // identificar 
    IO_id ( "Method_07 - v0.0" ); 
 
 // chamar e receber resultado da funcao 
    soma = somarFracao1 ( 5 ); 
 
 // mostrar resultado 
    IO_printf ( "soma de fracoes = %lf\n", soma ); 
 
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" ); 
} // end method_07 ( )

/** 
   somarFracao2 - funcao para somar certa quantidade de fracoes. 
   @return soma dos valores 
   @param x - quantidade de valores a serem mostrados 
 */ 
double somarFracao2 ( int x ) 
{ 
 // definir dados locais 
    double soma              = 1.0; 
    double numerador     = 0.0; 
    double denominador = 0.0; 
    int y                             =  0  ;  // controle 
 
 // mostrar primeiro valor 
    IO_printf ( "%d: %7.4lf/%7.4lf\n", 1, 1.0, soma ); 
 
 // repetir enquanto controle menor que a quantidade desejada 
    for ( y = 1; y <= (x-1); y = y+1 ) 
    { 
     // calcular numerador 
        numerador     = 2.0*y-1; 
     // calcular denominador 
        denominador = 2.0*y; 
     // mostrar valor 
        IO_printf ( "%d: %7.4lf/%7.4lf = %lf\n", 
                            y+1, numerador, denominador, (numerador/denominador) ); 
     // somar valor 
        soma = soma + numerador / denominador; 
    } // end for 
 // retornar resultado 
    return ( soma ); 
} // end somarFracao2 ( ) 
 
/** 
   Method_08. 
 */ 
void method_08 ( ) 
{ 
 // definir dado 
    double soma = 0.0; 
 
 // identificar 
    IO_id ( "Method_08 - v0.0" ); 
 
 // chamar e receber resultado da funcao 
    soma = somarFracao2 ( 5 ); 
 
 // mostrar resultado 
    IO_printf ( "soma de fracoes = %lf\n", soma ); 
 
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" ); 
} // end method_08 ( )

/** 
   somarFracao3 - funcao para somar certa quantidade de fracoes. 
   @return soma dos valores 
   @param x - quantidade de valores a serem mostrados 
 */ 
double somarFracao3 ( int x ) 
{ 
 // definir dados locais 
    double soma = 1.0; 
    int y                =  0  ;   // controle 
 
 // mostrar primeiro valor 
    IO_printf ( "%d: %7.4lf/%7.4lf\n", 1, 1.0, soma ); 
 
 // repetir enquanto controle menor que a quantidade desejada 
    for ( y = 1; y < x; y = y+1 ) 
    { 
     // mostrar valor 
        IO_printf ( "%d: %7.4lf/%7.4lf = %7.4lf\n", 
                            y+1, (2.0*y), (2.0*y+1), ((2.0*y)/(2.0*y+1)) ); 
     // somar valor 
        soma = soma + (2.0*y)/(2.0*y+1); 
    } // end for 
 // retornar resultado 
    return ( soma ); 
} // end somarFracao3 ( ) 

/** 
   Method_09. 
 */ 
void method_09 ( ) 
{ 
 // definir dado 
    double soma = 0.0; 
 
 // identificar 
    IO_id ( "EXEMPLO0509 - Method_09 - v0.0" ); 
 
 // chamar e receber resultado da funcao 
    soma = somarFracao3 ( 5 ); 
 
 // mostrar resultado 
    IO_printf ( "soma de fracoes = %lf\n", soma ); 
 
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" ); 
} // end method_09 ( )

/** 
   multiplicarValores - funcao para multiplicar certa quantidade de valores impares. 
   @return produto de valores 
   @param x - quantidade de valores 
 */ 
int multiplicarValores ( int x ) 
{ 
 // definir dados locais 
    int produto = 1; 
    int y             = 0;  // controle 
 
 // repetir enquanto controle menor que a quantidade desejada 
    for ( y = 1; y <= x; y = y+1 ) 
    { 
     // mostrar valor 
        IO_printf ( "%d: %d\n", y, (2*y-1) ); 
     // calcular o produto 
        produto = produto * (2*y-1); 
    } // end for 
 // retornar resultado 
    return ( produto ); 
} // end multiplicarValores ( ) 
 
/** 
   Method_10. 
 */ 
void method_10 ( ) 
{ 
 // identificar 
    IO_id ( "Method_10 - v0.0" ); 
 
 // mostrar produto de valores 
    IO_printf ( "%s%d\n", "produto = ", multiplicarValores ( 5 )  ); 
 
 // encerrar 
    IO_pause ( "Apertar ENTER para continuar" ); 
} // end method_10 ( ) 

/**
/* 
---------------------------------------------- documentacao complementar 
 
---------------------------------------------- notas / observacoes / comentarios 
 
---------------------------------------------- previsao de testes 
 
a.) 5 -> { 1, 2, 3, 4, 5 } 
 
---------------------------------------------- historico 
 
Versao Data      Modificacao 
  0.1 __/__      esboco 
 
 ---------------------------------------------- testes 
 
Versao Teste 
  0.1 01. ( OK )  identificacao de programa 
 
*/ 