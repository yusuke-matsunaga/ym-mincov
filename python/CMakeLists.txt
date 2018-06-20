

# ===================================================================
# インクルードパスの設定
# ===================================================================
include_directories (
  ${CMAKE_CURRENT_SOURCE_DIR}/../../ym-base/cython-src
  ${CMAKE_CURRENT_SOURCE_DIR}/../cython-src
  )


# ===================================================================
#  マクロの定義
# ===================================================================


# ===================================================================
# サブディレクトリの設定
# ===================================================================

add_subdirectory ( debug )


# ===================================================================
#  cython 用のソースファイルの設定
# ===================================================================

set ( CYTHON_SOURCES
  ${CMAKE_CURRENT_SOURCE_DIR}/../cython-src/mincov.pyx
  )

set_source_files_properties (
  ${CYTHON_SOURCES}
  PROPERTIES CYTHON_IS_CXX TRUE
  )


# ===================================================================
#  module ターゲットの設定
# ===================================================================

cython_add_module ( mincov
  ${CYTHON_SOURCES}
  $<TARGET_OBJECTS:ym_base>
  $<TARGET_OBJECTS:ym_mincov>
  )

target_compile_options ( mincov
  PRIVATE "-O3"
  )

target_compile_definitions ( mincov
  PRIVATE "-DNDEBUG"
  )

target_link_libraries ( mincov
  ${YM_LIB_DEPENDS}
  )

cython_add_module ( mincov_d
  ${CYTHON_SOURCES}
  $<TARGET_OBJECTS:ym_base_d>
  $<TARGET_OBJECTS:ym_mincov_d>
  )

target_compile_options ( mincov_d
  PRIVATE "-g"
  )

target_link_libraries ( mincov_d
  ${YM_LIB_DEPENDS}
  )

add_custom_command (
  TARGET mincov_d
  POST_BUILD
  COMMAND ${CMAKE_COMMAND}
  ARGS -E copy $<TARGET_FILE:mincov_d> ${CMAKE_CURRENT_BINARY_DIR}/debug/mincov.so
  )