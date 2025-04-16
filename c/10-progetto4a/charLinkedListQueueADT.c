#include "charArrayADT.h"

/** @brief Restituisce una coda vuota, se non trova memoria restituisce NULL */
CharQueueADT mkQueue() {
  CharQueueADT queue = malloc(sizeof(struct charQueue));

  if (queue == NULL) {
    return NULL;
  }

  queue->capacity = INITIAL_CAPACITY;
  queue->a = malloc(queue->capacity);
  queue->size = 0;
  queue->front = 0;
  queue->rear = 0;

  return queue;
}

/** @brief Distrugge la coda, recuperando la memoria */
void dsQueue(CharQueueADT *pq) {
  *pq = NULL;
  free(*pq);
}

/** @brief Aggiunge un elemento in fondo alla coda, restituisce esito 0/1 */
_Bool enqueue(CharQueueADT q, const char e) {
  if (q->size == q->capacity) {
    int new_capacity = q->capacity * 2;

    char *new_array = malloc(new_capacity);
    if (new_array == NULL) {
      return 0;
    }

    for (int i = 0; i < q->size; i++) {
      new_array[i] = q->a[(q->front + i) % q->capacity];
    }
    free(q->a);

    q->a = new_array;
    q->capacity = new_capacity;
    q->front = 0;
    q->rear = q->size;
  }

  q->a[q->rear] = e;
  q->rear = (q->rear + 1) % q->capacity;
  q->size++;
  return 1;
}

/** @brief Toglie e restituisce l'elemento in testa alla coda, restituisce esito
 * 0/1 */
_Bool dequeue(CharQueueADT q, char *res) {
  if (q->size == 0) {
    return 0;
  }

  *res = q->a[q->front];
  q->front = (q->front + 1) % q->capacity;
  q->size--;

  if (q->size < (q->capacity / 4) && q->capacity > INITIAL_CAPACITY) {
    int new_capacity = q->capacity / 2;

    char *new_array = malloc(new_capacity);
    if (new_array == NULL) {
      return 0;
    }

    for (int i = 0; i < q->size; i++) {
      new_array[i] = q->a[(q->front + i) % q->capacity];
    }
    free(q->a);

    q->a = new_array;
    q->capacity = new_capacity;
    q->front = 0;
    q->rear = q->size;
  }

  return 1;
}

/** @brief Controlla se la coda è vuota */
_Bool isEmpty(CharQueueADT q) {
  return !q->size;
}

/** @brief Restituisce il numero degli elementi presenti nella coda */
int size(CharQueueADT q) {
  return q->size;
}

/** @brief Restituisce l'elemento nella posizione data (a partire dalla testa
 * con indice zero) (senza toglierlo), restituisce esito 0/1 */
_Bool peek(CharQueueADT q, int position, char *res) {
  if (position < 0 || q->size == 0 || position >= q->size || res == NULL) {
    return 0;
  }

  int index = (q->front + position) % q->capacity;

  if (!q->a[index]) {
    return 0;
  }

  *res = q->a[index];

  return 1;
}