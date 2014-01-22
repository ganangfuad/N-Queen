#include<stdio.h>
#include<conio.h>
#include<math.h>
#include<time.h>

int a[30],count=0;
int simpan(int pos)
{
 int i;
 for(i=1;i<pos;i++)
 {
  if((a[i]==a[pos])||((abs(a[i]-a[pos])==abs(i-pos))))
   return 0;
 }
 return 1;
}
void sol(int n)
{
 int i,j;
 count++;
 printf("\n\nSolusi #%d:\n",count);
 for(i=1;i<=n;i++)
 {
  for(j=1;j<=n;j++)
  {
   if(a[i]==j)
    printf("Q\t");
   else
    printf("*\t");
  }
  printf("\n");
 }
}
void ratu(int n)
{
 int r=1;
 a[r]=0;
 while(r!=0)
 {
  a[r]=a[r]+1;
  while((a[r]<=n)&&!simpan(r))
   a[r]++;
  if(a[r]<=n)
  {
   if(r==n)
   sol(n);
   else
   {
    r++;
    a[r]=0;
   }
  }
  else
   r--;
 }
}
int main()
{
 int i,n;
 printf("Masukan jumlah ratu yang diinginkan : ");scanf("%d",&n);
 double start = clock();
 ratu(n);
 printf("\nTotal Solusi=%d",count);
 double stop = clock();
 printf("\nWaktu eksekusi Program: %.2f", (stop-start)/1000);
 getch();
}
