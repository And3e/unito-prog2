# Appunti Programmazione II

## Malloc

Permette di allocare dinamicamente (durante l’esecuzione del programma) una quantità di memoria specificata

```c
cast-type *ptr;

ptr = (cast-type *) malloc(byte-size);
```

- `cast-type`: Tipologia di variabilem (`int`, `float`, `char`, etc.)
- `byte-size`: Dimensione di memoria da allocare [in `byte`]

### Esempio

```c
int *x;
x = (int *) malloc (sizeof (int));
```

- `malloc` restituisce `*void` (fare poi il cast)
- `sizeof` resituisce la dimensione in `byte`

### Allocazione di un Array

```c
int astatico[N];

int *adinamico=(int *)malloc(sizeof(int)*N);
```

`astatico` e `adinamico` possono essere usati allo stesso identico modo.

## Free

Permette di liberare dinamicamente [`deallocare`] (durante l’esecuzione del programma) della memoria precedentemente allocata in maniera dinamica.

Dopo `free` tale memoria non sarà più accessibile

```c
cast-type *ptr;

ptr = (cast-type *) malloc(byte-size);

free(ptr);
```

### Esempio

```c
int *x;
x = (int *) malloc (sizeof (int));

free(x);
```

### Deallocazione di un Array

Per evitare `dangling pointers` (puntatori pendenti), è buona pratica assegnare `NULL` al puntatore dopo la free, come correttamente mostrato nel codice:

```c
free(array);

array = NULL;
```

---

## Memoria Statica / Dinamica

| STATICA - `tempo`                                | DINAMICA - `spazio`                   |
| ------------------------------------------------ | ------------------------------------- |
| ➔ accesso più rapido                             | ➔ accesso meno rapido                 |
| ➔ occupo memoria anche per variabili che non uso | ➔ occupo solo la memoria che mi serve |

---

## Tipi composti

- **`array mono e multi-dimensionali`**: tutti gli elementi sono omogenei (dello stesso tipo)
- **`strutture`**: gli elementi possono essere disomogenei (di tipi diversi)
- **`unioni`**: la variabile ha più vesti, può essere alternativamente di un tipo o di un altro

---

## Strutture

```c
struct libro {
  char titolo[MAXT];
  int pagine;
  char autore[MAXN];
  float prezzo;
};

struct libro l1; // creo una variabile `l1` di tipologia `libro`
```

### Strutture in memoria - `padding`

![Padding](imgs/padding.png)

I sistemi operativi non allocano la memoria a byte ma a gruppi di `4, 8, 16 ... byte`

```c
struct s {
  char x;
  char y;
  int z;
};

sizeof(struct s) = 8

sizeof(char)*2 + sizeof(int) = 6
```

### `typedef`

Spesso struct viene usato insieme a `typedef`

```c
typedef struct {
  char titolo[MAXT];
  int pagine;
  char autore[MAXN];
  float prezzo;
} libro; // nuovo tipo `libro`

libro l1; // variabile `l1` di tipo `libro`
```

### Deallocazione di una struct

```c
libro * l;

l = (libro *) malloc(sizeof(libro);

free(l);
l = NULL;
```

! Ricordarsi `l = NULL`

### Differenza tra `.` e `->`

- Si usa `.` quando si ha a che fare con **VARIABILI**
- Si usa `->` quando si ha a che fare con **PUNTATORI**

```c
typedef struct {
  int n;
} str;


str s1;
s1.n = 1;

// ----------

str *s2 = (str*) malloc(sizeof(str));;
s2->n = 1;
```

### Liste Concatenate (linkate)

Creazione di una lista da 3 elementi

1. Dichiarazione

   ```c
   typedef struct nodo {
     int a;
     float b;
     char c;

     struct nodo* next;
   } nodo;

   typedef nodo* lista;
   ```

2. Assegnazione

   ```c
   lista head = malloc(sizeof(nodo));

   head->a = 1;
   head->b = 1.1;
   head->c = 'A';
   head->next = NULL;

   // Creazione del secondo nodo
   lista secondo = malloc(sizeof(nodo));

   secondo->a = 2;
   secondo->b = 2.2;
   secondo->c = 'B';
   secondo->next = NULL;
   head->next = secondo; // Collegamento del primo al secondo nodo

   // Creazione del terzo nodo
   lista terzo = malloc(sizeof(nodo));

   terzo->a = 3;
   terzo->b = 3.3;
   terzo->c = 'C';
   terzo->next = NULL;
   secondo->next = terzo; // Collegamento del secondo al terzo nodo
   ```

3. Visualizzazione

   ```c
   // Stampa della lista
   lista temp = head;
   while (temp != NULL) {
     printf("Nodo: a=%d, b=%.1f, c=%c\n", temp->a, temp->b, temp->c);
     temp = temp->next;
   }
   ```

4. Deallocazione
   ```c
   while (head != NULL) {
     lista temp = head;
     head = head->next;
     free(temp);
   }
   ```

![alt text](imgs/liste.png)

