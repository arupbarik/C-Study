/*
==============================================================================
 PROGRAM: Implementation of QUEUE using Array
          (1) Linear Queue   (2) Circular Queue
==============================================================================

 This single file contains TWO menu-driven modules:
   MODULE 1 -> Linear Queue   : ENQUEUE, DEQUEUE, DISPLAY
   MODULE 2 -> Circular Queue : ENQUEUE_CQ, DEQUEUE_CQ, DISPLAY

 A top-level main menu lets the user choose which queue to work with.
==============================================================================

--------------------------------------------------------------------------
PSEUDOCODE : MAIN MENU (Top Level)
--------------------------------------------------------------------------
    START
    LOOP
        PRINT "1. Linear Queue Operations"
        PRINT "2. Circular Queue Operations"
        PRINT "3. Exit"
        READ choice
        SWITCH choice:
            CASE 1: CALL linearQueueMenu()
            CASE 2: CALL circularQueueMenu()
            CASE 3: EXIT program
            DEFAULT: PRINT "Invalid choice"
    END LOOP
    STOP
--------------------------------------------------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX 5   /* size of the queue (small size chosen to test overflow easily) */

/* ============================================================
   MODULE 1: LINEAR QUEUE USING ARRAY
   ============================================================

   PSEUDOCODE : LINEAR QUEUE - DATA STRUCTURE
   --------------------------------------------------------------
       DECLARE array queue[MAX]
       DECLARE front = -1, rear = -1

   PSEUDOCODE : ENQUEUE(value)
   --------------------------------------------------------------
       IF rear == MAX - 1 THEN
           PRINT "Queue Overflow"
       ELSE
           IF front == -1 THEN       // first element being inserted
               SET front = 0
           SET rear = rear + 1
           SET queue[rear] = value
       END IF

   PSEUDOCODE : DEQUEUE()
   --------------------------------------------------------------
       IF front == -1 OR front > rear THEN
           PRINT "Queue Underflow"
       ELSE
           SET removedValue = queue[front]
           SET front = front + 1
           IF front > rear THEN       // queue became empty, reset
               SET front = -1
               SET rear = -1
           PRINT removedValue
       END IF

   PSEUDOCODE : DISPLAY()
   --------------------------------------------------------------
       IF front == -1 OR front > rear THEN
           PRINT "Queue is empty"
       ELSE
           FOR i = front TO rear
               PRINT queue[i]
       END IF
   ============================================================ */

int lq[MAX];
int lfront = -1, lrear = -1;

void enqueueLQ(int value) {
    if (lrear == MAX - 1) {
        printf("Queue Overflow! Cannot insert %d.\n", value);
        return;
    }
    if (lfront == -1)
        lfront = 0;
    lrear++;
    lq[lrear] = value;
    printf("%d inserted into Linear Queue.\n", value);
}

void dequeueLQ(void) {
    if (lfront == -1 || lfront > lrear) {
        printf("Queue Underflow! Queue is empty.\n");
        return;
    }
    int removed = lq[lfront];
    lfront++;
    if (lfront > lrear) {   /* queue emptied, reset pointers */
        lfront = -1;
        lrear = -1;
    }
    printf("%d deleted from Linear Queue.\n", removed);
}

void displayLQ(void) {
    if (lfront == -1 || lfront > lrear) {
        printf("Linear Queue is empty.\n");
        return;
    }
    printf("Linear Queue elements: ");
    for (int i = lfront; i <= lrear; i++)
        printf("%d ", lq[i]);
    printf("\n");
}

