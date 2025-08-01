/* 
   Exemplo1600 - v0.0. - 23 / 06 / 2025 
   Author: Gabriel Ferreira Pereira
 
 */ 
 
// ----------------------------------------------- preparacao 
 
// dependências 
 
#include <iostream> 
 
// ----------------------------------------------- definicoes globais 
 
using namespace std; 
 
// ----------------------------------------------- metodos 
 
/** 
   Method_00 - nao faz nada. 
 */ 
void method_00 ( ) 
{ 
 // nao faz nada 
} // end method_00 ( ) 
 
/** 
   Method_01 - Testar definicoes da classe. 
 */ 
void method_01 ( ) 
{ 
 // definir dados 
 
 // identificar 
    cout << "\nMethod_01 - v0.0\n" << endl; 
 
 // encerrar 
    cout << "Apertar ENTER para continuar" << endl;
} // end method_01 ( ) 
 
// ----------------------------------------------- acao principal 
 
/* 
  Funcao principal. 
  @return codigo de encerramento 
*/ 
int main ( int argc, char** argv ) 
{ 
 // definir dado 
    int x = 0;  // definir variavel com valor inicial 
 
 // repetir até desejar parar 
    do 
    { 
     // identificar 
        cout << "EXEMPLO1600 - Programa - v0.0\n " << endl; 
 
     // mostrar opcoes 
        cout << "Opcoes     " << endl; 
        cout << " 0 - parar    " << endl; 
        cout << " 1 - testar definicoes  " << endl; 
 
     // ler do teclado 
        cout << endl << "Entrar com uma opcao: "; 
        cin  >> x; 
 
     // escolher acao 
        switch ( x ) 
        { 
          case 0: 
            method_00 ( ); 
           break; 
          case 1: 
            method_01 ( ); 
           break; 
          default: 
            cout << endl << "ERRO: Valor invalido." << endl; 
        } // end switch 
    } 
    while ( x != 0 ); 
 
 // encerrar 
    cout << "Apertar ENTER para terminar" << endl;
    return ( 0 ); 
} // end main ( )

 /* 
---------------------------------------------- documentacao complementar 
 
---------------------------------------------- notas / observacoes / comentarios 
 
---------------------------------------------- previsao de testes 
 
---------------------------------------------- historico 
 
Versao Data   Modificacao 
  0.1 __/__   esboco 
 
 ---------------------------------------------- testes 
 
Versao Teste 
  0.1 01. ( OK )    identificacao de programa 
 
*/ 
