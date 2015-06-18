#include "../include/DxLib.h";
#include "key.h";

//ゲーム本体部分

//変数
int difficulty=-1;	//title.cpp内で選択する難易度-0～2で数字がデカいほど難易度高い -1はエラー用

//各関数とか
void drawField(){
	//盤面描画関数
	//9*9マス→線は縦横それぞれ10本
	//始点座標
	int xIni=25;
	int yIni=25;
	int length=360+5*9;	//全体の長さ
	for(int i=0;i<10;i++){
		//横線
		DrawLine(xIni,yIni+i*length/9,xIni+length,yIni+i*length/9,GetColor(255,255,255)) ;
		//縦線
		DrawLine(xIni+i*length/9,yIni,xIni+i*length/9,yIni+length,GetColor(255,255,255)) ;
	}
}



void setDifficulty(int d){
	//難易度設定 難易度difficultyにd代入
	difficulty=d;
}
int getDifficulty(){
	//難易度取得
	return difficulty;
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
