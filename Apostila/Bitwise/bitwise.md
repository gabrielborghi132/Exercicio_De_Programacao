













# Apostila: Bitmask do zero

## 1. O que é uma bitmask?

Uma **bitmask** (ou máscara de bits) é uma maneira de representar vários valores de “ligado/desligado” usando os bits de um número inteiro.

Imagine que temos elementos identificados pelos índices `0`, `1`, `2` e `3`. Cada elemento corresponde a um bit:

| Elemento | Índice do bit |
|---|---:|
| Primeiro | 0 |
| Segundo | 1 |
| Terceiro | 2 |
| Quarto | 3 |

Um bit igual a `1` significa que o elemento correspondente está presente; um bit igual a `0` significa que está ausente.

> Os bits são numerados da direita para a esquerda. O bit mais à direita é o bit 0.

Por exemplo, `0101₂` tem ligados os bits 0 e 2. Portanto, representa o conjunto `{0, 2}`. O símbolo `{0, 2}` significa simplesmente “o conjunto que contém os elementos 0 e 2”. A máscara `0101₂`, em decimal, vale `5`.

| Máscara binária | Conjunto representado | Valor decimal |
|---|---|---:|
| `0000` | `{}` | 0 |
| `0001` | `{0}` | 1 |
| `0101` | `{0, 2}` | 5 |
| `1111` | `{0, 1, 2, 3}` | 15 |

Com `n` bits podemos representar todos os subconjuntos de `n` elementos. Há `2ⁿ` máscaras possíveis, pois cada elemento pode estar presente ou ausente.

## 2. Binário e índices dos bits

Em uma máscara como `110₂`, o bit mais à direita é o índice 0:

```text
bits:    1  1  0
índices: 2  1  0
```

Logo, `110₂` representa `{1, 2}`. O valor decimal da máscara é `6`, mas o conjunto representado contém os índices 1 e 2.

Em C++, podemos escrever números binários usando o prefixo `0b`, por exemplo `0b101`.

## 3. Operadores bit a bit

Os operadores trabalham em cada posição binária correspondente.

| Operador | Nome | Resultado de cada bit |
|---|---|---|
| `&` | AND | `1` somente se os dois bits forem `1` |
| `\|` | OR | `1` se pelo menos um dos bits for `1` |
| `^` | XOR | `1` se os bits forem diferentes |
| `~` | NOT | Inverte os bits |
| `<<` | deslocamento à esquerda | Desloca bits para a esquerda |
| `>>` | deslocamento à direita | Desloca bits para a direita |

### AND (`&`): interseção e teste de bit

Se `A = 101₂` e `B = 110₂`:

```text
  101
& 110
-----
  100
```

O resultado `100₂` representa `{2}`, o elemento comum aos dois conjuntos.

Para testar se o bit `i` está ligado em `mask`, usamos:

```cpp exemplo.cpp
bool ligado = (mask & (1 << i)) != 0;
```

`1 << i` cria uma máscara que tem somente o bit `i` ligado. Por exemplo, `1 << 2` resulta em `100₂`.

### OR (`|`): união

OR liga um bit se ele estiver ligado em pelo menos um dos operandos:

```text
  101
| 110
-----
  111
```

`101₂ | 110₂` representa a união `{0, 1, 2}`.

### XOR (`^`): alternar um bit

XOR resulta em `1` quando os bits são diferentes. Aplicar XOR com um bit ligado alterna esse bit: se era `0`, passa a `1`; se era `1`, passa a `0`.

### NOT (`~`): inverter bits

NOT inverte os bits. Em C++, inteiros têm uma largura fixa, e `~x` também inverte bits além dos que estamos usando para representar o conjunto. Por isso, ao calcular diferenças, combine o resultado com a máscara que limita os elementos de interesse, como em `A & ~B`.

## 4. Ligar, desligar, alternar e testar um elemento

Para ligar, desligar ou alternar o bit `i`:

