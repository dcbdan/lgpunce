#pragma once

#include "../types.h"
#include "../misc.h"

kernel_t gen_constant(vector<uint64_t> const& shape, float constant) {
  uint64_t total = uint64_product(shape);

  kernel_t ret;
  ret.capacity = 1;
  ret.flops = total;
  ret.op = [total, constant](void*, vector<void*> const& inns, vector<void*> const& outs) {
    float* out = (float*)outs[0];
    std::fill(out, out + total, constant);
  };

  return ret;
}

kernel_t gen_zeros(vector<uint64_t> const& shape) {
  return gen_constant(shape, 0.0);
}

kernel_t gen_ones(vector<uint64_t> const& shape) {
  return gen_constant(shape, 1.0);
}

