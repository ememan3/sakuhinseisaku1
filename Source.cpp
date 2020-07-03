/*--+----1----+----2----+----3----+----4----+----5--//-+----6----+----7----+----8----+----9----+---*/
/* OC_01_Kansei.cpp   																			   */
/* OC�p�v���O����01(������)																		   */

#define _CRT_SECURE_NO_WARNINGS

//########## �w�b�_�[�t�@�C���ǂݍ��� ##########5
#include "DxLib.h"

//########## �}�N����` ##########
#define DEBUG_MODE	FALSE	//�f�o�b�O���[�h

#define GAME_WIDTH	800		//��ʂ̉��̑傫��
#define GAME_HEIGHT	600		//��ʂ̏c�̑傫��
#define GAME_COLOR	32		//��ʂ̃J���[�r�b�g

#define GAME_WINDOW_NAME	"Kor tall Kanten"		//�E�B���h�E�̃^�C�g��
#define GAME_WINDOW_MODECHANGE	TRUE			//TRUE�F�E�B���h�E���[�h / FALSE�F�t���X�N���[��

#define SET_WINDOW_ST_MODE_DEFAULT			0	//�f�t�H���g
#define SET_WINDOW_ST_MODE_TITLE_NONE		1	//�^�C�g���o�[�Ȃ�
#define SET_WINDOW_ST_MODE_TITLE_FLAME_NONE	2	//�^�C�g���o�[�ƃt���[���Ȃ�
#define SET_WINDOW_ST_MODE_FLAME_NONE		3	//�t���[���Ȃ�

#define GAME_FPS_SPEED					   60

//�}�b�v�֘A
#define GAME_MAP_YOKO_SIZE		32		//�}�b�v�P�̑傫��(��)
#define GAME_MAP_TATE_SIZE		32		//�}�b�v�P�̑傫��(�c)

#define GAME_MAP_BUN_YOKO_CNT	32		//�}�b�v�̕�����(��)
#define GAME_MAP_BUN_TATE_CNT	41		//�}�b�v�̕�����(�c)

#define GAME_MAP_YOKO			40	//�}�b�v�̐�(��)
#define GAME_MAP_TATE			40	//�}�b�v�̐�(�c)
#define GAME_MAP_OK_KIND		2	//�ʍs�ł���}�b�v�̎��
#define GAME_MAP_NG_KIND		2	//�ʍs�ł��Ȃ��}�b�v�̎��
#define GAME_MAP_CLEAR			1	//�N���A�ł���}�b�v�̎��
#define GAME_MAP_BT_KIND		5	//�퓬����}�b�v�̎��
/*###################################�蒼����������#######################################################################3*/
#define GAME_MAP_1_PATH			"�Q�[���摜\\map\\map_image\\img01.png"	//�}�b�v�摜

#define GAME_MAP_CSV_1_SITA		"�Q�[���摜\\map\\map1_�^�C���E���C���[1.csv"	//�}�b�v��CSV
#define GAME_MAP_CSV_1_NAKA		"MAPIMAGE\\mapchip1_map_naka.csv"	//�}�b�v��CSV
#define GAME_MAP_CSV_1_UE		"�Q�[���摜\\map\\map1_�^�C���E���C���[2.csv"		//�}�b�v��CSV
/*###############################�����܂�########################################################################################3*/
#define GAME_MAP_NAME_1_UE		"MAPDATA_1_UE"		//�}�b�v����
#define GAME_MAP_NAME_1_NAKA	"MAPDATA_1_NAKA"	//�}�b�v����
#define GAME_MAP_NAME_1_SITA	"MAPDATA_1_SITA"	//�}�b�v����


#define MAP_IMG_NAME			"�Q�[���摜\\map\\map_image\\map.png"//�}�b�v�̉摜
#define MAP_CSV_1_SIN			"�Q�[���摜\\map\\map_image\\atari_atari.csv"//�}�b�v��CSV
#define MAP_NAME_1_SIN			"MAPDATA_1_SIN"

//#define GAME_CHARA				"CHARAIMAGE\\chara2.png"	//�L�����̉摜

//�L�����֘A
#define GAME_CHARA				"�Q�[���摜\\�L����\\�A�L����.png"	//�L�����̉摜
#define GAME_CHARA_BUN_YOKO_CNT	6		//�L�����̕�����(��)
#define GAME_CHARA_BUN_TATE_CNT	4		//�L�����̕�����(�c)
#define GAME_CHARA_YOKO_SIZE	20		//�L�����̑傫��(��)
#define GAME_CHARA_TATE_SIZE	28		//�L�����̑傫��(�c)
#define GAME_CHARA_MOTION_NUM	24		//�L�����̉摜��
#define GAME_CHARA_KIND_YOKO	1		//�L�����̉��̎��
#define GAME_CHARA_KIND_TATE	1		//�L�����̏c�̎��

#define GAME_CHARA_STARTX		4		//�L�����̍ŏ��̈ʒu
#define GAME_CHARA_STARTY		1		//�L�����̍ŏ��̈ʒu
#define GAME_CHARA_SPEED		2		//�L�����̃X�s�[�h

#define GAME_PLAYER_LV_FIRST	1		//�v���C���[�̍ŏ���LV
#define GAME_PLAYER_HP_FIRST	10		//�v���C���[�̍ŏ���HP
#define GAME_PLAYER_ATK_FIRST	4		//�v���C���[�̍ŏ���ATK
#define GAME_PLAYER_DEF_FIRST	6		//�v���C���[�̍ŏ���DEF

#define GAME_PLAYER_HP_LVUP		5		//�v���C���[��LVUP��HP
#define GAME_PLAYER_ATK_LVUP	4		//�v���C���[��LVUP��ATK
#define GAME_PLAYER_DEF_LVUP	3		//�v���C���[��LVUP��DEF

#define GAME_PLAYER_NAME		"�E��"	//�v���C���[�̖��O
#define GAME_PLAYER_ITEM_MAX	10		//�v���C���[�̃A�C�e���ێ�MAX

//�G�֘A
#define GAME_ENE_CSV_1				"ENEIMAGE\\enedata.csv"		//�G��CSV

#define GAME_ENE_GRASS_1_IMAGE		"ENEIMAGE\\grass_001.png"	//�G�̉摜
#define GAME_ENE_GRASS_2_IMAGE		"ENEIMAGE\\grass_002.png"	//�G�̉摜
#define GAME_ENE_GRASS_3_IMAGE		"ENEIMAGE\\grass_003.png"	//�G�̉摜
#define GAME_ENE_GRASS_4_IMAGE		"ENEIMAGE\\grass_004.png"	//�G�̉摜

#define GAME_ENE_KUSA_1_IMAGE		"ENEIMAGE\\kusa_001.png"	//�G�̉摜
#define GAME_ENE_KUSA_2_IMAGE		"ENEIMAGE\\kusa_002.png"	//�G�̉摜
#define GAME_ENE_KUSA_3_IMAGE		"ENEIMAGE\\kusa_003.png"	//�G�̉摜
#define GAME_ENE_KUSA_4_IMAGE		"ENEIMAGE\\kusa_004.png"	//�G�̉摜
#define GAME_ENE_KUSA_5_IMAGE		"ENEIMAGE\\kusa_005.png"	//�G�̉摜

#define GAME_ENE_RIVER_1_IMAGE		"ENEIMAGE\\river_001.png"	//�G�̉摜
#define GAME_ENE_RIVER_2_IMAGE		"ENEIMAGE\\river_002.png"	//�G�̉摜
#define GAME_ENE_RIVER_3_IMAGE		"ENEIMAGE\\river_003.png"	//�G�̉摜
#define GAME_ENE_RIVER_4_IMAGE		"ENEIMAGE\\river_004.png"	//�G�̉摜

#define GAME_ENE_MAOU_1_IMAGE		"ENEIMAGE\\maou_001.png"	//�G�̉摜
#define GAME_ENE_MAOU_2_IMAGE		"ENEIMAGE\\maou_002.png"	//�G�̉摜
#define GAME_ENE_MAOU_3_IMAGE		"ENEIMAGE\\maou_003.png"	//�G�̉摜
#define GAME_ENE_MAOU_4_IMAGE		"ENEIMAGE\\maou_004.png"	//�G�̉摜
#define GAME_ENE_MAOU_5_IMAGE		"ENEIMAGE\\maou_005.png"	//�G�̉摜
#define GAME_ENE_MAOU_6_IMAGE		"ENEIMAGE\\maou_006.png"	//�G�̉摜

#define GAME_ENE_BOSS_IMAGE			"ENEIMAGE\\boss2.png"		//�G�̉摜

#define GAME_ENE_BATTLE_NUM_MAX		3	//�G����x�ɐ퓬����ő吔
#define GAME_ENE_KIND_MAX			20	//�G�̎�ނ̍ő吔

#define GAME_TIME_SET				30	//����

//�퓬�֘A
#define GAME_BT_GRASS_IMAGE			"BATTLEIMAGE\\grass.png"	//�퓬��ʂ̔w�i
#define GAME_BT_RIVER_IMAGE			"BATTLEIMAGE\\river.png"	//�퓬��ʂ̔w�i
#define GAME_BT_MAOU_IMAGE			"BATTLEIMAGE\\maou.png"		//�퓬��ʂ̔w�i
#define GAME_BT_BOSS_IMAGE			"BATTLEIMAGE\\boss.png"		//�퓬��ʂ̔w�i

//�G�̃X�e�[�^�X�\���ꏊ
#define GAME_BATTLE_TEKI_ACT_WIDTH	200
#define GAME_BATTLE_TEKI_ACT_HEIGHT	60

//�����̃X�e�[�^�X�\���ꏊ
#define GAME_BATTLE_MY_ST_LEFT		50
#define GAME_BATTLE_MY_ST_TOP		475
#define GAME_BATTLE_MY_ST_RIGHT		250
#define GAME_BATTLE_MY_ST_BOTTOM	575

#define GAME_BATTLE_MY_ST_WIDTH		200

//�����̍s���\���ꏊ
#define GAME_BATTLE_MY_ACT_LEFT		275
#define GAME_BATTLE_MY_ACT_TOP		475
#define GAME_BATTLE_MY_ACT_RIGHT	750
#define GAME_BATTLE_MY_ACT_BOTTOM	575

//�����̃X�e�[�^�X�\���ꏊ[�U��]
#define GAME_BATTLE_MY_ACT_ATK_LEFT		295
#define GAME_BATTLE_MY_ACT_ATK_TOP		495
#define GAME_BATTLE_MY_ACT_ATK_RIGHT	425
#define GAME_BATTLE_MY_ACT_ATK_BOTTOM	555

//�����̃X�e�[�^�X�\���ꏊ[�A�C�e��]
#define GAME_BATTLE_MY_ACT_ITEM_LEFT	445
#define GAME_BATTLE_MY_ACT_ITEM_TOP		495
#define GAME_BATTLE_MY_ACT_ITEM_RIGHT	575
#define GAME_BATTLE_MY_ACT_ITEM_BOTTOM	555

//�����̃X�e�[�^�X�\���ꏊ[������]
#define GAME_BATTLE_MY_ACT_ESC_LEFT		595
#define GAME_BATTLE_MY_ACT_ESC_TOP		495
#define GAME_BATTLE_MY_ACT_ESC_RIGHT	725
#define GAME_BATTLE_MY_ACT_ESC_BOTTOM	555

#define GAME_TITLE_IMAGE				"�Q�[���摜\\�^�C�g��\\��i�^�C�g��.png"	//�^�C�g���̉摜
#define GAME_TITLE_BACKIMAGE			"�Q�[���摜\\�^�C�g��\\�^�C�g���w�i���� (2).jpg" //�^�C�g���w�i
#define GAME_CLEAR_IMAGE				"CLEARIMAGE\\clearimage.png"	//�Q�[���N���A�̉摜

#define GAME_MUSIC_LEVELUP				"MUSIC\\levelup.mp3"
#define GAME_MUSIC_BATTLE_SELECT		"MUSIC\\battle_select.mp3"
#define GAME_MUSIC_BATTLE_ENTER			"MUSIC\\battle_select_enter.mp3"
#define GAME_MUSIC_BATTLE_ATK			"MUSIC\\battle_atk.mp3"
#define GAME_MUSIC_BATTLE				"MUSIC\\battle.mp3"
#define GAME_MUSIC_BOSS					"MUSIC\\boss.mp3"
#define GAME_MUSIC_TITLE				"MUSIC\\wonderland.wav"
#define GAME_MUSIC_PLAY					"MUSIC\\�A�z�̎q.mp3"
#define GAME_MUSIC_BATTLE_ITEM			"MUSIC\\battle_item.mp3"
#define GAME_MUSIC_BATTLE_ESC			"MUSIC\\battle_esc.mp3"
#define GAME_MUSIC_END_SELECT			"MUSIC\\end_select.mp3"
#define GAME_MUSIC_END					"MUSIC\\�����T���E���h-1chorus-.mp3"

//########## �񋓌^ ##########
enum GAME_SCENE {
	GAME_SCENE_TITLE,		//�^�C�g�����
	GAME_SCENE_DESCRIPTION,
	GAME_SCENE_CHOICE,
	GAME_SCENE_PLAY,		//�v���C���
	GAME_SCENE_BATTLE,		//�퓬���
	GAME_SCENE_MOVE_SCENE,	//�V�[���J�ډ��
	GAME_SCENE_END			//�G���h���
};
//################################��������###############################################
enum CHARA_IMAGE {
	CHARA_KIND_1 = 0,
	/*CHARA_KIND_2 = 3,
	CHARA_KIND_3 = 6,
	CHARA_KIND_4 = 9,
	CHARA_KIND_5 = 48,
	CHARA_KIND_6 = 51,
	CHARA_KIND_7 = 54,
	CHARA_KIND_8 = 57,
	CHARA_KIND_END = 95*/
};	//�L�����̎�ނ̗񋓌^
//##########################�L���������I###########################################3
enum GAME_ENETYPE {
	GAME_ENETYPE_NONE = 0,		//�Ȃ�
	GAME_ENETYPE_GRASS = 1,		//��
	GAME_ENETYPE_KUSA = 26,		//���Q
	GAME_ENETYPE_RIVER = 936,	//��
	GAME_ENETYPE_MAOU = 314,	//������
	GAME_ENETYPE_BOSS = 148		//�{�X��
};

enum GAME_MAE_EFFECT {
	GAME_MAE_EFFECT_FADEIN,		//�t�F�[�h�C��
	GAME_MAE_EFFECT_FADEOUT,	//�t�F�[�h�A�E�g
};

enum GAME_ACT_KIND {
	GAME_ACT_KIND_NONE,		//�Ȃ�
	GAME_ACT_KIND_ATK,		//�U��
	GAME_ACT_KIND_ITEM,		//�A�C�e��
	GAME_ACT_KIND_ESC,		//������
	GAME_ACT_KIND_LVUP,		//���x���A�b�v
	GAME_ACT_KIND_MAX,		//�s����ޏI��
};

enum GAME_ITEM_KIND {
	GAME_ITEM_KIND_KAIHUKU_10,		//10��
	GAME_ITEM_KIND_KAIHUKU_20,		//20��
	GAME_ITEM_KIND_KAIHUKU_30,		//30��
	GAME_ITEM_KIND_ICHIGEKI,		//�ꌂ�K�E
	GAME_ITEM_KIND_MAX,				//�A�C�e���I��
};

enum GAME_TURN {
	GAME_TURN_NONE,		//�Ȃ�
	GAME_TURN_MY,		//�����̃^�[��
	GAME_TURN_ENEMY,	//�G�̃^�[��
};

enum GAME_END_KIND {
	GAME_END_KIND_NONE,		//�ŏ��̏��
	GAME_END_KIND_OVER,		//�Q�[���I�[�o
	GAME_END_KIND_CLEAR,	//�Q�[���N���A
};

struct STRUCT_MUSIC
{
	int Handle;					//���̃n���h��
	char FilePath[128];			//�t�@�C���̃p�X
	int Playtype;				//���̍Đ����@
};	//���\����

//########## �\���� ##########
struct STRUCT_IMAGE
{
	char FilePath[128];												//�t�@�C���̃p�X
	int Handle[GAME_MAP_BUN_YOKO_CNT * GAME_MAP_BUN_TATE_CNT];		//�摜�̃n���h��
	int X[GAME_MAP_BUN_YOKO_CNT * GAME_MAP_BUN_TATE_CNT];			//���̈ʒu
	int Y[GAME_MAP_BUN_YOKO_CNT * GAME_MAP_BUN_TATE_CNT];			//�c�̈ʒu
	int Width[GAME_MAP_BUN_YOKO_CNT * GAME_MAP_BUN_TATE_CNT];		//���̃T�C�Y
	int Height[GAME_MAP_BUN_YOKO_CNT * GAME_MAP_BUN_TATE_CNT];		//�c�̃T�C�Y
	int C_Width[GAME_MAP_BUN_YOKO_CNT * GAME_MAP_BUN_TATE_CNT];		//���̒��S�ʒu
	int C_Height[GAME_MAP_BUN_YOKO_CNT * GAME_MAP_BUN_TATE_CNT];	//�c�̒��S�ʒu

};	//STRUCT_IMAGE�\����

struct STRUCT_MAP_IMAGE
{
	char FilePath[128];												//�t�@�C���̃p�X
	int Handle;		//�摜�̃n���h��
	int X;			//���̈ʒu
	int Y;			//�c�̈ʒu
	int Width;		//���̃T�C�Y
	int Height;		//�c�̃T�C�Y
	int C_Width;		//���̒��S�ʒu
	int C_Height;	//�c�̒��S�ʒu

};

struct STRUCT_MAPDATA
{
	char name[64];											//�}�b�v�̖���	
	int data[GAME_MAP_TATE][GAME_MAP_YOKO];					//�}�b�v��CSV�f�[�^
	int mapdata_Init[GAME_MAP_TATE][GAME_MAP_YOKO];			//�}�b�v��CSV�f�[�^�i�ŏ��j

	int Handle[GAME_MAP_BUN_YOKO_CNT * GAME_MAP_BUN_TATE_CNT];	//�}�b�v�X�̃n���h��
	int X[GAME_MAP_BUN_YOKO_CNT * GAME_MAP_BUN_TATE_CNT];			//���̈ʒu
	int Y[GAME_MAP_BUN_YOKO_CNT * GAME_MAP_BUN_TATE_CNT];			//�c�̈ʒu
	int Width[GAME_MAP_BUN_YOKO_CNT * GAME_MAP_BUN_TATE_CNT];		//���̃T�C�Y
	int Height[GAME_MAP_BUN_YOKO_CNT * GAME_MAP_BUN_TATE_CNT];		//�c�̃T�C�Y
	int C_Width[GAME_MAP_BUN_YOKO_CNT * GAME_MAP_BUN_TATE_CNT];		//���̒��S�ʒu
	int C_Height[GAME_MAP_BUN_YOKO_CNT * GAME_MAP_BUN_TATE_CNT];	//�c�̒��S�ʒu

	int mapNGKind[GAME_MAP_NG_KIND];						//�}�b�v����̎�ށi�ʍs�ł��Ȃ��j
	int mapOKKind[GAME_MAP_OK_KIND];						//�}�b�v����̎�ށi�ʍs�ł���j
	int mapCLKind[GAME_MAP_CLEAR];							//�}�b�v����̎�� (�N���A�j
	int mapBTKind[GAME_MAP_BT_KIND];						//�}�b�v����̎�ށi�퓬�j
	int mapNGKind_cnt = FALSE;

	RECT rect_NG[GAME_MAP_TATE][GAME_MAP_YOKO];				//�����蔻��̗̈�i�ʍs�ł��Ȃ��j
	RECT rect_NG_First[GAME_MAP_TATE][GAME_MAP_YOKO];		//�����蔻��̗̈�i�ʍs�ł��Ȃ��j�i�ŏ��j

	RECT rect_OK[GAME_MAP_TATE][GAME_MAP_YOKO];				//�����蔻��̗̈�i�ʍs�ł���j
	RECT rect_OK_First[GAME_MAP_TATE][GAME_MAP_YOKO];		//�����蔻��̗̈�i�ʍs�ł���j�i�ŏ��j

	RECT rect_CL[GAME_MAP_TATE][GAME_MAP_YOKO];				//�����蔻��̗̈�i�ʍs�ł��Ȃ��j
	RECT rect_CL_First[GAME_MAP_TATE][GAME_MAP_YOKO];		//�����蔻��̗̈�i�ʍs�ł��Ȃ��j�i�ŏ��j

	RECT rect_BT[GAME_MAP_TATE][GAME_MAP_YOKO];				//�����蔻��̗̈�i�퓬�j
	RECT rect_BT_First[GAME_MAP_TATE][GAME_MAP_YOKO];		//�����蔻��̗̈�i�퓬�j�i�ŏ��j

};	//MAPDATA�\����

struct STRUCT_CHARAIMAGE
{
	char FilePath[128];													//�t�@�C���̃p�X
	int HandleChara[GAME_CHARA_BUN_YOKO_CNT * GAME_CHARA_BUN_TATE_CNT];		//�摜�̃n���h��
	int X[GAME_CHARA_BUN_YOKO_CNT * GAME_CHARA_BUN_TATE_CNT];			//���̈ʒu
	int Y[GAME_CHARA_BUN_YOKO_CNT * GAME_CHARA_BUN_TATE_CNT];			//�c�̈ʒu
	int Width[GAME_CHARA_BUN_YOKO_CNT * GAME_CHARA_BUN_TATE_CNT];		//���̃T�C�Y
	int Height[GAME_CHARA_BUN_YOKO_CNT * GAME_CHARA_BUN_TATE_CNT];		//�c�̃T�C�Y
	int C_Width[GAME_CHARA_BUN_YOKO_CNT * GAME_CHARA_BUN_TATE_CNT];		//���̒��S�ʒu
	int C_Height[GAME_CHARA_BUN_YOKO_CNT * GAME_CHARA_BUN_TATE_CNT];	//�c�̒��S�ʒu
};	//STRUCT_CHARAIMAGE�\����

struct STRUCT_CHARADATA
{
	STRUCT_CHARAIMAGE charaimage;		//�摜
	int Handle[GAME_CHARA_MOTION_NUM];	//�摜�̃n���h��
	int X;								//���̈ʒu
	int Y;								//�c�̈ʒu
	int Width;							//���̃T�C�Y
	int Height;							//�c�̃T�C�Y
	int C_Width;						//���̒��S�ʒu
	int C_Height;						//�c�̒��S�ʒu
	int NowHandleNum;					//���݂̉摜�̃n���h��
	int NowHandleCnt;					//���݂̃n���h���J�E���g
	int NowHandleCntMAX;				//���݂̃n���h���J�E���gMAX

	int Speed;							//���x
	int MoveDistX;						//�ړ�����X
	int MoveDistY;						//�ړ�����Y

	BOOL CanMoveUp;						//��ɍs���邩
	BOOL CanMoveDown;					//���ɍs���邩
	BOOL CanMoveLeft;					//���ɍs���邩
	BOOL CanMoveRight;					//�E�ɍs���邩

	BOOL ScrollOK_X;					//�X�N���[���ł��邩�ǂ���
	BOOL ScrollOK_Y;					//�X�N���[���ł��邩�ǂ���

	int atariX;							//�����蔻���X�ʒu
	int atariY;							//�����蔻���Y�ʒu
	int atariWidth;						//�����蔻��̕�
	int atariHeight;					//�����蔻��̍���
	RECT atariRect;						//�����蔻��̋�`�̈�

	int eneType;						//�G�̎��
	int eneBattleCnt;					//�G�̐키��

	char name[255];						//���O
	int HP;
	int ATK;
	int DEF;

	int LV;
	int HP_MAX;
	int ATK_MAX;
	int DEF_MAX;
	int item[(int)GAME_ITEM_KIND_MAX][GAME_PLAYER_ITEM_MAX];	//�����Ă���A�C�e����

	RECT rect_st;	//���̗̈�

	RECT rect_act_atk;	//���̗̈�[�U��]
	RECT rect_act_item;	//���̗̈�[�A�C�e��]
	RECT rect_act_esc;	//���̗̈�[������]

	RECT rect_act;		//�s���̗̈�

	int act_kind;				//�s���̎��;
	BOOL IsActKeyDown_left;		//�s�����������Ƃ�(��)
	BOOL IsActKeyDown_right;	//�s�����������Ƃ�(�E)

	int battle_turn;			//�^�[�����	
	BOOL IsEsc;					//�������邩
	BOOL IsActMsgStart;			//�s�����b�Z�[�W�J�n
	BOOL IsActMsgEnd;			//�s�����b�Z�[�W�I��
	int NowActMsgCnt;			//�s�����b�Z�[�W�J�E���g
	int NowActMsgCntMAX;		//�s�����b�Z�[�W�J�E���gMAX

	int damageCalc;				//�_���[�W�v�Z

	BOOL IsActLvupStart;		//LVUP���b�Z�[�W�J�n
	BOOL IsActLvupEnd;			//LVUP���b�Z�[�W�I��
	int NowActLvupCnt;			//LVUP���b�Z�[�W�J�E���g
	int NowActLvupntMAX;		//LVUP���b�Z�[�W�J�E���gMAX

	BOOL IsAlive;		//�����Ă��邩

	int gameEndKind;	//�Q�[���I���̏��

	int EndLV;			//�I�����_�ł�LV
	int EndHP;			//�I�����_�ł�HP
	int EndATK;			//�I�����_�ł�ATK
	int EndDEF;			//�I�����_�ł�DEF

};	//STRUCT_CHARADATA�\����

struct STRUCT_ENEDATA
{
	int Handle;							//�摜�̃n���h��
	int X;								//���̈ʒu
	int Y;								//�c�̈ʒu
	int Width;							//���̃T�C�Y
	int Height;							//�c�̃T�C�Y
	int C_Width;						//���̒��S�ʒu
	int C_Height;						//�c�̒��S�ʒu

	int No;
	int LV;
	char name[255];
	int enetype;						//�G�̃^�C�v
	int HP;
	int ATK;
	int DEF;

	int HP_MAX;
	int ATK_MAX;
	int DEF_MAX;
	int item[(int)GAME_ITEM_KIND_MAX][GAME_PLAYER_ITEM_MAX];	//�����Ă���A�C�e����

	RECT rect_st;	//���̗̈�
	RECT rect_act;	//�s���̗̈�

	BOOL IsAlive;	//�����Ă��邩

	int damageCalc;	//�_���[�W�v�Z

};	//STRUCT_ENEDATA�\����

