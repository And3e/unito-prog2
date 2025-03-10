# Installazione g++ compiler

## Installazione g++ su Windows

Guida online a [questo](https://www3.cs.stonybrook.edu/~alee/g++/g++.html) sito.

## Installazione g++ su Linux (Ubuntu)

1. sudo apt install g++
2. sudo apt install build-essential

### Compilare un file .cpp da bash

```
$ g++ -o hello hello.cpp
$ ./hello
Hello, World!
```

## Installazione g++ su Mac

Guida online a [questo](http://www-scf.usc.edu/~csci104/20142/installation/gccmac.html) sito.

---

# Compilare utilizzando `makefile`

## richiamare make da `bash` o da `powershell`

```bash
make main; make run
```

### ⚠️ `powershell` richiede il comando _`make`_ installato ⚠️
1. installare [choco](https://chocolatey.org/install)
2. eseguire '`choco install make`' sulla pwsh

### lista comandi principali prendendo in riferimento il file `makefile`

```bash
make main
make clear
make run
make git
```