#include<stdio.h>

void main()
{
     int cost[10][10] , distance[10] , path[10][10];
     int n ,v , p , row,column , min ,index=1,i,j;


     //enter number of nodes
     printf("Enter the number of nodes: ");
     scanf("%d", &n);

     //enter the cost matrix
     printf("Enter the cost matrix:\n");
     for(int i=1 ; i<=n ; i++)
     {
         for(j=1 ; j<=n ; j++)
         {
               scanf("%d",&cost[i][j]);
         }
     }

     //user enters nodes to be visitied

     printf("Enter the nodes to be visited:  ");
     scanf("%d",&v);

     //enter the no of paths for a particular node
     printf("Enter paths for particular node");
     scanf("%d",&p);

     //enter the path matrix
     printf("Enter the path matrix:\n");
     for(i=1; i<=p ; i++)
     {
           for(j=1 ; j<=n ; j++)
           {
              scanf("%d",&path[i][j]);
           }
     }

     for(i=1 ; i<=p ; i++)
     {
         distance[i]=0;
         row=1;
         for(j=1; j<n ; j++)
         {
              if(row!=v)
              {
                  //till i visit the last node
                  column = path[i][j+1];
                  distance[i]=distance[i]+cost[row][column];
              }
              row=column;
         }
     }

     //which distance to be considered
     min = distance[1];
     for(i=1 ; i<=p ; i++)
     {
         if(distance[i]<=min)
         {
             min=distance[i];
             index=i;
         }
     }

     printf("min distance is %d \n ", min);
     printf("min distance path is :");
     for(i=1 ; i<=n ;i++)
     {
         if(path[index][i]!=0)
         {
             printf("-->%d",path[index][i]);
         }
     }

}