struct STRUCT_SCENE_MOVE
{
	int kind;
	int DrawCnt;
	int DrawCntMax;
	double ToukaPercent;
	int DeleteX;
	int DeleteY;
}; //STRUCT_SCENE_MOVE�\����


//########## ���O�̍Ē�` ##########
typedef STRUCT_MUSIC MUSIC;
typedef STRUCT_IMAGE IMAGE;
typedef STRUCT_MAP_IMAGE MAP_IMG;
typedef STRUCT_MAPDATA MAPDATA;
typedef STRUCT_CHARAIMAGE CHARAIMAGE;
typedef STRUCT_CHARADATA CHARADATA;
typedef STRUCT_ENEDATA ENEDATA;
typedef STRUCT_SCENE_MOVE SCENE_MOVE;

//########## �O���[�o���ϐ� ##########

//�E�B���h�E�֌W
BOOL IsWM_CREATE = FALSE;				//WM_CREATE������ɓ��삵�������f����

//FPS�֘A
int StartTimeFps;						//����J�n����
int CountFps;							//�J�E���^
float CalcFps;							//�v�Z����
int SampleNumFps = GAME_FPS_SPEED;		//���ς����T���v����

//�L�[�{�[�h�֘A
char AllKeyState[256];			//���ׂẴL�[�̏�Ԃ�����

//�V�[���֘A
int GameSceneNow = (int)GAME_SCENE_TITLE;	//�ŏ��̃Q�[����ʂ��^�C�g���ɐݒ�

//�}�b�v�֘A
IMAGE Image_map;
MAPDATA mapData_sita;	//���̃}�b�v
MAPDATA mapData_naka;	//���̃}�b�v
MAPDATA mapData_ue;		//��̃}�b�v
MAPDATA mapData_sin;

MAP_IMG Map_Image;		//�}�b�v�摜

IMAGE image_grass;		//�퓬���
IMAGE image_river;		//�퓬���
IMAGE image_maou;		//�퓬���
IMAGE image_boss;		//�퓬���

IMAGE image_title;		//�^�C�g�����
IMAGE image_backtitle;	//�^�C�g���w�i
IMAGE image_clear;		//�N���A���

//�X�N���[���֌W
int ScrollCntYoko = 0;	//�X�N���[���J�E���^(��)
int ScrollCntTate = 0;	//�X�N���[���J�E���^(�c)

//�L�����n
CHARAIMAGE CharaImage;	//�L�����̉摜
CHARADATA	Myplayer;	//�L�����̃f�[�^

//�G�n
ENEDATA enedata[GAME_ENE_KIND_MAX];					//�G�̃f�[�^
ENEDATA eneBattleNum_INIT;							//�키�G(�������p)
ENEDATA eneBattle[GAME_ENE_BATTLE_NUM_MAX];		//�키�G�̐�

//�v���C���[�̃C���[�W�摜�̔ԍ���ݒ肷��
int PlayerImageNum[GAME_CHARA_MOTION_NUM];

//�퓬�O����
SCENE_MOVE sceneMove;

//�Q�[���G���h�ł̑I����
RECT rectEndCon{ 100,100,300,500 };
RECT rectEndEnd{ 500,100,700,500 };

//�Q�[���G���h�ł̑I���J�E���g
int EndConCnt = 0;
int EndConCntMAX = 120;

int EndEndCnt = 0;
int EndEndCntMAX = 120;
/*�ǉ���������*/
int SelectTitleNum = 0;
int play_scene;
int SelectSteageNum = 0;
int SelectEndNum = 0;
/*�ǉ������܂�*/
int MY_RANGE_RAND(int, int);	//�͈͂��w�肵��rand���s��

int SceneBefore;	//�ȑO�̃V�[��
int SceneNext;		//���̃V�[��

int FontDefault;
int FontBig;
int FontFutsu;

//����ǂݍ���
MUSIC MUSIC_MY_BGM_BATTLE;
MUSIC MUSIC_MY_SE_BATTLE_ATK;
MUSIC MUSIC_MY_SE_BATTLE_SELECT;
MUSIC MUSIC_MY_SE_BATTLE_ENTER;
MUSIC MUSIC_MY_BGM_BOSS;
MUSIC MUSIC_MY_SE_LEVELUP;
MUSIC MUSIC_MY_BGM_PLAY;
MUSIC MUSIC_MY_BGM_TITLE;
MUSIC MUSIC_MY_BGM_END;
MUSIC MUSIC_MY_SE_BATTLE_ITEM;
MUSIC MUSIC_MY_SE_BATTLE_ESC;
MUSIC MUSIC_MY_SE_END_SELECT;

//########## �v���g�^�C�v�錾 ##########

VOID MY_FPS_UPDATE(VOID);			//FPS�l���v���A�X�V����֐�
VOID MY_FPS_DRAW(VOID);				//FPS�l��`�悷��֐�
VOID MY_FPS_WAIT(VOID);				//FPS�l���v�����A�҂֐�

VOID MY_ALL_KEYDOWN_UPDATE(VOID);	//�L�[�̓��͏�Ԃ��X�V����֐�

VOID MY_GAME_TITLE(VOID);			//�^�C�g����ʂ̊֐�
VOID MY_GAME_TITLE_DRAW(VOID);		//�^�C�g����ʕ`��̊֐�
VOID MY_GAME_BACK_DRAW(VOID);		//�w�i�`��̊֐�
VOID MY_GAME_PLAY(VOID);			//�v���C��ʂ̊֐�
VOID MY_GAME_PLAY_DRAW(VOID);		//�v���C��ʕ`��̊֐�
VOID MY_GAME_BATTLE(VOID);			//�퓬��ʂ̊֐�
VOID MY_GAME_BATTLE_DRAW(VOID);		//�퓬��ʕ`��̊֐�
BOOL MY_GAME_SCENE_MOVE(int);		//�V�[���ړ���ʂ̊֐�
VOID MY_GAME_END(VOID);				//�G���h��ʂ̊֐�
VOID MY_GAME_END_DRAW(VOID);		//�G���h��ʕ`��̊֐�

BOOL MY_PLAY_INIT(VOID);			//�v���C��ʏ������֐�

VOID MY_BATTLE_ENEMY_INIT(int, int);		//�퓬�O�ɓG������������֐�

VOID MY_GAME_DESCRIPTION(VOID);

VOID MY_GAME_CHOICE(VOID);

BOOL MY_MAP_READ_CSV_UE_KIND_SET(MAPDATA *);	//�}�b�v(��)����̎�ނ�ݒ肷��
BOOL MY_MAP_READ_CSV_NAKA_KIND_SET(MAPDATA *);	//�}�b�v(��)����̎�ނ�ݒ肷��
BOOL MY_MAP_READ_CSV_SITA_KIND_SET(MAPDATA *);	//�}�b�v(��)����̎�ނ�ݒ肷��
BOOL MY_MAP_READ_CSV_SIN_KIND_SET(MAPDATA *);//�}�b�v����̎�ނ�ݒ肷��
BOOL MY_MAP_READ_CSV_NUM(MAPDATA *, const char *, const char *);				//�Q�[���}�b�v��CSV��ǂݍ��ފ֐�

BOOL MY_ENEMY_READ_CSV(ENEDATA *, const char *, int);	//�G�̏���ݒ肷��

int MY_LOAD_BACKGROUND(IMAGE *, const char *);										//�w�i��ǂݍ��ސݒ������֐�

int LOAD_IMG(MAP_IMG *, const char *);										//�摜��ǂݍ��ސݒ������֐�

VOID DRAW_MAP(MAP_IMG *, int, int);		//	�}�b�v�`��


int MY_LOAD_ENEMY(ENEDATA *, const char *);									//�G��ǂݍ��ސݒ������֐�

//BOOL MY_MAP_LOAD_BUNKATSU(MAPDATA *, int, int, int, int, int, const char *);	//MAP�𕪊����ēǂݍ��ސݒ������֐�

VOID MY_PLAY_MAP_DRAW(MAPDATA);			//�}�b�v��`�悷��֐�
VOID MY_PLAY_MAP_DRAW_ATARI(MAPDATA *, MAPDATA *, MAPDATA *);	//�}�b�v�̓����蔻���`�悷��֐�
VOID PLAY_MAP_DRAW_ATARI(MAPDATA *);		//�}�b�v�̓����蔻��

BOOL MY_CHARA_LOAD_BUNKATSU(CHARAIMAGE*, int, int, int, int, int, const char *);	//�L�����摜�𕪊����ēǂݍ��ސݒ������֐�

BOOL MY_PLAYER_INIT(CHARADATA *, CHARAIMAGE, int *, int, int, int);	//�v���C���[������������֐�
VOID MY_PLAY_PLAYER_DRAW(CHARADATA);								//�v���C���[��\������֐�

VOID MY_PLAY_PLAYER_OPERATION(VOID);								//�v���C���[�𑀍삷��֐�
BOOL MY_PLAY_PLAYER_OPERATION_KEY(int *, int *);					//�v���C���[�𑀍삷��(�L�[����)�֐�
VOID MY_PLAY_PLAYER_OPERATION_ENCOUNTER(int *, int *);				//�v���C���[�𑀍삷��(�G�o��)�֐�

VOID MY_SET_PLAYER_ATARI(CHARADATA *);	//�v���C���[�̓����蔻��̗̈��ݒ肷��֐�

BOOL MY_CHECK_RECT_ATARI(RECT, RECT);	// �̈�̓����蔻�������֐�
BOOL MY_CHECK_RECT_ATARI_CHARA_MAP_ATARIBASHO(RECT, RECT map[GAME_MAP_TATE][GAME_MAP_YOKO], int *, int *);

BOOL MY_MUSIC_LOAD(MUSIC *, const char *);	//����ǂݍ��ސݒ������֐�

BOOL MY_GAME_NOWLOADING(VOID);				//�Q�[���Ŏg�p����A���y��摜�Ȃǂ�ǂݍ��ފ֐�
BOOL MY_GAME_IN_MUGENLOOP(VOID);			//�������[�v���œ��삷��֐�
VOID MY_GAME_DELETE(VOID);					//�Q�[�����œǂݍ��񂾉摜�≹�y���폜����֐�
/*******************MenuElement�B**********************/
typedef struct {
	int x, y;
	char name[128];
}MenuElement_t, MenuElement_y, MenuElement_z;

MenuElement_t MenuElement[3] = {
	{200,300,"�Q�[���������"},
	{220,320,"�Q�[���X�^�[�g"},
	//{220,300,"Virtual to LIVE"},
	//{220,320,"Fam Fam Time!"},
	//{220,340,"Buzz!!�胀�[�������g"},
	{220,340,"�Q�[�����I���"},
};

MenuElement_z Menu[3] = {
	{200,300,"map1"},
	{220,320,"map2"},
	{220,340,"map3"},
};

MenuElement_y MenuElemen[2] = {
	{100,100,"������x"},
	{120,150,"�^�C�g���֖߂�"},
};

double GET_TIME = 0;
double MY_GAME_GET_TIME = 0;

int FontHandle_Time = 0;

int time = 0;

//########## �v���O�����ōŏ��Ɏ��s�����֐� ##########
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	int IsLoad = FALSE;		//���y��摜�Ȃǂ�ǂݍ��߂����m�F����ϐ�

	ChangeWindowMode(GAME_WINDOW_MODECHANGE);					//�E�B���h�E���[�h�ɐݒ�
	SetGraphMode(GAME_WIDTH, GAME_HEIGHT, GAME_COLOR);			//�w��̐��l�ŉ�ʂ�\������

	SetWindowStyleMode(SET_WINDOW_ST_MODE_DEFAULT);				//�^�C�g���o�[����

	SetMainWindowText(TEXT(GAME_WINDOW_NAME));					//�^�C�g���̕���

	if (DxLib_Init() == -1) { return -1; }						//�c�w���C�u��������������

	SetDrawScreen(DX_SCREEN_BACK);								//Draw�n�֐��͗���ʂɕ`��

	//MY_MAP_READ_CSV_UE_KIND_SET(&mapData_ue);		//�}�b�v�̏�̎�ނ�ݒ�
	//MY_MAP_READ_CSV_NAKA_KIND_SET(&mapData_naka);	//�}�b�v�̒��̎�ނ�ݒ�
	//MY_MAP_READ_CSV_SITA_KIND_SET(&mapData_sita);	//�}�b�v�̉��̎�ނ�ݒ�
	MY_MAP_READ_CSV_SIN_KIND_SET(&mapData_sin);

	//MY_MAP_READ_CSV_NUM(&mapData_ue, GAME_MAP_CSV_1_UE, GAME_MAP_NAME_1_UE);		//�}�b�v�P�̏��ǂݍ��݁A�����蔻��̗̈�����
	//MY_MAP_READ_CSV_NUM(&mapData_naka, GAME_MAP_CSV_1_NAKA, GAME_MAP_NAME_1_NAKA);	//�}�b�v�P�̒���ǂݍ��݁A�����蔻��̗̈�����
	//MY_MAP_READ_CSV_NUM(&mapData_sita, GAME_MAP_CSV_1_SITA, GAME_MAP_NAME_1_SITA);	//�}�b�v�P�̉���ǂݍ��݁A�����蔻��̗̈�����
	MY_MAP_READ_CSV_NUM(&mapData_sin, MAP_CSV_1_SIN, MAP_NAME_1_SIN);//�}�b�v��csv��ǂݍ��݁A�����蔻��̗̈�����

	LOAD_IMG(&Map_Image, MAP_IMG_NAME);		//�}�b�v�摜�ǂݍ���

	//if (MY_MAP_LOAD_BUNKATSU(&mapData_ue, GAME_MAP_BUN_YOKO_CNT * GAME_MAP_BUN_TATE_CNT, GAME_MAP_BUN_YOKO_CNT, GAME_MAP_BUN_TATE_CNT, 32, 32, GAME_MAP_1_PATH) == FALSE) { MessageBox(NULL, GAME_MAP_1_PATH, "NotFound", MB_OK); return -1; }		//MAP��ǂݍ���
	//if (MY_MAP_LOAD_BUNKATSU(&mapData_naka, GAME_MAP_BUN_YOKO_CNT * GAME_MAP_BUN_TATE_CNT, GAME_MAP_BUN_YOKO_CNT, GAME_MAP_BUN_TATE_CNT, 32, 32, GAME_MAP_1_PATH) == FALSE) { MessageBox(NULL, GAME_MAP_1_PATH, "NotFound", MB_OK); return -1; }	//MAP��ǂݍ���
	//if (MY_MAP_LOAD_BUNKATSU(&mapData_sita, GAME_MAP_BUN_YOKO_CNT * GAME_MAP_BUN_TATE_CNT, GAME_MAP_BUN_YOKO_CNT, GAME_MAP_BUN_TATE_CNT, 32, 32, GAME_MAP_1_PATH) == FALSE) { MessageBox(NULL, GAME_MAP_1_PATH, "NotFound", MB_OK); return -1; }	//MAP��ǂݍ���

	//if (MY_MAP_LOAD_BUNKATSU(&mapData_sin, GAME_MAP_BUN_YOKO_CNT * GAME_MAP_BUN_TATE_CNT, GAME_MAP_BUN_YOKO_CNT, GAME_MAP_BUN_TATE_CNT, 32, 32, GAME_MAP_1_PATH) == FALSE) { MessageBox(NULL, GAME_MAP_1_PATH, "NotFound", MB_OK); return -1; }	//MAP��ǂݍ���

	if (MY_CHARA_LOAD_BUNKATSU(&CharaImage, GAME_CHARA_BUN_YOKO_CNT * GAME_CHARA_BUN_TATE_CNT, GAME_CHARA_BUN_YOKO_CNT, GAME_CHARA_BUN_TATE_CNT, GAME_CHARA_YOKO_SIZE, GAME_CHARA_TATE_SIZE, GAME_CHARA) == FALSE) { MessageBox(NULL, GAME_CHARA, "NotFound", MB_OK); return -1; }	//GAME_CHARA_1��ǂݍ���

	//���������� �v���O�����ǉ��������� ����������������������������������������
	//[01]�Q�[���Ŏg�p����A���y��摜�Ȃǂ�ǂݍ���
	//���������� �v���O�����ǉ������܂� ����������������������������������������
	IsLoad = MY_GAME_NOWLOADING();

	if (IsLoad == FALSE) { return -1; }	//�ǂݍ��݂Ɏ��s������A�����I��

	int IsInLoop = FALSE;		//�������[�v���œ��삷�鏈�����������s���Ă��邩�m�F����ϐ�

	//######################�ǉ�2/4###############################
	FontHandle_Time = CreateFontToHandle(NULL, 50, 9);

	while (TRUE)	//�������[�v
	{
		//���������� �v���O�����ǉ��������� ����������������������������������������
		//[03]�������[�v���œ��삷�鏈�����s�킹��
		//���������� �v���O�����ǉ������܂� ����������������������������������������
		IsInLoop = MY_GAME_IN_MUGENLOOP();

		if (IsInLoop == FALSE) { break; }			//�����Ɏ��s������A�����I��
	}

	//���������� �v���O�����ǉ��������� ����������������������������������������
	//[02]�Q�[�����œǂݍ��񂾉摜�≹�y���폜����
	//���������� �v���O�����ǉ������܂� ����������������������������������������
	MY_GAME_DELETE();

	DxLib_End();		//�c�w���C�u�����g�p�̏I������

	return 0;
}


//########## �Q�[���Ŏg�p����A���y��摜�Ȃǂ�ǂݍ��ފ֐� ##########
BOOL MY_GAME_NOWLOADING(VOID)
{
	//***�w�i��ǂݍ���***
	if (MY_LOAD_BACKGROUND(&image_title, GAME_TITLE_IMAGE) == FALSE) { MessageBox(NULL, GAME_TITLE_IMAGE, "NotFound", MB_OK); return FALSE; }				//IMAGE��ǂݍ���
	if (MY_LOAD_BACKGROUND(&image_backtitle, GAME_TITLE_BACKIMAGE) == FALSE) { MessageBox(NULL, GAME_TITLE_BACKIMAGE, "NotFound", MB_OK); return FALSE; }				//IMAGE��ǂݍ���
	if (MY_LOAD_BACKGROUND(&image_clear, GAME_CLEAR_IMAGE) == FALSE) { MessageBox(NULL, GAME_CLEAR_IMAGE, "NotFound", MB_OK); return FALSE; }				//IMAGE��ǂݍ���
	if (MY_LOAD_BACKGROUND(&image_grass, GAME_BT_GRASS_IMAGE) == FALSE) { MessageBox(NULL, GAME_BT_GRASS_IMAGE, "NotFound", MB_OK); return FALSE; }			//IMAGE��ǂݍ���
	if (MY_LOAD_BACKGROUND(&image_river, GAME_BT_RIVER_IMAGE) == FALSE) { MessageBox(NULL, GAME_BT_RIVER_IMAGE, "NotFound", MB_OK); return FALSE; }			//IMAGE��ǂݍ���
	if (MY_LOAD_BACKGROUND(&image_maou, GAME_BT_MAOU_IMAGE) == FALSE) { MessageBox(NULL, GAME_BT_MAOU_IMAGE, "NotFound", MB_OK); return FALSE; }			//IMAGE��ǂݍ���
	if (MY_LOAD_BACKGROUND(&image_boss, GAME_BT_BOSS_IMAGE) == FALSE) { MessageBox(NULL, GAME_BT_BOSS_IMAGE, "NotFound", MB_OK); return FALSE; }			//IMAGE��ǂݍ���

	//***�G�̉摜��ǂݍ���***
	if (MY_LOAD_ENEMY(&enedata[0], GAME_ENE_GRASS_1_IMAGE) == FALSE) { MessageBox(NULL, GAME_ENE_GRASS_1_IMAGE, "NotFound", MB_OK); return FALSE; }		//IMAGE��ǂݍ���
	if (MY_LOAD_ENEMY(&enedata[1], GAME_ENE_GRASS_2_IMAGE) == FALSE) { MessageBox(NULL, GAME_ENE_GRASS_2_IMAGE, "NotFound", MB_OK); return FALSE; }		//IMAGE��ǂݍ���
	if (MY_LOAD_ENEMY(&enedata[2], GAME_ENE_GRASS_3_IMAGE) == FALSE) { MessageBox(NULL, GAME_ENE_GRASS_3_IMAGE, "NotFound", MB_OK); return FALSE; }		//IMAGE��ǂݍ���
	if (MY_LOAD_ENEMY(&enedata[3], GAME_ENE_GRASS_4_IMAGE) == FALSE) { MessageBox(NULL, GAME_ENE_GRASS_4_IMAGE, "NotFound", MB_OK); return FALSE; }		//IMAGE��ǂݍ���

	if (MY_LOAD_ENEMY(&enedata[4], GAME_ENE_KUSA_1_IMAGE) == FALSE) { MessageBox(NULL, GAME_ENE_KUSA_1_IMAGE, "NotFound", MB_OK); return FALSE; }			//IMAGE��ǂݍ���
	if (MY_LOAD_ENEMY(&enedata[5], GAME_ENE_KUSA_2_IMAGE) == FALSE) { MessageBox(NULL, GAME_ENE_KUSA_2_IMAGE, "NotFound", MB_OK); return FALSE; }			//IMAGE��ǂݍ���
	if (MY_LOAD_ENEMY(&enedata[6], GAME_ENE_KUSA_3_IMAGE) == FALSE) { MessageBox(NULL, GAME_ENE_KUSA_3_IMAGE, "NotFound", MB_OK); return FALSE; }			//IMAGE��ǂݍ���
	if (MY_LOAD_ENEMY(&enedata[7], GAME_ENE_KUSA_4_IMAGE) == FALSE) { MessageBox(NULL, GAME_ENE_KUSA_4_IMAGE, "NotFound", MB_OK); return FALSE; }			//IMAGE��ǂݍ���
	if (MY_LOAD_ENEMY(&enedata[8], GAME_ENE_KUSA_5_IMAGE) == FALSE) { MessageBox(NULL, GAME_ENE_KUSA_5_IMAGE, "NotFound", MB_OK); return FALSE; }			//IMAGE��ǂݍ���

	if (MY_LOAD_ENEMY(&enedata[9], GAME_ENE_RIVER_1_IMAGE) == FALSE) { MessageBox(NULL, GAME_ENE_RIVER_1_IMAGE, "NotFound", MB_OK); return FALSE; }			//IMAGE��ǂݍ���
	if (MY_LOAD_ENEMY(&enedata[10], GAME_ENE_RIVER_2_IMAGE) == FALSE) { MessageBox(NULL, GAME_ENE_RIVER_2_IMAGE, "NotFound", MB_OK); return FALSE; }		//IMAGE��ǂݍ���
	if (MY_LOAD_ENEMY(&enedata[11], GAME_ENE_RIVER_3_IMAGE) == FALSE) { MessageBox(NULL, GAME_ENE_RIVER_3_IMAGE, "NotFound", MB_OK); return FALSE; }		//IMAGE��ǂݍ���
	if (MY_LOAD_ENEMY(&enedata[12], GAME_ENE_RIVER_4_IMAGE) == FALSE) { MessageBox(NULL, GAME_ENE_RIVER_4_IMAGE, "NotFound", MB_OK); return FALSE; }		//IMAGE��ǂݍ���

	if (MY_LOAD_ENEMY(&enedata[13], GAME_ENE_MAOU_1_IMAGE) == FALSE) { MessageBox(NULL, GAME_ENE_MAOU_1_IMAGE, "NotFound", MB_OK); return FALSE; }		//IMAGE��ǂݍ���
	if (MY_LOAD_ENEMY(&enedata[14], GAME_ENE_MAOU_2_IMAGE) == FALSE) { MessageBox(NULL, GAME_ENE_MAOU_2_IMAGE, "NotFound", MB_OK); return FALSE; }		//IMAGE��ǂݍ���
	if (MY_LOAD_ENEMY(&enedata[15], GAME_ENE_MAOU_3_IMAGE) == FALSE) { MessageBox(NULL, GAME_ENE_MAOU_3_IMAGE, "NotFound", MB_OK); return FALSE; }		//IMAGE��ǂݍ���
	if (MY_LOAD_ENEMY(&enedata[16], GAME_ENE_MAOU_4_IMAGE) == FALSE) { MessageBox(NULL, GAME_ENE_MAOU_4_IMAGE, "NotFound", MB_OK); return FALSE; }		//IMAGE��ǂݍ���
	if (MY_LOAD_ENEMY(&enedata[17], GAME_ENE_MAOU_5_IMAGE) == FALSE) { MessageBox(NULL, GAME_ENE_MAOU_5_IMAGE, "NotFound", MB_OK); return FALSE; }		//IMAGE��ǂݍ���
	if (MY_LOAD_ENEMY(&enedata[18], GAME_ENE_MAOU_6_IMAGE) == FALSE) { MessageBox(NULL, GAME_ENE_MAOU_6_IMAGE, "NotFound", MB_OK); return FALSE; }		//IMAGE��ǂݍ���

	if (MY_LOAD_ENEMY(&enedata[19], GAME_ENE_BOSS_IMAGE) == FALSE) { MessageBox(NULL, GAME_ENE_BOSS_IMAGE, "NotFound", MB_OK); return FALSE; }			//IMAGE��ǂݍ���

	//�G�̃f�[�^��ǂݍ���
	if (MY_ENEMY_READ_CSV(enedata, GAME_ENE_CSV_1, GAME_ENE_KIND_MAX) == FALSE) { MessageBox(NULL, GAME_ENE_CSV_1, "NotFound", MB_OK); return FALSE; }		//�G�̏���ǂݍ���

	//����ǂݍ���
	if (MY_MUSIC_LOAD(&MUSIC_MY_BGM_BATTLE, GAME_MUSIC_BATTLE) == FALSE) { MessageBox(NULL, GAME_MUSIC_BATTLE, "NotFound", MB_OK); return FALSE; }							//MUSIC��ǂݍ���
	if (MY_MUSIC_LOAD(&MUSIC_MY_SE_BATTLE_SELECT, GAME_MUSIC_BATTLE_SELECT) == FALSE) { MessageBox(NULL, GAME_MUSIC_BATTLE_SELECT, "NotFound", MB_OK); return FALSE; }		//MUSIC��ǂݍ���
	if (MY_MUSIC_LOAD(&MUSIC_MY_SE_BATTLE_ENTER, GAME_MUSIC_BATTLE_ENTER) == FALSE) { MessageBox(NULL, GAME_MUSIC_BATTLE_ENTER, "NotFound", MB_OK); return FALSE; }			//MUSIC��ǂݍ���
	if (MY_MUSIC_LOAD(&MUSIC_MY_SE_BATTLE_ATK, GAME_MUSIC_BATTLE_ATK) == FALSE) { MessageBox(NULL, GAME_MUSIC_BATTLE_ATK, "NotFound", MB_OK); return FALSE; }				//MUSIC��ǂݍ���
	if (MY_MUSIC_LOAD(&MUSIC_MY_BGM_BOSS, GAME_MUSIC_BOSS) == FALSE) { MessageBox(NULL, GAME_MUSIC_BOSS, "NotFound", MB_OK); return FALSE; }								//MUSIC��ǂݍ���
	if (MY_MUSIC_LOAD(&MUSIC_MY_SE_LEVELUP, GAME_MUSIC_LEVELUP) == FALSE) { MessageBox(NULL, GAME_MUSIC_LEVELUP, "NotFound", MB_OK); return FALSE; }						//MUSIC��ǂݍ���
	if (MY_MUSIC_LOAD(&MUSIC_MY_BGM_PLAY, GAME_MUSIC_PLAY) == FALSE) { MessageBox(NULL, GAME_MUSIC_PLAY, "NotFound", MB_OK); return FALSE; }								//MUSIC��ǂݍ���
	if (MY_MUSIC_LOAD(&MUSIC_MY_BGM_TITLE, GAME_MUSIC_TITLE) == FALSE) { MessageBox(NULL, GAME_MUSIC_BATTLE_ITEM, "NotFound", MB_OK); return FALSE; }						//MUSIC��ǂݍ���
	if (MY_MUSIC_LOAD(&MUSIC_MY_SE_BATTLE_ITEM, GAME_MUSIC_BATTLE_ITEM) == FALSE) { MessageBox(NULL, GAME_MUSIC_BATTLE_ITEM, "NotFound", MB_OK); return FALSE; }			//MUSIC��ǂݍ���
	if (MY_MUSIC_LOAD(&MUSIC_MY_SE_BATTLE_ESC, GAME_MUSIC_BATTLE_ESC) == FALSE) { MessageBox(NULL, GAME_MUSIC_BATTLE_ESC, "NotFound", MB_OK); return FALSE; }				//MUSIC��ǂݍ���
	if (MY_MUSIC_LOAD(&MUSIC_MY_SE_END_SELECT, GAME_MUSIC_END_SELECT) == FALSE) { MessageBox(NULL, GAME_MUSIC_END_SELECT, "NotFound", MB_OK); return FALSE; }				//MUSIC��ǂݍ���
	if (MY_MUSIC_LOAD(&MUSIC_MY_BGM_END, GAME_MUSIC_END) == FALSE) { MessageBox(NULL, GAME_MUSIC_END, "NotFound", MB_OK); return FALSE; }									//MUSIC��ǂݍ���

	//�t�H���g(�����̎��)��ǂݍ���
	FontDefault = CreateFontToHandle("MS �S�V�b�N", 16, 8);	if (FontDefault == -1) { return FALSE; }	//�ʏ�t�H���g
	FontBig = CreateFontToHandle("Impact", 90, 1);			if (FontBig == -1) { return FALSE; }		//�傫�ȃt�H���g
	FontFutsu = CreateFontToHandle("Impact", 48, 1);		if (FontFutsu == -1) { return FALSE; }		//���ʂȃt�H���g

}

