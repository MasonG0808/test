#include <iostream>
#include<algorithm>
using namespace std;
//һ��3��ת�� 
int n,m;//nΪת�ִ�С 
int a[1005],b[1005],c[1005];
struct X{
	int x1,x2,x3;
};
X x[1005];
int sum,num1,num2,num3,N[4];
int cal(){
	N[1]=num1,N[2]=num2,N[3]=num3;
	sort(N+1,N+4);
	if(num1==num2==num3)
	sum+=200;
	if((num1==num2)||(num1==num3)||(num2==num3))
	sum+=100;
	if((num1+1==num2)&&(num2+1==num3))
	sum+=200;//���ж��Ƿ��������� 
	else if((N[1]+1==N[2])&&(N[2]+1==N[3]))//���û�У��ж�������Ƿ����� 
	sum+=100;
}
void roll(int i){
	//for(int j=1;j<=n;j++){
		num1+=x[i].x1,num2+=x[i].x2,num3+=x[i].x3;//����ת�˼��� 
		num1%=n,num2%=n,num3%=n;//ȡ�� 
		cal();
	//}
}
int main() {
   ios::sync_with_stdio(false);
   cin.tie(0);
   cout.tie(0);
   cin>>n;
   for(int i=1;i<=n;i++){
   	cin>>a[i];
   }
   for(int i=1;i<=n;i++){
   	cin>>b[i];
   }
   for(int i=1;i<=n;i++){
   	cin>>c[i];
   }
   cin>>m;
   for(int i=1;i<=m;i++){
   	cin>>x[i].x1>>x[i].x2>>x[i].x3;
   }
   for(int i=1;i<=m;i++){
   	roll(i);
   }
   cout<<sum;
   return 0;
}
