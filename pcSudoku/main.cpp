#include "include.h"

//���[�v�ŕK���s���R�又��
int ProcessLoop(){
	if(ProcessMessage()!=0)return -1;//�v���Z�X�������G���[�Ȃ�-1��Ԃ�
	if(ClearDrawScreen()!=0)return -1;//��ʃN���A�������G���[�Ȃ�-1��Ԃ�
	GetHitKeyStateAll_2();//���݂̃L�[���͏������s��
	return 0;
}


int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int nCmdShow){
	ChangeWindowMode(TRUE);//�E�B���h�E���[�h���j
	
	if(DxLib_Init() == -1 || SetDrawScreen( DX_SCREEN_BACK )!=0) return -1;//�������Ɨ���ʉ�

	//����������

	while(ProcessLoop()==0&&CheckStateKey(KEY_INPUT_ESCAPE)==0){//���C�����[�v
		//�����ɏ���

		//�^�C�g����ʍ쐬
		titleMain();



		//�����ɏ���

		ScreenFlip();//����ʔ��f
	}

	DxLib_End();//�c�w���C�u�����I������
	return 0;
}



