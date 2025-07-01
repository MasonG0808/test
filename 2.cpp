#include <bits/stdc++.h>
using namespace std;

int box[7][7];//0表示黑，1表示白 
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int vis[7][7]; 
bool Full(){
	for(int i=1;i<=6;i++){
		for(int j=1;j<=6;j++){
			if(box[i][j]==-1)
			return false;
		}
	}
	return true;
}
bool judge(){
	//先考虑行 
	for(int i=1;i<=4;i++){
		for(int j=1;j<=4;j++){
		int cnt_b=0,cnt_w=0;
		if(box[i][j]==0){
			cnt_b++;
		}	
		if(box[i][j]==1){
			cnt_w++;
		}
		if(box[i][j]==box[i][j+1]==box[i][j+2])
		return false;//行相等 
	
		if(cnt_b!=cnt_w)
		return false;
		}

	}
	for(int i=1,j=1;i<=5;i++){
		
		if((box[i][j]==box[i+1][j])&&(box[i][j+1]==box[i+1][j+1])&&(box[i][j+2]==box[i+1][j+2])&&(box[i][j+3]==box[i+1][j+3])&&(box[i][j+4]==box[i+1][j+4])&&(box[i][j+5]==box[i+1][j+6]))
		 return false;
	
		}
	for(int j=1,i=1;j<=5;j++){
		if((box[i][j]==box[i][j+1])&&(box[i+1][j+1]==box[i+1][j+1])&&(box[i+2][j+1]==box[i+2][j+1])&&(box[i+3][j+1]==box[i+3][j+1])&&(box[i+4][j+1]==box[i+=4][j+1])&&(box[i+5][j+1]==box[i+5][j+1]))
		 return false;
	}	
	for(int i=1;i<=4;i++){
		for(int j=1;j<=4;j++){
		int cnt_b=0,cnt_w=0;
		if(box[j][i]==0){
			cnt_b++;
		}	
		if(box[j][i]==1){
			cnt_w++;
		}	
		if(box[j][i]==box[j+1][i]==box[j+2][i])
		return false;//列相等 
		if(cnt_b!=cnt_w)
		return false;
		}
	}
	return true;
}
void dfs(int x,int y){
	if(Full()){//如果棋盘满了，开始判断 
	if(!judge()){//如果判断失败，则返回 
		return;
	}
	}
	for(int i=0;i<4;i++){
		int xx=x+dx[i];
		int yy=y+dy[i];
		if(xx>6||xx<1||yy>6||yy<1||vis[xx][yy]){
			continue;
		}
		if(box[xx][yy]==-1)//如果还未标记 
		{
			box[xx][yy]=0;//标记为黑 
			vis[xx][yy]=1;//来过 
			dfs(xx,yy);//继续搜索 
			box[xx][yy]=1;//若不行，回溯，标记为白 
			dfs(xx,yy); 
			vis[xx][yy]=0;//回溯 
		}
		vis[xx][yy]=1;
		dfs(xx,yy);
		vis[xx][yy]=0;
		
	}
}
int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  memset(box,-1,sizeof(box));//-1为未标记 
  memset(vis,0,sizeof(vis)) ;
  box[1][1]=0,box[1][2]=1,box[1][4]=1,box[2][4]=1;
  box[3][5]=1,box[3][6]=1,box[3][4]=0,box[4][4]=0,box[5][4]=1,box[6][4]=0;
  box[5][3]=0,box[5][6]=0,box[6][2]=1,box[6][5]=0;
  vis[1][1]=1;
  dfs(1,1);//从原点开始搜索 
  for(int i=1;i<=6;i++){
  	for(int j=1;j<=6;j++){
  		cout<<box[i][j]<<" "; 
	  }
	  cout<<endl;
  }
  return 0;
}
