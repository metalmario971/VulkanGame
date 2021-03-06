/**
*
*  @file Scene.h
*  @date February 9, 2020
*  @author MetalMario971
*
*/
#pragma once
#ifndef __SCENE_1581228482668944733_H__
#define __SCENE_1581228482668944733_H__

#include "../gfx/GfxHeader.h"
#include "../world/WorldHeader.h"
#include "../model/SceneNode.h"

namespace BR2 {
/**
*  @class Scene
*  @brief The scenegraph holding all relevant objects.
*/
class Scene : public SceneNode {
public:
  Scene();
  virtual ~Scene() override;

  static std::shared_ptr<Scene> create();
  void idle(int64_t us);
  void update(float delta);
  void updateWidthHeight(int32_t w, int32_t h, bool bForce);

  std::shared_ptr<UiScreen> getUiScreen() { return _pUiScreen; }
  std::shared_ptr<PhysicsWorld> getPhysicsManager() { return _pPhysicsWorld; }
  std::shared_ptr<CameraNode> getActiveCamera() { return _pActiveCamera; }
  //**TODO: we need to differentiate the different cameras by keeping exactly one camera defined as the "main player camera"
  std::shared_ptr<CameraNode> getDefaultCamera() { return _pDefaultCamera; }
  std::shared_ptr<LightManager> getLightManager() { return _pLightManager; }
  std::shared_ptr<GraphicsWindow> getWindow() { return _pGraphicsWindow; }
  std::shared_ptr<GLContext> tryGetContext();
  std::shared_ptr<RenderBucket> getRenderBucket() { return _pRenderBucket; }
  std::vector<std::shared_ptr<CameraNode>> getAllCameras();
  void setPhysicsWorld(std::shared_ptr<PhysicsWorld> p) { _pPhysicsWorld = p; }
  void setWindow(std::shared_ptr<GraphicsWindow> x) { _pGraphicsWindow = x; }
  void setActiveCamera(std::shared_ptr<CameraNode> x);

  virtual void drawDeferred(RenderParams& rp) override;
  virtual void drawForward(RenderParams& rp)override;
  virtual void drawShadow(RenderParams& rp) override;
  virtual void drawForwardDebug(RenderParams& rp) override;
  virtual void drawNonDepth(RenderParams& rp) override; // draw the non-depth test items (last)
  virtual void drawTransparent(RenderParams& rp) override; //These come after the way after, the very end
  virtual void drawUI(RenderParams& rp) override;

  virtual std::shared_ptr<TreeNode> attachChild(std::shared_ptr<TreeNode> pChild, bool bValidate = true) override;
  virtual bool detachChild(std::shared_ptr<TreeNode> pChild) override;

  void afterAttachedToWindow();
  uint64_t getFrameNumber();

private:
  bool _bDebugDisableCull = false;
  bool _bDrawDebug = false;
  bool _bShowDebugText = false;
  bool _bDebugShowWireframe = false;
  bool _bDebugClearWhite = false;
  bool _bDebugDisableShadows = false;
  bool _bDebugDisableDepthTest = false;

  std::shared_ptr<UiLabel> _pDebugLabel = nullptr;
  std::shared_ptr<LightManager> _pLightManager = nullptr;
  std::shared_ptr<ProjectFile> _pProjectFile = nullptr;
  std::shared_ptr<PhysicsWorld> _pPhysicsWorld = nullptr;
  std::shared_ptr<UiScreen> _pUiScreen = nullptr;
  std::shared_ptr<CameraNode> _pActiveCamera = nullptr;
  std::shared_ptr<CameraNode> _pDefaultCamera = nullptr;
  std::shared_ptr<GraphicsWindow> _pGraphicsWindow = nullptr;
  std::shared_ptr<RenderBucket> _pRenderBucket = nullptr;
  std::shared_ptr<ParticleManager> _pParticleManager = nullptr;
  //The default fly camera must always be available.
//std::shared_ptr<FlyingCameraControls> _pFlyCam = nullptr;

  //Test data.
  std::shared_ptr<MeshNode> _pQuadMeshBackground = nullptr;
  std::shared_ptr<Texture2D> _pTex = nullptr;
  std::shared_ptr<Atlas> _pParticlesAtlas = nullptr;

  void init() override;
  void createUi();
  void setDebugMode();
  void draw2d();
  void drawDebugText();
  void debugChangeRenderState();
  void drawBackgroundImage();
  void createFlyingCamera();
  void makeParticles();
  void dbgl(string_t);
};
}//ns BR2

#endif
