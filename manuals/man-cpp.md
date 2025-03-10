# Marguerettaz André

## Info

- Autore: André Marguerettaz
- Classe 4B IT
- A/S: 2022/2023

### Descrizione

Manuale c++ tratto da esercizi svolti durante l'anno.

---

## Guide online

- [Compilatore GNU](http://www-old.bo.cnr.it/corsi-di-informatica/corsoCstandard/Lezioni/16Linuxgcc.html)
- [Comando make](http://www-old.bo.cnr.it/corsi-di-informatica/corsoCstandard/Lezioni/17Linuxmake.html)

## Compilare da bash/shell

### Creare i file oggetto

1. Creo `main.o`

```bash
g++ -c main.cpp -Wall
```

2. Creo `myfunc.o`

```bash
g++ -c myfunc.cpp -Wall
```

### Creare il file eseguibile

3. Creo `Nomefile.exe`

```bash
g++ -o <Nomefile> main.o myfunc.o -Wall
```

### Comando unico

`3` passaggi in `1` riga di comando

```bash
g++ -c main.cpp -Wall; g++ -c myfunc.cpp -Wall; g++ -o <Nomefile> main.o myfunc.o  -Wall; ./<Nomefile>; echo $?
```

---

### Utilizzare `makefile`

`source di makefile`

```bash
<Nomefile>: myfunc.o main.o
   g++ -o <Nomefile> main.o myfunc.o -Wall
myfunc.o: myfunc.h myfunc.cpp
   g++ -o myfunc.o -c myfunc.cpp -Wall
main.o: myfunc.h main.cpp
   g++ -o main.o -c main.cpp -Wall
clear:
   rm -f \*.o <Nomefile>
run:
   ./<Nomefile>; echo $?
```

`richiamare make da bash`

tutti i comandi disponibili prendendo in riferimento il file `makefile`

```bash
make <Nomefile>
make myfunc.o
make main.o
make clear
make run
```

### Eseguire programma da terminale in modo automatico

mettere in `echo "n"` tutti gli inserimenti

```bash
echo "1 2 3"|.\main.exe
```
