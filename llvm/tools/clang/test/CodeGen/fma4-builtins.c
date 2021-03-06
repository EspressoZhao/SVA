// RUN: %clang_cc1 %s -O3 -triple=x86_64-apple-darwin -target-feature +fma4 -emit-llvm -o - | FileCheck %s

// Don't include mm_malloc.h, it's system specific.
#define __MM_MALLOC_H

#include <x86intrin.h>

__m128 test_mm_macc_ps(__m128 a, __m128 b, __m128 c) {
  // CHECK: @llvm.x86.fma4.vfmadd.ps
  return _mm_macc_ps(a, b, c);
}

__m128d test_mm_macc_pd(__m128d a, __m128d b, __m128d c) {
  // CHECK: @llvm.x86.fma4.vfmadd.pd
  return _mm_macc_pd(a, b, c);
}

__m128 test_mm_macc_ss(__m128 a, __m128 b, __m128 c) {
  // CHECK: @llvm.x86.fma4.vfmadd.ss
  return _mm_macc_ss(a, b, c);
}

__m128d test_mm_macc_sd(__m128d a, __m128d b, __m128d c) {
  // CHECK: @llvm.x86.fma4.vfmadd.sd
  return _mm_macc_sd(a, b, c);
}

__m128 test_mm_msub_ps(__m128 a, __m128 b, __m128 c) {
  // CHECK: @llvm.x86.fma4.vfmsub.ps
  return _mm_msub_ps(a, b, c);
}

__m128d test_mm_msub_pd(__m128d a, __m128d b, __m128d c) {
  // CHECK: @llvm.x86.fma4.vfmsub.pd
  return _mm_msub_pd(a, b, c);
}

__m128 test_mm_msub_ss(__m128 a, __m128 b, __m128 c) {
  // CHECK: @llvm.x86.fma4.vfmsub.ss
  return _mm_msub_ss(a, b, c);
}

__m128d test_mm_msub_sd(__m128d a, __m128d b, __m128d c) {
  // CHECK: @llvm.x86.fma4.vfmsub.sd
  return _mm_msub_sd(a, b, c);
}

__m128 test_mm_nmacc_ps(__m128 a, __m128 b, __m128 c) {
  // CHECK: @llvm.x86.fma4.vfnmadd.ps
  return _mm_nmacc_ps(a, b, c);
}

__m128d test_mm_nmacc_pd(__m128d a, __m128d b, __m128d c) {
  // CHECK: @llvm.x86.fma4.vfnmadd.pd
  return _mm_nmacc_pd(a, b, c);
}

__m128 test_mm_nmacc_ss(__m128 a, __m128 b, __m128 c) {
  // CHECK: @llvm.x86.fma4.vfnmadd.ss
  return _mm_nmacc_ss(a, b, c);
}

__m128d test_mm_nmacc_sd(__m128d a, __m128d b, __m128d c) {
  // CHECK: @llvm.x86.fma4.vfnmadd.sd
  return _mm_nmacc_sd(a, b, c);
}

__m128 test_mm_nmsub_ps(__m128 a, __m128 b, __m128 c) {
  // CHECK: @llvm.x86.fma4.vfnmsub.ps
  return _mm_nmsub_ps(a, b, c);
}

__m128d test_mm_nmsub_pd(__m128d a, __m128d b, __m128d c) {
  // CHECK: @llvm.x86.fma4.vfnmsub.pd
  return _mm_nmsub_pd(a, b, c);
}

__m128 test_mm_nmsub_ss(__m128 a, __m128 b, __m128 c) {
  // CHECK: @llvm.x86.fma4.vfnmsub.ss
  return _mm_nmsub_ss(a, b, c);
}

__m128d test_mm_nmsub_sd(__m128d a, __m128d b, __m128d c) {
  // CHECK: @llvm.x86.fma4.vfnmsub.sd
  return _mm_nmsub_sd(a, b, c);
}

__m128 test_mm_maddsub_ps(__m128 a, __m128 b, __m128 c) {
  // CHECK: @llvm.x86.fma4.vfmaddsub.ps
  return _mm_maddsub_ps(a, b, c);
}

__m128d test_mm_maddsub_pd(__m128d a, __m128d b, __m128d c) {
  // CHECK: @llvm.x86.fma4.vfmaddsub.pd
  return _mm_maddsub_pd(a, b, c);
}

__m128 test_mm_msubadd_ps(__m128 a, __m128 b, __m128 c) {
  // CHECK: @llvm.x86.fma4.vfmsubadd.ps
  return _mm_msubadd_ps(a, b, c);
}

__m128d test_mm_msubadd_pd(__m128d a, __m128d b, __m128d c) {
  // CHECK: @llvm.x86.fma4.vfmsubadd.pd
  return _mm_msubadd_pd(a, b, c);
}

__m256 test_mm256_macc_ps(__m256 a, __m256 b, __m256 c) {
  // CHECK: @llvm.x86.fma4.vfmadd.ps.256
  return _mm256_macc_ps(a, b, c);
}

__m256d test_mm256_macc_pd(__m256d a, __m256d b, __m256d c) {
  // CHECK: @llvm.x86.fma4.vfmadd.pd.256
  return _mm256_macc_pd(a, b, c);
}

__m256 test_mm256_msub_ps(__m256 a, __m256 b, __m256 c) {
  // CHECK: @llvm.x86.fma4.vfmsub.ps.256
  return _mm256_msub_ps(a, b, c);
}

__m256d test_mm256_msub_pd(__m256d a, __m256d b, __m256d c) {
  // CHECK: @llvm.x86.fma4.vfmsub.pd.256
  return _mm256_msub_pd(a, b, c);
}

__m256 test_mm256_nmacc_ps(__m256 a, __m256 b, __m256 c) {
  // CHECK: @llvm.x86.fma4.vfnmadd.ps.256
  return _mm256_nmacc_ps(a, b, c);
}

__m256d test_mm256_nmacc_pd(__m256d a, __m256d b, __m256d c) {
  // CHECK: @llvm.x86.fma4.vfnmadd.pd.256
  return _mm256_nmacc_pd(a, b, c);
}

__m256 test_mm256_nmsub_ps(__m256 a, __m256 b, __m256 c) {
  // CHECK: @llvm.x86.fma4.vfnmsub.ps.256
  return _mm256_nmsub_ps(a, b, c);
}

__m256d test_mm256_nmsub_pd(__m256d a, __m256d b, __m256d c) {
  // CHECK: @llvm.x86.fma4.vfnmsub.pd.256
  return _mm256_nmsub_pd(a, b, c);
}

__m256 test_mm256_maddsub_ps(__m256 a, __m256 b, __m256 c) {
  // CHECK: @llvm.x86.fma4.vfmaddsub.ps.256
  return _mm256_maddsub_ps(a, b, c);
}

__m256d test_mm256_maddsub_pd(__m256d a, __m256d b, __m256d c) {
  // CHECK: @llvm.x86.fma4.vfmaddsub.pd.256
  return _mm256_maddsub_pd(a, b, c);
}

__m256 test_mm256_msubadd_ps(__m256 a, __m256 b, __m256 c) {
  // CHECK: @llvm.x86.fma4.vfmsubadd.ps.256
  return _mm256_msubadd_ps(a, b, c);
}

__m256d test_mm256_msubadd_pd(__m256d a, __m256d b, __m256d c) {
  // CHECK: @llvm.x86.fma4.vfmsubadd.pd.256
  return _mm256_msubadd_pd(a, b, c);
}