//########## �Q�[�����œǂݍ��񂾉摜�≹�y���폜����֐� ##########
VOID MY_GAME_DELETE(VOID)
{
	//�}�b�v�̃n���h�����폜
	for (int mapCnt = 0; mapCnt < GAME_MAP_BUN_YOKO_CNT * GAME_MAP_BUN_TATE_CNT; mapCnt++)
	{
		DeleteGraph(mapData_ue.Handle[mapCnt]);
		DeleteGraph(mapData_sita.Handle[mapCnt]);
		DeleteGraph(mapData_sin.Handle[mapCnt]);
	}

	//�G�̃n���h�����폜
	for (int eneCnt = 0; eneCnt < GAME_ENE_KIND_MAX; eneCnt++)
	{
		DeleteGraph(enedata[eneCnt].Handle);
	}

	//�摜�̃n���h�����폜
	DeleteGraph(image_title.Handle[0]);
	DeleteGraph(image_backtitle.Handle[0]);
	DeleteGraph(image_clear.Handle[0]);
	DeleteGraph(image_grass.Handle[0]);
	DeleteGraph(image_river.Handle[0]);
	DeleteGraph(image_maou.Handle[0]);
	DeleteGraph(image_boss.Handle[0]);

	//�t�H���g�n���h�����폜
	DeleteFontToHandle(FontDefault);
	DeleteFontToHandle(FontBig);
	DeleteFontToHandle(FontFutsu);

	//���̃n���h�����폜
	DeleteMusicMem(MUSIC_MY_BGM_BATTLE.Handle);
	DeleteMusicMem(MUSIC_MY_SE_BATTLE_SELECT.Handle);
	DeleteMusicMem(MUSIC_MY_SE_BATTLE_ENTER.Handle);
	DeleteMusicMem(MUSIC_MY_SE_BATTLE_ATK.Handle);
	DeleteMusicMem(MUSIC_MY_BGM_BOSS.Handle);
	DeleteMusicMem(MUSIC_MY_SE_LEVELUP.Handle);
	DeleteMusicMem(MUSIC_MY_BGM_PLAY.Handle);
	DeleteMusicMem(MUSIC_MY_BGM_TITLE.Handle);
	DeleteMusicMem(MUSIC_MY_SE_BATTLE_ITEM.Handle);
	DeleteMusicMem(MUSIC_MY_SE_BATTLE_ESC.Handle);
	DeleteMusicMem(MUSIC_MY_SE_END_SELECT.Handle);
	DeleteMusicMem(MUSIC_MY_BGM_END.Handle);

	return;
}

//########## �Q�[���ł̖������[�v���̊֐� ##########
BOOL MY_GAME_IN_MUGENLOOP(VOID)
{
	if (ProcessMessage() != 0) { return FALSE; }	//���b�Z�[�W�����̌��ʂ��G���[�̂Ƃ��A�����I��

	if (ClearDrawScreen() != 0) { return FALSE; }	//��ʂ������ł��Ȃ������Ƃ��A�����I��

	MY_ALL_KEYDOWN_UPDATE();				//�L�[�̏�Ԃ��擾

	if (GameSceneNow != (int)GAME_SCENE_MOVE_SCENE)
	{
		SceneBefore = GameSceneNow;	//���̎��_�ł̃V�[�����擾
	}

	GET_TIME = GetNowCount();

	//�V�[���I��
	switch (GameSceneNow)
	{
	case (int)GAME_SCENE_TITLE:	//�^�C�g����ʂ̏�����������

		MY_GAME_TITLE();	//�^�C�g����ʂ̏���

		break;	//�^�C�g����ʂ̏��������܂�

//********************************�ǉ���������*****************************************
	case(int)GAME_SCENE_DESCRIPTION:

		MY_GAME_DESCRIPTION();

		break;

	case GAME_SCENE_CHOICE:

		MY_GAME_CHOICE();

		break;
		//****************************************************�����܂�*******************************************

	case (int)GAME_SCENE_PLAY:	//�v���C��ʂ̏�����������

		MY_GAME_PLAY();		//�v���C��ʂ̏���

		break;	//�v���C��ʂ̏��������܂�
	case (int)GAME_SCENE_BATTLE:	//�퓬��ʂ̏�����������

		//MY_GAME_BATTLE();		//�퓬��ʂ̏���

		break;	//�퓬��ʂ̏��������܂�

	case (int)GAME_SCENE_MOVE_SCENE:	//�V�[���ړ���ʂ̏�����������

		if (MY_GAME_SCENE_MOVE(SceneBefore) == TRUE)	//�V�[���ړ���ʂ̏���
		{
			if (SceneBefore == (int)GAME_SCENE_END)	//�G���h��ʂŉ�ʑJ�ڂ���Ƃ�
			{
				if (Myplayer.gameEndKind == (int)GAME_END_KIND_OVER)	//�Q�[���I�[�o�[�̂Ƃ�
				{
					if (MY_PLAY_INIT() == TRUE)		//�v���C��ʏ�����
					{
						//���͗D�����̂ŁA�X�e�[�^�X��S�񕜂����ďグ�܂��傤�B
						Myplayer.LV = Myplayer.EndLV;
						Myplayer.HP = Myplayer.HP_MAX = Myplayer.EndHP;
						Myplayer.ATK = Myplayer.ATK_MAX = Myplayer.EndATK;
						Myplayer.DEF = Myplayer.DEF_MAX = Myplayer.EndDEF;
					}
				}
			}

			GameSceneNow = SceneBefore = SceneNext;	//�V�[�������̉�ʂɂ���
		}
		break;	//�V�[���ړ���ʂ̏��������܂�

	case (int)GAME_SCENE_END:	//�G���h��ʂ̏�����������

		MY_GAME_END();		//�G���h��ʂ̏���

		break;	//�G���h��ʂ̏��������܂�

	default:

		break;

	}

	if (GameSceneNow != (int)GAME_SCENE_MOVE_SCENE)
	{
		SceneNext = GameSceneNow;	//���̎��_�ł̃V�[�����擾

		if (SceneBefore != SceneNext)	//�V�[�����Ⴄ�Ƃ��A��ʈړ����o
		{
			sceneMove.DrawCnt = 0;
			sceneMove.DrawCntMax = 30;
			sceneMove.DeleteX = 0;
			sceneMove.DeleteY = 0;
			sceneMove.kind = (int)GAME_MAE_EFFECT_FADEIN;	//�t�F�[�h�A�E�g

			GameSceneNow = (int)GAME_SCENE_MOVE_SCENE;	//�V�[���ړ���ʂ�
		}

	}

	MY_FPS_UPDATE();	//FPS�̏���[�X�V]

	MY_FPS_DRAW();		//FPS�̏���[�`��]

	ScreenFlip();		//���j�^�̃��t���b�V�����[�g�̑����ŗ���ʂ��ĕ`��

	MY_FPS_WAIT();		//FPS�̏���[�҂�]

	return TRUE;
}

//########## FPS�l���v���A�X�V����֐� ##########
VOID MY_FPS_UPDATE(VOID)
{
	if (CountFps == 0) //1�t���[���ڂȂ玞�����L��
	{
		StartTimeFps = GetNowCount();
	}

	if (CountFps == SampleNumFps) //60�t���[���ڂȂ畽�ς��v�Z
	{
		int now = GetNowCount();
		CalcFps = 1000.f / ((now - StartTimeFps) / (float)SampleNumFps);
		CountFps = 0;
		StartTimeFps = now;
	}
	CountFps++;
	return;
}

//########## FPS�l��`�悷��֐� ##########
VOID MY_FPS_DRAW(VOID)
{
	//�������`��
	DrawFormatStringToHandle(0, GAME_HEIGHT - 20, GetColor(255, 255, 255), FontDefault, "FPS:%.1f", CalcFps);
	return;
}

//########## FPS�l���v�����A�҂֐� ##########
VOID MY_FPS_WAIT(VOID)
{
	int resultTime = GetNowCount() - StartTimeFps;					//������������
	int waitTime = CountFps * 1000 / GAME_FPS_SPEED - resultTime;	//�҂ׂ�����

	if (waitTime > 0)		//�w���FPS�l���������ꍇ
	{
		Sleep(waitTime);	//�҂�
	}
	return;
}

//########## �L�[�̓��͏�Ԃ��X�V����֐� ##########
VOID MY_ALL_KEYDOWN_UPDATE(VOID)
{
	char TempKey[256];			//�ꎞ�I�ɁA���݂̃L�[�̓��͏�Ԃ��i�[����

	GetHitKeyStateAll(TempKey); // �S�ẴL�[�̓��͏�Ԃ𓾂�

	for (int i = 0; i < 256; i++)
	{
		if (TempKey[i] != 0)	//������Ă���L�[�̃L�[�R�[�h�������Ă���Ƃ�
		{
			AllKeyState[i]++;	//������Ă���
		}
		else
		{
			AllKeyState[i] = 0;	//������Ă��Ȃ�
		}
	}
	return;
}

//########## �^�C�g����ʂ̊֐� ##########
VOID MY_GAME_TITLE(VOID)
{
	//BGM������Ă��Ȃ��Ƃ�
	if (CheckSoundMem(MUSIC_MY_BGM_TITLE.Handle) == 0)
	{
		ChangeVolumeSoundMem(255 * 70 / 100, MUSIC_MY_BGM_TITLE.Handle);	//BGM�̉��ʂ�50���ɂ���
		PlaySoundMem(MUSIC_MY_BGM_TITLE.Handle, DX_PLAYTYPE_LOOP);			//BGM�𗬂�
	}

	if (AllKeyState[KEY_INPUT_RETURN] != 0)	//�G���^�[�L�[��������Ă�����
	{
		if (MY_PLAY_INIT() == TRUE)		//�v���C��ʏ�����
		{
			//GameSceneNow = (int)GAME_SCENE_PLAY;	//�V�[�����v���C��ʂɂ���
		}
	}
	/*MenuElement���j���[��I��*/

	if (AllKeyState[KEY_INPUT_DOWN] == 1) {
		SelectTitleNum = (SelectTitleNum + 1) % 3;
	}

	if (AllKeyState[KEY_INPUT_UP] == 1) {
		SelectTitleNum = (SelectTitleNum + 2) % 3;
	}

	if (AllKeyState[KEY_INPUT_DOWN] == 1 || AllKeyState[KEY_INPUT_UP] == 1) {
		for (int i = 0; i < 3; i++)
		{
			if (i == SelectTitleNum) {
				MenuElement[i].x = 200;
			}
			else {
				MenuElement[i].x = 220;
			}
		}
	}
	if (SelectTitleNum == 0 && AllKeyState[KEY_INPUT_RETURN] == 1)
	{
		GameSceneNow = GAME_SCENE_DESCRIPTION;
	}
	else if (SelectTitleNum == 1 && AllKeyState[KEY_INPUT_RETURN] == 1)
	{
		GameSceneNow = GAME_SCENE_CHOICE;
	}
	else if (SelectTitleNum == 2 && AllKeyState[KEY_INPUT_RETURN] == 1)//ESC�L�[����������I������
	{
		GameSceneNow = GAME_SCENE_END;
	}
	/*�����܂�*/
	MY_GAME_BACK_DRAW();
	MY_GAME_TITLE_DRAW();	//�^�C�g����ʕ`��̊֐�
	/**************************�ǉ�******************/
	for (int i = 0; i < 3; i++) {
		DrawFormatString(MenuElement[i].x, MenuElement[i].y, GetColor(255, 195, 123), "%s", MenuElement[i].name);
	}
	/**************************�����܂�**************************************/
	return;
}

//########## �^�C�g����ʕ`��̊֐� ##########
VOID MY_GAME_TITLE_DRAW(VOID)
{

	DrawGraph(GAME_WIDTH / 2 - image_title.Width[0] / 2, GAME_HEIGHT / 4 - image_title.Height[0] / 2, image_title.Handle[0], TRUE);

	DrawStringToHandle(0, 0, "�^�C�g�����", GetColor(255, 255, 255), FontDefault);

	return;
}

//#############�w�i�`��̊֐�#######################
VOID MY_GAME_BACK_DRAW(VOID)
{
	DrawGraph(GAME_WIDTH / 2 - image_backtitle.Width[0] / 2, GAME_HEIGHT / 2 - image_backtitle.Height[0] / 2, image_backtitle.Handle[0], TRUE);

	return;
}

//########## �������֐� ##########
BOOL MY_PLAY_INIT(VOID)
{
	ScrollCntYoko = 0;
	ScrollCntTate = 0;

	//�v���C���[�̉摜�̔ԍ���ݒ�
	int StartNum = (int)CHARA_KIND_1;
	int soeji = 0;
	PlayerImageNum[soeji++] = StartNum + 0;
	PlayerImageNum[soeji++] = StartNum + 1;
	PlayerImageNum[soeji++] = StartNum + 2;
	PlayerImageNum[soeji++] = StartNum + 3;
	PlayerImageNum[soeji++] = StartNum + 4;
	PlayerImageNum[soeji++] = StartNum + 5;
	PlayerImageNum[soeji++] = StartNum + 6;
	PlayerImageNum[soeji++] = StartNum + 7;
	PlayerImageNum[soeji++] = StartNum + 8;
	PlayerImageNum[soeji++] = StartNum + 9;
	PlayerImageNum[soeji++] = StartNum + 10;
	PlayerImageNum[soeji++] = StartNum + 11;
	PlayerImageNum[soeji++] = StartNum + 12;
	PlayerImageNum[soeji++] = StartNum + 13;
	PlayerImageNum[soeji++] = StartNum + 14;
	PlayerImageNum[soeji++] = StartNum + 15;
	PlayerImageNum[soeji++] = StartNum + 16;
	PlayerImageNum[soeji++] = StartNum + 17;
	PlayerImageNum[soeji++] = StartNum + 18;
	PlayerImageNum[soeji++] = StartNum + 19;
	PlayerImageNum[soeji++] = StartNum + 20;
	PlayerImageNum[soeji++] = StartNum + 21;
	PlayerImageNum[soeji++] = StartNum + 22;
	PlayerImageNum[soeji++] = StartNum + 23;

	//�v���C���[��������
	if (MY_PLAYER_INIT(&Myplayer, CharaImage, &PlayerImageNum[0], GAME_MAP_YOKO_SIZE * GAME_CHARA_STARTX, GAME_MAP_TATE_SIZE * GAME_CHARA_STARTY, GAME_CHARA_SPEED) == FALSE) { MessageBox(NULL, "CHARA_INIT", "NotFound", MB_OK); return FALSE; }

	//�G��������
	eneBattleNum_INIT.Handle = -1;
	eneBattleNum_INIT.X = -1;
	eneBattleNum_INIT.Y = -1;
	eneBattleNum_INIT.Width = -1;
	eneBattleNum_INIT.Height = -1;
	eneBattleNum_INIT.C_Width = -1;
	eneBattleNum_INIT.C_Height = -1;
	eneBattleNum_INIT.No = -1;
	eneBattleNum_INIT.LV = -1;
	wsprintf(eneBattleNum_INIT.name, "");
	eneBattleNum_INIT.enetype = -1;
	eneBattleNum_INIT.HP = -1;
	eneBattleNum_INIT.HP_MAX = -1;
	eneBattleNum_INIT.ATK = -1;
	eneBattleNum_INIT.ATK_MAX = -1;
	eneBattleNum_INIT.DEF = -1;
	eneBattleNum_INIT.DEF_MAX = -1;

	for (int kind = 0; kind < (int)GAME_ITEM_KIND_MAX; kind++)
	{
		for (int num = 0; num < GAME_PLAYER_ITEM_MAX; num++)
		{
			eneBattleNum_INIT.item[kind][num] = -1;
		}
	}

	eneBattleNum_INIT.IsAlive = TRUE;

	//�\���̈�̐ݒ�
	eneBattleNum_INIT.rect_st.left = -1;
	eneBattleNum_INIT.rect_st.top = -1;
	eneBattleNum_INIT.rect_st.right = -1;
	eneBattleNum_INIT.rect_st.bottom = -1;

	eneBattleNum_INIT.rect_act.left = -1;
	eneBattleNum_INIT.rect_act.top = -1;
	eneBattleNum_INIT.rect_act.right = -1;
	eneBattleNum_INIT.rect_act.bottom = -1;

	return TRUE;
}

VOID MY_GAME_DESCRIPTION(VOID)
{
	MY_GAME_BACK_DRAW();
	DrawString(0, 0, "�Q�[������", GetColor(255, 255, 255));
	if (AllKeyState[KEY_INPUT_RETURN] == 1)
	{
		GameSceneNow = 0;
	}

	return;
}

VOID MY_GAME_CHOICE(VOID)
{

	if (AllKeyState[KEY_INPUT_DOWN] == 1) {
		SelectSteageNum = (SelectSteageNum + 1) % 3;
	}

	if (AllKeyState[KEY_INPUT_UP] == 1) {
		SelectSteageNum = (SelectSteageNum + 2) % 3;
	}
	//���݂̃L�[�̈ʒu��\��
	if (AllKeyState[KEY_INPUT_DOWN] == 1 || AllKeyState[KEY_INPUT_UP] == 1) {
		for (int i = 0; i < 3; i++)
		{
			if (i == SelectSteageNum) {
				Menu[i].x = 200;
			}
			else {
				Menu[i].x = 220;
			}
		}
	}

	if (SelectSteageNum == 2 && AllKeyState[KEY_INPUT_RETURN] == 1)
	{
		GameSceneNow = GAME_SCENE_PLAY;
		play_scene = GAME_SCENE_PLAY;
		MY_GAME_GET_TIME = GET_TIME;
	}
	else if (SelectSteageNum == 1 && AllKeyState[KEY_INPUT_RETURN] == 1)
	{
		GameSceneNow = GAME_SCENE_PLAY;
		play_scene = GAME_SCENE_PLAY;
		MY_GAME_GET_TIME = GET_TIME;
	}
	else if (SelectSteageNum == 0 && AllKeyState[KEY_INPUT_RETURN] == 1)
	{
		GameSceneNow = GAME_SCENE_PLAY;
		play_scene = GAME_SCENE_PLAY;
		MY_GAME_GET_TIME = GET_TIME;
	}

	MY_GAME_BACK_DRAW();
	MY_GAME_TITLE_DRAW();

	/*MY_PLAY_BACKIMAGE_DRAW();*/

	for (int i = 0; i < 3; i++) {
		DrawFormatString(Menu[i].x, Menu[i].y, GetColor(255, 195, 123), "%s", Menu[i].name);
	}

	DrawString(0, 0, "�ȑI��", GetColor(255, 255, 255));

	/*if (AllKeyState[KEY_INPUT_RETURN] != 0)	//�G���^�[�L�[��������Ă�����
	{
		if (MY_PLAY_INIT() == TRUE)		//�v���C��ʏ�����
		{

			//Myplayer.Zanki = GAME_PLAYER_ZANKI_MAX;	//�c�@�̐ݒ�

			for (int tate = 0; tate < GAME_MAP_TATE; tate++)
			{
				for (int yoko = 0; yoko < GAME_MAP_YOKO; yoko++)
				{
					MapData[tate][yoko] = MapData_Init[tate][yoko];	//�}�b�v�����Ƃɖ߂�
				}
			}

			//Myplayer.GetCoinNum = 0;		//�Q�b�g�����R�C���̐���������

			//GameSceneNow = (int)GAME_SCENE_ZANKI;	//�V�[�����c�@�\����ʂɂ���

		}
	}*/

	DxLib_End;
	return;
}

//########## �v���C��ʂ̊֐� ##########
VOID MY_GAME_PLAY(VOID)
{
	//BGM������Ă��Ȃ��Ƃ�
	if (CheckSoundMem(MUSIC_MY_BGM_PLAY.Handle) == 0)
	{
		ChangeVolumeSoundMem(255 * 80 / 100, MUSIC_MY_BGM_PLAY.Handle);	//BGM�̉��ʂ�50���ɂ���
		PlaySoundMem(MUSIC_MY_BGM_PLAY.Handle, DX_PLAYTYPE_LOOP);			//BGM�𗬂�
	}

	if (AllKeyState[KEY_INPUT_RETURN] == 1) {
		GameSceneNow = GAME_SCENE_END;
	}


	MY_PLAY_PLAYER_OPERATION();		//�v���C���[�𑀍삷��

	DrawStringToHandle(0, 0, "�v���C���(�X�y�[�X�L�[�������Ă�������)", GetColor(255, 255, 255), FontDefault);

	MY_GAME_PLAY_DRAW();	//�v���C��ʕ`��

	/*time = */

	//�������������������Ԃ������܂���������������������������
	//DrawFormatStringToHandle(200, 1, GetColor(230, 50, 120), FontHandle_Time, "��������:%0.1lf�b", (GAME_TIME_SET - (GET_TIME - MY_GAME_GET_TIME) / 1000));

	/*if (GAME_TIME_SET - (GET_TIME - MY_GAME_GET_TIME) / 1000 <= 0)
	{
		GameSceneNow = GAME_SCENE_END;
	}*/
	//���������������������������܂Ł���������������������������������

	return;
}

// ########## �v���C��ʕ`��̊֐� ##########
VOID MY_GAME_PLAY_DRAW(VOID)
{
	//���������� �v���O�����ǉ��������� ����������������������������������������
	//[04]��ԉ��̃��C���[��`�悷��
	//���������� �v���O�����ǉ������܂� ����������������������������������������
	//MY_PLAY_MAP_DRAW(mapData_sita);

	////���������� �v���O�����ǉ��������� ����������������������������������������
	////[05]�^�񒆂̃��C���[��`�悷��
	////���������� �v���O�����ǉ������܂� ����������������������������������������
	//MY_PLAY_MAP_DRAW(mapData_naka);

	DRAW_MAP(&Map_Image, 0, 0);	//�}�b�v�`��

	MY_PLAY_PLAYER_DRAW(Myplayer);

	//���������� �v���O�����ǉ��������� ����������������������������������������
	//[06]��ԏ�̃��C���[��`�悷��
	//���������� �v���O�����ǉ������܂� ����������������������������������������
	//MY_PLAY_MAP_DRAW(mapData_ue);

	//MY_PLAY_MAP_DRAW_ATARI(&mapData_ue, &mapData_naka, &mapData_sita);
	PLAY_MAP_DRAW_ATARI(&mapData_sin);

	DrawStringToHandle(0, 0, "�v���C���", GetColor(255, 255, 255), FontDefault);

	return;
}

