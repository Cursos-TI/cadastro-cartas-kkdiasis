#include <stdio.h>
#include <string.h> // para possibilitar retirar o \n incluido no final da string pelo fgets 

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das cartas
// Objetivo: No nível novato você deve criar as cartas representando as cidades utilizando scanf para entrada de dados e printf para exibir as informações.
//

/*
  função para calcular densidade populacional:
  Recebe o float cx_populacao e float cx_area > calcula densidade (densidade = população / área ocupada km²)
  > Retorna var com o valor do cálculo da densidade populacional em hab/km²
*/ 
float densidadePopulacional(float populacao, float area)
{

  float densidadePop = populacao / area;

  return densidadePop;
}

/*
  Função para calcular o PIB per capta:
  Recebe float cx_pib e int cx_populacao > calcula: Pib / População e armazena em uma var > Retorna var com cálculo para main.
*/
float pibPerCapta(float pib, float populacao)
{
  float pibPerCapta = pib / populacao; //conversão explicita de int populacao para float populacao

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
  char estado, char codigo[5], char cidade[20],
  float area, float pib, float densidadePopulacional, float pibPerCapta,
  int pontosTuristicos, int populacao
)
{

  printf("\t= CARTA #%d =\n", carta);
  printf("\tEstado: %c\n", estado);
  printf("\tCodigo: %s\n", codigo);
  printf("\tCidade: %s\n", cidade);
  printf("\tPopulacao: %d\n", populacao);
  printf("\tArea: %.2f Km^2\n", area);
  printf("\tPIB: %.2f\n", pib);
  printf("\tPontos Turisticos: %d\n", pontosTuristicos);
  printf("\tDensidade populacional: %.2f HAB/Km^2\n", densidadePopulacional);
  printf("\tPIB per capta: R$ %.2f\n\n", pibPerCapta);



}



int main() {
  // Área para definição das variáveis para armazenar as propriedades das cidades
  // vars Carta #1
  char c1_estado, c1_codigo[5], c1_cidade[20];
  float c1_area, c1_pib, c1_densidadePopulacional, c1_pibPerCapta;
  int c1_pontos_turisticos; 
  int c1_populacao;

  // vars Carta #2
  char c2_estado, c2_codigo[5], c2_cidade[20];
  float c2_area, c2_pib, c2_densidadePopulacional, c2_pibPerCapta;
  int c2_populacao, c2_pontos_turisticos;
   


  // Área para entrada de dados
  //CARTA #1
  printf("\n\t\t==== SUPER TRUNFO CIDADES ====\n"); 
  printf("\n\t\t==== CADASTRANDO CARTA #1 ====\n"); 
  
  printf("Por favor, digite uma letra para o estado de A a H (ex: A): ");
  scanf("%c", &c1_estado);
  scanf("%*[^\n]"); scanf("%*c"); //LIMPA O BUFFER

  printf("Digite o codigo da carta no formato LETRA DO ESTADO + numeral(ex: %c01, %c02): ", c1_estado, c1_estado);
  fgets(c1_codigo, 5, stdin);
  c1_codigo[strcspn(c1_codigo, "\n")] = '\0'; //RETIRA O \N ACRESCENTADO PELO FGETS DO FINAL DA STRING

  printf("Digite nome da cidade, sem acentuacao (ex: Sao Roque): ");
  fgets(c1_cidade, 20, stdin);
  c1_cidade[strcspn(c1_cidade, "\n")] = '\0'; //RETIRA O \N ACRESCENTADO PELO FGETS DO FINAL DA STRING

  printf("Digite a populacao da cidade (ex: 92060): ");
  scanf("%d", &c1_populacao);

  printf("Digite a area da cidade em Km^2 (ex: 307.553): ");
  scanf("%e", &c1_area);

  printf("Digite o PIB da cidade (ex: 3108224143.00): ");
  scanf("%e", &c1_pib);

  printf("Quantidade de pontos turisticos (ex: 75): ");
  scanf("%d", &c1_pontos_turisticos);
  

  /*****************************************************************/
  //CARTA #2
  
  printf("\n\t\t==== CADASTRANDO CARTA #2 ====\n"); 
  scanf("%*[^\n]"); scanf("%*c"); //LIMPA O BUFFER
  
  printf("Por favor, digite uma letra para o estado de A a H (ex: B): ");
  scanf("%c", &c2_estado);
  scanf("%*[^\n]"); scanf("%*c"); //LIMPA O BUFFER

  printf("Digite o codigo da carta no formato LETRA DO ESTADO + numeral(ex: %c01, %c02): ", c2_estado, c2_estado);
  fgets(c2_codigo, 5, stdin);
  c2_codigo[strcspn(c2_codigo, "\n")] = '\0'; //RETIRA O \N ACRESCENTADO PELO FGETS DO FINAL DA STRING

  printf("Digite nome da cidade, sem acentuacao (ex: Sao Paulo): ");
  fgets(c2_cidade, 20, stdin);
  c2_cidade[strcspn(c2_cidade, "\n")] = '\0'; //RETIRA O \N ACRESCENTADO PELO FGETS DO FINAL DA STRING

  printf("Digite a populacao da cidade (ex: 11451999): ");
  scanf("%d", &c2_populacao);

  printf("Digite a area da cidade em Km^2 (ex: 1521.202): ");
  scanf("%e", &c2_area);

  printf("Digite o PIB da cidade (ex: 828980607731.00): ");
  scanf("%e", &c2_pib);

  printf("Quantidade de pontos turisticos (ex: 75): ");
  scanf("%d", &c2_pontos_turisticos);

/*
  Enviando dados coletados para funções de cálculo de densidade populacional e pib per capta
*/

  c1_densidadePopulacional = densidadePopulacional(c1_populacao, c1_area);
  c1_pibPerCapta = pibPerCapta(c1_pib, c1_populacao); 
  c2_densidadePopulacional = densidadePopulacional(c2_populacao, c2_area);
  c2_pibPerCapta = pibPerCapta(c2_pib, c2_populacao); 


  // Área para exibição dos dados da cidade
  
  
  exibeCartas(
    1,
    c1_estado, c1_codigo, c1_cidade, c1_area, c1_pib,
    c1_densidadePopulacional, c1_pibPerCapta,
    c1_pontos_turisticos, c1_populacao
  );

  exibeCartas(
    2,
    c2_estado, c2_codigo, c2_cidade, c2_area, c2_pib,
    c2_densidadePopulacional, c2_pibPerCapta,
    c2_pontos_turisticos, c2_populacao
  );

  
return 0;
} 
