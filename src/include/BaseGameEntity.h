#ifndef __BASE_GAME_ENTITY_H
#define __BASE_GAME_ENTITY_H

class BaseGameEntity {
 private:
  int id;                  // Unique ID
  static int nextValidId;  // Updated every time an entity is instantiated
  void SetId(int id);

 public:
  BaseGameEntity(int id) { SetId(id); }
  virtual ~BaseGameEntity() {}
  virtual void update() = 0;  // All entities must implement an update fn
  int Id() const { return id; }
};

#endif