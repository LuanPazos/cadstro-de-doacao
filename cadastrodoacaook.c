#include <stdio.h>
#define SIZE 500 
char nome[SIZE] [50]; // matris 200x 50 max-49 caracteres no fim tem que ter /0
char email[SIZE] [50];
int cpf [SIZE];
char tipoSanguineo[SIZE] [50];
int op;
void cadastro();
void pesquisa();
void lista();
int main(void) {
	//cadastro(); comentado porque foi chamado manualmente
	//lista();    comentado pq foi chamado manualmente
	//pesquisa();  comentado pq foi chamado manualmente
	do{
		system("cls"); //system permite executar o prompt dentro do programa
	    printf("\n----BEM VINDO AO SISTEMA DE CADASTRO DE DOACOES----\n1 - Cadastrar\n2 - Mostrar Cadastros \n3 - Pesquisar cadastro\n4 - Sair \n");
	    scanf("%d", &op);
		fflush(stdin);
	    switch(op){
	    	case 1:
	    		cadastro(); //chama função cadastro
	    		break;
	    	case 2:
	    		lista();
	    		break;
	    	case 3:
	    		pesquisa();
	    		break;
	    	case 4:
	    		system("exit"); //fecha janela
	    	    break;
	    	default:
	    		printf("opcao invalida");
	    		break;
		}
	    
	}while(op!=4); //se opção for diferente de 4 ( c n quiser sair) igual a 4 sai do prog
}
void lista() {
	int i;
	for(i=0;i<SIZE;i++) {
		if(cpf[i]>0){
			printf("\nNome: %s\nemail: %s\nCPF: %d \nTipo sanguineo: %s \n", nome[i], email[i], cpf[i], tipoSanguineo[i]);
		}else{
			break;
		}
			
	}
	getchar();
	getchar();
}



void cadastro() {
	static int linha;
	do{
		printf("\nDigite o nome: ");
		scanf("%[^\n]s", &nome[linha]); // COMANDO PARA LER PALAVRAS QUE CONTEM ESPAÇAMENTO
		fflush(stdin);
		printf ("\ndigite o email: ");
		scanf("%s", &email[linha]);
		fflush(stdin);
		printf("\ndigite o cpf: ");
		scanf("%d", &cpf [linha]); //%d pq é do tipo int (inteiro)
		fflush(stdin);
		printf("\ndigite o seu tipo sanguineo: ");
		scanf("%s", &tipoSanguineo[linha]);
		fflush(stdin);
		printf("\nDigite 1 para continuar ou outro valor para sair");
		scanf("%d",&op);
		fflush(stdin);
		linha++; //proxima execição muda para proxima linha ou (linha=linha+1)
	}while(op==1);
} //FIM DO CADASTRO
void pesquisa() {
	int cpfPesquisa;
	char tipoSanguineoPesquisa [50];
	int i;
	do{
		printf("\nDigite 1 para pesquisar o cpf \nDigite 2 para pesquisar o tipo sanguineo\n ");
		scanf("%d", &op);
		
		switch(op){
			case 1:
				printf("\nDigite o CPF:");
				scanf("%d", &cpfPesquisa);
				fflush(stdin);
				for(i=0;i<SIZE;i++){//i vai de 0 a 499 size vale 500
					if(cpf[i]==cpfPesquisa) {
						printf("\nNome: %s\nemail: %s\nCPF: %d \nTipo sanguineo: %s ", nome[i], email[i], cpf[i], tipoSanguineo[i]);
						}
				}
				break;
			case 2:
				printf("\nDigite o TIPO SANGUINEO\n");
				scanf("%s", &tipoSanguineoPesquisa);
				fflush(stdin);
					for(i=0;i<SIZE;i++){//i vai de 0 a 499 size vale 500
					if(strcmp (tipoSanguineo[i], tipoSanguineoPesquisa)==0){
						printf("\nNome: %s\nemail: %s\nCPF: %d \nTipo sanguineo: %s ", nome[i], email[i], cpf[i], tipoSanguineo[i]);
					}
		    	}
				break;
			default:
				printf("\n Opcao invalida");
				break;
		}
		printf("\nDigite 1 para continuar pesquisando ");
		scanf("%d", &op);
		fflush(stdin);
	}while(op==1);
	
}