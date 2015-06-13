#include "../include/DxLib.h";
#include "key.h";

//ゲーム本体部分

//変数
int difficulty=-1;	//title.cpp内で選択する難易度-0～2で数字がデカいほど難易度高い -1はエラー用



//各関数とか
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



	DrawFormatString( 240, 100, GetColor(255,255,255), "geme" );
	DrawFormatString( 240, 150, GetColor(255,255,255), "gemeD:%d",getDifficulty());

	return 3;
}
