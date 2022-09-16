#include<bits/stdc++.h>
#include<time.h>
#include<conio.h>
using namespace std;
typedef long long ll;
const int N=100;

int sx[9]={0, 1, 1, 0,-1,-1,-1, 0, 1};
int sy[9]={0, 0, 1, 1, 1, 0,-1,-1,-1};
int a[N][N];//field
int b[N][N];//opened(0=close,1=open,2=flag)
int x,y,n,m;//x=line y=col n=height m=width
int p,p1,p2;//number of mines,opened,flags
int z;//zhuangtai,1=play,2=lost,3=win
ll stt,et,tt;//start time,end time,pause time
int rn=20,rm=20,rp=50;


void back(int n=200){
	while(n--) printf("\b");
}
void exitx(){
	exit(0);
}
void ppx(int op){
	if(op==1) tt=time(0);
	
}
void pausex(){
	system("cls");
	system("title D:\\B3-C++????\\2022??\\16\\mor\\T1????.exe");
	int ra=rand()%64+32,rb=rand()%16+8;
	for(int i=1;i<=ra;i++){
		printf("%d: ",ra);
		for(int j=1;j<=rb;j++) printf("%3d ",rand()%256);
		printf("\n");
	}
	printf("\n"); 
	printf("--------------------------------\n");
	printf("Process exited after %.2f seconds with return value %d\n",
		rand()/100.0,0);
	system("pause");
	system("title Minesweeper");
}
/*void setting(){
	system("cls");
	printf
}*/

void end(int zz){
	z=zz;
	et=time(0);
	x=y=0;
}
void opn(int x,int y){
	if(a[x][y]==10){end(2);return;}
	if(b[x][y]==1||x<1||x>n||y<1||y>m) return;
	b[x][y]=1;p1++;
	if(p1==n*m-p){end(3);return;}
	if(a[x][y]==0)
		for(int v=1;v<=8;v++)
			if(a[x+sx[v]][y+sy[v]]!=10) opn(x+sx[v],y+sy[v]);
}
void opd(int x,int y){
	int cnt=0;//zhou wei flag shu
	for(int v=1;v<=8;v++) 
		if(b[x+sx[v]][y+sy[v]]==2) cnt++;
	if(cnt==a[x][y]) 
		for(int v=1;v<=8;v++) 
			if(b[x+sx[v]][y+sy[v]]!=2) opn(x+sx[v],y+sy[v]);
}
void flg(int x,int y){
	if(b[x][y]==2){
		b[x][y]=0;p2--;
	}else if(b[x][y]==0){
		b[x][y]=2;p2++;
	}
}
void start(){
	system("title Minesweeper");
	srand(time(0));
	n=rn,m=rm,p=rp;
	x=n/2,y=m/2;
	p1=0,p2=0,z=1;
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	for(int i=1;i<=p;i++){
		int tx=rand()%n+1,ty=rand()%m+1;
		if(a[tx][ty]==10||(x-1<=tx&&tx<=x+1&&y-1<=ty&&ty<=y+1)){
			i--;continue;
		}
		a[tx][ty]=10;
		for(int v=1;v<=8;v++) 
			if(a[tx+sx[v]][ty+sy[v]]!=10)a[tx+sx[v]][ty+sy[v]]++;
	}
	opn(x,y);
	stt=time(0);
}
void print(){
	system("cls");
	ll t1;
	if(z==1) t1=time(0)-stt;
	else t1=et-stt;
	if(z==2) printf("You lost!\n");
	if(z==3) printf("You win!\n");
	printf("time %2lld:%2lld    pos l:%2d,c:%2d\n",t1/60,t1%60,x,y);
	printf("flag %2d/%2d    open %3d/%3d\n\n",p2,p,p1,n*m-p);
	for(int i=1;i<=n;i++) printf("--");
	printf("-\n");
	for(int i=1;i<=n;i++){
		printf("|");
		for(int j=1;j<=m;j++){
			if(x==i&&y==j) printf("\b[");
			if(b[i][j]==1||z==2){
				if(a[i][j]==0) printf(" ");
				else if(a[i][j]==10) printf("*");
				else printf("%c",a[i][j]+'0');
			}
			else if(b[i][j]==2) printf("F");
			else printf("#");
			if(x==i&&y==j) printf("]");
			else printf(" ");
		}
		if(x!=i||y!=m) printf("\b|");
		printf("\n");
	}
	for(int i=1;i<=n;i++) printf("--");
	printf("-\n");
}
void play(){
	bool fl=1;
	while(fl){
		int ch=getch();
		fl=0;
		switch(ch){
			case 'w': case 'W': if(z==1&&x>1) x--; break;
			case 'a': case 'A': if(z==1&&y>1) y--; break;
			case 's': case 'S': if(z==1&&x<n) x++; break;
			case 'd': case 'D': if(z==1&&y<m) y++; break;
			
			case 'j': case 'J': if(z!=1) break;
			else{
				if(b[x][y]==1) opd(x,y);
				else if(b[x][y]==0) opn(x,y); 
				break;
			}
			case 'k': case 'K': if(z!=1) break;
			else{
				if(b[x][y]==1) opd(x,y); else flg(x,y); break;
			}
			
		//	case ';': case '\'': setting();break;
			case '-': case '=': start();break;
			case '\\': case '`': exitx();break;
			default: pausex();break;
		}
	}
}
int main(){
	start();
	while(1){
		print();
		play();
	}
	return 0;
}
