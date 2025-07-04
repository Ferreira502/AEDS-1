/*
 Exercicio14 - v0.0. - 13 / 05 / 2025
 Author: Gabriel Ferreira Pereira

 Para compilar em terminal (janela de comandos):
 Linux : g++ -o exercicio14 exercicio14.cpp
 Windows: g++ -o exercicio14 exercicio14.cpp

 Para executar em terminal (janela de comandos):
 Linux : ./exercicio14
 Windows: exercicio14
*/

#include <iostream>
#include <limits>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <string>
#include <sstream>
 
using namespace std; 

// -------------------------- definicao de metodos

class MeuObjeto 
{
private:
    string conteudo;

public:
    MeuObjeto(const string& valor) : conteudo(valor) {}

  int getInt() 
   {
       int resultado = 0;
       bool negativo = false;
       int i = 0;

       if (conteudo.empty()) 
       {
           return -1;
       }

       if (conteudo[0] == '-') 
       {
           negativo = true;
           i = 1;
       }

       while (i < conteudo.length())
       {
           char c = conteudo[i];
           if (c >= '0' && c <= '9') 
           {
               resultado = resultado * 10 + (c - '0');
           } 
           else 
           {
               return -1;
           }
           i++;
       }
        
       if (negativo) 
       {
           resultado = -resultado;
       }

       return resultado;
   }

   void setConteudo(const string& novoConteudo) 
   {
       conteudo = novoConteudo;
  }

  
  double getDouble() 
  {
    if (conteudo.empty()) 
    {
        return 0.0;
    }

    double resultado = 0.0;
    bool negativo = false;
    bool decimal = false;
    double divisorDecimal = 10.0;

    int i = 0;
    if (conteudo[0] == '-') 
    {
        negativo = true;
        i = 1;
    }

    bool temDigitos = false;

    while (i < conteudo.length())
    {
        char c = conteudo[i];

        if (c == '.') {
            if (decimal) 
            {
                return 0.0;
            }
            decimal = true;
        }

        else if (c >= '0' && c <= '9') 
        {
            temDigitos = true;
            if (!decimal) 
            {
                resultado = resultado * 10 + (c - '0');
            } else 
            {
                resultado = resultado + (c - '0') / divisorDecimal;
                divisorDecimal *= 10.0;
            }
        }
        else 
        {
            return 0.0;
        }
        
        i++;
    }

    if (!temDigitos) 
    {
        return 0.0;
    }

    if (negativo) 
    {
        resultado = -resultado;
    }

    return resultado;
  }
  
  bool getBoolean() 
  {
    string texto = "";
    int i = 0;

    while (i < conteudo.length()) 
    {
        char c = conteudo[i];

        if (c >= 'A' && c <= 'Z') 
        {
            texto += c + 32; 
        } else 
        {
            texto += c;
        }

        i++;
    }

    if (texto == "true" || texto == "t" || texto == "1") 
    {
        return true;

    } 
    else if (texto == "false" || texto == "f" || texto == "0") 
    {
        return false;
    }

    return false;
   }

   bool contains(string subtexto) 
   {
        int tamanhoConteudo = conteudo.length();
        int tamanhoSubtexto = subtexto.length();

        if (tamanhoSubtexto > tamanhoConteudo || tamanhoSubtexto == 0) 
        {
            return false;
        }

        for (int i = 0; i <= tamanhoConteudo - tamanhoSubtexto; i++) 
        {
            int j = 0;
            while (j < tamanhoSubtexto && conteudo[i + j] == subtexto[j]) 
            {
                j++;
            }

            if (j == tamanhoSubtexto) 
            {
                return true;
            }
        }   

        return false;
    
    }

    string toUpperCase() 
    {
        string resultado = "";

        for (int i = 0; i < conteudo.length(); i++) 
        {
            char c = conteudo[i];

            if (c >= 'a' && c <= 'z') 
            {
                resultado += c - 32;
            } 
            else 
            {
                resultado += c;
            }
        }

        return resultado;
    }


