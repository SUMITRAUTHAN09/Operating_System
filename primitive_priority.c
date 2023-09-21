#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

void input(int p[],int at[],int bt[],int priority[],int n){
    printf("   AT BT PRIORITY\n");
    for(int i=0;i<n;i++){
        printf("p%d: ",i+1);
        scanf("%d %d %d",&at[i],&bt[i],&priority[i]);
        p[i]=i+1;
    }
}
void swap(int *x,int *y){
    int temp=*x;
        *x=*y;
        *y=temp;

}
void sort(int p[],int at[],int bt[],int priority[],int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-i-1;j++){
            if(at[j]>at[j+1]){
                swap(&at[j],&at[j+1]);
                swap(&bt[j],&bt[j+1]);
                swap(&p[j],&p[j+1]);
                swap(&priority[j],&priority[j+1]);
            }
        }
    }
}

void calculate(int at[], int bt[], int ct[],int tat[],int wt[], int priority[], int n) {
    int remaining[n];
    for (int i = 0; i < n; i++) {
        remaining[i] = bt[i];
    }

    int time = 0;
    int completed = 0;

    while (completed < n) {
        int highest_priority = -1;
        int highest_priority_index = -1;

        for (int i = 0; i < n; i++) {
            if (at[i] <= time && remaining[i] > 0 && priority[i] > highest_priority) {
                highest_priority = priority[i];
                highest_priority_index = i;
            }
        }

        if (highest_priority_index == -1) {
            time++;
        } else {

            remaining[highest_priority_index]--;
            time++;

            if (remaining[highest_priority_index] == 0) {
                ct[highest_priority_index] = time;
                completed++;
            }
        }
        for(int i=0;i<n;i++){
            tat[i]=ct[i]-at[i];
            wt[i]=tat[i]-bt[i];
        }
    }
}

void display(int p[],int at[],int bt[],int ct[],int tat[],int wt[],int n){
    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");
    for(int i=0;i<n;i++){
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",p[i],at[i],bt[i],ct[i],tat[i],wt[i]);

    }
}

int main(){
    int n;
    printf("Enter the number of process:");
    scanf("%d",&n);
    int p[n],at[n],bt[n],ct[n],tat[n],wt[n],priority[n];

    input(p,at,bt,priority,n);
    sort(p,at,bt,priority,n);
    calculate(at,bt,ct,tat,wt,priority,n);
    display(p,at,bt,ct,tat,wt,n);

    return 0;
}
