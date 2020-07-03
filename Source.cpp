/*--+----1----+----2----+----3----+----4----+----5--//-+----6----+----7----+----8----+----9----+---*/
/* OC_01_Kansei.cpp   																			   */
/* OC用プログラム01(完成版)																		   */

#define _CRT_SECURE_NO_WARNINGS

//########## ヘッダーファイル読み込み ##########5
#include "DxLib.h"

//########## マクロ定義 ##########
#define DEBUG_MODE	FALSE	//デバッグモード

#define GAME_WIDTH	800		//画面の横の大きさ
#define GAME_HEIGHT	600		//画面の縦の大きさ
#define GAME_COLOR	32		//画面のカラービット

#define GAME_WINDOW_NAME	"Kor tall Kanten"		//ウィンドウのタイトル
#define GAME_WINDOW_MODECHANGE	TRUE			//TRUE：ウィンドウモード / FALSE：フルスクリーン

#define SET_WINDOW_ST_MODE_DEFAULT			0	//デフォルト
#define SET_WINDOW_ST_MODE_TITLE_NONE		1	//タイトルバーなし
#define SET_WINDOW_ST_MODE_TITLE_FLAME_NONE	2	//タイトルバーとフレームなし
#define SET_WINDOW_ST_MODE_FLAME_NONE		3	//フレームなし

#define GAME_FPS_SPEED					   60

//マップ関連
#define GAME_MAP_YOKO_SIZE		32		//マップ１つの大きさ(横)
#define GAME_MAP_TATE_SIZE		32		//マップ１つの大きさ(縦)

#define GAME_MAP_BUN_YOKO_CNT	32		//マップの分割数(横)
#define GAME_MAP_BUN_TATE_CNT	41		//マップの分割数(縦)

#define GAME_MAP_YOKO			40	//マップの数(横)
#define GAME_MAP_TATE			40	//マップの数(縦)
#define GAME_MAP_OK_KIND		2	//通行できるマップの種類
#define GAME_MAP_NG_KIND		2	//通行できないマップの種類
#define GAME_MAP_CLEAR			1	//クリアできるマップの種類
#define GAME_MAP_BT_KIND		5	//戦闘するマップの種類
/*###################################手直しここから#######################################################################3*/
#define GAME_MAP_1_PATH			"ゲーム画像\\map\\map_image\\img01.png"	//マップ画像

#define GAME_MAP_CSV_1_SITA		"ゲーム画像\\map\\map1_タイル・レイヤー1.csv"	//マップのCSV
#define GAME_MAP_CSV_1_NAKA		"MAPIMAGE\\mapchip1_map_naka.csv"	//マップのCSV
#define GAME_MAP_CSV_1_UE		"ゲーム画像\\map\\map1_タイル・レイヤー2.csv"		//マップのCSV
/*###############################ここまで########################################################################################3*/
#define GAME_MAP_NAME_1_UE		"MAPDATA_1_UE"		//マップ名称
#define GAME_MAP_NAME_1_NAKA	"MAPDATA_1_NAKA"	//マップ名称
#define GAME_MAP_NAME_1_SITA	"MAPDATA_1_SITA"	//マップ名称


#define MAP_IMG_NAME			"ゲーム画像\\map\\map_image\\map.png"//マップの画像
#define MAP_CSV_1_SIN			"ゲーム画像\\map\\map_image\\atari_atari.csv"//マップのCSV
#define MAP_NAME_1_SIN			"MAPDATA_1_SIN"

//#define GAME_CHARA				"CHARAIMAGE\\chara2.png"	//キャラの画像

//キャラ関連
#define GAME_CHARA				"ゲーム画像\\キャラ\\アキくん.png"	//キャラの画像
#define GAME_CHARA_BUN_YOKO_CNT	6		//キャラの分割数(横)
#define GAME_CHARA_BUN_TATE_CNT	4		//キャラの分割数(縦)
#define GAME_CHARA_YOKO_SIZE	20		//キャラの大きさ(横)
#define GAME_CHARA_TATE_SIZE	28		//キャラの大きさ(縦)
#define GAME_CHARA_MOTION_NUM	24		//キャラの画像数
#define GAME_CHARA_KIND_YOKO	1		//キャラの横の種類
#define GAME_CHARA_KIND_TATE	1		//キャラの縦の種類

#define GAME_CHARA_STARTX		4		//キャラの最初の位置
#define GAME_CHARA_STARTY		1		//キャラの最初の位置
#define GAME_CHARA_SPEED		2		//キャラのスピード

#define GAME_PLAYER_LV_FIRST	1		//プレイヤーの最初のLV
#define GAME_PLAYER_HP_FIRST	10		//プレイヤーの最初のHP
#define GAME_PLAYER_ATK_FIRST	4		//プレイヤーの最初のATK
#define GAME_PLAYER_DEF_FIRST	6		//プレイヤーの最初のDEF

#define GAME_PLAYER_HP_LVUP		5		//プレイヤーのLVUPのHP
#define GAME_PLAYER_ATK_LVUP	4		//プレイヤーのLVUPのATK
#define GAME_PLAYER_DEF_LVUP	3		//プレイヤーのLVUPのDEF

#define GAME_PLAYER_NAME		"勇者"	//プレイヤーの名前
#define GAME_PLAYER_ITEM_MAX	10		//プレイヤーのアイテム保持MAX

//敵関連
#define GAME_ENE_CSV_1				"ENEIMAGE\\enedata.csv"		//敵のCSV

#define GAME_ENE_GRASS_1_IMAGE		"ENEIMAGE\\grass_001.png"	//敵の画像
#define GAME_ENE_GRASS_2_IMAGE		"ENEIMAGE\\grass_002.png"	//敵の画像
#define GAME_ENE_GRASS_3_IMAGE		"ENEIMAGE\\grass_003.png"	//敵の画像
#define GAME_ENE_GRASS_4_IMAGE		"ENEIMAGE\\grass_004.png"	//敵の画像

#define GAME_ENE_KUSA_1_IMAGE		"ENEIMAGE\\kusa_001.png"	//敵の画像
#define GAME_ENE_KUSA_2_IMAGE		"ENEIMAGE\\kusa_002.png"	//敵の画像
#define GAME_ENE_KUSA_3_IMAGE		"ENEIMAGE\\kusa_003.png"	//敵の画像
#define GAME_ENE_KUSA_4_IMAGE		"ENEIMAGE\\kusa_004.png"	//敵の画像
#define GAME_ENE_KUSA_5_IMAGE		"ENEIMAGE\\kusa_005.png"	//敵の画像

#define GAME_ENE_RIVER_1_IMAGE		"ENEIMAGE\\river_001.png"	//敵の画像
#define GAME_ENE_RIVER_2_IMAGE		"ENEIMAGE\\river_002.png"	//敵の画像
#define GAME_ENE_RIVER_3_IMAGE		"ENEIMAGE\\river_003.png"	//敵の画像
#define GAME_ENE_RIVER_4_IMAGE		"ENEIMAGE\\river_004.png"	//敵の画像

#define GAME_ENE_MAOU_1_IMAGE		"ENEIMAGE\\maou_001.png"	//敵の画像
#define GAME_ENE_MAOU_2_IMAGE		"ENEIMAGE\\maou_002.png"	//敵の画像
#define GAME_ENE_MAOU_3_IMAGE		"ENEIMAGE\\maou_003.png"	//敵の画像
#define GAME_ENE_MAOU_4_IMAGE		"ENEIMAGE\\maou_004.png"	//敵の画像
#define GAME_ENE_MAOU_5_IMAGE		"ENEIMAGE\\maou_005.png"	//敵の画像
#define GAME_ENE_MAOU_6_IMAGE		"ENEIMAGE\\maou_006.png"	//敵の画像

#define GAME_ENE_BOSS_IMAGE			"ENEIMAGE\\boss2.png"		//敵の画像

#define GAME_ENE_BATTLE_NUM_MAX		3	//敵が一度に戦闘する最大数
#define GAME_ENE_KIND_MAX			20	//敵の種類の最大数

#define GAME_TIME_SET				30	//時間

//戦闘関連
#define GAME_BT_GRASS_IMAGE			"BATTLEIMAGE\\grass.png"	//戦闘画面の背景
#define GAME_BT_RIVER_IMAGE			"BATTLEIMAGE\\river.png"	//戦闘画面の背景
#define GAME_BT_MAOU_IMAGE			"BATTLEIMAGE\\maou.png"		//戦闘画面の背景
#define GAME_BT_BOSS_IMAGE			"BATTLEIMAGE\\boss.png"		//戦闘画面の背景

//敵のステータス表示場所
#define GAME_BATTLE_TEKI_ACT_WIDTH	200
#define GAME_BATTLE_TEKI_ACT_HEIGHT	60

//自分のステータス表示場所
#define GAME_BATTLE_MY_ST_LEFT		50
#define GAME_BATTLE_MY_ST_TOP		475
#define GAME_BATTLE_MY_ST_RIGHT		250
#define GAME_BATTLE_MY_ST_BOTTOM	575

#define GAME_BATTLE_MY_ST_WIDTH		200

//自分の行動表示場所
#define GAME_BATTLE_MY_ACT_LEFT		275
#define GAME_BATTLE_MY_ACT_TOP		475
#define GAME_BATTLE_MY_ACT_RIGHT	750
#define GAME_BATTLE_MY_ACT_BOTTOM	575

//自分のステータス表示場所[攻撃]
#define GAME_BATTLE_MY_ACT_ATK_LEFT		295
#define GAME_BATTLE_MY_ACT_ATK_TOP		495
#define GAME_BATTLE_MY_ACT_ATK_RIGHT	425
#define GAME_BATTLE_MY_ACT_ATK_BOTTOM	555

//自分のステータス表示場所[アイテム]
#define GAME_BATTLE_MY_ACT_ITEM_LEFT	445
#define GAME_BATTLE_MY_ACT_ITEM_TOP		495
#define GAME_BATTLE_MY_ACT_ITEM_RIGHT	575
#define GAME_BATTLE_MY_ACT_ITEM_BOTTOM	555

//自分のステータス表示場所[逃げる]
#define GAME_BATTLE_MY_ACT_ESC_LEFT		595
#define GAME_BATTLE_MY_ACT_ESC_TOP		495
#define GAME_BATTLE_MY_ACT_ESC_RIGHT	725
#define GAME_BATTLE_MY_ACT_ESC_BOTTOM	555

#define GAME_TITLE_IMAGE				"ゲーム画像\\タイトル\\作品タイトル.png"	//タイトルの画像
#define GAME_TITLE_BACKIMAGE			"ゲーム画像\\タイトル\\タイトル背景お城 (2).jpg" //タイトル背景
#define GAME_CLEAR_IMAGE				"CLEARIMAGE\\clearimage.png"	//ゲームクリアの画像

#define GAME_MUSIC_LEVELUP				"MUSIC\\levelup.mp3"
#define GAME_MUSIC_BATTLE_SELECT		"MUSIC\\battle_select.mp3"
#define GAME_MUSIC_BATTLE_ENTER			"MUSIC\\battle_select_enter.mp3"
#define GAME_MUSIC_BATTLE_ATK			"MUSIC\\battle_atk.mp3"
#define GAME_MUSIC_BATTLE				"MUSIC\\battle.mp3"
#define GAME_MUSIC_BOSS					"MUSIC\\boss.mp3"
#define GAME_MUSIC_TITLE				"MUSIC\\wonderland.wav"
#define GAME_MUSIC_PLAY					"MUSIC\\アホの子.mp3"
#define GAME_MUSIC_BATTLE_ITEM			"MUSIC\\battle_item.mp3"
#define GAME_MUSIC_BATTLE_ESC			"MUSIC\\battle_esc.mp3"
#define GAME_MUSIC_END_SELECT			"MUSIC\\end_select.mp3"
#define GAME_MUSIC_END					"MUSIC\\星屑サラウンド-1chorus-.mp3"

//########## 列挙型 ##########
enum GAME_SCENE {
	GAME_SCENE_TITLE,		//タイトル画面
	GAME_SCENE_DESCRIPTION,
	GAME_SCENE_CHOICE,
	GAME_SCENE_PLAY,		//プレイ画面
	GAME_SCENE_BATTLE,		//戦闘画面
	GAME_SCENE_MOVE_SCENE,	//シーン遷移画面
	GAME_SCENE_END			//エンド画面
};
//################################ここから###############################################
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
};	//キャラの種類の列挙型
//##########################キャラ直す！###########################################3
enum GAME_ENETYPE {
	GAME_ENETYPE_NONE = 0,		//なし
	GAME_ENETYPE_GRASS = 1,		//草
	GAME_ENETYPE_KUSA = 26,		//草２
	GAME_ENETYPE_RIVER = 936,	//川
	GAME_ENETYPE_MAOU = 314,	//魔王城
	GAME_ENETYPE_BOSS = 148		//ボス戦
};

enum GAME_MAE_EFFECT {
	GAME_MAE_EFFECT_FADEIN,		//フェードイン
	GAME_MAE_EFFECT_FADEOUT,	//フェードアウト
};

enum GAME_ACT_KIND {
	GAME_ACT_KIND_NONE,		//なし
	GAME_ACT_KIND_ATK,		//攻撃
	GAME_ACT_KIND_ITEM,		//アイテム
	GAME_ACT_KIND_ESC,		//逃げる
	GAME_ACT_KIND_LVUP,		//レベルアップ
	GAME_ACT_KIND_MAX,		//行動種類終了
};

enum GAME_ITEM_KIND {
	GAME_ITEM_KIND_KAIHUKU_10,		//10回復
	GAME_ITEM_KIND_KAIHUKU_20,		//20回復
	GAME_ITEM_KIND_KAIHUKU_30,		//30回復
	GAME_ITEM_KIND_ICHIGEKI,		//一撃必殺
	GAME_ITEM_KIND_MAX,				//アイテム終了
};

enum GAME_TURN {
	GAME_TURN_NONE,		//なし
	GAME_TURN_MY,		//自分のターン
	GAME_TURN_ENEMY,	//敵のターン
};

enum GAME_END_KIND {
	GAME_END_KIND_NONE,		//最初の状態
	GAME_END_KIND_OVER,		//ゲームオーバ
	GAME_END_KIND_CLEAR,	//ゲームクリア
};

struct STRUCT_MUSIC
{
	int Handle;					//音のハンドル
	char FilePath[128];			//ファイルのパス
	int Playtype;				//音の再生方法
};	//音構造体

//########## 構造体 ##########
struct STRUCT_IMAGE
{
	char FilePath[128];												//ファイルのパス
	int Handle[GAME_MAP_BUN_YOKO_CNT * GAME_MAP_BUN_TATE_CNT];		//画像のハンドル
	int X[GAME_MAP_BUN_YOKO_CNT * GAME_MAP_BUN_TATE_CNT];			//横の位置
	int Y[GAME_MAP_BUN_YOKO_CNT * GAME_MAP_BUN_TATE_CNT];			//縦の位置
	int Width[GAME_MAP_BUN_YOKO_CNT * GAME_MAP_BUN_TATE_CNT];		//横のサイズ
	int Height[GAME_MAP_BUN_YOKO_CNT * GAME_MAP_BUN_TATE_CNT];		//縦のサイズ
	int C_Width[GAME_MAP_BUN_YOKO_CNT * GAME_MAP_BUN_TATE_CNT];		//横の中心位置
	int C_Height[GAME_MAP_BUN_YOKO_CNT * GAME_MAP_BUN_TATE_CNT];	//縦の中心位置

};	//STRUCT_IMAGE構造体

struct STRUCT_MAP_IMAGE
{
	char FilePath[128];												//ファイルのパス
	int Handle;		//画像のハンドル
	int X;			//横の位置
	int Y;			//縦の位置
	int Width;		//横のサイズ
	int Height;		//縦のサイズ
	int C_Width;		//横の中心位置
	int C_Height;	//縦の中心位置

};

struct STRUCT_MAPDATA
{
	char name[64];											//マップの名称	
	int data[GAME_MAP_TATE][GAME_MAP_YOKO];					//マップのCSVデータ
	int mapdata_Init[GAME_MAP_TATE][GAME_MAP_YOKO];			//マップのCSVデータ（最初）

	int Handle[GAME_MAP_BUN_YOKO_CNT * GAME_MAP_BUN_TATE_CNT];	//マップ個々のハンドル
	int X[GAME_MAP_BUN_YOKO_CNT * GAME_MAP_BUN_TATE_CNT];			//横の位置
	int Y[GAME_MAP_BUN_YOKO_CNT * GAME_MAP_BUN_TATE_CNT];			//縦の位置
	int Width[GAME_MAP_BUN_YOKO_CNT * GAME_MAP_BUN_TATE_CNT];		//横のサイズ
	int Height[GAME_MAP_BUN_YOKO_CNT * GAME_MAP_BUN_TATE_CNT];		//縦のサイズ
	int C_Width[GAME_MAP_BUN_YOKO_CNT * GAME_MAP_BUN_TATE_CNT];		//横の中心位置
	int C_Height[GAME_MAP_BUN_YOKO_CNT * GAME_MAP_BUN_TATE_CNT];	//縦の中心位置

	int mapNGKind[GAME_MAP_NG_KIND];						//マップ判定の種類（通行できない）
	int mapOKKind[GAME_MAP_OK_KIND];						//マップ判定の種類（通行できる）
	int mapCLKind[GAME_MAP_CLEAR];							//マップ判定の種類 (クリア）
	int mapBTKind[GAME_MAP_BT_KIND];						//マップ判定の種類（戦闘）
	int mapNGKind_cnt = FALSE;

	RECT rect_NG[GAME_MAP_TATE][GAME_MAP_YOKO];				//当たり判定の領域（通行できない）
	RECT rect_NG_First[GAME_MAP_TATE][GAME_MAP_YOKO];		//当たり判定の領域（通行できない）（最初）

	RECT rect_OK[GAME_MAP_TATE][GAME_MAP_YOKO];				//当たり判定の領域（通行できる）
	RECT rect_OK_First[GAME_MAP_TATE][GAME_MAP_YOKO];		//当たり判定の領域（通行できる）（最初）

	RECT rect_CL[GAME_MAP_TATE][GAME_MAP_YOKO];				//当たり判定の領域（通行できない）
	RECT rect_CL_First[GAME_MAP_TATE][GAME_MAP_YOKO];		//当たり判定の領域（通行できない）（最初）

	RECT rect_BT[GAME_MAP_TATE][GAME_MAP_YOKO];				//当たり判定の領域（戦闘）
	RECT rect_BT_First[GAME_MAP_TATE][GAME_MAP_YOKO];		//当たり判定の領域（戦闘）（最初）

};	//MAPDATA構造体

struct STRUCT_CHARAIMAGE
{
	char FilePath[128];													//ファイルのパス
	int HandleChara[GAME_CHARA_BUN_YOKO_CNT * GAME_CHARA_BUN_TATE_CNT];		//画像のハンドル
	int X[GAME_CHARA_BUN_YOKO_CNT * GAME_CHARA_BUN_TATE_CNT];			//横の位置
	int Y[GAME_CHARA_BUN_YOKO_CNT * GAME_CHARA_BUN_TATE_CNT];			//縦の位置
	int Width[GAME_CHARA_BUN_YOKO_CNT * GAME_CHARA_BUN_TATE_CNT];		//横のサイズ
	int Height[GAME_CHARA_BUN_YOKO_CNT * GAME_CHARA_BUN_TATE_CNT];		//縦のサイズ
	int C_Width[GAME_CHARA_BUN_YOKO_CNT * GAME_CHARA_BUN_TATE_CNT];		//横の中心位置
	int C_Height[GAME_CHARA_BUN_YOKO_CNT * GAME_CHARA_BUN_TATE_CNT];	//縦の中心位置
};	//STRUCT_CHARAIMAGE構造体

struct STRUCT_CHARADATA
{
	STRUCT_CHARAIMAGE charaimage;		//画像
	int Handle[GAME_CHARA_MOTION_NUM];	//画像のハンドル
	int X;								//横の位置
	int Y;								//縦の位置
	int Width;							//横のサイズ
	int Height;							//縦のサイズ
	int C_Width;						//横の中心位置
	int C_Height;						//縦の中心位置
	int NowHandleNum;					//現在の画像のハンドル
	int NowHandleCnt;					//現在のハンドルカウント
	int NowHandleCntMAX;				//現在のハンドルカウントMAX

	int Speed;							//速度
	int MoveDistX;						//移動距離X
	int MoveDistY;						//移動距離Y

	BOOL CanMoveUp;						//上に行けるか
	BOOL CanMoveDown;					//下に行けるか
	BOOL CanMoveLeft;					//左に行けるか
	BOOL CanMoveRight;					//右に行けるか

	BOOL ScrollOK_X;					//スクロールできるかどうか
	BOOL ScrollOK_Y;					//スクロールできるかどうか

