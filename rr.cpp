#include<stdio.h>
 
int main()
{
      int i, limit, total = 0, x, counter = 0, tq;
      int wt = 0, tat = 0, at[10], bt[10], temp[10];
      float awt, atat;
      printf("\nEnter Total Number of Processes:\t");
      scanf("%d", &limit);
      x = limit;
      for(i = 0; i < limit; i++)
      {
            printf("\nEnter Details of Process[%d]\n", i + 1);
 
            printf("Arrival Time:\t");
 
            scanf("%d", &at[i]);
 
            printf("Burst Time:\t");
 
            scanf("%d", &bt[i]);
 
            temp[i] = bt[i];
      }
 
      printf("\nEnter Time Quantum:\t");
      scanf("%d", &tq);
      printf("\nProcess ID\t\tBurst Time\t Turnaround Time\t Waiting Time\n");
      for(total = 0, i = 0; x != 0;)
      {
            if(temp[i] <= tq && temp[i] > 0)
            {
                  total = total + temp[i];
                  temp[i] = 0;
                  counter = 1;
            }
            else if(temp[i] > 0)
            {
                  temp[i] = temp[i] - tq;
                  total = total + tq;
            }
            if(temp[i] == 0 && counter == 1)
            {
                  x--;
                  printf("\nProcess[%d]\t\t%d\t\t %d\t\t\t %d", i + 1, bt[i], total - at[i], total - at[i] - bt[i]);
                  wt = wt + total - at[i] - bt[i];
                  tat = tat + total - at[i];
                  counter = 0;
            }
            if(i == limit - 1)
            {
                  i = 0;
            }
            else if(at[i + 1] <= total)
            {
                  i++;
            }
            else
            {
                  i = 0;
            }
      }
 
      awt = wt * 1.0 / limit;
      atat = tat * 1.0 / limit;
      printf("\n\nAverage Waiting Time:\t%f", awt);
      printf("\nAvg Turnaround Time:\t%f\n", atat);
      return 0;
}
