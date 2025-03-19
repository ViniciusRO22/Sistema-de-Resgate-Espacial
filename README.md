### Resgate Espacial em Órbita

### Descrição do Projeto
 Este projeto simula um resgate espacial em órbita, envolvendo módulos de uma estação espacial que foram atingidos por uma chuva de meteoros, astronautas e um robô de resgate. O sistema utiliza programação orientada a objetos em C++ para estruturar os componentes do resgate e sempre fornece o melhor caminho de resgate possível utilizando o metodo de busca BFS.

### Estrutura do Projeto
O projeto é composto pelos seguintes arquivos:
- `Astronauta.cpp` / `Astronauta.hpp`
- `EstacaoEspacial.cpp` / `EstacaoEspacial.hpp`
- `Modulo.cpp` / `Modulo.hpp`
- `ModuloComAstronauta.cpp` / `ModuloComAstronauta.hpp`
- `ModuloComFogo.cpp` / `ModuloComFogo.hpp`
- `ModuloNormal.cpp` / `ModuloNormal.hpp`
- `ModuloObstaculo.cpp` / `ModuloObstaculo.hpp`
- `ModuloSeguranca.cpp` / `ModuloSeguranca.hpp`
- `ModuloVazio.cpp` / `ModuloVazio.hpp`
- `ResgateEspacial.cpp` / `ResgateEspacial.hpp`
- `RoboDeResgate.cpp` / `RoboDeResgate.hpp`

### Outros arquivos
- `Diagrama de Classes.png`: Representa a estrutura das classes do projeto.
- `entradaX.txt`: Arquivos de entrada para testar o sistema, contendo a matriz de modulos a ser utilizada no resgate e as informações dos astronautas. 

## Como Compilar e Executar
Para compilar o projeto, utilize um compilador C++ como o g++. Um exemplo de compilação:
```sh
 g++ -o resgate ResgateEspacial.cpp EstacaoEspacial.cpp RoboDeResgate.cpp Modulo.cpp ModuloComAstronauta.cpp ModuloComFogo.cpp ModuloNormal.cpp ModuloObstaculo.cpp ModuloSeguranca.cpp ModuloVazio.cpp Astronauta.cpp 
```

Para executar:
```sh
 ./resgate
```

## Autor
- Vinícius Ramalho