	int atariX;							//当たり判定のX位置
	int atariY;							//当たり判定のY位置
	int atariWidth;						//当たり判定の幅
	int atariHeight;					//当たり判定の高さ
	RECT atariRect;						//当たり判定の矩形領域

	int eneType;						//敵の種類
	int eneBattleCnt;					//敵の戦う数

	char name[255];						//名前
	int HP;
	int ATK;
	int DEF;

	int LV;
	int HP_MAX;
	int ATK_MAX;
	int DEF_MAX;
	int item[(int)GAME_ITEM_KIND_MAX][GAME_PLAYER_ITEM_MAX];	//持っているアイテム数

	RECT rect_st;	//情報の領域

	RECT rect_act_atk;	//情報の領域[攻撃]
	RECT rect_act_item;	//情報の領域[アイテム]
	RECT rect_act_esc;	//情報の領域[逃げる]

	RECT rect_act;		//行動の領域

	int act_kind;				//行動の種類;
	BOOL IsActKeyDown_left;		//行動を押したとき(左)
	BOOL IsActKeyDown_right;	//行動を押したとき(右)

	int battle_turn;			//ターン情報	
	BOOL IsEsc;					//逃げられるか
	BOOL IsActMsgStart;			//行動メッセージ開始
	BOOL IsActMsgEnd;			//行動メッセージ終了
	int NowActMsgCnt;			//行動メッセージカウント
	int NowActMsgCntMAX;		//行動メッセージカウントMAX

	int damageCalc;				//ダメージ計算

	BOOL IsActLvupStart;		//LVUPメッセージ開始
	BOOL IsActLvupEnd;			//LVUPメッセージ終了
	int NowActLvupCnt;			//LVUPメッセージカウント
	int NowActLvupntMAX;		//LVUPメッセージカウントMAX

	BOOL IsAlive;		//生きているか

	int gameEndKind;	//ゲーム終了の状態

	int EndLV;			//終了時点でのLV
	int EndHP;			//終了時点でのHP
	int EndATK;			//終了時点でのATK
	int EndDEF;			//終了時点でのDEF

};	//STRUCT_CHARADATA構造体

struct STRUCT_ENEDATA
{
	int Handle;							//画像のハンドル
	int X;								//横の位置
	int Y;								//縦の位置
	int Width;							//横のサイズ
	int Height;							//縦のサイズ
	int C_Width;						//横の中心位置
	int C_Height;						//縦の中心位置

	int No;
	int LV;
	char name[255];
	int enetype;						//敵のタイプ
	int HP;
	int ATK;
	int DEF;

	int HP_MAX;
	int ATK_MAX;
	int DEF_MAX;
	int item[(int)GAME_ITEM_KIND_MAX][GAME_PLAYER_ITEM_MAX];	//持っているアイテム数

	RECT rect_st;	//情報の領域
	RECT rect_act;	//行動の領域

	BOOL IsAlive;	//生きているか

	int damageCalc;	//ダメージ計算

};	//STRUCT_ENEDATA構造体

struct STRUCT_SCENE_MOVE
{
	int kind;
	int DrawCnt;
	int DrawCntMax;
	double ToukaPercent;
	int DeleteX;
	int DeleteY;
}; //STRUCT_SCENE_MOVE構造体


//########## 名前の再定義 ##########
typedef STRUCT_MUSIC MUSIC;
typedef STRUCT_IMAGE IMAGE;
typedef STRUCT_MAP_IMAGE MAP_IMG;
typedef STRUCT_MAPDATA MAPDATA;
typedef STRUCT_CHARAIMAGE CHARAIMAGE;
typedef STRUCT_CHARADATA CHARADATA;
typedef STRUCT_ENEDATA ENEDATA;
typedef STRUCT_SCENE_MOVE SCENE_MOVE;

//########## グローバル変数 ##########

//ウィンドウ関係
BOOL IsWM_CREATE = FALSE;				//WM_CREATEが正常に動作したか判断する

//FPS関連
int StartTimeFps;						//測定開始時刻
int CountFps;							//カウンタ
float CalcFps;							//計算結果
int SampleNumFps = GAME_FPS_SPEED;		//平均を取るサンプル数

//キーボード関連
char AllKeyState[256];			//すべてのキーの状態が入る

//シーン関連
int GameSceneNow = (int)GAME_SCENE_TITLE;	//最初のゲーム画面をタイトルに設定

//マップ関連
IMAGE Image_map;
MAPDATA mapData_sita;	//下のマップ
MAPDATA mapData_naka;	//中のマップ
MAPDATA mapData_ue;		//上のマップ
MAPDATA mapData_sin;

MAP_IMG Map_Image;		//マップ画像

IMAGE image_grass;		//戦闘画面
IMAGE image_river;		//戦闘画面
IMAGE image_maou;		//戦闘画面
IMAGE image_boss;		//戦闘画面

IMAGE image_title;		//タイトル画面
IMAGE image_backtitle;	//タイトル背景
IMAGE image_clear;		//クリア画面

//スクロール関係
int ScrollCntYoko = 0;	//スクロールカウンタ(横)
int ScrollCntTate = 0;	//スクロールカウンタ(縦)

//キャラ系
CHARAIMAGE CharaImage;	//キャラの画像
CHARADATA	Myplayer;	//キャラのデータ

//敵系
ENEDATA enedata[GAME_ENE_KIND_MAX];					//敵のデータ
ENEDATA eneBattleNum_INIT;							//戦う敵(初期化用)
ENEDATA eneBattle[GAME_ENE_BATTLE_NUM_MAX];		//戦う敵の数

//プレイヤーのイメージ画像の番号を設定する
int PlayerImageNum[GAME_CHARA_MOTION_NUM];

//戦闘前効果
SCENE_MOVE sceneMove;

//ゲームエンドでの選択肢
RECT rectEndCon{ 100,100,300,500 };
RECT rectEndEnd{ 500,100,700,500 };

//ゲームエンドでの選択カウント
int EndConCnt = 0;
int EndConCntMAX = 120;

int EndEndCnt = 0;
int EndEndCntMAX = 120;
/*追加ここから*/
int SelectTitleNum = 0;
int play_scene;
int SelectSteageNum = 0;
int SelectEndNum = 0;
/*追加ここまで*/
int MY_RANGE_RAND(int, int);	//範囲を指定してrandを行う

int SceneBefore;	//以前のシーン
int SceneNext;		//次のシーン

int FontDefault;
int FontBig;
int FontFutsu;

//音を読み込む
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

//########## プロトタイプ宣言 ##########

VOID MY_FPS_UPDATE(VOID);			//FPS値を計測、更新する関数
VOID MY_FPS_DRAW(VOID);				//FPS値を描画する関数
VOID MY_FPS_WAIT(VOID);				//FPS値を計測し、待つ関数

VOID MY_ALL_KEYDOWN_UPDATE(VOID);	//キーの入力状態を更新する関数

VOID MY_GAME_TITLE(VOID);			//タイトル画面の関数
VOID MY_GAME_TITLE_DRAW(VOID);		//タイトル画面描画の関数
VOID MY_GAME_BACK_DRAW(VOID);		//背景描画の関数
VOID MY_GAME_PLAY(VOID);			//プレイ画面の関数
VOID MY_GAME_PLAY_DRAW(VOID);		//プレイ画面描画の関数
VOID MY_GAME_BATTLE(VOID);			//戦闘画面の関数
VOID MY_GAME_BATTLE_DRAW(VOID);		//戦闘画面描画の関数
BOOL MY_GAME_SCENE_MOVE(int);		//シーン移動画面の関数
VOID MY_GAME_END(VOID);				//エンド画面の関数
VOID MY_GAME_END_DRAW(VOID);		//エンド画面描画の関数

BOOL MY_PLAY_INIT(VOID);			//プレイ画面初期化関数

VOID MY_BATTLE_ENEMY_INIT(int, int);		//戦闘前に敵を初期化する関数

VOID MY_GAME_DESCRIPTION(VOID);

VOID MY_GAME_CHOICE(VOID);

BOOL MY_MAP_READ_CSV_UE_KIND_SET(MAPDATA *);	//マップ(上)判定の種類を設定する
BOOL MY_MAP_READ_CSV_NAKA_KIND_SET(MAPDATA *);	//マップ(中)判定の種類を設定する
BOOL MY_MAP_READ_CSV_SITA_KIND_SET(MAPDATA *);	//マップ(下)判定の種類を設定する
BOOL MY_MAP_READ_CSV_SIN_KIND_SET(MAPDATA *);//マップ判定の種類を設定する
BOOL MY_MAP_READ_CSV_NUM(MAPDATA *, const char *, const char *);				//ゲームマップのCSVを読み込む関数

BOOL MY_ENEMY_READ_CSV(ENEDATA *, const char *, int);	//敵の情報を設定する

int MY_LOAD_BACKGROUND(IMAGE *, const char *);										//背景を読み込む設定をする関数

int LOAD_IMG(MAP_IMG *, const char *);										//画像を読み込む設定をする関数

VOID DRAW_MAP(MAP_IMG *, int, int);		//	マップ描画


int MY_LOAD_ENEMY(ENEDATA *, const char *);									//敵を読み込む設定をする関数

//BOOL MY_MAP_LOAD_BUNKATSU(MAPDATA *, int, int, int, int, int, const char *);	//MAPを分割して読み込む設定をする関数

VOID MY_PLAY_MAP_DRAW(MAPDATA);			//マップを描画する関数
VOID MY_PLAY_MAP_DRAW_ATARI(MAPDATA *, MAPDATA *, MAPDATA *);	//マップの当たり判定を描画する関数
VOID PLAY_MAP_DRAW_ATARI(MAPDATA *);		//マップの当たり判定

BOOL MY_CHARA_LOAD_BUNKATSU(CHARAIMAGE*, int, int, int, int, int, const char *);	//キャラ画像を分割して読み込む設定をする関数

BOOL MY_PLAYER_INIT(CHARADATA *, CHARAIMAGE, int *, int, int, int);	//プレイヤーを初期化する関数
VOID MY_PLAY_PLAYER_DRAW(CHARADATA);								//プレイヤーを表示する関数

VOID MY_PLAY_PLAYER_OPERATION(VOID);								//プレイヤーを操作する関数
BOOL MY_PLAY_PLAYER_OPERATION_KEY(int *, int *);					//プレイヤーを操作する(キー操作)関数
VOID MY_PLAY_PLAYER_OPERATION_ENCOUNTER(int *, int *);				//プレイヤーを操作する(敵出現)関数

VOID MY_SET_PLAYER_ATARI(CHARADATA *);	//プレイヤーの当たり判定の領域を設定する関数

BOOL MY_CHECK_RECT_ATARI(RECT, RECT);	// 領域の当たり判定をする関数
BOOL MY_CHECK_RECT_ATARI_CHARA_MAP_ATARIBASHO(RECT, RECT map[GAME_MAP_TATE][GAME_MAP_YOKO], int *, int *);

BOOL MY_MUSIC_LOAD(MUSIC *, const char *);	//音を読み込む設定をする関数

BOOL MY_GAME_NOWLOADING(VOID);				//ゲームで使用する、音楽や画像などを読み込む関数
BOOL MY_GAME_IN_MUGENLOOP(VOID);			//無限ループ内で動作する関数
VOID MY_GAME_DELETE(VOID);					//ゲーム内で読み込んだ画像や音楽を削除する関数
/*******************MenuElement達**********************/
typedef struct {
	int x, y;
	char name[128];
}MenuElement_t, MenuElement_y, MenuElement_z;

MenuElement_t MenuElement[3] = {
	{200,300,"ゲーム操作説明"},
	{220,320,"ゲームスタート"},
	//{220,300,"Virtual to LIVE"},
	//{220,320,"Fam Fam Time!"},
	//{220,340,"Buzz!!りムーヴメント"},
	{220,340,"ゲームを終わる"},
};

MenuElement_z Menu[3] = {
	{200,300,"map1"},
	{220,320,"map2"},
	{220,340,"map3"},
};

MenuElement_y MenuElemen[2] = {
	{100,100,"もう一度"},
	{120,150,"タイトルへ戻る"},
};

double GET_TIME = 0;
double MY_GAME_GET_TIME = 0;

int FontHandle_Time = 0;

int time = 0;

//########## プログラムで最初に実行される関数 ##########
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	int IsLoad = FALSE;		//音楽や画像などを読み込めたか確認する変数

	ChangeWindowMode(GAME_WINDOW_MODECHANGE);					//ウィンドウモードに設定
	SetGraphMode(GAME_WIDTH, GAME_HEIGHT, GAME_COLOR);			//指定の数値で画面を表示する

	SetWindowStyleMode(SET_WINDOW_ST_MODE_DEFAULT);				//タイトルバーあり

	SetMainWindowText(TEXT(GAME_WINDOW_NAME));					//タイトルの文字

	if (DxLib_Init() == -1) { return -1; }						//ＤＸライブラリ初期化処理

	SetDrawScreen(DX_SCREEN_BACK);								//Draw系関数は裏画面に描画

	//MY_MAP_READ_CSV_UE_KIND_SET(&mapData_ue);		//マップの上の種類を設定
	//MY_MAP_READ_CSV_NAKA_KIND_SET(&mapData_naka);	//マップの中の種類を設定
	//MY_MAP_READ_CSV_SITA_KIND_SET(&mapData_sita);	//マップの下の種類を設定
	MY_MAP_READ_CSV_SIN_KIND_SET(&mapData_sin);

	//MY_MAP_READ_CSV_NUM(&mapData_ue, GAME_MAP_CSV_1_UE, GAME_MAP_NAME_1_UE);		//マップ１の上を読み込み、当たり判定の領域を作る
	//MY_MAP_READ_CSV_NUM(&mapData_naka, GAME_MAP_CSV_1_NAKA, GAME_MAP_NAME_1_NAKA);	//マップ１の中を読み込み、当たり判定の領域を作る
	//MY_MAP_READ_CSV_NUM(&mapData_sita, GAME_MAP_CSV_1_SITA, GAME_MAP_NAME_1_SITA);	//マップ１の下を読み込み、当たり判定の領域を作る
	MY_MAP_READ_CSV_NUM(&mapData_sin, MAP_CSV_1_SIN, MAP_NAME_1_SIN);//マップのcsvを読み込み、当たり判定の領域を作る

	LOAD_IMG(&Map_Image, MAP_IMG_NAME);		//マップ画像読み込み

	//if (MY_MAP_LOAD_BUNKATSU(&mapData_ue, GAME_MAP_BUN_YOKO_CNT * GAME_MAP_BUN_TATE_CNT, GAME_MAP_BUN_YOKO_CNT, GAME_MAP_BUN_TATE_CNT, 32, 32, GAME_MAP_1_PATH) == FALSE) { MessageBox(NULL, GAME_MAP_1_PATH, "NotFound", MB_OK); return -1; }		//MAPを読み込む
	//if (MY_MAP_LOAD_BUNKATSU(&mapData_naka, GAME_MAP_BUN_YOKO_CNT * GAME_MAP_BUN_TATE_CNT, GAME_MAP_BUN_YOKO_CNT, GAME_MAP_BUN_TATE_CNT, 32, 32, GAME_MAP_1_PATH) == FALSE) { MessageBox(NULL, GAME_MAP_1_PATH, "NotFound", MB_OK); return -1; }	//MAPを読み込む
	//if (MY_MAP_LOAD_BUNKATSU(&mapData_sita, GAME_MAP_BUN_YOKO_CNT * GAME_MAP_BUN_TATE_CNT, GAME_MAP_BUN_YOKO_CNT, GAME_MAP_BUN_TATE_CNT, 32, 32, GAME_MAP_1_PATH) == FALSE) { MessageBox(NULL, GAME_MAP_1_PATH, "NotFound", MB_OK); return -1; }	//MAPを読み込む

	//if (MY_MAP_LOAD_BUNKATSU(&mapData_sin, GAME_MAP_BUN_YOKO_CNT * GAME_MAP_BUN_TATE_CNT, GAME_MAP_BUN_YOKO_CNT, GAME_MAP_BUN_TATE_CNT, 32, 32, GAME_MAP_1_PATH) == FALSE) { MessageBox(NULL, GAME_MAP_1_PATH, "NotFound", MB_OK); return -1; }	//MAPを読み込む

	if (MY_CHARA_LOAD_BUNKATSU(&CharaImage, GAME_CHARA_BUN_YOKO_CNT * GAME_CHARA_BUN_TATE_CNT, GAME_CHARA_BUN_YOKO_CNT, GAME_CHARA_BUN_TATE_CNT, GAME_CHARA_YOKO_SIZE, GAME_CHARA_TATE_SIZE, GAME_CHARA) == FALSE) { MessageBox(NULL, GAME_CHARA, "NotFound", MB_OK); return -1; }	//GAME_CHARA_1を読み込む

	//▼▼▼▼▼ プログラム追加ここから ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼
	//[01]ゲームで使用する、音楽や画像などを読み込む
	//▲▲▲▲▲ プログラム追加ここまで ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲
	IsLoad = MY_GAME_NOWLOADING();

	if (IsLoad == FALSE) { return -1; }	//読み込みに失敗したら、強制終了

	int IsInLoop = FALSE;		//無限ループ内で動作する処理が正しく行われているか確認する変数

	//######################追加2/4###############################
	FontHandle_Time = CreateFontToHandle(NULL, 50, 9);

	while (TRUE)	//無限ループ
	{
		//▼▼▼▼▼ プログラム追加ここから ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼
		//[03]無限ループ内で動作する処理を行わせる
		//▲▲▲▲▲ プログラム追加ここまで ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲
		IsInLoop = MY_GAME_IN_MUGENLOOP();

		if (IsInLoop == FALSE) { break; }			//処理に失敗したら、強制終了
	}

	//▼▼▼▼▼ プログラム追加ここから ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼
	//[02]ゲーム内で読み込んだ画像や音楽を削除する
	//▲▲▲▲▲ プログラム追加ここまで ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲
	MY_GAME_DELETE();

	DxLib_End();		//ＤＸライブラリ使用の終了処理

	return 0;
}