    string toLowerCase() 
    {
        string resultado = "";

        for (int i = 0; i < conteudo.length(); i++) 
        {
            char c = conteudo[i];

            if (c >= 'A' && c <= 'Z') 
            {
                resultado += c + 32;
            } 
            else 
            {
                resultado += c;
            }   
        }

        return resultado;
    }
    string replace(char original, char novo) 
    {
        string resultado = "";

        for (int i = 0; i < conteudo.length(); i++) 
        {
            if (conteudo[i] == original) 
            {
                resultado += novo;
            } else 
            {
                resultado += conteudo[i];
            }
        }

        return resultado;
    }

    string encrypt() 
    {
        string resultado = "";
        int deslocamento = 3;

        for (int i = 0; i < conteudo.length(); i++) 
        {
            char c = conteudo[i];

        
            if (c >= 'A' && c <= 'Z') 
            {
                char codificado = ((c - 'A' + deslocamento) % 26) + 'A';
                resultado += codificado;
            }

            else if (c >= 'a' && c <= 'z') 
            {
                char codificado = ((c - 'a' + deslocamento) % 26) + 'a';
                resultado += codificado;
            }

            else 
            {
                resultado += c;
            }
        }

        return resultado;
    }

    string decrypt() 
    {
        string resultado = "";
        int deslocamento = 3;

        for (int i = 0; i < conteudo.length(); i++) 
        {
            char c = conteudo[i];

            if (c >= 'A' && c <= 'Z') 
            {
                char decodificado = ((c - 'A' - deslocamento + 26) % 26) + 'A';
                resultado += decodificado;
            }
            else if (c >= 'a' && c <= 'z') 
            {
                char decodificado = ((c - 'a' - deslocamento + 26) % 26) + 'a';
                resultado += decodificado;
            }
            
            else 
            {
                resultado += c;
            }
        }

        return resultado;
    }

    int split(string sequencia[]) 
    {
        int quantidade = 0;
        string palavra = "";
    
        for (int i = 0; i <= conteudo.length(); i++) 
        {
            char c = conteudo[i];

            if (c == ' ' || c == '\0') 
            {
                if (palavra != "") 
                {
                    sequencia[quantidade] = palavra;
                    quantidade++;
                    palavra = "";
                }
            } 
            else 
            {
                palavra += c;
            }
        }

        return quantidade;
    }

    int splitBy(char delimitador, string sequencia[]) 
    {
        int quantidade = 0;
        string palavra = "";

        for (int i = 0; i <= conteudo.length(); i++) 
        {
            char c = conteudo[i];

            if (c == delimitador || c == '\0') 
            {
                if (palavra != "") 
                {
                    sequencia[quantidade] = palavra;
                    quantidade++;
                    palavra = "";
                }
            } 
            else 
            {
                palavra += c;
            }
        }

        return quantidade;
    }


    string reverse() 
    {
        string invertido = "";

        for (int i = conteudo.length() - 1; i >= 0; i--) 
        {
            invertido += conteudo[i];
        }

        return invertido;
}

};

// --------------- METODO01-----------------

/**  
     Funcao para converter conteudo do objeto para valor inteiro com sinal, se possivel. 
     @return valor inteiro equivalente, se valido; 
                   (-1), caso contrario 
  */

void metodo01() 
{
    cout << "\n\tMetodo01\n";
    
    MeuObjeto obj1("123");
    MeuObjeto obj2("abc");
    MeuObjeto obj3("-45");
    MeuObjeto obj4("123abc");
    MeuObjeto obj5("-");         
    MeuObjeto obj6("");          
    MeuObjeto obj7("-0010");     

    cout << "obj1.getInt() = " << obj1.getInt() << endl; 
    cout << "obj2.getInt() = " << obj2.getInt() << endl; 
    cout << "obj3.getInt() = " << obj3.getInt() << endl; 
    cout << "obj4.getInt() = " << obj4.getInt() << endl; 
    cout << "obj5.getInt() = " << obj5.getInt() << endl; 
    cout << "obj6.getInt() = " << obj6.getInt() << endl; 
    cout << "obj7.getInt() = " << obj7.getInt() << endl; 

    getchar();
    cout << "\nApertar ENTER para continuar." << endl;
    getchar();
}

