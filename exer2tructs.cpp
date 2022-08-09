//Em um determinado curso a nota do estudante é calculada a partir de três notas atribuídas, 
//respectivamente, a um trabalho de laboratório, a uma avaliação semestral e a um exame final. 
//As notas variam de 0 a 10 e a nota final é a média ponderada das três notas mencionadas. 
//O número máximo de alunos cadastrados será de 20 alunos. A tabela abaixo fornece os pesos:

//Laboratório peso 2
//Avaliação semestral peso 3
//Prova final peso 5

//Após calcular a nota final do aluno, verfique qual a sua classificação e imprima na tela.

//nota final classificação

//[8-10] A
//[7-7.9] B
//[6-6.9] C
//[5-5.9] D
//[0-4.9] R
//Suponha que n <= 20.

//A struct será composta por: CODIGO DO ALUNO, NOME DO ALUNO, AS 3 NOTAS, MEDIA FINAL E CLASSIFICAÇÃO.
//Construa um programa que faça a leitura do número de alunos a serem cadastrados, obedecendo o limite de 20, 
//imprima todos os alunos cadastrados com a sua nota final calculada e sua classificação.

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define LAB 2
#define SEM 3
#define FIN 5


typedef struct{
	int codigo;
	char nome[50];
	float notalab;
	float notasem;
	float notafin;
	float media;
	char classi;
} NOTASALUNOS;


void leitura(NOTASALUNOS aluno[], int numalunos){
	int i;
	for(i=0 ; i<numalunos ; i++){
		
		printf("\nAluno %d", i+1);
		printf("\nDigite o codigo do aluno: ");
		scanf("%d", &aluno[i].codigo);
		printf("\nDigite o nome do aluno: ");
		fflush(stdin);
		gets(aluno[i].nome);
		
		do{
			printf("Digite a nota do laboratorio (PESO = 2): ");
			scanf("%f", &aluno[i].notalab);
			
			if(aluno[i].notalab > LAB || aluno[i].notalab < 0)
			{
				printf("Valor invalido, por favor, tente novamente!\n");
			}
		}while(aluno[i].notalab > LAB || aluno[i].notalab < 0);
		
		do{
			printf("Digite a nota do seminario (PESO = 3): ");
			scanf("%f", &aluno[i].notasem);
			
			if(aluno[i].notasem > SEM || aluno[i].notasem < 0)
			{
				printf("Valor invalido, por favor, tente novamente!\n");
			}
		}while(aluno[i].notasem > SEM || aluno[i].notasem < 0);
		
		do{
			printf("Digite a nota da prova final (PESO = 5): ");
			scanf("%f", &aluno[i].notafin);
			
			if(aluno[i].notafin > FIN || aluno[i].notafin < 0)
			{
				printf("Valor invalido, por favor, tente novamente!\n");
			}
		}while(aluno[i].notafin > FIN || aluno[i].notafin < 0);
	}
}

void calcular(NOTASALUNOS aluno[], int numalunos){
	int i;
	for(i=0 ; i<numalunos ; i++){
		aluno[i].media = ((aluno[i].notalab * 10) + (aluno[i].notasem * 10) + (aluno[i].notafin * 10)) / (LAB + SEM + FIN);
		if (aluno[i].media >= 8.00){
			aluno[i].classi = 'A';
		} else if ((aluno[i].media >= 7.00) && (aluno[i].media <=7.90)){
			aluno[i].classi = 'B';
		} else if ((aluno[i].media >= 6.00) && (aluno[i].media <= 6.90)){
			aluno[i].classi = 'C';
		} else if ((aluno[i].media >= 5.00) && (aluno[i].media <= 5.90)){
			aluno[i].classi = 'D';
		} else if ((aluno[i].media >= 0.00) && (aluno[i].media <= 4.00)){
			aluno[i].classi = 'R';
		}
	}
}

void impressao(NOTASALUNOS aluno[], int numalunos){
	int i;
	for(i=0 ; i<numalunos ; i++){
		printf("\n\nCodigo do aluno: %d\n", aluno[i].codigo);
		printf("Nome do aluno: %s\n", aluno[i].nome);
		printf("Media final: %.2f\n", aluno[i].media);
		printf("Classificacao: %c\n\n", aluno[i].classi);
	}
}


int main(void){
	int numalunos;
	
	do{
		printf("\nDigite o numero de alunos (maximo 20): ");
		scanf("%d", &numalunos);
		
		if(numalunos <= 0 || numalunos > 20){
			printf("Valor invalido, por favor, tente novamente!");
		}
	}
	while (numalunos <= 0 || numalunos >50);
	
	NOTASALUNOS aluno[numalunos];
	
	leitura(aluno, numalunos);
	calcular(aluno, numalunos);
	impressao(aluno, numalunos);
}
