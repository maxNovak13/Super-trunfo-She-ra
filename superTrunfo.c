#include<stdio.h>
#include<string.h>
#include<time.h>
#include<locale.h>
struct baralho{
	char nome[20];
	int forca;
	int habil;
	int magia;
	int intel;
	char classe;
};
void atribuirVal(struct baralho cart[16]);
void embaralhar(struct baralho cart[16], struct baralho monteJog1[16],struct baralho monteJog2[16], int vazJ1[16], int vazJ2[16]);
int escolherTrib(struct baralho monteJogador[16]);
void organizaMonte(struct baralho monteJogVenceu[16], struct baralho monteJogPerdeu[16], int vetVazVen[16], int vetVazPer[16]);
void fimDoMonte(struct baralho monteJog1[16], struct baralho monteJog2[16], int vetVaz1[16], int vetVaz2[16]);
int calCartas(int vetorVaz[16]);
int main(){
	srand(time(NULL));
	setlocale(LC_ALL, "Portuguese");
	struct baralho carta[16];
	int vencedor, numCarJog1, numCarJog2;
	//var vencedor é usada pra controlar quem venceu a partida e se deu empate;
	atribuirVal(carta);
	//função que atribui valor a struct do baralho;
	printf("\n O jogo do super trunfo começa,\n");
	struct baralho Jog1[16];
	struct baralho Jog2[16];
	int vazJ1[16]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	int vazJ2[16]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	embaralhar(carta, Jog1, Jog2, vazJ1, vazJ2);
	//função que distribui as cartas embaralhadas aos jogadores;
	printf(" as cartas são embaralhadas e distribuídas aos jogadores.\n");
	int partida=1, guardarJog, guardar;	
	do{
		printf("\n\tINICIO DA PARTIDA NÚMERO %d\n", partida);
		if(partida==1){
			//se for a primeira partida escolhe quem joga primeiro aleatoriamente;
			guardarJog=rand()%2;
			if(guardarJog==0){
				printf("\n Jogador 1 iniciará o jogo\n");
				guardar=escolherTrib(Jog1);	
			}
			else if(guardarJog==1){
				printf("\n Jogador 2 iniciará o jogo\n");
				guardar=escolherTrib(Jog2);
			}
		}
		else{
			if(guardarJog==0){
			//após a primeira partida o jogador que venceu a última partida, que não deu empate, é quem inicia; 
				printf("\n Jogador 1 inicia a partida.\n");	
				guardar=escolherTrib(Jog1);
				//essa função "busca" o maior trib e retorna ela
			}
			else if(guardarJog==1){
				printf("\n Jogador 2 inicia a partida.\n");
				guardar=escolherTrib(Jog2);
			}
		}
		if(Jog1[0].classe=='S'){
			//verifica se o jogador 1 tem o supertrunfo
			printf("\n O jogador 1 tem o supertrunfo\n");
			if(Jog2[0].classe=='A'){
				//verifica se o jog 2 tem uma carta de classe A
				printf("\n Mas o jogador 2 tem uma carta de classe A\n\n");
				vencedor=2;
			}
			else{
				//O jogador 2 NÃO tem uma carta de classe A, logo o jogador 1 venceu a partida;
				vencedor=1;
			}
		}
		else if(Jog2[0].classe=='S'){
			//verifica se o jogador 2 tem o supertrunfo
			printf("\n O jogador 2 tem o supertrunfo\n");
			if(Jog1[0].classe=='A'){
				//verifica se o jog 1 tem uma carta de classe A
				printf(" Mas jogador 1 tem uma carta de classe A\n\n");
				vencedor=1;
			} 
			else {
				//jogador 1 NÃO tem uma carta de classe A, logo o jogador 2 venceu a partida;
				vencedor=2;
			}
		}
		else{
			//como ninguém tem supertrunfo, o tributo será comparado;
			if(guardar == 0){
				printf("\n O jogador escolheu o tributo força.\n\n");
				printf("\t Os personagens em jogo são estes:\n");
				printf(" Personagem jogador 1: ");
				puts(Jog1[0].nome);
				printf(" Força: %d\n", Jog1[0].forca);
				printf("\n Personagem jogador 2: ");
				puts(Jog2[0].nome);
				printf(" Força: %d\n\n", Jog2[0].forca);
				if(Jog1[0].forca>Jog2[0].forca){
					vencedor=1;
				} 
				else if (Jog1[0].forca<Jog2[0].forca){
					vencedor=2;
				} 
				else {
					// empate
					vencedor=0;
				}
			}
			else if(guardar == 1){
				printf("\n O jogador escolheu o tributo habilidade.\n\n");
				printf("\t Os personagens em jogo são estes:\n");
				printf(" Personagem jogador 1: ");
				puts(Jog1[0].nome);
				printf(" Habilidade: %d\n", Jog1[0].habil);
				printf("\n Personagem jogador 2: ");
				puts(Jog2[0].nome);
				printf(" Habilidade: %d\n\n", Jog2[0].habil);
				if(Jog1[0].habil>Jog2[0].habil){
					vencedor=1;
				} 
				else if (Jog1[0].habil<Jog2[0].habil){
					vencedor=2;
				} 
				else {
					// empate
					vencedor=0;
				}
			}
			else if(guardar == 2){
				printf("\n O jogador escolheu o tributo magia.\n\n");
				printf("\t Os personagens em jogo são estes:\n");
				printf(" Personagem jogador 1: ");
				puts(Jog1[0].nome);
				printf(" Magia: %d\n", Jog1[0].magia);
				printf("\n Personagem jogador 2: ");
				puts(Jog2[0].nome);
				printf(" Magia: %d\n\n", Jog2[0].magia);
				if(Jog1[0].magia>Jog2[0].magia){
					vencedor=1;
				} 
				else if (Jog1[0].magia<Jog2[0].magia){
					vencedor=2;
				} 
				else {
					// empate
					vencedor=0;
				}
			}
			else if(guardar == 3){
				printf("\n O jogador escolheu o tributo inteligência.\n\n");
				printf("\t Os personagens em jogo são estes:\n");
				printf(" Personagem jogador 1: ");
				puts(Jog1[0].nome);
				printf(" Inteligência: %d\n", Jog1[0].intel);
				printf("\n Personagem jogador 2: ");
				puts(Jog2[0].nome);
				printf(" Inteligência: %d\n\n", Jog2[0].intel);
				if(Jog1[0].intel>Jog2[0].intel){
					vencedor=1;
				} 
				else if (Jog1[0].intel<Jog2[0].intel){
					vencedor=2;
				} 
				else {
					// empate
					vencedor=0;
				}
			}
		}	
		system("pause");
		if(vencedor==1){
			//verifica quem venceu a partida;
			printf("\n\tJogador 1 VENCEU a rodada!\n\n\n");
			organizaMonte(Jog1, Jog2, vazJ1, vazJ2);
			guardarJog=0;
		} 
		else if(vencedor==2){
			printf("\n\tJogador 2 VENCEU a rodada!\n\n\n");
			organizaMonte(Jog2, Jog1, vazJ2, vazJ1);
			guardarJog=1;
		}
		else{
			//se deu empate
			printf("\n\tDeu empate, ");
			if(vazJ1[0]==1 && vazJ1[1]== 0){
				//se o jogador 1 tiver uma carta e der empate ele perde a partida
				printf("mas como o jogador 1 tem apenas uma carta, o jogador 2 VENCEU a rodada.\n\n\n");
				organizaMonte(Jog2, Jog1, vazJ2, vazJ1);
			}
			else if(vazJ2[0]==1 && vazJ2[1]== 0){
				//... o mesmo acontece se for o jogador 2
				printf("mas como o jogador 2 tem apenas uma carta, o jogador 1 VENCEU a rodada.\n\n\n");
				organizaMonte(Jog1, Jog2, vazJ1, vazJ2);
			}
			else{
			printf("as cartas vão para o fim do monte de cada jogador.\n\n\n");
			fimDoMonte(Jog1, Jog2, vazJ1, vazJ2);	
			}
		}
		numCarJog1 = calCartas(vazJ1);
		numCarJog2 = calCartas(vazJ2);
		printf("\tPLACAR\n jogador 1: %d cartas || jogador 2: %d cartas\n\n", numCarJog1, numCarJog2);
		//imprime o placar a cada rodada
		system("pause");
		system("cls");	
		partida++;
	} while(vazJ2[0] == 1 && vazJ1[0] == 1);
	printf("\n \n GAME OVER!\n\n");
	if(vazJ2[0] == 0){
		//verifica qual jogador está sem cartas
		printf(" O jogador 2 ficou sem cartas, logo o vencedor do super trunfo foi o jogador 1.");
	} 
	else {
		printf(" O jogador 1 ficou sem cartas, logo o vencedor do super trunfo foi o jogador 2.");
	}
	return 0;
}
void atribuirVal(struct baralho carta[16]){
	strcpy(carta[0].nome, "She-ra");
	carta[0].forca=9;
	carta[0].habil=8;
	carta[0].magia=8;
	carta[0].intel=7;
	carta[0].classe='S';
	strcpy(carta[1].nome, "Felina");
	carta[1].forca=6;
	carta[1].habil=8;
	carta[1].magia=5;
	carta[1].intel=7;
	carta[1].classe='A';
	strcpy(carta[2].nome, "Sombria");
	carta[2].forca=6;
	carta[2].habil=8;
	carta[2].magia=9;
	carta[2].intel=8;
	carta[2].classe='A';
	strcpy(carta[3].nome, "Mestre da Horda");
	carta[3].forca=8;
	carta[3].habil=8;
	carta[3].magia=6;
	carta[3].intel=9;
	carta[3].classe='A';
	strcpy(carta[4].nome, "Cintilante");
	carta[4].forca=6;
	carta[4].habil=7;
	carta[4].magia=9;
	carta[4].intel=7;
	carta[4].classe='A';
	strcpy(carta[5].nome, "Hordak");
	carta[5].forca=7;
	carta[5].habil=6;
	carta[5].magia=5;
	carta[5].intel=8;
	carta[5].classe='B';
	strcpy(carta[6].nome, "Double Trouble");
	carta[6].forca=5;
	carta[6].habil=7;
	carta[6].magia=7;
	carta[6].intel=8;
	carta[6].classe='B';
	strcpy(carta[7].nome, "Rainha Angela");
	carta[7].forca=5;
	carta[7].habil=6;
	carta[7].magia=8;
	carta[7].intel=7;
	carta[7].classe='B';
	strcpy(carta[8].nome, "Scorpia");
	carta[8].forca=8;
	carta[8].habil=6;
	carta[8].magia=7;
	carta[8].intel=5;
	carta[8].classe='C';
	strcpy(carta[9].nome, "Perfuma");
	carta[9].forca=6;
	carta[9].habil=7;
	carta[9].magia=8;
	carta[9].intel=6;
	carta[9].classe='C';
	strcpy(carta[10].nome, "Arqueiro");
	carta[10].forca=6;
	carta[10].habil=7;
	carta[10].magia=5;
	carta[10].intel=6;
	carta[10].classe='C';
	strcpy(carta[11].nome, "Gélida");
	carta[11].forca=6;
	carta[11].habil=8;
	carta[11].magia=7;
	carta[11].intel=7;
	carta[11].classe='C';
	strcpy(carta[12].nome, "Serena");
	carta[12].forca=6;
	carta[12].habil=7;
	carta[12].magia=8;
	carta[12].intel=6;
	carta[12].classe='D';
	strcpy(carta[13].nome, "Entrapta");
	carta[13].forca=5;
	carta[13].habil=8;
	carta[13].magia=5;
	carta[13].intel=9;
	carta[13].classe='D';
	strcpy(carta[14].nome, "Falcão do Mar");
	carta[14].forca=6;
	carta[14].habil=7;
	carta[14].magia=5;
	carta[14].intel=5;
	carta[14].classe='D';
	strcpy(carta[15].nome, "Huntara");
	carta[15].forca=8;
	carta[15].habil=7;
	carta[15].magia=5;
	carta[15].intel=6;
	carta[15].classe='D';
}
void embaralhar(struct baralho carta[16], struct baralho Jog1[16],struct baralho Jog2[16], int vazJ1[16], int vazJ2[16]){
	int n, k, j, cartasSorteas[16]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1}, l=8;
    for (j = 0; j < 8; j++) {
    	//ditribrui as cartas para o jogador 1
        do {
            n = rand() % 16;
        } while (n==cartasSorteas[0]|| n==cartasSorteas[1] || n==cartasSorteas[2] || n==cartasSorteas[3] || n==cartasSorteas[4] || n==cartasSorteas[5] || n==cartasSorteas[6] || n==cartasSorteas[7]);
        cartasSorteas[j] = n;
		strcpy(Jog1[j].nome, carta[n].nome);
		Jog1[j].forca=carta[n].forca;
		Jog1[j].habil=carta[n].habil;
		Jog1[j].magia=carta[n].magia;
		Jog1[j].intel=carta[n].intel;
		Jog1[j].classe=carta[n].classe;
		cartasSorteas[j] = n;
		vazJ1[j]=1;
		//preenche o vetor que controla as casas preenchidas e vazias do jogador 1;
	}
	for(j=0; j<8; j++){
		//ditribrui as cartas para o jogador 2
		do {
            n = rand() % 16;
        } while (n==cartasSorteas[0] || n==cartasSorteas[1] || n==cartasSorteas[2] || n==cartasSorteas[3] || n==cartasSorteas[4] || n==cartasSorteas[5] || n==cartasSorteas[6] || n==cartasSorteas[7] || n==cartasSorteas[8] || n==cartasSorteas[9] || n==cartasSorteas[10] || n==cartasSorteas[11] || n==cartasSorteas[12] || n==cartasSorteas[13] || n==cartasSorteas[14] || n==cartasSorteas[15]);
        cartasSorteas[l] = n;
        l++;
		strcpy(Jog2[j].nome, carta[n].nome);
		Jog2[j].forca=carta[n].forca;
		Jog2[j].habil=carta[n].habil;
		Jog2[j].magia=carta[n].magia;
		Jog2[j].intel=carta[n].intel;
		Jog2[j].classe=carta[n].classe;
		cartasSorteas[l] = n;	
		vazJ2[j]=1;
	}
}
int escolherTrib(struct baralho monteJog[16]){
	//a função compara cada um dos tributos em busca do maior e retorna qual é o maior pra função principal
	int guar;
	if(monteJog[0].forca > monteJog[0].habil && monteJog[0].forca > monteJog[0].magia && monteJog[0].forca > monteJog[0].intel){
		//verifica se força é o maior tributo do jogador
		guar=0;
	}
	if(monteJog[0].habil > monteJog[0].forca && monteJog[0].habil > monteJog[0].magia && monteJog[0].habil > monteJog[0].intel){
		//verifica se habilidade é o maior tributo do jogador
		guar=1;
	}
	if(monteJog[0].magia > monteJog[0].forca && monteJog[0].magia > monteJog[0].habil && monteJog[0].magia > monteJog[0].intel){
		//verifica se magia é o maior tributo do jogador
		guar=2;
	}
	if(monteJog[0].intel > monteJog[0].forca && monteJog[0].intel > monteJog[0].habil && monteJog[0].intel > monteJog[0].magia){
		//verifica se magia é o maior tributo do jogador
		guar=3;
	}
	return guar;
}
void organizaMonte(struct baralho monteJogVenceu[16], struct baralho monteJogPerdeu[16], int vetVazVen[16], int vetVazPer[16]){
	int j, cont;
	cont=0;
	for(j=0;j<16;j++){
		if(vetVazVen[j]!=1){
		//verifica a posição q tá vazia do monte do jogador vencedor e copia o que ta posição 0 pra proxima q tiver vazia
		//ou seja, coloca a carta do jog vencedor no fim do baralho
			strcpy(monteJogVenceu[j].nome, monteJogVenceu[0].nome);
			monteJogVenceu[j].forca = monteJogVenceu[0].forca;
			monteJogVenceu[j].habil = monteJogVenceu[0].habil;
			monteJogVenceu[j].magia = monteJogVenceu[0].magia;
			monteJogVenceu[j].intel = monteJogVenceu[0].intel;
			monteJogVenceu[j].classe = monteJogVenceu[0].classe;	
			break;
		}
	}
	for(j=0;j<16;j++){
		if(vetVazVen[j]==1){
			//reorganiza o struct do jog vencedor
			strcpy(monteJogVenceu[j].nome, monteJogVenceu[j+1].nome);
			monteJogVenceu[j].forca = monteJogVenceu[j+1].forca;
			monteJogVenceu[j].habil = monteJogVenceu[j+1].habil;
			monteJogVenceu[j].magia = monteJogVenceu[j+1].magia;
			monteJogVenceu[j].intel = monteJogVenceu[j+1].intel;
			monteJogVenceu[j].classe = monteJogVenceu[j+1].classe;
		}
		else{
			//coloca a carta do jog perdedor no baralho do jog vencedor;
			strcpy(monteJogVenceu[j].nome, monteJogPerdeu[0].nome);
			monteJogVenceu[j].forca = monteJogPerdeu[0].forca;
			monteJogVenceu[j].habil = monteJogPerdeu[0].habil;
			monteJogVenceu[j].magia = monteJogPerdeu[0].magia;
			monteJogVenceu[j].intel = monteJogPerdeu[0].intel;
			monteJogVenceu[j].classe = monteJogPerdeu[0].classe;
			vetVazVen[j]=1;
			break;
		}
	}
	for(j=0;j<16;j++){
		if(vetVazPer[j]==1){
			//reorganiza o struct do jog que perdeu
			strcpy(monteJogPerdeu[j].nome, monteJogPerdeu[j+1].nome);
			monteJogPerdeu[j].forca = monteJogPerdeu[j+1].forca;
			monteJogPerdeu[j].habil = monteJogPerdeu[j+1].habil;
			monteJogPerdeu[j].magia = monteJogPerdeu[j+1].magia;
			monteJogPerdeu[j].intel = monteJogPerdeu[j+1].intel;
			monteJogPerdeu[j].classe = monteJogPerdeu[j+1].classe;
			cont++;	
		}
	}	
	vetVazPer[cont-1]=0;
}
void fimDoMonte(struct baralho monteJog1[16], struct baralho monteJog2[16], int vetVaz1[16], int vetVaz2[16]){
	int l;
	for(l=0; l<16; l++){
		//encontra a proxima posição vazia do jogador 1 e cola a primeira carta, "coloca embaixo do monte";
		if(vetVaz1[l] != 1){
			strcpy(monteJog1[l].nome, monteJog1[0].nome);
			monteJog1[l].forca = monteJog1[0].forca;
			monteJog1[l].habil = monteJog1[0].habil;
			monteJog1[l].magia = monteJog1[0].magia;
			monteJog1[l].intel = monteJog1[0].intel;
			monteJog1[l].classe = monteJog1[0].classe;
			break;
		}
	}
	for(l=0; l<16; l++){
		if(vetVaz2[l] != 1){
			//encontra a proxima posição vazia do jogador 2 e cola a primeira carta, "coloca embaixo do monte";
			strcpy(monteJog2[l].nome, monteJog2[0].nome);
			monteJog2[l].forca = monteJog2[0].forca;
			monteJog2[l].habil = monteJog2[0].habil;
			monteJog2[l].magia = monteJog2[0].magia;
			monteJog2[l].intel = monteJog2[0].intel;
			monteJog2[l].classe = monteJog2[0].classe;
			break;
		}
	}
	for(l=0; l<16; l++){
		if(vetVaz1[l] == 1){
			//reorganiza o struct do monte do jog 1
			strcpy(monteJog1[l].nome, monteJog1[l+1].nome);
			monteJog1[l].forca = monteJog1[l+1].forca;
			monteJog1[l].habil = monteJog1[l+1].habil;
			monteJog1[l].magia = monteJog1[l+1].magia;
			monteJog1[l].intel = monteJog1[l+1].intel;
			monteJog1[l].classe = monteJog1[l+1].classe;
		}
		if(vetVaz1[l] != 1){
			//ao encontrar a primeira posição "vazia" no struct q foi colada a primeira carta, 
			//reorganiza no monte(coloca na posição anterior a ela)
			//e "esvazia" a que ela estava
			strcpy(monteJog1[l].nome, "vazio");
			monteJog1[l].forca = 0;
			monteJog1[l].habil = 0;
			monteJog1[l].magia = 0;
			monteJog1[l].intel = 0;
			monteJog1[l].classe = 'v';
			break;
		}
	}
	for(l=0; l<16; l++){
		if(vetVaz2[l] == 1){
			//reorganiza o struct do monte do jog 2
			strcpy(monteJog2[l].nome, monteJog2[l+1].nome);
			monteJog2[l].forca = monteJog2[l+1].forca;
			monteJog2[l].habil = monteJog2[l+1].habil;
			monteJog2[l].magia = monteJog2[l+1].magia;
			monteJog2[l].intel = monteJog2[l+1].intel;
			monteJog2[l].classe = monteJog2[l+1].classe;
		}
		if(vetVaz2[l] != 1){
			//ao encontrar a primeira posição "vazia" no struct q foi colada a primeira carta, 
			//reorganiza no monte(coloca na poição anterior a ela)
			//e "esvazia" a que ela estava
			strcpy(monteJog2[l].nome, "vazio");
			monteJog2[l].forca = 0;
			monteJog2[l].habil = 0;
			monteJog2[l].magia = 0;
			monteJog2[l].intel = 0;
			monteJog2[l].classe = 'v';	
			break;
		}
	}
}
int calCartas(int vetorVaz[16]){
	//calcula a quantidade de cartas de um jogador
	int h, numC;
	numC = 0;
	for(h=0; h<16; h++){
		if(vetorVaz[h] == 1){
			numC++;
		}
	}
	return numC;
}
