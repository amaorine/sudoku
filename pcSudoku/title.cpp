#include "../include/DxLib.h";
#include "key.h";

//�^�C�g�����
//���j���[�������āA0�F�Q�[���X�^�[�g	1:�L�^������	2:�I��
//0�̏ꍇ�͂���title�t�@�C�����œ�Փx�ݒ�܂ł���ā�game�t�@�C���̕��ɒ���	1:�L�^�\���t�@�C���֔�ԁ@2:�Q�[�����I��

// ���j���[���ڂ̕\���ɕK�v�ȍ\���̂�p�ӂ���
typedef struct{
        int x, y;       // ���W�i�[�p�ϐ�
        char name[128]; // ���ږ��i�[�p�ϐ�
}titleMenu_t ;

// ���j���[���ڗv�f��5���
        titleMenu_t MenuElement[4]={
                {  80, 250, "�Q�[���X�^�[�g" }, // �^�O�̒��g�̏��ԂŊi�[�����Bx��80���Ay��100���Aname��"�Q�[���X�^�[�g"��
                { 100, 300, "���R�[�h" },
                { 100, 350, "�w���v" },
                { 100, 400, "�Q�[���I��" },
        };
		titleMenu_t menuDifficulty[3]={
                {  80, 250, "Easy" }, // �^�O�̒��g�̏��ԂŊi�[�����Bx��80���Ay��100���Aname��"�Q�[���X�^�[�g"��
                { 100, 300, "Normal" },
                { 100, 350, "Hard" }
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
			if(CheckStateKey(KEY_INPUT_DOWN)== 1 ||CheckStateKey(KEY_INPUT_UP)== 1 ){ // ���L�[���A��L�[�������ꂽ�u��
					for(int i=0; i<n;i++ ){              // ���j���[���ڐ��ł���5���[�v����
						if(i==selectNum){          // ���������Ă���̂��A�I��ԍ��Ɠ����v�f�Ȃ�
							tM[i].x = 80; // ���W��80�ɂ���
						} else {                       // ���������Ă���̂��A�I��ԍ��ȊO�Ȃ�
							tM[i].x = 100;// ���W��100�ɂ���
						}
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
			break;
		case 2:	//�͂�/�������̏�ʂ̏ꍇ
			break;
		default:
			//�I��
			DxLib_End();//�c�w���C�u�����I������
			break;

		}
	}

	//�v�Z�t�F�[�Y
	switch(selectPage){
	case 0:	//�ŏ��̏�ʁ��Q�[���X�^�[�g��I������Ƃ��܂ŁB
		menuCalc(MenuElement,4);
		break;
	case 1:	//��Փx�I����ʂ̎��B
		menuCalc(menuDifficulty,3);
		break;
	case 2:	//�͂�/�������̏�ʂ̎��A�m�F�����ꍇ�͑I��������Փx���Q�[���{�̂ɓn���B
		break;
	default:
		break;
	}


	// �`��t�F�[�Y

	//�^�C�g���\��
	DrawFormatString( 240, 100, GetColor(255,255,255), "Sudoku for PC" );
	//���j���[�\������
	switch(selectPage){
	case 0:	//�Q�[���X�^�[�g�܂ł�
		menuDraw(MenuElement,4);
		break;
	case 1:	//��Փx�I���̎�
		 menuDraw(menuDifficulty,3);
		break;
	case 2:
		break;
	}
	return 0;
}