//########## ゲームで使用する、音楽や画像などを読み込む関数 ##########
BOOL MY_GAME_NOWLOADING(VOID)
{
	//***背景を読み込む***
	if (MY_LOAD_BACKGROUND(&image_title, GAME_TITLE_IMAGE) == FALSE) { MessageBox(NULL, GAME_TITLE_IMAGE, "NotFound", MB_OK); return FALSE; }				//IMAGEを読み込む
	if (MY_LOAD_BACKGROUND(&image_backtitle, GAME_TITLE_BACKIMAGE) == FALSE) { MessageBox(NULL, GAME_TITLE_BACKIMAGE, "NotFound", MB_OK); return FALSE; }				//IMAGEを読み込む
	if (MY_LOAD_BACKGROUND(&image_clear, GAME_CLEAR_IMAGE) == FALSE) { MessageBox(NULL, GAME_CLEAR_IMAGE, "NotFound", MB_OK); return FALSE; }				//IMAGEを読み込む
	if (MY_LOAD_BACKGROUND(&image_grass, GAME_BT_GRASS_IMAGE) == FALSE) { MessageBox(NULL, GAME_BT_GRASS_IMAGE, "NotFound", MB_OK); return FALSE; }			//IMAGEを読み込む
	if (MY_LOAD_BACKGROUND(&image_river, GAME_BT_RIVER_IMAGE) == FALSE) { MessageBox(NULL, GAME_BT_RIVER_IMAGE, "NotFound", MB_OK); return FALSE; }			//IMAGEを読み込む
	if (MY_LOAD_BACKGROUND(&image_maou, GAME_BT_MAOU_IMAGE) == FALSE) { MessageBox(NULL, GAME_BT_MAOU_IMAGE, "NotFound", MB_OK); return FALSE; }			//IMAGEを読み込む
	if (MY_LOAD_BACKGROUND(&image_boss, GAME_BT_BOSS_IMAGE) == FALSE) { MessageBox(NULL, GAME_BT_BOSS_IMAGE, "NotFound", MB_OK); return FALSE; }			//IMAGEを読み込む

	//***敵の画像を読み込む***
	if (MY_LOAD_ENEMY(&enedata[0], GAME_ENE_GRASS_1_IMAGE) == FALSE) { MessageBox(NULL, GAME_ENE_GRASS_1_IMAGE, "NotFound", MB_OK); return FALSE; }		//IMAGEを読み込む
	if (MY_LOAD_ENEMY(&enedata[1], GAME_ENE_GRASS_2_IMAGE) == FALSE) { MessageBox(NULL, GAME_ENE_GRASS_2_IMAGE, "NotFound", MB_OK); return FALSE; }		//IMAGEを読み込む
	if (MY_LOAD_ENEMY(&enedata[2], GAME_ENE_GRASS_3_IMAGE) == FALSE) { MessageBox(NULL, GAME_ENE_GRASS_3_IMAGE, "NotFound", MB_OK); return FALSE; }		//IMAGEを読み込む
	if (MY_LOAD_ENEMY(&enedata[3], GAME_ENE_GRASS_4_IMAGE) == FALSE) { MessageBox(NULL, GAME_ENE_GRASS_4_IMAGE, "NotFound", MB_OK); return FALSE; }		//IMAGEを読み込む

	if (MY_LOAD_ENEMY(&enedata[4], GAME_ENE_KUSA_1_IMAGE) == FALSE) { MessageBox(NULL, GAME_ENE_KUSA_1_IMAGE, "NotFound", MB_OK); return FALSE; }			//IMAGEを読み込む
	if (MY_LOAD_ENEMY(&enedata[5], GAME_ENE_KUSA_2_IMAGE) == FALSE) { MessageBox(NULL, GAME_ENE_KUSA_2_IMAGE, "NotFound", MB_OK); return FALSE; }			//IMAGEを読み込む
	if (MY_LOAD_ENEMY(&enedata[6], GAME_ENE_KUSA_3_IMAGE) == FALSE) { MessageBox(NULL, GAME_ENE_KUSA_3_IMAGE, "NotFound", MB_OK); return FALSE; }			//IMAGEを読み込む
	if (MY_LOAD_ENEMY(&enedata[7], GAME_ENE_KUSA_4_IMAGE) == FALSE) { MessageBox(NULL, GAME_ENE_KUSA_4_IMAGE, "NotFound", MB_OK); return FALSE; }			//IMAGEを読み込む
	if (MY_LOAD_ENEMY(&enedata[8], GAME_ENE_KUSA_5_IMAGE) == FALSE) { MessageBox(NULL, GAME_ENE_KUSA_5_IMAGE, "NotFound", MB_OK); return FALSE; }			//IMAGEを読み込む

	if (MY_LOAD_ENEMY(&enedata[9], GAME_ENE_RIVER_1_IMAGE) == FALSE) { MessageBox(NULL, GAME_ENE_RIVER_1_IMAGE, "NotFound", MB_OK); return FALSE; }			//IMAGEを読み込む
	if (MY_LOAD_ENEMY(&enedata[10], GAME_ENE_RIVER_2_IMAGE) == FALSE) { MessageBox(NULL, GAME_ENE_RIVER_2_IMAGE, "NotFound", MB_OK); return FALSE; }		//IMAGEを読み込む
	if (MY_LOAD_ENEMY(&enedata[11], GAME_ENE_RIVER_3_IMAGE) == FALSE) { MessageBox(NULL, GAME_ENE_RIVER_3_IMAGE, "NotFound", MB_OK); return FALSE; }		//IMAGEを読み込む
	if (MY_LOAD_ENEMY(&enedata[12], GAME_ENE_RIVER_4_IMAGE) == FALSE) { MessageBox(NULL, GAME_ENE_RIVER_4_IMAGE, "NotFound", MB_OK); return FALSE; }		//IMAGEを読み込む

	if (MY_LOAD_ENEMY(&enedata[13], GAME_ENE_MAOU_1_IMAGE) == FALSE) { MessageBox(NULL, GAME_ENE_MAOU_1_IMAGE, "NotFound", MB_OK); return FALSE; }		//IMAGEを読み込む
	if (MY_LOAD_ENEMY(&enedata[14], GAME_ENE_MAOU_2_IMAGE) == FALSE) { MessageBox(NULL, GAME_ENE_MAOU_2_IMAGE, "NotFound", MB_OK); return FALSE; }		//IMAGEを読み込む
	if (MY_LOAD_ENEMY(&enedata[15], GAME_ENE_MAOU_3_IMAGE) == FALSE) { MessageBox(NULL, GAME_ENE_MAOU_3_IMAGE, "NotFound", MB_OK); return FALSE; }		//IMAGEを読み込む
	if (MY_LOAD_ENEMY(&enedata[16], GAME_ENE_MAOU_4_IMAGE) == FALSE) { MessageBox(NULL, GAME_ENE_MAOU_4_IMAGE, "NotFound", MB_OK); return FALSE; }		//IMAGEを読み込む
	if (MY_LOAD_ENEMY(&enedata[17], GAME_ENE_MAOU_5_IMAGE) == FALSE) { MessageBox(NULL, GAME_ENE_MAOU_5_IMAGE, "NotFound", MB_OK); return FALSE; }		//IMAGEを読み込む
	if (MY_LOAD_ENEMY(&enedata[18], GAME_ENE_MAOU_6_IMAGE) == FALSE) { MessageBox(NULL, GAME_ENE_MAOU_6_IMAGE, "NotFound", MB_OK); return FALSE; }		//IMAGEを読み込む

	if (MY_LOAD_ENEMY(&enedata[19], GAME_ENE_BOSS_IMAGE) == FALSE) { MessageBox(NULL, GAME_ENE_BOSS_IMAGE, "NotFound", MB_OK); return FALSE; }			//IMAGEを読み込む

	//敵のデータを読み込む
	if (MY_ENEMY_READ_CSV(enedata, GAME_ENE_CSV_1, GAME_ENE_KIND_MAX) == FALSE) { MessageBox(NULL, GAME_ENE_CSV_1, "NotFound", MB_OK); return FALSE; }		//敵の情報を読み込む

	//音を読み込む
	if (MY_MUSIC_LOAD(&MUSIC_MY_BGM_BATTLE, GAME_MUSIC_BATTLE) == FALSE) { MessageBox(NULL, GAME_MUSIC_BATTLE, "NotFound", MB_OK); return FALSE; }							//MUSICを読み込む
	if (MY_MUSIC_LOAD(&MUSIC_MY_SE_BATTLE_SELECT, GAME_MUSIC_BATTLE_SELECT) == FALSE) { MessageBox(NULL, GAME_MUSIC_BATTLE_SELECT, "NotFound", MB_OK); return FALSE; }		//MUSICを読み込む
	if (MY_MUSIC_LOAD(&MUSIC_MY_SE_BATTLE_ENTER, GAME_MUSIC_BATTLE_ENTER) == FALSE) { MessageBox(NULL, GAME_MUSIC_BATTLE_ENTER, "NotFound", MB_OK); return FALSE; }			//MUSICを読み込む
	if (MY_MUSIC_LOAD(&MUSIC_MY_SE_BATTLE_ATK, GAME_MUSIC_BATTLE_ATK) == FALSE) { MessageBox(NULL, GAME_MUSIC_BATTLE_ATK, "NotFound", MB_OK); return FALSE; }				//MUSICを読み込む
	if (MY_MUSIC_LOAD(&MUSIC_MY_BGM_BOSS, GAME_MUSIC_BOSS) == FALSE) { MessageBox(NULL, GAME_MUSIC_BOSS, "NotFound", MB_OK); return FALSE; }								//MUSICを読み込む
	if (MY_MUSIC_LOAD(&MUSIC_MY_SE_LEVELUP, GAME_MUSIC_LEVELUP) == FALSE) { MessageBox(NULL, GAME_MUSIC_LEVELUP, "NotFound", MB_OK); return FALSE; }						//MUSICを読み込む
	if (MY_MUSIC_LOAD(&MUSIC_MY_BGM_PLAY, GAME_MUSIC_PLAY) == FALSE) { MessageBox(NULL, GAME_MUSIC_PLAY, "NotFound", MB_OK); return FALSE; }								//MUSICを読み込む
	if (MY_MUSIC_LOAD(&MUSIC_MY_BGM_TITLE, GAME_MUSIC_TITLE) == FALSE) { MessageBox(NULL, GAME_MUSIC_BATTLE_ITEM, "NotFound", MB_OK); return FALSE; }						//MUSICを読み込む
	if (MY_MUSIC_LOAD(&MUSIC_MY_SE_BATTLE_ITEM, GAME_MUSIC_BATTLE_ITEM) == FALSE) { MessageBox(NULL, GAME_MUSIC_BATTLE_ITEM, "NotFound", MB_OK); return FALSE; }			//MUSICを読み込む
	if (MY_MUSIC_LOAD(&MUSIC_MY_SE_BATTLE_ESC, GAME_MUSIC_BATTLE_ESC) == FALSE) { MessageBox(NULL, GAME_MUSIC_BATTLE_ESC, "NotFound", MB_OK); return FALSE; }				//MUSICを読み込む
	if (MY_MUSIC_LOAD(&MUSIC_MY_SE_END_SELECT, GAME_MUSIC_END_SELECT) == FALSE) { MessageBox(NULL, GAME_MUSIC_END_SELECT, "NotFound", MB_OK); return FALSE; }				//MUSICを読み込む
	if (MY_MUSIC_LOAD(&MUSIC_MY_BGM_END, GAME_MUSIC_END) == FALSE) { MessageBox(NULL, GAME_MUSIC_END, "NotFound", MB_OK); return FALSE; }									//MUSICを読み込む

	//フォント(文字の種類)を読み込む
	FontDefault = CreateFontToHandle("MS ゴシック", 16, 8);	if (FontDefault == -1) { return FALSE; }	//通常フォント
	FontBig = CreateFontToHandle("Impact", 90, 1);			if (FontBig == -1) { return FALSE; }		//大きなフォント
	FontFutsu = CreateFontToHandle("Impact", 48, 1);		if (FontFutsu == -1) { return FALSE; }		//普通なフォント

}

