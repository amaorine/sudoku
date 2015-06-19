#include "../include/DxLib.h";
#include "key.h";

//C++�̃��C�u����
#include <iostream>

#include <algorithm>

using namespace std;

//�Q�[���{�̕���

//�ϐ�
int difficulty=-1;	//title.cpp���őI�������Փx-0�`2�Ő������f�J���قǓ�Փx���� -1�̓G���[�p
int setIni=0;	//�������s����邩�ǂ����̔���B
const int n=9;
//������̐���
int num[n]={1,2,3,4,5,6,7,8,9};
//
int bord[2][9][9];


//�Q�[���{�́A�Ƃ�܈ʒu���Ǝ����Ă��鐔�l�̂�
typedef struct{
        int num; //���l
}gameNumParts;

//���ۏ������ރ{�[�h�A0�������p�A1�������ɋ󔒂�����Ď��ۃv���C���[�ɉ������镔��
gameNumParts gameBord[2][9][9];

//�e�֐��Ƃ�



//���������Ɏg��,�Z�b�g���������������Ă��邩�̔���
int jnLine(int x,int y){
	int flagLine=0;

	return flagLine;
	
}
int jnRange(int x,int y){
	int xRange=x/3*3;
	int yRange=y/3*3;

	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			if(!(x==i+xRange&&y==j+yRange)){
				if(bord[0][x][y]==bord[0][i+xRange][j+yRange]){
					return 1;
				}				
			}
		}
	}

	return 0;
}


int judgeNum(int x,int y){
	//�c�E���E����3*3�}�X���Ő��������Ȃ�������0,�������1�Ԃ��B
	int jn=jnLine(x,y)||jnRange(x,y);
	return jn;
}


void sortHight(){

		for(int i=0;i<9;i++){
			if(i!=0){
				if(bord[0][0][0]==bord[0][i][0]){
					int num=bord[0][i][0];
					bord[0][i][0]=bord[0][i][1];
					bord[0][i][1]=n;
				}
			}
		}
}


//�������g
void setNumberField(int dif){
	//j=y,k=x




	//�Ƃ��num[]�ŏ�����
	for(int i=0;i<2;i++){
		for(int j=0;j<9;j++){
			for(int k=0;k<9;k++){
				bord[i][j][k]=0;

			}	
		}	
	}


	//�q�ׂ̏�ʁ@0�@���
	for(int j=0;j<9;j++){
		for(int k=0;k<9;k++){
			bord[0][j][k]=num[k];
			}	
	}	
	//���Ń����_�����ꔃ
	for(int i=0;i<9;i++){
		std::random_shuffle(bord[0][i],bord[0][i]+n);
	}

	//���Ȃ��悤�ɔ��菈��
	//�c���C���ł��Ԃ������̏���
	sortHight();

	//3*3�̃u���b�N���ł��Ԃ������̏���



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
		//�Ƃ肠����gameBord[0]�̂�`�悵�Ă邯�ǂ���͓����p�Ȃ̂ŕ`�悷�ׂ��Ȃ̂�[1]�̕�
	for(int k=0;k<9;k++){
		for(int j=0;j<9;j++){
			DrawFormatString(xIni+j*lengthParts+lengthParts/2,yIni+k*lengthParts+lengthParts/2, GetColor(255,255,255),"%d",bord[0][k][j]);
			DrawFormatString( 400, 150, GetColor(255,255,255), "x:%d",k);
			DrawFormatString( 400, 200, GetColor(255,255,255), "y:%d",j);

		}
	}

	DrawFormatString( 200, 300, GetColor(255,255,255), "jn:%d",judgeNum(0,0));
	DrawFormatString( 200, 350, GetColor(255,255,255), "jnL:%d",jnLine(0,0));
	DrawFormatString( 200, 400, GetColor(255,255,255), "jnR:%d",jnRange(0,0));
	
}





//�Q�[�����C��
int gameMain(){
	//�Q�[����ʑS�̂̃��C��
	//�߂�l�͉�ʐ؂�ւ����Ȃ�����K��3
	if(setIni==0){
		setNumberField(getDifficulty());
		setIni=1;
	}


	drawField();


	
	DrawFormatString( 240, 100, GetColor(255,255,255), "geme" );
	DrawFormatString( 240, 150, GetColor(255,255,255), "gemeD:%d",getDifficulty());

	return 3;
}
