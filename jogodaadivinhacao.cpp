#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(){
    cout << "*******************************************" << endl;
    cout << "*****Bem vindos ao jogo da adivinhação*****" << endl;
    cout << "*******************************************" << endl;

    cout << "Escolha o seu nível de dificuldade" << endl;
    cout << "Fácil (F), Médio (M), Difícil (D): ";
    char dificuldade;
    cin >> dificuldade;
    int numero_de_tentativa;
    if(dificuldade == 'F'){
        numero_de_tentativa = 15;
    }
    else if(dificuldade == 'M'){
        numero_de_tentativa = 10;
    }
    else{
        numero_de_tentativa = 5;
    }

    srand(time(NULL));
    const int NUMERO_SECRETO = rand() % 100;
    bool nao_acertou = true;
    int tentativas = 0;
    double pontos = 1000.0;

    for(tentativas = 1; tentativas <= numero_de_tentativa; tentativas++){
        int chute;
        cout << "Tentativa "<< tentativas << endl;
        cout << "Qual o valor do seu chute? ";
        cin >> chute;

        double pontos_perdidos = abs((chute - NUMERO_SECRETO) / 2.0);
        pontos = pontos - pontos_perdidos;

        cout << "O valor do seu chute é: " << chute << endl;


        bool acertou = chute == NUMERO_SECRETO;
        bool maior = chute > NUMERO_SECRETO;


        if(acertou){
            cout << "Parabéns! você acertou o numero secreto!" << endl;
            nao_acertou = false;
            break;
        }
        else if(maior){
            cout << "O seu chute é maior que o numero secreto" << endl;
        }
        else{
            cout << "O seu chute é menor que o numero secreto" << endl;
        }
    }
    cout << "Fim de jogo!" << endl;
    if(nao_acertou){
        cout << "Você perdeu! Tente novamente!" << endl;
    }
    else{
        cout << "Você acertou o numero secreto em " << tentativas << " tentativas" << endl;
        cout.precision(2);
        cout << fixed;
        cout << "Sua pontuação foi de: " << pontos << endl;
    }
}