//########## ゲーム内で読み込んだ画像や音楽を削除する関数 ##########
VOID MY_GAME_DELETE(VOID)
{
	//マップのハンドルを削除
	for (int mapCnt = 0; mapCnt < GAME_MAP_BUN_YOKO_CNT * GAME_MAP_BUN_TATE_CNT; mapCnt++)
	{
		DeleteGraph(mapData_ue.Handle[mapCnt]);
		DeleteGraph(mapData_sita.Handle[mapCnt]);
		DeleteGraph(mapData_sin.Handle[mapCnt]);
	}

	//敵のハンドルを削除
	for (int eneCnt = 0; eneCnt < GAME_ENE_KIND_MAX; eneCnt++)
	{
		DeleteGraph(enedata[eneCnt].Handle);
	}

	//画像のハンドルを削除
	DeleteGraph(image_title.Handle[0]);
	DeleteGraph(image_backtitle.Handle[0]);
	DeleteGraph(image_clear.Handle[0]);
	DeleteGraph(image_grass.Handle[0]);
	DeleteGraph(image_river.Handle[0]);
	DeleteGraph(image_maou.Handle[0]);
	DeleteGraph(image_boss.Handle[0]);

	//フォントハンドルを削除
	DeleteFontToHandle(FontDefault);
	DeleteFontToHandle(FontBig);
	DeleteFontToHandle(FontFutsu);

	//音のハンドルを削除
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

//########## ゲームでの無限ループ内の関数 ##########
BOOL MY_GAME_IN_MUGENLOOP(VOID)
{
	if (ProcessMessage() != 0) { return FALSE; }	//メッセージ処理の結果がエラーのとき、強制終了

	if (ClearDrawScreen() != 0) { return FALSE; }	//画面を消去できなかったとき、強制終了

	MY_ALL_KEYDOWN_UPDATE();				//キーの状態を取得

	if (GameSceneNow != (int)GAME_SCENE_MOVE_SCENE)
	{
		SceneBefore = GameSceneNow;	//この時点でのシーンを取得
	}

	GET_TIME = GetNowCount();

	//シーン選択
	switch (GameSceneNow)
	{
	case (int)GAME_SCENE_TITLE:	//タイトル画面の処理ここから

		MY_GAME_TITLE();	//タイトル画面の処理

		break;	//タイトル画面の処理ここまで

//********************************追加ここから*****************************************
	case(int)GAME_SCENE_DESCRIPTION:

		MY_GAME_DESCRIPTION();

		break;

	case GAME_SCENE_CHOICE:

		MY_GAME_CHOICE();

		break;
		//****************************************************ここまで*******************************************

	case (int)GAME_SCENE_PLAY:	//プレイ画面の処理ここから

		MY_GAME_PLAY();		//プレイ画面の処理

		break;	//プレイ画面の処理ここまで
	case (int)GAME_SCENE_BATTLE:	//戦闘画面の処理ここから

		//MY_GAME_BATTLE();		//戦闘画面の処理

		break;	//戦闘画面の処理ここまで

	case (int)GAME_SCENE_MOVE_SCENE:	//シーン移動画面の処理ここから

		if (MY_GAME_SCENE_MOVE(SceneBefore) == TRUE)	//シーン移動画面の処理
		{
			if (SceneBefore == (int)GAME_SCENE_END)	//エンド画面で画面遷移するとき
			{
				if (Myplayer.gameEndKind == (int)GAME_END_KIND_OVER)	//ゲームオーバーのとき
				{
					if (MY_PLAY_INIT() == TRUE)		//プレイ画面初期化
					{
						//私は優しいので、ステータスを全回復させて上げましょう。
						Myplayer.LV = Myplayer.EndLV;
						Myplayer.HP = Myplayer.HP_MAX = Myplayer.EndHP;
						Myplayer.ATK = Myplayer.ATK_MAX = Myplayer.EndATK;
						Myplayer.DEF = Myplayer.DEF_MAX = Myplayer.EndDEF;
					}
				}
			}

			GameSceneNow = SceneBefore = SceneNext;	//シーンを次の画面にする
		}
		break;	//シーン移動画面の処理ここまで

	case (int)GAME_SCENE_END:	//エンド画面の処理ここから

		MY_GAME_END();		//エンド画面の処理

		break;	//エンド画面の処理ここまで

	default:

		break;

	}

	if (GameSceneNow != (int)GAME_SCENE_MOVE_SCENE)
	{
		SceneNext = GameSceneNow;	//この時点でのシーンを取得

		if (SceneBefore != SceneNext)	//シーンが違うとき、画面移動演出
		{
			sceneMove.DrawCnt = 0;
			sceneMove.DrawCntMax = 30;
			sceneMove.DeleteX = 0;
			sceneMove.DeleteY = 0;
			sceneMove.kind = (int)GAME_MAE_EFFECT_FADEIN;	//フェードアウト

			GameSceneNow = (int)GAME_SCENE_MOVE_SCENE;	//シーン移動画面へ
		}

	}

	MY_FPS_UPDATE();	//FPSの処理[更新]

	MY_FPS_DRAW();		//FPSの処理[描画]

	ScreenFlip();		//モニタのリフレッシュレートの速さで裏画面を再描画

	MY_FPS_WAIT();		//FPSの処理[待つ]

	return TRUE;
}

//########## FPS値を計測、更新する関数 ##########
VOID MY_FPS_UPDATE(VOID)
{
	if (CountFps == 0) //1フレーム目なら時刻を記憶
	{
		StartTimeFps = GetNowCount();
	}

	if (CountFps == SampleNumFps) //60フレーム目なら平均を計算
	{
		int now = GetNowCount();
		CalcFps = 1000.f / ((now - StartTimeFps) / (float)SampleNumFps);
		CountFps = 0;
		StartTimeFps = now;
	}
	CountFps++;
	return;
}

//########## FPS値を描画する関数 ##########
VOID MY_FPS_DRAW(VOID)
{
	//文字列を描画
	DrawFormatStringToHandle(0, GAME_HEIGHT - 20, GetColor(255, 255, 255), FontDefault, "FPS:%.1f", CalcFps);
	return;
}

//########## FPS値を計測し、待つ関数 ##########
VOID MY_FPS_WAIT(VOID)
{
	int resultTime = GetNowCount() - StartTimeFps;					//かかった時間
	int waitTime = CountFps * 1000 / GAME_FPS_SPEED - resultTime;	//待つべき時間

	if (waitTime > 0)		//指定のFPS値よりも早い場合
	{
		Sleep(waitTime);	//待つ
	}
	return;
}

//########## キーの入力状態を更新する関数 ##########
VOID MY_ALL_KEYDOWN_UPDATE(VOID)
{
	char TempKey[256];			//一時的に、現在のキーの入力状態を格納する

	GetHitKeyStateAll(TempKey); // 全てのキーの入力状態を得る

	for (int i = 0; i < 256; i++)
	{
		if (TempKey[i] != 0)	//押されているキーのキーコードを押しているとき
		{
			AllKeyState[i]++;	//押されている
		}
		else
		{
			AllKeyState[i] = 0;	//押されていない
		}
	}
	return;
}

//########## タイトル画面の関数 ##########
VOID MY_GAME_TITLE(VOID)
{
	//BGMが流れていないとき
	if (CheckSoundMem(MUSIC_MY_BGM_TITLE.Handle) == 0)
	{
		ChangeVolumeSoundMem(255 * 70 / 100, MUSIC_MY_BGM_TITLE.Handle);	//BGMの音量を50％にする
		PlaySoundMem(MUSIC_MY_BGM_TITLE.Handle, DX_PLAYTYPE_LOOP);			//BGMを流す
	}

	if (AllKeyState[KEY_INPUT_RETURN] != 0)	//エンターキーが押されていた時
	{
		if (MY_PLAY_INIT() == TRUE)		//プレイ画面初期化
		{
			//GameSceneNow = (int)GAME_SCENE_PLAY;	//シーンをプレイ画面にする
		}
	}
	/*MenuElementメニューを選択*/

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
	else if (SelectTitleNum == 2 && AllKeyState[KEY_INPUT_RETURN] == 1)//ESCキーを押したら終了する
	{
		GameSceneNow = GAME_SCENE_END;
	}
	/*ここまで*/
	MY_GAME_BACK_DRAW();
	MY_GAME_TITLE_DRAW();	//タイトル画面描画の関数
	/**************************追加******************/
	for (int i = 0; i < 3; i++) {
		DrawFormatString(MenuElement[i].x, MenuElement[i].y, GetColor(255, 195, 123), "%s", MenuElement[i].name);
	}
	/**************************ここまで**************************************/
	return;
}

//########## タイトル画面描画の関数 ##########
VOID MY_GAME_TITLE_DRAW(VOID)
{

	DrawGraph(GAME_WIDTH / 2 - image_title.Width[0] / 2, GAME_HEIGHT / 4 - image_title.Height[0] / 2, image_title.Handle[0], TRUE);

	DrawStringToHandle(0, 0, "タイトル画面", GetColor(255, 255, 255), FontDefault);

	return;
}

//#############背景描画の関数#######################
VOID MY_GAME_BACK_DRAW(VOID)
{
	DrawGraph(GAME_WIDTH / 2 - image_backtitle.Width[0] / 2, GAME_HEIGHT / 2 - image_backtitle.Height[0] / 2, image_backtitle.Handle[0], TRUE);

	return;
}

//########## 初期化関数 ##########
BOOL MY_PLAY_INIT(VOID)
{
	ScrollCntYoko = 0;
	ScrollCntTate = 0;

	//プレイヤーの画像の番号を設定
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

	//プレイヤーを初期化
	if (MY_PLAYER_INIT(&Myplayer, CharaImage, &PlayerImageNum[0], GAME_MAP_YOKO_SIZE * GAME_CHARA_STARTX, GAME_MAP_TATE_SIZE * GAME_CHARA_STARTY, GAME_CHARA_SPEED) == FALSE) { MessageBox(NULL, "CHARA_INIT", "NotFound", MB_OK); return FALSE; }

	//敵を初期化
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

	//表示領域の設定
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
	DrawString(0, 0, "ゲーム説明", GetColor(255, 255, 255));
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
	//現在のキーの位置を表示
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

	DrawString(0, 0, "曲選択", GetColor(255, 255, 255));

	/*if (AllKeyState[KEY_INPUT_RETURN] != 0)	//エンターキーが押されていた時
	{
		if (MY_PLAY_INIT() == TRUE)		//プレイ画面初期化
		{

			//Myplayer.Zanki = GAME_PLAYER_ZANKI_MAX;	//残機の設定

			for (int tate = 0; tate < GAME_MAP_TATE; tate++)
			{
				for (int yoko = 0; yoko < GAME_MAP_YOKO; yoko++)
				{
					MapData[tate][yoko] = MapData_Init[tate][yoko];	//マップをもとに戻す
				}
			}

			//Myplayer.GetCoinNum = 0;		//ゲットしたコインの数を初期化

			//GameSceneNow = (int)GAME_SCENE_ZANKI;	//シーンを残機表示画面にする

		}
	}*/

	DxLib_End;
	return;
}

//########## プレイ画面の関数 ##########
VOID MY_GAME_PLAY(VOID)
{
	//BGMが流れていないとき
	if (CheckSoundMem(MUSIC_MY_BGM_PLAY.Handle) == 0)
	{
		ChangeVolumeSoundMem(255 * 80 / 100, MUSIC_MY_BGM_PLAY.Handle);	//BGMの音量を50％にする
		PlaySoundMem(MUSIC_MY_BGM_PLAY.Handle, DX_PLAYTYPE_LOOP);			//BGMを流す
	}

	if (AllKeyState[KEY_INPUT_RETURN] == 1) {
		GameSceneNow = GAME_SCENE_END;
	}


	MY_PLAY_PLAYER_OPERATION();		//プレイヤーを操作する

	DrawStringToHandle(0, 0, "プレイ画面(スペースキーを押してください)", GetColor(255, 255, 255), FontDefault);

	MY_GAME_PLAY_DRAW();	//プレイ画面描画

	/*time = */

	//▼▼▼▼▼▼制限時間を消しました▼▼▼▼▼▼▼▼▼▼▼▼
	//DrawFormatStringToHandle(200, 1, GetColor(230, 50, 120), FontHandle_Time, "制限時間:%0.1lf秒", (GAME_TIME_SET - (GET_TIME - MY_GAME_GET_TIME) / 1000));

	/*if (GAME_TIME_SET - (GET_TIME - MY_GAME_GET_TIME) / 1000 <= 0)
	{
		GameSceneNow = GAME_SCENE_END;
	}*/
	//▲▲▲▲▲▲▲▲▲▲▲ここまで▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲

	return;
}

// ########## プレイ画面描画の関数 ##########
VOID MY_GAME_PLAY_DRAW(VOID)
{
	//▼▼▼▼▼ プログラム追加ここから ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼
	//[04]一番下のレイヤーを描画する
	//▲▲▲▲▲ プログラム追加ここまで ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲
	//MY_PLAY_MAP_DRAW(mapData_sita);

	////▼▼▼▼▼ プログラム追加ここから ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼
	////[05]真ん中のレイヤーを描画する
	////▲▲▲▲▲ プログラム追加ここまで ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲
	//MY_PLAY_MAP_DRAW(mapData_naka);

	DRAW_MAP(&Map_Image, 0, 0);	//マップ描画

	MY_PLAY_PLAYER_DRAW(Myplayer);

	//▼▼▼▼▼ プログラム追加ここから ▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼▼
	//[06]一番上のレイヤーを描画する
	//▲▲▲▲▲ プログラム追加ここまで ▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲▲
	//MY_PLAY_MAP_DRAW(mapData_ue);

	//MY_PLAY_MAP_DRAW_ATARI(&mapData_ue, &mapData_naka, &mapData_sita);
	PLAY_MAP_DRAW_ATARI(&mapData_sin);

	DrawStringToHandle(0, 0, "プレイ画面", GetColor(255, 255, 255), FontDefault);

	return;
}

//########## プレイヤーを初期化する関数 ##########
//引　数：CHARADATA 構造体：設定するCHARADATA構造体
//引　数：CHARAIMAGE構造体：設定するCHARAIMAGE構造体
//引　数：int* 　　 　　　：使用する画像の番号（配列の先頭アドレスを引数とする）
//引　数：int　	　　　　　：画像の初期位置X
//引　数：int　	　　　　　：画像の初期位置Y
//引　数：int　	　　　　　：移動スピード
//戻り値：BOOL：エラー時：FALSE
BOOL MY_PLAYER_INIT(CHARADATA *charadata, CHARAIMAGE charaimage, int *num, int x, int y, int speed)
{
	//*(num + 0)は配列の先頭アドレス

	for (int mot = 0; mot < GAME_CHARA_MOTION_NUM; mot++)
	{
		charadata->Handle[mot] = charaimage.HandleChara[mot];	//画像のハンドルを入れる
	}

	charadata->X = x;
	charadata->Y = y;
	charadata->Width = charaimage.Width[*(num + 0)];		//最初の画像の横幅を設定する
	charadata->Height = charaimage.Height[*(num + 0)];		//最初の画像の高さを設定する
	charadata->C_Width = charaimage.C_Width[*(num + 0)];	//最初の画像の横幅の中心を設定する
	charadata->C_Height = charaimage.C_Height[*(num + 0)];	//最初の画像の高さの中心を設定する

	//マップひとつあたりと同じ大きさにする
	charadata->Width = GAME_MAP_YOKO_SIZE;
	charadata->Height = GAME_MAP_TATE_SIZE;
	charadata->C_Width = GAME_MAP_YOKO_SIZE / 2;
	charadata->C_Height = GAME_MAP_TATE_SIZE / 2;

	charadata->NowHandleNum = 6;	//前向きの最初の画像
	charadata->NowHandleCnt = 0;	//画像カウンタを初期化

	charadata->NowHandleCntMAX = 6;	//画像カウンタMAXを初期化

	//***** 以下、パラメータ設定 **************************************************
	charadata->Speed = speed;			//移動速度を設定する

	charadata->MoveDistX = x;			//今の距離を、マップの最初から動いた距離として設定する
	charadata->MoveDistY = y;			//今の距離を、マップの最初から動いた距離として設定する

	charadata->CanMoveUp = TRUE;		//上に移動できる
	charadata->CanMoveDown = TRUE;		//下に移動できる
	charadata->CanMoveLeft = TRUE;		//左に移動できる
	charadata->CanMoveRight = TRUE;		//右に移動できる

	charadata->ScrollOK_X = FALSE;	//移動できない
	charadata->ScrollOK_Y = FALSE;	//移動できない

	charadata->atariX = 4;			//当たり判定のX位置を、イイ感じに設定
	charadata->atariY = 10;			//当たり判定のY位置を、イイ感じに設定
	charadata->atariWidth = 18;		//当たり判定の幅　を、イイ感じに設定
	charadata->atariHeight = 24;	//当たり判定の高さを、イイ感じに設定

	charadata->eneType = (int)GAME_ENETYPE_NONE;	//敵の種類はなし

	wsprintf(charadata->name, GAME_PLAYER_NAME);	//名前を設定

	charadata->LV = charadata->HP_MAX = GAME_PLAYER_LV_FIRST;			//プレイヤーの最初のLV
	charadata->HP = charadata->HP_MAX = GAME_PLAYER_HP_FIRST;			//プレイヤーの最初のHP
	charadata->ATK = charadata->ATK_MAX = GAME_PLAYER_ATK_FIRST;		//プレイヤーの最初のATK
	charadata->DEF = charadata->DEF_MAX = GAME_PLAYER_DEF_FIRST;		//プレイヤーの最初のDEF

	charadata->act_kind = (int)GAME_ACT_KIND_ATK;	//最初は攻撃
	charadata->IsActKeyDown_left = FALSE;			//行動キーを押していない
	charadata->IsActKeyDown_right = FALSE;			//行動キーを押していない
	charadata->battle_turn = (int)GAME_TURN_NONE;	//ターン初期化
	charadata->IsEsc = FALSE;						//逃げられない
	charadata->IsActMsgStart = FALSE;			//行動メッセージ開始
	charadata->IsActMsgEnd = FALSE;				//行動メッセージ終了

	charadata->NowActMsgCnt = 0;					//行動メッセージカウント
	charadata->NowActMsgCntMAX = 90;				//行動メッセージカウントMAX

	charadata->damageCalc = 0;	//ダメージ計算

	charadata->IsActLvupStart = FALSE;	//レベルアップメッセージ開始
	charadata->IsActLvupEnd = FALSE;	//レベルアップメッセージ開始
	charadata->NowActLvupCnt = 0;		//レベルアップメッセージカウント
	charadata->NowActLvupntMAX = 150;	//レベルアップメッセージカウントMAX

	charadata->IsAlive = TRUE;			//生きている

	//表示領域の設定

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

	//アイテムの初期化
	for (int kind = 0; kind < (int)GAME_ITEM_KIND_MAX; kind++)
	{
		for (int cnt = 0; cnt < GAME_PLAYER_ITEM_MAX; cnt++)
		{
			charadata->item[kind][cnt] = 0;	//アイテムを何も持っていない
		}
	}

	MY_SET_PLAYER_ATARI(charadata);	//プレイヤーの当たり判定の領域を設定する

	return TRUE;
}

//########## プレイヤーを操作する関数 ##########
VOID MY_PLAY_PLAYER_OPERATION(VOID)
{
	int retAtariX = 0; int retAtariY = 0;	//当たっているマップの場所

	BOOL IsKeyDown = MY_PLAY_PLAYER_OPERATION_KEY(&retAtariX, &retAtariY);	//キーを押して操作しているか判断

	if (IsKeyDown == TRUE)	//キーを押したとき
	{
		//MY_PLAY_PLAYER_OPERATION_ENCOUNTER(&retAtariX, &retAtariY);			//敵出現判定
		static int x = 0, y = 0;
		if (MY_CHECK_RECT_ATARI_CHARA_MAP_ATARIBASHO(Myplayer.atariRect, mapData_sin.rect_CL, &x, &y) == TRUE)	//ゴールの時
		{
			GameSceneNow = (int)GAME_SCENE_END;	//エンド画面へ
		}


	}

	return;
}

//########## プレイヤーを操作する(キー操作)関数 ##########
BOOL MY_PLAY_PLAYER_OPERATION_KEY(int *x, int *y)
{
	BOOL IsKeyDown = FALSE;		//キーを押されたか

	if (AllKeyState[KEY_INPUT_LEFT] != 0)	//左矢印キーが押されていた時
	{
		IsKeyDown = TRUE;	//キーを押された

		Myplayer.CanMoveLeft = TRUE;	//左方向に、まだ動ける

		MY_SET_PLAYER_ATARI(&Myplayer);	//プレイヤーの当たり判定の領域を設定
		Myplayer.atariRect.left -= 4;	//少し、当たり判定の領域を左にずらす
		Myplayer.atariRect.right -= 4;	//少し、当たり判定の領域を左にずらす

		//if (MY_CHECK_RECT_ATARI_CHARA_MAP_ATARIBASHO(Myplayer.atariRect, mapData_naka.rect_NG, x, y) == TRUE)	//左に行けないモノと当たったとき
		//{
		//	Myplayer.CanMoveLeft = FALSE;	//左に行けない
		//}

		if (MY_CHECK_RECT_ATARI_CHARA_MAP_ATARIBASHO(Myplayer.atariRect, mapData_sin.rect_NG, x, y) == TRUE)	//左に行けないモノと当たったとき
		{
			Myplayer.CanMoveLeft = FALSE;	//左に行けない
		}

		if (Myplayer.CanMoveLeft == TRUE)	//左に移動できるとき
		{
			if (Myplayer.ScrollOK_X == FALSE)	//スクロールできないとき
			{
				if (Myplayer.X > 0)
				{
					Myplayer.X -= Myplayer.Speed;	//プレイヤーを左に移動
				}
			}
			else	//スクロールできるとき
			{
				if (ScrollCntYoko > 0)	//マップ外へスクロールしない
				{
					ScrollCntYoko -= Myplayer.Speed;	//画面を左にスクロール
				}
			}

			if (Myplayer.MoveDistX > 0)
			{
				Myplayer.MoveDistX -= Myplayer.Speed;	//動いた距離を計算
			}
		}

	}

	if (AllKeyState[KEY_INPUT_RIGHT] != 0)	//右矢印キーが押されていた時
	{
		IsKeyDown = TRUE;	//キーを押された

		Myplayer.CanMoveRight = TRUE;	//右方向に、まだ動ける

		MY_SET_PLAYER_ATARI(&Myplayer);	//プレイヤーの当たり判定の領域を設定
		Myplayer.atariRect.left += 4;	//少し、プレイヤーの当たり判定の領域を右にずらす
		Myplayer.atariRect.right += 4;	//少し、プレイヤーの当たり判定の領域を右にずらす

		//if (MY_CHECK_RECT_ATARI_CHARA_MAP_ATARIBASHO(Myplayer.atariRect, mapData_naka.rect_NG, x, y) == TRUE)	//右に行けないモノと当たったとき
		//{
		//	Myplayer.CanMoveRight = FALSE;	//右に行けない
		//}

		if (MY_CHECK_RECT_ATARI_CHARA_MAP_ATARIBASHO(Myplayer.atariRect, mapData_sin.rect_NG, x, y) == TRUE)	//右に行けないモノと当たったとき
		{
			Myplayer.CanMoveRight = FALSE;	//右に行けない
		}

		if (Myplayer.CanMoveRight == TRUE)	//右に移動できるとき
		{
			if (Myplayer.ScrollOK_X == FALSE)	//プレイヤーが動けるとき
			{
				if (Myplayer.X + Myplayer.Width < GAME_WIDTH)
				{
					Myplayer.X += Myplayer.Speed;			//プレイヤーを右に移動
				}
			}
			else	//プレイヤーが動けないとき
			{
				if (ScrollCntYoko < GAME_MAP_YOKO_SIZE * GAME_MAP_YOKO)	//画面外へスクロールしない
				{
					ScrollCntYoko += Myplayer.Speed;	//画面を右にスクロール
				}
			}

			if (Myplayer.MoveDistX < GAME_MAP_YOKO_SIZE * GAME_MAP_YOKO)
			{
				Myplayer.MoveDistX += Myplayer.Speed;	//動いた距離を計算
			}
		}
	}

	if (AllKeyState[KEY_INPUT_UP] != 0)	//上矢印キーが押されていた時
	{
		IsKeyDown = TRUE;	//キーを押された

		Myplayer.CanMoveUp = TRUE;	//上方向に、まだ動ける

		MY_SET_PLAYER_ATARI(&Myplayer);	//プレイヤーの当たり判定の領域を設定
		Myplayer.atariRect.top -= 4;	//少し、当たり判定の領域を上にずらす
		Myplayer.atariRect.bottom -= 4;	//少し、当たり判定の領域を上にずらす

		//if (MY_CHECK_RECT_ATARI_CHARA_MAP_ATARIBASHO(Myplayer.atariRect, mapData_naka.rect_NG, x, y) == TRUE)	//上に行けないモノと当たったとき
		//{
		//	Myplayer.CanMoveUp = FALSE;	//上に行けない
		//}

		if (MY_CHECK_RECT_ATARI_CHARA_MAP_ATARIBASHO(Myplayer.atariRect, mapData_sin.rect_NG, x, y) == TRUE)	//上に行けないモノと当たったとき
		{
			Myplayer.CanMoveUp = FALSE;	//上に行けない
		}

		if (Myplayer.CanMoveUp == TRUE)	//上に移動できるとき
		{
			if (Myplayer.ScrollOK_Y == FALSE)	//プレイヤーが動けるとき
			{
				if (Myplayer.Y > 0)
				{
					Myplayer.Y -= Myplayer.Speed;	//プレイヤーを上に移動
				}
			}
			else	//スクロールできるとき
			{
				if (ScrollCntTate > 0)	//マップ外へスクロールしない
				{
					ScrollCntTate -= Myplayer.Speed;	//画面を上にスクロール
				}
			}

			if (Myplayer.MoveDistY > 0)
			{
				Myplayer.MoveDistY -= Myplayer.Speed;	//動いた距離を計算
			}
		}
	}

	if (AllKeyState[KEY_INPUT_DOWN] != 0)	//下矢印キーが押されていた時
	{
		IsKeyDown = TRUE;	//キーを押された

		Myplayer.CanMoveDown = TRUE;	//下方向に、まだ動ける

		MY_SET_PLAYER_ATARI(&Myplayer);	//プレイヤーの当たり判定の領域を設定
		Myplayer.atariRect.top += 4;	//少し、プレイヤーの当たり判定の領域を下にずらす
		Myplayer.atariRect.bottom += 4;	//少し、プレイヤーの当たり判定の領域を下にずらす

		//if (MY_CHECK_RECT_ATARI_CHARA_MAP_ATARIBASHO(Myplayer.atariRect, mapData_naka.rect_NG, x, y) == TRUE)	//下に行けないモノと当たったとき
		//{
		//	Myplayer.CanMoveDown = FALSE;	//下に行けない
		//}

		if (MY_CHECK_RECT_ATARI_CHARA_MAP_ATARIBASHO(Myplayer.atariRect, mapData_sin.rect_NG, x, y) == TRUE)	//下に行けないモノと当たったとき
		{
			Myplayer.CanMoveDown = FALSE;	//下に行けない
			//if()
		}

		if (Myplayer.CanMoveDown == TRUE)	//下に移動できるとき
		{
			if (Myplayer.ScrollOK_Y == FALSE)	//プレイヤーが動けるとき
			{
				if (Myplayer.Y + Myplayer.Width < GAME_HEIGHT)
				{
					Myplayer.Y += Myplayer.Speed;			//プレイヤーを下に移動
				}
			}
			else	//プレイヤーが動けないとき
			{
				if (ScrollCntTate < GAME_MAP_TATE_SIZE * GAME_MAP_TATE)	//画面外へスクロールしない
				{
					ScrollCntTate += Myplayer.Speed;	//画面下にスクロール
				}
			}

			if (Myplayer.MoveDistY < GAME_MAP_TATE_SIZE * (GAME_MAP_TATE - 1))
			{
				Myplayer.MoveDistY += Myplayer.Speed;	//動いた距離を計算
			}
		}
	}

	//マップの左側にいるときは、プレイヤーを動かす
	if (Myplayer.MoveDistX > 0 &&
		Myplayer.MoveDistX <= GAME_MAP_YOKO_SIZE * 10)	//プレイヤーの動いた距離が一定以上あれば(開始地点)
	{
		Myplayer.ScrollOK_X = FALSE;					//マップを止めて、プレイヤーを動かす
	}

	//マップ真ん中らへんにいるときは、マップを動かす
	if (Myplayer.MoveDistX > GAME_MAP_YOKO_SIZE * 10 &&
		Myplayer.MoveDistX <= GAME_MAP_YOKO_SIZE * (GAME_MAP_YOKO - 15))	//プレイヤーの動いた距離が一定以上あれば(開始地点)
	{
		Myplayer.ScrollOK_X = TRUE;					//マップを動かす
	}

	//マップの右側にいるときは、プレイヤーを動かす
	if (Myplayer.MoveDistX > GAME_MAP_YOKO_SIZE * (GAME_MAP_YOKO - 15) &&
		Myplayer.MoveDistX <= GAME_MAP_YOKO_SIZE * GAME_MAP_YOKO)	//プレイヤーの動いた距離が一定以上あれば(終了地点)
	{
		Myplayer.ScrollOK_X = FALSE;					//マップを止めて、プレイヤーを動かす
	}

	//マップの上側にいるときは、プレイヤーを動かす
	if (Myplayer.MoveDistY > 0 &&
		Myplayer.MoveDistY <= GAME_MAP_TATE_SIZE * 10)	//プレイヤーの動いた距離が一定以上あれば(開始地点)
	{
		Myplayer.ScrollOK_Y = FALSE;					//マップを止めて、プレイヤーを動かす
	}

	//マップ真ん中らへんにいるときは、マップを動かす
	if (Myplayer.MoveDistY > GAME_MAP_TATE_SIZE * 10 &&
		Myplayer.MoveDistY <= GAME_MAP_TATE_SIZE * (GAME_MAP_TATE - 9))	//プレイヤーの動いた距離が一定以上あれば(開始地点)
	{
		Myplayer.ScrollOK_Y = TRUE;					//マップを動かす
	}

	//マップの下側にいるときは、プレイヤーを動かす
	if (Myplayer.MoveDistY > GAME_MAP_TATE_SIZE * (GAME_MAP_TATE - 9) &&
		Myplayer.MoveDistY <= GAME_MAP_TATE_SIZE * GAME_MAP_TATE)	//プレイヤーの動いた距離が一定以上あれば(終了地点)
	{
		Myplayer.ScrollOK_Y = FALSE;	//マップを止めて、プレイヤーを動かす
	}



	return IsKeyDown;
}

//########## プレイヤーを操作する(敵出現)関数 ##########
VOID MY_PLAY_PLAYER_OPERATION_ENCOUNTER(int *x, int *y)
{
	MY_SET_PLAYER_ATARI(&Myplayer);	//プレイヤーの当たり判定の領域を設定

	//エンカウント判定が地面にあるとき
	if (MY_CHECK_RECT_ATARI_CHARA_MAP_ATARIBASHO(Myplayer.atariRect, mapData_sita.rect_BT, x, y) == TRUE)
	{
		Myplayer.eneType = mapData_sita.data[*(y)][*(x)];			//マップのデータを敵のタイプにする	

		int battleRate;		//戦闘開始率
		switch (Myplayer.eneType)
		{
		case (int)GAME_ENETYPE_GRASS:
			battleRate = 100;		//100回に1回は戦闘する
			break;
		case (int)GAME_ENETYPE_RIVER:
			battleRate = 50;		//50回に1回は戦闘する
			break;
		case (int)GAME_ENETYPE_KUSA:
			battleRate = 100;		//100回に1回は戦闘する
			break;
		case (int)GAME_ENETYPE_MAOU:
			battleRate = 400;		//400回に1回は戦闘する
			break;
		case (int)GAME_ENETYPE_BOSS:
			battleRate = 1;			//必ず戦闘する
			break;
		default:
			break;
		}

		//ランダムで戦闘の判定
		//int random = GetRand(battleRate);	//0～MAXまでの数値をランダムに得る

	//	if (random % battleRate == 0)		//敵を出現させるとき
	//	{
	//		Myplayer.eneBattleCnt = MY_RANGE_RAND(1, GAME_ENE_BATTLE_NUM_MAX);	//ランダムに敵の出現数を選ぶ

	//		Myplayer.eneBattleCnt = 1;

	//		//MY_BATTLE_ENEMY_INIT(*(x), *(y));	//敵を初期化

	//		//Myplayer.NowActMsgCnt = 0;		//行動メッセージカウンタ
	//		//Myplayer.IsEsc = FALSE;			//逃げられない
	//		//Myplayer.IsActMsgStart = FALSE;	//行動メッセージ開始
	//		//Myplayer.IsActMsgEnd = FALSE;	//行動メッセージ終了

	//		//Myplayer.IsActLvupStart = FALSE;	//レベルアップメッセージ開始
	//		//Myplayer.IsActLvupEnd = FALSE;	//レベルアップメッセージ終了
	//		//Myplayer.NowActLvupCnt = 0;			//レベルアップメッセージカウンタ

	//		//Myplayer.act_kind = (int)GAME_ACT_KIND_ATK;	//行動は攻撃から
	//		//Myplayer.battle_turn = (int)GAME_TURN_MY;	//自分のターンから

	//		GameSceneNow = (int)GAME_SCENE_BATTLE;	//戦闘画面へ移動
	//	}
	}
}

//########## 戦闘前に敵を初期化する関数 ##########
VOID MY_BATTLE_ENEMY_INIT(int retAtariX, int retAtariY)
{
	//敵のデータの初期化
	for (int i = 0; i < GAME_ENE_BATTLE_NUM_MAX; i++) { eneBattle[i] = eneBattleNum_INIT; }

	int rate;	//出現率
	switch (Myplayer.eneType)	//タイプに合わせて、敵をランダムで選ぶ
	{
	case (int)GAME_ENETYPE_GRASS:
		for (int i = 0; i < Myplayer.eneBattleCnt; i++)
		{
			rate = GetRand(99);	//(0～99)までのどれかをランダムで選ぶ

			if (rate >= 0 && rate < 40)			//出現率40％
			{
				eneBattle[i] = enedata[0];
			}
			else if (rate >= 40 && rate < 70)	//出現率30％
			{
				eneBattle[i] = enedata[1];
			}
			else if (rate >= 70 && rate < 90)	//出現率20％
			{
				eneBattle[i] = enedata[2];
			}
			else if (rate >= 90 && rate < 100)	//出現率10％
			{
				eneBattle[i] = enedata[3];
			}

		}
		break;
	case (int)GAME_ENETYPE_KUSA:
		for (int i = 0; i < Myplayer.eneBattleCnt; i++)
		{
			rate = GetRand(99);	//(0～99)までのどれかをランダムで選ぶ

			if (rate >= 0 && rate < 20)			//出現率25％
			{
				eneBattle[i] = enedata[4];
			}
			else if (rate >= 20 && rate < 40)	//出現率20％
			{
				eneBattle[i] = enedata[5];
			}
			else if (rate >= 40 && rate < 60)	//出現率20％
			{
				eneBattle[i] = enedata[6];
			}
			else if (rate >= 60 && rate < 80)	//出現率20％
			{
				eneBattle[i] = enedata[7];
			}
			else if (rate >= 80 && rate < 100)	//出現率20％
			{
				eneBattle[i] = enedata[8];
			}
		}
		break;
	case (int)GAME_ENETYPE_RIVER:
		for (int i = 0; i < Myplayer.eneBattleCnt; i++)
		{
			rate = GetRand(99);	//(0～99)までのどれかをランダムで選ぶ

			if (rate >= 0 && rate < 25)			//出現率25％
			{
				eneBattle[i] = enedata[9];
			}
			else if (rate >= 25 && rate < 50)	//出現率25％
			{
				eneBattle[i] = enedata[10];
			}
			else if (rate >= 50 && rate < 75)	//出現率25％
			{
				eneBattle[i] = enedata[11];
			}
			else if (rate >= 75 && rate < 100)	//出現率25％
			{
				eneBattle[i] = enedata[12];
			}
		}
		break;
	case (int)GAME_ENETYPE_MAOU:
		for (int i = 0; i < Myplayer.eneBattleCnt; i++)
		{
			rate = GetRand(99);	//(0～99)までのどれかをランダムで選ぶ

			if (rate >= 0 && rate < 20)			//出現率20％
			{
				eneBattle[i] = enedata[13];
			}
			else if (rate >= 20 && rate < 30)	//出現率10％
			{
				eneBattle[i] = enedata[14];
			}
			else if (rate >= 30 && rate < 50)	//出現率20％
			{
				eneBattle[i] = enedata[15];
			}
			else if (rate >= 50 && rate < 60)	//出現率10％
			{
				eneBattle[i] = enedata[16];
			}
			else if (rate >= 60 && rate < 80)	//出現率20％
			{
				eneBattle[i] = enedata[17];
			}
			else if (rate >= 80 && rate < 100)	//出現率20％
			{
				eneBattle[i] = enedata[18];
			}
		}
		break;
	case (int)GAME_ENETYPE_BOSS:

		eneBattle[0] = enedata[19];	//ボスは必ず出現

		break;
	default:
		break;
	}

	if (Myplayer.eneBattleCnt == 1)
	{
		int TekiCenter = GAME_WIDTH / 2;	//敵の幅の中心を計算

		eneBattle[0].rect_act.left = GAME_WIDTH / 2 - eneBattle[0].C_Width;
		eneBattle[0].rect_act.top = GAME_HEIGHT / 2 - eneBattle[0].C_Height;
		eneBattle[0].rect_act.right = GAME_WIDTH / 2 + eneBattle[0].C_Width;
		eneBattle[0].rect_act.bottom = GAME_HEIGHT / 2 + eneBattle[0].C_Height;

		eneBattle[0].rect_st.left = eneBattle[0].rect_act.left + (eneBattle[0].rect_act.right - eneBattle[0].rect_act.left) / 2 - GAME_BATTLE_TEKI_ACT_WIDTH / 2;	//敵の画像に中央寄せ
		eneBattle[0].rect_st.top = eneBattle[0].rect_act.top - GAME_BATTLE_TEKI_ACT_HEIGHT - 5;
		eneBattle[0].rect_st.right = eneBattle[0].rect_st.left + GAME_BATTLE_TEKI_ACT_WIDTH;
		eneBattle[0].rect_st.bottom = eneBattle[0].rect_st.top + GAME_BATTLE_TEKI_ACT_HEIGHT;
		eneBattle[0].IsAlive = TRUE;
	}

}

//########## 範囲を指定してrandを行う ##########
int MY_RANGE_RAND(int min, int max)
{
	return min + (int)(rand()*(max - min + 1.0) / (1.0 + RAND_MAX));
}

//########## キャラクターとマップの当たり判定をする関数(当たった場所を知る) ##########
//引　数　：RECT	：当たり判定をする領域(キャラクター)
//引　数　：RECT	：当たり判定をする領域(マップ)
//引　数　：int 	：あたった場所(X位置)
//引　数　：int 	：あたった場所(Y位置)
//戻り値　：当たっている：TRUE / 当たっていない / FALSE
BOOL MY_CHECK_RECT_ATARI_CHARA_MAP_ATARIBASHO(RECT chara, RECT map[GAME_MAP_TATE][GAME_MAP_YOKO], int *atariX, int *atariY)
{
	for (int tate = 0; tate < GAME_MAP_TATE; tate++)
	{
		for (int yoko = 0; yoko < GAME_MAP_YOKO; yoko++)
		{
			//キャラクターの当たっている場所を取得
			if (MY_CHECK_RECT_ATARI(chara, map[tate][yoko]) == TRUE)
			{
				*atariY = tate;	//atariYのアドレスが指し示す先の場所に、当たったモノの縦の位置を入れる
				*atariX = yoko;	//atariXのアドレスが指し示す先の場所に、当たったモノの横の位置を入れる

				return TRUE;
			}
		}
	}

	return FALSE;		//当たっていない
}

//########## 領域の当たり判定をする関数 ##########
BOOL MY_CHECK_RECT_ATARI(RECT a, RECT b)
{
	if (a.left < b.right &&
		a.top < b.bottom &&
		a.right > b.left &&
		a.bottom > b.top
		)
	{
		return TRUE;	//当たっている
	}

	return FALSE;		//当たっていない
}

//########## プレイヤーの当たり判定の領域を設定する関数 ##########
VOID MY_SET_PLAYER_ATARI(CHARADATA *charadata)
{
	//当たり判定の領域の設定
	charadata->atariRect.left = charadata->X + charadata->atariX + 2;						//現在のX位置 ＋ 当たり判定のX位置
	charadata->atariRect.top = charadata->Y + charadata->atariY + 2;						//現在のY位置 ＋ 当たり判定のY位置
	charadata->atariRect.right = charadata->X + charadata->atariX + charadata->atariWidth - 2;		//現在のX位置 ＋ 当たり判定のX位置 ＋ 当たり判定の幅
	charadata->atariRect.bottom = charadata->Y + charadata->atariY + charadata->atariHeight - 2;	//現在のY位置 ＋ 当たり判定のY位置 ＋ 当たり判定の高さ

	return;
}

//########## プレイヤーを表示する関数 ##########
VOID MY_PLAY_PLAYER_DRAW(CHARADATA player)
{
	//プレイヤーを描画
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
			GetColor(0, 0, 255), FALSE);	//枠線描画
	}

	if (AllKeyState[KEY_INPUT_LEFT] != 0)	//左矢印キーが押されていた時
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
				Myplayer.NowHandleNum++;	//次の左向きの画像
			}
			else
			{
				Myplayer.NowHandleNum = 6;	//一番最初の左向きの画像
			}
		}
	}
	else if (AllKeyState[KEY_INPUT_RIGHT] != 0)	//右矢印キーが押されていた時
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
				Myplayer.NowHandleNum++;	//次の右向きの画像
			}
			else
			{
				Myplayer.NowHandleNum = 12;	//一番最初の右向きの画像
			}
		}
	}
	else if (AllKeyState[KEY_INPUT_UP] != 0)	//上矢印キーが押されていた時
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
				Myplayer.NowHandleNum++;	//次の上向きの画像
			}
			else
			{
				Myplayer.NowHandleNum = 18;	//一番最初の上向きの画像
			}
		}
	}
	else if (AllKeyState[KEY_INPUT_DOWN] != 0)	//下矢印キーが押されていた時
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
				Myplayer.NowHandleNum++;	//次の下向きの画像
			}
			else
			{
				Myplayer.NowHandleNum = 0;	//一番最初の下向きの画像
			}
		}
	}

	if (DEBUG_MODE)
	{
		DrawFormatStringToHandle(0, 20, GetColor(255, 255, 255), FontDefault, "プレイヤーが動いた距離X：%04d", player.MoveDistX);	//動いた距離を表示
		DrawFormatStringToHandle(0, 40, GetColor(255, 255, 255), FontDefault, "プレイヤーが動いた距離Y：%04d", player.MoveDistY);	//動いた距離を表示
		DrawFormatStringToHandle(0, 60, GetColor(255, 255, 255), FontDefault, "プレイヤーX：%04d", player.X);						//プレイヤーのX位置を表示
		DrawFormatStringToHandle(0, 80, GetColor(255, 255, 255), FontDefault, "プレイヤーY：%04d", player.Y);						//プレイヤーのY位置を表示
	}
	return;
}