// --------------- METODO02-----------------

/**  
     Funcao para converter conteudo do objeto para valor real com sinal, se possivel. 
     @return valor real equivalente, se valido; 
                   (0.0), caso contrario 
  */

void metodo02() 
{
    cout << "\n\tMetodo02\n";

    
    MeuObjeto obj1("123.45");
    MeuObjeto obj2("-3.1415");
    MeuObjeto obj3("0.001");
    MeuObjeto obj4("abc");
    MeuObjeto obj5("12.3.4");
    MeuObjeto obj6(".5");
    MeuObjeto obj7("123."); 

    cout << "obj1.getDouble() = " << obj1.getDouble() << endl; 
    cout << "obj2.getDouble() = " << obj2.getDouble() << endl;
    cout << "obj3.getDouble() = " << obj3.getDouble() << endl; 
    cout << "obj4.getDouble() = " << obj4.getDouble() << endl; 
    cout << "obj5.getDouble() = " << obj5.getDouble() << endl; 
    cout << "obj6.getDouble() = " << obj6.getDouble() << endl;
    cout << "obj7.getDouble() = " << obj7.getDouble() << endl;
    
    getchar();
    cout << "\nApertar ENTER para continuar." << endl;
    getchar();
}


// --------------- METODO03-----------------

/**  
     Funcao para converter conteudo do objeto para valor lógico, se possivel. 
     Nota: Considerar válidos: { false, true, F, T, 0, 1 }  
     @return valor logico equivalente, se valido; 
                   false, caso contrario 
  */

void metodo03() 
{
    cout << "\n\tMetodo03\n";
    
    MeuObjeto obj1("true");
    MeuObjeto obj2("FALSE");
    MeuObjeto obj3("T");
    MeuObjeto obj4("f");
    MeuObjeto obj5("1");
    MeuObjeto obj6("0");
    MeuObjeto obj7("a");
    MeuObjeto obj8("b");

    cout << "obj1.getBoolean() = " << obj1.getBoolean() << endl; 
    cout << "obj2.getBoolean() = " << obj2.getBoolean() << endl; 
    cout << "obj3.getBoolean() = " << obj3.getBoolean() << endl;
    cout << "obj4.getBoolean() = " << obj4.getBoolean() << endl; 
    cout << "obj5.getBoolean() = " << obj5.getBoolean() << endl;
    cout << "obj6.getBoolean() = " << obj6.getBoolean() << endl; 
    cout << "obj7.getBoolean() = " << obj7.getBoolean() << endl; 
    cout << "obj8.getBoolean() = " << obj8.getBoolean() << endl; 
    
    getchar();
    cout << "\nApertar ENTER para continuar." << endl;
    getchar();
}


// --------------- METODO04-----------------

/**  
     Funcao para verificar se o parametro (subtexto) esta’ contido no conteudo. 
     @return true , se contiver (a partir de qualquer posicao); 
                   false, caso contrario 
  */

void metodo04() 
{
    cout << "\n\tMetodo04\n";
    MeuObjeto obj("exemplo de texto");

    cout << "Contem 'de': " << obj.contains("de") << endl;       
    cout << "Contem 'texto': " << obj.contains("texto") << endl; 
    cout << "Contem 'Texto': " << obj.contains("Texto") << endl;
    cout << "Contem 'x': " << obj.contains("x") << endl;         
    cout << "Contem 'abc': " << obj.contains("abc") << endl;     

    getchar();
    cout << "\nApertar ENTER para continuar." << endl;
    getchar();
}


// --------------- METODO05-----------------

/**  
     Funcao para converter letras para maiusculas. 
     @return valor equivalente em maiusculas, se houver; 
                   o proprio valor, caso contrario 
  */

