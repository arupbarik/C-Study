/* =========================================================================
 * QUEUE OPERATIONS
 * Enqueue (insertion) and Dequeue (deletion) for:
 *   1. Linear Queue
 *   2. Circular Queue
 * ========================================================================= */

#include <stdio.h>
#define MAX 5

/* =========================================================================
 * 1. LINEAR QUEUE
 * =========================================================================
 *
 * PSEUDOCODE: ENQUEUE_LINEAR(QUEUE, FRONT, REAR, MAX, ITEM)
 *   1. IF REAR = MAX - 1 THEN
 *        PRINT "QUEUE OVERFLOW"
 *        EXIT
 *   2. IF FRONT = -1 THEN
 *        SET FRONT = 0
 *   3. SET REAR = REAR + 1
 *   4. SET QUEUE[REAR] = ITEM
 *   5. END
 *
 * PSEUDOCODE: DEQUEUE_LINEAR(QUEUE, FRONT, REAR)
 *   1. IF FRONT = -1 OR FRONT > REAR THEN
 *        PRINT "QUEUE UNDERFLOW"
 *        EXIT
 *   2. SET ITEM = QUEUE[FRONT]
 *   3. SET FRONT = FRONT + 1
 *   4. IF FRONT > REAR THEN
 *        SET FRONT = -1
 *        SET REAR  = -1
 *   5. RETURN ITEM
 *   6. END
 * ========================================================================= */

int lqueue[MAX];
int lfront = -1, lrear = -1;

void enqueue_linear(int item) {
    if (lrear == MAX - 1) {
        printf("Linear Queue Overflow\n");
        return;
    }
    if (lfront == -1)
        lfront = 0;
    lrear++;
    lqueue[lrear] = item;
}

int dequeue_linear(void) {
    int item;
    if (lfront == -1 || lfront > lrear) {
        printf("Linear Queue Underflow\n");
        return -1;
    }
    item = lqueue[lfront];
    lfront++;
    if (lfront > lrear)
        lfront = lrear = -1;
    return item;
}

/* =========================================================================
 * 2. CIRCULAR QUEUE
 * =========================================================================
 *
 * PSEUDOCODE: ENQUEUE_CIRCULAR(QUEUE, FRONT, REAR, MAX, ITEM)
 *   1. IF (REAR + 1) MOD MAX = FRONT THEN
 *        PRINT "QUEUE OVERFLOW"
 *        EXIT
 *   2. IF FRONT = -1 THEN
 *        SET FRONT = 0
 *        SET REAR  = 0
 *      ELSE
 *        SET REAR = (REAR + 1) MOD MAX
 *   3. SET QUEUE[REAR] = ITEM
 *   4. END
 *
 * PSEUDOCODE: DEQUEUE_CIRCULAR(QUEUE, FRONT, REAR, MAX)
 *   1. IF FRONT = -1 THEN
 *        PRINT "QUEUE UNDERFLOW"
 *        EXIT
 *   2. SET ITEM = QUEUE[FRONT]
 *   3. IF FRONT = REAR THEN
 *        SET FRONT = -1
 *        SET REAR  = -1
 *      ELSE
 *        SET FRONT = (FRONT + 1) MOD MAX
 *   4. RETURN ITEM
 *   5. END
 * ========================================================================= */

int cqueue[MAX];
int cfront = -1, crear = -1;

void enqueue_circular(int item) {
    if ((crear + 1) % MAX == cfront) {
        printf("Circular Queue Overflow\n");
        return;
    }
    if (cfront == -1) {
        cfront = 0;
        crear = 0;
    } else {
        crear = (crear + 1) % MAX;
    }
    cqueue[crear] = item;
}

int dequeue_circular(void) {
    int item;
    if (cfront == -1) {
        printf("Circular Queue Underflow\n");
        return -1;
    }
    item = cqueue[cfront];
    if (cfront == crear) {
        cfront = crear = -1;
    } else {
        cfront = (cfront + 1) % MAX;
    }
    return item;
}

/* =========================================================================
 * DEMO DRIVER
 * ========================================================================= */

int main(void) {
    printf("--- Linear Queue ---\n");
    enqueue_linear(10);
    enqueue_linear(20);
    enqueue_linear(30);
    printf("Dequeued: %d\n", dequeue_linear());
    printf("Dequeued: %d\n", dequeue_linear());
    enqueue_linear(40);

    printf("\n--- Circular Queue ---\n");
    enqueue_circular(1);
    enqueue_circular(2);
    enqueue_circular(3);
    printf("Dequeued: %d\n", dequeue_circular());
    enqueue_circular(4);
    enqueue_circular(5);
    enqueue_circular(6); /* reuses the freed slot */

    return 0;
}