//########## マップを描画する関数 ##########
VOID MY_PLAY_MAP_DRAW(MAPDATA mapdata)
{
	//スクロールするマップを描画
	for (int tate = 0; tate < GAME_MAP_TATE; tate++)
	{
		for (int yoko = 0; yoko < GAME_MAP_YOKO; yoko++)
		{
			if ((yoko + 1) * GAME_MAP_YOKO_SIZE - ScrollCntYoko >= 0 &&
				(yoko + 0) * GAME_MAP_YOKO_SIZE - ScrollCntYoko <= GAME_WIDTH &&
				(tate + 1) * GAME_MAP_TATE_SIZE - ScrollCntTate >= 0 &&
				(tate + 0) * GAME_MAP_TATE_SIZE - ScrollCntTate <= GAME_HEIGHT
				)	//画面に写っているならばならば
			{
				DrawGraph(
					yoko * GAME_MAP_YOKO_SIZE - ScrollCntYoko,				//位置からスクロール量を引く
					tate * GAME_MAP_TATE_SIZE - ScrollCntTate,				//位置からスクロール量を引く
					mapdata.Handle[mapdata.data[tate][yoko]], TRUE);		//マップをスクロールしながら描画
			}

		}
	}

}

//########## マップの当たり判定を描画する関数 old ##########
VOID MY_PLAY_MAP_DRAW_ATARI(MAPDATA *map_ue, MAPDATA *map_naka, MAPDATA *map_sita)
{
	//スクロールするマップを描画
	for (int tate = 0; tate < GAME_MAP_TATE; tate++)
	{
		for (int yoko = 0; yoko < GAME_MAP_YOKO; yoko++)
		{
			if ((yoko + 1) * GAME_MAP_YOKO_SIZE - ScrollCntYoko >= 0 &&
				(yoko + 0) * GAME_MAP_YOKO_SIZE - ScrollCntYoko <= GAME_WIDTH &&
				(tate + 1) * GAME_MAP_TATE_SIZE - ScrollCntTate >= 0 &&
				(tate + 0) * GAME_MAP_TATE_SIZE - ScrollCntTate <= GAME_HEIGHT
				)	//画面に写っているならば
			{
				if (DEBUG_MODE)
				{
					DrawBox(
						map_naka->rect_OK[tate][yoko].left,
						map_naka->rect_OK[tate][yoko].top,
						map_naka->rect_OK[tate][yoko].right,
						map_naka->rect_OK[tate][yoko].bottom,
						GetColor(116, 232, 232), FALSE);	//通過できるマップ

					DrawBox(
						map_naka->rect_NG[tate][yoko].left,
						map_naka->rect_NG[tate][yoko].top,
						map_naka->rect_NG[tate][yoko].right,
						map_naka->rect_NG[tate][yoko].bottom,
						GetColor(232, 135, 166), FALSE);	//通過できないマップ

					DrawBox(
						map_sita->rect_BT[tate][yoko].left,
						map_sita->rect_BT[tate][yoko].top,
						map_sita->rect_BT[tate][yoko].right,
						map_sita->rect_BT[tate][yoko].bottom,
						GetColor(232, 232, 116), FALSE);	//戦闘するマップ
				}
			}

			//マップの当たり判定もスクロールさせる

			/*コメントアウト消さないで！保留中！
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


			/*コメントアウト消さないで！保留中！
			map_naka->rect_BT[tate][yoko].left = map_naka->rect_BT_First[tate][yoko].left - ScrollCntYoko;
			map_naka->rect_BT[tate][yoko].right = map_naka->rect_BT_First[tate][yoko].right - ScrollCntYoko;
			map_naka->rect_BT[tate][yoko].top = map_naka->rect_BT_First[tate][yoko].top - ScrollCntTate;
			map_naka->rect_BT[tate][yoko].bottom = map_naka->rect_BT_First[tate][yoko].bottom - ScrollCntTate;
			*/

			/*コメントアウト消さないで！保留中！
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

//###########マップの当たり判定を描画する関数　new!!#################################################
VOID PLAY_MAP_DRAW_ATARI(MAPDATA *map_sin)
{
	//スクロールするマップを描画
	for (int tate = 0; tate < GAME_MAP_TATE; tate++)
	{
		for (int yoko = 0; yoko < GAME_MAP_YOKO; yoko++)
		{
			if ((yoko + 1) * GAME_MAP_YOKO_SIZE - ScrollCntYoko >= 0 &&
				(yoko + 0) * GAME_MAP_YOKO_SIZE - ScrollCntYoko <= GAME_WIDTH &&
				(tate + 1) * GAME_MAP_TATE_SIZE - ScrollCntTate >= 0 &&
				(tate + 0) * GAME_MAP_TATE_SIZE - ScrollCntTate <= GAME_HEIGHT
				)	//画面に写っているならば
			{
				if (DEBUG_MODE)
				{
					//DrawBox(
					//	map_naka->rect_OK[tate][yoko].left,
					//	map_naka->rect_OK[tate][yoko].top,
					//	map_naka->rect_OK[tate][yoko].right,
					//	map_naka->rect_OK[tate][yoko].bottom,
					//	GetColor(116, 232, 232), FALSE);	//通過できるマップ

					//DrawBox(
					//	map_naka->rect_NG[tate][yoko].left,
					//	map_naka->rect_NG[tate][yoko].top,
					//	map_naka->rect_NG[tate][yoko].right,
					//	map_naka->rect_NG[tate][yoko].bottom,
					//	GetColor(232, 135, 166), FALSE);	//通過できないマップ

					//DrawBox(
					//	map_sita->rect_BT[tate][yoko].left,
					//	map_sita->rect_BT[tate][yoko].top,
					//	map_sita->rect_BT[tate][yoko].right,
					//	map_sita->rect_BT[tate][yoko].bottom,
					//	GetColor(232, 232, 116), FALSE);	//戦闘するマップ

					DrawBox(
						map_sin->rect_OK[tate][yoko].left,
						map_sin->rect_OK[tate][yoko].top,
						map_sin->rect_OK[tate][yoko].right,
						map_sin->rect_OK[tate][yoko].bottom,
						GetColor(116, 232, 232), FALSE);	//通過できるマップ

				}
			}

			//マップの当たり判定もスクロールさせる

			/*コメントアウト消さないで！保留中！
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


			/*コメントアウト消さないで！保留中！
			map_sin->rect_BT[tate][yoko].left = map_sin->rect_BT_First[tate][yoko].left - ScrollCntYoko;
			map_sin->rect_BT[tate][yoko].right = map_sin->rect_BT_First[tate][yoko].right - ScrollCntYoko;
			map_sin->rect_BT[tate][yoko].top = map_sin->rect_BT_First[tate][yoko].top - ScrollCntTate;
			map_sin->rect_BT[tate][yoko].bottom = map_sin->rect_BT_First[tate][yoko].bottom - ScrollCntTate;
			*/

			/*コメントアウト消さないで！保留中！
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

//########## シーンを移動するときの演出をする関数 ##########
BOOL MY_GAME_SCENE_MOVE(int beforeScene)
{
	//BGMを止める
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

	switch (sceneMove.kind)	//演出効果の種類
	{
	case (int)GAME_MAE_EFFECT_FADEIN:	//フェードイン

		if (sceneMove.DrawCnt < sceneMove.DrawCntMax)
		{
			sceneMove.DrawCnt++;
		}
		else
		{
			return TRUE;	//画面移動
		}

		switch (beforeScene)
		{
		case (int)GAME_SCENE_TITLE:	//タイトル画面

			MY_GAME_BACK_DRAW();

			MY_GAME_TITLE_DRAW();	//タイトル画面描画

			break;

		case (int)GAME_SCENE_PLAY:	//プレイ画面

			MY_GAME_PLAY_DRAW();	//プレイ画面描画

			break;

		case (int)GAME_SCENE_BATTLE:	//戦闘画面

			MY_GAME_BATTLE_DRAW();		//戦闘画面描画

			break;

		case (int)GAME_SCENE_MOVE_SCENE:	//シーン移動画面

			break;

		case (int)GAME_SCENE_END:	//エンド画面

			MY_GAME_END_DRAW();		//エンド画面

			break;

		default:

			break;

		}

		sceneMove.ToukaPercent = sceneMove.DrawCnt / (double)sceneMove.DrawCntMax;	//透過％を求める
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, sceneMove.ToukaPercent * 255);				//透過させる
		DrawBox(0, 0, GAME_WIDTH, GAME_HEIGHT, GetColor(0, 0, 0), TRUE);					//真っ暗な画面にする
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);											//透過をやめる

		break;

	case (int)GAME_MAE_EFFECT_FADEOUT:	//フェードアウト

		if (sceneMove.DrawCnt < sceneMove.DrawCntMax)
		{
			sceneMove.DrawCnt++;
		}
		else
		{
			return TRUE;	//画面移動
		}

		switch (beforeScene)
		{
		case (int)GAME_SCENE_TITLE:	//タイトル画面

			MY_GAME_TITLE_DRAW();	//タイトル画面描画

			break;

		case (int)GAME_SCENE_PLAY:	//プレイ画面

			MY_GAME_PLAY_DRAW();	//プレイ画面描画

			break;

		case (int)GAME_SCENE_BATTLE:	//戦闘画面

			MY_GAME_BATTLE_DRAW();		//戦闘画面描画

			break;

		case (int)GAME_SCENE_MOVE_SCENE:	//シーン移動画面

			break;

		case (int)GAME_SCENE_END:	//エンド画面

			MY_GAME_END_DRAW();		//エンド画面

			break;

		default:

			break;

		}

		sceneMove.ToukaPercent = (sceneMove.DrawCntMax - sceneMove.DrawCnt) / (double)sceneMove.DrawCntMax;		//透過％を求める
		SetDrawBlendMode(DX_BLENDMODE_ALPHA, sceneMove.ToukaPercent * 255);		//透過させる
		DrawBox(0, 0, GAME_WIDTH, GAME_HEIGHT, GetColor(0, 0, 0), TRUE);			//真っ暗な画面にする
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);									//透過をやめる

		break;

	default:
		break;
	}

	DrawStringToHandle(0, 0, "シーン移動画面", GetColor(255, 255, 255), FontDefault);

	return FALSE;
}

//########## 戦闘画面の関数 ##########
VOID MY_GAME_BATTLE(VOID)
{
	if (Myplayer.eneType != (int)GAME_ENETYPE_BOSS)	//ボス以外
	{
		//BGMが流れていないとき
		if (CheckSoundMem(MUSIC_MY_BGM_BATTLE.Handle) == 0)
		{
			ChangeVolumeSoundMem(255 * 50 / 100, MUSIC_MY_BGM_BATTLE.Handle);	//BGMの音量を50％にする
			PlaySoundMem(MUSIC_MY_BGM_BATTLE.Handle, DX_PLAYTYPE_LOOP);			//BGMを流す
		}
	}
	else if (Myplayer.eneType == (int)GAME_ENETYPE_BOSS)	//ボス
	{
		//BGMが流れていないとき
		if (CheckSoundMem(MUSIC_MY_BGM_BOSS.Handle) == 0)
		{
			ChangeVolumeSoundMem(255 * 50 / 100, MUSIC_MY_BGM_BOSS.Handle);	//BGMの音量を50％にする
			PlaySoundMem(MUSIC_MY_BGM_BOSS.Handle, DX_PLAYTYPE_LOOP);			//BGMを流す
		}
	}


	if (Myplayer.battle_turn == (int)GAME_TURN_MY)	//自分のターンのとき
	{
		if (AllKeyState[KEY_INPUT_LEFT] != 0)	//左キーが押されていた時
		{
			if (Myplayer.IsActMsgStart == FALSE)	//行動していないとき
			{
				if (Myplayer.IsActKeyDown_left == FALSE)	//押し続けて選択はできない
				{
					if (Myplayer.act_kind <= (int)GAME_ACT_KIND_ATK)
					{
						Myplayer.act_kind = (int)GAME_ACT_KIND_ESC;	//最後の行動へ戻る
					}
					else
					{
						Myplayer.act_kind--;	//前の行動を選択
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

		if (AllKeyState[KEY_INPUT_RIGHT] != 0)	//右キーが押されていた時
		{
			if (Myplayer.IsActMsgStart == FALSE)	//行動していないとき
			{
				if (Myplayer.IsActKeyDown_right == FALSE)	//押し続けて選択はできない
				{
					if (Myplayer.act_kind >= (int)GAME_ACT_KIND_ESC)
					{
						Myplayer.act_kind = (int)GAME_ACT_KIND_ATK;	//最初の行動へ戻る
					}
					else
					{
						Myplayer.act_kind++;	//次の行動を選択
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

		if (AllKeyState[KEY_INPUT_RETURN] != 0)	//エンターキーが押されていたとき
		{
			if (Myplayer.IsActMsgStart == FALSE)	//行動していないとき
			{
				switch (Myplayer.act_kind)	//行動を決定する
				{
				case (int)GAME_ACT_KIND_ATK:	//攻撃するとき

					PlaySoundMem(MUSIC_MY_SE_BATTLE_ATK.Handle, DX_PLAYTYPE_BACK);

					for (int cnt = 0; cnt < Myplayer.eneBattleCnt; cnt++)	//敵の数だけ攻撃
					{
						if (eneBattle[cnt].IsAlive == TRUE)	//敵が戦えるとき
						{
							Myplayer.damageCalc = Myplayer.ATK - eneBattle[cnt].DEF;	//プレイヤーの攻撃力 - 敵の防御力 がダメージ

							if (Myplayer.damageCalc <= 0) { Myplayer.damageCalc = 0; }

							eneBattle[cnt].HP -= Myplayer.damageCalc;	//HPをへらす

							if (eneBattle[cnt].HP <= 0) { eneBattle[cnt].IsAlive = FALSE; };	//敵は戦闘不能
						}
					}

					break;
				case (int)GAME_ACT_KIND_ITEM:	//アイテムを使用するとき

					PlaySoundMem(MUSIC_MY_SE_BATTLE_ITEM.Handle, DX_PLAYTYPE_BACK);

					if (Myplayer.HP + Myplayer.HP_MAX / 4 < Myplayer.HP_MAX)	//HPの最大値を超えない
					{
						Myplayer.HP += Myplayer.HP_MAX / 4;	//HPを最大HPの4分の１回復する
					}
					else
					{
						Myplayer.HP = Myplayer.HP_MAX;
					}

					break;
				case (int)GAME_ACT_KIND_ESC:	//逃げるとき

					if (Myplayer.eneType != (int)GAME_ENETYPE_BOSS)	//ボス以外は逃げられる
					{
						if (GetRand(99) <= 49)	//50%で逃げれる
						{
							PlaySoundMem(MUSIC_MY_SE_BATTLE_ESC.Handle, DX_PLAYTYPE_BACK);
							Myplayer.IsEsc = TRUE;		//逃げられる
						}
						else
						{
							Myplayer.IsEsc = FALSE;		//逃げられない
						}
					}
					else if (Myplayer.eneType == (int)GAME_ENETYPE_BOSS)	//ボスは逃げられない
					{
						Myplayer.IsEsc = FALSE;			//逃げられない
					}
					break;

				default:
					break;
				}

				Myplayer.NowActMsgCnt = 0;			//行動メッセージカウント
				Myplayer.IsActMsgStart = TRUE;		//行動メッセージ開始
				Myplayer.IsActMsgEnd = FALSE;		//行動メッセージ終了
			}
		}
	}
	else if (Myplayer.battle_turn == (int)GAME_TURN_ENEMY)	//敵のターンのとき
	{
		if (Myplayer.IsActMsgStart == FALSE)
		{
			PlaySoundMem(MUSIC_MY_SE_BATTLE_ATK.Handle, DX_PLAYTYPE_BACK);

			for (int cnt = 0; cnt < Myplayer.eneBattleCnt; cnt++)	//敵の数だけ攻撃
			{
				if (eneBattle[cnt].IsAlive == TRUE)	//敵が戦えるとき
				{
					eneBattle[cnt].damageCalc = eneBattle[cnt].ATK - Myplayer.DEF;	//敵の攻撃力 - プレイヤーの防御力 がダメージ

					if (eneBattle[cnt].damageCalc <= 0)		//ダメージを与えられない
					{
						eneBattle[cnt].damageCalc = 0;
					}

					Myplayer.HP -= eneBattle[cnt].damageCalc;	//HPをへらす

					if (Myplayer.HP <= 0)	//ゲームオーバ
					{
						Myplayer.IsAlive = FALSE;

						Myplayer.gameEndKind = (int)GAME_END_KIND_OVER;
						Myplayer.X = GAME_WIDTH / 2 - Myplayer.C_Width;
						Myplayer.Y = GAME_HEIGHT / 2 - Myplayer.C_Height;

						//私は優しいのでステータスを引き続がせてあげましょう。
						Myplayer.EndLV = Myplayer.LV;
						Myplayer.EndHP = Myplayer.HP_MAX;
						Myplayer.EndATK = Myplayer.ATK_MAX;
						Myplayer.EndDEF = Myplayer.DEF_MAX;

						EndConCnt = 0;	//エンド画面のコンテニューカウント初期化
						EndEndCnt = 0;	//エンド画面のタイトルカウント初期化
						break;
					}
				}
			}

			Myplayer.NowActMsgCnt = 0;		//行動メッセージカウント
			Myplayer.IsActMsgStart = TRUE;	//行動メッセージ開始
			Myplayer.IsActMsgEnd = FALSE;	//行動メッセージ終了
		}
	}

	MY_GAME_BATTLE_DRAW();	//戦闘画面描画の関数

	if (Myplayer.IsActMsgEnd == TRUE)	//行動メッセージ終了
	{
		BOOL IsMoveScene = FALSE;	//シーンを移動するとき

		if (Myplayer.act_kind == (int)GAME_ACT_KIND_ESC)
		{
			if (Myplayer.IsEsc == TRUE)	//逃げたとき
			{
				IsMoveScene = TRUE;	//シーンを移動する
			}
		}

		if (Myplayer.act_kind == (int)GAME_ACT_KIND_ATK)
		{
			int EneNoFightNum = 0;
			for (int cnt = 0; cnt < Myplayer.eneBattleCnt; cnt++)	//敵が全員倒れているかチェック
			{
				if (eneBattle[cnt].IsAlive == FALSE) { EneNoFightNum++; }
			}

			//敵が全員倒れたとき
			if (EneNoFightNum == Myplayer.eneBattleCnt)
			{
				//レベルアップ
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
					Myplayer.act_kind = (int)GAME_ACT_KIND_LVUP;	//レベルアップ
					Myplayer.battle_turn = (int)GAME_TURN_MY;		//自分のターンにする
					Myplayer.IsActMsgStart = TRUE;					//メッセージ開始
				}

				if (Myplayer.eneType == (int)GAME_ENETYPE_BOSS)	//ボスを倒したとき
				{

					Myplayer.gameEndKind = (int)GAME_END_KIND_CLEAR;
					Myplayer.X = GAME_WIDTH / 2 - Myplayer.C_Width;
					Myplayer.Y = GAME_HEIGHT / 2 - Myplayer.C_Height;

					GameSceneNow = (int)GAME_SCENE_END;	//終了画面へ移動
				}

			}

		}

		if (Myplayer.act_kind == (int)GAME_ACT_KIND_LVUP)
		{
			if (Myplayer.IsActLvupEnd == TRUE)
			{
				IsMoveScene = TRUE;	//シーンを移動する
			}
		}

		if (IsMoveScene == FALSE)		//シーンを移動しないとき
		{
			if (Myplayer.IsActLvupStart == FALSE && Myplayer.IsAlive == TRUE)	//レベルアップしていないとき かつ プレイヤーが倒れていないとき
			{
				//ターンを相手にする
				if (Myplayer.battle_turn == (int)GAME_TURN_MY)
				{
					Myplayer.battle_turn = (int)GAME_TURN_ENEMY;
				}
				else if (Myplayer.battle_turn == (int)GAME_TURN_ENEMY)
				{
					Myplayer.battle_turn = (int)GAME_TURN_MY;
				}

				Myplayer.IsActMsgStart = FALSE;	//行動メッセージ開始
				Myplayer.IsActMsgEnd = FALSE;	//行動メッセージ終了
			}
		}
		else if (IsMoveScene == TRUE)	//シーンを移動するとき
		{
			GameSceneNow = (int)GAME_SCENE_PLAY;	//プレイ画面へ移動
		}

		if (Myplayer.IsAlive == FALSE)	//プレイヤーが倒れたら
		{
			GameSceneNow = (int)GAME_SCENE_END;	//終了画面へ移動
		}
	}

	return;
}

// ########## 戦闘画面描画の関数 ##########
VOID MY_GAME_BATTLE_DRAW(VOID)
{
	//戦闘背景を描画
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

	//自分のステータスを表示する場所
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

	int MyHpColor;	//HPの色を決める
	if (Myplayer.HP > Myplayer.HP_MAX / 2) { MyHpColor = GetColor(0, 255, 0); }
	else if (Myplayer.HP > Myplayer.HP_MAX / 4) { MyHpColor = GetColor(255, 255, 0); }
	else { MyHpColor = GetColor(255, 0, 0); }

	if (Myplayer.HP > 0)	//HPがあるとき
	{
		//HPを四角で表示する
		DrawBox(
			Myplayer.rect_st.left + 4,
			Myplayer.rect_st.top + 18 * 2 + 4,
			Myplayer.rect_st.left + 4 + (GAME_BATTLE_MY_ST_WIDTH *  Myplayer.HP / Myplayer.HP_MAX) - 8,
			Myplayer.rect_st.top + 18 * 3,
			MyHpColor, TRUE);
	}

	//自分のステータスを表示する
	DrawFormatStringToHandle(Myplayer.rect_st.left, Myplayer.rect_st.top + 6, GetColor(0, 0, 0), FontDefault, "　%s", Myplayer.name);
	DrawFormatStringToHandle(Myplayer.rect_st.left, Myplayer.rect_st.top + 18 * 1 + 4, GetColor(0, 0, 0), FontDefault, "　　Ｌ　Ｖ：%03d", Myplayer.LV);
	DrawFormatStringToHandle(Myplayer.rect_st.left, Myplayer.rect_st.top + 18 * 2 + 4, GetColor(0, 0, 0), FontDefault, "　　Ｈ　Ｐ：%03d／%03d", Myplayer.HP, Myplayer.HP_MAX);
	DrawFormatStringToHandle(Myplayer.rect_st.left, Myplayer.rect_st.top + 18 * 3 + 4, GetColor(0, 0, 0), FontDefault, "　　ＡＴＫ：%03d", Myplayer.ATK);
	DrawFormatStringToHandle(Myplayer.rect_st.left, Myplayer.rect_st.top + 18 * 4 + 4, GetColor(0, 0, 0), FontDefault, "　　ＤＥＦ：%03d", Myplayer.DEF);

	//自分の行動を表示する場所
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


	if (Myplayer.battle_turn == (int)GAME_TURN_MY)	//自分のターンのとき
	{
		if (Myplayer.IsActMsgStart == FALSE)	//何も選んでいないとき
		{
			//行動を選んだときの色
			int actColor[(int)GAME_ACT_KIND_MAX];			//行動するときに選択されている色
			int selectColor = GetColor(255, 255, 0);		//選択された色
			int NoselectColor = GetColor(255, 255, 255);	//選択されていない色

			switch (Myplayer.act_kind)	//色を選ぶ
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

			//自分のコマンドを表示する場所
			DrawBox(
				Myplayer.rect_act_atk.left,
				Myplayer.rect_act_atk.top,
				Myplayer.rect_act_atk.right,
				Myplayer.rect_act_atk.bottom,
				GetColor(0, 0, 0),
				TRUE);	//攻撃

			DrawBox(
				Myplayer.rect_act_atk.left + 4,
				Myplayer.rect_act_atk.top + 4,
				Myplayer.rect_act_atk.right - 4,
				Myplayer.rect_act_atk.bottom - 4,
				actColor[(int)GAME_ACT_KIND_ATK],
				TRUE);	//攻撃

			DrawStringToHandle(Myplayer.rect_act_atk.left + 4 + 4, Myplayer.rect_act_atk.top + 4 + 4, "こうげき！", GetColor(0, 0, 0), FontDefault);

			DrawBox(
				Myplayer.rect_act_item.left,
				Myplayer.rect_act_item.top,
				Myplayer.rect_act_item.right,
				Myplayer.rect_act_item.bottom,
				GetColor(0, 0, 0),
				TRUE);	//アイテム

			DrawBox(
				Myplayer.rect_act_item.left + 4,
				Myplayer.rect_act_item.top + 4,
				Myplayer.rect_act_item.right - 4,
				Myplayer.rect_act_item.bottom - 4,
				actColor[(int)GAME_ACT_KIND_ITEM],
				TRUE);	//アイテム

			DrawStringToHandle(Myplayer.rect_act_item.left + 4 + 4, Myplayer.rect_act_item.top + 4 + 4, "アイテム", GetColor(0, 0, 0), FontDefault);

			DrawBox(
				Myplayer.rect_act_esc.left,
				Myplayer.rect_act_esc.top,
				Myplayer.rect_act_esc.right,
				Myplayer.rect_act_esc.bottom,
				GetColor(0, 0, 0),
				TRUE);	//逃げる

			DrawBox(
				Myplayer.rect_act_esc.left + 4,
				Myplayer.rect_act_esc.top + 4,
				Myplayer.rect_act_esc.right - 4,
				Myplayer.rect_act_esc.bottom - 4,
				actColor[(int)GAME_ACT_KIND_ESC],
				TRUE);	//逃げる

			DrawStringToHandle(Myplayer.rect_act_esc.left + 4 + 4, Myplayer.rect_act_esc.top + 4 + 4, "逃げる", GetColor(0, 0, 0), FontDefault);

		}
		else if (Myplayer.IsActMsgStart == TRUE) //行動メッセージ表示
		{
			switch (Myplayer.act_kind)
			{
			case (int)GAME_ACT_KIND_NONE:
				break;
			case (int)GAME_ACT_KIND_ATK:

				DrawFormatStringToHandle(Myplayer.rect_act_atk.left, Myplayer.rect_act_atk.top, GetColor(0, 0, 0), FontDefault, "%s の こうげき！", Myplayer.name);

				for (int cnt = 0; cnt < Myplayer.eneBattleCnt; cnt++)	//敵の数だけ攻撃
				{
					if (Myplayer.damageCalc > 0)	//ダメージを与えられるとき
					{
						DrawFormatStringToHandle(Myplayer.rect_act_atk.left, Myplayer.rect_act_atk.top + (cnt + 1) * 20, GetColor(0, 0, 0), FontDefault, "%s に %d の こうげき！", eneBattle[cnt].name, Myplayer.ATK - eneBattle[cnt].DEF);
					}
					else
					{
						DrawFormatStringToHandle(Myplayer.rect_act_atk.left, Myplayer.rect_act_atk.top + (cnt + 1) * 20, GetColor(0, 0, 0), FontDefault, "%s に ダメージ を 与えられない！", eneBattle[cnt].name);
					}

					if (eneBattle[cnt].IsAlive == FALSE)	//敵がたおれたとき
					{
						DrawFormatStringToHandle(Myplayer.rect_act_atk.left, Myplayer.rect_act_atk.top + (cnt + 2) * 20, GetColor(0, 0, 0), FontDefault, "%s は たおれた！", eneBattle[cnt].name);
					}
				}

				break;
			case (int)GAME_ACT_KIND_ITEM:

				DrawFormatStringToHandle(Myplayer.rect_act_atk.left, Myplayer.rect_act_atk.top + 20 * 0, GetColor(0, 0, 0), FontDefault, "%s は ふしぎな薬草 を持っていた！", Myplayer.name);
				DrawFormatStringToHandle(Myplayer.rect_act_atk.left, Myplayer.rect_act_atk.top + 20 * 1, GetColor(0, 0, 0), FontDefault, "%s は HPを 少し 回復した！", Myplayer.name);

				break;
			case (int)GAME_ACT_KIND_LVUP:

				DrawFormatStringToHandle(Myplayer.rect_act_atk.left, Myplayer.rect_act_atk.top + 20 * 0, GetColor(0, 0, 0), FontDefault, "%s の レベル が １上がった！", Myplayer.name);
				DrawFormatStringToHandle(Myplayer.rect_act_atk.left, Myplayer.rect_act_atk.top + 20 * 1, GetColor(0, 0, 0), FontDefault, "%s の HP     が %d になった！", Myplayer.name, Myplayer.HP_MAX);
				DrawFormatStringToHandle(Myplayer.rect_act_atk.left, Myplayer.rect_act_atk.top + 20 * 2, GetColor(0, 0, 0), FontDefault, "%s の ATK    が %d になった！", Myplayer.name, Myplayer.ATK_MAX);
				DrawFormatStringToHandle(Myplayer.rect_act_atk.left, Myplayer.rect_act_atk.top + 20 * 3, GetColor(0, 0, 0), FontDefault, "%s の DEF    が %d になった！", Myplayer.name, Myplayer.DEF_MAX);

				break;

			case (int)GAME_ACT_KIND_ESC:
				if (Myplayer.IsEsc == TRUE)	//逃げられるときのメッセージ
				{
					DrawStringToHandle(Myplayer.rect_act_atk.left, Myplayer.rect_act_atk.top, "うまく 逃げきれた！", GetColor(0, 0, 0), FontDefault);
				}
				else if (Myplayer.IsEsc == FALSE)	//逃げられるときのメッセージ
				{
					DrawStringToHandle(Myplayer.rect_act_atk.left, Myplayer.rect_act_atk.top, "回り込まれて しまった！ 逃げられない！", GetColor(0, 0, 0), FontDefault);
				}
				break;
			default:
				break;
			}

			//しばらくメッセージを表示
			if (Myplayer.IsActMsgEnd == FALSE)
			{
				if (Myplayer.NowActMsgCnt < Myplayer.NowActMsgCntMAX)
				{
					Myplayer.NowActMsgCnt++;
				}
				else
				{
					Myplayer.IsActMsgEnd = TRUE;		//行動メッセージ終了
				}
			}

			if (Myplayer.IsActLvupStart == TRUE)	//レベルアップメッセージを表示
			{
				//しばらくメッセージを表示
				if (Myplayer.NowActLvupCnt < Myplayer.NowActLvupntMAX)
				{
					Myplayer.NowActLvupCnt++;
				}
				else
				{
					Myplayer.IsActLvupEnd = TRUE;		//レベルアップメッセージ終了
				}
			}
		}
	}
	else if (Myplayer.battle_turn == (int)GAME_TURN_ENEMY)	//敵のターンのとき
	{
		if (Myplayer.IsActMsgStart == TRUE)	//行動メッセージ開始
		{
			int cnt;
			for (cnt = 0; cnt < Myplayer.eneBattleCnt; cnt++)	//敵の数だけ攻撃
			{
				DrawFormatStringToHandle(Myplayer.rect_act_atk.left, Myplayer.rect_act_atk.top, GetColor(0, 0, 0), FontDefault, "%s の こうげき！", eneBattle[cnt].name);

				if (eneBattle[cnt].damageCalc > 0)	//ダメージを与えられるとき
				{
					DrawFormatStringToHandle(Myplayer.rect_act_atk.left, Myplayer.rect_act_atk.top + (cnt + 1) * 20, GetColor(0, 0, 0), FontDefault, "%s に %d の こうげき！", Myplayer.name, eneBattle[cnt].ATK - Myplayer.DEF);
				}
				else
				{
					DrawFormatStringToHandle(Myplayer.rect_act_atk.left, Myplayer.rect_act_atk.top + (cnt + 1) * 20, GetColor(0, 0, 0), FontDefault, "%s に ダメージ を 与えられない！", Myplayer.name);
				}
			}

			if (Myplayer.IsAlive == FALSE)	//自分がたおれたとき
			{
				DrawFormatStringToHandle(Myplayer.rect_act_atk.left, Myplayer.rect_act_atk.top + (cnt + 1) * 20, GetColor(0, 0, 0), FontDefault, "%s は たおれた！", Myplayer.name);
			}

			//しばらくメッセージを表示
			if (Myplayer.IsActMsgEnd == FALSE)
			{
				if (Myplayer.NowActMsgCnt < Myplayer.NowActMsgCntMAX)
				{
					Myplayer.NowActMsgCnt++;
				}
				else
				{
					Myplayer.IsActMsgEnd = TRUE;		//行動メッセージ終了
				}
			}

		}
	}

	if (Myplayer.eneBattleCnt == 1)
	{
		if (eneBattle[0].IsAlive == TRUE)	//敵が戦えるとき
		{
			//敵を表示
			DrawGraph(
				eneBattle[0].rect_act.left,
				eneBattle[0].rect_act.top,
				eneBattle[0].Handle,
				TRUE);

			//敵のステータスを表示する場所
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

			int EneHpColor;	//HPの色を決める
			if (eneBattle[0].HP > eneBattle[0].HP_MAX / 2) { EneHpColor = GetColor(0, 255, 0); }
			else if (eneBattle[0].HP > eneBattle[0].HP_MAX / 4) { EneHpColor = GetColor(255, 255, 0); }
			else { EneHpColor = GetColor(255, 0, 0); }

			//HPを四角で表示する
			DrawBox(
				eneBattle[0].rect_st.left + 4,
				eneBattle[0].rect_st.top + 18 * 2 + 4,
				eneBattle[0].rect_st.left + 4 + (GAME_BATTLE_TEKI_ACT_WIDTH * eneBattle[0].HP / eneBattle[0].HP_MAX) - 8,
				eneBattle[0].rect_st.top + 18 * 3,
				EneHpColor, TRUE);

			//敵のステータスを表示する
			DrawFormatStringToHandle(eneBattle[0].rect_st.left, eneBattle[0].rect_st.top + 6, GetColor(0, 0, 0), FontDefault, " %s", eneBattle[0].name);
			DrawFormatStringToHandle(eneBattle[0].rect_st.left, eneBattle[0].rect_st.top + 18 * 1 + 4, GetColor(0, 0, 0), FontDefault, "　Ｌ　Ｖ：%03d", eneBattle[0].LV);
			DrawFormatStringToHandle(eneBattle[0].rect_st.left, eneBattle[0].rect_st.top + 18 * 2 + 4, GetColor(0, 0, 0), FontDefault, "　Ｈ　Ｐ：%03d／%03d", eneBattle[0].HP, eneBattle[0].HP_MAX);
		}
	}

	DrawStringToHandle(0, 0, "戦闘画面", GetColor(255, 255, 255), FontDefault);

	return;
}

//########## エンド画面の関数 ##########
VOID MY_GAME_END(VOID)
{
	BOOL IsAtari = FALSE;	//当たり判定

	//BGMが流れていないとき
	if (CheckSoundMem(MUSIC_MY_BGM_END.Handle) == 0)
	{
		ChangeVolumeSoundMem(255 * 70 / 100, MUSIC_MY_BGM_END.Handle);	//BGMの音量を50％にする
		PlaySoundMem(MUSIC_MY_BGM_END.Handle, DX_PLAYTYPE_LOOP);			//BGMを流す
	}

	switch (Myplayer.gameEndKind)	//キー操作
	{
	case (int)GAME_END_KIND_NONE:

		break;

	case (int)GAME_END_KIND_OVER:

		if (AllKeyState[KEY_INPUT_LEFT] != 0)	//左矢印キーが押されていた時
		{
			if (Myplayer.X > 0)
			{
				Myplayer.X -= Myplayer.Speed;	//プレイヤーを左に移動
			}
		}

		if (AllKeyState[KEY_INPUT_RIGHT] != 0)	//右矢印キーが押されていた時
		{
			if (Myplayer.X + Myplayer.Width < GAME_WIDTH)
			{
				Myplayer.X += Myplayer.Speed;	//プレイヤーを右に移動
			}
		}

		if (AllKeyState[KEY_INPUT_UP] != 0)	//上矢印キーが押されていた時
		{
			if (Myplayer.Y > 0)
			{
				Myplayer.Y -= Myplayer.Speed;	//プレイヤーを上に移動
			}
		}

		if (AllKeyState[KEY_INPUT_DOWN] != 0)	//下矢印キーが押されていた時
		{
			if (Myplayer.Y + Myplayer.Width < GAME_HEIGHT)
			{
				Myplayer.Y += Myplayer.Speed;			//プレイヤーを下に移動
			}
		}

		MY_SET_PLAYER_ATARI(&Myplayer);	//当たり判定をプレイヤーに反映

		if (MY_CHECK_RECT_ATARI(rectEndCon, Myplayer.atariRect) == TRUE)	//コンティニューのとき
		{
			if (EndConCnt < EndConCntMAX)
			{
				EndConCnt++;
			}
			else
			{
				GameSceneNow = (int)GAME_SCENE_PLAY;	//シーンをプレイ画面にする
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

		if (MY_CHECK_RECT_ATARI(rectEndEnd, Myplayer.atariRect) == TRUE)	//コンティニューのとき
		{
			if (EndEndCnt < EndEndCntMAX)
			{
				EndEndCnt++;
			}
			else
			{
				GameSceneNow = (int)GAME_SCENE_TITLE;	//シーンをタイトル画面にする
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
				ChangeVolumeSoundMem(255 * 50 / 100, MUSIC_MY_SE_END_SELECT.Handle);	//BGMの音量を50％にする
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

		if (AllKeyState[KEY_INPUT_SPACE] != 0)	//スペースキーが押されていた時
		{
			GameSceneNow = (int)GAME_SCENE_TITLE;	//シーンをタイトル画面にする
		}

		break;
	default:

		break;
	}

	MY_GAME_END_DRAW();	//エンド画面描画の関数
	MY_GAME_BACK_DRAW();

	/*****************************追加***************************/
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


	/*****************************追加ここまで*******************************/
	return;
}

//########## エンド画面描画の関数 ##########
VOID MY_GAME_END_DRAW(VOID)
{
	char clear[64] = { "GAME CLEAR" };
	int height;
	int Width;

	switch (Myplayer.gameEndKind)	//描画
	{
	case (int)GAME_END_KIND_NONE:

		break;

	case (int)GAME_END_KIND_OVER:

		DrawBox(rectEndCon.left, rectEndCon.top, rectEndCon.right, rectEndCon.bottom, GetColor(255, 0, 0), FALSE);

		SetDrawBlendMode(DX_BLENDMODE_ALPHA, ((double)EndConCnt / EndConCntMAX) * 255);	//透過させる
		DrawBox(rectEndCon.left + 4, rectEndCon.top + 4, rectEndCon.right - 4, rectEndCon.bottom - 4, GetColor(255, 0, 0), TRUE);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);								//透過をやめる

		DrawStringToHandle(rectEndCon.left + 4, rectEndCon.top + 4, "GAME CONTINUE??", GetColor(255, 255, 255), FontDefault);

		DrawBox(rectEndEnd.left, rectEndEnd.top, rectEndEnd.right, rectEndEnd.bottom, GetColor(0, 0, 255), FALSE);

		SetDrawBlendMode(DX_BLENDMODE_ALPHA, ((double)EndEndCnt / EndEndCntMAX) * 255);	//透過させる
		DrawBox(rectEndEnd.left + 4, rectEndEnd.top + 4, rectEndEnd.right - 4, rectEndEnd.bottom - 4, GetColor(0, 0, 255), TRUE);
		SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);								//透過をやめる

		DrawStringToHandle(rectEndEnd.left + 4, rectEndEnd.top + 4, "BACK TITLE??", GetColor(255, 255, 255), FontDefault);

		MY_PLAY_PLAYER_DRAW(Myplayer);					//プレイヤーを描画する

		break;

	case (int)GAME_END_KIND_CLEAR:

		DrawGraph(0, 0, image_clear.Handle[0], TRUE);

		height = GetFontSizeToHandle(FontBig);								//フォントの高さを取得
		Width = GetDrawStringWidthToHandle(clear, strlen(clear), FontBig);	//フォントの幅を取得

		DrawStringToHandle(GAME_WIDTH / 2 - Width / 2 + 4, GAME_HEIGHT / 2 - height / 2 - 100 + 4, clear, GetColor(0, 0, 0), FontBig);
		DrawStringToHandle(GAME_WIDTH / 2 - Width / 2, GAME_HEIGHT / 2 - height / 2 - 100, clear, GetColor(30, 144, 255), FontBig);


		break;
	default:

		break;
	}

	DrawStringToHandle(0, 0, "エンド画面", GetColor(255, 255, 255), FontDefault);

	return;
}

