#include <stdio.h>
#include <string.h> // para possibilitar retirar o \n incluido no final da string pelo fgets 

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das cartas
// Objetivo: No nível novato você deve criar as cartas representando as cidades utilizando scanf para entrada de dados e printf para exibir as informações.


// Estrutura única para todas as cartas
struct Carta
{

  char estado, codigo[5], cidade[20];
  float area, pib, densidadePopulacional,
  pibPerCapta, superPoder;
  int pontos_turisticos; 
  unsigned long int populacao;

};


/*
  função para calcular densidade populacional:
  Recebe o float cx_populacao e float cx_area > calcula densidade (densidade = população / área ocupada km²)
  > Retorna var com o valor do cálculo da densidade populacional em hab/km²
*/ 
float densidadePopulacional(unsigned long int populacao, float area)
{

  float densidadePop = populacao / area;

  return densidadePop;
}

/*
  Função para calcular o PIB per capta:
  Recebe float cx_pib e int cx_populacao > calcula: Pib / População e armazena em uma var > Retorna var com cálculo para main.
*/
float pibPerCapta(float pib, unsigned long int populacao)
{
  float pibPerCapta = pib / populacao;

  return pibPerCapta;
}





/*
  Função para exibir as cartas cadastradas
  esta deve reber os valores char estado, codigo[5], cidade[20];
  float area, pib, densidadePopulacional, pibPerCapta;
  int pontosTuristicos;
  unsigned long int populacao. 
*/
void exibeCartas(
  int carta,
  char estado, char *codigo, char *cidade,
  float area, float pib, float densidadePopulacional, float pibPerCapta,
  int pontosTuristicos, unsigned long int populacao, float superPoder
)
{ 

  printf("\t= CARTA #%d =\n", carta);
  printf("\tEstado: %c\n", estado);
  printf("\tCodigo: %s\n", codigo);
  printf("\tCidade: %s\n", cidade);
  printf("\tPopulacao: %ld\n", populacao);
  printf("\tArea: %.2f Km^2\n", area);
  printf("\tPIB: %.2f\n", pib);
  printf("\tPontos Turisticos: %d\n", pontosTuristicos);
  printf("\tDensidade populacional: %.2f HAB/Km^2\n", densidadePopulacional);
  printf("\tPIB per capta: R$ %.2f\n", pibPerCapta);
  printf("\tSUPER PODER: %.2f bi\n\n", (superPoder / 1e9));



}

/*
  O SUPER PODER é calculado somando 
  população, área, PIB, número de pontos turísticos, PIB per capita e o inverso da densidade populacional 
*/
float superPoder(
  float area, float pib, float densidadePopulacional, float pibPerCapta,
  float pontosTuristicos, float populacao
)
{
  
  float super = (populacao + area + pib + pontosTuristicos + pibPerCapta) + (-densidadePopulacional);

  return super;

}

void batalha(struct Carta *c1, struct Carta *c2)
{
  
  printf("\n\t\t==== COMPARACAO DE CARTAS ====\n\n");
  
  
  
  
  printf("\tPopulacao: Carta %d venceu (%d)\n\n", 2 - (c1->populacao > c2->populacao), (c1->populacao > c2->populacao) );
  printf("\tArea: Carta %d venceu (%d)\n\n", 2 - (c1->area > c2->area), (c1->area > c2->area) );
  printf("\tPIB: Carta %d venceu (%d)\n\n", 2 - (c1->pib > c2->pib), (c1->pib > c2->pib) );
  printf("\tPontos turisticos: Carta %d venceu (%d)\n\n", 2 - (c1->pontos_turisticos > c2->pontos_turisticos), (c1->pontos_turisticos > c2->pontos_turisticos) );
  printf("\tDensidade Populacional: Carta %d venceu (%d)\n\n", 2 - (c1->densidadePopulacional < c2->densidadePopulacional), (c1->densidadePopulacional < c2->densidadePopulacional) );
  printf("\tPIB per Capta: Carta %d venceu (%d)\n\n", 2 - (c1->pibPerCapta > c2->pibPerCapta), (c1->pibPerCapta > c2->pibPerCapta) );
  printf("\tSuper Poder: Carta %d venceu (%d)\n\n", 2 - (c1->superPoder > c2->superPoder), (c1->superPoder > c2->superPoder) );
  
}  



/*
  Função para cadastramento das cartas
*/
void cadastraCartas(struct Carta *c)
{
  printf("\n\t\t==== CADASTRANDO CARTAS ====\n"); 
  
  printf("Por favor, digite uma letra para o estado de A a H (ex: A): ");
  scanf("%c", &c->estado);
  scanf("%*[^\n]"); scanf("%*c"); //LIMPA O BUFFER

  printf("Digite o codigo da carta no formato LETRA DO ESTADO + numeral(ex: %c01, %c02): ", c->estado, c->estado);
  fgets(c->codigo, 5, stdin);
  c->codigo[strcspn(c->codigo, "\n")] = '\0'; //RETIRA O \N ACRESCENTADO PELO FGETS DO FINAL DA STRING

  printf("Digite nome da cidade, sem acentuacao (ex: Sao Roque): ");
  fgets(c->cidade, 20, stdin);
  c->cidade[strcspn(c->cidade, "\n")] = '\0'; //RETIRA O \N ACRESCENTADO PELO FGETS DO FINAL DA STRING

  printf("Digite a populacao da cidade (ex: 92060): ");
  scanf("%ld", &c->populacao);

  printf("Digite a area da cidade em Km^2 (ex: 307.553): ");
  scanf("%e", &c->area);

  printf("Digite o PIB da cidade (ex: 3108224143.00): ");
  scanf("%e", &c->pib);

  printf("Quantidade de pontos turisticos (ex: 75): ");
  scanf("%d", &c->pontos_turisticos);
  scanf("%*[^\n]"); scanf("%*c"); //LIMPA O BUFFER
  
}

int main() {
  
  struct Carta c1;//carta1
  struct Carta c2; //carta2
  
  // INICIANDO CADASTRO DE CARTAS
  cadastraCartas(&c1);
  cadastraCartas(&c2);
  
/*
  Enviando dados coletados para funções de cálculo de densidade populacional e pib per capta
*/

  c1.densidadePopulacional = densidadePopulacional(c1.populacao, c1.area);
  c1.pibPerCapta = pibPerCapta(c1.pib, c1.populacao); 
  c1.superPoder = superPoder(c1.area, c1.pib, c1.densidadePopulacional,
                             c1.pibPerCapta, c1.pontos_turisticos, 
                             c1.populacao
                            );
  
  c2.densidadePopulacional = densidadePopulacional(c2.populacao, c2.area);
  c2.pibPerCapta = pibPerCapta(c2.pib, c2.populacao); 
  c2.superPoder = superPoder(c2.area, c2.pib, c2.densidadePopulacional,
                             c2.pibPerCapta, c2.pontos_turisticos, 
                             c2.populacao
                            ); 


  // Área para exibição dos dados da cidade
  //Passando as variáveis para a função para exibição das cartas
  
  exibeCartas(
    1,
    c1.estado, c1.codigo, c1.cidade, c1.area, c1.pib,
    c1.densidadePopulacional, c1.pibPerCapta,
    c1.pontos_turisticos, c1.populacao,
    c1.superPoder
  );

  exibeCartas(
    2,
    c2.estado, c2.codigo, c2.cidade, c2.area, c2.pib,
    c2.densidadePopulacional, c2.pibPerCapta,
    c2.pontos_turisticos, c2.populacao,
    c2.superPoder
  );

  batalha(&c1, &c2);
  
return 0;
} 
