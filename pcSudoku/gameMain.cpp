#include "../include/DxLib.h";
#include "key.h";

//�Q�[���{�̕���

//�ϐ�
int difficulty=-1;	//title.cpp���őI�������Փx-0�`2�Ő������f�J���قǓ�Փx���� -1�̓G���[�p
int setIni=0;	//�������s����邩�ǂ����̔���B

//�Q�[���{�́A�Ƃ�܈ʒu���Ǝ����Ă��鐔�l�̂�
typedef struct{
        int num; //���l
}gameNumParts;

//���ۏ������ރ{�[�h�A0�������p�A1�������ɋ󔒂�����Ď��ۃv���C���[�ɉ������镔��
gameNumParts gameBord[2][9][9];

//�e�֐��Ƃ�

//�������g
void setNumberField(int dif){
	//�g���}������
	for(int i=0;i<2;i++){
		for(int j=0;j<9;j++){
			for(int k=0;k<9;k++){
				gameBord[i][j][k].num=0;
			}
		}
	}

	//�����̔����BgameBord[0][][]



	//���ۃv���C���[�ɉ�����������
}


//�擾�E�Z�b�g�g
void setDifficulty(int d){
	//��Փx�ݒ� ��Փxdifficulty��d���
	difficulty=d;
}
int getDifficulty(){
	//��Փx�擾
	return difficulty;
}


//�v�Z�g
void calcField(){
	//�����Ɖߌv�Z����{�̕���
}


//�`��g
void drawField(){
	//�Ֆʕ`��֐�
	//9*9�}�X�����͏c�����ꂼ��10�{
		//�n�_���W
	int xIni=25;
	int yIni=25;
	int length=360+5*9;	//�S�̂̒���
	int lengthParts=length/9;
	for(int i=0;i<10;i++){
		//����
		DrawLine(xIni,yIni+i*lengthParts,xIni+length,yIni+i*lengthParts,GetColor(255,255,255)) ;
		//�c��
		DrawLine(xIni+i*lengthParts,yIni,xIni+i*lengthParts,yIni+length,GetColor(255,255,255)) ;
	}
		//�����`��
	for(int k=0;k<9;k++){
		for(int j=0;j<9;j++){
			DrawFormatString(xIni+k*lengthParts+lengthParts/2,yIni+j*lengthParts+lengthParts/2, GetColor(255,255,255),"%d",gameBord[0][k][j].num);
		}
	}
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
