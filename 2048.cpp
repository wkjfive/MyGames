#include<bits/stdc++.h>
#include<time.h>
#include<conio.h>
#include<windows.h>
using namespace std;
HANDLE handle=GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_CURSOR_INFO CursorInfo;
int a[4][4];//map
string st[]={
	"      ",
	"   2  ",
	"   4  ",
	"   8  ",
	"  16  ",
	"  32  ",
	"  64  ",
	"  128 ",
	"  256 ",
	"  512 ",
	" 1024 ",
	" 2048 ",
	" 4096 ",
	" 8192 ",
	" 16384",
	" 32768",
	" 65536",
	"131072",
	"262144",
	"524288"};
int score,tmx,hib,size=4,winnum=11;
int move;

void hide(){
	system("cls");
	system("title ");
	system("mode con lines=1 cols=20");
}
void initsc(){
	GetConsoleCursorInfo(handle,&CursorInfo);//获取控制台光标信息	 
	CursorInfo.bVisible=false; //隐藏控制台光标 
	SetConsoleCursorInfo(handle,&CursorInfo);//设置控制台光标状态 
	system("title 2048");
	system("mode con lines=22 cols=30");
}
void newx(){
	int cx,cy,tp;
	while(1){
		cx=rand()%size;
		cy=rand()%size;
		tp=rand()%2+1;//1~2
		if(!a[cx][cy]) break;
	}
	a[cx][cy]=tp;
}
void init(){
	initsc();
	memset(a,0,sizeof(a));
	score=0;
	tmx=-1;
	hib=0;
	newx();
}
void exitx(){
	CursorInfo.bVisible=true;
	SetConsoleCursorInfo(handle,&CursorInfo);//设置控制台光标状态 
	system("cls");
	system("mode con cols=80 lines=300");
	exit(0);
}

