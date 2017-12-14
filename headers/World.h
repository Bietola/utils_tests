#pragma once

#include <memory>
#include <vector>

#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

#include "Body.h"

// world
class World: public sf::Drawable, public sf::Transformable {
    public:
        // some custom types
        using BodyPtr = Body*;

    private:
        // physics world
        b2World mPhysicsWorld;

        // all bodies
        std::vector<BodyPtr> mBodies;

    public:
        // constructor
        World(const b2Vec2& gravity);

        // getters
        b2World& getPhysicsWorld() {return mPhysicsWorld;}

        // spawn body
        template <class BodyType, typename... Args>
        void spawn(Args&&... args);

        // update world
        void update(const sf::Time& delta);

        // draw world to render target
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override; 
};

// template methods
template <class BodyType, typename... Args>
void World::spawn(Args&&... args) {
    auto bodyPtr = new BodyType(std::forward<Args>(args)...);
    mBodies.push_back(bodyPtr);
}