5. Eliminare un elemento della lista

   Per eliminare un elemento della lista, bisogna cambiare il valore della variabile `next`, facendo puntare il puntatore ad un altro elemento della lista.

   Ricordarsi poi di fare la `free()` per deallocare l'elemento della lista ormai superfluo

   ```c
   void cancella_testa(lista *L) {
     lista tmp = (*L);
     *L = (*L)->next;
     free(tmp);
   }
   ```

   ![Elimina primo elemento dalla lista](imgs/elimina-elemento.png)

6. Aggiungere un elemento in testa

   ```c
   void aggiungi_in_testa(lista *L, lista nuovo) {
     nuovo->next = *L;
     *L = nuovo;
   }
   ```

   ![Aggiungi elemento nella testa della lista](imgs/aggiungi-elemento.png)

#### Tipologie di liste

![Tipi di liste](imgs/tipi-liste.png)

### Funzioni `ricorsive` su liste

Esempio:

```c
int somma_nodi(lista l) {
  if (l == NULL) return 0;
  return (l->dato + somma_nodi(l->next));
}
```

Controparte iterativa:

```c
int somma_iter(lista l) {
  int ris = 0;

  while (l) {
    ris += l->dato;
    l = l->next;
  }

  return ris;
}
```

#### RICORSIONE in `testa`/`coda`

**`TESTA`**

```c
tipo-ritorno FUNZIONE(params …) {
  if (test-caso-base1) ... return1
  ...

  else {
    [vrb-temp =] FUNZIONE(...); // prima richiamo ricorsivo
    elabora nodo corrente // poi elaboro il nodo corrente
    return ...
  }
}

// ESEMPIO
void stampa(lista l) {
  if (l != NULL) {
    printf(" %d,", l->dato); // elaboro nodo
    stampa(l->next); // ricorsione sul next
  }
  else printf(" /\n");
}
```

**`CODA`**

```c
tipo-ritorno FUNZIONE(params …) {
  if (test-caso-base1) ... return1
  ...

  else {
    elabora nodo corrente // prima elaboro il nodo corrente
    [vrb-temp =] FUNZIONE(...); // poi richiamo ricorsivo
    return ...
  }
}

// ESEMPIO
void stampa_inversa(lista l) {
  if (l != NULL) {
    stampa_inversa(l->next); // ricorsione sul next
    printf(" %d,", l->dato); // elaboro nodo
  }
  else printf(" /\n");
}
```

#### Ricorsione in `testa`/`coda` con valore di ritorno

**Richiamo in `testa`**

```c
int conta(lista L, int S) {
  if (!L) return 0;
  else if (L->peso >= S) return 0;
  else {
    int temp = conta(L->next,S);
    return (1 + temp);
  }
}
```

**Richiamo in `coda`**

```c
int conta2(lista l, int S) {
  if (!l) return 0; // (1) caso base lista vuota
  else if (l->peso >= S) return 0; // (2) caso base non ho altro da contare

  return (1 + conta2(l->next, S));
}
```

##### Rimozione in `coda` con ricorsione in `testa`

**Lista passata per riferimento**

```c
void elimina_lista(lista *l) {
  if (l) {
    if (*l) { // se la lista non è vuota
      elimina_lista(&((*l)->next)); // mi sposto avanti
      free(*l); // libero il nodo (attuale ultimo)
      *l = NULL;
    }
  }
}
```

**Lista passata per valore**

```c
lista elimina_lista(lista l) {
  if (l) {
    l->next=elimina_lista(l->next);
    free(l);
    return NULL;
  }

  return NULL;
}
```

##### Inserimento di un elemento nella lista [ORDINATA]

**Lista passata per valore**

```c
lista inserimento_ordinato(lista l, lista nodo) {
  if (l) {
    if (nodo->dato <= l->dato) {
      // nodo inserito nella prima posizione
      nodo->next = l;
      return nodo;
    } else if (nodo->dato < l->next->dato) {
      // nodo maggiore di `l` e minore di `l->next`
      nodo->next = l->next;
      l->next = nodo;
      return l;
    } else {
      // nodo maggiore sia di `l` sia di `l-next`
      // non sono nella posizione giusta, ricorsione
      l->next = inserimento_ordinato(l->next, nodo);
      return l;
    }
  }

  return nodo;
}
```

**Lista passata per riferimento**

```c
void inserimento_ordinato(lista *l, lista nodo) {
  if (l) {
    if (*l) {
      if (nodo->dato <= (*l)->dato) {
        // nodo va inserito in prima posizione
        nodo->next = *l;
        *l = nodo;
      } else if (!((*l)->next)) {
        // `l` ultimo e nodo maggiore di `l`, diventa lui l'ultimo
        (*l)->next = nodo;
        nodo->next = NULL;
      } else if (nodo->dato < (*l)->next->dato) {
        // nodo maggiore di `l` e minore di `l->next`
        nodo->next = (*l)->next;
        (*l)->next = nodo;
      } else {
        // nodo maggiore sia di `l` sia di `l-next`
        inserimento_ordinato(&(*l)->next, nodo);
      }
    }
  }

  // `l` era NULL e nodo diventa il primo e solo elemento
  *l = nodo;
}
```
