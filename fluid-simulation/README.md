# Simulação de Fluído com SDL2

Este projeto implementa uma simulação de fluído que acompanha o cursor do mouse, utilizando a biblioteca SDL2.

## Estrutura do Projeto

- `src/main.cpp`: Ponto de entrada da aplicação.
- `src/fluid/`: Contém a implementação da simulação do fluído e das partículas.
- `src/renderer/`: Responsável pela renderização do fluído e das partículas.
- `src/utils/`: Funções utilitárias para manipulação de vetores.
- `include/SDL2`: Arquivos de cabeçalho da biblioteca SDL2.
- `lib/`: Bibliotecas externas utilizadas no projeto.
- `CMakeLists.txt`: Script de configuração do CMake.

## Instruções de Compilação

1. Certifique-se de que a biblioteca SDL2 está instalada.
2. Navegue até o diretório do projeto.
3. Execute `cmake .` para configurar o projeto.
4. Execute `make` para compilar o projeto.

## Uso

Após a compilação, execute o programa gerado. O fluído irá acompanhar o movimento do cursor do mouse na janela da aplicação.