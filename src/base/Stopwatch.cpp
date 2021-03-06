#include "../base/Stopwatch.h"
#include "../base/Logger.h"
#include "../base/DateTime.h"
#include "../base/Gu.h"

namespace BR2 {
Stopwatch::Stopwatch(const string_t& strName, bool bStart) : _tA(0), _tB(0) {
  _strName = strName;
  if (bStart) {
    start();
  }
}
Stopwatch::~Stopwatch() {
}
void Stopwatch::start(const string_t& strName) {
  _strName = strName;
  _tA = Gu::getMicroSeconds();
}
string_t Stopwatch::stop(bool bLog, bool bFancy) {
  _tB = Gu::getMicroSeconds();

  if (bLog == true) {
    BRLogDebug(toString(bFancy));
  }

  return toString(bFancy);
}
t_timeval Stopwatch::deltaMilliseconds() {
  return (_tB - _tA) / 1000;
}
t_timeval Stopwatch::deltaMicroseconds() {
  return (_tB - _tA);
}
string_t Stopwatch::toString(bool bFancy) {
  if (bFancy) {
    string_t st = DateTime::fromMilliseconds(deltaMilliseconds()).timeToStr(":");
    return st;
  }
  else {
    return Stz "" + _strName + " " + StringUtil::format("%.2f", (float)deltaMilliseconds() + ((float)(deltaMicroseconds() % 1000) / 1000.0f)) + "ms";
  }
}
void Stopwatch::print(string_t& st) {
  string_t str = st + toString() + "ms";
  Gu::print(str);
}
string_t Stopwatch::pulse(bool bLog, bool bFancy) {
  string_t ret = stop(bLog, bFancy);
  start();
  return ret;
}

bool Stopwatch::pulse(t_timeval isGreaterThanMs) {
  bool bRet;
  stop();
  {
    if (deltaMilliseconds() >= isGreaterThanMs) {
      bRet = true;
    }
    else {
      bRet = false;
    }
  }
  start();

  return bRet;
}

}  // namespace BR2
