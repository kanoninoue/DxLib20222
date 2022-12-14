#include "DxLib.h"
#include "Map.h"
#include "Draw.h"
#include "Player.h"
//#include "Collision.h"
// ウィンドウのタイトルに表示する文字列
const char TITLE[] = "xx2x_xx_ナマエ: タイトル";

// ウィンドウ横幅
const int WIN_WIDTH = 1504;

// ウィンドウ縦幅
const int WIN_HEIGHT = 736;

int WINAPI WinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine,
                   _In_ int nCmdShow) {
	// ウィンドウモードに設定
	ChangeWindowMode(TRUE);

	// ウィンドウサイズを手動では変更させず、
	// かつウィンドウサイズに合わせて拡大できないようにする
	SetWindowSizeChangeEnableFlag(FALSE, FALSE);

	// タイトルを変更
	SetMainWindowText(TITLE);

	// 画面サイズの最大サイズ、カラービット数を設定(モニターの解像度に合わせる)
	SetGraphMode(WIN_WIDTH, WIN_HEIGHT, 32);

	// 画面サイズを設定(解像度との比率で設定)
	SetWindowSizeExtendRate(1.0);

	// 画面の背景色を設定する
	SetDrawScreen(DX_SCREEN_BACK);
	SetBackgroundColor(255, 255, 255);

	// DXlibの初期化
	if (DxLib_Init() == -1) { return -1; }

	// (ダブルバッファ)描画先グラフィック領域は裏面を指定
	SetDrawScreen(DX_SCREEN_BACK);

	// 画像などのリソースデータの変数宣言と読み込み


	// ゲームループで使う変数の宣言
	//マップ
	Map* map;
	map = new Map();
	//お絵描き変数
	Drawing* drawing = new Drawing();
	//プレイヤー
	Player* player = new Player();
	//Collision* collision;
	//collision = new Collision();
	//キー入力用変数
	char KeyBuf[256];
	drawing->Initialize(KeyBuf);

	player->Initialize(KeyBuf);
	// 最新のキーボード情報用
	char keys[256] = {0};

	// 1ループ(フレーム)前のキーボード情報
	char oldkeys[256] = {0};

	// ゲームループ
	while (true) {
		// 最新のキーボード情報だったものは1フレーム前のキーボード情報として保存
		// 最新のキーボード情報を取得
		GetHitKeyStateAll(keys);

		// 画面クリア
		ClearDrawScreen();
		//---------  ここからプログラムを記述  ----------//

		// 更新処理
		GetHitKeyStateAll(KeyBuf);
		
		drawing->Update(player->GetSceneNumber());
		player->Update(drawing->GetDrawMode(), drawing->GetTopPosX()
			, drawing->GetTopUnderX(), drawing->GetTopPosY(), drawing->GetLineLeftX(),
			drawing->GetLineRightX(), drawing->GetLineLeftY(), drawing->GetJumpPosX(),
			drawing->GetJumpPosY(), drawing->GetJumpbottomX(),
			drawing->AGetTopPosX(),
			drawing->AGetTopUnderX(),
			drawing->AGetTopPosY(), drawing->BGetTopPosX(),
			drawing->BGetTopUnderX(),
			drawing->BGetTopPosY(),
			drawing->AGetLineLeftX(),
		drawing->AGetLineRightX(),
		drawing->AGetLineLeftY(),

		drawing->BGetLineLeftX(),
		drawing->BGetLineRightX(),
		drawing->BGetLineLeftY(),
		drawing->AGetJumpPosX(),
		drawing->AGetJumpbottomX(),
		drawing->AGetJumpPosY(),
		drawing->BGetJumpPosX(),
		drawing->BGetJumpbottomX(),
		drawing->BGetJumpPosY(),

		drawing->CGetLineLeftX(),
		drawing->CGetLineRightX(),
		drawing->CGetLineLeftY(), 
		
		 
		

		drawing->DGetLineLeftX(),
		drawing->DGetLineRightX(),
		drawing->DGetLineLeftY(), 
		drawing->CGetJumpPosX(),
		drawing->CGetJumpbottomX(),
		drawing->CGetJumpPosY(),
		drawing->DGetJumpPosX(),
		drawing->DGetJumpbottomX(),
		drawing->DGetJumpPosY(),
		
		
		drawing->EGetLineLeftX(),
		drawing->EGetLineRightX(),
		drawing->EGetLineLeftY(),
		drawing->FGetLineLeftX(), 
		drawing->FGetLineRightX(),
		drawing->FGetLineLeftY(), 
		
		drawing->EGetJumpPosX(),
		drawing->EGetJumpbottomX(),
		drawing->EGetJumpPosY(), 
		
		
		drawing->FGetJumpPosX(),
		drawing->FGetJumpbottomX(), 
		drawing->FGetJumpPosY()
		

		);


		//collision->Update();
		


		// 描画処理
		ClearDrawScreen();
		drawing->Draw(player->GetSceneNumber());
		map->Draw(player->GetSceneNumber());
		player->Draw();
		//collision->Draw();
		

		//---------  ここまでにプログラムを記述  ---------//
		// (ダブルバッファ)裏面
		ScreenFlip();

		// 20ミリ秒待機(疑似60FPS)
		WaitTimer(20);

		// Windowsシステムからくる情報を処理する
		if (ProcessMessage() == -1) {
			break;
		}

		// ESCキーが押されたらループから抜ける
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1) {
			break;
		}
	}
	// Dxライブラリ終了処理
	DxLib_End();

	// 正常終了
	return 0;
}
