# Sistema de Gerenciamento de Entregas - C++
---
## 📌 Descrição
Este sistema tem como objetivo simular a logística de entregas entre locais, utilizando veículos cadastrados e permitindo o gerenciamento completo dos dados envolvidos. O projeto foi desenvolvido com foco em boas práticas de programação orientada a objetos (POO), organização modular do código e uso de validações robustas para garantir integridade dos dados.
---
## ⚙️ Funcionalidades Principais
* **CRUD de:**
  * Locais
  * Veículos
  * Pedidos
* **Simulação de entrega** entre locais, considerando autonomia dos veículos
* **Validações robustas** para:
  * Duplicidade de entradas
  * Formatos inválidos de entradas
* **Sistema de backup e restauração dos dados**
* **Persistência em arquivos binários**
---
## 👨‍💻 Desenvolvedor
*Felipe Paz Carvalho Batista*
📧 felipepaz.cb@gmail.com
[![LinkedIn](https://img.shields.io/badge/LinkedIn-0A66C2?style=flat&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/felipepazcb/)
---
## 🛠️ Tecnologias Utilizadas
* C++
* Manipulação de arquivos binários
* Programação Orientada a Objetos
---
## 🧰 Ferramentas e Colaboração
* Code::Blocks -- Ambiente de Desenvolvimento
* Git -- Controle de versão
* GitHub -- Hospedagem do repositório
---
## 📁 Estrutura do Projeto
📁 SistemaGerenciamentodeEntregas
├── 📁 include # Arquivos de cabeçalho (.h)
│ ├── Data.h
│ ├── Local.h
│ ├── ManagerLocais.h
│ ├── ManagerPedidos.h
│ ├── ManagerVeiculos.h
│ ├── Pedido.h
│ ├── Rotas.h
│ ├── Sistema.h
│ ├── Validador.h
│ └── Veiculo.h
├── 📁 src # Arquivos de implementação (.cpp)
│ ├── Data.cpp
│ ├── Local.cpp
│ ├── ManagerLocais.cpp
│ ├── ManagerPedidos.cpp
│ ├── ManagerVeiculos.cpp
│ ├── Pedido.cpp
│ ├── Rotas.cpp
│ ├── Sistema.cpp
│ ├── Validador.cpp
│ └── Veiculo.cpp
└── main.cpp # Ponto de entrada da aplicação
---
## ▶️ Como Executar o Projeto
### Pré-requisitos
* Compilador C++ instalado (g++ ou ambiente como Code::Blocks)
* Sistema operacional: Windows, Linux ou macOS

### Instruções
1. **Clone este repositório:**
```bash
git clone https://github.com/felipepcbatista/sistema-gerenciamento-de-entregas-cpp.git
cd sistema-gerenciamento-de-entregas-cpp
```
2. **Compile o projeto** com algum compilador (exemplo com g++):
```bash
g++ -I include src/*.cpp main.cpp -o sistema
```
3. **Execute o programa**
* No Windows (CMD ou PowerShell):
```bash
.\sistema.exe
```
* No Linux/macOS:
```bash
./sistema
```
4. **Fluxo esperado no terminal:**
```csharp
=====MENU PRINCIPAL=====
[1]Cadastrar Local
[2]Atualizar Local
...
[15]Carregar Dados
[0]Sair
Escolha uma opcao:
```
---
## Licença
Este projeto é livre para fins **acadêmicos**
---
