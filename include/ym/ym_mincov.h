﻿#ifndef YM_YM_MINCOV_H
#define YM_YM_MINCOV_H

/// @file ym_mincov.h
/// @brief Mincov Solver 用の定義ファイル
/// @author Yusuke Matsunaga (松永 裕介)
///
/// Copyright (C) 2005-2011, 2014, 2016 Yusuke Matsunaga
/// All rights reserved.

/// @defgroup MincovGroup Mincov Solver
///
/// 最小被覆問題を解くためのライブラリ


#include "ym_config.h"


/// @brief mincov 用の名前空間の開始
#define BEGIN_NAMESPACE_YM_MINCOV \
BEGIN_NAMESPACE_YM \
BEGIN_NAMESPACE(nsMincov)

/// @brief mincov 用の名前空間の終了
#define END_NAMESPACE_YM_MINCOV \
END_NAMESPACE(nsMincov) \
END_NAMESPACE_YM

/// @namespace nsYm::nsMincov
/// @brief MINCOV ソルバ関係のクラスが属する名前空間

BEGIN_NAMESPACE_YM_MINCOV

class MinCov;
class LbCalc;
class Selector;
class McSolver;
class McSolverImpl;
class McCell;
class McRowHead;
class McColHead;
class McMatrix;

END_NAMESPACE_YM_MINCOV

BEGIN_NAMESPACE_YM

using nsMincov::MinCov;

END_NAMESPACE_YM

#endif // YM_YM_MINCOV_H
