#include <stdio.h>
#include <stdlib.h>

typedef struct process
{

    int num;
    struct process *next;
} process;

typedef struct cadre
{

    int PC;
    struct cadre *nextCadre;
} cadre;

typedef struct etat
{

    char DF;
    cadre *elemet;
    struct etat *nextEtat;
} etat;

cadre *changeEtat(int n, int b, int t[], cadre *C)
{

    C = malloc(sizeof(cadre));
    cadre *ptr = C;
    for (int i = 0; i < n; i++)
    {
        ptr->PC = t[i];
        if (i == n - 1)
            break;
        ptr->nextCadre = malloc(sizeof(cadre));
        ptr = ptr->nextCadre;
    }
    ptr->nextCadre = NULL;
    return C;
}

etat *fifo(process *P, etat *E)
{

    int np, i = 0, df = 0, b = 0;
    printf("donne nombre page: ");
    scanf("%d", &np);
    int temp[np];
    for (int i = 0; i < np; i++)
    {
        temp[i] = -1;
    }
    process *ptrP = P;
    E = malloc(sizeof(etat));
    etat *ptrE = E;
    while (ptrP != NULL)
    {
        b = 0;
        for (i = 0; i < np; i++)
        {
            if (temp[i] == ptrP->num)
            {
                b++;
                df--;
            }
        }
        df++;
        if (b == 0)
        {
            if (df < np)
            {
                temp[df] = ptrP->num;
            }
            else
            {
                temp[df % np] = ptrP->num;
            }
            ptrE->DF = 'D';
            ptrE->elemet = changeEtat(np, b, temp, ptrE->elemet);
        }

        else
        {
            ptrE->DF = 'V';
            ptrE->elemet = changeEtat(np, b, temp, ptrE->elemet);
        }

        if (ptrP->next == NULL)
            break;
        ptrE->nextEtat = malloc(sizeof(etat));
        ptrE = ptrE->nextEtat;
        ptrP = ptrP->next;
    }
    ptrE->nextEtat = NULL;
    return E;
}

void display(process *P, etat *E)
{

    process *ptrP = P;
    etat *ptrE = E;
    cadre *ptrC;

    while (ptrE != NULL)
    {
        ptrC = ptrE->elemet;
        printf("Pocess.%d\n", ptrP->num);
        ptrP = ptrP->next;
        while (ptrC != NULL)
        {
            printf("%d\n", ptrC->PC);
            ptrC = ptrC->nextCadre;
        }
        printf("%c", ptrE->DF);
        printf("\n----------------------\n");

        ptrE = ptrE->nextEtat;
    }
}

process *insertProcess()
{

    printf("create list process\n");
    process *head = malloc(sizeof(process));
    process *ptr = head;
    int add;
    do
    {

        printf("\nenter numbre of process: ");
        scanf("%d", &ptr->num);
        ptr->next = NULL;
        printf("\nadd process: ");
        scanf("%d", &add);
        if (add == 1)
        {
            ptr->next = malloc(sizeof(process));
            ptr = ptr->next;
        }
    } while (add == 1);
    return head;
}

void displayListProcess(process *h)
{

    if (h != NULL)
    {

        process *ptr = h;
        printf("%d", ptr->num);
        ptr = ptr->next;
        while (ptr != NULL)
        {
            printf("--%d", ptr->num);
            ptr = ptr->next;
        }
    }
    else
        printf("empty list\n");
}

int main()
{
    process *headP = insertProcess();
    etat *headE;
    headE = fifo(headP, headE);
    display(headP, headE);
    return 0;
}
