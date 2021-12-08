#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<string.h>

struct aluno{
  double ra;
  char nome[20];
  
  struct aluno *anterior;
};
struct aluno *atual = NULL;

void buscar_por_nome_ou_parte_dele(){
	printf("#### Buscar por nome ou parte do nome ####\n\n");
     
     
     char parte_nome[20];
     
     		printf("Digite o nome ou parte do nome para pesquisar: ");
     		scanf("%s",	&parte_nome);
     		
   
     		
	struct aluno *atual_aux = atual;
	if (atual_aux==NULL){
		printf("\nNenhum registro foi encontrado!");
	}else{
		while(atual_aux!=NULL){
			 if (strstr(atual_aux->nome, parte_nome)){
		printf("%s E parte do nome %s",parte_nome,atual_aux->nome);
			
			printf("\n----------------\n");
		}
	atual_aux = atual_aux->anterior;
	 }

   }
}
	
  
  
	

void excluir_todos(){
	printf("Deseja realmente excluir todo os registros\n");
	printf("resposta(s/n):");
	fflush(stdin);
	
	
	
	
	struct aluno *atual_aux = atual;
	if (atual_aux==NULL){
		printf("\nNenhum registro foi encontrado!");
	}else{	
		while(atual_aux!=NULL){
			
		if(getchar()=='s'){
		 
		  	free(atual);
		  	
			 
			   	atual_aux = atual_aux->anterior;
			   printf("\n----------------\n");
			   printf("Registro excluido com sucesso !");
			   
			   
			   system("pause");
		  }	
		  
		main();
		}
		 
	     
		}
		
		
 

	
}



void exibir_maior_e_menor_nome_cadastrado(){
//	char nome1[20];
//	char nome2[20];
	
/*	printf("Digite um nome: ");
	scanf(" %[^\n]",&nome1);

	printf("Digite outro nome: ");
	scanf(" %[^\n]",&nome2);*/
		struct aluno *atual_aux = atual;
	if (atual_aux==NULL){
		printf("\nNenhum registro foi encontrado!");
	}else{
		while(atual_aux!=NULL){
		
	if (strlen(atual_aux->anterior->nome)>strlen(atual_aux->nome)){
		printf("\nO nome %s tem mais letras que o nome %s",atual_aux->anterior->nome,atual_aux->nome);
	}else if (strlen(atual_aux->nome)>strlen(atual_aux->anterior->nome)){
		printf("\nO nome %s tem mais letras que o nome %s",atual_aux->nome, atual_aux->anterior->nome);
	}else{
		printf("\nO dois nomes tem a mesma quantidade de letras");		
	}
		atual_aux = atual_aux->anterior;
		printf("\n----------------\n");
		
    printf("\n\n");
	system("pause");
	
}
}
}

void cadastrar(){
     printf("#### Cadastro ####\n\n");
     struct aluno *anterior = atual;
     atual = (struct aluno *) malloc(sizeof(struct aluno));
     atual->anterior = anterior;
     
     printf("Digite o RA..: ");
     scanf("%lf",&atual->ra);
     
     printf("Digite o NOME: ");
     fflush(stdin);
     gets(atual->nome);
     
     printf("\nDados cadastrador com sucesso!");
}

void consultar(){
	printf("#### Consulta ####\n\n");
	printf("Digite o RA..: ");
	double ra;
	scanf("%lf",&ra);
	struct aluno *atual_aux = atual;
	struct aluno *proximo   = atual;
	while(atual_aux!=NULL){
		if (atual_aux->ra==ra){
			printf("Dados encontrados:\n");
			printf("RA   = %.0lf\n",atual_aux->ra);                    
			printf("NOME = %s\n\n",atual_aux->nome);
			break;
		}
		proximo = atual_aux;
        atual_aux = atual_aux->anterior;
	}
     
	if (atual_aux==NULL){
		printf("Nenhum registro foi encontrado!");
		return;
	}
	int opcao;
    for(;;){
	 	printf("O que deseja fazer:\n");
		printf("1 - Alterar\n");
		printf("2 - Excluir\n");
		printf("3 - voltar\n");
		printf("Opcao: ");
		scanf("%d",&opcao);
		if (opcao==1){
			printf("Digite os novos dados:\n");                     
			printf("RA   = ");                    
			scanf("%lf",&atual_aux->ra);
			printf("NOME = ");
			fflush(stdin);
			gets(atual_aux->nome);
			printf("Registro alterado com sucesso!");  
			break;
		}else if (opcao==2){
			printf("Deseja realmente excluir o registro\n");
			printf("Resposta (s/n): ");
			fflush(stdin);
			if (getchar()=='s'){
			  if (atual_aux == atual){
			      atual = atual->anterior;
			      free(atual_aux);
			  }else{               
			      proximo->anterior = atual_aux->anterior;
			      free(atual_aux); 
			  }
			  printf("Registro excluido com sucesso!");
			  return;             
			}else{
			  printf("Nenhum registro foi excluido!");                        
			}
		}else if (opcao==3){
			printf("Voltando ao menu inicial...");
			break;
		}else{
			printf("Opção inválida!");
		}
	}
}

void listar_todos(){
	printf("#### Exibindo todos os registros ####\n\n");
	struct aluno *atual_aux = atual;
	if (atual_aux==NULL){
		printf("\nNenhum registro foi encontrado!");
	}else{
		while(atual_aux!=NULL){
			printf("RA   = %.0lf",atual_aux->ra);                    
			printf("\nNOME = %s",atual_aux->nome);
			atual_aux = atual_aux->anterior;
			printf("\n----------------\n");
		}
	}
 }


main(){
     int opcao;
     for(;;){
         system("cls");
         printf("#### SISTEMA DE GERENCIAMENTO DE ALUNOS ####\n\n");
         printf("1 - Cadastrar aluno\n");
         printf("2 - Consultar por RA\n");
         printf("3 - Listar todos\n");
         printf("4 - Buscar por nome (completo ou uma parte nome) \n");
         printf("5 - Excluir todos  \n");
         printf("6 - Exibir o maior e o menor nome cadastrado \n");
         printf("7 - Sair\n\n");
		         
         printf("\nDigite a opcao desejada: ");
         scanf("%d",&opcao);
         system("cls");
         if (opcao==1){
            cadastrar();
         }else if (opcao==2){
            consultar();
         }else if (opcao==3){
            listar_todos();
         }else if (opcao==4){
         	//Desenvolver esta função
            buscar_por_nome_ou_parte_dele();
         }else if (opcao==5){
            //Desenvolver esta função
            excluir_todos();
         }else if (opcao==6){
            //Desenvolver esta função
            exibir_maior_e_menor_nome_cadastrado();
         }else if (opcao==7){
            printf("Saindo...");
            getch();
            break;
         }
         getch();
     }
}
