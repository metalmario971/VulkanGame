/**
*  @file GpuBufferGeneric.h
*  @date October 7, 2014
*  @author MetalMario971
*/
#pragma once
#pragma once
#ifndef __GPUBUFFERGENERIC_220156197467321424683_H__
#define __GPUBUFFERGENERIC_220156197467321424683_H__

#include "../model/GpuBufferData.h"

namespace BR2 {
/**
*  @class ShaderStorageBuffer  SSBO
*  @brief TODO: change the name to GpuShaderStorageBuffer
*/
class ShaderStorageBuffer : public GpuBufferData {
public:
  ShaderStorageBuffer(const string_t& name, std::shared_ptr<GLContext> gc, size_t eleSize);
  virtual ~ShaderStorageBuffer() override;

  void syncRead(void* out_data, size_t num_bytes, size_t byte_offset = 0, bool useMemoryBarrier = true);
  void syncWrite(void* in_data, size_t num_bytes, size_t byte_offset = 0, bool useMemoryBarrier = true);
  void allocFill(size_t num_elements, const void* frags = NULL);
};

}

#endif
