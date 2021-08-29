#include "Creature.h"

Engine::Object::Creature::Creature(const std::string &tileMapName) : Object(tileMapName) {

}

Engine::Object::Creature::Creature(const std::string &tileMapName, const Engine::Common::Position &position)
: Object(tileMapName, position) {

}

void Engine::Object::Creature::onInteraction(const Engine::Object::Object &) {
    // do nothing
}