//########## �v���C���[������������֐� ##########
//���@���FCHARADATA �\���́F�ݒ肷��CHARADATA�\����
//���@���FCHARAIMAGE�\���́F�ݒ肷��CHARAIMAGE�\����
//���@���Fint* �@�@ �@�@�@�F�g�p����摜�̔ԍ��i�z��̐擪�A�h���X�������Ƃ���j
//���@���Fint�@	�@�@�@�@�@�F�摜�̏����ʒuX
//���@���Fint�@	�@�@�@�@�@�F�摜�̏����ʒuY
//���@���Fint�@	�@�@�@�@�@�F�ړ��X�s�[�h
//�߂�l�FBOOL�F�G���[���FFALSE
BOOL MY_PLAYER_INIT(CHARADATA *charadata, CHARAIMAGE charaimage, int *num, int x, int y, int speed)
{
	//*(num + 0)�͔z��̐擪�A�h���X

	for (int mot = 0; mot < GAME_CHARA_MOTION_NUM; mot++)
	{
		charadata->Handle[mot] = charaimage.HandleChara[mot];	//�摜�̃n���h��������
	}

	charadata->X = x;
	charadata->Y = y;
	charadata->Width = charaimage.Width[*(num + 0)];		//�ŏ��̉摜�̉�����ݒ肷��
	charadata->Height = charaimage.Height[*(num + 0)];		//�ŏ��̉摜�̍�����ݒ肷��
	charadata->C_Width = charaimage.C_Width[*(num + 0)];	//�ŏ��̉摜�̉����̒��S��ݒ肷��
	charadata->C_Height = charaimage.C_Height[*(num + 0)];	//�ŏ��̉摜�̍����̒��S��ݒ肷��

	//�}�b�v�ЂƂ�����Ɠ����傫���ɂ���
	charadata->Width = GAME_MAP_YOKO_SIZE;
	charadata->Height = GAME_MAP_TATE_SIZE;
	charadata->C_Width = GAME_MAP_YOKO_SIZE / 2;
	charadata->C_Height = GAME_MAP_TATE_SIZE / 2;

	charadata->NowHandleNum = 6;	//�O�����̍ŏ��̉摜
	charadata->NowHandleCnt = 0;	//�摜�J�E���^��������

	charadata->NowHandleCntMAX = 6;	//�摜�J�E���^MAX��������

	//***** �ȉ��A�p�����[�^�ݒ� **************************************************
	charadata->Speed = speed;			//�ړ����x��ݒ肷��

	charadata->MoveDistX = x;			//���̋������A�}�b�v�̍ŏ����瓮���������Ƃ��Đݒ肷��
	charadata->MoveDistY = y;			//���̋������A�}�b�v�̍ŏ����瓮���������Ƃ��Đݒ肷��

	charadata->CanMoveUp = TRUE;		//��Ɉړ��ł���
	charadata->CanMoveDown = TRUE;		//���Ɉړ��ł���
	charadata->CanMoveLeft = TRUE;		//���Ɉړ��ł���
	charadata->CanMoveRight = TRUE;		//�E�Ɉړ��ł���

	charadata->ScrollOK_X = FALSE;	//�ړ��ł��Ȃ�
	charadata->ScrollOK_Y = FALSE;	//�ړ��ł��Ȃ�

	charadata->atariX = 4;			//�����蔻���X�ʒu���A�C�C�����ɐݒ�
	charadata->atariY = 10;			//�����蔻���Y�ʒu���A�C�C�����ɐݒ�
	charadata->atariWidth = 18;		//�����蔻��̕��@���A�C�C�����ɐݒ�
	charadata->atariHeight = 24;	//�����蔻��̍������A�C�C�����ɐݒ�

	charadata->eneType = (int)GAME_ENETYPE_NONE;	//�G�̎�ނ͂Ȃ�

	wsprintf(charadata->name, GAME_PLAYER_NAME);	//���O��ݒ�

	charadata->LV = charadata->HP_MAX = GAME_PLAYER_LV_FIRST;			//�v���C���[�̍ŏ���LV
	charadata->HP = charadata->HP_MAX = GAME_PLAYER_HP_FIRST;			//�v���C���[�̍ŏ���HP
	charadata->ATK = charadata->ATK_MAX = GAME_PLAYER_ATK_FIRST;		//�v���C���[�̍ŏ���ATK
	charadata->DEF = charadata->DEF_MAX = GAME_PLAYER_DEF_FIRST;		//�v���C���[�̍ŏ���DEF

	charadata->act_kind = (int)GAME_ACT_KIND_ATK;	//�ŏ��͍U��
	charadata->IsActKeyDown_left = FALSE;			//�s���L�[�������Ă��Ȃ�
	charadata->IsActKeyDown_right = FALSE;			//�s���L�[�������Ă��Ȃ�
	charadata->battle_turn = (int)GAME_TURN_NONE;	//�^�[��������
	charadata->IsEsc = FALSE;						//�������Ȃ�
	charadata->IsActMsgStart = FALSE;			//�s�����b�Z�[�W�J�n
	charadata->IsActMsgEnd = FALSE;				//�s�����b�Z�[�W�I��

	charadata->NowActMsgCnt = 0;					//�s�����b�Z�[�W�J�E���g
	charadata->NowActMsgCntMAX = 90;				//�s�����b�Z�[�W�J�E���gMAX

	charadata->damageCalc = 0;	//�_���[�W�v�Z

	charadata->IsActLvupStart = FALSE;	//���x���A�b�v���b�Z�[�W�J�n
	charadata->IsActLvupEnd = FALSE;	//���x���A�b�v���b�Z�[�W�J�n
	charadata->NowActLvupCnt = 0;		//���x���A�b�v���b�Z�[�W�J�E���g
	charadata->NowActLvupntMAX = 150;	//���x���A�b�v���b�Z�[�W�J�E���gMAX

	charadata->IsAlive = TRUE;			//�����Ă���

	//�\���̈�̐ݒ�

	charadata->rect_st.left = GAME_BATTLE_MY_ST_LEFT;
	charadata->rect_st.top = GAME_BATTLE_MY_ST_TOP;
	charadata->rect_st.right = GAME_BATTLE_MY_ST_RIGHT;
	charadata->rect_st.bottom = GAME_BATTLE_MY_ST_BOTTOM;

	charadata->rect_act.left = GAME_BATTLE_MY_ACT_LEFT;
	charadata->rect_act.top = GAME_BATTLE_MY_ACT_TOP;
	charadata->rect_act.right = GAME_BATTLE_MY_ACT_RIGHT;
	charadata->rect_act.bottom = GAME_BATTLE_MY_ACT_BOTTOM;

	charadata->rect_act_atk.left = GAME_BATTLE_MY_ACT_ATK_LEFT;
	charadata->rect_act_atk.top = GAME_BATTLE_MY_ACT_ATK_TOP;
	charadata->rect_act_atk.right = GAME_BATTLE_MY_ACT_ATK_RIGHT;
	charadata->rect_act_atk.bottom = GAME_BATTLE_MY_ACT_ATK_BOTTOM;

	charadata->rect_act_item.left = GAME_BATTLE_MY_ACT_ITEM_LEFT;
	charadata->rect_act_item.top = GAME_BATTLE_MY_ACT_ITEM_TOP;
	charadata->rect_act_item.right = GAME_BATTLE_MY_ACT_ITEM_RIGHT;
	charadata->rect_act_item.bottom = GAME_BATTLE_MY_ACT_ITEM_BOTTOM;

	charadata->rect_act_esc.left = GAME_BATTLE_MY_ACT_ESC_LEFT;
	charadata->rect_act_esc.top = GAME_BATTLE_MY_ACT_ESC_TOP;
	charadata->rect_act_esc.right = GAME_BATTLE_MY_ACT_ESC_RIGHT;
	charadata->rect_act_esc.bottom = GAME_BATTLE_MY_ACT_ESC_BOTTOM;
	charadata->gameEndKind = (int)GAME_END_KIND_NONE;

	//�A�C�e���̏�����
	for (int kind = 0; kind < (int)GAME_ITEM_KIND_MAX; kind++)
	{
		for (int cnt = 0; cnt < GAME_PLAYER_ITEM_MAX; cnt++)
		{
			charadata->item[kind][cnt] = 0;	//�A�C�e�������������Ă��Ȃ�
		}
	}

	MY_SET_PLAYER_ATARI(charadata);	//�v���C���[�̓����蔻��̗̈��ݒ肷��

	return TRUE;
}

//########## �v���C���[�𑀍삷��֐� ##########
VOID MY_PLAY_PLAYER_OPERATION(VOID)
{
	int retAtariX = 0; int retAtariY = 0;	//�������Ă���}�b�v�̏ꏊ

	BOOL IsKeyDown = MY_PLAY_PLAYER_OPERATION_KEY(&retAtariX, &retAtariY);	//�L�[�������đ��삵�Ă��邩���f

	if (IsKeyDown == TRUE)	//�L�[���������Ƃ�
	{
		//MY_PLAY_PLAYER_OPERATION_ENCOUNTER(&retAtariX, &retAtariY);			//�G�o������
		static int x = 0, y = 0;
		if (MY_CHECK_RECT_ATARI_CHARA_MAP_ATARIBASHO(Myplayer.atariRect, mapData_sin.rect_CL, &x, &y) == TRUE)	//�S�[���̎�
		{
			GameSceneNow = (int)GAME_SCENE_END;	//�G���h��ʂ�
		}


	}

	return;
}

//########## �v���C���[�𑀍삷��(�L�[����)�֐� ##########
BOOL MY_PLAY_PLAYER_OPERATION_KEY(int *x, int *y)
{
	BOOL IsKeyDown = FALSE;		//�L�[�������ꂽ��

	if (AllKeyState[KEY_INPUT_LEFT] != 0)	//�����L�[��������Ă�����
	{
		IsKeyDown = TRUE;	//�L�[�������ꂽ

		Myplayer.CanMoveLeft = TRUE;	//�������ɁA�܂�������

		MY_SET_PLAYER_ATARI(&Myplayer);	//�v���C���[�̓����蔻��̗̈��ݒ�
		Myplayer.atariRect.left -= 4;	//�����A�����蔻��̗̈�����ɂ��炷
		Myplayer.atariRect.right -= 4;	//�����A�����蔻��̗̈�����ɂ��炷

		//if (MY_CHECK_RECT_ATARI_CHARA_MAP_ATARIBASHO(Myplayer.atariRect, mapData_naka.rect_NG, x, y) == TRUE)	//���ɍs���Ȃ����m�Ɠ��������Ƃ�
		//{
		//	Myplayer.CanMoveLeft = FALSE;	//���ɍs���Ȃ�
		//}

		if (MY_CHECK_RECT_ATARI_CHARA_MAP_ATARIBASHO(Myplayer.atariRect, mapData_sin.rect_NG, x, y) == TRUE)	//���ɍs���Ȃ����m�Ɠ��������Ƃ�
		{
			Myplayer.CanMoveLeft = FALSE;	//���ɍs���Ȃ�
		}

		if (Myplayer.CanMoveLeft == TRUE)	//���Ɉړ��ł���Ƃ�
		{
			if (Myplayer.ScrollOK_X == FALSE)	//�X�N���[���ł��Ȃ��Ƃ�
			{
				if (Myplayer.X > 0)
				{
					Myplayer.X -= Myplayer.Speed;	//�v���C���[�����Ɉړ�
				}
			}
			else	//�X�N���[���ł���Ƃ�
			{
				if (ScrollCntYoko > 0)	//�}�b�v�O�փX�N���[�����Ȃ�
				{
					ScrollCntYoko -= Myplayer.Speed;	//��ʂ����ɃX�N���[��
				}
			}

			if (Myplayer.MoveDistX > 0)
			{
				Myplayer.MoveDistX -= Myplayer.Speed;	//�������������v�Z
			}
		}

	}

	if (AllKeyState[KEY_INPUT_RIGHT] != 0)	//�E���L�[��������Ă�����
	{
		IsKeyDown = TRUE;	//�L�[�������ꂽ

		Myplayer.CanMoveRight = TRUE;	//�E�����ɁA�܂�������

		MY_SET_PLAYER_ATARI(&Myplayer);	//�v���C���[�̓����蔻��̗̈��ݒ�
		Myplayer.atariRect.left += 4;	//�����A�v���C���[�̓����蔻��̗̈���E�ɂ��炷
		Myplayer.atariRect.right += 4;	//�����A�v���C���[�̓����蔻��̗̈���E�ɂ��炷

		//if (MY_CHECK_RECT_ATARI_CHARA_MAP_ATARIBASHO(Myplayer.atariRect, mapData_naka.rect_NG, x, y) == TRUE)	//�E�ɍs���Ȃ����m�Ɠ��������Ƃ�
		//{
		//	Myplayer.CanMoveRight = FALSE;	//�E�ɍs���Ȃ�
		//}

		if (MY_CHECK_RECT_ATARI_CHARA_MAP_ATARIBASHO(Myplayer.atariRect, mapData_sin.rect_NG, x, y) == TRUE)	//�E�ɍs���Ȃ����m�Ɠ��������Ƃ�
		{
			Myplayer.CanMoveRight = FALSE;	//�E�ɍs���Ȃ�
		}

		if (Myplayer.CanMoveRight == TRUE)	//�E�Ɉړ��ł���Ƃ�
		{
			if (Myplayer.ScrollOK_X == FALSE)	//�v���C���[��������Ƃ�
			{
				if (Myplayer.X + Myplayer.Width < GAME_WIDTH)
				{
					Myplayer.X += Myplayer.Speed;			//�v���C���[���E�Ɉړ�
				}
			}
			else	//�v���C���[�������Ȃ��Ƃ�
			{
				if (ScrollCntYoko < GAME_MAP_YOKO_SIZE * GAME_MAP_YOKO)	//��ʊO�փX�N���[�����Ȃ�
				{
					ScrollCntYoko += Myplayer.Speed;	//��ʂ��E�ɃX�N���[��
				}
			}

			if (Myplayer.MoveDistX < GAME_MAP_YOKO_SIZE * GAME_MAP_YOKO)
			{
				Myplayer.MoveDistX += Myplayer.Speed;	//�������������v�Z
			}
		}
	}

	if (AllKeyState[KEY_INPUT_UP] != 0)	//����L�[��������Ă�����
	{
		IsKeyDown = TRUE;	//�L�[�������ꂽ

		Myplayer.CanMoveUp = TRUE;	//������ɁA�܂�������

		MY_SET_PLAYER_ATARI(&Myplayer);	//�v���C���[�̓����蔻��̗̈��ݒ�
		Myplayer.atariRect.top -= 4;	//�����A�����蔻��̗̈����ɂ��炷
		Myplayer.atariRect.bottom -= 4;	//�����A�����蔻��̗̈����ɂ��炷

		//if (MY_CHECK_RECT_ATARI_CHARA_MAP_ATARIBASHO(Myplayer.atariRect, mapData_naka.rect_NG, x, y) == TRUE)	//��ɍs���Ȃ����m�Ɠ��������Ƃ�
		//{
		//	Myplayer.CanMoveUp = FALSE;	//��ɍs���Ȃ�
		//}

		if (MY_CHECK_RECT_ATARI_CHARA_MAP_ATARIBASHO(Myplayer.atariRect, mapData_sin.rect_NG, x, y) == TRUE)	//��ɍs���Ȃ����m�Ɠ��������Ƃ�
		{
			Myplayer.CanMoveUp = FALSE;	//��ɍs���Ȃ�
		}

		if (Myplayer.CanMoveUp == TRUE)	//��Ɉړ��ł���Ƃ�
		{
			if (Myplayer.ScrollOK_Y == FALSE)	//�v���C���[��������Ƃ�
			{
				if (Myplayer.Y > 0)
				{
					Myplayer.Y -= Myplayer.Speed;	//�v���C���[����Ɉړ�
				}
			}
			else	//�X�N���[���ł���Ƃ�
			{
				if (ScrollCntTate > 0)	//�}�b�v�O�փX�N���[�����Ȃ�
				{
					ScrollCntTate -= Myplayer.Speed;	//��ʂ���ɃX�N���[��
				}
			}

			if (Myplayer.MoveDistY > 0)
			{
				Myplayer.MoveDistY -= Myplayer.Speed;	//�������������v�Z
			}
		}
	}

	if (AllKeyState[KEY_INPUT_DOWN] != 0)	//�����L�[��������Ă�����
	{
		IsKeyDown = TRUE;	//�L�[�������ꂽ

		Myplayer.CanMoveDown = TRUE;	//�������ɁA�܂�������

		MY_SET_PLAYER_ATARI(&Myplayer);	//�v���C���[�̓����蔻��̗̈��ݒ�
		Myplayer.atariRect.top += 4;	//�����A�v���C���[�̓����蔻��̗̈�����ɂ��炷
		Myplayer.atariRect.bottom += 4;	//�����A�v���C���[�̓����蔻��̗̈�����ɂ��炷

		//if (MY_CHECK_RECT_ATARI_CHARA_MAP_ATARIBASHO(Myplayer.atariRect, mapData_naka.rect_NG, x, y) == TRUE)	//���ɍs���Ȃ����m�Ɠ��������Ƃ�
		//{
		//	Myplayer.CanMoveDown = FALSE;	//���ɍs���Ȃ�
		//}

		if (MY_CHECK_RECT_ATARI_CHARA_MAP_ATARIBASHO(Myplayer.atariRect, mapData_sin.rect_NG, x, y) == TRUE)	//���ɍs���Ȃ����m�Ɠ��������Ƃ�
		{
			Myplayer.CanMoveDown = FALSE;	//���ɍs���Ȃ�
			//if()
		}

		if (Myplayer.CanMoveDown == TRUE)	//���Ɉړ��ł���Ƃ�
		{
			if (Myplayer.ScrollOK_Y == FALSE)	//�v���C���[��������Ƃ�
			{
				if (Myplayer.Y + Myplayer.Width < GAME_HEIGHT)
				{
					Myplayer.Y += Myplayer.Speed;			//�v���C���[�����Ɉړ�
				}
			}
			else	//�v���C���[�������Ȃ��Ƃ�
			{
				if (ScrollCntTate < GAME_MAP_TATE_SIZE * GAME_MAP_TATE)	//��ʊO�փX�N���[�����Ȃ�
				{
					ScrollCntTate += Myplayer.Speed;	//��ʉ��ɃX�N���[��
				}
			}

			if (Myplayer.MoveDistY < GAME_MAP_TATE_SIZE * (GAME_MAP_TATE - 1))
			{
				Myplayer.MoveDistY += Myplayer.Speed;	//�������������v�Z
			}
		}
	}

	//�}�b�v�̍����ɂ���Ƃ��́A�v���C���[�𓮂���
	if (Myplayer.MoveDistX > 0 &&
		Myplayer.MoveDistX <= GAME_MAP_YOKO_SIZE * 10)	//�v���C���[�̓��������������ȏ゠���(�J�n�n�_)
	{
		Myplayer.ScrollOK_X = FALSE;					//�}�b�v���~�߂āA�v���C���[�𓮂���
	}

	//�}�b�v�^�񒆂�ւ�ɂ���Ƃ��́A�}�b�v�𓮂���
	if (Myplayer.MoveDistX > GAME_MAP_YOKO_SIZE * 10 &&
		Myplayer.MoveDistX <= GAME_MAP_YOKO_SIZE * (GAME_MAP_YOKO - 15))	//�v���C���[�̓��������������ȏ゠���(�J�n�n�_)
	{
		Myplayer.ScrollOK_X = TRUE;					//�}�b�v�𓮂���
	}

	//�}�b�v�̉E���ɂ���Ƃ��́A�v���C���[�𓮂���
	if (Myplayer.MoveDistX > GAME_MAP_YOKO_SIZE * (GAME_MAP_YOKO - 15) &&
		Myplayer.MoveDistX <= GAME_MAP_YOKO_SIZE * GAME_MAP_YOKO)	//�v���C���[�̓��������������ȏ゠���(�I���n�_)
	{
		Myplayer.ScrollOK_X = FALSE;					//�}�b�v���~�߂āA�v���C���[�𓮂���
	}

	//�}�b�v�̏㑤�ɂ���Ƃ��́A�v���C���[�𓮂���
	if (Myplayer.MoveDistY > 0 &&
		Myplayer.MoveDistY <= GAME_MAP_TATE_SIZE * 10)	//�v���C���[�̓��������������ȏ゠���(�J�n�n�_)
	{
		Myplayer.ScrollOK_Y = FALSE;					//�}�b�v���~�߂āA�v���C���[�𓮂���
	}

	//�}�b�v�^�񒆂�ւ�ɂ���Ƃ��́A�}�b�v�𓮂���
	if (Myplayer.MoveDistY > GAME_MAP_TATE_SIZE * 10 &&
		Myplayer.MoveDistY <= GAME_MAP_TATE_SIZE * (GAME_MAP_TATE - 9))	//�v���C���[�̓��������������ȏ゠���(�J�n�n�_)
	{
		Myplayer.ScrollOK_Y = TRUE;					//�}�b�v�𓮂���
	}

	//�}�b�v�̉����ɂ���Ƃ��́A�v���C���[�𓮂���
	if (Myplayer.MoveDistY > GAME_MAP_TATE_SIZE * (GAME_MAP_TATE - 9) &&
		Myplayer.MoveDistY <= GAME_MAP_TATE_SIZE * GAME_MAP_TATE)	//�v���C���[�̓��������������ȏ゠���(�I���n�_)
	{
		Myplayer.ScrollOK_Y = FALSE;	//�}�b�v���~�߂āA�v���C���[�𓮂���
	}



	return IsKeyDown;
}

//########## �v���C���[�𑀍삷��(�G�o��)�֐� ##########
VOID MY_PLAY_PLAYER_OPERATION_ENCOUNTER(int *x, int *y)
{
	MY_SET_PLAYER_ATARI(&Myplayer);	//�v���C���[�̓����蔻��̗̈��ݒ�

	//�G���J�E���g���肪�n�ʂɂ���Ƃ�
	if (MY_CHECK_RECT_ATARI_CHARA_MAP_ATARIBASHO(Myplayer.atariRect, mapData_sita.rect_BT, x, y) == TRUE)
	{
		Myplayer.eneType = mapData_sita.data[*(y)][*(x)];			//�}�b�v�̃f�[�^��G�̃^�C�v�ɂ���	

		int battleRate;		//�퓬�J�n��
		switch (Myplayer.eneType)
		{
		case (int)GAME_ENETYPE_GRASS:
			battleRate = 100;		//100���1��͐퓬����
			break;
		case (int)GAME_ENETYPE_RIVER:
			battleRate = 50;		//50���1��͐퓬����
			break;
		case (int)GAME_ENETYPE_KUSA:
			battleRate = 100;		//100���1��͐퓬����
			break;
		case (int)GAME_ENETYPE_MAOU:
			battleRate = 400;		//400���1��͐퓬����
			break;
		case (int)GAME_ENETYPE_BOSS:
			battleRate = 1;			//�K���퓬����
			break;
		default:
			break;
		}

		//�����_���Ő퓬�̔���
		//int random = GetRand(battleRate);	//0�`MAX�܂ł̐��l�������_���ɓ���

	//	if (random % battleRate == 0)		//�G���o��������Ƃ�
	//	{
	//		Myplayer.eneBattleCnt = MY_RANGE_RAND(1, GAME_ENE_BATTLE_NUM_MAX);	//�����_���ɓG�̏o������I��

	//		Myplayer.eneBattleCnt = 1;

	//		//MY_BATTLE_ENEMY_INIT(*(x), *(y));	//�G��������

	//		//Myplayer.NowActMsgCnt = 0;		//�s�����b�Z�[�W�J�E���^
	//		//Myplayer.IsEsc = FALSE;			//�������Ȃ�
	//		//Myplayer.IsActMsgStart = FALSE;	//�s�����b�Z�[�W�J�n
	//		//Myplayer.IsActMsgEnd = FALSE;	//�s�����b�Z�[�W�I��

	//		//Myplayer.IsActLvupStart = FALSE;	//���x���A�b�v���b�Z�[�W�J�n
	//		//Myplayer.IsActLvupEnd = FALSE;	//���x���A�b�v���b�Z�[�W�I��
	//		//Myplayer.NowActLvupCnt = 0;			//���x���A�b�v���b�Z�[�W�J�E���^

	//		//Myplayer.act_kind = (int)GAME_ACT_KIND_ATK;	//�s���͍U������
	//		//Myplayer.battle_turn = (int)GAME_TURN_MY;	//�����̃^�[������

	//		GameSceneNow = (int)GAME_SCENE_BATTLE;	//�퓬��ʂֈړ�
	//	}
	}
}

//########## �퓬�O�ɓG������������֐� ##########
VOID MY_BATTLE_ENEMY_INIT(int retAtariX, int retAtariY)
{
	//�G�̃f�[�^�̏�����
	for (int i = 0; i < GAME_ENE_BATTLE_NUM_MAX; i++) { eneBattle[i] = eneBattleNum_INIT; }

	int rate;	//�o����
	switch (Myplayer.eneType)	//�^�C�v�ɍ��킹�āA�G�������_���őI��
	{
	case (int)GAME_ENETYPE_GRASS:
		for (int i = 0; i < Myplayer.eneBattleCnt; i++)
		{
			rate = GetRand(99);	//(0�`99)�܂ł̂ǂꂩ�������_���őI��

			if (rate >= 0 && rate < 40)			//�o����40��
			{
				eneBattle[i] = enedata[0];
			}
			else if (rate >= 40 && rate < 70)	//�o����30��
			{
				eneBattle[i] = enedata[1];
			}
			else if (rate >= 70 && rate < 90)	//�o����20��
			{
				eneBattle[i] = enedata[2];
			}
			else if (rate >= 90 && rate < 100)	//�o����10��
			{
				eneBattle[i] = enedata[3];
			}

		}
		break;
	case (int)GAME_ENETYPE_KUSA:
		for (int i = 0; i < Myplayer.eneBattleCnt; i++)
		{
			rate = GetRand(99);	//(0�`99)�܂ł̂ǂꂩ�������_���őI��

			if (rate >= 0 && rate < 20)			//�o����25��
			{
				eneBattle[i] = enedata[4];
			}
			else if (rate >= 20 && rate < 40)	//�o����20��
			{
				eneBattle[i] = enedata[5];
			}
			else if (rate >= 40 && rate < 60)	//�o����20��
			{
				eneBattle[i] = enedata[6];
			}
			else if (rate >= 60 && rate < 80)	//�o����20��
			{
				eneBattle[i] = enedata[7];
			}
			else if (rate >= 80 && rate < 100)	//�o����20��
			{
				eneBattle[i] = enedata[8];
			}
		}
		break;
	case (int)GAME_ENETYPE_RIVER:
		for (int i = 0; i < Myplayer.eneBattleCnt; i++)
		{
			rate = GetRand(99);	//(0�`99)�܂ł̂ǂꂩ�������_���őI��

			if (rate >= 0 && rate < 25)			//�o����25��
			{
				eneBattle[i] = enedata[9];
			}
			else if (rate >= 25 && rate < 50)	//�o����25��
			{
				eneBattle[i] = enedata[10];
			}
			else if (rate >= 50 && rate < 75)	//�o����25��
			{
				eneBattle[i] = enedata[11];
			}
			else if (rate >= 75 && rate < 100)	//�o����25��
			{
				eneBattle[i] = enedata[12];
			}
		}
		break;
	case (int)GAME_ENETYPE_MAOU:
		for (int i = 0; i < Myplayer.eneBattleCnt; i++)
		{
			rate = GetRand(99);	//(0�`99)�܂ł̂ǂꂩ�������_���őI��

			if (rate >= 0 && rate < 20)			//�o����20��
			{
				eneBattle[i] = enedata[13];
			}
			else if (rate >= 20 && rate < 30)	//�o����10��
			{
				eneBattle[i] = enedata[14];
			}
			else if (rate >= 30 && rate < 50)	//�o����20��
			{
				eneBattle[i] = enedata[15];
			}
			else if (rate >= 50 && rate < 60)	//�o����10��
			{
				eneBattle[i] = enedata[16];
			}
			else if (rate >= 60 && rate < 80)	//�o����20��
			{
				eneBattle[i] = enedata[17];
			}
			else if (rate >= 80 && rate < 100)	//�o����20��
			{
				eneBattle[i] = enedata[18];
			}
		}
		break;
	case (int)GAME_ENETYPE_BOSS:

		eneBattle[0] = enedata[19];	//�{�X�͕K���o��

		break;
	default:
		break;
	}

	if (Myplayer.eneBattleCnt == 1)
	{
		int TekiCenter = GAME_WIDTH / 2;	//�G�̕��̒��S���v�Z

		eneBattle[0].rect_act.left = GAME_WIDTH / 2 - eneBattle[0].C_Width;
		eneBattle[0].rect_act.top = GAME_HEIGHT / 2 - eneBattle[0].C_Height;
		eneBattle[0].rect_act.right = GAME_WIDTH / 2 + eneBattle[0].C_Width;
		eneBattle[0].rect_act.bottom = GAME_HEIGHT / 2 + eneBattle[0].C_Height;

		eneBattle[0].rect_st.left = eneBattle[0].rect_act.left + (eneBattle[0].rect_act.right - eneBattle[0].rect_act.left) / 2 - GAME_BATTLE_TEKI_ACT_WIDTH / 2;	//�G�̉摜�ɒ�����
		eneBattle[0].rect_st.top = eneBattle[0].rect_act.top - GAME_BATTLE_TEKI_ACT_HEIGHT - 5;
		eneBattle[0].rect_st.right = eneBattle[0].rect_st.left + GAME_BATTLE_TEKI_ACT_WIDTH;
		eneBattle[0].rect_st.bottom = eneBattle[0].rect_st.top + GAME_BATTLE_TEKI_ACT_HEIGHT;
		eneBattle[0].IsAlive = TRUE;
	}

}

