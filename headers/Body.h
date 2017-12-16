#pragma once

#include <cassert>
#include <initializer_list>

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

        // thing to draw
        sf::ConvexShape mSprite;

    public:
        // simple constructore
        Body(const b2Vec2& position, const std::initializer_list<b2Vec2>& vertices,
             const float density, const b2BodyType bodyType);

        // draw function
        void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

        // to be called every frame
        virtual void update(const sf::Time& time) = 0;
};
