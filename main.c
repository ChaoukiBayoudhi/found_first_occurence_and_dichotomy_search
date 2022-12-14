#include <stdio.h>
#include <time.h> // for time() or clock()
#include <stdlib.h> // for rand()
#define SIZE_MAX 10000 // max size of array as constant

//implementation of functions
void input_array(int *tab, int *size){
    int i;
    printf("Enter the size of the array: ");
    scanf("%d", size);
    for(i=0; i<*size; i++){
        printf("Enter the element %d: ", i+1);
        //scanf("%d", &tab[i]);
        scanf("%d", tab+i);
    }
}
//get a sorted array from the keyboard
//wrong introduced values are ignored
void input_sorted_array(int *tab, int *size){
    int i;
    printf("Enter the size of the array: ");
    scanf("%d", size);
    //get the first element
    printf("Enter the element 1: ");
    scanf("%d", &tab[0]);
    //get the rest of the elements but check each time if they are greater than the previous one
    for(i=1; i<*size; i++){
        do{
            printf("Enter the element %d: (>=%d)", i+1,tab[i-1]);
            //scanf("%d", &tab[i]);
            scanf("%d", tab+i);
        }while(tab[i]<tab[i-1]);
    }
}
void print_array(int *tab, int size){
    int i;
    printf("The array is: \n");
    for(i=0; i<size; i++){
        printf("%d\t", tab[i]);
    }
    printf("\n");
}
//find a value x in an array (sorted or not)
//complexity: O(n)
int find(int *tab, int size, int x){
    int i;
    while(i<size && tab[i]!=x){
        i++;
    }
    if(i<size)//we found the value
        return i;
    return -1;//if we reach this point, the value was not found

}
//find a value x in a sorted array
//dichotomy search algorithm

int find_in_sorted_array(int *tab, int size, int x){
int start=0, end=size-1, middle,find=-1;
while(start<=end && find==-1){
    middle=(start+end)/2;
    if(tab[middle]==x)
        find=middle;
    if(x>tab[middle])
        start=middle+1;
    else
        end=middle-1;
    }
    return find;
}
//generate a random array with values between 0 and 100
void generate_random_array(int *tab, int size){
    int i;
    srand(time(NULL));
    for(i=0; i<size; i++){
        tab[i]=rand()%101;
    }
}
void generate_random_sorted_array(int *tab, int size){
    int i;
    srand(time(NULL));
    tab[0]=rand()%101;
    for(i=1; i<size; i++){
        do {
            tab[i] = rand() % 101;
        }while(tab[i]<tab[i-1]);
    }
}
int main() {
    int tab[SIZE_MAX],size,x,value;
//    srand(time(NULL));//to get different values each time we call rand() function
//    value=rand()%100;//generate a random value between 0 and 99
//    //value=a+rand()%(b-a+1);//generate a random value between a and b
//    printf("The value is: %d", value);
//    getchar();
    //find a value in an array
    //printf("Introduce an array.\n");
    //input_array(tab, &size);
    do {
        printf("Enter the size of the array: ");
        scanf("%d", &size);
    } while(size<0 || size>SIZE_MAX);
    generate_random_array(tab, size);
    print_array(tab, size);
    printf("Enter the integer to find :\t");
    scanf("%d",&x);
    int time1=clock();
    int index=find(tab, size, x);
    int time2=clock();
    if(index==-1)
        printf("The value %d was not found.\n", x);
    else
        printf("The value %d was found at index %d.\n", x, index);

    printf("The time taken by the sequential version is %d ms.\n", time2-time1);

    //find in a sorted array
    printf("Introduce a sorted array.\n");
    //input_sorted_array(tab, &size);
    do {
        printf("Enter the size of the array: ");

        scanf("%d", &size);
    }while(size<0 ||size>SIZE_MAX);
    generate_random_sorted_array(tab, size);
    print_array(tab, size);
    printf("Enter the integer to find :\t");
    scanf("%d",&x);
    time1=clock();
    index=find_in_sorted_array(tab, size, x);
    time2=clock();
    if(index==-1)
        printf("The value %d was not found.\n", x);
    else
        printf("The value %d was found at index %d.\n", x, index);
    printf("The time taken by the dichotomy version is %d ms.\n", time2-time1);
    return 0;
}
