#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <time.h>

int main() {
        setlocale(LC_ALL, "Portuguese");

        // IMPRIME O CABEÇALHO DO NOSSO JOGO

        printf ("******************************************\n");
        printf ("**Bem vindo ao nosso jogo de adivinhação**\n");
        printf ("******************************************\n");

        // VARIÁVEIS
        
        srand (time(0));
        int numerosecreto = rand() % 100;
        
        int chute;
        int acertou = 0; 
        int tentativas = 1;
        double pontos = 1000;
        int nivel;
        int numtentativas;
          printf ("Em qual nível você quer jogar?\n");
          printf ("Digite:\n");
          printf ("- 1 para Fácil\n");
          printf ("- 2 para Normal\n");
          printf ("- 3 para Difícil\n");
          scanf ("%d", &nivel);

        switch (nivel) {
          case 1:
            numtentativas = 10;
            break;
            
          case 2: 
            numtentativas = 5;
            break;
            
          default:
            numtentativas = 3;
            break; 
      
        }
        for (int i = 1; i <= numtentativas; i++) {
              printf ("Qual é o seu %d° chute? ", tentativas++);
              scanf ("%d", &chute);
              printf ("\n");
               
               if (chute < 0) {
                 printf ("Ops! Números negativos não, kirido(a)!\n");
                 printf ("Tente novamente.\n");
                
                continue; 
                
               }

               if (chute == numerosecreto) {
                       printf ("Parabéns, você acertou!\n");
                       printf ("Jogue de novo! Você é um(a) ótimo(a) jogador(a)!\n");
                       
                       break;              
        }
               else {
                  
                       if (chute > numerosecreto) {
                               printf ("Que pena, você errou...\n");
                               printf ("Seu chute foi maior que o número secreto.\n\n");      
            }
                       else {
                               printf ("Que pena, você errou...\n");
                               printf ("Seu chute foi menor que o número secreto.\n\n");            
            } 
                     
        } 
        
         double pontosperdidos = abs(chute - numerosecreto) / 2.0;
         pontos = pontos - pontosperdidos;  
    }
       printf ("Sua pontuação final foi: %.1f\n", pontos);
}