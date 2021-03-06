/**
*  @file MbiFile.h
*  @date January 13, 2018
*  @author MetalMario971
*/
#pragma once
#ifndef __MBIFILE_15158731212931798061_H__
#define __MBIFILE_15158731212931798061_H__

#include "../base/IOBase.h"
#include "../model/ModelHeader.h"

namespace BR2 {
/**
*  @class MbiFile
*  @brief Mob Binary file.  The main file for all models.
*   TODO: When we release this, we must implement multiple file version importers for backwards compat.
*/
class MbiFile : public GLFramework {
public:
public:
  MbiFile(std::shared_ptr<GLContext> ct);
  virtual ~MbiFile() override;

  std::vector<std::shared_ptr<ModelSpec>>& getModelSpecs() { return _vecModels; }
  bool loadAndParse(string_t file);
  void save(string_t file);
private:
/*
0.4 - Added texture binding.
*/
  const string_t c_strMbiVersion = "0.04";
  std::vector<std::shared_ptr<ModelSpec>> _vecModels;
  std::shared_ptr<BinaryFile> _pFile = nullptr;
  string_t _fileLoc;
   
  void postLoad();
  void parseErr(string_t str, bool bDebugBreak, bool bFatal);
};

}//ns Game



#endif
