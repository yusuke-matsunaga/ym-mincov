#ifndef YM_MINCOV_H
#define YM_MINCOV_H

/// @file ym/MinCov.h
/// @brief MinCov のヘッダファイル
/// @author Yusuke Matsunaga (松永 裕介)
///
/// Copyright (C) 2005-2011, 2014, 2015, 2016 Yusuke Matsunaga
/// All rights reserved.


#include "ym/ym_mincov.h"


BEGIN_NAMESPACE_YM_MINCOV

//////////////////////////////////////////////////////////////////////
/// @class MinCov MinCov.h "ym/MinCov.h"
/// @brief 最小被覆問題を解くクラス
//////////////////////////////////////////////////////////////////////
class MinCov
{
public:

  /// @brief コンストラクタ
  MinCov();

  /// @brief デストラクタ
  ~MinCov();


public:
  //////////////////////////////////////////////////////////////////////
  // 外部インターフェイス
  //////////////////////////////////////////////////////////////////////

  /// @brief 問題のサイズを設定する．
  /// @param[in] row_size 行数
  /// @param[in] col_size 列数
  void
  set_size(int row_size,
	   int col_size);

  /// @brief 列のコストを設定する
  /// @param[in] col_pos 追加する要素の列番号 ( 0 <= col_pos < col_size )
  /// @param[in] cost コスト
  void
  set_col_cost(int col_pos,
	       int cost);

  /// @brief 要素を追加する．
  /// @param[in] row_pos 追加する要素の行番号
  /// @param[in] col_pos 追加する要素の列番号
  void
  insert_elem(int row_pos,
	      int col_pos);

  /// @brief 最小被覆問題を解く．
  /// @param[out] solution 選ばれた列集合
  /// @return 解のコスト
  int
  exact(vector<int>& solution);

  /// @brief ヒューリスティックで最小被覆問題を解く．
  /// @param[out] solution 選ばれた列集合
  /// @return 解のコスト
  ///
  /// デフォルトのヒューリスティック(greedy)を用いる．
  int
  heuristic(vector<int>& solution);

  /// @brief ヒューリスティックで最小被覆問題を解く．
  /// @param[in] algorithm ヒューリスティックの名前
  /// @param[out] solution 選ばれた列集合
  /// @return 解のコスト
  int
  heuristic(const string& algorithm,
	    vector<int>& solution);

  /// @brief partition フラグを設定する．
  /// @param[in] flag 分割を行う時 true にセットする．
  void
  set_partition_flag(bool flag);

  /// @brief デバッグフラグを設定する．
  /// @param[in] flag デバッグ情報を出力する時 true にセットする．
  void
  set_debug_flag(bool flag);

  /// @brief デバッグで表示する最大深さを設定する．
  /// @param[in] depth セットする最大深さ
  ///
  /// デバッグフラグが false の時は意味を持たない．
  void
  set_max_depth(int depth);


private:
  //////////////////////////////////////////////////////////////////////
  // データメンバ
  //////////////////////////////////////////////////////////////////////

  // 実際の処理を行うオブジェクト
  nsMincov::McSolver* mSolver;

};

END_NAMESPACE_YM_MINCOV

#endif // YM_MINCOV_H