```cpp exemplo.cpp
mask |= (1 << i);        // liga o bit i
mask &= ~(1 << i);       // desliga o bit i
mask ^= (1 << i);        // alterna o bit i
bool tem = mask & (1 << i); // testa se o bit i está ligado
```

Os operadores com `=` atualizam a própria variável. Por exemplo, `mask |= (1 << i)` equivale a `mask = mask | (1 << i)`.

Se começarmos com `mask = 0` e ligarmos os bits 0 e 2, obtemos `0101₂`, que vale 5 e representa `{0, 2}`:

```cpp exemplo.cpp
long long mask = 0;
mask |= (1LL << 0);
mask |= (1LL << 2);
```

### Cuidado com o tipo do deslocamento

Em C++, `1 << i` usa um `int`. Se `i` for grande, o deslocamento pode exceder o limite do tipo. Para máscaras maiores, use `1LL << i` e um tipo `long long`, respeitando também a largura desse tipo. Para problemas com poucos elementos, como `n` até aproximadamente 20, `int` costuma ser suficiente.

## 5. Percorrer todas as máscaras

Com `n` elementos, as máscaras vão de `0` até `2ⁿ - 1`. Assim, podemos percorrer todos os subconjuntos:

```cpp exemplo.cpp
#include <iostream>
using namespace std;

int main() {
    int n = 3;

    for (int mask = 0; mask < (1 << n); ++mask) {
        // Aqui mask representa um dos 2^n subconjuntos.
        cout << mask << '\n';
    }
}
```

Para `n = 3`, são oito máscaras: `000`, `001`, `010`, `011`, `100`, `101`, `110` e `111`.

Para mostrar quais índices pertencem a cada máscara, testamos cada bit:

```cpp exemplo.cpp
#include <iostream>
using namespace std;

int main() {
    int n = 3;

    for (int mask = 0; mask < (1 << n); ++mask) {
        cout << "mask " << mask << ": {";
        bool primeiro = true;

        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                if (!primeiro) cout << ", ";
                cout << i;
                primeiro = false;
            }
        }

        cout << "}\n";
    }
}
```

Se também percorremos os `n` bits de cada máscara, a complexidade é `O(n · 2ⁿ)`. Isso é útil quando `n` é pequeno, porque `2ⁿ` cresce rapidamente.

## 6. Operações entre conjuntos

Considere `A = 101₂ = {0, 2}` e `B = 110₂ = {1, 2}`.

| Expressão | Resultado em binário | Conjunto | Significado |
|---|---|---|---|
| `A \| B` | `111` | `{0, 1, 2}` | União: está em A ou em B |
| `A & B` | `100` | `{2}` | Interseção: está em A e em B |
| `A & ~B` | `001` | `{0}` | Diferença: está em A, mas não em B |

Para entender `A & ~B`, considere somente três bits:

```text
A       = 101
B       = 110
~B      = 001   (considerando três bits)
A & ~B  = 001
```

O elemento 2 está em ambos os conjuntos e é removido de A; sobra o elemento 0.

Outro exemplo: `111 & ~010 = 101`. Remover o elemento 1 de `{0, 1, 2}` deixa `{0, 2}`.

## 7. Contar elementos ligados: `popcount`

Em C++20, `std::popcount` conta quantos bits estão ligados. Para usá-lo, inclua `<bit>`:

```cpp exemplo.cpp
#include <bit>
#include <iostream>
using namespace std;

int main() {
    unsigned int mask = 0b10101;
    cout << popcount(mask) << '\n'; // 3
}
```

A máscara `10101₂` tem três bits ligados e representa três elementos.

## 8. Submáscaras

Uma **submáscara** de `mask` é uma máscara cujos bits ligados também estão ligados em `mask`. Pensando em conjuntos, uma submáscara representa um subconjunto.

Por exemplo, `110₂` representa `{1, 2}`. Suas submáscaras são:

