#include <iostream>
#include <vector>
#include <string>

class Ability {
protected:
    std::string name;
    int damage;
    int manaCost;
public:
    Ability(std::string name, int damage, int manaCost) : name(name), damage(damage), manaCost(manaCost) {}
    virtual void execute() = 0; // virtual function for executing the ability
    std::string getName() const { return name; }
    int getDamage() const { return damage; }
    int getManaCost() const { return manaCost; }
};

class Character {
protected:
    std::string name;
    int health;
    int level;
    std::vector<Ability*> abilities; // vector of abilities that the character can use
public:
    Character(std::string name, int health, int level) : name(name), health(health), level(level) {}
    virtual void useAbility(int index) { abilities[index]->execute(); } // virtual function for using abilities
    void addAbility(Ability* ability) { abilities.push_back(ability); }
    std::string getName() const { return name; }
    int getHealth() const { return health; }
    int getLevel() const { return level; }
};

class Warrior : public Character {
public:
    Warrior(std::string name, int health, int level) : Character(name, health, level) {}
    void useAbility(int index) override {
        std::cout << "Warrior " << getName() << " uses " << abilities[index]->getName() << "!\n";
        abilities[index]->execute();
    }
};

class Archer : public Character {
public:
    Archer(std::string name, int health, int level) : Character(name, health, level) {}
    void useAbility(int index) override {
        std::cout << "Archer " << getName() << " uses " << abilities[index]->getName() << "!\n";
        abilities[index]->execute();
    }
};

class Mage : public Character {
public:
    Mage(std::string name, int health, int level) : Character(name, health, level) {}
    void useAbility(int index) override {
        std::cout << "Mage " << getName() << " uses " << abilities[index]->getName() << "!\n";
        abilities[index]->execute();
    }
};

class Slash : public Ability {
public:
    Slash() : Ability("Slash", 20, 10) {}
    void execute() override { std::cout << "Slash does " << getDamage() << " damage!\n"; }
};

class Fireball : public Ability {
public:
    Fireball() : Ability("Fireball", 30, 20) {}
    void execute() override { std::cout << "Fireball does " << getDamage() << " damage!\n"; }
};

class Heal : public Ability {
public:
    Heal() : Ability("Heal", -30, 20) {}
    void execute() override { std::cout << "Heal restores " << -getDamage() << " health!\n"; }
};

int main() {
    Warrior warrior("Bob the Warrior", 100, 10);
    Archer archer("Alice the Archer", 80, 8);
    Mage mage("Mike the Mage", 60, 6);

    Ability* slash = new Slash();
    Ability* fireball = new Fireball();
    Ability* heal = new Heal();

    warrior.addAbility(slash);
    warrior.addAbility(heal);
    archer.addAbility(slash);
    archer.addAbility(fireball);
    //mage.addAbility(fire
	mage.addAbility(heal);

    // Gameplay
    std::cout << "Welcome to the game!\n";

    std::cout << warrior.getName() << " has " << warrior.getHealth() << " health and is at level " << warrior.getLevel() << ".\n";
    std::cout << archer.getName() << " has " << archer.getHealth() << " health and is at level " << archer.getLevel() << ".\n";
    std::cout << mage.getName() << " has " << mage.getHealth() << " health and is at level " << mage.getLevel() << ".\n";

    // Warrior uses ability
    std::cout << "\n" << warrior.getName() << " uses ability 0:\n";
    warrior.useAbility(0);
    std::cout << "\n" << archer.getName() << " uses ability 1:\n";
    archer.useAbility(1);
    std::cout << "\n" << mage.getName() << " uses ability 2:\n";
    mage.useAbility(2);

    // Archer uses ability
    std::cout << "\n" << archer.getName() << " uses ability 0:\n";
    archer.useAbility(0);
    std::cout << "\n" << mage.getName() << " uses ability 1:\n";
    mage.useAbility(1);
    std::cout << "\n" << warrior.getName() << " uses ability 1:\n";
    warrior.useAbility(1);

    // Mage uses ability
    std::cout << "\n" << mage.getName() << " uses ability 0:\n";
    mage.useAbility(0);
    std::cout << "\n" << warrior.getName() << " uses ability 0:\n";
    warrior.useAbility(0);
    std::cout << "\n" << archer.getName() << " uses ability 1:\n";
    archer.useAbility(1);

    // Display current status of the game
    std::cout << "\nCurrent status of the game:\n";
    std::cout << warrior.getName() << " has " << warrior.getHealth() << " health and is at level " << warrior.getLevel() << ".\n";
    std::cout << archer.getName() << " has " << archer.getHealth() << " health and is at level " << archer.getLevel() << ".\n";
    std::cout << mage.getName() << " has " << mage.getHealth() << " health and is at level " << mage.getLevel() << ".\n";

    // Free allocated memory
    delete slash;
    delete fireball;
    delete heal;

return 0;
}

