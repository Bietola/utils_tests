#pragma once

#include <cassert>

#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

// forwarding
class World;

// generic body
class Body : public sf::Drawable, public sf::Transformable {
    public:
        // world used by all bodies
        static World gWorld;

    protected:
        // physics body
        b2Body* mPhysicsBody = nullptr;

    public:
        // simple constructore
        Body(const b2Vec2& position, const b2Vec2& size, const float density,
             const b2BodyType bodyType);

        // draw function
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

        // to be called every frame
        virtual void update(const sf::Time& time) = 0;
};