- `110₂` → `{1, 2}`;
- `100₂` → `{2}`;
- `010₂` → `{1}`;
- `000₂` → `{}`.

A máscara original e a máscara vazia também contam como submáscaras. `101₂` não é submáscara de `110₂`, porque o bit 0 está ligado em `101`, mas desligado em `110`.

### Enumerar todas as submáscaras

A fórmula `(sub - 1) & mask` encontra a próxima submáscara:

```cpp exemplo.cpp
int mask = 0b101;

for (int sub = mask; ; sub = (sub - 1) & mask) {
    // Processa sub.

    if (sub == 0) break;
}
```

Para `mask = 101₂`, a sequência é `101 → 100 → 001 → 000`.

Para `mask = 110₂`, é `110 → 100 → 010 → 000`.

Para `mask = 1011₂`, é `1011 → 1010 → 1001 → 1000 → 0011 → 0010 → 0001 → 0000`.

O `break` é importante para processar o zero uma vez e encerrar o laço. Se `mask` tem `k` bits ligados, existem `2ᵏ` submáscaras, incluindo zero.

## 9. Percorrer apenas os bits ligados

Uma maneira simples de encontrar os índices dos bits ligados é testar todos os índices de `0` a `n - 1`. Outra técnica percorre somente os bits que estão ligados.

Em C++20, `std::countr_zero(mask)` retorna o número de zeros à direita, que é o índice do bit ligado mais à direita. A expressão `mask &= mask - 1` remove esse bit.

```cpp exemplo.cpp
#include <bit>
#include <iostream>
using namespace std;

int main() {
    unsigned int mask = 0b10110;

    while (mask != 0) {
        int indice = countr_zero(mask);
        cout << indice << ' ';
        mask &= mask - 1;
    }
}
```

A saída é `1 2 4`, pois `10110₂` representa `{1, 2, 4}`. Se há `k` bits ligados, o laço executa `k` vezes. A condição `mask != 0` evita chamar `countr_zero` com zero.

## 10. Máscara para escolher elementos de um array

Uma aplicação comum é usar o bit `i` para dizer se o elemento `a[i]` foi escolhido. Para `a = {3, 5, 2}` e `mask = 101₂`, escolhemos os índices 0 e 2, ou seja, os valores 3 e 2.

```cpp exemplo.cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> a = {3, 5, 2};
    int n = a.size();

    for (int mask = 0; mask < (1 << n); ++mask) {
        int soma = 0;

        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) {
                soma += a[i];
            }
        }

        cout << "mask = " << mask << ", soma = " << soma << '\n';
    }
}
```

A máscara `110₂` seleciona os índices 1 e 2. No array `{3, 5, 2}`, isso corresponde a `5` e `2`, cuja soma é `7`.

O programa percorre `2ⁿ` subconjuntos e examina até `n` posições para cada um: complexidade `O(n · 2ⁿ)`. Por isso, essa técnica é indicada principalmente para `n` pequeno.

## 11. Resumo das operações mais usadas

| Objetivo | Expressão |
|---|---|
| Criar uma máscara só com o bit `i` ligado | `1 << i` ou `1LL << i` |
| Testar o bit `i` | `(mask & (1 << i)) != 0` |
| Ligar o bit `i` | `mask |= (1 << i)` |
| Desligar o bit `i` | `mask &= ~(1 << i)` |
| Alternar o bit `i` | `mask ^= (1 << i)` |
| Contar bits ligados (C++20) | `popcount(mask)` |
| Remover o bit ligado mais à direita | `mask &= mask - 1` |
| Obter a próxima submáscara | `(sub - 1) & mask` |

## 12. Ideias para lembrar

1. O bit mais à direita é o índice 0.
2. Uma máscara representa quais elementos estão presentes em um conjunto.
3. A máscara `101₂` representa `{0, 2}`, não o conjunto `{1, 0, 1}`.
4. Para `n` elementos há `2ⁿ` máscaras.
5. `&` testa/intersecta; `|` une; `^` alterna bits.
6. Uma submáscara só pode ter bits que também existem na máscara original.
7. Ao enumerar todas as submáscaras, não esqueça de tratar o zero para evitar um laço infinito.
8. Ao usar deslocamentos, escolha um tipo que comporte o bit deslocado.

