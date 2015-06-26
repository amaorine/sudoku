#include "../include/DxLib.h";
#include "key.h";

//C++のライブラリ
#include <iostream>
#include <algorithm>
#include <time.h>
using namespace std;

//ゲーム本体部分

//変数
int difficulty=-1;	//title.cpp内で選択する難易度-0～2で数字がデカいほど難易度高い -1はエラー用
int setIni=0;	//初期化行動取るかどうかの判定。
const int n=9;
//入れる基準の数字
int num[n]={1,2,3,4,5,6,7,8,9};
//
int bord[2][9][9];


//ゲーム本体、とりま位置情報と持っている数値のみ
typedef struct{
        int num; //数値
}gameNumParts;

//実際書き込むボード、0→答え用、1→答えに空白を作って実際プレイヤーに解かせる部分
gameNumParts gameBord[2][9][9];

//各関数とか



//初期化時に使う,セットした数字が合っているかの判定

int jnRange(int x,int y){
	int xRange=x/3*3;
	int yRange=y/3*3;

	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(!(x==i+xRange&&y==j+yRange)){
				if(bord[0][x][y]==bord[0][i+xRange][j+yRange]){
					return 1;
				}				
			}
		}
	}

	return 0;
}





void sortHight(){
int n=0;	//取り換えする時の文字
int k,l,m;	//並び替えに使う
int count[9];	//被ってないかチェック



//縦で上から見て行って、配列bord[0][i][0]とかぶった配列bord[0][j][任意]を、配列bord[0][j][9-1]の様は指定されたやつの隣と交換。

//1-9が縦列内での数字の個数を数える

	for(int h=0;h<9;h++){
		for(int i=0;i<9;i++){
			count[i]=0;
		}

		for(int i=0;i<9;i++){
			count[bord[0][i][h]-1]++;
		}

		//checkNum[i]
		for(int i=0;i<9;i++){
			//count[i]が
			//0→同列にあるcount[i]==0の数とcount[i]==2の数交換
			//2→同列にあるcount[i]==0の数とcount[i]==2の数交換
			//1→何もしない
			while(count[i]>1){
				//個数が1以外の場合は被ってるか足りないかなので交換処理
				for(int j=0;j<9;j++){
					//j bord[0][j][0]
					if(bord[0][j][h]-1==i){
						//iとbord[0][j][0]の中身一致
						for(int k=8;k>h;k--){
							//k bord[0][j][k]
							if(count[bord[0][j][k]-1]==0){
								//count[bord[0][j][k]]の値が1とcount[i]以外の場合
								//=count[i]=0ならば2,count[i]==2ならば0の場合
								//交換
								int n=bord[0][j][k];
								bord[0][j][k]=bord[0][j][h];
								bord[0][j][h]=n;

								for(int m=0;m<9;m++){
									count[m]=0;
								}

								for(int m=0;m<9;m++){
									count[bord[0][m][h]-1]++;
								}
							}
						}
					}
				}
			}
		}

	}


}


//初期化組
void setNumberField(int dif){
	//j=y,k=x

//	srand((unsigned)time(NULL));


	//とりまnum[]で初期化
	for(int i=0;i<2;i++){
		for(int j=0;j<9;j++){
			for(int k=0;k<9;k++){
				bord[i][j][k]=0;

			}	
		}	
	}


	//子為の場面　0　作る
	for(int j=0;j<9;j++){
		for(int k=0;k<9;k++){
			bord[0][j][k]=num[k];
			}	
	}	
	//横でランダム入れ買
	for(int i=0;i<9;i++){
		std::random_shuffle(bord[0][i],bord[0][i]+n);
	}

	//被らないように判定処理
	//縦ラインでかぶった時の処理
	sortHight();

	//3*3のブロック内でかぶった時の処理



	//実際プレイヤーに解かせる板を作る


	


}


//取得・セット組
void setDifficulty(int d){
	//難易度設定 難易度difficultyにd代入
	difficulty=d;
}
int getDifficulty(){
	//難易度取得
	return difficulty;
}


//計算組
void calcField(){
	//数字と過計算する本体部分
}


//描画組
void drawField(){
	//盤面描画関数
	//9*9マス→線は縦横それぞれ10本
		//始点座標
	int xIni=25;
	int yIni=25;
	int length=360+5*9;	//全体の長さ
	int lengthParts=length/9;
	for(int i=0;i<10;i++){
		//横線
		DrawLine(xIni,yIni+i*lengthParts,xIni+length,yIni+i*lengthParts,GetColor(255,255,255)) ;
		//縦線
		DrawLine(xIni+i*lengthParts,yIni,xIni+i*lengthParts,yIni+length,GetColor(255,255,255)) ;
	}
		//数字描画
		//とりあえずgameBord[0]のやつ描画してるけどこれは答え用なので描画すべきなのは[1]の方
	for(int k=0;k<9;k++){
		for(int j=0;j<9;j++){
			DrawFormatString(xIni+j*lengthParts+lengthParts/2,yIni+k*lengthParts+lengthParts/2, GetColor(255,255,255),"%d",bord[0][k][j]);
		}
	}
	
}





//ゲームメイン
int gameMain(){
	//ゲーム画面全体のメイン
	//戻り値は画面切り替えしない限り必ず3
	if(setIni==0){
		setNumberField(getDifficulty());
		setIni=1;
	}


	drawField();


	
	DrawFormatString( 240, 100, GetColor(255,255,255), "geme" );
	DrawFormatString( 240, 150, GetColor(255,255,255), "gemeD:%d",getDifficulty());

	return 3;
}
