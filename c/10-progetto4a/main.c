#include "charArrayADT.h"
#include <stdio.h>

int main(void) {
  CharQueueADT q = mkQueue();
  if (q == NULL) {
    fprintf(stderr, "Error: Unable to create the queue.\n");
    return 1;
  }

  _Bool ret;
  char res;

  // Test 1: peek(q,1,&res) on an empty queue, expecting failure (ret == 0)
  ret = peek(q, 1, &res);
  printf("Test 1: peek(q, 1, &res) returned: %d\n", ret);

  // Test 2: peek(q,-1,&res) with invalid negative index, expecting failure (ret
  // == 0)
  ret = peek(q, -1, &res);
  printf("Test 2: peek(q, -1, &res) returned: %d\n", ret);

  // Test 3: enqueue(q,'w')
  ret = enqueue(q, 'w');
  printf("Test 3: enqueue(q, 'w') returned: %d\n", ret);

  // Test 4: peek(q,0,&res); should succeed and return 'w'
  ret = peek(q, 0, &res);
  printf("Test 4: peek(q, 0, &res) returned: %d, res = '%c'\n", ret, res);

  // Test 5: enqueue(q,'a')
  ret = enqueue(q, 'a');
  printf("Test 5: enqueue(q, 'a') returned: %d\n", ret);

  // Test 6: enqueue(q,'b')
  ret = enqueue(q, 'b');
  printf("Test 6: enqueue(q, 'b') returned: %d\n", ret);

  // Test 7: peek(q,2,&res); the queue now holds {'w', 'a', 'b'} so index 2 should be 'b'
  ret = peek(q, 2, &res);
  printf("Test 7: peek(q, 2, &res) returned: %d, res = '%c'\n", ret, res);

  // Test 8: peek(q,3,&res); index 3 is out of bounds (given only 3 elements) and should fail (ret == 0)
  ret = peek(q, 3, &res);
  printf("Test 8: peek(q, 3, &res) returned: %d\n", ret);

  dsQueue(&q);
  if (q == NULL)
    printf("Queue destroyed successfully.\n");
  else
    printf("Queue not destroyed correctly.\n");

  return 0;
}
