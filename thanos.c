//
//  thanos.c
//  
//
//  Created by Mark on 12/25/18.
//
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define MAX 50 // the maximum length of a line

int countPeople()
{
    // file opening
    FILE *victims;
    victims = fopen("/Users/18markl/Desktop/victims.txt","r");
    int count = 0;
    char buffer[MAX];
    
    while(fgets(buffer,MAX,victims) != NULL)
    {
        count++;
    }
    // file closing
    fclose(victims);
    
    return count;
}

int oddOrEven(int x)
{
    while(x != 1 && x != 2)
    {
        x = x - 2;
    }
    if(x == 1)
    {
        return 0;
    }
    else if(x == 2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int divideByTwoRoundUp(int x)
{
    int even = oddOrEven(countPeople());
    float y = 0.5;
    if(even == 0)
    {
        x = x + 1;
        x = x / 2;
        return x;
    }
    else if(even == 1)
    {
        x = x / 2;
        return x;
    }
    else
    {
        return 0;
    }
}

int main()
{
    printf("\n\n\n\n\n\n\n\n                'Perfectly balanced, as all things should be'\n\n\n\n\n\n\n\n");
    FILE *victims;
    srand(time(NULL));
    // variables
    int numberPeople = countPeople(), even = oddOrEven(numberPeople), chosenPositions[divideByTwoRoundUp(numberPeople)],i,j;
    char buffer[MAX];
    struct person
    {
        char name[MAX];
        int position;
        int snapped;
    } id[numberPeople];
    // stores and prints the people
    victims = fopen("/Users/18markl/Desktop/victims.txt","r");
    for(i=0;i<numberPeople;i++)
    {
        fgets(buffer,MAX,victims); // gets the line
        strncpy(id[i].name,buffer,MAX); // stores the name
        id[i].position = i; // sets position to each person
        id[i].snapped = 0; // sets all persons to not snapped
        if(i == numberPeople-1)
        {
            printf("%s\n", id[i].name);
            printf("Position in list: %d\n", id[i].position+1);
        }
        else
        {
            printf("%s", id[i].name);
            printf("Position in list: %d\n", id[i].position+1);
        }
    }
    fclose(victims);
    printf("\n\n\n\n                                    *SNAP*\n\n\n\n");
    // determines if someone is snapped or not
    for(i=0;i<divideByTwoRoundUp(numberPeople);i++)
    {
        chosenPositions[i] = rand () % numberPeople;
    }
    for(i = 0 ; i < divideByTwoRoundUp(numberPeople) ; i++)
    {
        for(j = 0 ; j < divideByTwoRoundUp(numberPeople);j++)
        {
            if(chosenPositions[i] == chosenPositions [j] && i != j)
            {
                chosenPositions[i] = rand () % numberPeople;
                i = 0;
            }
        }
    }
    for(i=0 ; i < divideByTwoRoundUp(numberPeople) ; i++)
    {
        for(j = 0 ; j < numberPeople;j++)
        {
            if(chosenPositions[i] == id[j].position)
            {
                id[j].snapped = 1;
            }
        }
    }
    for(i=0;i<numberPeople;i++)
    {
        if(i == numberPeople-1)
        {
            printf("%s\n", id[i].name);
            if(id[i].snapped == 1)
            {
                printf("is SNAPPED\n");
            }
            else
            {
                printf("is SPARED\n");
            }
        }
        else
        {
            printf("%s", id[i].name);
            if(id[i].snapped == 1)
            {
                printf("is SNAPPED\n");
            }
            else
            {
                printf("is SPARED\n");
            }
        }
    }
    return 0;
}