//########## 敵の情報CSVを読み込む関数 ##########
BOOL MY_ENEMY_READ_CSV(ENEDATA *enedata, const char *path, int max)
{
	FILE *fp;

	if ((fp = fopen(path, "r")) == NULL)	//ファイルを読み込みモード(r)で開く
	{
		return FALSE;
	}//異常終了

	//ここから正常に読み込めたときの処理****************************************

	char read = '\0';
	while (read != '\n')	//1行目を改行をヒントに飛ばす
	{
		read = fgetc(fp);
	}

	int result = 0;			//ファイルの最後かチェック
	int LoopCnt = 0;		//ループカウンタ
	while (result != EOF)	//End Of File（ファイルの最後）ではないとき繰り返す
	{
		//CSVのデータの１行分を読み取る
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

		if (LoopCnt > max + 1)	//CSVの情報が多すぎるとき
		{
			fclose(fp);		//ファイルを閉じる
			return FALSE;
		}
	}
	fclose(fp);	//ファイルを閉じる

	return TRUE;
}
//########## ゲームマップのCSVを読み込む関数 ##########
BOOL MY_MAP_READ_CSV_NUM(MAPDATA *mapdata, const char *path, const char *mapname)
{
	FILE *fp;

	if ((fp = fopen(path, "r")) == NULL)	//ファイルを読み込みモード(r)で開く
	{
		return FALSE;
	}//異常終了	

	 //ここから正常に読み込めたときの処理****************************************

	int result = 0;			//ファイルの最後かチェック
	int LoopCnt = 0;		//ループカウンタ
	while (result != EOF)	//End Of File（ファイルの最後）ではないとき繰り返す
	{
		//ファイルから数値を一つ読み込み(%d,)、配列に格納する
		result = fscanf(fp, "%d,", &mapdata->data[LoopCnt / GAME_MAP_YOKO][LoopCnt % GAME_MAP_YOKO]);
		mapdata->mapdata_Init[LoopCnt / GAME_MAP_YOKO][LoopCnt % GAME_MAP_YOKO]
			= mapdata->data[LoopCnt / GAME_MAP_YOKO][LoopCnt % GAME_MAP_YOKO];	//値をコピー

		LoopCnt++;
	}
	fclose(fp);	//ファイルを閉じる

	//マップの名称を入れる
	wsprintf(mapdata->name, mapname);	//マップの名称をコピー

	//マップ領域の初期化
	for (int tate = 0; tate < GAME_MAP_TATE; tate++)
	{
		for (int yoko = 0; yoko < GAME_MAP_YOKO; yoko++)
		{
			mapdata->rect_NG[tate][yoko].left = 0;
			mapdata->rect_NG[tate][yoko].top = 0;
			mapdata->rect_NG[tate][yoko].right = 0;
			mapdata->rect_NG[tate][yoko].bottom = 0;

			mapdata->rect_NG_First[tate][yoko] = mapdata->rect_NG[tate][yoko];	//初期位置を設定

			mapdata->rect_OK[tate][yoko].left = 0;
			mapdata->rect_OK[tate][yoko].top = 0;
			mapdata->rect_OK[tate][yoko].right = 0;
			mapdata->rect_OK[tate][yoko].bottom = 0;

			mapdata->rect_OK_First[tate][yoko] = mapdata->rect_OK[tate][yoko];	//初期位置を設定

			mapdata->rect_BT[tate][yoko].left = 0;
			mapdata->rect_BT[tate][yoko].top = 0;
			mapdata->rect_BT[tate][yoko].right = 0;
			mapdata->rect_BT[tate][yoko].bottom = 0;

			mapdata->rect_BT_First[tate][yoko] = mapdata->rect_BT[tate][yoko];	//初期位置を設定

			mapdata->rect_CL[tate][yoko].left = 0;
			mapdata->rect_CL[tate][yoko].top = 0;
			mapdata->rect_CL[tate][yoko].right = 0;
			mapdata->rect_CL[tate][yoko].bottom = 0;

			mapdata->rect_CL_First[tate][yoko] = mapdata->rect_CL[tate][yoko];	//初期位置を設定

		}
	}

	//マップを当たり判定の領域に変換
	int cnt;
	for (int tate = 0; tate < GAME_MAP_TATE; tate++)
	{
		for (int yoko = 0; yoko < GAME_MAP_YOKO; yoko++)
		{
			for (cnt = 0; cnt < GAME_MAP_NG_KIND; cnt++)	//通行できないマップ
			{
				if (mapdata->data[tate][yoko] == mapdata->mapNGKind[cnt])
				{
					mapdata->rect_NG[tate][yoko].left = yoko * GAME_MAP_YOKO_SIZE + 1;
					mapdata->rect_NG[tate][yoko].top = tate * GAME_MAP_TATE_SIZE + 1;
					mapdata->rect_NG[tate][yoko].right = (yoko + 1) * GAME_MAP_YOKO_SIZE - 1;
					mapdata->rect_NG[tate][yoko].bottom = (tate + 1) * GAME_MAP_TATE_SIZE - 1;

					mapdata->rect_NG_First[tate][yoko] = mapdata->rect_NG[tate][yoko];	//初期位置を設定
				}
			}

			for (cnt = 0; cnt < GAME_MAP_OK_KIND; cnt++)	//通行できるマップ
			{
				if (mapdata->data[tate][yoko] == mapdata->mapOKKind[cnt])
				{
					mapdata->rect_OK[tate][yoko].left = yoko * GAME_MAP_YOKO_SIZE + 1;
					mapdata->rect_OK[tate][yoko].top = tate * GAME_MAP_TATE_SIZE + 1;
					mapdata->rect_OK[tate][yoko].right = (yoko + 1) * GAME_MAP_YOKO_SIZE - 1;
					mapdata->rect_OK[tate][yoko].bottom = (tate + 1) * GAME_MAP_TATE_SIZE - 1;

					mapdata->rect_OK_First[tate][yoko] = mapdata->rect_OK[tate][yoko];	//初期位置を設定
				}
			}

			for (cnt = 0; cnt < GAME_MAP_BT_KIND; cnt++)	//戦闘マップ
			{
				if (mapdata->data[tate][yoko] == mapdata->mapBTKind[cnt])
				{
					mapdata->rect_BT[tate][yoko].left = yoko * GAME_MAP_YOKO_SIZE + 1;
					mapdata->rect_BT[tate][yoko].top = tate * GAME_MAP_TATE_SIZE + 1;
					mapdata->rect_BT[tate][yoko].right = (yoko + 1) * GAME_MAP_YOKO_SIZE - 1;
					mapdata->rect_BT[tate][yoko].bottom = (tate + 1) * GAME_MAP_TATE_SIZE - 1;

					mapdata->rect_BT_First[tate][yoko] = mapdata->rect_BT[tate][yoko];	//初期位置を設定
				}
			}
			//############################追加#############################################
			for (cnt = 0; cnt < GAME_MAP_CLEAR; cnt++)	//戦闘マップ
			{
				if (mapdata->data[tate][yoko] == mapdata->mapCLKind[cnt])
				{
					mapdata->rect_CL[tate][yoko].left = yoko * GAME_MAP_YOKO_SIZE + 1;
					mapdata->rect_CL[tate][yoko].top = tate * GAME_MAP_TATE_SIZE + 1;
					mapdata->rect_CL[tate][yoko].right = (yoko + 1) * GAME_MAP_YOKO_SIZE - 1;
					mapdata->rect_CL[tate][yoko].bottom = (tate + 1) * GAME_MAP_TATE_SIZE - 1;

					mapdata->rect_CL_First[tate][yoko] = mapdata->rect_CL[tate][yoko];	//初期位置を設定
				}
			}
			//#######################ここまで##########################################################
		}
	}

	return TRUE;
}

