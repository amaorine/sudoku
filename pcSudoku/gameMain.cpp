#include "../include/DxLib.h";
#include "key.h";

//�Q�[���{�̕���

//�ϐ�
int difficulty=-1;	//title.cpp���őI�������Փx-0�`2�Ő������f�J���قǓ�Փx���� -1�̓G���[�p

//�e�֐��Ƃ�
void drawField(){
	//�Ֆʕ`��֐�
	//9*9�}�X�����͏c�����ꂼ��10�{
	//�n�_���W
	int xIni=25;
	int yIni=25;
	int length=360+5*9;	//�S�̂̒���
	for(int i=0;i<10;i++){
		//����
		DrawLine(xIni,yIni+i*length/9,xIni+length,yIni+i*length/9,GetColor(255,255,255)) ;
		//�c��
		DrawLine(xIni+i*length/9,yIni,xIni+i*length/9,yIni+length,GetColor(255,255,255)) ;
	}
}



void setDifficulty(int d){
	//��Փx�ݒ� ��Փxdifficulty��d���
	difficulty=d;
}
int getDifficulty(){
	//��Փx�擾
	return difficulty;
}

//�Q�[�����C��
int gameMain(){
	//�Q�[����ʑS�̂̃��C��
	//�߂�l�͉�ʐ؂�ւ����Ȃ�����K��3
	drawField();



	DrawFormatString( 240, 100, GetColor(255,255,255), "geme" );
	DrawFormatString( 240, 150, GetColor(255,255,255), "gemeD:%d",getDifficulty());

	return 3;
}
