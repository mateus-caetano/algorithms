# QxdAlgoritmos

## Objetivo

Seu objetivo é implementar os algoritmos e estruturas de dados vistos na disciplina. Você irá construir uma espécie de biblioteca, seguindo a API definida pelos arquivos que já estão nesse repositório.

## Instruções

Os algoritmos e as estruturas estão organizadas nos arquivos de cabeçalho disponibilizados. Seu trabalho consiste em implementar *todas* as funções contidas nesses arquivos, juntamente com quaisquer outras que você necessitar.

Cada arquivo `.h`, à exceção do `qxddefs.h` deve ter um correspondente `.c` onde você implementará as funções correspondentes. Note que inclusive os tipos abstratos de dados precisam ser definidos (o que significa que é preciso incluir a descrição de seus campos). Isso também deverá ser feito nos arquivos `.c` pertinentes.

Os arquivos de cabeçalho **não devem** ser alterados! Quais quer funções auxiliares devem ser incluidas apenas nos arquivos de implementação.

O arquivo `main.c` pode ser usado para você testar o funcionamento das suas implementações.

## Documentação

Cada função definida nos cabeçalhos foi documentada com a descrição do que elas esperam como parâmetros e quais são seus comportamentos. Essa documentação está nos próprios arquivos, porém foi feita em um formato que permite a geração de documentação interativa. A versão em html dessas mesmas descrições está no arquivo `index.html` dentro da pasta `docs`.

## Informações

A cada novo assunto que virmos nas aulas, esse repositório será atualizado. Assim, verifique de vez em quando se algum arquivo foi adicionado.

Note, também, que a nomenclatura de algoritmos e estruturas usadas nos arquivos deste repositório não necessariamente é a mesma que usamos na sala. Aqui tentamos usar nomes baseados nos já convencionados por várias linguagens. Por exemplo, usamos o nome `vector`para nos referirmos a uma *lista sequencial* e `list` para *lista (simplesmente) encadeada*.

### Atualização
Para obter as atualizações feitas nos arquivos deste projeto e importá-las para a sua versão, siga os passos a seguir:

0. Acesse a página da sua versão do projeto no Github.
0. Verifique na barra acima da listagem de arquivos se há alguma referência a "_commits behind_". Se houver, isso 
  significa que houve atualização dos arquivos no projeto principal.
  
#### Via navegador
0. Havendo atualização, [clique neste link](https://github.com/UFCQXD-ED-2018-2/ed-qxdalgo/compare/master) para 
acessar a página onde você importará as mudanças.
0. Abaixo do título da página ("_Comparing changes_"), você deve encontrar um link rotulado como "_compare across 
forks_". Clique nesse link.
0. Observe que a barra logo abaixo desse link mudou. Procure a caixa que contém a sentença "_base fork_" (deve ser a 
primeira caixa à esquerda), e nela selecione o seu projeto.
0. Aguarde um pouco até que apareça logo abaixo dessas caixas a mensagem "_Able to merge_". Então, clique no botão 
"_Create pull request_".
0. Nos campos "_Title_" e "_Leave a comment_" que aparecerem, preencha com "Atualização do projeto".
0. Clique novamente no botão "_Create pull request_".
0. Na página que for carregada, procure pelo botão "_Merge pull request_", clique nele e então em "_Confirm merge_.
0. Pronto, o código foi atualizado na sua versão do projeto _no Github_. Agora você deve importar essas alterações 
  para a versão que você está editando no seu computador.
  
**Caso algum dos passos acima tenha falhado, entre em contato enviando informações sobre o que falhou e capturas de
tela relacionadas.**
  
#### Via terminal
0. Num terminal, entre na pasta que hospeda o seu projeto no seu computador.
0. Execute o comando a seguir para verificar se ainda existem alterações não submetidas na sua versão.

       git status
0. Caso existam, finalize as alterações necessárias, salve-as (`commit`) e só então continue.
0. (Caso você não tenha feito ainda,) insira a informação sobre o projeto principal no seu projeto executando o comando

       git remote add upstream git@github.com:UFCQXD-ED-2018-2/ed-qxdalgo.git
0. Execute o comando a seguir para obter as alterações do projeto principal e, simultaneamente, inserí-las na sua 
versão.

       git pull upstream
0. Pronto, você atualizou a sua versão do projeto no seu computador. Não se esqueça de enviá-la para o _Github_ (`push`).

**Caso algum erro tenha acontecido e você não consiga resolver ou não saiba como, procure um monitor ou a mim.**

       

## Compilação

Para compilar este projeto, basta incluir todos os arquivos `.c`. Alternativamente, você pode importar a pasta que contém este arquivo `README` como um projeto no [*CLion*](https://www.jetbrains.com/clion).

## Entrega

A implementação desses códigos deve ser individual e a entrega consiste em subir suas implementações para este repositório usando a ferramenta `git` ou qualquer visualização gráfica deste. Sugerimos o programa [gitkraken](https://www.gitkraken.com/).