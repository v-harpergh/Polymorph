
#include <iostream>
#include <vector>
#include <string>

class Instrument {
public:
    Instrument(std::string name, std::string sound) : name(name), sound(sound) {}

    virtual ~Instrument() = default;
    virtual void play() const = 0;

protected:
    std::string name;
    std::string sound;

    void makeSound(int repetitions) const {
        std::cout << name << ": ";

        for (int i = 0; i < repetitions; i++) {
            std::cout << sound;

            if (i < repetitions - 1) {
                std::cout << " ";
            }
        }

        std::cout << '\n';
    }
};

class Trumpet : public Instrument {
public:
    Trumpet() : Instrument("Trumpet", "doot") {}

    void play() const override {
        makeSound(3);
    }
};

class Violin : public Instrument {
public:
    Violin() : Instrument("Violin", "vwa") {}

    void play() const override {
        makeSound(5);
    }
};

class Piano : public Instrument {
public:
    Piano() : Instrument("Piano", "dee") {}

    void play() const override {
        makeSound(2);
    }
};

class Trombone : public Instrument {
public:
    Trombone() : Instrument("Trombone", "Dwooooo~") {}

    void play() const override {
        makeSound(1);
    }
};

class Singer : public Instrument {
public:
    Singer() : Instrument("Singer", "blah") {}

    void play() const override {
        makeSound(6);
    }
};

class orchestra {
public:
    void addInstrument(Instrument* inst) {
        Instruments.push_back(inst);
    }

    void play() const {
        for (const auto* inst : Instruments) {
            inst->play();
        }
    }

private:
    std::vector<Instrument*> Instruments;
};

int main() {
    Trumpet trumpet;
    Violin violin;
    Piano piano;
    Trombone trombone;
    Singer singer;

    orchestra symphony;

    symphony.addInstrument(&trumpet);
    symphony.addInstrument(&violin);
    symphony.addInstrument(&piano);
    symphony.addInstrument(&trombone);
    symphony.addInstrument(&trumpet);
    symphony.addInstrument(&singer);

    symphony.play();

    return 0;
}