//########## 背景を読み込む設定をする関数 ##########
//引　数：IMAGE構造体：設定する画像構造体の変数
//引　数：const char *：読み込む画像のファイルパス
//戻り値：int：画像のハンドル / エラーは -1
int MY_LOAD_BACKGROUND(IMAGE *image, const char *path)
{
	image->Handle[0] = LoadGraph(path);	//ハンドルは１つしかない

	//画像サイズを取得
	GetGraphSize(
		image->Handle[0],			//ハンドルから、画像の幅と高さを取得して・・・
		&image->Width[0],			//IMAGE構造体の幅　に、画像の幅　を設定する
		&image->Height[0]);			//IMAGE構造体の逆さに、画像の高さを設定する			

	image->C_Width[0] = image->Width[0] / 2;	//画像の横サイズの中心を取得
	image->C_Height[0] = image->Height[0] / 2;	//画像の縦サイズの中心を取得

	return image->Handle[0];
}

//########## 敵を読み込む設定をする関数 ##########
//引　数：ENEDATA構造体：設定する画像構造体の変数
//引　数：const char *：読み込む画像のファイルパス
//戻り値：int：画像のハンドル / エラーは -1
int MY_LOAD_ENEMY(ENEDATA *enedata, const char *path)
{
	enedata->Handle = LoadGraph(path);	//ハンドルは１つしかない

	//画像サイズを取得
	GetGraphSize(
		enedata->Handle,			//ハンドルから、画像の幅と高さを取得して・・・
		&enedata->Width,			//ENEDATA構造体の幅　に、画像の幅　を設定する
		&enedata->Height);			//ENEDATA構造体の逆さに、画像の高さを設定する			

	enedata->C_Width = enedata->Width / 2;	//画像の横サイズの中心を取得
	enedata->C_Height = enedata->Height / 2;	//画像の縦サイズの中心を取得

	return enedata->Handle;
}

//########## MAPを分割して読み込む設定をする関数 ##########
//引　数：MAPDATA構造体：設定する画像構造体(分割)の変数
//引　数：int　：画像の分割数
//引　数：int　：画像の横の分割数
//引　数：int　：画像の縦の分割数
//引　数：int　：画像の横の分割サイズ
//引　数：int　：画像の縦の分割サイズ
//引　数：const char *：読み込む画像のファイルパス
//戻り値：BOOL：エラー時：FALSE
//BOOL MY_MAP_LOAD_BUNKATSU(MAPDATA *mapdata, int bun_num, int bun_x_num, int bun_y_num, int bun_width, int bun_height, const char *path)
//{
//	int ret = 0;
//
//	ret = LoadDivGraph(path, bun_num, bun_x_num, bun_y_num, bun_width, bun_height, mapdata->Handle);	//画像をメモリに分割して読み込み、ハンドルを取得
//
//	if (ret == -1) { return FALSE; }	//画像読み込みエラー
//
//	for (int cnt = 0; cnt < GAME_MAP_BUN_YOKO_CNT * GAME_MAP_BUN_TATE_CNT; cnt++)
//	{
//		//画像サイズを取得
//		GetGraphSize(
//			mapdata->Handle[cnt],		//ハンドルから、画像の幅と高さを取得して・・・
//			&mapdata->Width[cnt],		//MAP構造体の幅　に、画像の幅　を設定する
//			&mapdata->Height[cnt]);		//MAP構造体の逆さに、画像の高さを設定する			
//
//		mapdata->C_Width[cnt] = mapdata->Width[cnt] / 2;	//画像の横サイズの中心を取得
//		mapdata->C_Height[cnt] = mapdata->Height[cnt] / 2;	//画像の縦サイズの中心を取得
//	}
//
//	return TRUE;
//}

