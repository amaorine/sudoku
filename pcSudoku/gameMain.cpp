#include "../include/DxLib.h";
#include "key.h";

//ゲーム本体部分

//変数
int difficulty=-1;	//title.cpp内で選択する難易度-0～2で数字がデカいほど難易度高い -1はエラー用
int setIni=0;	//初期化行動取るかどうかの判定。

//ゲーム本体、とりま位置情報と持っている数値のみ
typedef struct{
        int num; //数値
}gameNumParts;

//実際書き込むボード、0→答え用、1→答えに空白を作って実際プレイヤーに解かせる部分
gameNumParts gameBord[2][9][9];

//各関数とか

//初期化組
void setNumberField(int dif){
	//トリマ初期化
	for(int i=0;i<2;i++){
		for(int j=0;j<9;j++){
			for(int k=0;k<9;k++){
				gameBord[i][j][k].num=0;
			}
		}
	}

	//答えの板を作る。gameBord[0][][]



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
	for(int k=0;k<9;k++){
		for(int j=0;j<9;j++){
			DrawFormatString(xIni+k*lengthParts+lengthParts/2,yIni+j*lengthParts+lengthParts/2, GetColor(255,255,255),"%d",gameBord[0][k][j].num);
		}
	}
}





//ゲームメイン
int gameMain(){
	//ゲーム画面全体のメイン
	//戻り値は画面切り替えしない限り必ず3


	drawField();


	
	DrawFormatString( 240, 100, GetColor(255,255,255), "geme" );
	DrawFormatString( 240, 150, GetColor(255,255,255), "gemeD:%d",getDifficulty());

	return 3;
}
