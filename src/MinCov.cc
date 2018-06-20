
/// @file MinCov.cc
/// @brief MinCov の実装ファイル
/// @author Yusuke Matsunaga (松永 裕介)
///
/// Copyright (C) 2014 Yusuke Matsunaga
/// All rights reserved.


#include "ym/MinCov.h"
#include "McSolver.h"
#include "McSolverImpl.h"


BEGIN_NAMESPACE_YM

//////////////////////////////////////////////////////////////////////
// クラス MinCov
//////////////////////////////////////////////////////////////////////

// @brief コンストラクタ
MinCov::MinCov()
{
  mSolver = new nsMincov::McSolver();
}

// @brief デストラクタ
MinCov::~MinCov()
{
  delete mSolver;
}

// @brief 問題のサイズを設定する．
// @param[in] row_size 行数
// @param[in] col_size 列数
void
MinCov::set_size(int row_size,
		 int col_size)
{
  mSolver->set_size(row_size, col_size);
}

// @brief 列のコストを設定する
// @param[in] col_pos 追加する要素の列番号
// @param[in] cost コスト
void
MinCov::set_col_cost(int col_pos,
		     int cost)
{
  mSolver->set_col_cost(col_pos, cost);
}

// @brief 要素を追加する．
// @param[in] row_pos 追加する要素の行番号
// @param[in] col_pos 追加する要素の列番号
void
MinCov::insert_elem(int row_pos,
		    int col_pos)
{
  mSolver->insert_elem(row_pos, col_pos);
}

// @brief 最小被覆問題を解く．
// @param[out] solution 選ばれた列集合
// @return 解のコスト
int
MinCov::exact(vector<int>& solution)
{
  return mSolver->exact(solution);
}

// @brief ヒューリスティックで最小被覆問題を解く．
// @param[out] solution 選ばれた列集合
// @param[in] algorithm ヒューリスティックの名前
// @return 解のコスト
//
// デフォルトのヒューリスティック(greedy)を用いる．
int
MinCov::heuristic(vector<int>& solution)
{
  return mSolver->heuristic("greedy", solution);
}

// @brief ヒューリスティックで最小被覆問題を解く．
// @param[in] algorithm ヒューリスティックの名前
// @param[out] solution 選ばれた列集合
// @return 解のコスト
int
MinCov::heuristic(const string& algorithm,
		  vector<int>& solution)
{
  return mSolver->heuristic(algorithm, solution);
}

// @brief partition フラグを設定する．
void
MinCov::set_partition_flag(bool flag)
{
  nsMincov::McSolverImpl::set_partition(flag);
}

// @brief デバッグフラグを設定する．
void
MinCov::set_debug_flag(bool flag)
{
  nsMincov::McSolverImpl::set_debug(flag);
}

// @brief デバッグで表示する最大深さを設定する．
void
MinCov::set_max_depth(int depth)
{
  nsMincov::McSolverImpl::set_max_depth(depth);
}

END_NAMESPACE_YM