void metodo05() 
{
    cout << "\n\tMetodo05\n";
     MeuObjeto obj1("abc123");
    MeuObjeto obj2("Teste De CAso");
    MeuObjeto obj3("JA ESTA EM MAIUSCULAS");

    cout << "obj1.toUpperCase() = " << obj1.toUpperCase() << endl; 
    cout << "obj2.toUpperCase() = " << obj2.toUpperCase() << endl; 
    cout << "obj3.toUpperCase() = " << obj3.toUpperCase() << endl;

    getchar();
    cout << "\nApertar ENTER para continuar" << endl;
    getchar();
}

// --------------- METODO06-----------------

/**  
     Funcao para converter letras para minusculas. 
     @return valor equivalente em minusculas, se houver; 
                   o proprio valor, caso contrario 
  */ 

void metodo06() 
{
    cout << "\n\tMetodo06\n";

     MeuObjeto obj1("ABC123");
    MeuObjeto obj2("Teste De CAso");
    MeuObjeto obj3("ja esta em minusculas");

    cout << "obj1.toLowerCase() = " << obj1.toLowerCase() << endl;
    cout << "obj2.toLowerCase() = " << obj2.toLowerCase() << endl;
    cout << "obj3.toLowerCase() = " << obj3.toLowerCase() << endl;

    getchar();
    cout << "\nApertar ENTER para continuar." << endl;
    getchar();
}

// --------------- METODO07-----------------

/**  
     Funcao para trocar todas as ocorrencias de certo caractere por outro novo. 
     @return valor com substituicoes, se houver; 
                   o proprio valor, caso contrario 
  */

void metodo07() 
{
    cout << "\n\tMetodo07\n";

    MeuObjeto obj1("banana");
    MeuObjeto obj2("A casa e azul");
    MeuObjeto obj3("123-456-789");

    cout << "obj1.replace('a', 'o') = " << obj1.replace('a', 'o') << endl;
    cout << "obj2.replace('a', '*') = " << obj2.replace('a', '*') << endl;
    cout << "obj3.replace('-', '.') = " << obj3.replace('-', '.') << endl;

    getchar();
    cout << "\nApertar ENTER para continuar." << endl;
    getchar();
}

// --------------- METODO08-----------------

/**  
     Funcao para codificar o conteudo segundo a cifra de César (pesquisar). 
     @return valor equivalente codificado, se houver; 
                   o proprio valor, caso contrario 
  */ 

void metodo08() 
{
    cout << "\n\tMetodo08\n";

    MeuObjeto obj1("abc");
    MeuObjeto obj2("xyz");
    MeuObjeto obj3("Hello, World");
    MeuObjeto obj4("Segredo123");

    cout << "obj1.encrypt() = " << obj1.encrypt() << endl;
    cout << "obj2.encrypt() = " << obj2.encrypt() << endl;
    cout << "obj3.encrypt() = " << obj3.encrypt() << endl;
    cout << "obj4.encrypt() = " << obj4.encrypt() << endl;

    getchar();
    cout << "\nApertar ENTER para continuar." << endl;
    getchar();
}


// --------------- METODO09-----------------

/**  
     Funcao para decodificar o conteudo previamente cifrado pela funcao acima. 
     @return valor equivalente decodificado, se houver; 
                   o proprio valor, caso contrario 
  */

void metodo09() 
{
    cout << "\n\tMetodo09\n";

    MeuObjeto obj1("def");
    MeuObjeto obj2("abc");
    MeuObjeto obj3("Khoor, Zruog!");
    MeuObjeto obj4("Vhjuhgr123");

    cout << "obj1.decrypt() = " << obj1.decrypt() << endl;
    cout << "obj2.decrypt() = " << obj2.decrypt() << endl;
    cout << "obj3.decrypt() = " << obj3.decrypt() << endl;
    cout << "obj4.decrypt() = " << obj4.decrypt() << endl;

    getchar();
    cout << "\nApertar ENTER para continuar." << endl;
    getchar();
}

// --------------- METODO10-----------------

/**  
     Funcao para separar todas as sequencias de caracteres separadas por espaços em branco. 
     @param sequencia - arranjo para armazenar possiveis cadeias de caracteres identificadas 
     @return quantidade de sequencias de caracteres identificadas, se houver; 
                   zero, caso contrario 
  */

