# Simulação de Fluído com SDL2

Este projeto implementa uma simulação de fluído que acompanha o cursor do mouse, utilizando a biblioteca SDL2.

## Estrutura do Projeto

fluid-simulation
├── src
│   ├── main.cpp
│   ├── fluid
│   │   ├── fluid.cpp
│   │   ├── fluid.hpp
│   │   ├── particle.cpp
│   │   └── particle.hpp
│   ├── renderer
│   │   ├── renderer.cpp
│   │   └── renderer.hpp
│   └── utils
│       ├── vector.cpp
│       └── vector.hpp
├── include
│   └── SDL2
├── lib
├── CMakeLists.txt
└── README.md
- `CMakeLists.txt`: Script de configuração do CMake.

## Instruções de Compilação

1. Certifique-se de que a biblioteca SDL2 está instalada.
2. Navegue até o diretório do projeto.
3. Execute `cmake .` para configurar o projeto.
4. Execute `make` para compilar o projeto.

## Uso

Após a compilação, execute o programa gerado. O fluído irá acompanhar o movimento do cursor do mouse na janela da aplicação.