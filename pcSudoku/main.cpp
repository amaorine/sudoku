#include "include.h"

//ループで必ず行う３大処理
int ProcessLoop(){
	if(ProcessMessage()!=0)return -1;//プロセス処理がエラーなら-1を返す
	if(ClearDrawScreen()!=0)return -1;//画面クリア処理がエラーなら-1を返す
	GetHitKeyStateAll_2();//現在のキー入力処理を行う
	return 0;
}


int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow){
	ChangeWindowMode(TRUE);//ウィンドウモード撃破
	
	if(DxLib_Init() == -1 || SetDrawScreen( DX_SCREEN_BACK )!=0) return -1;//初期化と裏画面化

	//初期化処理

	while(ProcessLoop()==0&&CheckStateKey(KEY_INPUT_ESCAPE)==0){//メインループ
		//ここに処理

		//タイトル画面作成
		titleMain();



		//ここに処理

		ScreenFlip();//裏画面反映
	}

	DxLib_End();//ＤＸライブラリ終了処理
	return 0;
}