//########## CHARAを分割して読み込む設定をする関数 ##########
//引　数：CHARAIMAGE構造体　：設定するCHARAIMAGE構造体(分割)の変数
//引　数：int　：画像の分割数
//引　数：int　：画像の横の分割数
//引　数：int　：画像の縦の分割数
//引　数：int　：画像の横の分割サイズ
//引　数：int　：画像の縦の分割サイズ
//引　数：const char *：読み込む画像のファイルパス
//戻り値：BOOL：エラー時：FALSE
BOOL MY_CHARA_LOAD_BUNKATSU(CHARAIMAGE *c, int bun_num, int bun_x_num, int bun_y_num, int bun_width, int bun_height, const char *path)
{
	int retLoad;

	//ファイルパスをコピー
	wsprintf(c->FilePath, path);

	//画像をメモリに分割して読み込み、ハンドルを取得
	retLoad = LoadDivGraph(c->FilePath, bun_num, bun_x_num, bun_y_num, bun_width, bun_height, c->HandleChara);

	if (retLoad == -1) { return FALSE; }	//画像読み込みエラー

	for (int cnt = 0; cnt < GAME_CHARA_BUN_YOKO_CNT *GAME_CHARA_BUN_TATE_CNT; cnt++)
	{
		//画像サイズを取得
		GetGraphSize(
			c->HandleChara[cnt],		//ハンドルから、画像の幅と高さを取得して・・・
			&c->Width[cnt],		//MAP構造体の幅　に、画像の幅　を設定する
			&c->Height[cnt]);	//MAP構造体の逆さに、画像の高さを設定する			

		c->C_Width[cnt] = c->Width[cnt] / 2;			//画像の横サイズの中心を取得
		c->C_Height[cnt] = c->Height[cnt] / 2;			//画像の縦サイズの中心を取得
	}

	return TRUE;
}

//########## 音を読み込む設定をする関数 ##########
//引　数：音構造体　	:設定する音構造体の変数
//引　数：const char *	:読み込む画像のファイルパス
//戻り値：BOOL			:TRUE:正常 / FALSE:異常
BOOL MY_MUSIC_LOAD(MUSIC *m, const char *path)
{
	//音を読み込む
	m->Handle = LoadSoundMem(path);

	if (m->Handle == -1) { return FALSE; }

	return TRUE;
}

//########## マップ(上)判定の種類を設定する ##########
BOOL MY_MAP_READ_CSV_UE_KIND_SET(MAPDATA *mapdata)
{
	int Soeji;

	//通行できる種類の残りを-1で埋める
	Soeji = 0;
	for (int cnt = Soeji; cnt < GAME_MAP_OK_KIND; cnt++) { mapdata->mapOKKind[cnt] = -1; }

	//通行できない種類の残りを-1で埋める
	Soeji = 0;
	for (int cnt = Soeji; cnt < GAME_MAP_NG_KIND; cnt++) { mapdata->mapNGKind[cnt] = -1; }

	//戦闘するマップの残りを-1で埋める
	Soeji = 0;
	for (int cnt = Soeji; cnt < GAME_MAP_BT_KIND; cnt++) { mapdata->mapBTKind[cnt] = -1; }

	return TRUE;
}

//########## マップ(中)判定の種類を設定する ##########
BOOL MY_MAP_READ_CSV_NAKA_KIND_SET(MAPDATA *mapdata)
{
	int Soeji;

	//通行できるマップ
	Soeji = 0;
	mapdata->mapOKKind[Soeji++] = 30;	//空白
	mapdata->mapOKKind[Soeji++] = 1081;	//｜の道
	mapdata->mapOKKind[Soeji++] = 1145;	//＋の道
	mapdata->mapOKKind[Soeji++] = 1113;	//－の道
	mapdata->mapOKKind[Soeji++] = 18;	//草

	mapdata->mapOKKind[Soeji++] = 160;	//春大木
	mapdata->mapOKKind[Soeji++] = 161;	//春大木
	mapdata->mapOKKind[Soeji++] = 162;	//春大木
	mapdata->mapOKKind[Soeji++] = 163;	//春大木
	mapdata->mapOKKind[Soeji++] = 192;	//春大木
	mapdata->mapOKKind[Soeji++] = 193;	//春大木
	mapdata->mapOKKind[Soeji++] = 194;	//春大木
	mapdata->mapOKKind[Soeji++] = 195;	//春大木
	mapdata->mapOKKind[Soeji++] = 224;	//春大木
	mapdata->mapOKKind[Soeji++] = 225;	//春大木
	mapdata->mapOKKind[Soeji++] = 226;	//春大木
	mapdata->mapOKKind[Soeji++] = 227;	//春大木
	mapdata->mapOKKind[Soeji++] = 256;	//春大木
	mapdata->mapOKKind[Soeji++] = 259;	//春大木

	mapdata->mapOKKind[Soeji++] = 164;	//夏大木
	mapdata->mapOKKind[Soeji++] = 165;	//夏大木
	mapdata->mapOKKind[Soeji++] = 166;	//夏大木
	mapdata->mapOKKind[Soeji++] = 167;	//夏大木
	mapdata->mapOKKind[Soeji++] = 196;	//夏大木
	mapdata->mapOKKind[Soeji++] = 197;	//夏大木
	mapdata->mapOKKind[Soeji++] = 198;	//夏大木
	mapdata->mapOKKind[Soeji++] = 199;	//夏大木
	mapdata->mapOKKind[Soeji++] = 228;	//夏大木
	mapdata->mapOKKind[Soeji++] = 229;	//夏大木
	mapdata->mapOKKind[Soeji++] = 230;	//夏大木
	mapdata->mapOKKind[Soeji++] = 231;	//夏大木
	mapdata->mapOKKind[Soeji++] = 260;	//夏大木
	mapdata->mapOKKind[Soeji++] = 263;	//夏大木

	mapdata->mapOKKind[Soeji++] = 288;	//秋大木
	mapdata->mapOKKind[Soeji++] = 289;	//秋大木
	mapdata->mapOKKind[Soeji++] = 290;	//秋大木
	mapdata->mapOKKind[Soeji++] = 291;	//秋大木
	mapdata->mapOKKind[Soeji++] = 320;	//秋大木
	mapdata->mapOKKind[Soeji++] = 321;	//秋大木
	mapdata->mapOKKind[Soeji++] = 322;	//秋大木
	mapdata->mapOKKind[Soeji++] = 323;	//秋大木
	mapdata->mapOKKind[Soeji++] = 352;	//秋大木
	mapdata->mapOKKind[Soeji++] = 353;	//秋大木
	mapdata->mapOKKind[Soeji++] = 354;	//秋大木
	mapdata->mapOKKind[Soeji++] = 355;	//秋大木
	mapdata->mapOKKind[Soeji++] = 384;	//秋大木
	mapdata->mapOKKind[Soeji++] = 387;	//秋大木

	mapdata->mapOKKind[Soeji++] = 292;	//冬大木
	mapdata->mapOKKind[Soeji++] = 293;	//冬大木
	mapdata->mapOKKind[Soeji++] = 294;	//冬大木
	mapdata->mapOKKind[Soeji++] = 295;	//冬大木
	mapdata->mapOKKind[Soeji++] = 324;	//冬大木
	mapdata->mapOKKind[Soeji++] = 325;	//冬大木
	mapdata->mapOKKind[Soeji++] = 326;	//冬大木
	mapdata->mapOKKind[Soeji++] = 327;	//冬大木
	mapdata->mapOKKind[Soeji++] = 356;	//冬大木
	mapdata->mapOKKind[Soeji++] = 357;	//冬大木
	mapdata->mapOKKind[Soeji++] = 358;	//冬大木
	mapdata->mapOKKind[Soeji++] = 359;	//冬大木
	mapdata->mapOKKind[Soeji++] = 388;	//冬大木
	mapdata->mapOKKind[Soeji++] = 391;	//冬大木
	mapdata->mapOKKind[Soeji++] = 12;	//花
	mapdata->mapOKKind[Soeji++] = 801;	//縁下
	mapdata->mapOKKind[Soeji++] = 768;	//縁左

	mapdata->mapOKKind[Soeji++] = 1219;	//蓮の花
	mapdata->mapOKKind[Soeji++] = 1173;	//ピサの斜塔上

	mapdata->mapOKKind[Soeji++] = 466;	//立て看板左上
	mapdata->mapOKKind[Soeji++] = 467;	//立て看板右上

	mapdata->mapOKKind[Soeji++] = 82;	//草長め

	mapdata->mapOKKind[Soeji++] = 1188;	//花
	mapdata->mapOKKind[Soeji++] = 1188;	//花
	mapdata->mapOKKind[Soeji++] = 1188;	//花
	mapdata->mapOKKind[Soeji++] = 1186;	//花
	mapdata->mapOKKind[Soeji++] = 1190;	//花
	mapdata->mapOKKind[Soeji++] = 1191;	//花

	mapdata->mapOKKind[Soeji++] = 17;	//川

	//通行できる種類の残りを-1で埋める
	for (int cnt = Soeji; cnt < GAME_MAP_OK_KIND; cnt++) { mapdata->mapOKKind[cnt] = -1; }

	//通行できないマップ
	Soeji = 0;
	mapdata->mapNGKind[Soeji++] = 1136;	//家
	mapdata->mapNGKind[Soeji++] = 1105;	//家
	mapdata->mapNGKind[Soeji++] = 1106;	//家左
	mapdata->mapNGKind[Soeji++] = 1200;	//家右
	mapdata->mapNGKind[Soeji++] = 1169;	//豪邸左
	mapdata->mapNGKind[Soeji++] = 1170;	//豪邸右

	mapdata->mapNGKind[Soeji++] = 34;	//中木夏
	mapdata->mapNGKind[Soeji++] = 35;	//中木夏
	mapdata->mapNGKind[Soeji++] = 98;	//中木夏
	mapdata->mapNGKind[Soeji++] = 99;	//中木夏
	mapdata->mapNGKind[Soeji++] = 66;	//中木夏
	mapdata->mapNGKind[Soeji++] = 67;	//中木夏

	mapdata->mapNGKind[Soeji++] = 945;	//小木
	mapdata->mapNGKind[Soeji++] = 946;	//小木

	mapdata->mapNGKind[Soeji++] = 257;	//春大木
	mapdata->mapNGKind[Soeji++] = 258;	//春大木
	mapdata->mapNGKind[Soeji++] = 261;	//夏大木
	mapdata->mapNGKind[Soeji++] = 262;	//夏大木
	mapdata->mapNGKind[Soeji++] = 385;	//秋大木
	mapdata->mapNGKind[Soeji++] = 386;	//秋大木
	mapdata->mapNGKind[Soeji++] = 389;	//冬大木
	mapdata->mapNGKind[Soeji++] = 390;	//冬大木
	mapdata->mapNGKind[Soeji++] = 1088;	//春大木
	mapdata->mapNGKind[Soeji++] = 1089;	//夏大木
	mapdata->mapNGKind[Soeji++] = 1090;	//秋大木
	mapdata->mapNGKind[Soeji++] = 1091;	//冬大木

	mapdata->mapNGKind[Soeji++] = 432;	//木看板

	mapdata->mapNGKind[Soeji++] = 448;	//池
	mapdata->mapNGKind[Soeji++] = 480;	//池
	mapdata->mapNGKind[Soeji++] = 512;	//池
	mapdata->mapNGKind[Soeji++] = 544;	//池
	mapdata->mapNGKind[Soeji++] = 450;	//池
	mapdata->mapNGKind[Soeji++] = 482;	//池
	mapdata->mapNGKind[Soeji++] = 513;	//池
	mapdata->mapNGKind[Soeji++] = 546;	//池
	mapdata->mapNGKind[Soeji++] = 481;	//池
	mapdata->mapNGKind[Soeji++] = 513;	//池
	mapdata->mapNGKind[Soeji++] = 545;	//池

	mapdata->mapNGKind[Soeji++] = 1040;	//山
	mapdata->mapNGKind[Soeji++] = 1041;	//山
	mapdata->mapNGKind[Soeji++] = 1042;	//山
	mapdata->mapNGKind[Soeji++] = 1043;	//山
	mapdata->mapNGKind[Soeji++] = 1072;	//山
	mapdata->mapNGKind[Soeji++] = 1073;	//山
	mapdata->mapNGKind[Soeji++] = 1074;	//山
	mapdata->mapNGKind[Soeji++] = 1075;	//山

	mapdata->mapNGKind[Soeji++] = 1137;	//豪邸噴水左
	mapdata->mapNGKind[Soeji++] = 1138;	//豪邸噴水右

	mapdata->mapNGKind[Soeji++] = 1168;	//学校
	mapdata->mapNGKind[Soeji++] = 1200;	//ピラミッド
	mapdata->mapNGKind[Soeji++] = 1233;	//ピラミッド
	mapdata->mapNGKind[Soeji++] = 1202;	//家旗
	mapdata->mapNGKind[Soeji++] = 1232;	//家遺跡
	mapdata->mapNGKind[Soeji++] = 1234;	//家遺跡
	mapdata->mapNGKind[Soeji++] = 1205;	//ピサの斜塔下

	mapdata->mapNGKind[Soeji++] = 498;	//立て看板左下
	mapdata->mapNGKind[Soeji++] = 499;	//立て看板右下

	mapdata->mapNGKind[Soeji++] = 1260;	//塀
	mapdata->mapNGKind[Soeji++] = 1288;	//塀
	mapdata->mapNGKind[Soeji++] = 1289;	//塀
	mapdata->mapNGKind[Soeji++] = 1290;	//塀
	mapdata->mapNGKind[Soeji++] = 1291;	//塀
	mapdata->mapNGKind[Soeji++] = 1292;	//塀
	mapdata->mapNGKind[Soeji++] = 1256;	//塀
	mapdata->mapNGKind[Soeji++] = 1258;	//塀
	mapdata->mapNGKind[Soeji++] = 1259;	//塀
	mapdata->mapNGKind[Soeji++] = 1294;	//塀

	mapdata->mapNGKind[Soeji++] = 542;	//箱
	mapdata->mapNGKind[Soeji++] = 543;	//箱
	mapdata->mapNGKind[Soeji++] = 574;	//箱
	mapdata->mapNGKind[Soeji++] = 575;	//箱
	mapdata->mapNGKind[Soeji++] = 606;	//箱
	mapdata->mapNGKind[Soeji++] = 607;	//箱

	mapdata->mapNGKind[Soeji++] = 1284;	//落とし穴小
	mapdata->mapNGKind[Soeji++] = 1285;	//落とし穴中

	mapdata->mapNGKind[Soeji++] = 1107;	//元魔王城
	mapdata->mapNGKind[Soeji++] = 1108;	//元魔王城
	mapdata->mapNGKind[Soeji++] = 1139;	//元魔王城
	mapdata->mapNGKind[Soeji++] = 1140;	//元魔王城

	mapdata->mapNGKind[Soeji++] = 1194;	//魔王城門
	mapdata->mapNGKind[Soeji++] = 1195;	//魔王城門

	mapdata->mapNGKind[Soeji++] = 1171;	//魔王城
	mapdata->mapNGKind[Soeji++] = 1172;	//魔王城
	mapdata->mapNGKind[Soeji++] = 1203;	//魔王城
	mapdata->mapNGKind[Soeji++] = 1204;	//魔王城

	mapdata->mapNGKind[Soeji++] = 1124;	//川

	mapdata->mapNGKind[Soeji++] = 350;	//宝箱
	mapdata->mapNGKind[Soeji++] = 382;	//宝箱空き

	mapdata->mapNGKind[Soeji++] = 351;	//金の宝箱
	mapdata->mapNGKind[Soeji++] = 383;	//金の宝箱空き

	//通行できない種類の残りを-1で埋める
	for (int cnt = Soeji; cnt < GAME_MAP_NG_KIND; cnt++) { mapdata->mapNGKind[cnt] = -1; }

	//戦闘するマップの残りを-1で埋める
	Soeji = 0;
	for (int cnt = Soeji; cnt < GAME_MAP_BT_KIND; cnt++) { mapdata->mapBTKind[cnt] = -1; }

	return TRUE;
}

//########## マップ(下)判定の種類を設定する ##########
BOOL MY_MAP_READ_CSV_SITA_KIND_SET(MAPDATA *mapdata)
{
	int Soeji;


	//通行できるマップ
	Soeji = 0;
	mapdata->mapOKKind[Soeji++] = 0;	//緑のマップ
	mapdata->mapOKKind[Soeji++] = 1;	//草1
	mapdata->mapOKKind[Soeji++] = 152;	//岩
	mapdata->mapOKKind[Soeji++] = 314;	//魔王城
	mapdata->mapOKKind[Soeji++] = 616;	//池
	mapdata->mapOKKind[Soeji++] = 936;	//海


	//通行できる種類の残りを-1で埋める
	for (int cnt = Soeji; cnt < GAME_MAP_OK_KIND; cnt++) { mapdata->mapOKKind[cnt] = -1; }

	//通行できない種類の残りを-1で埋める
	Soeji = 0;
	for (int cnt = Soeji; cnt < GAME_MAP_NG_KIND; cnt++) { mapdata->mapNGKind[cnt] = -1; }

	//戦闘するマップ
	Soeji = 0;
	mapdata->mapBTKind[Soeji++] = GAME_ENETYPE_GRASS;	//草1
	mapdata->mapBTKind[Soeji++] = GAME_ENETYPE_KUSA;	//草2
	mapdata->mapBTKind[Soeji++] = GAME_ENETYPE_RIVER;	//川
	mapdata->mapBTKind[Soeji++] = GAME_ENETYPE_MAOU;	//魔王城
	mapdata->mapBTKind[Soeji++] = GAME_ENETYPE_BOSS;	//BOSS

	//戦闘するマップの残りを-1で埋める
	for (int cnt = Soeji; cnt < GAME_MAP_BT_KIND; cnt++) { mapdata->mapBTKind[cnt] = -1; }

	return TRUE;
}

//#########追加分の判定####################
BOOL MY_MAP_READ_CSV_SIN_KIND_SET(MAPDATA *mapdata)
{
	int Soeji;


	//通行できるマップ
	Soeji = 0;


	mapdata->mapOKKind[Soeji++] = 100;
	//mapdata->mapOKKind[Soeji++] = 102;

	//通行できないマップ

	Soeji = 0;
	mapdata->mapNGKind[Soeji++] = 101;

	//クリア
	Soeji = 0;
	mapdata->mapCLKind[Soeji++] = 102;
	//mapdata->mapNGKind[Soeji++] = 102;

	//############################################失敗#########################################################################################
	/*if (MY_CHECK_RECT_ATARI_CHARA_MAP_ATARIBASHO(Myplayer.atariRect, mapData_sin.rect_NG,x,y) = 102)	//下に行けないモノと当たったとき
	{
		GameSceneNow = MY_GAME_END;
	}*/
	//###############################################################################################################################################

	Soeji = 0;




	return TRUE;
}

//#########マップの読み込み#############
int LOAD_IMG(MAP_IMG *m_img, const char *path)
{
	m_img->Handle = LoadGraph(path);	//ハンドルは１つしかない

//画像サイズを取得
	GetGraphSize(
		m_img->Handle,			//ハンドルから、画像の幅と高さを取得して・・・
		&m_img->Width,			//m_img構造体の幅　に、画像の幅　を設定する
		&m_img->Height);			//m_img構造体の逆さに、画像の高さを設定する			

	m_img->C_Width = m_img->Width / 2;	//画像の横サイズの中心を取得
	m_img->C_Height = m_img->Height / 2;	//画像の縦サイズの中心を取得

	return m_img->Handle;

}

//マップ描画
VOID DRAW_MAP(MAP_IMG *map_img, int x, int y)
{

	//スクロールするマップを描画
	//for (int tate = 0; tate < GAME_MAP_TATE; tate++)
	//{
	//	for (int yoko = 0; yoko < GAME_MAP_YOKO; yoko++)
	//	{
			//if ((yoko + 1) * GAME_MAP_YOKO_SIZE - ScrollCntYoko >= 0 &&
			//	(yoko + 0) * GAME_MAP_YOKO_SIZE - ScrollCntYoko <= GAME_WIDTH &&
			//	(tate + 1) * GAME_MAP_TATE_SIZE - ScrollCntTate >= 0 &&
			//	(tate + 0) * GAME_MAP_TATE_SIZE - ScrollCntTate <= GAME_HEIGHT
			//	)	//画面に写っているならばならば
	if (x - ScrollCntYoko <= GAME_WIDTH &&
		y - ScrollCntTate <= GAME_HEIGHT
		)	//画面に写っているならばならば

	{
		DrawGraph(
			x - ScrollCntYoko,				//位置からスクロール量を引く
			y - ScrollCntTate,				//位置からスクロール量を引く
			map_img->Handle, TRUE);		//マップをスクロールしながら描画
	}

	//	}
	//}

	//DrawGraph(x, y, map_img->Handle, TRUE);	//描画
	return;
}