//########## �͈͂��w�肵��rand���s�� ##########
int MY_RANGE_RAND(int min, int max)
{
	return min + (int)(rand()*(max - min + 1.0) / (1.0 + RAND_MAX));
}

//########## �L�����N�^�[�ƃ}�b�v�̓����蔻�������֐�(���������ꏊ��m��) ##########
//���@���@�FRECT	�F�����蔻�������̈�(�L�����N�^�[)
//���@���@�FRECT	�F�����蔻�������̈�(�}�b�v)
//���@���@�Fint 	�F���������ꏊ(X�ʒu)
//���@���@�Fint 	�F���������ꏊ(Y�ʒu)
//�߂�l�@�F�������Ă���FTRUE / �������Ă��Ȃ� / FALSE
BOOL MY_CHECK_RECT_ATARI_CHARA_MAP_ATARIBASHO(RECT chara, RECT map[GAME_MAP_TATE][GAME_MAP_YOKO], int *atariX, int *atariY)
{
	for (int tate = 0; tate < GAME_MAP_TATE; tate++)
	{
		for (int yoko = 0; yoko < GAME_MAP_YOKO; yoko++)
		{
			//�L�����N�^�[�̓������Ă���ꏊ���擾
			if (MY_CHECK_RECT_ATARI(chara, map[tate][yoko]) == TRUE)
			{
				*atariY = tate;	//atariY�̃A�h���X���w��������̏ꏊ�ɁA�����������m�̏c�̈ʒu������
				*atariX = yoko;	//atariX�̃A�h���X���w��������̏ꏊ�ɁA�����������m�̉��̈ʒu������

				return TRUE;
			}
		}
	}

	return FALSE;		//�������Ă��Ȃ�
}

//########## �̈�̓����蔻�������֐� ##########
BOOL MY_CHECK_RECT_ATARI(RECT a, RECT b)
{
	if (a.left < b.right &&
		a.top < b.bottom &&
		a.right > b.left &&
		a.bottom > b.top
		)
	{
		return TRUE;	//�������Ă���
	}

	return FALSE;		//�������Ă��Ȃ�
}

//########## �v���C���[�̓����蔻��̗̈��ݒ肷��֐� ##########
VOID MY_SET_PLAYER_ATARI(CHARADATA *charadata)
{
	//�����蔻��̗̈�̐ݒ�
	charadata->atariRect.left = charadata->X + charadata->atariX + 2;						//���݂�X�ʒu �{ �����蔻���X�ʒu
	charadata->atariRect.top = charadata->Y + charadata->atariY + 2;						//���݂�Y�ʒu �{ �����蔻���Y�ʒu
	charadata->atariRect.right = charadata->X + charadata->atariX + charadata->atariWidth - 2;		//���݂�X�ʒu �{ �����蔻���X�ʒu �{ �����蔻��̕�
	charadata->atariRect.bottom = charadata->Y + charadata->atariY + charadata->atariHeight - 2;	//���݂�Y�ʒu �{ �����蔻���Y�ʒu �{ �����蔻��̍���

	return;
}

//########## �v���C���[��\������֐� ##########
VOID MY_PLAY_PLAYER_DRAW(CHARADATA player)
{
	//�v���C���[��`��
	DrawGraph(
		player.X,
		player.Y,
		player.Handle[player.NowHandleNum], TRUE);

	if (DEBUG_MODE)
	{
		DrawBox(
			player.atariRect.left,
			player.atariRect.top,
			player.atariRect.right,
			player.atariRect.bottom,
			GetColor(0, 0, 255), FALSE);	//�g���`��
	}

	if (AllKeyState[KEY_INPUT_LEFT] != 0)	//�����L�[��������Ă�����
	{
		if (Myplayer.NowHandleCnt < Myplayer.NowHandleCntMAX)
		{
			Myplayer.NowHandleCnt++;
		}
		else
		{
			Myplayer.NowHandleCnt = 0;

			if (Myplayer.NowHandleNum >= 6 && Myplayer.NowHandleNum < 8)
			{
				Myplayer.NowHandleNum++;	//���̍������̉摜
			}
			else
			{
				Myplayer.NowHandleNum = 6;	//��ԍŏ��̍������̉摜
			}
		}
	}
	else if (AllKeyState[KEY_INPUT_RIGHT] != 0)	//�E���L�[��������Ă�����
	{
		if (Myplayer.NowHandleCnt < Myplayer.NowHandleCntMAX)
		{
			Myplayer.NowHandleCnt++;
		}
		else
		{
			Myplayer.NowHandleCnt = 0;

			if (Myplayer.NowHandleNum >= 12 && Myplayer.NowHandleNum < 14)
			{
				Myplayer.NowHandleNum++;	//���̉E�����̉摜
			}
			else
			{
				Myplayer.NowHandleNum = 12;	//��ԍŏ��̉E�����̉摜
			}
		}
	}
	else if (AllKeyState[KEY_INPUT_UP] != 0)	//����L�[��������Ă�����
	{
		if (Myplayer.NowHandleCnt < Myplayer.NowHandleCntMAX)
		{
			Myplayer.NowHandleCnt++;
		}
		else
		{
			Myplayer.NowHandleCnt = 0;

			if (Myplayer.NowHandleNum >= 18 && Myplayer.NowHandleNum < 20)
			{
				Myplayer.NowHandleNum++;	//���̏�����̉摜
			}
			else
			{
				Myplayer.NowHandleNum = 18;	//��ԍŏ��̏�����̉摜
			}
		}
	}
	else if (AllKeyState[KEY_INPUT_DOWN] != 0)	//�����L�[��������Ă�����
	{
		if (Myplayer.NowHandleCnt < Myplayer.NowHandleCntMAX)
		{
			Myplayer.NowHandleCnt++;
		}
		else
		{
			Myplayer.NowHandleCnt = 0;

			if (Myplayer.NowHandleNum >= 0 && Myplayer.NowHandleNum < 2)
			{
				Myplayer.NowHandleNum++;	//���̉������̉摜
			}
			else
			{
				Myplayer.NowHandleNum = 0;	//��ԍŏ��̉������̉摜
			}
		}
	}

	if (DEBUG_MODE)
	{
		DrawFormatStringToHandle(0, 20, GetColor(255, 255, 255), FontDefault, "�v���C���[������������X�F%04d", player.MoveDistX);	//������������\��
		DrawFormatStringToHandle(0, 40, GetColor(255, 255, 255), FontDefault, "�v���C���[������������Y�F%04d", player.MoveDistY);	//������������\��
		DrawFormatStringToHandle(0, 60, GetColor(255, 255, 255), FontDefault, "�v���C���[X�F%04d", player.X);						//�v���C���[��X�ʒu��\��
		DrawFormatStringToHandle(0, 80, GetColor(255, 255, 255), FontDefault, "�v���C���[Y�F%04d", player.Y);						//�v���C���[��Y�ʒu��\��
	}
	return;
}

//########## �}�b�v��`�悷��֐� ##########
VOID MY_PLAY_MAP_DRAW(MAPDATA mapdata)
{
	//�X�N���[������}�b�v��`��
	for (int tate = 0; tate < GAME_MAP_TATE; tate++)
	{
		for (int yoko = 0; yoko < GAME_MAP_YOKO; yoko++)
		{
			if ((yoko + 1) * GAME_MAP_YOKO_SIZE - ScrollCntYoko >= 0 &&
				(yoko + 0) * GAME_MAP_YOKO_SIZE - ScrollCntYoko <= GAME_WIDTH &&
				(tate + 1) * GAME_MAP_TATE_SIZE - ScrollCntTate >= 0 &&
				(tate + 0) * GAME_MAP_TATE_SIZE - ScrollCntTate <= GAME_HEIGHT
				)	//��ʂɎʂ��Ă���Ȃ�΂Ȃ��
			{
				DrawGraph(
					yoko * GAME_MAP_YOKO_SIZE - ScrollCntYoko,				//�ʒu����X�N���[���ʂ�����
					tate * GAME_MAP_TATE_SIZE - ScrollCntTate,				//�ʒu����X�N���[���ʂ�����
					mapdata.Handle[mapdata.data[tate][yoko]], TRUE);		//�}�b�v���X�N���[�����Ȃ���`��
			}

		}
	}

}

//########## �}�b�v�̓����蔻���`�悷��֐� old ##########
VOID MY_PLAY_MAP_DRAW_ATARI(MAPDATA *map_ue, MAPDATA *map_naka, MAPDATA *map_sita)
{
	//�X�N���[������}�b�v��`��
	for (int tate = 0; tate < GAME_MAP_TATE; tate++)
	{
		for (int yoko = 0; yoko < GAME_MAP_YOKO; yoko++)
		{
			if ((yoko + 1) * GAME_MAP_YOKO_SIZE - ScrollCntYoko >= 0 &&
				(yoko + 0) * GAME_MAP_YOKO_SIZE - ScrollCntYoko <= GAME_WIDTH &&
				(tate + 1) * GAME_MAP_TATE_SIZE - ScrollCntTate >= 0 &&
				(tate + 0) * GAME_MAP_TATE_SIZE - ScrollCntTate <= GAME_HEIGHT
				)	//��ʂɎʂ��Ă���Ȃ��
			{
				if (DEBUG_MODE)
				{
					DrawBox(
						map_naka->rect_OK[tate][yoko].left,
						map_naka->rect_OK[tate][yoko].top,
						map_naka->rect_OK[tate][yoko].right,
						map_naka->rect_OK[tate][yoko].bottom,
						GetColor(116, 232, 232), FALSE);	//�ʉ߂ł���}�b�v

					DrawBox(
						map_naka->rect_NG[tate][yoko].left,
						map_naka->rect_NG[tate][yoko].top,
						map_naka->rect_NG[tate][yoko].right,
						map_naka->rect_NG[tate][yoko].bottom,
						GetColor(232, 135, 166), FALSE);	//�ʉ߂ł��Ȃ��}�b�v

					DrawBox(
						map_sita->rect_BT[tate][yoko].left,
						map_sita->rect_BT[tate][yoko].top,
						map_sita->rect_BT[tate][yoko].right,
						map_sita->rect_BT[tate][yoko].bottom,
						GetColor(232, 232, 116), FALSE);	//�퓬����}�b�v
				}
			}

			//�}�b�v�̓����蔻����X�N���[��������

			/*�R�����g�A�E�g�����Ȃ��ŁI�ۗ����I
			map_ue->rect_OK[tate][yoko].left = map_ue->rect_OK_First[tate][yoko].left - ScrollCntYoko;
			map_ue->rect_OK[tate][yoko].right = map_ue->rect_OK_First[tate][yoko].right - ScrollCntYoko;
			map_ue->rect_OK[tate][yoko].top = map_ue->rect_OK_First[tate][yoko].top - ScrollCntTate;
			map_ue->rect_OK[tate][yoko].bottom = map_ue->rect_OK_First[tate][yoko].bottom - ScrollCntTate;

			map_ue->rect_NG[tate][yoko].left = map_ue->rect_NG_First[tate][yoko].left - ScrollCntYoko;
			map_ue->rect_NG[tate][yoko].right = map_ue->rect_NG_First[tate][yoko].right - ScrollCntYoko;
			map_ue->rect_NG[tate][yoko].top = map_ue->rect_NG_First[tate][yoko].top - ScrollCntTate;
			map_ue->rect_NG[tate][yoko].bottom = map_ue->rect_NG_First[tate][yoko].bottom - ScrollCntTate;

			map_ue->rect_BT[tate][yoko].left = map_ue->rect_BT_First[tate][yoko].left - ScrollCntYoko;
			map_ue->rect_BT[tate][yoko].right = map_ue->rect_BT_First[tate][yoko].right - ScrollCntYoko;
			map_ue->rect_BT[tate][yoko].top = map_ue->rect_BT_First[tate][yoko].top - ScrollCntTate;
			map_ue->rect_BT[tate][yoko].bottom = map_ue->rect_BT_First[tate][yoko].bottom - ScrollCntTate;
			*/

			map_naka->rect_OK[tate][yoko].left = map_naka->rect_OK_First[tate][yoko].left - ScrollCntYoko;
			map_naka->rect_OK[tate][yoko].right = map_naka->rect_OK_First[tate][yoko].right - ScrollCntYoko;
			map_naka->rect_OK[tate][yoko].top = map_naka->rect_OK_First[tate][yoko].top - ScrollCntTate;
			map_naka->rect_OK[tate][yoko].bottom = map_naka->rect_OK_First[tate][yoko].bottom - ScrollCntTate;

			map_naka->rect_NG[tate][yoko].left = map_naka->rect_NG_First[tate][yoko].left - ScrollCntYoko;
			map_naka->rect_NG[tate][yoko].right = map_naka->rect_NG_First[tate][yoko].right - ScrollCntYoko;
			map_naka->rect_NG[tate][yoko].top = map_naka->rect_NG_First[tate][yoko].top - ScrollCntTate;
			map_naka->rect_NG[tate][yoko].bottom = map_naka->rect_NG_First[tate][yoko].bottom - ScrollCntTate;

			map_naka->rect_CL[tate][yoko].left = map_naka->rect_CL_First[tate][yoko].left - ScrollCntYoko;
			map_naka->rect_CL[tate][yoko].right = map_naka->rect_CL_First[tate][yoko].right - ScrollCntYoko;
			map_naka->rect_CL[tate][yoko].top = map_naka->rect_CL_First[tate][yoko].top - ScrollCntTate;
			map_naka->rect_CL[tate][yoko].bottom = map_naka->rect_CL_First[tate][yoko].bottom - ScrollCntTate;


			/*�R�����g�A�E�g�����Ȃ��ŁI�ۗ����I
			map_naka->rect_BT[tate][yoko].left = map_naka->rect_BT_First[tate][yoko].left - ScrollCntYoko;
			map_naka->rect_BT[tate][yoko].right = map_naka->rect_BT_First[tate][yoko].right - ScrollCntYoko;
			map_naka->rect_BT[tate][yoko].top = map_naka->rect_BT_First[tate][yoko].top - ScrollCntTate;
			map_naka->rect_BT[tate][yoko].bottom = map_naka->rect_BT_First[tate][yoko].bottom - ScrollCntTate;
			*/

			/*�R�����g�A�E�g�����Ȃ��ŁI�ۗ����I
			map_sita->rect_OK[tate][yoko].left = map_sita->rect_OK_First[tate][yoko].left - ScrollCntYoko;
			map_sita->rect_OK[tate][yoko].right = map_sita->rect_OK_First[tate][yoko].right - ScrollCntYoko;
			map_sita->rect_OK[tate][yoko].top = map_sita->rect_OK_First[tate][yoko].top - ScrollCntTate;
			map_sita->rect_OK[tate][yoko].bottom = map_sita->rect_OK_First[tate][yoko].bottom - ScrollCntTate;

			map_sita->rect_NG[tate][yoko].left = map_sita->rect_NG_First[tate][yoko].left - ScrollCntYoko;
			map_sita->rect_NG[tate][yoko].right = map_sita->rect_NG_First[tate][yoko].right - ScrollCntYoko;
			map_sita->rect_NG[tate][yoko].top = map_sita->rect_NG_First[tate][yoko].top - ScrollCntTate;
			map_sita->rect_NG[tate][yoko].bottom = map_sita->rect_NG_First[tate][yoko].bottom - ScrollCntTate;
			*/
			map_sita->rect_BT[tate][yoko].left = map_sita->rect_BT_First[tate][yoko].left - ScrollCntYoko;
			map_sita->rect_BT[tate][yoko].right = map_sita->rect_BT_First[tate][yoko].right - ScrollCntYoko;
			map_sita->rect_BT[tate][yoko].top = map_sita->rect_BT_First[tate][yoko].top - ScrollCntTate;
			map_sita->rect_BT[tate][yoko].bottom = map_sita->rect_BT_First[tate][yoko].bottom - ScrollCntTate;


		}
	}
}

//###########�}�b�v�̓����蔻���`�悷��֐��@new!!#################################################
VOID PLAY_MAP_DRAW_ATARI(MAPDATA *map_sin)
{
	//�X�N���[������}�b�v��`��
	for (int tate = 0; tate < GAME_MAP_TATE; tate++)
	{
		for (int yoko = 0; yoko < GAME_MAP_YOKO; yoko++)
		{
			if ((yoko + 1) * GAME_MAP_YOKO_SIZE - ScrollCntYoko >= 0 &&
				(yoko + 0) * GAME_MAP_YOKO_SIZE - ScrollCntYoko <= GAME_WIDTH &&
				(tate + 1) * GAME_MAP_TATE_SIZE - ScrollCntTate >= 0 &&
				(tate + 0) * GAME_MAP_TATE_SIZE - ScrollCntTate <= GAME_HEIGHT
				)	//��ʂɎʂ��Ă���Ȃ��
			{
				if (DEBUG_MODE)
				{
					//DrawBox(
					//	map_naka->rect_OK[tate][yoko].left,
					//	map_naka->rect_OK[tate][yoko].top,
					//	map_naka->rect_OK[tate][yoko].right,
					//	map_naka->rect_OK[tate][yoko].bottom,
					//	GetColor(116, 232, 232), FALSE);	//�ʉ߂ł���}�b�v

					//DrawBox(
					//	map_naka->rect_NG[tate][yoko].left,
					//	map_naka->rect_NG[tate][yoko].top,
					//	map_naka->rect_NG[tate][yoko].right,
					//	map_naka->rect_NG[tate][yoko].bottom,
					//	GetColor(232, 135, 166), FALSE);	//�ʉ߂ł��Ȃ��}�b�v

					//DrawBox(
					//	map_sita->rect_BT[tate][yoko].left,
					//	map_sita->rect_BT[tate][yoko].top,
					//	map_sita->rect_BT[tate][yoko].right,
					//	map_sita->rect_BT[tate][yoko].bottom,
					//	GetColor(232, 232, 116), FALSE);	//�퓬����}�b�v

					DrawBox(
						map_sin->rect_OK[tate][yoko].left,
						map_sin->rect_OK[tate][yoko].top,
						map_sin->rect_OK[tate][yoko].right,
						map_sin->rect_OK[tate][yoko].bottom,
						GetColor(116, 232, 232), FALSE);	//�ʉ߂ł���}�b�v

				}
			}

			//�}�b�v�̓����蔻����X�N���[��������

			/*�R�����g�A�E�g�����Ȃ��ŁI�ۗ����I
			map_ue->rect_OK[tate][yoko].left = map_ue->rect_OK_First[tate][yoko].left - ScrollCntYoko;
			map_ue->rect_OK[tate][yoko].right = map_ue->rect_OK_First[tate][yoko].right - ScrollCntYoko;
			map_ue->rect_OK[tate][yoko].top = map_ue->rect_OK_First[tate][yoko].top - ScrollCntTate;
			map_ue->rect_OK[tate][yoko].bottom = map_ue->rect_OK_First[tate][yoko].bottom - ScrollCntTate;

			map_ue->rect_NG[tate][yoko].left = map_ue->rect_NG_First[tate][yoko].left - ScrollCntYoko;
			map_ue->rect_NG[tate][yoko].right = map_ue->rect_NG_First[tate][yoko].right - ScrollCntYoko;
			map_ue->rect_NG[tate][yoko].top = map_ue->rect_NG_First[tate][yoko].top - ScrollCntTate;
			map_ue->rect_NG[tate][yoko].bottom = map_ue->rect_NG_First[tate][yoko].bottom - ScrollCntTate;

			map_ue->rect_BT[tate][yoko].left = map_ue->rect_BT_First[tate][yoko].left - ScrollCntYoko;
			map_ue->rect_BT[tate][yoko].right = map_ue->rect_BT_First[tate][yoko].right - ScrollCntYoko;
			map_ue->rect_BT[tate][yoko].top = map_ue->rect_BT_First[tate][yoko].top - ScrollCntTate;
			map_ue->rect_BT[tate][yoko].bottom = map_ue->rect_BT_First[tate][yoko].bottom - ScrollCntTate;
			*/

			map_sin->rect_OK[tate][yoko].left = map_sin->rect_OK_First[tate][yoko].left - ScrollCntYoko;
			map_sin->rect_OK[tate][yoko].right = map_sin->rect_OK_First[tate][yoko].right - ScrollCntYoko;
			map_sin->rect_OK[tate][yoko].top = map_sin->rect_OK_First[tate][yoko].top - ScrollCntTate;
			map_sin->rect_OK[tate][yoko].bottom = map_sin->rect_OK_First[tate][yoko].bottom - ScrollCntTate;

			map_sin->rect_NG[tate][yoko].left = map_sin->rect_NG_First[tate][yoko].left - ScrollCntYoko;
			map_sin->rect_NG[tate][yoko].right = map_sin->rect_NG_First[tate][yoko].right - ScrollCntYoko;
			map_sin->rect_NG[tate][yoko].top = map_sin->rect_NG_First[tate][yoko].top - ScrollCntTate;
			map_sin->rect_NG[tate][yoko].bottom = map_sin->rect_NG_First[tate][yoko].bottom - ScrollCntTate;

			map_sin->rect_CL[tate][yoko].left = map_sin->rect_CL_First[tate][yoko].left - ScrollCntYoko;
			map_sin->rect_CL[tate][yoko].right = map_sin->rect_CL_First[tate][yoko].right - ScrollCntYoko;
			map_sin->rect_CL[tate][yoko].top = map_sin->rect_CL_First[tate][yoko].top - ScrollCntTate;
			map_sin->rect_CL[tate][yoko].bottom = map_sin->rect_CL_First[tate][yoko].bottom - ScrollCntTate;


			/*�R�����g�A�E�g�����Ȃ��ŁI�ۗ����I
			map_sin->rect_BT[tate][yoko].left = map_sin->rect_BT_First[tate][yoko].left - ScrollCntYoko;
			map_sin->rect_BT[tate][yoko].right = map_sin->rect_BT_First[tate][yoko].right - ScrollCntYoko;
			map_sin->rect_BT[tate][yoko].top = map_sin->rect_BT_First[tate][yoko].top - ScrollCntTate;
			map_sin->rect_BT[tate][yoko].bottom = map_sin->rect_BT_First[tate][yoko].bottom - ScrollCntTate;
			*/

			/*�R�����g�A�E�g�����Ȃ��ŁI�ۗ����I
			map_sita->rect_OK[tate][yoko].left = map_sita->rect_OK_First[tate][yoko].left - ScrollCntYoko;
			map_sita->rect_OK[tate][yoko].right = map_sita->rect_OK_First[tate][yoko].right - ScrollCntYoko;
			map_sita->rect_OK[tate][yoko].top = map_sita->rect_OK_First[tate][yoko].top - ScrollCntTate;
			map_sita->rect_OK[tate][yoko].bottom = map_sita->rect_OK_First[tate][yoko].bottom - ScrollCntTate;

			map_sita->rect_NG[tate][yoko].left = map_sita->rect_NG_First[tate][yoko].left - ScrollCntYoko;
			map_sita->rect_NG[tate][yoko].right = map_sita->rect_NG_First[tate][yoko].right - ScrollCntYoko;
			map_sita->rect_NG[tate][yoko].top = map_sita->rect_NG_First[tate][yoko].top - ScrollCntTate;
			map_sita->rect_NG[tate][yoko].bottom = map_sita->rect_NG_First[tate][yoko].bottom - ScrollCntTate;
			*/
			/*map_sita->rect_BT[tate][yoko].left = map_sita->rect_BT_First[tate][yoko].left - ScrollCntYoko;
			map_sita->rect_BT[tate][yoko].right = map_sita->rect_BT_First[tate][yoko].right - ScrollCntYoko;
			map_sita->rect_BT[tate][yoko].top = map_sita->rect_BT_First[tate][yoko].top - ScrollCntTate;
			map_sita->rect_BT[tate][yoko].bottom = map_sita->rect_BT_First[tate][yoko].bottom - ScrollCntTate;*/


		}
	}
}

