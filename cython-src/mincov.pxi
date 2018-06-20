
### @file mincov.pxi
### @brief mincov の cython インターフェイス
### @author Yusuke Matsunaga (松永 裕介)
###
### Copyright (C) 2018 Yusuke Matsunaga
### All rights reserved.

from libcpp cimport bool
from libcpp.string cimport string
from libcpp.vector cimport vector
from CXX_MinCov cimport MinCov as CXX_MinCov


### @brief MinCov の Python バージョン
cdef class MinCov :
    cdef CXX_MinCov _this

    ### @brief 初期化
    def __init__(MinCov self, *args) :
        if len(args) == 0 :
            pass
        elif len(args) == 2 and type(args[0]) == int and type(args[1]) == int :
            self.set_size(args[0], args[1])
        else :
            # 引数がおかしい
            assert False

    ### @brief 問題のサイズを設定する．
    ### @param[in] row_size 行数
    ### @param[in] col_size 列数
    def set_size(MinCov self, int row_size, int col_size) :
        self._this.set_size(row_size, col_size)

    ### @brief 列のコストを設定する．
    ### @param[in] col_pos 列番号 ( 0 <= col_pos < col_size )
    ### @param[in] cost コスト
    def set_col_cost(MinCov self, int col_pos, int cost) :
        self._this.set_col_cost(col_pos, cost)

    ### @brief 要素を追加する．
    ### @param[in] row_pos 行番号 ( 0 <= row_pos < row_size )
    ### @param[in] col_pos 列番号 ( 0 <= col_pos < col_size )
    def insert_elem(MinCov self, int row_pos, int col_pos) :
        self._this.insert_elem(row_pos, col_pos)

    ### @brief 最小被覆問題の厳密解を求める．
    ### @return 解のコストと解の列のリストのタプル
    def exact(MinCov self) :
        cdef vector[int] c_solution
        cdef int cost = self._this.exact(c_solution)
        solution = list()
        for i in range(c_solution.size()) :
            solution.append(c_solution[i])
        return cost, solution

    ### @brief 最小被覆問題の近似解を求める．
    ### @param[in] algorithm アルゴリズムの名前(キーワード引数)
    ### @return 解のコストと解の列のリストのタプル
    def heuristic(MinCov self, **kwargs) :
        pass

    ### @brief partition フラグを設定する．
    ### @param[in] flag ブロック分割を行う時 True にセットする．
    def set_partition_flag(MinCov self, bool flag) :
        self._this.set_partition_flag(flag)

    ### @brief デバッグフラグを設定する．
    ### @param[in] flag フラグの値
    def set_debug_flag(MinCov self, bool flag) :
        self._this.set_debug_flag(flag)

    ### @brief デバッグで表示する最大深さを設定する．
    ### @param[in] depth セットする最大深さ
    ###
    ### デバッグフラグが False の時は意味を持たない．
    def set_max_depth(MinCov self, int depth) :
        self._this.set_max_depth(depth)
