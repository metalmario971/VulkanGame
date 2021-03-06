/**
*  @file FpsMeter.h
*  @date August 10, 2019
*  @author MetalMario971
*/
#pragma once
#ifndef __FPSMETER_15654546452638750759_H__
#define __FPSMETER_15654546452638750759_H__

#include "../base/BaseHeader.h"

namespace BR2 {
/**
*  @class FpsMeter
*  @brief Manages game FPS per window.
*/
class FpsMeter {
public:
  bool deltaMs(t_timeval& __inout_ last, t_timeval ms);
  float getFps() { return _fpsLast; }
  void update();
  uint64_t getFrameNumber() { return _iFrame; }
  bool frameMod(uint64_t i) {
    return (_iFrame % i) == 0;
  }
private:
  t_timeval _last = 0;
  t_timeval _tmr = 0;
  float _fpsLast = 60;
  uint64_t _iFrame = 0; //Current frame number
};

}//ns Game



#endif
