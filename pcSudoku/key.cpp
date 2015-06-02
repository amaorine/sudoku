#include "../include/DxLib.h";

 int stateKey[256];

int GetHitKeyStateAll_2(){
	char GetHitKeyStateAll_Key[256];
	GetHitKeyStateAll( GetHitKeyStateAll_Key );
for(int i=0;i<256;i++){
	if(GetHitKeyStateAll_Key[i]==1) stateKey[i]++;
	else                            stateKey[i]=0;
}
	return 0;
}
//キー状態確認
int CheckStateKey(unsigned char Handle){
	return stateKey[Handle];
}

void key_test(){
        DrawFormatString( 0, 0, GetColor(255,255,255), "分割出来ています" );
} 