//########## �V�[�����ړ�����Ƃ��̉��o������֐� ##########
BOOL MY_GAME_SCENE_MOVE(int beforeScene)
{
	//BGM���~�߂�
	if (CheckSoundMem(MUSIC_MY_BGM_TITLE.Handle) != 0)
	{
		StopSoundMem(MUSIC_MY_BGM_TITLE.Handle);
	}
	if (CheckSoundMem(MUSIC_MY_BGM_PLAY.Handle) != 0)
	{
		StopSoundMem(MUSIC_MY_BGM_PLAY.Handle);
	}
	if (CheckSoundMem(MUSIC_MY_BGM_BATTLE.Handle) != 0)
	{
		StopSoundMem(MUSIC_MY_BGM_BATTLE.Handle);
	}
	if (CheckSoundMem(MUSIC_MY_BGM_BOSS.Handle) != 0)
	{
		StopSoundMem(MUSIC_MY_BGM_BOSS.Handle);
	}
	if (CheckSoundMem(MUSIC_MY_BGM_END.Handle) != 0)
	{
		StopSoundMem(MUSIC_MY_BGM_END.Handle);
	}

	switch (sceneMove.kind)	//���o���ʂ̎��
	{
	case (int)GAME_MAE_EFFECT_FADEIN:	//�t�F�[�h�C��

		if (sceneMove.DrawCnt < sceneMove.DrawCntMax)
		{
			sceneMove.DrawCnt++;
		}
		else
		{
			return TRUE;	//��ʈړ�
		}

		switch (beforeScene)
		{
		case (int)GAME_SCENE_TITLE:	//�^�C�g�����

			MY_GAME_BACK_DRAW();

			MY_GAME_TITLE_DRAW();	//�^�C�g����ʕ`��

			break;

		case (int)GAME_SCENE_PLAY:	//�v���C���

			MY_GAME_PLAY_DRAW();	//�v���C��ʕ`��

			break;

		case (int)GAME_SCENE_BATTLE:	//�퓬���

			MY_GAME_BATTLE_DRAW();		//�퓬��ʕ`��

			break;

		case (int)GAME_SCENE_MOVE_SCENE:	//�V�[���ړ����

			break;

		case (int)GAME_SCENE_END:	//�G���h���

			MY_GAME_END_DRAW();		//�G���h���

			break;

		default:

			break;

		}

		sceneMove.ToukaPercent = sceneMove.DrawCnt / (double)sceneMove.DrawCntMax;	//���߁������߂�
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, sceneMove.ToukaPercent * 255);				//���߂�����
		DrawBox(0, 0, GAME_WIDTH, GAME_HEIGHT, GetColor(0, 0, 0), TRUE);					//�^���Âȉ�ʂɂ���
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);											//���߂���߂�

		break;

	case (int)GAME_MAE_EFFECT_FADEOUT:	//�t�F�[�h�A�E�g

		if (sceneMove.DrawCnt < sceneMove.DrawCntMax)
		{
			sceneMove.DrawCnt++;
		}
		else
		{
			return TRUE;	//��ʈړ�
		}

		switch (beforeScene)
		{
		case (int)GAME_SCENE_TITLE:	//�^�C�g�����

			MY_GAME_TITLE_DRAW();	//�^�C�g����ʕ`��

			break;

		case (int)GAME_SCENE_PLAY:	//�v���C���

			MY_GAME_PLAY_DRAW();	//�v���C��ʕ`��

			break;

		case (int)GAME_SCENE_BATTLE:	//�퓬���

			MY_GAME_BATTLE_DRAW();		//�퓬��ʕ`��

			break;

		case (int)GAME_SCENE_MOVE_SCENE:	//�V�[���ړ����

			break;

		case (int)GAME_SCENE_END:	//�G���h���

			MY_GAME_END_DRAW();		//�G���h���

			break;

		default:

			break;

		}

		sceneMove.ToukaPercent = (sceneMove.DrawCntMax - sceneMove.DrawCnt) / (double)sceneMove.DrawCntMax;		//���߁������߂�
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, sceneMove.ToukaPercent * 255);		//���߂�����
		DrawBox(0, 0, GAME_WIDTH, GAME_HEIGHT, GetColor(0, 0, 0), TRUE);			//�^���Âȉ�ʂɂ���
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);									//���߂���߂�

		break;

	default:
		break;
	}

	DrawStringToHandle(0, 0, "�V�[���ړ����", GetColor(255, 255, 255), FontDefault);

	return FALSE;
}

//########## �퓬��ʂ̊֐� ##########
VOID MY_GAME_BATTLE(VOID)
{
	if (Myplayer.eneType != (int)GAME_ENETYPE_BOSS)	//�{�X�ȊO
	{
		//BGM������Ă��Ȃ��Ƃ�
		if (CheckSoundMem(MUSIC_MY_BGM_BATTLE.Handle) == 0)
		{
			ChangeVolumeSoundMem(255 * 50 / 100, MUSIC_MY_BGM_BATTLE.Handle);	//BGM�̉��ʂ�50���ɂ���
			PlaySoundMem(MUSIC_MY_BGM_BATTLE.Handle, DX_PLAYTYPE_LOOP);			//BGM�𗬂�
		}
	}
	else if (Myplayer.eneType == (int)GAME_ENETYPE_BOSS)	//�{�X
	{
		//BGM������Ă��Ȃ��Ƃ�
		if (CheckSoundMem(MUSIC_MY_BGM_BOSS.Handle) == 0)
		{
			ChangeVolumeSoundMem(255 * 50 / 100, MUSIC_MY_BGM_BOSS.Handle);	//BGM�̉��ʂ�50���ɂ���
			PlaySoundMem(MUSIC_MY_BGM_BOSS.Handle, DX_PLAYTYPE_LOOP);			//BGM�𗬂�
		}
	}


	if (Myplayer.battle_turn == (int)GAME_TURN_MY)	//�����̃^�[���̂Ƃ�
	{
		if (AllKeyState[KEY_INPUT_LEFT] != 0)	//���L�[��������Ă�����
		{
			if (Myplayer.IsActMsgStart == FALSE)	//�s�����Ă��Ȃ��Ƃ�
			{
				if (Myplayer.IsActKeyDown_left == FALSE)	//���������đI���͂ł��Ȃ�
				{
					if (Myplayer.act_kind <= (int)GAME_ACT_KIND_ATK)
					{
						Myplayer.act_kind = (int)GAME_ACT_KIND_ESC;	//�Ō�̍s���֖߂�
					}
					else
					{
						Myplayer.act_kind--;	//�O�̍s����I��
					}
					PlaySoundMem(MUSIC_MY_SE_BATTLE_SELECT.Handle, DX_PLAYTYPE_BACK);
				}

				Myplayer.IsActKeyDown_left = TRUE;
			}
		}
		else
		{
			Myplayer.IsActKeyDown_left = FALSE;
		}

		if (AllKeyState[KEY_INPUT_RIGHT] != 0)	//�E�L�[��������Ă�����
		{
			if (Myplayer.IsActMsgStart == FALSE)	//�s�����Ă��Ȃ��Ƃ�
			{
				if (Myplayer.IsActKeyDown_right == FALSE)	//���������đI���͂ł��Ȃ�
				{
					if (Myplayer.act_kind >= (int)GAME_ACT_KIND_ESC)
					{
						Myplayer.act_kind = (int)GAME_ACT_KIND_ATK;	//�ŏ��̍s���֖߂�
					}
					else
					{
						Myplayer.act_kind++;	//���̍s����I��
					}
					PlaySoundMem(MUSIC_MY_SE_BATTLE_SELECT.Handle, DX_PLAYTYPE_BACK);
				}

				Myplayer.IsActKeyDown_right = TRUE;
			}
		}
		else
		{
			Myplayer.IsActKeyDown_right = FALSE;
		}

		if (AllKeyState[KEY_INPUT_RETURN] != 0)	//�G���^�[�L�[��������Ă����Ƃ�
		{
			if (Myplayer.IsActMsgStart == FALSE)	//�s�����Ă��Ȃ��Ƃ�
			{
				switch (Myplayer.act_kind)	//�s�������肷��
				{
				case (int)GAME_ACT_KIND_ATK:	//�U������Ƃ�

					PlaySoundMem(MUSIC_MY_SE_BATTLE_ATK.Handle, DX_PLAYTYPE_BACK);

					for (int cnt = 0; cnt < Myplayer.eneBattleCnt; cnt++)	//�G�̐������U��
					{
						if (eneBattle[cnt].IsAlive == TRUE)	//�G���킦��Ƃ�
						{
							Myplayer.damageCalc = Myplayer.ATK - eneBattle[cnt].DEF;	//�v���C���[�̍U���� - �G�̖h��� ���_���[�W

							if (Myplayer.damageCalc <= 0) { Myplayer.damageCalc = 0; }

							eneBattle[cnt].HP -= Myplayer.damageCalc;	//HP���ւ炷

							if (eneBattle[cnt].HP <= 0) { eneBattle[cnt].IsAlive = FALSE; };	//�G�͐퓬�s�\
						}
					}

					break;
				case (int)GAME_ACT_KIND_ITEM:	//�A�C�e�����g�p����Ƃ�

					PlaySoundMem(MUSIC_MY_SE_BATTLE_ITEM.Handle, DX_PLAYTYPE_BACK);

					if (Myplayer.HP + Myplayer.HP_MAX / 4 < Myplayer.HP_MAX)	//HP�̍ő�l�𒴂��Ȃ�
					{
						Myplayer.HP += Myplayer.HP_MAX / 4;	//HP���ő�HP��4���̂P�񕜂���
					}
					else
					{
						Myplayer.HP = Myplayer.HP_MAX;
					}

					break;
				case (int)GAME_ACT_KIND_ESC:	//������Ƃ�

					if (Myplayer.eneType != (int)GAME_ENETYPE_BOSS)	//�{�X�ȊO�͓�������
					{
						if (GetRand(99) <= 49)	//50%�œ������
						{
							PlaySoundMem(MUSIC_MY_SE_BATTLE_ESC.Handle, DX_PLAYTYPE_BACK);
							Myplayer.IsEsc = TRUE;		//��������
						}
						else
						{
							Myplayer.IsEsc = FALSE;		//�������Ȃ�
						}
					}
					else if (Myplayer.eneType == (int)GAME_ENETYPE_BOSS)	//�{�X�͓������Ȃ�
					{
						Myplayer.IsEsc = FALSE;			//�������Ȃ�
					}
					break;

				default:
					break;
				}

				Myplayer.NowActMsgCnt = 0;			//�s�����b�Z�[�W�J�E���g
				Myplayer.IsActMsgStart = TRUE;		//�s�����b�Z�[�W�J�n
				Myplayer.IsActMsgEnd = FALSE;		//�s�����b�Z�[�W�I��
			}
		}
	}
	else if (Myplayer.battle_turn == (int)GAME_TURN_ENEMY)	//�G�̃^�[���̂Ƃ�
	{
		if (Myplayer.IsActMsgStart == FALSE)
		{
			PlaySoundMem(MUSIC_MY_SE_BATTLE_ATK.Handle, DX_PLAYTYPE_BACK);

			for (int cnt = 0; cnt < Myplayer.eneBattleCnt; cnt++)	//�G�̐������U��
			{
				if (eneBattle[cnt].IsAlive == TRUE)	//�G���킦��Ƃ�
				{
					eneBattle[cnt].damageCalc = eneBattle[cnt].ATK - Myplayer.DEF;	//�G�̍U���� - �v���C���[�̖h��� ���_���[�W

					if (eneBattle[cnt].damageCalc <= 0)		//�_���[�W��^�����Ȃ�
					{
						eneBattle[cnt].damageCalc = 0;
					}

					Myplayer.HP -= eneBattle[cnt].damageCalc;	//HP���ւ炷

					if (Myplayer.HP <= 0)	//�Q�[���I�[�o
					{
						Myplayer.IsAlive = FALSE;

						Myplayer.gameEndKind = (int)GAME_END_KIND_OVER;
						Myplayer.X = GAME_WIDTH / 2 - Myplayer.C_Width;
						Myplayer.Y = GAME_HEIGHT / 2 - Myplayer.C_Height;

						//���͗D�����̂ŃX�e�[�^�X�������������Ă����܂��傤�B
						Myplayer.EndLV = Myplayer.LV;
						Myplayer.EndHP = Myplayer.HP_MAX;
						Myplayer.EndATK = Myplayer.ATK_MAX;
						Myplayer.EndDEF = Myplayer.DEF_MAX;

						EndConCnt = 0;	//�G���h��ʂ̃R���e�j���[�J�E���g������
						EndEndCnt = 0;	//�G���h��ʂ̃^�C�g���J�E���g������
						break;
					}
				}
			}

			Myplayer.NowActMsgCnt = 0;		//�s�����b�Z�[�W�J�E���g
			Myplayer.IsActMsgStart = TRUE;	//�s�����b�Z�[�W�J�n
			Myplayer.IsActMsgEnd = FALSE;	//�s�����b�Z�[�W�I��
		}
	}

	MY_GAME_BATTLE_DRAW();	//�퓬��ʕ`��̊֐�

	if (Myplayer.IsActMsgEnd == TRUE)	//�s�����b�Z�[�W�I��
	{
		BOOL IsMoveScene = FALSE;	//�V�[�����ړ�����Ƃ�

		if (Myplayer.act_kind == (int)GAME_ACT_KIND_ESC)
		{
			if (Myplayer.IsEsc == TRUE)	//�������Ƃ�
			{
				IsMoveScene = TRUE;	//�V�[�����ړ�����
			}
		}

		if (Myplayer.act_kind == (int)GAME_ACT_KIND_ATK)
		{
			int EneNoFightNum = 0;
			for (int cnt = 0; cnt < Myplayer.eneBattleCnt; cnt++)	//�G���S���|��Ă��邩�`�F�b�N
			{
				if (eneBattle[cnt].IsAlive == FALSE) { EneNoFightNum++; }
			}

			//�G���S���|�ꂽ�Ƃ�
			if (EneNoFightNum == Myplayer.eneBattleCnt)
			{
				//���x���A�b�v
				if (Myplayer.IsActLvupStart == FALSE)
				{
					PlaySoundMem(MUSIC_MY_SE_LEVELUP.Handle, DX_PLAYTYPE_BACK);

					Myplayer.LV++;
					Myplayer.HP_MAX += GAME_PLAYER_HP_LVUP;
					Myplayer.ATK_MAX += GAME_PLAYER_ATK_LVUP;
					Myplayer.DEF_MAX += GAME_PLAYER_DEF_LVUP;

					Myplayer.HP = Myplayer.HP_MAX;
					Myplayer.ATK = Myplayer.ATK_MAX;
					Myplayer.DEF = Myplayer.DEF_MAX;

					Myplayer.IsActLvupStart = TRUE;
					Myplayer.act_kind = (int)GAME_ACT_KIND_LVUP;	//���x���A�b�v
					Myplayer.battle_turn = (int)GAME_TURN_MY;		//�����̃^�[���ɂ���
					Myplayer.IsActMsgStart = TRUE;					//���b�Z�[�W�J�n
				}

				if (Myplayer.eneType == (int)GAME_ENETYPE_BOSS)	//�{�X��|�����Ƃ�
				{

					Myplayer.gameEndKind = (int)GAME_END_KIND_CLEAR;
					Myplayer.X = GAME_WIDTH / 2 - Myplayer.C_Width;
					Myplayer.Y = GAME_HEIGHT / 2 - Myplayer.C_Height;

					GameSceneNow = (int)GAME_SCENE_END;	//�I����ʂֈړ�
				}

			}

		}

		if (Myplayer.act_kind == (int)GAME_ACT_KIND_LVUP)
		{
			if (Myplayer.IsActLvupEnd == TRUE)
			{
				IsMoveScene = TRUE;	//�V�[�����ړ�����
			}
		}

		if (IsMoveScene == FALSE)		//�V�[�����ړ����Ȃ��Ƃ�
		{
			if (Myplayer.IsActLvupStart == FALSE && Myplayer.IsAlive == TRUE)	//���x���A�b�v���Ă��Ȃ��Ƃ� ���� �v���C���[���|��Ă��Ȃ��Ƃ�
			{
				//�^�[���𑊎�ɂ���
				if (Myplayer.battle_turn == (int)GAME_TURN_MY)
				{
					Myplayer.battle_turn = (int)GAME_TURN_ENEMY;
				}
				else if (Myplayer.battle_turn == (int)GAME_TURN_ENEMY)
				{
					Myplayer.battle_turn = (int)GAME_TURN_MY;
				}

				Myplayer.IsActMsgStart = FALSE;	//�s�����b�Z�[�W�J�n
				Myplayer.IsActMsgEnd = FALSE;	//�s�����b�Z�[�W�I��
			}
		}
		else if (IsMoveScene == TRUE)	//�V�[�����ړ�����Ƃ�
		{
			GameSceneNow = (int)GAME_SCENE_PLAY;	//�v���C��ʂֈړ�
		}

		if (Myplayer.IsAlive == FALSE)	//�v���C���[���|�ꂽ��
		{
			GameSceneNow = (int)GAME_SCENE_END;	//�I����ʂֈړ�
		}
	}

	return;
}

// ########## �퓬��ʕ`��̊֐� ##########
VOID MY_GAME_BATTLE_DRAW(VOID)
{
	//�퓬�w�i��`��
	switch (Myplayer.eneType)
	{
	case (int)GAME_ENETYPE_GRASS:
		DrawGraph(0, 0, image_grass.Handle[0], TRUE);
		break;
	case (int)GAME_ENETYPE_RIVER:
		DrawGraph(0, 0, image_river.Handle[0], TRUE);
		break;
	case (int)GAME_ENETYPE_KUSA:
		DrawGraph(0, 0, image_grass.Handle[0], TRUE);
		break;
	case (int)GAME_ENETYPE_MAOU:
		DrawGraph(0, 0, image_maou.Handle[0], TRUE);
		break;
	case (int)GAME_ENETYPE_BOSS:
		DrawGraph(0, 0, image_boss.Handle[0], TRUE);
		break;
	default:
		break;
	}

	//�����̃X�e�[�^�X��\������ꏊ
	DrawBox(
		Myplayer.rect_st.left,
		Myplayer.rect_st.top,
		Myplayer.rect_st.right,
		Myplayer.rect_st.bottom,
		GetColor(0, 0, 0),
		TRUE);

	DrawBox(
		Myplayer.rect_st.left + 4,
		Myplayer.rect_st.top + 4,
		Myplayer.rect_st.right - 4,
		Myplayer.rect_st.bottom - 4,
		GetColor(255, 255, 255),
		TRUE);

	int MyHpColor;	//HP�̐F�����߂�
	if (Myplayer.HP > Myplayer.HP_MAX / 2) { MyHpColor = GetColor(0, 255, 0); }
	else if (Myplayer.HP > Myplayer.HP_MAX / 4) { MyHpColor = GetColor(255, 255, 0); }
	else { MyHpColor = GetColor(255, 0, 0); }

	if (Myplayer.HP > 0)	//HP������Ƃ�
	{
		//HP���l�p�ŕ\������
		DrawBox(
			Myplayer.rect_st.left + 4,
			Myplayer.rect_st.top + 18 * 2 + 4,
			Myplayer.rect_st.left + 4 + (GAME_BATTLE_MY_ST_WIDTH *  Myplayer.HP / Myplayer.HP_MAX) - 8,
			Myplayer.rect_st.top + 18 * 3,
			MyHpColor, TRUE);
	}

	//�����̃X�e�[�^�X��\������
	DrawFormatStringToHandle(Myplayer.rect_st.left, Myplayer.rect_st.top + 6, GetColor(0, 0, 0), FontDefault, "�@%s", Myplayer.name);
	DrawFormatStringToHandle(Myplayer.rect_st.left, Myplayer.rect_st.top + 18 * 1 + 4, GetColor(0, 0, 0), FontDefault, "�@�@�k�@�u�F%03d", Myplayer.LV);
	DrawFormatStringToHandle(Myplayer.rect_st.left, Myplayer.rect_st.top + 18 * 2 + 4, GetColor(0, 0, 0), FontDefault, "�@�@�g�@�o�F%03d�^%03d", Myplayer.HP, Myplayer.HP_MAX);
	DrawFormatStringToHandle(Myplayer.rect_st.left, Myplayer.rect_st.top + 18 * 3 + 4, GetColor(0, 0, 0), FontDefault, "�@�@�`�s�j�F%03d", Myplayer.ATK);
	DrawFormatStringToHandle(Myplayer.rect_st.left, Myplayer.rect_st.top + 18 * 4 + 4, GetColor(0, 0, 0), FontDefault, "�@�@�c�d�e�F%03d", Myplayer.DEF);

	//�����̍s����\������ꏊ
	DrawBox(
		Myplayer.rect_act.left,
		Myplayer.rect_act.top,
		Myplayer.rect_act.right,
		Myplayer.rect_act.bottom,
		GetColor(0, 0, 0),
		TRUE);

	DrawBox(
		Myplayer.rect_act.left + 4,
		Myplayer.rect_act.top + 4,
		Myplayer.rect_act.right - 4,
		Myplayer.rect_act.bottom - 4,
		GetColor(255, 255, 255),
		TRUE);


	if (Myplayer.battle_turn == (int)GAME_TURN_MY)	//�����̃^�[���̂Ƃ�
	{
		if (Myplayer.IsActMsgStart == FALSE)	//�����I��ł��Ȃ��Ƃ�
		{
			//�s����I�񂾂Ƃ��̐F
			int actColor[(int)GAME_ACT_KIND_MAX];			//�s������Ƃ��ɑI������Ă���F
			int selectColor = GetColor(255, 255, 0);		//�I�����ꂽ�F
			int NoselectColor = GetColor(255, 255, 255);	//�I������Ă��Ȃ��F

			switch (Myplayer.act_kind)	//�F��I��
			{
			case (int)GAME_ACT_KIND_NONE:
				actColor[(int)GAME_ACT_KIND_NONE] = selectColor;
				actColor[(int)GAME_ACT_KIND_ATK] = NoselectColor;
				actColor[(int)GAME_ACT_KIND_ITEM] = NoselectColor;
				actColor[(int)GAME_ACT_KIND_ESC] = NoselectColor;
				break;
			case (int)GAME_ACT_KIND_ATK:
				actColor[(int)GAME_ACT_KIND_NONE] = NoselectColor;
				actColor[(int)GAME_ACT_KIND_ATK] = selectColor;
				actColor[(int)GAME_ACT_KIND_ITEM] = NoselectColor;
				actColor[(int)GAME_ACT_KIND_ESC] = NoselectColor;
				break;
			case (int)GAME_ACT_KIND_ITEM:
				actColor[(int)GAME_ACT_KIND_NONE] = NoselectColor;
				actColor[(int)GAME_ACT_KIND_ATK] = NoselectColor;
				actColor[(int)GAME_ACT_KIND_ITEM] = selectColor;
				actColor[(int)GAME_ACT_KIND_ESC] = NoselectColor;
				break;
			case (int)GAME_ACT_KIND_ESC:
				actColor[(int)GAME_ACT_KIND_NONE] = NoselectColor;
				actColor[(int)GAME_ACT_KIND_ATK] = NoselectColor;
				actColor[(int)GAME_ACT_KIND_ITEM] = NoselectColor;
				actColor[(int)GAME_ACT_KIND_ESC] = selectColor;
				break;
			default:
				actColor[(int)GAME_ACT_KIND_NONE] = NoselectColor;
				actColor[(int)GAME_ACT_KIND_ATK] = NoselectColor;
				actColor[(int)GAME_ACT_KIND_ITEM] = NoselectColor;
				actColor[(int)GAME_ACT_KIND_ESC] = NoselectColor;
				break;
			}

			//�����̃R�}���h��\������ꏊ
			DrawBox(
				Myplayer.rect_act_atk.left,
				Myplayer.rect_act_atk.top,
				Myplayer.rect_act_atk.right,
				Myplayer.rect_act_atk.bottom,
				GetColor(0, 0, 0),
				TRUE);	//�U��

			DrawBox(
				Myplayer.rect_act_atk.left + 4,
				Myplayer.rect_act_atk.top + 4,
				Myplayer.rect_act_atk.right - 4,
				Myplayer.rect_act_atk.bottom - 4,
				actColor[(int)GAME_ACT_KIND_ATK],
				TRUE);	//�U��

			DrawStringToHandle(Myplayer.rect_act_atk.left + 4 + 4, Myplayer.rect_act_atk.top + 4 + 4, "���������I", GetColor(0, 0, 0), FontDefault);

			DrawBox(
				Myplayer.rect_act_item.left,
				Myplayer.rect_act_item.top,
				Myplayer.rect_act_item.right,
				Myplayer.rect_act_item.bottom,
				GetColor(0, 0, 0),
				TRUE);	//�A�C�e��

			DrawBox(
				Myplayer.rect_act_item.left + 4,
				Myplayer.rect_act_item.top + 4,
				Myplayer.rect_act_item.right - 4,
				Myplayer.rect_act_item.bottom - 4,
				actColor[(int)GAME_ACT_KIND_ITEM],
				TRUE);	//�A�C�e��

			DrawStringToHandle(Myplayer.rect_act_item.left + 4 + 4, Myplayer.rect_act_item.top + 4 + 4, "�A�C�e��", GetColor(0, 0, 0), FontDefault);

			DrawBox(
				Myplayer.rect_act_esc.left,
				Myplayer.rect_act_esc.top,
				Myplayer.rect_act_esc.right,
				Myplayer.rect_act_esc.bottom,
				GetColor(0, 0, 0),
				TRUE);	//������

			DrawBox(
				Myplayer.rect_act_esc.left + 4,
				Myplayer.rect_act_esc.top + 4,
				Myplayer.rect_act_esc.right - 4,
				Myplayer.rect_act_esc.bottom - 4,
				actColor[(int)GAME_ACT_KIND_ESC],
				TRUE);	//������

			DrawStringToHandle(Myplayer.rect_act_esc.left + 4 + 4, Myplayer.rect_act_esc.top + 4 + 4, "������", GetColor(0, 0, 0), FontDefault);

		}
		else if (Myplayer.IsActMsgStart == TRUE) //�s�����b�Z�[�W�\��
		{
			switch (Myplayer.act_kind)
			{
			case (int)GAME_ACT_KIND_NONE:
				break;
			case (int)GAME_ACT_KIND_ATK:

				DrawFormatStringToHandle(Myplayer.rect_act_atk.left, Myplayer.rect_act_atk.top, GetColor(0, 0, 0), FontDefault, "%s �� ���������I", Myplayer.name);

				for (int cnt = 0; cnt < Myplayer.eneBattleCnt; cnt++)	//�G�̐������U��
				{
					if (Myplayer.damageCalc > 0)	//�_���[�W��^������Ƃ�
					{
						DrawFormatStringToHandle(Myplayer.rect_act_atk.left, Myplayer.rect_act_atk.top + (cnt + 1) * 20, GetColor(0, 0, 0), FontDefault, "%s �� %d �� ���������I", eneBattle[cnt].name, Myplayer.ATK - eneBattle[cnt].DEF);
					}
					else
					{
						DrawFormatStringToHandle(Myplayer.rect_act_atk.left, Myplayer.rect_act_atk.top + (cnt + 1) * 20, GetColor(0, 0, 0), FontDefault, "%s �� �_���[�W �� �^�����Ȃ��I", eneBattle[cnt].name);
					}

					if (eneBattle[cnt].IsAlive == FALSE)	//�G�������ꂽ�Ƃ�
					{
						DrawFormatStringToHandle(Myplayer.rect_act_atk.left, Myplayer.rect_act_atk.top + (cnt + 2) * 20, GetColor(0, 0, 0), FontDefault, "%s �� �����ꂽ�I", eneBattle[cnt].name);
					}
				}

				break;
			case (int)GAME_ACT_KIND_ITEM:

				DrawFormatStringToHandle(Myplayer.rect_act_atk.left, Myplayer.rect_act_atk.top + 20 * 0, GetColor(0, 0, 0), FontDefault, "%s �� �ӂ����Ȗ� �������Ă����I", Myplayer.name);
				DrawFormatStringToHandle(Myplayer.rect_act_atk.left, Myplayer.rect_act_atk.top + 20 * 1, GetColor(0, 0, 0), FontDefault, "%s �� HP�� ���� �񕜂����I", Myplayer.name);

				break;
			case (int)GAME_ACT_KIND_LVUP:

				DrawFormatStringToHandle(Myplayer.rect_act_atk.left, Myplayer.rect_act_atk.top + 20 * 0, GetColor(0, 0, 0), FontDefault, "%s �� ���x�� �� �P�オ�����I", Myplayer.name);
				DrawFormatStringToHandle(Myplayer.rect_act_atk.left, Myplayer.rect_act_atk.top + 20 * 1, GetColor(0, 0, 0), FontDefault, "%s �� HP     �� %d �ɂȂ����I", Myplayer.name, Myplayer.HP_MAX);
				DrawFormatStringToHandle(Myplayer.rect_act_atk.left, Myplayer.rect_act_atk.top + 20 * 2, GetColor(0, 0, 0), FontDefault, "%s �� ATK    �� %d �ɂȂ����I", Myplayer.name, Myplayer.ATK_MAX);
				DrawFormatStringToHandle(Myplayer.rect_act_atk.left, Myplayer.rect_act_atk.top + 20 * 3, GetColor(0, 0, 0), FontDefault, "%s �� DEF    �� %d �ɂȂ����I", Myplayer.name, Myplayer.DEF_MAX);

				break;

			case (int)GAME_ACT_KIND_ESC:
				if (Myplayer.IsEsc == TRUE)	//��������Ƃ��̃��b�Z�[�W
				{
					DrawStringToHandle(Myplayer.rect_act_atk.left, Myplayer.rect_act_atk.top, "���܂� �������ꂽ�I", GetColor(0, 0, 0), FontDefault);
				}
				else if (Myplayer.IsEsc == FALSE)	//��������Ƃ��̃��b�Z�[�W
				{
					DrawStringToHandle(Myplayer.rect_act_atk.left, Myplayer.rect_act_atk.top, "��荞�܂�� ���܂����I �������Ȃ��I", GetColor(0, 0, 0), FontDefault);
				}
				break;
			default:
				break;
			}

			//���΂炭���b�Z�[�W��\��
			if (Myplayer.IsActMsgEnd == FALSE)
			{
				if (Myplayer.NowActMsgCnt < Myplayer.NowActMsgCntMAX)
				{
					Myplayer.NowActMsgCnt++;
				}
				else
				{
					Myplayer.IsActMsgEnd = TRUE;		//�s�����b�Z�[�W�I��
				}
			}

			if (Myplayer.IsActLvupStart == TRUE)	//���x���A�b�v���b�Z�[�W��\��
			{
				//���΂炭���b�Z�[�W��\��
				if (Myplayer.NowActLvupCnt < Myplayer.NowActLvupntMAX)
				{
					Myplayer.NowActLvupCnt++;
				}
				else
				{
					Myplayer.IsActLvupEnd = TRUE;		//���x���A�b�v���b�Z�[�W�I��
				}
			}
		}
	}
	else if (Myplayer.battle_turn == (int)GAME_TURN_ENEMY)	//�G�̃^�[���̂Ƃ�
	{
		if (Myplayer.IsActMsgStart == TRUE)	//�s�����b�Z�[�W�J�n
		{
			int cnt;
			for (cnt = 0; cnt < Myplayer.eneBattleCnt; cnt++)	//�G�̐������U��
			{
				DrawFormatStringToHandle(Myplayer.rect_act_atk.left, Myplayer.rect_act_atk.top, GetColor(0, 0, 0), FontDefault, "%s �� ���������I", eneBattle[cnt].name);

				if (eneBattle[cnt].damageCalc > 0)	//�_���[�W��^������Ƃ�
				{
					DrawFormatStringToHandle(Myplayer.rect_act_atk.left, Myplayer.rect_act_atk.top + (cnt + 1) * 20, GetColor(0, 0, 0), FontDefault, "%s �� %d �� ���������I", Myplayer.name, eneBattle[cnt].ATK - Myplayer.DEF);
				}
				else
				{
					DrawFormatStringToHandle(Myplayer.rect_act_atk.left, Myplayer.rect_act_atk.top + (cnt + 1) * 20, GetColor(0, 0, 0), FontDefault, "%s �� �_���[�W �� �^�����Ȃ��I", Myplayer.name);
				}
			}

			if (Myplayer.IsAlive == FALSE)	//�����������ꂽ�Ƃ�
			{
				DrawFormatStringToHandle(Myplayer.rect_act_atk.left, Myplayer.rect_act_atk.top + (cnt + 1) * 20, GetColor(0, 0, 0), FontDefault, "%s �� �����ꂽ�I", Myplayer.name);
			}

			//���΂炭���b�Z�[�W��\��
			if (Myplayer.IsActMsgEnd == FALSE)
			{
				if (Myplayer.NowActMsgCnt < Myplayer.NowActMsgCntMAX)
				{
					Myplayer.NowActMsgCnt++;
				}
				else
				{
					Myplayer.IsActMsgEnd = TRUE;		//�s�����b�Z�[�W�I��
				}
			}

		}
	}

	if (Myplayer.eneBattleCnt == 1)
	{
		if (eneBattle[0].IsAlive == TRUE)	//�G���킦��Ƃ�
		{
			//�G��\��
			DrawGraph(
				eneBattle[0].rect_act.left,
				eneBattle[0].rect_act.top,
				eneBattle[0].Handle,
				TRUE);

			//�G�̃X�e�[�^�X��\������ꏊ
			DrawBox(
				eneBattle[0].rect_st.left,
				eneBattle[0].rect_st.top,
				eneBattle[0].rect_st.right,
				eneBattle[0].rect_st.bottom,
				GetColor(0, 0, 0),
				TRUE);

			DrawBox(
				eneBattle[0].rect_st.left + 4,
				eneBattle[0].rect_st.top + 4,
				eneBattle[0].rect_st.right - 4,
				eneBattle[0].rect_st.bottom - 4,
				GetColor(255, 255, 255),
				TRUE);

			int EneHpColor;	//HP�̐F�����߂�
			if (eneBattle[0].HP > eneBattle[0].HP_MAX / 2) { EneHpColor = GetColor(0, 255, 0); }
			else if (eneBattle[0].HP > eneBattle[0].HP_MAX / 4) { EneHpColor = GetColor(255, 255, 0); }
			else { EneHpColor = GetColor(255, 0, 0); }

			//HP���l�p�ŕ\������
			DrawBox(
				eneBattle[0].rect_st.left + 4,
				eneBattle[0].rect_st.top + 18 * 2 + 4,
				eneBattle[0].rect_st.left + 4 + (GAME_BATTLE_TEKI_ACT_WIDTH * eneBattle[0].HP / eneBattle[0].HP_MAX) - 8,
				eneBattle[0].rect_st.top + 18 * 3,
				EneHpColor, TRUE);

			//�G�̃X�e�[�^�X��\������
			DrawFormatStringToHandle(eneBattle[0].rect_st.left, eneBattle[0].rect_st.top + 6, GetColor(0, 0, 0), FontDefault, " %s", eneBattle[0].name);
			DrawFormatStringToHandle(eneBattle[0].rect_st.left, eneBattle[0].rect_st.top + 18 * 1 + 4, GetColor(0, 0, 0), FontDefault, "�@�k�@�u�F%03d", eneBattle[0].LV);
			DrawFormatStringToHandle(eneBattle[0].rect_st.left, eneBattle[0].rect_st.top + 18 * 2 + 4, GetColor(0, 0, 0), FontDefault, "�@�g�@�o�F%03d�^%03d", eneBattle[0].HP, eneBattle[0].HP_MAX);
		}
	}

	DrawStringToHandle(0, 0, "�퓬���", GetColor(255, 255, 255), FontDefault);

	return;
}

