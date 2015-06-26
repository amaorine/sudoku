#include "../include/DxLib.h";
#include "key.h";

//C++�̃��C�u����
#include <iostream>
#include <algorithm>
#include <time.h>
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





void sortHight(){
int n=0;	//��芷�����鎞�̕���
int k,l,m;	//���ёւ��Ɏg��
int count[9];	//����ĂȂ����`�F�b�N



//�c�ŏォ�猩�čs���āA�z��bord[0][i][0]�Ƃ��Ԃ����z��bord[0][j][�C��]���A�z��bord[0][j][9-1]�̗l�͎w�肳�ꂽ��ׂ̗ƌ����B

//1-9���c����ł̐����̌��𐔂���

	for(int h=0;h<9;h++){
		for(int i=0;i<9;i++){
			count[i]=0;
		}

		for(int i=0;i<9;i++){
			count[bord[0][i][h]-1]++;
		}

		//checkNum[i]
		for(int i=0;i<9;i++){
			//count[i]��
			//0������ɂ���count[i]==0�̐���count[i]==2�̐�����
			//2������ɂ���count[i]==0�̐���count[i]==2�̐�����
			//1���������Ȃ�
			while(count[i]>1){
				//����1�ȊO�̏ꍇ�͔���Ă邩����Ȃ����Ȃ̂Ō�������
				for(int j=0;j<9;j++){
					//j bord[0][j][0]
					if(bord[0][j][h]-1==i){
						//i��bord[0][j][0]�̒��g��v
						for(int k=8;k>h;k--){
							//k bord[0][j][k]
							if(count[bord[0][j][k]-1]==0){
								//count[bord[0][j][k]]�̒l��1��count[i]�ȊO�̏ꍇ
								//=count[i]=0�Ȃ��2,count[i]==2�Ȃ��0�̏ꍇ
								//����
								int n=bord[0][j][k];
								bord[0][j][k]=bord[0][j][h];
								bord[0][j][h]=n;

								for(int m=0;m<9;m++){
									count[m]=0;
								}

								for(int m=0;m<9;m++){
									count[bord[0][m][h]-1]++;
								}
							}
						}
					}
				}
			}
		}

	}


}


//�������g
void setNumberField(int dif){
	//j=y,k=x

//	srand((unsigned)time(NULL));


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
		}
	}
	
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
