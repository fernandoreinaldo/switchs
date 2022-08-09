//1. Crie um programa onde a struct armazene os dados de 5 alunos: nome, idade, sexo, matricula, cidade, curso. 
//Os dados devem ser lidos e após impressos. O programa deve utilizar 3 módulos: leitura, impressão e o módulo para encontra o mais velho e mais novo.
//Encontre: o nome do mais velho e o nome do mais novo, imprima estes resultados na função criada.

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


typedef struct{
	char nome[50];
	int idade;
	char sexo;
	int matricula;
	char cidade[50];
	char curso[50];
}CADALUNOS;

void maiormenor (CADALUNOS alunos[3]){
	int maior, menor, i, pmaior=0, pmenor=0;
	maior = alunos[0].idade;
	menor = alunos[0].idade;
	for (i=0; i<3;i++){
		if (alunos[i].idade > maior){
			maior = alunos[i].idade;
			pmaior = i;
		}else if(alunos[i].idade < menor){
			menor = alunos[i].idade;
			pmenor = i;
		}
	}
	printf ("\nMais velho: %s", alunos[pmaior].nome);
	printf ("\nMais novo: %s", alunos[pmenor].nome);
}

void imprimir (CADALUNOS alunos[3]){
	int i;
		for (i=0;i<3;i++){
		printf ("\nAluno %d", i);
		printf ("\n Nome do aluno: %s ", alunos[i].nome);
		printf ("\n Idade: %d ", alunos[i].idade);
		printf ("\n Sexo: %c ", alunos[i].sexo);
		printf ("\n Matricula: %d ", alunos[i].matricula);
		printf ("\n Cidade: %s ", alunos[i].cidade);
		printf ("\n Curso: %s ", alunos[i].curso);
	}
}

void leitura (CADALUNOS alunos[3]){
	int i;
	for (i=0;i<3;i++){
		printf ("\nAluno %d", i);
		printf ("\n Digite o nome do aluno: ");
		fflush (stdin);
		gets (alunos[i].nome);
		printf ("\n Digite a idade: ");
		scanf ("%d", &alunos[i].idade);
		printf ("\n Digite o sexo: ");
		fflush (stdin);
		scanf ("%c", &alunos[i].sexo);
		printf ("\n Digite a matricula: ");
		scanf ("%d", &alunos[i].matricula);
		printf ("\n Digite a cidade: ");
		fflush (stdin);
		gets (alunos[i].cidade);
		printf ("\n Digite o curso: ");
		fflush (stdin);
		gets (alunos[i].curso);
	}
}

int main(void){
	CADALUNOS alunos[3];
	int maior, menor;
	leitura(alunos);
	imprimir(alunos);
	maiormenor (alunos);
}
