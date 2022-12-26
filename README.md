# Trabalho-Pratico-3---AEDS1

### UPDATE NO TAD DICIONÁRIO

Neste trabalho vamos exercitar os algoritmos de ordenação estudados em sala de aula. Para isso,
utilizaremos a implementação do TAD Dicionário desenvolvido por vocês no Trabalho Prático 01 (TP01).
O TAD Dicionário disponibiliza a seu usuário todas as palavras de um dado texto de entrada separadas
por sua primeira letra. Dessa maneira são até 26 listas, cada uma delas contendo todas as palavras do
texto que se iniciam com uma determinada letra. Para cada palavra, ainda é exibida a lista de linhas do
texto na qual a mesma ocorre.

De acordo com a forma como as operações dos TADs envolvidos no desenvolvimento do TAD Dicionário
foram realizadas, é fácil perceber que a lista de linhas do texto em que cada palavra ocorre estará
naturalmente ordenada, visto que o texto é varrido sequencialmente, linha por linha, da primeira à
última. Entretanto, a lista de palavras que começam com determinada letra não necessariamente está
ordenada, justamente porque as mesmas são adicionadas ao longo do processamento sequencial do
texto, normalmente inseridas sistematicamente ao final ou ao início da lista. A não ser que elas
naturalmente apareçam ordenadas no texto, as palavras não estarão ordenadas na lista.
A ideia agora é, portanto, incrementar o TAD Dicionário com a possibilidade de, após montar as listas das
palavras separadas pela letra do alfabeto com a qual começam, oferecer ao usuário a possibilidade de
visualizá-las ordenadas (além da opção não-ordenada já implementada). Para isso, o grupo deve realizar
as seguintes ações:

Realizar uma reimplementação do TAD Lista de Palavras, usado para o desenvolvimento do TAD
Dicionário, mudando a estrutura de dados utilizada de lista encadeada para vetor;
Implementar um método de ordenação para cada algoritmo visto em sala de aula (bolha,
seleção, inserção, shellsort, quicksort, heapsort), que receba como entrada uma uma Lista de
Palavras (cópia), e faça a ordenação das palavras da lista conforme a lógica de cada um deles;
Inserir no TAD Dicionário uma operação que possibilita ao usuário exibir a lista de palavras que
começam com determinada letra ordenada, escolhendo ainda qual método de ordenação usar.
Nesse caso, o método correspondente à ordenação escolhida será chamado, recebendo uma 
cópia da lista a ser ordenada. A cópia da lista é ordenada e exibida para o usuário. A lista original
permanece não ordenada;
Inserir no TAD Dicionário uma operação que possibilita ao usuário exibir todo o dicionário com
as listas de palavras ordenadas, escolhendo o método de ordenação a ser utilizado. Nesse caso,
o método correspondente à ordenação escolhida será chamado para cada uma das até 26 listas
do alfabeto. As listas originais continuam não ordenadas;
Atualizar o sistema de teste, de maneira a permitir acesso às duas novas operações
disponibilizadas pelo TAD Dicionário;
Para cada chamada às operações que exibem uma lista de palavras por letra ordenada ou todo o
dicionário ordenado, deverá ser exibido ao usuário o número de comparações feitas, o número
de movimentações realizadas e o tempo total gasto com a operação.

### TESTES

Dois arquivos texto serão disponibilizados para os alunos para realização de testes durante o
desenvolvimento. Além desse, um outro arquivo será utilizado no dia das entrevistas para avaliação dos
trabalhos.
O grupo deverá utilizar o sistema para executar a operação de exibir cada uma das listas de palavras que
começam com determinada letra do alfabeto ordenada, para cada um dos algoritmos implementados e
usando os dois arquivos texto fornecidos. Para cada método de ordenação e arquivo, apresente a média
do número de comparações, movimentações e tempo gasto, calculada com os valores obtidos para cada
lista. Em seguida, faça o mesmo para a operação que mostra todo o dicionário ordenado, isto é, mostre
para cada método de ordenação e arquivo, o número de comparações, movimentações e tempo gasto.
