# include	<stdio.h>
# include	<string.h>
# include	<stdlib.h>
# include	<time.h>

void abertura();
void chute();
void desenhaforca();
void escolhepalavra();
int acertou();
int enforcou();
int jachutou(char letra);
int chuteserrados();

	char palavrasecreta[20];
	char chutes[26];
	int chutesdados = 0;

void abertura(){
	printf("**************************\n");
	printf("*	Jogo de Forca	*\n");
	printf("**************************\n");
}

void chuta(){
	char chute;
	scanf(" %c", &chute);
		
	chutes[chutesdados] = chute;
	chutesdados++;
}

int jachutou(char letra){
	int achou = 0;
	int j;
			
	for(j = 0; j < chutesdados; j++){
		if(chutes[j] == letra){
			achou = 1;
			break;
		}
	}
	return achou;	
}

void desenhaforca(){
	int i;
	
	int erros = chuteserrados();
	
	printf("DICA: Fruta\n");
    printf("  _______       \n");
    printf(" |/      |      \n");
    printf(" |      %c%c%c  \n", (erros>=1?'(':' '), (erros>=1?'_':' '), (erros>=1?')':' '));
    printf(" |      %c%c%c  \n", (erros>=3?'\\':' '), (erros>=2?'|':' '), (erros>=3?'/': ' '));
    printf(" |       %c     \n", (erros>=2?'|':' '));
    printf(" |      %c %c   \n", (erros>=4?'/':' '), (erros>=4?'\\':' '));
    printf(" |              \n");
    printf("_|___           \n");
    printf("\n\n");
	
	for(i = 0; i < strlen(palavrasecreta); i++){
			
		int achou = jachutou(palavrasecreta[i]);
			
		if(achou){
			printf("%c ", palavrasecreta[i]);
		} else{
			printf("_ ");
		}
	}
	printf("\n");
}

void escolhepalavra(){
	sprintf(palavrasecreta, "UVA");
}

int acertou(){
	int i;
	
	for(i = 0; i < strlen(palavrasecreta); i++) {
		if(!jachutou(palavrasecreta[i])) {
			return 0;
		}
	}
	return 1;
}

int chuteserrados(){
		int i;
	int j;
	int erros = 0;
	
	for(i = 0; i < chutesdados; i++){
		
		int existe = 0;

		
		for(j = 0; j < strlen(palavrasecreta); j++){
			if(chutes[i] == palavrasecreta[j]) {
				
				existe = 1;
				break;
			}
		}
		
		if(!existe) erros++;
	}
	return erros;
}
int enforcou(){

	
	return chuteserrados() >= 5;
}

int main(){
		
	escolhepalavra();
	
	abertura();
	
	do{
		desenhaforca(palavrasecreta, chutes, chutesdados);
		chuta(chutes, &chutesdados);
		
	} while(!acertou() && !enforcou());
	
	if(acertou()) {
		printf("\nParabéns, você ganhou!\n\n");

        printf("       ___________      \n");
        printf("      '._==_==_=_.'     \n");
        printf("      .-\\:      /-.    \n");
        printf("     | (|:.     |) |    \n");
        printf("      '-|:.     |-'     \n");
        printf("        \\::.    /      \n");
        printf("         '::. .'        \n");
        printf("           ) (          \n");
        printf("         _.' '._        \n");
        printf("        '-------'       \n\n");
		
		
	} else{
		printf("\nPuxa, você foi enforcado!\n");
        printf("A palavra era **%s**\n\n", palavrasecreta);

        printf("    _______________         \n");
        printf("   /               \\       \n"); 
        printf("  /                 \\      \n");
        printf("//                   \\/\\  \n");
        printf("\\|   XXXX     XXXX   | /   \n");
        printf(" |   XXXX     XXXX   |/     \n");
        printf(" |   XXX       XXX   |      \n");
        printf(" |                   |      \n");
        printf(" \\__      XXX      __/     \n");
        printf("   |\\     XXX     /|       \n");
        printf("   | |           | |        \n");
        printf("   | I I I I I I I |        \n");
        printf("   |  I I I I I I  |        \n");
        printf("   \\_             _/       \n");
        printf("     \\_         _/         \n");
        printf("       \\_______/           \n");
		
	}
}
