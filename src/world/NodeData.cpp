#include "../base/Hash.h"
#include "../base/BinaryFile.h"
#include "../world/NodeData.h"


namespace BR2 {
NodeData::NodeData(const string_t& name) {
  _strName = name;
}
NodeData::~NodeData() {
}
void NodeData::deserialize(std::shared_ptr<BinaryFile> bf) {
  bf->readString(_strName);
}
void NodeData::serialize(std::shared_ptr<BinaryFile> bf) {
  bf->writeString(std::move(_strName));
}
uint32_t NodeData::getHashedName() {
  if (_iNameHash == 0) {
    _iNameHash = STRHASH(_strName);
  }
  return _iNameHash;
}


}//ns BR2