void metodo10() 
{
    cout << "\n\tMetodo10\n";
    
    MeuObjeto obj1("O rato roeu a roupa do rei");
    string palavras[10];

    int qtd = obj1.split(palavras);

    cout << "Quantidade de palavras: " << qtd << endl;

    for (int i = 0; i < qtd; i++) 
    {
        cout << "[" << i << "]: " << palavras[i] << endl;
    }

    getchar();
    cout << "\nApertar ENTER para continuar." << endl;
    getchar();
}


// --------------- METODO11-----------------

void metodo11() 
{
    cout << "\n\tMetodoE1\n";
    
    MeuObjeto obj1("ana,maria,joao,ze");
    string nomes[10];

    int qtd = obj1.splitBy(',', nomes);

    cout << "Fragmentos encontrados: " << qtd << endl;

    for (int i = 0; i < qtd; i++) 
    {
        cout << "[" << i << "]: " << nomes[i] << endl;
    }

    MeuObjeto obj2("10:20:30:40");
    string numeros[10];

    int qtd2 = obj2.splitBy(':', numeros);

    cout << "\nFragmentos encontrados: " << qtd2 << endl;

    for (int i = 0; i < qtd2; i++) 
    {
        cout << "[" << i << "]: " << numeros[i] << endl;
    }

    getchar();
    cout << "\nApertar ENTER para continuar." << endl;
    getchar();
}

// --------------- METODO12-----------------

void metodo12() 
{
    cout << "\n\tMetodoE2\n";

    MeuObjeto obj1("abcde");
    MeuObjeto obj2("12345");
    MeuObjeto obj3("amor");

    cout << "Original: " << "abcde" << " | Invertido: " << obj1.reverse() << endl; 
    cout << "Original: " << "12345" << " | Invertido: " << obj2.reverse() << endl; 
    cout << "Original: " << "amor" << "  | Invertido: " << obj3.reverse() << endl;

    getchar();
    cout << "\nApertar ENTER para continuar." << endl;
    getchar();
}

void menuOpcoes() {
    cout << "\nExercicio14 - v.0.0 - 13/05/2025" << endl;
    cout << "Matricula: 842527 Nome: Gabriel Ferreira Pereira" << endl;
    cout << "Opcoes: "           << endl;
    cout << " 0 - parar "        << endl;
    cout << " 1 - metodo 01 "  << endl;
    cout << " 2 - metodo 02 "  << endl;
    cout << " 3 - metodo 03 "  << endl;
    cout << " 4 - metodo 04 "  << endl;
    cout << " 5 - metodo 05 "  << endl;
    cout << " 6 - metodo 06 "  << endl;
    cout << " 7 - metodo 07 "  << endl;
    cout << " 8 - metodo 08 "  << endl;
    cout << " 9 - metodo 09 "  << endl;
    cout << "10 - metodo 10 "  << endl;
    cout << "11 - metodo E1 "  << endl;
    cout << "12 - metodo E2 "  << endl;
    cout << endl;
}

// -------------------------- definicao do metodo principal

int main() 
{
    int opcao = 0;

    do {
        menuOpcoes();
        cout << "Qual a sua opcao? ";
        cin >> opcao;
        getchar();

        cout << opcao << endl;

        switch (opcao) {
            case 0: break;
            case 1:  metodo01(); break;
            case 2:  metodo02(); break;
            case 3:  metodo03(); break;
            case 4:  metodo04(); break;
            case 5:  metodo05(); break;
            case 6:  metodo06(); break;
            case 7:  metodo07(); break;
            case 8:  metodo08(); break;
            case 9:  metodo09(); break;
            case 10: metodo10(); break;
            case 11: metodo11(); break;
            case 12: metodo12(); break;
            default: 
                cout << "\nERRO: Opcao invalida\n" << endl;
                break;
        }

    } while (opcao != 0);

    cout << "\nApertar ENTER para terminar." << endl;
    cin.get();

    return 0;
}