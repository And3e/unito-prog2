#include "linkedListQueue.h"

/* @brief Restituisce una coda vuota, se non trova memoria restituisce NULL */
CharQueueADT mkQueue() {
  CharQueueADT queue = malloc(sizeof(struct charQueue));

  if (queue == NULL) {
    return 0;
  }

  queue->front = NULL;
  queue->rear = NULL;
  queue->count = 0;

  return queue;
}

/* @brief Distrugge la coda, recuperando la memoria */
void dsQueue(CharQueueADT *pq) {
  if (pq == NULL || *pq == NULL) {
    return;
  }

  ListNodePtr current = (*pq)->front;

  while (current != NULL) {
    ListNodePtr temp = current;
    current = current->next;
    temp = NULL;
    free(temp);
  }

  free(*pq);
  *pq = NULL;
}

/* @brief Aggiunge un elemento in fondo alla coda, restituisce esito 0/1 */
_Bool enqueue(CharQueueADT q, const char e) {
  if (isEmpty(q)) {
    return 0;
  }

  ListNodePtr node = malloc(sizeof(struct listNode));

  if (node == NULL) {
    return 0;
  }

  node->data = e;
  node->next = NULL;

  if (q->front == NULL) {
    q->front = node;
    q->rear = node;
  } else {
    q->rear->next = node;
    q->rear = node;
  }

  q->count++;
  return 1;
}

/* @brief Toglie e restituisce l'elemento in testa alla coda, restituisce esito
 * 0/1 */
_Bool dequeue(CharQueueADT q, char *res) {
  if (isEmpty(q) || res == NULL) {
    return 0;
  }

  ListNodePtr node = q->front;
  *res = node->data;
  q->front = node->next;

  if (q->front == NULL) {
    q->rear = NULL;
  }

  node = NULL;
  free(node);

  q->count--;

  return 1;
}

/* @brief Controlla se la coda è vuota */
_Bool isEmpty(CharQueueADT q) {
  if (q == NULL || q->front == NULL || q->rear == NULL) {
    return 1;
  }

  return 0;
}

/* @brief Restituisce il numero degli elementi presenti nella coda */
int size(CharQueueADT q) {
  if (isEmpty(q)) {
    return 0;
  }

  if (q == NULL) {
    return 0;
  }

  return q->count;
}

/* @brief Restituisce l'elemento nella posizione data (a partire dalla testa con
 * indice zero) (senza toglierlo), restituisce esito 0/1 */
_Bool peek(CharQueueADT q, int position, char *res) {
  if (position < 0 || position >= q->count || isEmpty(q) || res == NULL) {
    return 0;
  }

  ListNodePtr node = q->front;

  for (int i = 0; i < position; i++) {
    if (node == NULL) {
      return 0;
    }

    node = node->next;
  }

  if (node == NULL) {
    return 0;
  }

  *res = node->data;
  return 1;
}