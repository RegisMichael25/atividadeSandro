#include <iostream>  
using namespace std;

// Função que faz o calculo da media das notas
float calcularMedia(float notas[], int total) {
    float soma = 0;
    for (int i = 0; i < total; i++) {
        soma += notas[i];
    }
    return soma / total;
}

// essa função ordena as notas
void ordenar(float notas[], int total) {
    for (int i = 0; i < total - 1; i++) {
        for (int j = 0; j < total - 1 - i; j++) {
            if (notas[j] > notas[j + 1]) {
                float temp = notas[j];
                notas[j] = notas[j + 1];
                notas[j + 1] = temp;
            }
        }
    }
}

// Essa função faz o calculo da mediana com uma condição 
float calcularMediana(float notas[], int total) {
    ordenar(notas, total);  // Ordena antes de calcular
    if (total % 2 == 0) {
        return (notas[total / 2 - 1] + notas[total / 2]) / 2;
    } else {
        return notas[total / 2];
    }
}

// Função que calcula o desvio padrão(pesquisado)
float calcularDesvioPadrao(float notas[], int total, float media) {
    float soma = 0;
    for (int i = 0; i < total; i++) {
        float diferenca = notas[i] - media;
        soma += diferenca * diferenca;  // Quadrado da diferença
    }
    // Raiz quadrada a mão(pesquisada)
    float variancia = soma / total;
    float raiz = variancia;
    for (int i = 0; i < 10; i++) {
        raiz = 0.5 * (raiz + variancia / raiz);
    }
    return raiz;
}

int main() {
    float notas[100];  // Array quearmazena até 100 notas
    int totalNotas = 0;
    int tentativasExtras = 0;

    float nota1, nota2;
    cout << "Informe a primeira nota do aluno: ";
    cin >> nota1;
    cout << "Agora digite a segunda nota: ";
    cin >> nota2;

    notas[totalNotas++] = nota1;
    notas[totalNotas++] = nota2;

    float mediaFinal = (nota1 + nota2) / 2;

    while (mediaFinal < 6.0) {
        float novaNota;
        cout << "\nMédia atual: " << mediaFinal << "\n";
        cout << "Digite uma nova nota para substituir sua menor nota: ";
        cin >> novaNota;

        notas[totalNotas++] = novaNota;
        tentativasExtras++;

        // Substitui a menor nota entre as duas
        if (nota1 < nota2) {
            nota1 = novaNota;
        } else {
            nota2 = novaNota;
        }

        mediaFinal = (nota1 + nota2) / 2;
    }

    // Mostra a média final e o total de tentativas do aluno
    cout << "\nA média final alcançada foi: " << mediaFinal << endl;
    cout << "Tentativas extras: " << tentativasExtras << endl;

    // Mostrar o histórico de notas do aluno
    cout << "\n Histórico das notas do aluno:\n";
    for (int i = 0; i < totalNotas; i++) {
        cout << notas[i] << " ";
    }
    cout << endl;

    // Calcular e mostrar todas as estatísticas 
    float mediaGeral = calcularMedia(notas, totalNotas);
    float mediana = calcularMediana(notas, totalNotas);
    float desvio = calcularDesvioPadrao(notas, totalNotas, mediaGeral);

    cout << "\nEstatísticas:\n";
    cout << "Média geral: " << mediaGeral << endl;
    cout << "Mediana: " << mediana << endl;
    cout << "Desvio padrão: " << desvio << endl;

    return 0;
}

