#include "World.h"

World::World(const b2Vec2& gravity):
    mPhysicsWorld(gravity) {}

void World::update(const sf::Time& delta) {
    // update physics body
    mPhysicsWorld.Step(delta.asSeconds(), 8, 3);

    // udpate bodies
    for(auto bodyPtr : mBodies) {
        bodyPtr->update(delta);
    }
}

void World::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    // set transform
    states.transform = getTransform();

    // draw all bodies
    for(auto bodyPtr : mBodies) {
        target.draw(*bodyPtr, states);
    }
}
