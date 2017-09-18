#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct stack
{
    float top;
    float capacity;
    int* store;
};
struct stack *temp,stk;
int count=0;
int h;
void top(struct stack* temp)
{
    temp->top=-1;
}
int permission(struct stack* temp,int h)
{
    int d;
    printf("Do you want to continue ::( press 1--> YES and 0-->NO)::");
    scanf("%d",&d);
    if(d==1)
    {
        float m = ((((temp->top)+1)/(temp->capacity))*100);
        if ((m>=50)&&(m<=60))
        {
            printf("\n\t\t\tNOTICE\n\n\t50%% of the memory space is used up.\n");
        }
        if ((m>=90)&&(m<=94.6))
        {
            printf("\n\t\t\tNOTICE\n\n\t90%% of the memory space is used up.\n");
        }
        if (h+1==((temp->capacity)-4))
        {
            printf("\t\t\t\tWARNING\n\n\t Only 4 valid spaces are left to store data in the stack\n");
        }
        if (h+1==((temp->capacity)-2))
        {
            printf("\n\t\t\t\tWARNING\n\n\t Only 2 valid spaces are left to store data in the stack\n");
        }
        if (h+1==((temp->capacity)-1))
        {
            printf("\n\t\t\t\tWARNING\n\n\t Only 1 valid spaces are left to store data in the stack\n");
        }
        if(h+1 ==(temp->capacity))
        {
            temp->top=h;
            h=temp->top;
            printf("\n\t\tThe stack is fully loaded.\n\n\t\t No more Entries can be made.\n");
            return menu(temp);
        }
        return create_stack(temp);
    }
    if(d==0)
    {
        temp->top=h;
        h=temp->top;
        printf("\nPress 2 to display the stack.\n");
        return menu(temp);
    }
    else{
        printf("\nInvalid input.\n\nPress correct indication to continue.\n");
        return permission(temp,h);
    }
    return 0;
}
void capacity(struct stack* temp)
{
    count = count + 1;
    if(((temp->top)<0) && count == 1)
    {
        float c;
         printf("\nEnter the maximum capacity of the stack :: ");
         scanf("%f",&c);
         temp->capacity=c;
         temp->store = (int*)malloc((temp->capacity)*sizeof(int));
    }
    else
    {
        printf("\nCreation process of stack can be done once only.\n\nTo modify operate PUSH or POP.\n");
        return menu(temp);
    }

}
int pop(struct stack* temp)
{
    if((temp->top)<0)
    {
        printf("\nThe stack is empty.\nGoto step 1 first.\n");
        return menu(temp);
    }
    else
    {
        int po;
        h = (temp->top);
        po = (temp->store[h]);
        (temp->top)= (temp->top)-1;
        h = (temp->top);
        temp->top = h;
        printf("\nThe removed element from the list is %d.\n",po);
        printf("\nPress 2 to observe the changes .\n");
        return menu(temp);
    }
    return 0;
}
int push(struct stack* temp)
{
    if(((temp->capacity)-1)==(temp->top))
    {
        printf("\nThe stack is full . No more data can be pushed.\n\nGo to step 4 to Empty space.\n");
        return menu(temp);
    }
    else
    {
        int p;
        printf("\nEnter the element you want to insert :: ");
        scanf("%d",&p);
        h=(temp->top)+1;
        temp->top =h;
        temp->store[h]=p;
        printf("\nPush completed.\n\nPress 2 to observe the results.\n");
        return menu(temp);
    }
    return 0;
}
int display_stack(struct stack* temp)
{
    if((temp->top)<0)
    {
        printf("\nThe stack is empty.\nGoto step 1 first.\n");
        return menu(temp);
    }
    else
    {
        int i;
        printf("\nThe stack created so far .....\n\n");
        for(i=0;i<=(temp->top);i++)
        {
            printf("| %d |",temp->store[i]);
        }
        printf("<- TOP\n");
        float x = ((((temp->top)+1)/(temp->capacity))*100);
        printf("\nmemory status of the stack...\n\n\tSpace used.\t\t  Free space.\n\t%4.3f %%\t\t  %4.3f %%\n",x,(100-x));
        return menu(temp);
    }
    return 0;
}
int create_stack(struct stack* temp,int h)
{
    int data;
    printf("\nEnter data into the stack :: ");
    scanf("%d",&data);
    (temp->top) = (temp->top)+1;
    h = temp->top;
    temp->store[h] = data;
    permission(temp,h);
    return 0;
}
int menu(struct stack* temp)
{
    int n;
    printf("\nEnter your choice:\n\n1. Create a new stack.\n2. Display the stack.\n3. Operate push operation.\n4. Operate pop operation.\n5. Exit process.\n\n");
    scanf("%d",&n);
    switch(n)
    {
    case 1:
        capacity(temp);
        create_stack(temp,h);
        break;
    case 2:
        display_stack(temp);
        break;
    case 3:
        push(temp);
        break;
    case 4:
        pop(temp);
        break;
    case 5:
        exit (0);
    default:
        printf("\nInvalid Input.\nTry again...\n");
        return menu(temp);
    }
    return 0;
}
int main()
{
    temp=&stk;
    top(temp);
    menu(temp);
    return 0;
}
