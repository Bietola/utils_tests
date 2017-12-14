#include "Body.h"

#include "World.h"

// initialize body global world
World Body::gWorld(b2Vec2(0.f, 9.8f));

// simple constructore
Body::Body(const b2Vec2& position, const b2Vec2& size, const float density,
           const b2BodyType bodyType) {
    // init graphics transform
    setOrigin(size.x / 2.f, size.y / 2.f);
    setPosition(position.x, position.y); 
    setScale(size.x, size.y);

    // init body definition
    b2BodyDef bodyDef;
    bodyDef.position = position;
    bodyDef.type     = bodyType;

    // create body
    mPhysicsBody = gWorld.getPhysicsWorld().CreateBody(&bodyDef);

    // init body shape
    b2PolygonShape shape;
    shape.SetAsBox(size.x, size.y);
    
    // init body fixture
    b2FixtureDef fixtureDef;
    fixtureDef.density = density;
    fixtureDef.shape   = &shape;

    // attach fixture to body
    mPhysicsBody->CreateFixture(&fixtureDef);
}

// draw function
void Body::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    // assertions
    assert(mPhysicsBody && "drawing body with no physics body...");

    // set up transform
    states.transform.translate(getPosition() * 30.f);
    states.transform.scale(getScale() * 30.f);
    states.transform.rotate(getRotation());

    // create sprite (just a red rectangle for now...)
    sf::RectangleShape sprite({2.f, 2.f});
    sprite.setOrigin(1.f, 1.f);
    sprite.setFillColor(sf::Color::Red);

    // draw sprite
    target.draw(sprite, states);
}
