#include <stdio.h>

// Desafio Super Trunfo - Países
// Tema 1 - Cadastro das cartas
// Objetivo: No nível novato você deve criar as cartas representando as cidades utilizando scanf para entrada de dados e printf para exibir as informações.

int main() {
  // Área para definição das variáveis para armazenar as propriedades das cidades
  // vars Carta #1
  char c1_estado[10], c1_codigo[5], c1_cidade[20];
  float c1_area, c1_pib;
  int c1_populacao, c1_pontos_turisticos; 

  // vars Carta #2
  char c2_estado[20], c2_codigo[5], c2_cidade[20];
  float c2_area, c2_pib;
  int c2_populacao, c2_pontos_turisticos;
   


  // Área para entrada de dados
  //CARTA #1
  printf("\n\t\t==== CADASTRANDO CARTA #1 ====\n"); 
  
  printf("Por favor, digite o estado sem acentuacao (ex: Sao Paulo): ");
  scanf("%[^\n]", c1_estado);
  scanf("%*[^\n]"); scanf("%*c"); //LIMPA O BUFFER

  printf("Digite o codigo da carta (ex: A01, A02): ");
  scanf("%[^\n]", c1_codigo);
  scanf("%*[^\n]"); scanf("%*c"); //LIMPA O BUFFER

  printf("Digite nome da cidade, sem acentuacao (ex: Belem): ");
  scanf("%[^\n]", c1_cidade);
  scanf("%*[^\n]"); scanf("%*c"); //LIMPA O BUFFER

  printf("Digite a populacao da cidade (ex: 10500000): ");
  scanf("%d", &c1_populacao);

  printf("Digite a area da cidade em Km^2 (ex: 1.5006000): ");
  scanf("%e", &c1_area);

  printf("Digite o PIB da cidade (ex: 1.500633432): ");
  scanf("%e", &c1_pib);

  printf("Quantidade de pontos turisticos (ex: 75): ");
  scanf("%d", &c1_pontos_turisticos);
  

  /*****************************************************************/
  //CARTA #2
  printf("\n\t\t==== CADASTRANDO CARTA #2 ====\n"); 
  scanf("%*[^\n]"); scanf("%*c"); //LIMPA O BUFFER
  
  printf("Por favor, digite o estado sem acentuacao (ex: Sao Paulo): ");
  scanf("%[^\n]", c2_estado);
  scanf("%*[^\n]"); scanf("%*c"); //LIMPA O BUFFER

  printf("Digite o codigo da carta (ex: B01, B02): ");
  scanf("%[^\n]", c2_codigo);
  scanf("%*[^\n]"); scanf("%*c"); //LIMPA O BUFFER

  printf("Digite nome da cidade, sem acentuacao (ex: Belem): ");
  scanf("%[^\n]", c2_cidade);
  scanf("%*[^\n]"); scanf("%*c"); //LIMPA O BUFFER

  printf("Digite a populacao da cidade (ex: 10500000): ");
  scanf("%d", &c2_populacao);

  printf("Digite a area da cidade em Km^2 (ex: 1.5006000): ");
  scanf("%e", &c2_area);

  printf("Digite o PIB da cidade (ex: 1.500633432): ");
  scanf("%e", &c2_pib);

  printf("Quantidade de pontos turisticos (ex: 75): ");
  scanf("%d", &c2_pontos_turisticos);


  // Área para exibição dos dados da cidade
  //Exibindo deck de cartas lado a lado
  printf("\n\t\t\t==== DECK ==== \n");

  // EXIBINDO INFORMAÇÕES DA CARTA #1
  printf("\t= CARTA #1 =\n");
  printf("\tEstado: %s\n", c1_estado);
  printf("\tCodigo: %s\n", c1_codigo);
  printf("\tCidade: %s\n", c1_cidade);
  printf("\tPopulacao: %d\n", c1_populacao);
  printf("\tArea: %f Km^2\n", c1_area);
  printf("\tPIB: %f\n", c1_pib);
  printf("\tPontos Turisticos: %d\n\n", c1_pontos_turisticos);

  // EXIBINDO INFORMAÇÕES DA CARTA #2
  printf("\t= CARTA #2 =\n");
  printf("\tEstado: %s\n", c2_estado);
  printf("\tCodigo: %s\n", c2_codigo);
  printf("\tCidade: %s\n", c2_cidade);
  printf("\tPopulacao: %d\n", c2_populacao);
  printf("\tArea: %f Km^2\n", c2_area);
  printf("\tPIB: %f\n", c2_pib);
  printf("\tPontos Turisticos: %d\n\n", c2_pontos_turisticos);



return 0;
} 
