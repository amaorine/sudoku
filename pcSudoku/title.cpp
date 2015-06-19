#include "../include/DxLib.h";
#include "key.h";
#include "gameMain.h";

//�^�C�g�����
//���j���[�������āA0�F�Q�[���X�^�[�g	1:�L�^������	2:�I��
//0�̏ꍇ�͂���title�t�@�C�����œ�Փx�ݒ�܂ł���ā�game�t�@�C���̕��ɒ���	1:�L�^�\���t�@�C���֔�ԁ@2:�Q�[�����I��

// ���j���[���ڂ̕\���ɕK�v�ȍ\���̂�p�ӂ���
typedef struct{
        int x, y;       // ���W�i�[�p�ϐ�
        char name[128]; // ���ږ��i�[�p�ϐ�
}titleMenu_t ;

//���j���[���ڂ�2�����z��
titleMenu_t menuElement[3][4]={
	{
		//[0][0-3]�ŏ��̃��j���[���
		{  80, 250, "�Q�[���X�^�[�g" },
        { 100, 300, "���R�[�h" },
        { 100, 350, "�w���v" },
        { 100, 400, "�Q�[���I��" }
	},
	{
		//[1][0-2]��Փx�I�����
		{  80, 250, "Easy" }, 
        { 100, 300, "Normal" },
        { 100, 350, "Hard" }
	},
	{
		//[2][0-1]��Փx�m�F���
		{  80, 250, "yes" }, 
        { 100, 300, "no" }
	}
		};

//�ϐ�
//���ݑI������Ă镔��
int selectNum=0;
int selectPage=0;

//�ϐ�


//���j���[�n�֐�
	//���j���[�v�Z
	void menuCalc(titleMenu_t* tM,int n){
			if(CheckStateKey(KEY_INPUT_DOWN)==1){
				selectNum = (selectNum+1) %n;
			}
			//�\�����L�[�����ꂽ�ꍇ
			else if(CheckStateKey(KEY_INPUT_UP)==1){
				selectNum = (selectNum+n-1) %n;
			}
					for(int i=0; i<n;i++ ){              // ���j���[���ڐ��ł���5���[�v����
						if(i==selectNum){          // ���������Ă���̂��A�I��ԍ��Ɠ����v�f�Ȃ�
							tM[i].x = 80; // ���W��80�ɂ���
						} else {                       // ���������Ă���̂��A�I��ԍ��ȊO�Ȃ�
							tM[i].x = 100;// ���W��100�ɂ���
						}
					}

	}

	//���j���[�\��
	void menuDraw(titleMenu_t* tM,int n){
			for( int i=0; i<n; i++ ){ // ���j���[���ڂ�`��
			DrawFormatString(tM[i].x,tM[i].y, GetColor(255,255,255),tM[i].name );
		}
	}

//���j���[�n�֐������܂ŃE

//�^�C�g�����
int titleMain(){
	if(CheckStateKey(KEY_INPUT_Z)==1){
		switch(selectPage){
			//title����Փx�I�����Q�[���X�^�[�g�܂ł̏����̓^�C�g����ʂł��̂ł����ŕ�����B
		case 0:	//�Q�[���N�����̉�ʂ̏ꍇ
				switch(selectNum){
				case 0:
					//�Q�[����Փx�I����ʂɂȂ�
					selectPage=1;
					break;
				case 1:
					//�X�R�A��ʂɈړ�
					return 1;
					break;
				case 2:
					//�w���v��ʂ�
					return 2;
					break;
				default:
					//�I��
					DxLib_End();//�c�w���C�u�����I������
					break;
				}
				break;
		case 1:	//��Փx�I����ʂ̏ꍇ
			//�J�[�\���̈ʒu�œ�Փx���聨�g���}�ێ�
			setDifficulty(selectNum);
			selectPage=2;	//�͂�/��������
			break;
		case 2:	//�͂�/�������̏�ʂ̏ꍇ
			if(selectNum==0){
				//�n�C�̏ꍇ�͓�Փx�n���ăQ�[����ʂ�

				return 3;
			}
			else{
				//�m�[�Ȃ�߂�
				//�����Ηj
				setDifficulty(-1);
				selectPage=1;
			}
			break;
		default:
			//�I��
			DxLib_End();//�c�w���C�u�����I������
			break;

		}
		selectNum=0;
	}
	else if(CheckStateKey(KEY_INPUT_X)==1){
		//X�{�^���Ŗ߂�Ƃ��̑���B���̃t�@�C�����ł̐؂�ւ�����Ȃ̂ŁA����l��selectPage�̂�
		switch(selectPage){
		case 0:	//�^�C�g���̍ŏ�
			selectNum=3;	//��ԉ��̏I������܂ŃJ�[�\�������Ă�
			break;
		case 1:	//��Փx�I����ʂȂ̂Ń^�C�g����ʂɖ߂�
			selectPage=0;
			break;
		case 2:	//yes/no��ʂȂ̂œ�Փx�I����ʂɖ߂�
			selectPage=1;
			break;
		default:
			//�I��
			DxLib_End();//�c�w���C�u�����I������
			break;
		}
	}

	//�v�Z�t�F�[�Y
	//menuElement[selectPage]�̗v�f��=selectPage=0,1,2�̎�4,3,2�Ȃ̂�4-selectPage�ŏo����
		menuCalc(menuElement[selectPage],4-selectPage);


	// �`��t�F�[�Y

	//�^�C�g���\��
	DrawFormatString( 240, 100, GetColor(255,255,255), "Sudoku for PC" );
	DrawFormatString( 240, 150, GetColor(255,255,255), "Snm:%d",selectNum );
	DrawFormatString( 240, 200, GetColor(255,255,255), "SPa:%d",selectPage );
	//���j���[�\������
	menuDraw(menuElement[selectPage],4-selectPage);
	return 0;
}