## Exercícios de revisão

1. Quais elementos são representados por `110₂`?
2. Qual é o valor decimal de `101₂`?
3. Se `mask = 0` e ligamos os bits 0 e 2, qual é a máscara binária e seu valor decimal?
4. Quais são as submáscaras de `101₂`?
5. Quais índices são escolhidos por `mask = 110₂` para o array `{3, 5, 2}`? Qual é a soma dos valores escolhidos?
6. Para `A = 111₂` e `B = 010₂`, o que representa `A & ~B`?

### Respostas

1. `{1, 2}`.
2. `5`.
3. `101₂`, que vale `5`.
4. `101`, `100`, `001` e `000`.
5. Índices 1 e 2; valores 5 e 2; soma 7.
6. `101₂`, ou seja, `{0, 2}`.

## 13. Outros fundamentos importantes

### Operadores bit a bit e lógicos

`&` e `|` operam nos bits; `&&` e `||` combinam condições booleanas. Para testar um bit, use `&`:

```cpp exemplo.cpp
bool ligado = (mask & (1 << i)) != 0;
```

Por exemplo, `mask && (1 << i)` não verifica se o bit `i` está ligado: apenas verifica se os dois valores são diferentes de zero.

### XOR e deslocamento à direita

- `A ^ B` mantém os bits presentes em exatamente uma das máscaras (diferença simétrica).
- `x ^ x == 0` e `x ^ 0 == x`.
- `mask ^= (1 << i)` alterna o bit `i`.
- `(mask >> i) & 1` extrai o valor do bit `i`.

### Testes úteis

Para verificar se `sub` é submáscara de `mask`, todos os bits de `sub` devem estar em `mask`:

```cpp exemplo.cpp
bool eh_submascara = (sub & mask) == sub;
```

Para complementar uma máscara considerando apenas `n` bits, limite o resultado com uma máscara completa:

```cpp exemplo.cpp
unsigned int full_mask = (1u << n) - 1;
unsigned int complemento = full_mask ^ mask;
```

Use isso somente se `n` couber na largura do tipo. O operador `~mask` sozinho inverte todos os bits do tipo, não apenas os `n` bits do conjunto.

Se `x > 0`, ele é potência de 2 quando tem um único bit ligado:

```cpp exemplo.cpp
bool eh_potencia_de_dois = x != 0 && (x & (x - 1)) == 0;
```

Os parênteses são importantes por causa da precedência dos operadores em C++.

### Isolar o bit ligado mais à direita

Com um inteiro sem sinal, `mask & -mask` deixa ligado somente o bit 1 mais à direita. Para percorrer os bits ligados, pode-se isolar e remover um por vez:

```cpp exemplo.cpp
while (mask != 0) {
    unsigned int bit = mask & -mask;
    int indice = countr_zero(bit); // requer <bit>, C++20
    mask -= bit;
}
```

Se `mask == 0`, não há bit ligado; não chame `countr_zero` com zero. Outra forma de remover o bit mais à direita é `mask &= mask - 1`.

### Largura e deslocamentos

`1 << i` usa `int`; em plataformas comuns de Codeforces, prefira índices até 30. Para máscaras maiores, use `1LL << i` e respeite a largura de `long long` (normalmente índices até 62 para manter o resultado positivo). Nunca desloque por uma quantidade igual ou maior que a largura do tipo. Mesmo quando o tipo comporta a máscara, percorrer `2ⁿ` estados pode ser inviável.

---

Esta apostila resume os fundamentos estudados. O próximo passo, quando esses padrões estiverem firmes, é usar bitmasks em **programação dinâmica sobre subconjuntos (DP com bitmask)**.




























