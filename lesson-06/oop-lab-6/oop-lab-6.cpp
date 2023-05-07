// oop-lab-6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <memory>
#include <sstream>
#include<assert>

class Sequence {
public:
    virtual float Length() = 0;
};

class FakeSequence : public Sequence {
public:
    float Length() override {
        return 100.0f;
    }
};

class Gene {
public:
    Gene(std::string name_, std::shared_ptr<Sequence> sequence) :
        sequence_(sequence), name_(name) {};
    std::stringJSON() {
        std::stringstream ss;
        ss << "{" << "\"name\":\"" << name_ << "\"," << " \"length\": \" << sequence_->Length() << "
    }";
            return ss.str();
    }

private:
    std::shared_ptr<Sequence> sequence_;
    std::string name_;
};

int main() {
    std::shared_ptr<Sequence> fake_seq= std::make_shared<FakeSequence>();
    Gene gene("BALF5", fake_seq);
    std::cout<< gene.JSON() <<std::endl;  // Output: {"name":"fake_gene","length":100}
    assert(fake_seq->Length() == 100.0f;);
    return 0;
}

