#include "../include/DxLib.h";
#include "key.h";

//タイトル画面
//メニューをだして、0：ゲームスタート	1:記録を見る	2:終了
//0の場合はこのtitleファイル内で難易度設定までやって→gameファイルの方に跳ぶ	1:記録表示ファイルへ飛ぶ　2:ゲームを終了

// メニュー項目の表示に必要な構造体を用意する
typedef struct{
        int x, y;       // 座標格納用変数
        char name[128]; // 項目名格納用変数
}titleMenu_t ;

// メニュー項目要素を5つ作る
        titleMenu_t MenuElement[4]={
                {  80, 250, "ゲームスタート" }, // タグの中身の順番で格納される。xに80が、yに100が、nameに"ゲームスタート"が
                { 100, 300, "レコード" },
                { 100, 350, "ヘルプ" },
                { 100, 400, "ゲーム終了" },
        };
		titleMenu_t menuDifficulty[3]={
                {  80, 250, "Easy" }, // タグの中身の順番で格納される。xに80が、yに100が、nameに"ゲームスタート"が
                { 100, 300, "Normal" },
                { 100, 350, "Hard" }
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
			if(CheckStateKey(KEY_INPUT_DOWN)== 1 ||CheckStateKey(KEY_INPUT_UP)== 1 ){ // 下キーか、上キーが押された瞬間
					for(int i=0; i<n;i++ ){              // メニュー項目数である5個ループ処理
						if(i==selectNum){          // 今処理しているのが、選択番号と同じ要素なら
							tM[i].x = 80; // 座標を80にする
						} else {                       // 今処理しているのが、選択番号以外なら
							tM[i].x = 100;// 座標を100にする
						}
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
			break;
		case 2:	//はい/いいえの場面の場合
			break;
		default:
			//終了
			DxLib_End();//ＤＸライブラリ終了処理
			break;

		}
	}

	//計算フェーズ
	switch(selectPage){
	case 0:	//最初の場面→ゲームスタートを選択するときまで。
		menuCalc(MenuElement,4);
		break;
	case 1:	//難易度選択場面の時。
		menuCalc(menuDifficulty,3);
		break;
	case 2:	//はい/いいえの場面の時、確認した場合は選択した難易度をゲーム本体に渡す。
		break;
	default:
		break;
	}


	// 描画フェーズ

	//タイトル表示
	DrawFormatString( 240, 100, GetColor(255,255,255), "Sudoku for PC" );
	//メニュー表示分岐
	switch(selectPage){
	case 0:	//ゲームスタートまでの
		menuDraw(MenuElement,4);
		break;
	case 1:	//難易度選択の時
		 menuDraw(menuDifficulty,3);
		break;
	case 2:
		break;
	}
	return 0;
}