void linearQueueMenu(void) {
    int choice, value;
    /*
    PSEUDOCODE : linearQueueMenu()
    --------------------------------------------------------------
        LOOP
            PRINT "1. ENQUEUE"
            PRINT "2. DEQUEUE"
            PRINT "3. DISPLAY"
            PRINT "4. Back to Main Menu"
            READ choice
            SWITCH choice:
                CASE 1: READ value; CALL enqueueLQ(value)
                CASE 2: CALL dequeueLQ()
                CASE 3: CALL displayLQ()
                CASE 4: RETURN to main menu
                DEFAULT: PRINT "Invalid choice"
        END LOOP
    --------------------------------------------------------------
    */
    do {
        printf("\n--- LINEAR QUEUE MENU ---\n");
        printf("1. ENQUEUE\n2. DEQUEUE\n3. DISPLAY\n4. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueueLQ(value);
                break;
            case 2:
                dequeueLQ();
                break;
            case 3:
                displayLQ();
                break;
            case 4:
                printf("Returning to Main Menu...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 4);
}

/* ============================================================
   MODULE 2: CIRCULAR QUEUE USING ARRAY
   ============================================================

   PSEUDOCODE : CIRCULAR QUEUE - DATA STRUCTURE
   --------------------------------------------------------------
       DECLARE array cqueue[MAX]
       DECLARE front = -1, rear = -1

   PSEUDOCODE : ENQUEUE_CQ(value)
   --------------------------------------------------------------
       IF (rear + 1) MOD MAX == front THEN
           PRINT "Circular Queue Overflow"
       ELSE
           IF front == -1 THEN            // first element
               SET front = 0
           SET rear = (rear + 1) MOD MAX
           SET cqueue[rear] = value
       END IF

   PSEUDOCODE : DEQUEUE_CQ()
   --------------------------------------------------------------
       IF front == -1 THEN
           PRINT "Circular Queue Underflow"
       ELSE
           SET removedValue = cqueue[front]
           IF front == rear THEN          // only one element existed
               SET front = -1
               SET rear = -1
           ELSE
               SET front = (front + 1) MOD MAX
           PRINT removedValue
       END IF

   PSEUDOCODE : DISPLAY()
   --------------------------------------------------------------
       IF front == -1 THEN
           PRINT "Circular Queue is empty"
       ELSE
           SET i = front
           LOOP
               PRINT cqueue[i]
               IF i == rear THEN BREAK
               SET i = (i + 1) MOD MAX
           END LOOP
       END IF
   ============================================================ */

int cq[MAX];
int cfront = -1, crear = -1;

void enqueueCQ(int value) {
    if ((crear + 1) % MAX == cfront) {
        printf("Circular Queue Overflow! Cannot insert %d.\n", value);
        return;
    }
    if (cfront == -1)
        cfront = 0;
    crear = (crear + 1) % MAX;
    cq[crear] = value;
    printf("%d inserted into Circular Queue.\n", value);
}

void dequeueCQ(void) {
    if (cfront == -1) {
        printf("Circular Queue Underflow! Queue is empty.\n");
        return;
    }
    int removed = cq[cfront];
    if (cfront == crear) {     /* only one element was present */
        cfront = -1;
        crear = -1;
    } else {
        cfront = (cfront + 1) % MAX;
    }
    printf("%d deleted from Circular Queue.\n", removed);
}

void displayCQ(void) {
    if (cfront == -1) {
        printf("Circular Queue is empty.\n");
        return;
    }
    printf("Circular Queue elements: ");
    int i = cfront;
    while (1) {
        printf("%d ", cq[i]);
        if (i == crear)
            break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

void circularQueueMenu(void) {
    int choice, value;
    /*
    PSEUDOCODE : circularQueueMenu()
    --------------------------------------------------------------
        LOOP
            PRINT "1. ENQUEUE_CQ"
            PRINT "2. DEQUEUE_CQ"
            PRINT "3. DISPLAY"
            PRINT "4. Back to Main Menu"
            READ choice
            SWITCH choice:
                CASE 1: READ value; CALL enqueueCQ(value)
                CASE 2: CALL dequeueCQ()
                CASE 3: CALL displayCQ()
                CASE 4: RETURN to main menu
                DEFAULT: PRINT "Invalid choice"
        END LOOP
    --------------------------------------------------------------
    */
    do {
        printf("\n--- CIRCULAR QUEUE MENU ---\n");
        printf("1. ENQUEUE_CQ\n2. DEQUEUE_CQ\n3. DISPLAY\n4. Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                enqueueCQ(value);
                break;
            case 2:
                dequeueCQ();
                break;
            case 3:
                displayCQ();
                break;
            case 4:
                printf("Returning to Main Menu...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 4);
}

/* ============================================================
   MAIN FUNCTION - TOP LEVEL MENU
   ============================================================ */
int main(void) {
    int choice;

    do {
        printf("\n=================================\n");
        printf("      QUEUE OPERATIONS MENU\n");
        printf("=================================\n");
        printf("1. Linear Queue Operations\n");
        printf("2. Circular Queue Operations\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                linearQueueMenu();
                break;
            case 2:
                circularQueueMenu();
                break;
            case 3:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 3);

    return 0;
}