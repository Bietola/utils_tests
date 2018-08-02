#include <iostream>
#include <memory>

#include "utils/prototype.h"

class Greeter :
    public utl::clonable_interface<Greeter> {

    protected:
        std::string mAdjective = "wonderful";

    public:
        void setAdjective(const std::string& adj) { mAdjective = adj; }

        virtual ~Greeter() { std::cout << "me dead now..." << std::endl; }

        virtual void greet() const = 0;
};

class WorldGreeter : 
    public utl::clonable<Greeter, WorldGreeter> {

    private:
        std::string mAdditionalAdjective = "wonderful";

    public:
        WorldGreeter(const std::string& adj): mAdditionalAdjective(adj) {}

        void greet() const override {
            std::cout << "hello " + mAdjective + ", " + mAdditionalAdjective + " world!" << std::endl;
        }
};

int main() {
    std::unique_ptr<Greeter> greeter1 = std::make_unique<WorldGreeter>("peaceful");
    std::unique_ptr<Greeter> greeter2 = greeter1->clone();
    greeter2->setAdjective("cruel");

    greeter1->greet();
    greeter2->greet();

    return 0;
}
