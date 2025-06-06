/* 
   Exemplo1300 - v0.0. - 05 / 06 / 2025 
   Author: Gabriel Ferreira Pereira
 
 */ 
 
// ----------------------------------------------- classes 
 
#include "Contato.hpp"  // classe para tratar dados de pessoas 
 
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
    Contato pessoa1;
    Contato* pessoa3 = new Contato();
 
 // identificar 
    cout << "\nMethod_01 - v0.0\n" << endl; 
    cout << "Objetos pessoa1 e pessoa3 criados" << endl;

    delete pessoa3;
 
 // encerrar 
    pause ( "Apertar ENTER para continuar" ); 
} // end method_01 ( ) 

/** 
   Method_02 - Testar atribuicoes. 
 */ 
void method_02 ( ) 
{ 
 // definir dados 
    Contato pessoa1;
    Contato* pessoa3 = new Contato();
 
 // identificar 
    cout << "\nMethod_02 - v0.0\n" << endl; 
 
 // testar atribuicoes 
     pessoa1.setNome("Pessoa_01");
    pessoa1.setFone("111", 0);
    pessoa3->setNome("Pessoa_03");
    pessoa3->setFone("333", 0);

    cout << "pessoa1 - { " << pessoa1.getNome() << ", " << pessoa1.getFone(0) << " }" << endl;
    cout << "pessoa3 - { " << pessoa3->getNome() << ", " << pessoa3->getFone(0) << " }" << endl;

    delete pessoa3;
 
 // encerrar 
    pause ( "Apertar ENTER para continuar" ); 
} // end method_02 ( ) 

/** 
   Method_03 - Testar recuperacao de dados. 
 */ 
void method_03 ( ) 
{ 
 // definir dados 
    Contato pessoa1;
    Contato* pessoa3 = new Contato();
 
 // identificar 
    cout << "\nMethod_03 - v0.0\n" << endl; 
 
 // testar atribuicoes 
    pessoa1.setNome("Pessoa_01");
    pessoa1.setFone("111", 0);
    pessoa3->setNome("Pessoa_03");
    pessoa3->setFone("333", 0);

    cout << "pessoa1 - " << pessoa1.toString() << endl;
    cout << "pessoa3 - " << pessoa3->toString() << endl;

    delete pessoa3;
 
 // encerrar 
    pause ( "Apertar ENTER para continuar" ); 
} // end method_03 ( )

/** 
   Method_04 - Testar construtor alternativo. 
 */ 
void method_04 ( ) 
{ 
 // definir dados 
    Contato pessoa1("Pessoa_01", "111");
    Contato* pessoa3 = new Contato("Pessoa_03", "333");
 
 // identificar 
    cout << "\nMethod_04 - v0.0\n" << endl; 
 
 // testar atribuicoes 
 
    cout << "pessoa1 - " << pessoa1.toString() << endl;
    cout << "pessoa3 - " << pessoa3->toString() << endl;

    delete pessoa3;
 
 // encerrar 
    pause ( "Apertar ENTER para continuar" ); 
} // end method_04 ( )

// ----------------------------------------------- acao principal 
 
/* 
  Funcao principal. 
  @return codigo de encerramento 
*/ 
int main ( int argc, char** argv ) 
{ 
 // definir dado 
    int x = 0;                // definir variavel com valor inicial 
 
 // repetir até desejar parar 
    do 
    { 
     // identificar 
        cout << "EXEMPLO1300 - Programa - v0.0\n            " << endl; 
 
     // mostrar opcoes 
        cout << "Opcoes                                                          " << endl; 
        cout << " 0 - parar                                                        " << endl; 
        cout << " 1 - testar definicao de contatos (objetos) " << endl;
        cout << " 2 - Testar atribuicoes "                     << endl;
        cout << " 3 - Testar recuperacao de dados "            << endl;
        cout << " 4 - Testar construtor alternativo "          << endl;

 
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
           case 2: 
            method_02 ( ); 
           break; 
           case 3: 
            method_03 ( ); 
           break; 
           case 4: 
            method_04 ( ); 
           break; 
          default: 
            cout << endl << "ERRO: Valor invalido." << endl; 
        } // end switch 
    } 
    while ( x != 0 ); 
 
 // encerrar 
    pause  ( "Apertar ENTER para terminar" ); 
    return ( 0 ); 
} // end main ( ) 