#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>
#include <stdbool.h>

/*	dados do viculo
	1 - marca 
	2 - modelo
	3 - ano de fabricação
	4 - placa (XXX-YYYY)
*/

struct carro {
	int id;
	char marca [10];
	char modelo [10];
	int anoFabricacao;
	char placa [8];
};

struct ListaCarros {
	struct carro bancoDados [11];
	int ultimo;
};

/*	funcionalidades
	1 - inserir um novo veiculo
	2 - Listar veiculos cadastrados
	3 - Listar veiculos com filtro de ano de fabricação e modelo
	4 - Listar veiculos acima de um ano determinado pelo usuario
*/
char funcionalidade (){
	char func;
	printf("\nSelecione uma das opções a seguir:\n");
	printf("(i) - P/ Inserir um novo veiculo\n");
	printf("(l) - P/ Listar veiculos cadastrados\n");
	printf("(a) - P/ Listar veiculos com filtro de ano de fabricação\n");
	printf("(m) - P/ Listar veiculos com filtro de modelo\n");
	printf("(u) - P/ Listar veiculos acima de um ano determinado\n");
	printf("(q) - P/ Sair. Sua escolha: ");
	scanf("%c", &func);
	return func;
};

bool inserirNovoItem (struct ListaCarros *Garagem){
	if(Garagem->ultimo == 11){
		return 0;
	}
	else{
		printf("Digite a Marca do Veículo: ");
		scanf("%s/n", &Garagem->bancoDados[Garagem->ultimo+1].marca);
		printf("Digite o Modelo do Veículo: ");
		scanf("%s/n", &Garagem->bancoDados[Garagem->ultimo+1].modelo);
		printf("Digite o Ano de Fabricação do Veículo: ");
		scanf("%d/n", &Garagem->bancoDados[Garagem->ultimo+1].anoFabricacao);
		printf("Digite a Placa do Veículo: ");
		scanf("%s/n", &Garagem->bancoDados[Garagem->ultimo+1].placa);
		Garagem->bancoDados[Garagem->ultimo+1].id = Garagem->ultimo +1;
		Garagem->ultimo = Garagem->ultimo + 1;
		
		printf("_________ Teste de Funcionalidade _________\n");
		printf(Garagem->bancoDados[Garagem->ultimo].marca);
		printf(Garagem->bancoDados[Garagem->ultimo].modelo);
		printf("%d", Garagem->bancoDados[Garagem->ultimo].anoFabricacao);
		printf(Garagem->bancoDados[Garagem->ultimo].placa);
		printf("%d", Garagem->ultimo);
		return 1;
	}
};

void listarItens(struct ListaCarros *Garagem){
	printf("_______ Lista de Carros ______\n");
	int i;
	for(i = 1; i <= Garagem->ultimo; i++){
		printf("Carro ID: %d\n", Garagem->bancoDados[i].id);
		printf("Marca: %s\n", Garagem->bancoDados[i].marca);
		printf("Modelo: %s\n", Garagem->bancoDados[i].modelo);
		printf("Ano de Fabricação: %d\n", Garagem->bancoDados[i].anoFabricacao);
		printf("Placa: %s\n", Garagem->bancoDados[i].placa);
	}
};

void listarPorAno(struct ListaCarros *Garagem){
	int ano, i;
	printf("Digite o ano para o filtro: ");
	scanf("%d/n", &ano);
	for(i = 1; i <= Garagem->ultimo; i++){
		if(Garagem->bancoDados[i].anoFabricacao == ano){
			printf("Carro ID: %d\n", Garagem->bancoDados[i].id);
			printf("Marca: %s\n", Garagem->bancoDados[i].marca);
			printf("Modelo: %s\n", Garagem->bancoDados[i].modelo);
			printf("Ano de Fabricação: %d\n", Garagem->bancoDados[i].anoFabricacao);
			printf("Placa: %s\n", Garagem->bancoDados[i].placa);
		}
	}
};

void listarPorModelo(struct ListaCarros *Garagem){
	int i;
	char modelo [10];
	printf("Digite o modelo para o filtro: ");
	scanf("%s/n", &modelo);
	for(i = 1; i <= Garagem->ultimo; i++){
		if(Garagem->bancoDados[i].modelo == modelo){
			printf("Carro ID: %d\n", Garagem->bancoDados[i].id);
			printf("Marca: %s\n", Garagem->bancoDados[i].marca);
			printf("Modelo: %s\n", Garagem->bancoDados[i].modelo);
			printf("Ano de Fabricação: %d\n", Garagem->bancoDados[i].anoFabricacao);
			printf("Placa: %s\n", Garagem->bancoDados[i].placa);
		}
	}
};

void listarAcimaAno(struct ListaCarros *Garagem){
	int ano, i;
	printf("Digite o ano para o filtro: ");
	scanf("%d/n", &ano);
	for(i = 1; i <= Garagem->ultimo; i++){
		if(Garagem->bancoDados[i].anoFabricacao >= ano){
			printf("Carro ID: %d\n", Garagem->bancoDados[i].id);
			printf("Marca: %s\n", Garagem->bancoDados[i].marca);
			printf("Modelo: %s\n", Garagem->bancoDados[i].modelo);
			printf("Ano de Fabricação: %d\n", Garagem->bancoDados[i].anoFabricacao);
			printf("Placa: %s\n", Garagem->bancoDados[i].placa);
		}
	}
};

int main(int argc, char *argv[]) {
		
	setlocale(LC_ALL, "Portuguese");
	bool doWhile = 1;

	
	struct ListaCarros Garagem;
	Garagem.bancoDados[0].anoFabricacao = 0;
	Garagem.bancoDados[0].id = 0;
	Garagem.bancoDados[0].marca[0] = 'x';
	Garagem.bancoDados[0].modelo[0] = 'x';
	Garagem.bancoDados[0].placa[0] = 'x';
	Garagem.ultimo = 0;
	
	printf("\n______ Sistema de Informações de Veiculos _______\n");
	

	do{
		char funcion = funcionalidade();
		switch (funcion){		
			case 'i':
				if((inserirNovoItem(&Garagem))== 0){					
					printf("Lista completa!");
				}
				else{
					printf("Carro Inserido na Lista!");
				}
				break;
			case 'l':
				listarItens(&Garagem);
				break;
			case 'a':
				listarPorAno(&Garagem);
				break;
			case 'm':
				listarPorModelo(&Garagem);
				break;
			case 'u':
				listarAcimaAno(&Garagem);
				break;
			case 'q':
				doWhile = 0;
				break;
		}
	}
		
	while (doWhile == 1);
	
	return 0;
}
