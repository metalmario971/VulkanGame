
#include "../base/FpsMeter.h"
#include "../base/Delta.h"
#include "../base/FrameSync.h"
#include "../base/InputManager.h"
#include "../base/Logger.h"
#include "../base/Sequencer.h"
#include "../base/SoundCache.h"
#include "../base/FileSystem.h"
#include "../base/EngineConfig.h"
#include "../base/GraphicsWindow.h"
#include "../gfx/UiControls.h"
#include "../gfx/Picker.h"
#include "../gfx/GraphicsContext.h"
#include "../gfx/RenderSettings.h"
#include "../gfx/CameraNode.h"
#include "../gfx/ShaderMaker.h"
#include "../gfx/GraphicsApi.h"
#include "../base/GLContext.h"
#include "../model/VertexTypes.h"
#include "../model/VertexFormat.h"
#include "../model/ModelCache.h"
#include "../world/PhysicsWorld.h"
#include "../world/Scene.h"

namespace BR2 {
GraphicsContext::GraphicsContext(std::shared_ptr<GraphicsApi> api) {
  _pGraphicsApi = api;
  _fClearR = 0.02f;
  _fClearG = 0.02f;
  _fClearB = 0.021f;
  _fClearA = 1.0f;
}
GraphicsContext::~GraphicsContext() {
}
std::shared_ptr<GraphicsWindow> GraphicsContext::createGraphicsWindow(SDL_Window* sdlw, const GraphicsWindowCreateParameters& params) {
  BRLogDebug("Creating graphics window.");

  std::shared_ptr<GraphicsWindow> w = nullptr;
  try {
    w = std::make_shared<GraphicsWindow>(getThis<GLContext>());
    w->init(_pGraphicsApi, sdlw, params);
    _vecWindows.push_back(w);
  }
  catch (const Exception& ex) {
    w = nullptr;
    BRLogError("Error creating graphics window from graphics context.");
  }

  return w;
}

}  // namespace BR2
