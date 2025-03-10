# Utils bash/shell

## Compilare da bash/shell

**già presente nella cartella [`../cpp/`](https://gitlab.com/san.marguerettaz/4bit_marguerettaz/-/tree/main/cpp)**

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

3. Creo `<Nomefile>.exe`

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

## Creare/modificare un file

```bash
nano <Nomefile>
```

## Scarica da link

```bash
wget <url>
```

## Trova le differenze

```bash
diff <file1> <file2>
```
