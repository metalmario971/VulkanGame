/**
*  @file BaseDefines.h
*  @date February 12, 2020
*  @author MetalMario971
*/
#pragma once
#ifndef __BASEDEFINES_15815732801329887558_H__
#define __BASEDEFINES_15815732801329887558_H__

#include "../base/MachineTypes.h"

namespace BR2 {
//Operating System global defines
//We can use either SDL's defines, or use the defines in the expected OS headers
// BR2_OS_WINDOWS, BR2_OS_ANDROID, BR2_OS_LINUX, BR2_OS_IOS, BR2_OS_OSX
#define MUST_OVERRIDE virtual

/************************************************************************/
/* FILES                                                                */
/************************************************************************/
constexpr const char* BR_GET_FILENAME(const char* path) {
    const char* file = path;
    while (*path) {
        if (*path++ == '/') {
            file = path;
        }
    }
    return file;
}
//#if defined(BR2_OS_WINDOWS)
//#define BR_SRC_FNAME __FILE__
//#define BR_SRC_FLINE __LINE__
//#elif defined(BR2_OS_LINUX)
#define BR_SRC_FNAME (BR2::BR_GET_FILENAME(__FILE__))
#define BR_SRC_FLINE (__LINE__)
//#else
//  OS_METHOD_NOT_IMPLEMENTED;
//#endif

//Note: Linux: this is defined in limits.h but doesn't account for actual BUFFER SIZES for wchar.
#if defined(BR2_OS_WINDOWS)
#define BRO_MAX_PATH ((MAX_PATH)*2)
#elif defined(BR2_OS_LINUX)
#define BRO_MAX_PATH ((PATH_MAX)*2)
#else
OS_ERROR_NOT_IMPLEMENTED
#endif

//std::char_traits<wchar_t>::length (dimObjPrefix);

/************************************************************************/
/* FILES                                                                */
/************************************************************************/


#define DEL_MEM(x) \
  do {             \
    if (x) {       \
      delete x;    \
      x = nullptr; \
    }              \
  } while (0);

#define FILESYSTEM_ROOT_DIRECTORY "./data"
#define CACHE_ROOT_DIRECTORY "./data/cache"

#ifndef TRUE
#define TRUE true
#endif
#ifndef FALSE
#define FALSE false
#endif

#define DOES_NOT_OVERRIDE
#define DOES_NOT_INHERIT _NoInheritClassBase
#define OVERRIDE override
#define NOT_VIRTUAL
#define FORCE_INLINE inline
#define CONST_EXPR constexpr

//Cache alignment needed for GPU memory (std430)
//Note in MSVC the alignment comes before structure, after with GCC
#ifdef BR2_OS_WINDOWS
#define CACHE_ALIGN_16_WIN __declspec(align(16))
#define CACHE_ALIGN_16_GCC
#elif defined(BR2_OS_LINUX)
#define CACHE_ALIGN_16_WIN 
#define CACHE_ALIGN_16_GCC __attribute__((aligned(16)))
#else
OS_METHOD_NOT_IMPLEMENTED
#endif
#define STATIC static
#ifndef __inout_
#define __inout_
#endif

#ifndef __out_
#define __out_
#endif

#ifndef __in_
#define __in_
#endif

#ifndef __ignored
#define __ignored
#endif

//optinoal parameter
#ifndef __opt_
#define __opt_
#endif

//Reference parameter (class does not own data)
#ifndef __ref_
#define __ref_
#endif

//By Value param
#ifndef __byval_
#define __byval_
#endif

//Note: this must remain a uint32_t, we serialize it as a uint32_t
typedef uint32_t Hash32;
typedef uint64_t NodeId;
#define NO_NODE_ID (0)

////String
//#ifdef USE_STD_STRING
//typedef std::string string_t;
//#else
//#include "../base/StringWrapper.h"
//#endif
typedef std::wstring wstring_t;
typedef std::string string_t;

/************************************************************************/
/* Enums                                                                */
/************************************************************************/
enum class FrameState { NoFrameState,
                        SyncBegin,
                        Update,
                        Render,
                        SyncEnd };

namespace ColorSpace {
typedef enum { Linear,
               SRGB } e;
}
namespace ButtonState {
typedef enum { Up,
               Press,
               Down,
               Release,
               None } e;
}  // namespace ButtonState
namespace MouseButton {
typedef enum { Left,
               Right,
               Middle } e;
}
namespace PlayState {
typedef enum { Playing,
               Paused,
               Stopped,
               Ended } e;
}
namespace MemSize {
typedef enum { MEMSZ_GIG2 = 536870912 } e;
}
namespace FileWriteMode {
typedef enum { Truncate,
               Append } e;
}
namespace LoadState {
typedef enum { NotLoaded,
               Loaded,
               LoadFailed } e;
}
namespace KeyMod {
typedef enum {
  NoKeyMod = 0x00,
  Shift = 0x01,
  Alt = 0x02,
  Ctrl = 0x04,
  ShiftDontCare = 0x08,
  AltDontCare = 0x10,
  CtrlDontCare = 0x20
} e;
}
namespace RenderSystem {
typedef enum { OpenGL,
               Vulkan } e;
}
enum class OpenGLProfile { Core,
                           Compatibility,
                           ES };
enum class LineBreak { Unix,
                       DOS };
enum class GamePadType { KeyboardAndMouse };

/************************************************************************/
/* Forward Decl                                                         */
/************************************************************************/
class SoundSpec;
class SoundInst;
class SoundPlayInfo;
class Sequence;
class Sequencer;
class _NoInheritClassBase {};
class Logger;
class Texture2D;
class GLContext;
class TexCache;
class Img32;
class BinaryFile;
class EasyNoise;
class FileSystem;
class Exception;
class SoundSpec;
class SoundCache;
class TouchInfo;
class InputManager;  // Renamed InputManager;
class GameMemory;
class AppRunner;
class Delta;
class EngineConfig;
class TreeNode;
class Crc32;
class StreamBuffer;
class Net;
class SyncTimer;
class FpsMeter;
class FrameSync;
//class Component;
class ProjectFile;
class CSharpScript;
class GraphicsWindow;

class WindowManager;
class CSharpScript;
class CSharpCompiler;
class Packet;
class ApplicationPackage;
//Classes that will be removed
class GamePad;
class GamePadButton;
class KeyboardGamePad;

template <class Tx>
class DynamicBuffer;
template <class Tx>
class GrowBuffer;
template <class Tx>
class Allocator;

template <class TItem>
class HashMapItem;
template <class Tx>
class HashMap;

typedef uint64_t t_timeval;
typedef string_t DiskLoc;
// typedef int32_t t_date;            // - Date information [m][d][y1][y2] = [8][27][198][7]
// typedef int64_t t_datetime;        // - A Date + the time.[m][d][y1][y2][h][m][s][ms]
// typedef uint32_t t_time;
typedef std::vector<char> ByteBuffer;
typedef GameMemory PureMemory;  //Pure memory without a VPtr
typedef PureMemory GpuMemory;   //Pure memory without a VPtr

/************************************************************************/
/* Base Classes                                                         */
/************************************************************************/
class GameMemory : DOES_NOT_INHERIT {
public:
  NOT_VIRTUAL ~GameMemory() DOES_NOT_OVERRIDE {}  // Upon tests - this also will get called when the class is deleted.
  GameMemory() {}
};
class VirtualMemory : public GameMemory {
public:
  VirtualMemory() {
  }
  virtual ~VirtualMemory() DOES_NOT_OVERRIDE {
  }
};
template <typename Tx>
class VirtualMemoryShared : public std::enable_shared_from_this<Tx> {
public:
  VirtualMemoryShared() {
  }
  virtual ~VirtualMemoryShared() DOES_NOT_OVERRIDE {
  }
  template <typename Ty> std::shared_ptr<Ty> getThis() {
    return std::dynamic_pointer_cast<Ty>(this->shared_from_this());
  }
};
class OperatingSystemMemory : DOES_NOT_INHERIT {
public:
  OperatingSystemMemory() {
  }
  virtual ~OperatingSystemMemory() DOES_NOT_OVERRIDE {
  }
};
class GameMemoryManager : DOES_NOT_INHERIT {
public:
  static char* allocBlock(size_t newSize) {
    char* block = new char[newSize];
    return block;
  }
  static void freeBlock(char* m) {
    delete[] m;
  }
};

}  // namespace BR2

#endif
