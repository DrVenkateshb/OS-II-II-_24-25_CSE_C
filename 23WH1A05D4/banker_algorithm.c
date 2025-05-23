#include<stdio.h>

int main() {
  int p, c;
  printf("Enter number of processess: \n");
  scanf("%d", &p);
  printf("Enter number of resources: \n");
  scanf("%d", &c);
  int count = 0, i, j, alc[p][c], max[p][c], need[p][c], safe[p], available[c], done[p], terminate = 0;
  printf("enter allocation of resource of all process %dx%d matrix: \n", p, c);
  for (i = 0; i < p; i++) {
    for (j = 0; j < c; j++) {
      scanf("%d", & alc[i][j]);
    }
  }
  printf("enter the max resource process required %dx%d matrix: \n", p, c);
  for (i = 0; i < p; i++) {
    for (j = 0; j < c; j++) {
      scanf("%d", & max[i][j]);
    }
  }
  printf("enter the  available resource: \n");
  for (i = 0; i < c; i++){
    printf("%c : ", 65+i);
    scanf("%d", & available[i]);
  }
  printf("Need resources matrix: \n");
  printf("Process  ");
  for(i = 0; i < c; i++){
    printf("%c\t ", 65+i);
  }
  printf("\n");
  for (i = 0; i < p; i++) {
    printf("   P%d  \t", i);
    for (j = 0; j < c; j++) {
      need[i][j] = max[i][j] - alc[i][j];
      printf("%d\t", need[i][j]);
    }
    printf("\n");
  }
  for (i = 0; i < p; i++) {
    done[i] = 0;
  }
  while (count < p) {
    for (i = 0; i < p; i++) {
      if (done[i] == 0) {
        for (j = 0; j < c; j++) {
          if (need[i][j] > available[j])
            break;
        }
        if (j == c) {
          safe[count] = i;
          done[i] = 1;
          for (j = 0; j < c; j++) {
            available[j] += alc[i][j];
          }
          count++;
          terminate = 0;
        } else {
          terminate++;
        }
      }
    }
    if (terminate == (p - 1)) {
      printf("Safe sequence does not exist");
      break;
    }

  }
  if (terminate != (p - 1)) {
    printf("\nAvailable resource after completion\n");
    for (i = 0; i < c; i++) {
      printf("%c : %d\n", 65+i, available[i]);
    }
    printf("\nSafe sequence are\n");
    for (i = 0; i < p; i++) {
      printf("p%d\t", safe[i]);
    }
    printf("\n");
  }

  return 0;
}