//########## �G���h��ʂ̊֐� ##########
VOID MY_GAME_END(VOID)
{
	BOOL IsAtari = FALSE;	//�����蔻��

	//BGM������Ă��Ȃ��Ƃ�
	if (CheckSoundMem(MUSIC_MY_BGM_END.Handle) == 0)
	{
		ChangeVolumeSoundMem(255 * 70 / 100, MUSIC_MY_BGM_END.Handle);	//BGM�̉��ʂ�50���ɂ���
		PlaySoundMem(MUSIC_MY_BGM_END.Handle, DX_PLAYTYPE_LOOP);			//BGM�𗬂�
	}

	switch (Myplayer.gameEndKind)	//�L�[����
	{
	case (int)GAME_END_KIND_NONE:

		break;

	case (int)GAME_END_KIND_OVER:

		if (AllKeyState[KEY_INPUT_LEFT] != 0)	//�����L�[��������Ă�����
		{
			if (Myplayer.X > 0)
			{
				Myplayer.X -= Myplayer.Speed;	//�v���C���[�����Ɉړ�
			}
		}

		if (AllKeyState[KEY_INPUT_RIGHT] != 0)	//�E���L�[��������Ă�����
		{
			if (Myplayer.X + Myplayer.Width < GAME_WIDTH)
			{
				Myplayer.X += Myplayer.Speed;	//�v���C���[���E�Ɉړ�
			}
		}

		if (AllKeyState[KEY_INPUT_UP] != 0)	//����L�[��������Ă�����
		{
			if (Myplayer.Y > 0)
			{
				Myplayer.Y -= Myplayer.Speed;	//�v���C���[����Ɉړ�
			}
		}

		if (AllKeyState[KEY_INPUT_DOWN] != 0)	//�����L�[��������Ă�����
		{
			if (Myplayer.Y + Myplayer.Width < GAME_HEIGHT)
			{
				Myplayer.Y += Myplayer.Speed;			//�v���C���[�����Ɉړ�
			}
		}

		MY_SET_PLAYER_ATARI(&Myplayer);	//�����蔻����v���C���[�ɔ��f

		if (MY_CHECK_RECT_ATARI(rectEndCon, Myplayer.atariRect) == TRUE)	//�R���e�B�j���[�̂Ƃ�
		{
			if (EndConCnt < EndConCntMAX)
			{
				EndConCnt++;
			}
			else
			{
				GameSceneNow = (int)GAME_SCENE_PLAY;	//�V�[�����v���C��ʂɂ���
			}

			IsAtari = TRUE;
		}
		else
		{
			if (EndConCnt > 0)
			{
				EndConCnt--;
			}
		}

		if (MY_CHECK_RECT_ATARI(rectEndEnd, Myplayer.atariRect) == TRUE)	//�R���e�B�j���[�̂Ƃ�
		{
			if (EndEndCnt < EndEndCntMAX)
			{
				EndEndCnt++;
			}
			else
			{
				GameSceneNow = (int)GAME_SCENE_TITLE;	//�V�[�����^�C�g����ʂɂ���
			}

			IsAtari = TRUE;
		}
		else
		{
			if (EndEndCnt > 0)
			{
				EndEndCnt--;
			}
		}

		if (IsAtari == TRUE)
		{
			if (CheckSoundMem(MUSIC_MY_SE_END_SELECT.Handle) == 0)
			{
				ChangeVolumeSoundMem(255 * 50 / 100, MUSIC_MY_SE_END_SELECT.Handle);	//BGM�̉��ʂ�50���ɂ���
				PlaySoundMem(MUSIC_MY_SE_END_SELECT.Handle, DX_PLAYTYPE_BACK);
			}
		}
		else if (IsAtari == FALSE)
		{
			if (CheckSoundMem(MUSIC_MY_SE_END_SELECT.Handle) != 0)
			{
				StopSoundMem(MUSIC_MY_SE_END_SELECT.Handle);
			}
		}

		break;

	case (int)GAME_END_KIND_CLEAR:

		if (AllKeyState[KEY_INPUT_SPACE] != 0)	//�X�y�[�X�L�[��������Ă�����
		{
			GameSceneNow = (int)GAME_SCENE_TITLE;	//�V�[�����^�C�g����ʂɂ���
		}

		break;
	default:

		break;
	}

	MY_GAME_END_DRAW();	//�G���h��ʕ`��̊֐�
	MY_GAME_BACK_DRAW();

	/*****************************�ǉ�***************************/
	if (AllKeyState[KEY_INPUT_DOWN] == 1) {
		SelectEndNum = (SelectEndNum + 1) % 2;
	}

	if (AllKeyState[KEY_INPUT_UP] == 1) {
		SelectEndNum = (SelectEndNum + 1) % 2;
	}	if (AllKeyState[KEY_INPUT_DOWN] == 1 || AllKeyState[KEY_INPUT_UP] == 1) {
		for (int i = 0; i < 2; i++)
		{
			if (i == SelectEndNum) {
				MenuElemen[i].x = 100;
			}
			else {
				MenuElemen[i].x = 120;
			}
		}
	}
	else if (SelectEndNum == 1 && AllKeyState[KEY_INPUT_RETURN] == 1)
	{
		GameSceneNow = GAME_SCENE_TITLE;
	}
	else if (SelectEndNum == 0 && AllKeyState[KEY_INPUT_RETURN] == 1)
	{
		//scene = GAME_SCENE_PLAY;

		if (GAME_SCENE_PLAY == play_scene)
		{
			GameSceneNow = GAME_SCENE_PLAY;
			MY_PLAY_INIT();
			MY_GAME_GET_TIME = GET_TIME;
		}
		/*else if (GAME_SCENE_PLAY_2 == play_scene)
		{
			GameSceneNow = GAME_SCENE_PLAY_2;
		}
		else if (GAME_SCENE_PLAY_3 == play_scene)
		{
			GameSceneNow = GAME_SCENE_PLAY_3;
		}*/
	}
	for (int i = 0; i < 2; i++) {
		DrawFormatString(MenuElemen[i].x, MenuElemen[i].y, GetColor(255, 123, 195), "%s", MenuElemen[i].name);
	}


	/*****************************�ǉ������܂�*******************************/
	return;
}

//########## �G���h��ʕ`��̊֐� ##########
VOID MY_GAME_END_DRAW(VOID)
{
	char clear[64] = { "GAME CLEAR" };
	int height;
	int Width;

	switch (Myplayer.gameEndKind)	//�`��
	{
	case (int)GAME_END_KIND_NONE:

		break;

	case (int)GAME_END_KIND_OVER:

		DrawBox(rectEndCon.left, rectEndCon.top, rectEndCon.right, rectEndCon.bottom, GetColor(255, 0, 0), FALSE);

		SetDrawBlendMode(DX_BLENDMODE_ALPHA, ((double)EndConCnt / EndConCntMAX) * 255);	//���߂�����
		DrawBox(rectEndCon.left + 4, rectEndCon.top + 4, rectEndCon.right - 4, rectEndCon.bottom - 4, GetColor(255, 0, 0), TRUE);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);								//���߂���߂�

		DrawStringToHandle(rectEndCon.left + 4, rectEndCon.top + 4, "GAME CONTINUE??", GetColor(255, 255, 255), FontDefault);

		DrawBox(rectEndEnd.left, rectEndEnd.top, rectEndEnd.right, rectEndEnd.bottom, GetColor(0, 0, 255), FALSE);

		SetDrawBlendMode(DX_BLENDMODE_ALPHA, ((double)EndEndCnt / EndEndCntMAX) * 255);	//���߂�����
		DrawBox(rectEndEnd.left + 4, rectEndEnd.top + 4, rectEndEnd.right - 4, rectEndEnd.bottom - 4, GetColor(0, 0, 255), TRUE);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);								//���߂���߂�

		DrawStringToHandle(rectEndEnd.left + 4, rectEndEnd.top + 4, "BACK TITLE??", GetColor(255, 255, 255), FontDefault);

		MY_PLAY_PLAYER_DRAW(Myplayer);					//�v���C���[��`�悷��

		break;

	case (int)GAME_END_KIND_CLEAR:

		DrawGraph(0, 0, image_clear.Handle[0], TRUE);

		height = GetFontSizeToHandle(FontBig);								//�t�H���g�̍������擾
		Width = GetDrawStringWidthToHandle(clear, strlen(clear), FontBig);	//�t�H���g�̕����擾

		DrawStringToHandle(GAME_WIDTH / 2 - Width / 2 + 4, GAME_HEIGHT / 2 - height / 2 - 100 + 4, clear, GetColor(0, 0, 0), FontBig);
		DrawStringToHandle(GAME_WIDTH / 2 - Width / 2, GAME_HEIGHT / 2 - height / 2 - 100, clear, GetColor(30, 144, 255), FontBig);


		break;
	default:

		break;
	}

	DrawStringToHandle(0, 0, "�G���h���", GetColor(255, 255, 255), FontDefault);

	return;
}

//########## �G�̏��CSV��ǂݍ��ފ֐� ##########
BOOL MY_ENEMY_READ_CSV(ENEDATA *enedata, const char *path, int max)
{
	FILE *fp;

	if ((fp = fopen(path, "r")) == NULL)	//�t�@�C����ǂݍ��݃��[�h(r)�ŊJ��
	{
		return FALSE;
	}//�ُ�I��

	//�������琳��ɓǂݍ��߂��Ƃ��̏���****************************************

	char read = '\0';
	while (read != '\n')	//1�s�ڂ����s���q���g�ɔ�΂�
	{
		read = fgetc(fp);
	}

	int result = 0;			//�t�@�C���̍Ōォ�`�F�b�N
	int LoopCnt = 0;		//���[�v�J�E���^
	while (result != EOF)	//End Of File�i�t�@�C���̍Ō�j�ł͂Ȃ��Ƃ��J��Ԃ�
	{
		//CSV�̃f�[�^�̂P�s����ǂݎ��
		result = fscanf(
			fp,
			"%d,%d,%d,%[^,],%d,%d,%d",
			&(enedata + LoopCnt)->No,
			&(enedata + LoopCnt)->enetype,
			&(enedata + LoopCnt)->LV,
			(enedata + LoopCnt)->name,
			&(enedata + LoopCnt)->HP,
			&(enedata + LoopCnt)->ATK,
			&(enedata + LoopCnt)->DEF
		);

		(enedata + LoopCnt)->HP_MAX = (enedata + LoopCnt)->HP;
		(enedata + LoopCnt)->ATK_MAX = (enedata + LoopCnt)->ATK;
		(enedata + LoopCnt)->DEF_MAX = (enedata + LoopCnt)->DEF;

		LoopCnt++;

		if (LoopCnt > max + 1)	//CSV�̏�񂪑�������Ƃ�
		{
			fclose(fp);		//�t�@�C�������
			return FALSE;
		}
	}
	fclose(fp);	//�t�@�C�������

	return TRUE;
}
//########## �Q�[���}�b�v��CSV��ǂݍ��ފ֐� ##########
BOOL MY_MAP_READ_CSV_NUM(MAPDATA *mapdata, const char *path, const char *mapname)
{
	FILE *fp;

	if ((fp = fopen(path, "r")) == NULL)	//�t�@�C����ǂݍ��݃��[�h(r)�ŊJ��
	{
		return FALSE;
	}//�ُ�I��	

	 //�������琳��ɓǂݍ��߂��Ƃ��̏���****************************************

	int result = 0;			//�t�@�C���̍Ōォ�`�F�b�N
	int LoopCnt = 0;		//���[�v�J�E���^
	while (result != EOF)	//End Of File�i�t�@�C���̍Ō�j�ł͂Ȃ��Ƃ��J��Ԃ�
	{
		//�t�@�C�����琔�l����ǂݍ���(%d,)�A�z��Ɋi�[����
		result = fscanf(fp, "%d,", &mapdata->data[LoopCnt / GAME_MAP_YOKO][LoopCnt % GAME_MAP_YOKO]);
		mapdata->mapdata_Init[LoopCnt / GAME_MAP_YOKO][LoopCnt % GAME_MAP_YOKO]
			= mapdata->data[LoopCnt / GAME_MAP_YOKO][LoopCnt % GAME_MAP_YOKO];	//�l���R�s�[

		LoopCnt++;
	}
	fclose(fp);	//�t�@�C�������

	//�}�b�v�̖��̂�����
	wsprintf(mapdata->name, mapname);	//�}�b�v�̖��̂��R�s�[

	//�}�b�v�̈�̏�����
	for (int tate = 0; tate < GAME_MAP_TATE; tate++)
	{
		for (int yoko = 0; yoko < GAME_MAP_YOKO; yoko++)
		{
			mapdata->rect_NG[tate][yoko].left = 0;
			mapdata->rect_NG[tate][yoko].top = 0;
			mapdata->rect_NG[tate][yoko].right = 0;
			mapdata->rect_NG[tate][yoko].bottom = 0;

			mapdata->rect_NG_First[tate][yoko] = mapdata->rect_NG[tate][yoko];	//�����ʒu��ݒ�

			mapdata->rect_OK[tate][yoko].left = 0;
			mapdata->rect_OK[tate][yoko].top = 0;
			mapdata->rect_OK[tate][yoko].right = 0;
			mapdata->rect_OK[tate][yoko].bottom = 0;

			mapdata->rect_OK_First[tate][yoko] = mapdata->rect_OK[tate][yoko];	//�����ʒu��ݒ�

			mapdata->rect_BT[tate][yoko].left = 0;
			mapdata->rect_BT[tate][yoko].top = 0;
			mapdata->rect_BT[tate][yoko].right = 0;
			mapdata->rect_BT[tate][yoko].bottom = 0;

			mapdata->rect_BT_First[tate][yoko] = mapdata->rect_BT[tate][yoko];	//�����ʒu��ݒ�

			mapdata->rect_CL[tate][yoko].left = 0;
			mapdata->rect_CL[tate][yoko].top = 0;
			mapdata->rect_CL[tate][yoko].right = 0;
			mapdata->rect_CL[tate][yoko].bottom = 0;

			mapdata->rect_CL_First[tate][yoko] = mapdata->rect_CL[tate][yoko];	//�����ʒu��ݒ�

		}
	}

	//�}�b�v�𓖂��蔻��̗̈�ɕϊ�
	int cnt;
	for (int tate = 0; tate < GAME_MAP_TATE; tate++)
	{
		for (int yoko = 0; yoko < GAME_MAP_YOKO; yoko++)
		{
			for (cnt = 0; cnt < GAME_MAP_NG_KIND; cnt++)	//�ʍs�ł��Ȃ��}�b�v
			{
				if (mapdata->data[tate][yoko] == mapdata->mapNGKind[cnt])
				{
					mapdata->rect_NG[tate][yoko].left = yoko * GAME_MAP_YOKO_SIZE + 1;
					mapdata->rect_NG[tate][yoko].top = tate * GAME_MAP_TATE_SIZE + 1;
					mapdata->rect_NG[tate][yoko].right = (yoko + 1) * GAME_MAP_YOKO_SIZE - 1;
					mapdata->rect_NG[tate][yoko].bottom = (tate + 1) * GAME_MAP_TATE_SIZE - 1;

					mapdata->rect_NG_First[tate][yoko] = mapdata->rect_NG[tate][yoko];	//�����ʒu��ݒ�
				}
			}

			for (cnt = 0; cnt < GAME_MAP_OK_KIND; cnt++)	//�ʍs�ł���}�b�v
			{
				if (mapdata->data[tate][yoko] == mapdata->mapOKKind[cnt])
				{
					mapdata->rect_OK[tate][yoko].left = yoko * GAME_MAP_YOKO_SIZE + 1;
					mapdata->rect_OK[tate][yoko].top = tate * GAME_MAP_TATE_SIZE + 1;
					mapdata->rect_OK[tate][yoko].right = (yoko + 1) * GAME_MAP_YOKO_SIZE - 1;
					mapdata->rect_OK[tate][yoko].bottom = (tate + 1) * GAME_MAP_TATE_SIZE - 1;

					mapdata->rect_OK_First[tate][yoko] = mapdata->rect_OK[tate][yoko];	//�����ʒu��ݒ�
				}
			}

			for (cnt = 0; cnt < GAME_MAP_BT_KIND; cnt++)	//�퓬�}�b�v
			{
				if (mapdata->data[tate][yoko] == mapdata->mapBTKind[cnt])
				{
					mapdata->rect_BT[tate][yoko].left = yoko * GAME_MAP_YOKO_SIZE + 1;
					mapdata->rect_BT[tate][yoko].top = tate * GAME_MAP_TATE_SIZE + 1;
					mapdata->rect_BT[tate][yoko].right = (yoko + 1) * GAME_MAP_YOKO_SIZE - 1;
					mapdata->rect_BT[tate][yoko].bottom = (tate + 1) * GAME_MAP_TATE_SIZE - 1;

					mapdata->rect_BT_First[tate][yoko] = mapdata->rect_BT[tate][yoko];	//�����ʒu��ݒ�
				}
			}
			//############################�ǉ�#############################################
			for (cnt = 0; cnt < GAME_MAP_CLEAR; cnt++)	//�퓬�}�b�v
			{
				if (mapdata->data[tate][yoko] == mapdata->mapCLKind[cnt])
				{
					mapdata->rect_CL[tate][yoko].left = yoko * GAME_MAP_YOKO_SIZE + 1;
					mapdata->rect_CL[tate][yoko].top = tate * GAME_MAP_TATE_SIZE + 1;
					mapdata->rect_CL[tate][yoko].right = (yoko + 1) * GAME_MAP_YOKO_SIZE - 1;
					mapdata->rect_CL[tate][yoko].bottom = (tate + 1) * GAME_MAP_TATE_SIZE - 1;

					mapdata->rect_CL_First[tate][yoko] = mapdata->rect_CL[tate][yoko];	//�����ʒu��ݒ�
				}
			}
			//#######################�����܂�##########################################################
		}
	}

	return TRUE;
}

