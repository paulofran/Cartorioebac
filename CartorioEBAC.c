#include <stdio.h> //Biblioteca de comunicação com o usuário
#include <stdlib.h> //Biblioteca de alocação de espaço em memória
#include <locale.h> //Biblioteca de alocações de texto por região
#include <string.h> //Biblioteca responsavel pelas strings

//funcao responsavel por cadastrar os usuarios no sistema
int registro(){
	//inicio criacao de variaveis/strings
	char arquivo[40];
	char cpf[40];
	char nome [40];
	char sobrenome [40];
	char cargo [40];
	//final da criacao de variaveis/strings
	int opcao = 0;
	
	printf("Voltar a pagina?: \n\n");
	printf("Digite o CPF a ser cadastrado: "); //coletando a informacao do usuario
	scanf("%s", cpf); //salvando a informacao do usuario e %s refere-se a string
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das strings
	
	FILE *file; //cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
	fprintf(file,cpf); //salvo o valor da variavel
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo,"a"); //atualiza o arquivo
	fprintf(file,","); //adiciona "," no arquivo
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: "); //coletando a informacao do usuario
	scanf("%s",nome); //salvando a informacao adicionada 
	
	file = fopen(arquivo,"a"); //atualiza o arquivo	
	fprintf(file,nome);//adiciona a informacao adicionada ao arquivo
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo,"a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);

	system("pause");
}

int consulta(){
	setlocale(LC_ALL, "Portuguese"); //definindo linguagem
	
	//criacao de variaveis
	char cpf[40];
	char conteudo[200];
	//fim de criacao de variaveis
	
	// Solicita ao usuario que insira o CPF a ser cadastrado 
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf); //salva a informacao solicitada acima
	
	FILE *file; // abre os arquivos que corresponde ao cpf pra leitura
	file =  fopen(cpf,"r"); //abre o arquivo e lê ele
	
	//mensagem para caso nao tenha o arquivo no banco de dados
	if(file == NULL){
		printf("Arquivo nao localizado\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL){
		printf("\nEssas sao as informacoes do usuario: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	
}

int deletar(){	
	char cpf[40]; // criacao de variavel char. (variavel tipo char é melhor para strings)
	
	printf("Digite o CPF do usuario a ser DELETADO: "); //adiciona um cpf para o sistema consultar
	scanf("%s", cpf); //salva o cpf para consulta
	
	FILE *file; //abre o arquivo
	file = fopen(cpf,"r"); //ler a variavel cpf e comparar as informacoes
	fclose(file);//fecha o arquivo
	
	//verifica as informacoes e se o cpf adicionado nao existir, cria uma mensagem
	if(file == NULL){
		printf("Usuario nao encontrado no sistema!.\n");
		system("pause");
		
	}
	//verifica se o cpf existe no banco de dados e se existir exclui e manda mensagem pro usuario
	if(file != NULL){
		remove(cpf); //remove o cpf verificado
		printf("Usuario deletado com sucesso!\n\n");//mensagem pro usuario de confirmacao
		system("pause");//pausa a mensagem
	}
	
	//caso haja algum problema e o sistema nao consiga verificar as informacoes
	else {
		printf("\n Erro ao deletar o usuario.\n\n");//cria uma mensagem de erro ao verificar cpf
		system("pause");
	}
	
	
}

int main(){
	
	int opcao = 0; //definindo variaveis
	int laco = 1; //variavel de repeticao
 
	for(laco=1;laco=1;){
		
		system("cls"); //responsavel por limpar a tela
		setlocale(LC_ALL, "Portuguese"); //definindo linguagem
		
		//inicio do menu
		printf("### Cartório da EBAC ###\n\n"); 
		printf("Escolha a opção desejada do menu:\n\n");
		printf("\t1 - Registrar nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("Opcao:"); 
		//final do menu
		
		scanf("%d", &opcao); //armazenando a escolha do user
		
		system("cls"); //responsavel por limpar a tela
		
		//Inicio da selecao
		
		switch(opcao){
			case 1:
				registro(); //chamada da funcao registro
			break;	
			
			case 2:
				consulta();	//chamada da funcao consulta
			break;
			
			case 3:
				deletar(); //chamada da funcao deletar
			break;
			
			default:
				printf("Esse numero nao e valido, tente novamente! \n\n");
				system("pause");
			
		}
		//fim da selecao
		
		
		
		
		//printf("Esse Software foi desenvolvido por Paulo Francisco\n");
		
	}
	
	
}
 

