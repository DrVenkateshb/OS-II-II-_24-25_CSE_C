#include<stdio.h>
int main(){
        int m_size,np,nb;
        int b[10],p[10],a[10];
        printf("enter the size of the memory:");
        scanf("%d",&m_size);
        printf("enter the number of memory blocks:");
        scanf("%d",&nb);
        for(int i=0;i<nb;i++){
                scanf("%d",&b[i]);
        }
        printf("enter the number of processes:");
        scanf("%d",&np);
        for(int i=0;i<np;i++){
                scanf("%d",&p[i]);
                a[i]=-1;
        }
        for(int i=0;i<np;i++){
                int best=-1;
                for(int j=0;j<nb;j++){
                        if(b[j]>=p[i]){
                                if(best==-1||b[j]>b[best]){
                                        best=j;
                                }
                        }
                }
                        if(best!=-1){
                                a[i]=best;
                                b[best]-=p[i];
                        }
                }

        printf("\nProcess No\tProcess Size\tBlock No\n");
                for(int i=0;i<np;i++){
                        if(a[i]!=-1){
                                printf("%d\t\t%d\t\t%d\n",i+1,p[i],a[i]+1);
                      }
			else{
                                printf("%d\t\t%d\t\tNot Allocated\n",i+1,p[i]);
                        }
                }
                return 0;
        }