void update(){
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			hib=max(hib,a[i][j]);
		}
	}
}
void print(){
	system("cls");
	cout<<"2048 v1.2 by wkj\n";
	cout<<"time:"<<tmx<<"\n"<<
	"score:"<<score<<"\n"<<
	"highest block:"<<(1<<hib)<<"\n";
	
	cout<<"-----------------------------\n";//29
	for(int i=0;i<size;i++){
		cout<<"|      |      |      |      |\n";
		cout<<"|";
		for(int j=0;j<size;j++){
			int x=a[i][j];
			if(x<20) cout<<st[x];
			else cout<<"2^"<<setw(4)<<x;
			cout<<"|";
		}
		cout<<"\n";
		cout<<"|      |      |      |      |\n";
		cout<<"-----------------------------\n";//29
	}
	
}
void tttttt(){
/*
bool up(){
	bool fl=0;
	for(int j=1;j<=4;j++){
		for(int i=3;i>=1;i--){
			if(a[i][j]==0){
				for(int k=i+1;k<=4;k++) a[k-1][j]=a[k][j];
				a[4][j]=0;
				fl=1;
			}
		}
		if(fl) continue;
		for(int i=1;i<=3;i++){
			if(a[i][j]!=a[i+1][j]||a[i][j]==0) continue;
			a[i][j]+=1;
			for(int k=i+2;k<=4;k++) a[k-1][j]=a[k][j];
			a[4][j]=0;
			fl=1;
			break;
		}
	}
	return fl;
}
bool down(){
	bool fl=0;
	for(int j=1;j<=4;j++){
		for(int i=2;i<=4;i++){
			if(a[i][j]==0){
				for(int k=i-1;k>=1;k--) a[k+1][j]=a[k][j];
				a[1][j]=0;
				fl=1;
			}
		}
		if(fl) continue;
		for(int i=4;i>=2;i--){
			if(a[i][j]!=a[i-1][j]||a[i][j]==0) continue;
			a[i][j]+=1;
			for(int k=i-2;k>=1;k--) a[k+1][j]=a[k][j];
			a[1][j]=0;
			fl=1;
			break;
		}
	}
	return fl;
}
bool left(){
	bool fl=0;
	for(int i=1;i<=4;i++){
		for(int j=1;j<=3;j++){
			if(a[i][1]==0){
				for(int k=2;k<=4;k++) a[i][k-1]=a[i][k];
				a[i][4]=0;
				fl=1;
			}
		}
		if(fl) continue;
		for(int j=1;j<=3;j++){
			if(a[i][j]!=a[i][j+1]||a[i][j]==0) continue;
			a[i][j]+=1;
			for(int k=i+2;k<=4;k++) a[i][k-1]=a[i][k];
			a[i][4]=0;
			fl=1;
			break;
		}
	}
	return fl;
}
bool right(){
	bool fl=0;
	for(int i=1;i<=4;i++){
		for(int j=2;j<=4;j++){
			if(a[i][6-j]==0){
				for(int k=3;k>=1;k--) a[i][k+1]=a[i][k];
				a[i][1]=0;
				fl=1;
			}
		}
		if(fl) continue;
		for(int j=4;j>=2;j--){
			if(a[i][j]!=a[i][j-1]||a[i][j]==0) continue;
			a[i][j]+=1;
			for(int k=i-2;k>=1;k--) a[i][k+1]=a[i][k];
			a[i][1]=0;
			fl=1;
			break;
		}
	}
	return fl;
}*/ }
int win(){
    for(int i=0;i<size;i++)
        for(int j=0;j<size;j++)
            if(a[i][j]==winnum) return 1;
    return 0;
}
int fail(){
    for(int i=0;i<size;i++)
        for(int j=0;j<size;j++)
            if(!a[i][j]
			||(j<size-1&&a[i][j+1]==a[i][j])
			||(i<size-1&&a[i+1][j]==a[i][j])) return 0;
    return 1;
}
int up(){
    move=0;
    for(int j=0;j<size;j++){
        int last=-1,ts=0;
        for(int i=0;i<size;i++){
            if(!a[i][j]){
                if(last==-1) last=i;
            }else
                if(last!=-1) swap(a[i][j],a[last][j]),move=1,last++;
        }
    }
    for(int j=0;j<size;j++)
        for(int i=0;i<size-1;i++)
            if(!a[i][j]) break;
            else if(a[i][j]==a[i+1][j]){
                move=1;
                a[i][j]++;
                score+=1<<a[i][j];
                a[i+1][j]=0;
                for(int k=i+1;k<size-1;k++){
                    a[k][j]=a[k+1][j];
                    a[k+1][j]=0;
                }
            }
    return move;
}
int down(){
    move=0;
    for(int j=0;j<size;j++){
        int last=-1,ts=0;
        for(int i=size-1;i>=0;i--){
            if(!a[i][j]){
                if(last==-1) last=i;
            }else
                if(last!=-1) swap(a[i][j],a[last][j]),move=1,last--;
        }
    }
    for(int j=0;j<size;j++)
        for(int i=size-1;i>=1;i--)
            if(!a[i][j]) break;
            else if(a[i][j]==a[i-1][j]){
                move=1;
                a[i][j]++;
                score+=1<<a[i][j];
                a[i-1][j]=0;
                for(int k=i-1;k>=1;k--){
                    a[k][j]=a[k-1][j];
                    a[k-1][j]=0;
                }
            }
    return move;
}
int left(){
    move=0;
    for(int i=0;i<size;i++){
        int last=-1,ts=0;
        for(int j=0;j<size;j++){
            if(!a[i][j]){
                if(last==-1) last=j;
            }else
                if(last!=-1) swap(a[i][j],a[i][last]),move=1,last++;
        }
    }
    for(int i=0;i<size;i++)
        for(int j=0;j<size-1;j++)
            if(!a[i][j]) break;
            else if(a[i][j]==a[i][j+1]){
                move=1;
                a[i][j]++;
                score+=1<<a[i][j];
                a[i][j+1]=0;
                for(int k=j+1;k<size-1;k++){
                    a[i][k]=a[i][k+1];
                    a[i][k+1]=0;
                }
            }
    return move;
}
int right(){
    move=0;
    for(int i=0;i<size;i++){
        int last=-1,ts=0;
        for(int j=size-1;j>=0;j--){
            if(!a[i][j]){
                if(last==-1) last=j;
            }else
                if(last!=-1) swap(a[i][j],a[i][last]),move=1,last--;
        }
    }
    for(int i=0;i<size;i++)
        for(int j=size-1;j>=1;j--)
            if(!a[i][j]) break;
            else if(a[i][j]==a[i][j-1]){
                move=1;
                a[i][j]++;
                score+=1<<a[i][j];
                a[i][j-1]=0;
                for(int k=j-1;k>=1;k--){
                    a[i][k]=a[i][k-1];
                    a[i][k-1]=0;
                }
            }
    return move;
}

void play(){
	scr:
	char ch=getch();
	switch(ch){
		case 'w':case 'W':case 'H'://case char(72):
		if(!up()) goto scr;
		break;
		case 'a':case 'A':case 'K'://case char(75):
		if(!left()) goto scr;
		break;
		case 's':case 'S':case 'P'://case char(80):
		if(!down()) goto scr;
		break;
		case 'd':case 'D':case 'M'://case char(77):
		if(!right()) goto scr;
		break;
		case 'q':case'Q':exitx();
		case 'e':case'E':init();return ;
		case ' ':hide();getch();initsc();print();goto scr;
		default:goto scr;
	}
	newx();
}

int main(){
	srand(time(NULL));
	init();
	
	while(1){
		tmx++;
		update(); 
		print();
		if(win()) cout<<"You win!"<<flush;
		else if(fail()) cout<<"You fail!"<<flush;
		play();
	}
	return 0;
}

