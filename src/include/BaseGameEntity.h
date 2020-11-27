#ifndef __BASE_GAME_ENTITY_H
#define __BASE_GAME_ENTITY_H
#include <memory>
using std::enable_shared_from_this;

class BaseGameEntity : public enable_shared_from_this<BaseGameEntity> {
 private:
  int id;                  // Unique ID
  static int nextValidId;  // Updated every time an entity is instantiated
  void SetId(int id);

 public:
  BaseGameEntity(int id) { SetId(id); }
  virtual ~BaseGameEntity() {}
  virtual void Update() = 0;  // All entities must implement an update fn
  int Id() const { return id; }
};

#endif