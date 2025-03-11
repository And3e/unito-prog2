# Debugger `gdb` GNU

## Comandi Principali

- `q`: quit
- `r`: run
- `l` (list): mostra il codice sorgente, con varie opzioni

## Print

- `p`: print `<nome-variabile> / <espressione>`
- `p list[0]@25`: stampa i primi 25 elementi di un array [list]
- `pt` (ptype): stampa il tipo di una variabile

```bash
(gdb) p var
(gdb) p &myvar
(gdb) p argv[1]
(gdb) p list[10]@5
(gdb) *(long *)0x614c20
```

## Set

- `set var  <var >= <value>`: Modifica il valore di una variabile

```bash
(gdb) set var res=4
(gdb) set var ptr = (int*)0

(gdb) set {int}0x83040 = 4
```

## Breakpoints

- `b` (break): inserisci un breakpoint
- `c` (continue): continua l'esecuzione fino ad un breakpoint
- `n` (next): esegue la prossima istruzione (**senza entrare nelle funzioni chiamate**)
- `s` (step): esegue la prossima istruzione (**entrando nelle funzioni chiamate**)
- `f` (finish): continua esecuzione fino al termine della funzione corrente

- `i b` (info breakpoints): mostra i breakpoints attuali
- `d` (delete): rimuove il breakpoint n-esimo

  - ```bash
      (gdb) d 2
    ```

- `watch <var>`: ferma l’esecuzione del programma quando il valore di una variabile (o di una espressione) nel contesto corrente cambia
  - `watch myaddr`: stop quando una locazione di memoria viene modificata
  - `i wat` (info watchpoints): mostra i watchpoint attuali
  - `display myvar`: stampa il valore di una variabile (espressione) a ogni arresto dell’esecuzione

## Operazioni sullo Stack

- `bt` (backtrace): visualizza lo stack di tutte le chiamate con i relativi argomenti
- `f <framenumber>`: seleziona un frame dello stack
- `up`: si sposta nel chiamante del frame corrente
- `down`: si sposta nel chiamato del frame corrente
- `info locals`: mostra le variabili locali del frame corrente
- `info args`: mostra gli argomenti del frame corrente 