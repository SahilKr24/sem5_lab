#include <stdio.h>
 
int weight[] = {50,5,1000};
int price[] = {5000,500000,5000};
 
void Greedy_Knapsack(int M,int n) {
    int current_value;

    //Total value of items in bag
    float total_value;
    int i, maximum;

    //Check if item has been picked up
    int used[n];
 
    for (i = 0; i < n; ++i)
        used[i] = 0;
 
    current_value = M;
    while (current_value > 0) {
        maximum = -1;
        for (i = 0; i < n; ++i)
            if ((used[i] == 0) &&
                ((maximum == -1) || (price[i]*1.0/weight[i] > price[maximum]*1.0/weight[maximum])))
                maximum = i;

        //Set that item has been picked up
        used[maximum] = 1;
        current_value -= weight[maximum];
        total_value += price[maximum];
        if (current_value >= 0)
            printf("Add object %d (₹%d, %d weight). Space left: %d.\n", maximum + 1, price[maximum], weight[maximum], current_value);
        else {
            printf("Add %d%% (₹%d, %d weight) of object %d.\n", (int)((1 + current_value*1.0/weight[maximum]) * 100), price[maximum], weight[maximum], maximum + 1);
            total_value -= price[maximum];
            total_value += (1 + (float)current_value/weight[maximum]) * price[maximum];
        }
    }
 
    printf("Filled the knapsack with items worth ₹%.2f.\n", total_value);
}
 
int main() {
    //Max weight
    int M = 60;
    //Number of items
    int n = 3;
    Greedy_Knapsack(M,n);
    return 0;
}