//########## �w�i��ǂݍ��ސݒ������֐� ##########
//���@���FIMAGE�\���́F�ݒ肷��摜�\���̂̕ϐ�
//���@���Fconst char *�F�ǂݍ��މ摜�̃t�@�C���p�X
//�߂�l�Fint�F�摜�̃n���h�� / �G���[�� -1
int MY_LOAD_BACKGROUND(IMAGE *image, const char *path)
{
	image->Handle[0] = LoadGraph(path);	//�n���h���͂P�����Ȃ�

	//�摜�T�C�Y���擾
	GetGraphSize(
		image->Handle[0],			//�n���h������A�摜�̕��ƍ������擾���āE�E�E
		&image->Width[0],			//IMAGE�\���̂̕��@�ɁA�摜�̕��@��ݒ肷��
		&image->Height[0]);			//IMAGE�\���̂̋t���ɁA�摜�̍�����ݒ肷��			

	image->C_Width[0] = image->Width[0] / 2;	//�摜�̉��T�C�Y�̒��S���擾
	image->C_Height[0] = image->Height[0] / 2;	//�摜�̏c�T�C�Y�̒��S���擾

	return image->Handle[0];
}

//########## �G��ǂݍ��ސݒ������֐� ##########
//���@���FENEDATA�\���́F�ݒ肷��摜�\���̂̕ϐ�
//���@���Fconst char *�F�ǂݍ��މ摜�̃t�@�C���p�X
//�߂�l�Fint�F�摜�̃n���h�� / �G���[�� -1
int MY_LOAD_ENEMY(ENEDATA *enedata, const char *path)
{
	enedata->Handle = LoadGraph(path);	//�n���h���͂P�����Ȃ�

	//�摜�T�C�Y���擾
	GetGraphSize(
		enedata->Handle,			//�n���h������A�摜�̕��ƍ������擾���āE�E�E
		&enedata->Width,			//ENEDATA�\���̂̕��@�ɁA�摜�̕��@��ݒ肷��
		&enedata->Height);			//ENEDATA�\���̂̋t���ɁA�摜�̍�����ݒ肷��			

	enedata->C_Width = enedata->Width / 2;	//�摜�̉��T�C�Y�̒��S���擾
	enedata->C_Height = enedata->Height / 2;	//�摜�̏c�T�C�Y�̒��S���擾

	return enedata->Handle;
}

//########## MAP�𕪊����ēǂݍ��ސݒ������֐� ##########
//���@���FMAPDATA�\���́F�ݒ肷��摜�\����(����)�̕ϐ�
//���@���Fint�@�F�摜�̕�����
//���@���Fint�@�F�摜�̉��̕�����
//���@���Fint�@�F�摜�̏c�̕�����
//���@���Fint�@�F�摜�̉��̕����T�C�Y
//���@���Fint�@�F�摜�̏c�̕����T�C�Y
//���@���Fconst char *�F�ǂݍ��މ摜�̃t�@�C���p�X
//�߂�l�FBOOL�F�G���[���FFALSE
//BOOL MY_MAP_LOAD_BUNKATSU(MAPDATA *mapdata, int bun_num, int bun_x_num, int bun_y_num, int bun_width, int bun_height, const char *path)
//{
//	int ret = 0;
//
//	ret = LoadDivGraph(path, bun_num, bun_x_num, bun_y_num, bun_width, bun_height, mapdata->Handle);	//�摜���������ɕ������ēǂݍ��݁A�n���h�����擾
//
//	if (ret == -1) { return FALSE; }	//�摜�ǂݍ��݃G���[
//
//	for (int cnt = 0; cnt < GAME_MAP_BUN_YOKO_CNT * GAME_MAP_BUN_TATE_CNT; cnt++)
//	{
//		//�摜�T�C�Y���擾
//		GetGraphSize(
//			mapdata->Handle[cnt],		//�n���h������A�摜�̕��ƍ������擾���āE�E�E
//			&mapdata->Width[cnt],		//MAP�\���̂̕��@�ɁA�摜�̕��@��ݒ肷��
//			&mapdata->Height[cnt]);		//MAP�\���̂̋t���ɁA�摜�̍�����ݒ肷��			
//
//		mapdata->C_Width[cnt] = mapdata->Width[cnt] / 2;	//�摜�̉��T�C�Y�̒��S���擾
//		mapdata->C_Height[cnt] = mapdata->Height[cnt] / 2;	//�摜�̏c�T�C�Y�̒��S���擾
//	}
//
//	return TRUE;
//}

//########## CHARA�𕪊����ēǂݍ��ސݒ������֐� ##########
//���@���FCHARAIMAGE�\���́@�F�ݒ肷��CHARAIMAGE�\����(����)�̕ϐ�
//���@���Fint�@�F�摜�̕�����
//���@���Fint�@�F�摜�̉��̕�����
//���@���Fint�@�F�摜�̏c�̕�����
//���@���Fint�@�F�摜�̉��̕����T�C�Y
//���@���Fint�@�F�摜�̏c�̕����T�C�Y
//���@���Fconst char *�F�ǂݍ��މ摜�̃t�@�C���p�X
//�߂�l�FBOOL�F�G���[���FFALSE
BOOL MY_CHARA_LOAD_BUNKATSU(CHARAIMAGE *c, int bun_num, int bun_x_num, int bun_y_num, int bun_width, int bun_height, const char *path)
{
	int retLoad;

	//�t�@�C���p�X���R�s�[
	wsprintf(c->FilePath, path);

	//�摜���������ɕ������ēǂݍ��݁A�n���h�����擾
	retLoad = LoadDivGraph(c->FilePath, bun_num, bun_x_num, bun_y_num, bun_width, bun_height, c->HandleChara);

	if (retLoad == -1) { return FALSE; }	//�摜�ǂݍ��݃G���[

	for (int cnt = 0; cnt < GAME_CHARA_BUN_YOKO_CNT *GAME_CHARA_BUN_TATE_CNT; cnt++)
	{
		//�摜�T�C�Y���擾
		GetGraphSize(
			c->HandleChara[cnt],		//�n���h������A�摜�̕��ƍ������擾���āE�E�E
			&c->Width[cnt],		//MAP�\���̂̕��@�ɁA�摜�̕��@��ݒ肷��
			&c->Height[cnt]);	//MAP�\���̂̋t���ɁA�摜�̍�����ݒ肷��			

		c->C_Width[cnt] = c->Width[cnt] / 2;			//�摜�̉��T�C�Y�̒��S���擾
		c->C_Height[cnt] = c->Height[cnt] / 2;			//�摜�̏c�T�C�Y�̒��S���擾
	}

	return TRUE;
}

//########## ����ǂݍ��ސݒ������֐� ##########
//���@���F���\���́@	:�ݒ肷�鉹�\���̂̕ϐ�
//���@���Fconst char *	:�ǂݍ��މ摜�̃t�@�C���p�X
//�߂�l�FBOOL			:TRUE:���� / FALSE:�ُ�
BOOL MY_MUSIC_LOAD(MUSIC *m, const char *path)
{
	//����ǂݍ���
	m->Handle = LoadSoundMem(path);

	if (m->Handle == -1) { return FALSE; }

	return TRUE;
}

//########## �}�b�v(��)����̎�ނ�ݒ肷�� ##########
BOOL MY_MAP_READ_CSV_UE_KIND_SET(MAPDATA *mapdata)
{
	int Soeji;

	//�ʍs�ł����ނ̎c���-1�Ŗ��߂�
	Soeji = 0;
	for (int cnt = Soeji; cnt < GAME_MAP_OK_KIND; cnt++) { mapdata->mapOKKind[cnt] = -1; }

	//�ʍs�ł��Ȃ���ނ̎c���-1�Ŗ��߂�
	Soeji = 0;
	for (int cnt = Soeji; cnt < GAME_MAP_NG_KIND; cnt++) { mapdata->mapNGKind[cnt] = -1; }

	//�퓬����}�b�v�̎c���-1�Ŗ��߂�
	Soeji = 0;
	for (int cnt = Soeji; cnt < GAME_MAP_BT_KIND; cnt++) { mapdata->mapBTKind[cnt] = -1; }

	return TRUE;
}

//########## �}�b�v(��)����̎�ނ�ݒ肷�� ##########
BOOL MY_MAP_READ_CSV_NAKA_KIND_SET(MAPDATA *mapdata)
{
	int Soeji;

	//�ʍs�ł���}�b�v
	Soeji = 0;
	mapdata->mapOKKind[Soeji++] = 30;	//��
	mapdata->mapOKKind[Soeji++] = 1081;	//�b�̓�
	mapdata->mapOKKind[Soeji++] = 1145;	//�{�̓�
	mapdata->mapOKKind[Soeji++] = 1113;	//�|�̓�
	mapdata->mapOKKind[Soeji++] = 18;	//��

	mapdata->mapOKKind[Soeji++] = 160;	//�t���
	mapdata->mapOKKind[Soeji++] = 161;	//�t���
	mapdata->mapOKKind[Soeji++] = 162;	//�t���
	mapdata->mapOKKind[Soeji++] = 163;	//�t���
	mapdata->mapOKKind[Soeji++] = 192;	//�t���
	mapdata->mapOKKind[Soeji++] = 193;	//�t���
	mapdata->mapOKKind[Soeji++] = 194;	//�t���
	mapdata->mapOKKind[Soeji++] = 195;	//�t���
	mapdata->mapOKKind[Soeji++] = 224;	//�t���
	mapdata->mapOKKind[Soeji++] = 225;	//�t���
	mapdata->mapOKKind[Soeji++] = 226;	//�t���
	mapdata->mapOKKind[Soeji++] = 227;	//�t���
	mapdata->mapOKKind[Soeji++] = 256;	//�t���
	mapdata->mapOKKind[Soeji++] = 259;	//�t���

	mapdata->mapOKKind[Soeji++] = 164;	//�đ��
	mapdata->mapOKKind[Soeji++] = 165;	//�đ��
	mapdata->mapOKKind[Soeji++] = 166;	//�đ��
	mapdata->mapOKKind[Soeji++] = 167;	//�đ��
	mapdata->mapOKKind[Soeji++] = 196;	//�đ��
	mapdata->mapOKKind[Soeji++] = 197;	//�đ��
	mapdata->mapOKKind[Soeji++] = 198;	//�đ��
	mapdata->mapOKKind[Soeji++] = 199;	//�đ��
	mapdata->mapOKKind[Soeji++] = 228;	//�đ��
	mapdata->mapOKKind[Soeji++] = 229;	//�đ��
	mapdata->mapOKKind[Soeji++] = 230;	//�đ��
	mapdata->mapOKKind[Soeji++] = 231;	//�đ��
	mapdata->mapOKKind[Soeji++] = 260;	//�đ��
	mapdata->mapOKKind[Soeji++] = 263;	//�đ��

	mapdata->mapOKKind[Soeji++] = 288;	//�H���
	mapdata->mapOKKind[Soeji++] = 289;	//�H���
	mapdata->mapOKKind[Soeji++] = 290;	//�H���
	mapdata->mapOKKind[Soeji++] = 291;	//�H���
	mapdata->mapOKKind[Soeji++] = 320;	//�H���
	mapdata->mapOKKind[Soeji++] = 321;	//�H���
	mapdata->mapOKKind[Soeji++] = 322;	//�H���
	mapdata->mapOKKind[Soeji++] = 323;	//�H���
	mapdata->mapOKKind[Soeji++] = 352;	//�H���
	mapdata->mapOKKind[Soeji++] = 353;	//�H���
	mapdata->mapOKKind[Soeji++] = 354;	//�H���
	mapdata->mapOKKind[Soeji++] = 355;	//�H���
	mapdata->mapOKKind[Soeji++] = 384;	//�H���
	mapdata->mapOKKind[Soeji++] = 387;	//�H���

	mapdata->mapOKKind[Soeji++] = 292;	//�~���
	mapdata->mapOKKind[Soeji++] = 293;	//�~���
	mapdata->mapOKKind[Soeji++] = 294;	//�~���
	mapdata->mapOKKind[Soeji++] = 295;	//�~���
	mapdata->mapOKKind[Soeji++] = 324;	//�~���
	mapdata->mapOKKind[Soeji++] = 325;	//�~���
	mapdata->mapOKKind[Soeji++] = 326;	//�~���
	mapdata->mapOKKind[Soeji++] = 327;	//�~���
	mapdata->mapOKKind[Soeji++] = 356;	//�~���
	mapdata->mapOKKind[Soeji++] = 357;	//�~���
	mapdata->mapOKKind[Soeji++] = 358;	//�~���
	mapdata->mapOKKind[Soeji++] = 359;	//�~���
	mapdata->mapOKKind[Soeji++] = 388;	//�~���
	mapdata->mapOKKind[Soeji++] = 391;	//�~���
	mapdata->mapOKKind[Soeji++] = 12;	//��
	mapdata->mapOKKind[Soeji++] = 801;	//����
	mapdata->mapOKKind[Soeji++] = 768;	//����

	mapdata->mapOKKind[Soeji++] = 1219;	//�@�̉�
	mapdata->mapOKKind[Soeji++] = 1173;	//�s�T�̎Γ���

	mapdata->mapOKKind[Soeji++] = 466;	//���ĊŔ���
	mapdata->mapOKKind[Soeji++] = 467;	//���ĊŔE��

	mapdata->mapOKKind[Soeji++] = 82;	//������

	mapdata->mapOKKind[Soeji++] = 1188;	//��
	mapdata->mapOKKind[Soeji++] = 1188;	//��
	mapdata->mapOKKind[Soeji++] = 1188;	//��
	mapdata->mapOKKind[Soeji++] = 1186;	//��
	mapdata->mapOKKind[Soeji++] = 1190;	//��
	mapdata->mapOKKind[Soeji++] = 1191;	//��

	mapdata->mapOKKind[Soeji++] = 17;	//��

	//�ʍs�ł����ނ̎c���-1�Ŗ��߂�
	for (int cnt = Soeji; cnt < GAME_MAP_OK_KIND; cnt++) { mapdata->mapOKKind[cnt] = -1; }

	//�ʍs�ł��Ȃ��}�b�v
	Soeji = 0;
	mapdata->mapNGKind[Soeji++] = 1136;	//��
	mapdata->mapNGKind[Soeji++] = 1105;	//��
	mapdata->mapNGKind[Soeji++] = 1106;	//�ƍ�
	mapdata->mapNGKind[Soeji++] = 1200;	//�ƉE
	mapdata->mapNGKind[Soeji++] = 1169;	//���@��
	mapdata->mapNGKind[Soeji++] = 1170;	//���@�E

	mapdata->mapNGKind[Soeji++] = 34;	//���؉�
	mapdata->mapNGKind[Soeji++] = 35;	//���؉�
	mapdata->mapNGKind[Soeji++] = 98;	//���؉�
	mapdata->mapNGKind[Soeji++] = 99;	//���؉�
	mapdata->mapNGKind[Soeji++] = 66;	//���؉�
	mapdata->mapNGKind[Soeji++] = 67;	//���؉�

	mapdata->mapNGKind[Soeji++] = 945;	//����
	mapdata->mapNGKind[Soeji++] = 946;	//����

	mapdata->mapNGKind[Soeji++] = 257;	//�t���
	mapdata->mapNGKind[Soeji++] = 258;	//�t���
	mapdata->mapNGKind[Soeji++] = 261;	//�đ��
	mapdata->mapNGKind[Soeji++] = 262;	//�đ��
	mapdata->mapNGKind[Soeji++] = 385;	//�H���
	mapdata->mapNGKind[Soeji++] = 386;	//�H���
	mapdata->mapNGKind[Soeji++] = 389;	//�~���
	mapdata->mapNGKind[Soeji++] = 390;	//�~���
	mapdata->mapNGKind[Soeji++] = 1088;	//�t���
	mapdata->mapNGKind[Soeji++] = 1089;	//�đ��
	mapdata->mapNGKind[Soeji++] = 1090;	//�H���
	mapdata->mapNGKind[Soeji++] = 1091;	//�~���

	mapdata->mapNGKind[Soeji++] = 432;	//�؊Ŕ�

	mapdata->mapNGKind[Soeji++] = 448;	//�r
	mapdata->mapNGKind[Soeji++] = 480;	//�r
	mapdata->mapNGKind[Soeji++] = 512;	//�r
	mapdata->mapNGKind[Soeji++] = 544;	//�r
	mapdata->mapNGKind[Soeji++] = 450;	//�r
	mapdata->mapNGKind[Soeji++] = 482;	//�r
	mapdata->mapNGKind[Soeji++] = 513;	//�r
	mapdata->mapNGKind[Soeji++] = 546;	//�r
	mapdata->mapNGKind[Soeji++] = 481;	//�r
	mapdata->mapNGKind[Soeji++] = 513;	//�r
	mapdata->mapNGKind[Soeji++] = 545;	//�r

	mapdata->mapNGKind[Soeji++] = 1040;	//�R
	mapdata->mapNGKind[Soeji++] = 1041;	//�R
	mapdata->mapNGKind[Soeji++] = 1042;	//�R
	mapdata->mapNGKind[Soeji++] = 1043;	//�R
	mapdata->mapNGKind[Soeji++] = 1072;	//�R
	mapdata->mapNGKind[Soeji++] = 1073;	//�R
	mapdata->mapNGKind[Soeji++] = 1074;	//�R
	mapdata->mapNGKind[Soeji++] = 1075;	//�R

	mapdata->mapNGKind[Soeji++] = 1137;	//���@������
	mapdata->mapNGKind[Soeji++] = 1138;	//���@�����E

	mapdata->mapNGKind[Soeji++] = 1168;	//�w�Z
	mapdata->mapNGKind[Soeji++] = 1200;	//�s���~�b�h
	mapdata->mapNGKind[Soeji++] = 1233;	//�s���~�b�h
	mapdata->mapNGKind[Soeji++] = 1202;	//�Ɗ�
	mapdata->mapNGKind[Soeji++] = 1232;	//�ƈ��
	mapdata->mapNGKind[Soeji++] = 1234;	//�ƈ��
	mapdata->mapNGKind[Soeji++] = 1205;	//�s�T�̎Γ���

	mapdata->mapNGKind[Soeji++] = 498;	//���ĊŔ���
	mapdata->mapNGKind[Soeji++] = 499;	//���ĊŔE��

	mapdata->mapNGKind[Soeji++] = 1260;	//��
	mapdata->mapNGKind[Soeji++] = 1288;	//��
	mapdata->mapNGKind[Soeji++] = 1289;	//��
	mapdata->mapNGKind[Soeji++] = 1290;	//��
	mapdata->mapNGKind[Soeji++] = 1291;	//��
	mapdata->mapNGKind[Soeji++] = 1292;	//��
	mapdata->mapNGKind[Soeji++] = 1256;	//��
	mapdata->mapNGKind[Soeji++] = 1258;	//��
	mapdata->mapNGKind[Soeji++] = 1259;	//��
	mapdata->mapNGKind[Soeji++] = 1294;	//��

	mapdata->mapNGKind[Soeji++] = 542;	//��
	mapdata->mapNGKind[Soeji++] = 543;	//��
	mapdata->mapNGKind[Soeji++] = 574;	//��
	mapdata->mapNGKind[Soeji++] = 575;	//��
	mapdata->mapNGKind[Soeji++] = 606;	//��
	mapdata->mapNGKind[Soeji++] = 607;	//��

	mapdata->mapNGKind[Soeji++] = 1284;	//���Ƃ�����
	mapdata->mapNGKind[Soeji++] = 1285;	//���Ƃ�����

	mapdata->mapNGKind[Soeji++] = 1107;	//��������
	mapdata->mapNGKind[Soeji++] = 1108;	//��������
	mapdata->mapNGKind[Soeji++] = 1139;	//��������
	mapdata->mapNGKind[Soeji++] = 1140;	//��������

	mapdata->mapNGKind[Soeji++] = 1194;	//�������
	mapdata->mapNGKind[Soeji++] = 1195;	//�������

	mapdata->mapNGKind[Soeji++] = 1171;	//������
	mapdata->mapNGKind[Soeji++] = 1172;	//������
	mapdata->mapNGKind[Soeji++] = 1203;	//������
	mapdata->mapNGKind[Soeji++] = 1204;	//������

	mapdata->mapNGKind[Soeji++] = 1124;	//��

	mapdata->mapNGKind[Soeji++] = 350;	//��
	mapdata->mapNGKind[Soeji++] = 382;	//�󔠋�

	mapdata->mapNGKind[Soeji++] = 351;	//���̕�
	mapdata->mapNGKind[Soeji++] = 383;	//���̕󔠋�

	//�ʍs�ł��Ȃ���ނ̎c���-1�Ŗ��߂�
	for (int cnt = Soeji; cnt < GAME_MAP_NG_KIND; cnt++) { mapdata->mapNGKind[cnt] = -1; }

	//�퓬����}�b�v�̎c���-1�Ŗ��߂�
	Soeji = 0;
	for (int cnt = Soeji; cnt < GAME_MAP_BT_KIND; cnt++) { mapdata->mapBTKind[cnt] = -1; }

	return TRUE;
}

//########## �}�b�v(��)����̎�ނ�ݒ肷�� ##########
BOOL MY_MAP_READ_CSV_SITA_KIND_SET(MAPDATA *mapdata)
{
	int Soeji;


	//�ʍs�ł���}�b�v
	Soeji = 0;
	mapdata->mapOKKind[Soeji++] = 0;	//�΂̃}�b�v
	mapdata->mapOKKind[Soeji++] = 1;	//��1
	mapdata->mapOKKind[Soeji++] = 152;	//��
	mapdata->mapOKKind[Soeji++] = 314;	//������
	mapdata->mapOKKind[Soeji++] = 616;	//�r
	mapdata->mapOKKind[Soeji++] = 936;	//�C


	//�ʍs�ł����ނ̎c���-1�Ŗ��߂�
	for (int cnt = Soeji; cnt < GAME_MAP_OK_KIND; cnt++) { mapdata->mapOKKind[cnt] = -1; }

	//�ʍs�ł��Ȃ���ނ̎c���-1�Ŗ��߂�
	Soeji = 0;
	for (int cnt = Soeji; cnt < GAME_MAP_NG_KIND; cnt++) { mapdata->mapNGKind[cnt] = -1; }

	//�퓬����}�b�v
	Soeji = 0;
	mapdata->mapBTKind[Soeji++] = GAME_ENETYPE_GRASS;	//��1
	mapdata->mapBTKind[Soeji++] = GAME_ENETYPE_KUSA;	//��2
	mapdata->mapBTKind[Soeji++] = GAME_ENETYPE_RIVER;	//��
	mapdata->mapBTKind[Soeji++] = GAME_ENETYPE_MAOU;	//������
	mapdata->mapBTKind[Soeji++] = GAME_ENETYPE_BOSS;	//BOSS

	//�퓬����}�b�v�̎c���-1�Ŗ��߂�
	for (int cnt = Soeji; cnt < GAME_MAP_BT_KIND; cnt++) { mapdata->mapBTKind[cnt] = -1; }

	return TRUE;
}

//#########�ǉ����̔���####################
BOOL MY_MAP_READ_CSV_SIN_KIND_SET(MAPDATA *mapdata)
{
	int Soeji;


	//�ʍs�ł���}�b�v
	Soeji = 0;


	mapdata->mapOKKind[Soeji++] = 100;
	//mapdata->mapOKKind[Soeji++] = 102;

	//�ʍs�ł��Ȃ��}�b�v

	Soeji = 0;
	mapdata->mapNGKind[Soeji++] = 101;

	//�N���A
	Soeji = 0;
	mapdata->mapCLKind[Soeji++] = 102;
	//mapdata->mapNGKind[Soeji++] = 102;

	//############################################���s#########################################################################################
	/*if (MY_CHECK_RECT_ATARI_CHARA_MAP_ATARIBASHO(Myplayer.atariRect, mapData_sin.rect_NG,x,y) = 102)	//���ɍs���Ȃ����m�Ɠ��������Ƃ�
	{
		GameSceneNow = MY_GAME_END;
	}*/
	//###############################################################################################################################################

	Soeji = 0;




	return TRUE;
}

//#########�}�b�v�̓ǂݍ���#############
int LOAD_IMG(MAP_IMG *m_img, const char *path)
{
	m_img->Handle = LoadGraph(path);	//�n���h���͂P�����Ȃ�

//�摜�T�C�Y���擾
	GetGraphSize(
		m_img->Handle,			//�n���h������A�摜�̕��ƍ������擾���āE�E�E
		&m_img->Width,			//m_img�\���̂̕��@�ɁA�摜�̕��@��ݒ肷��
		&m_img->Height);			//m_img�\���̂̋t���ɁA�摜�̍�����ݒ肷��			

	m_img->C_Width = m_img->Width / 2;	//�摜�̉��T�C�Y�̒��S���擾
	m_img->C_Height = m_img->Height / 2;	//�摜�̏c�T�C�Y�̒��S���擾

	return m_img->Handle;

}

//�}�b�v�`��
VOID DRAW_MAP(MAP_IMG *map_img, int x, int y)
{

	//�X�N���[������}�b�v��`��
	//for (int tate = 0; tate < GAME_MAP_TATE; tate++)
	//{
	//	for (int yoko = 0; yoko < GAME_MAP_YOKO; yoko++)
	//	{
			//if ((yoko + 1) * GAME_MAP_YOKO_SIZE - ScrollCntYoko >= 0 &&
			//	(yoko + 0) * GAME_MAP_YOKO_SIZE - ScrollCntYoko <= GAME_WIDTH &&
			//	(tate + 1) * GAME_MAP_TATE_SIZE - ScrollCntTate >= 0 &&
			//	(tate + 0) * GAME_MAP_TATE_SIZE - ScrollCntTate <= GAME_HEIGHT
			//	)	//��ʂɎʂ��Ă���Ȃ�΂Ȃ��
	if (x - ScrollCntYoko <= GAME_WIDTH &&
		y - ScrollCntTate <= GAME_HEIGHT
		)	//��ʂɎʂ��Ă���Ȃ�΂Ȃ��

	{
		DrawGraph(
			x - ScrollCntYoko,				//�ʒu����X�N���[���ʂ�����
			y - ScrollCntTate,				//�ʒu����X�N���[���ʂ�����
			map_img->Handle, TRUE);		//�}�b�v���X�N���[�����Ȃ���`��
	}

	//	}
	//}

	//DrawGraph(x, y, map_img->Handle, TRUE);	//�`��
	return;
}
