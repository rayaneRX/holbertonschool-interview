#include <stdio.h>
#include <stdlib.h>

typedef struct listint_t {
    int data;
    struct listint_t *next;
} listint_t;

listint_t* reverseList(listint_t *head) {
    listint_t *prev = NULL;
    listint_t *curr = head;
    listint_t *next = NULL;

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    return prev;
}

int is_palindrome(listint_t **head) {
    listint_t *slow = *head;
    listint_t *fast = *head;
    listint_t *prev_slow = NULL;
    listint_t *second_half = NULL;
    int is_palindrome = 1;

    if (*head != NULL && (*head)->next != NULL) {
        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            prev_slow = slow;
            slow = slow->next;
        }

        if (fast != NULL) {
            slow = slow->next;
        }

        second_half = reverseList(slow);

        listint_t *temp1 = *head;
        listint_t *temp2 = second_half;
        while (temp1 != NULL && temp2 != NULL) {
            if (temp1->data != temp2->data) {
                is_palindrome = 0;
                break;
            }
            temp1 = temp1->next;
            temp2 = temp2->next;
        }

        second_half = reverseList(second_half);

        if (prev_slow != NULL) {
            prev_slow->next = second_half;
        } else {
            *head = second_half;
        }
    }

    return is_palindrome;
}

void push(listint_t **head, int new_data) {
    listint_t *new_node = (listint_t*)malloc(sizeof(listint_t));
    new_node->data = new_data;
    new_node->next = *head;
    *head = new_node;
}

void printList(listint_t *node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}
