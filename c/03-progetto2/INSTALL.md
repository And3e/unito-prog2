# Installazione `gcc` Compiler

## Installazione `gcc` su Windows

Guida online a [questo](https://www3.cs.stonybrook.edu/~alee/g++/g++.html) sito. (Anche valido per `gcc`).

## Installazione `gcc` su Linux (Ubuntu)

1. ```bash
   sudo apt install gcc
   ```

2. ```bash
   sudo apt install build-essential
   ```

### Compilare un file `.c` da bash

```bash
$ gcc -o hello hello.c
$ ./hello
Hello, World!
```

## Installazione `gcc` su Mac

Guida online a [questo](http://www-scf.usc.edu/~csci104/20142/installation/gccmac.html) sito.

---

# Compilare utilizzando `makefile`

## Richiamare `make` da bash o da PowerShell

```bash
make main; make run
```

#### ⚠️ `PowerShell` richiede il comando _`make`_ installato ⚠️

### Lista comandi principali prendendo in riferimento il file `makefile`

```bash
make main   # Compila il file principale
make clear  # Pulisce i file compilati
make run    # Esegue il programma compilato
make git    # Aggiorna il repository Git
```