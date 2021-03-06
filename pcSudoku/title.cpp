#include "../include/DxLib.h";
#include "key.h";
#include "gameMain.h";

//タイトル画面
//メニューをだして、0：ゲームスタート	1:記録を見る	2:終了
//0の場合はこのtitleファイル内で難易度設定までやって→gameファイルの方に跳ぶ	1:記録表示ファイルへ飛ぶ　2:ゲームを終了

// メニュー項目の表示に必要な構造体を用意する
typedef struct{
        int x, y;       // 座標格納用変数
        char name[128]; // 項目名格納用変数
}titleMenu_t ;

//メニュー項目を2次元配列化
titleMenu_t menuElement[3][4]={
	{
		//[0][0-3]最初のメニュー画面
		{  80, 250, "ゲームスタート" },
        { 100, 300, "レコード" },
        { 100, 350, "ヘルプ" },
        { 100, 400, "ゲーム終了" }
	},
	{
		//[1][0-2]難易度選択画面
		{  80, 250, "Easy" }, 
        { 100, 300, "Normal" },
        { 100, 350, "Hard" }
	},
	{
		//[2][0-1]難易度確認画面
		{  80, 250, "yes" }, 
        { 100, 300, "no" }
	}
		};

//変数
//現在選択されてる部分
int selectNum=0;
int selectPage=0;

//変数


//メニュー系関数
	//メニュー計算
	void menuCalc(titleMenu_t* tM,int n){
			if(CheckStateKey(KEY_INPUT_DOWN)==1){
				selectNum = (selectNum+1) %n;
			}
			//十字↑キー押された場合
			else if(CheckStateKey(KEY_INPUT_UP)==1){
				selectNum = (selectNum+n-1) %n;
			}
					for(int i=0; i<n;i++ ){              // メニュー項目数である5個ループ処理
						if(i==selectNum){          // 今処理しているのが、選択番号と同じ要素なら
							tM[i].x = 80; // 座標を80にする
						} else {                       // 今処理しているのが、選択番号以外なら
							tM[i].x = 100;// 座標を100にする
						}
					}

	}

	//メニュー表示
	void menuDraw(titleMenu_t* tM,int n){
			for( int i=0; i<n; i++ ){ // メニュー項目を描画
			DrawFormatString(tM[i].x,tM[i].y, GetColor(255,255,255),tM[i].name );
		}
	}

//メニュー系関数ここまでウ

//タイトル画面
int titleMain(){
	if(CheckStateKey(KEY_INPUT_Z)==1){
		switch(selectPage){
			//title→難易度選択→ゲームスタートまでの処理はタイトル画面でやるのでここで分ける。
		case 0:	//ゲーム起動時の画面の場合
				switch(selectNum){
				case 0:
					//ゲーム難易度選択画面になる
					selectPage=1;
					break;
				case 1:
					//スコア画面に移動
					return 1;
					break;
				case 2:
					//ヘルプ画面へ
					return 2;
					break;
				default:
					//終了
					DxLib_End();//ＤＸライブラリ終了処理
					break;
				}
				break;
		case 1:	//難易度選択画面の場合
			//カーソルの位置で難易度判定→トリマ保持
			setDifficulty(selectNum);
			selectPage=2;	//はい/いいえへ
			break;
		case 2:	//はい/いいえの場面の場合
			if(selectNum==0){
				//ハイの場合は難易度渡してゲーム画面へ

				return 3;
			}
			else{
				//ノーなら戻す
				//初期火曜
				setDifficulty(-1);
				selectPage=1;
			}
			break;
		default:
			//終了
			DxLib_End();//ＤＸライブラリ終了処理
			break;

		}
		selectNum=0;
	}
	else if(CheckStateKey(KEY_INPUT_X)==1){
		//Xボタンで戻るときの操作。このファイル内での切り替え動作なので、見る値はselectPageのみ
		switch(selectPage){
		case 0:	//タイトルの最初
			selectNum=3;	//一番下の終了操作までカーソル持ってく
			break;
		case 1:	//難易度選択画面なのでタイトル画面に戻す
			selectPage=0;
			break;
		case 2:	//yes/no画面なので難易度選択画面に戻す
			selectPage=1;
			break;
		default:
			//終了
			DxLib_End();//ＤＸライブラリ終了処理
			break;
		}
	}

	//計算フェーズ
	//menuElement[selectPage]の要素数=selectPage=0,1,2の時4,3,2なので4-selectPageで出せる
		menuCalc(menuElement[selectPage],4-selectPage);


	// 描画フェーズ

	//タイトル表示
	DrawFormatString( 240, 100, GetColor(255,255,255), "Sudoku for PC" );
	DrawFormatString( 240, 150, GetColor(255,255,255), "Snm:%d",selectNum );
	DrawFormatString( 240, 200, GetColor(255,255,255), "SPa:%d",selectPage );
	//メニュー表示分岐
	menuDraw(menuElement[selectPage],4-selectPage);
	return 0;
}

