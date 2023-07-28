#include <iostream>
#include <windows.h>

int baseWarriorHealthPoint = 100;
int baseMageHealthPoint = 65;

int baseWarriorDamage = 52;
int baseMageDamage = 52;
int baseDamageMultiplier = 21;


enum CharacterClass {
    Warrior = 1,
    Mage = 2
};

enum MonsterType {
    Mantis = 1,
    Dragon = 2,
    Ape = 3,
    Witcher = 4,
    Tuco = 5
};

int CalculateRandomDamage(CharacterClass characterClass) {
    switch (characterClass) {
        case Warrior:
            return baseWarriorDamage + (rand() % baseDamageMultiplier + 1);
        case Mage:
            return baseMageDamage + (rand() % baseDamageMultiplier + 3);
    }
}

class Player {

public:
    Player(CharacterClass characterClass) {
        _characterClass = characterClass;

        switch (characterClass) {
            case Warrior:
                this->healthPoint = baseWarriorHealthPoint;
                this->damage = baseWarriorDamage;
                break;
            case Mage:
                this->healthPoint = baseMageHealthPoint;
                this->damage = baseMageDamage;
                break;
        }
    }

    CharacterClass _characterClass;
    int healthPoint;
    int damage;

    int GetHitDamage() {
        return CalculateRandomDamage(this->_characterClass);
    }
};

class Monster {
public:
    Monster(MonsterType monsterType) {
        _monsterType = monsterType;

        switch (monsterType) {
            case Mantis:
                this->healthPoint = 220;
                this->damage = 15;
                break;
            case Dragon:
                this->healthPoint = 375;
                this->damage = 35;
                break;
            case Ape:
                this->healthPoint = 255;
                this->damage = 25;
                break;
            case Witcher:
                this->healthPoint = 85;
                this->damage = 45;
                break;
            case Tuco:
                this->healthPoint = 600;
                this->damage = 10;
                break;
        }
    }

    MonsterType _monsterType;
    int healthPoint;
    int damage;
};

// Extension for cin to enum
std::istream &operator>>(std::istream &is, CharacterClass &i) {
    int tmp;
    if (is >> tmp)
        i = static_cast<CharacterClass>( tmp );
    return is;
}

void IntroducePlayer(Player player) {
    switch (player._characterClass) {
        case Mantis:
            std::cout << "You choose Warrior. HP:" << player.healthPoint << " DMG:" << player.damage << std::endl;
            break;
        case Mage:
            std::cout << "You choose Mage. HP:" << player.healthPoint << " DMG:" << player.damage << std::endl;
            break;
    }
}

Monster SpawnRandomMonster() {
    auto randomMonsterIndex = (rand() % 6);
    auto monsterType = MonsterType(randomMonsterIndex);

    return {monsterType};
}

void IntroduceMonster(Monster monster) {
    switch (monster._monsterType) {
        case Mantis:
            std::cout << "Mantis has been spawned. HP:" << monster.healthPoint << " DMG:" << monster.damage
                      << std::endl;
            break;
        case Dragon:
            std::cout << "Dragon has been spawned. HP:" << monster.healthPoint << " DMG:" << monster.damage
                      << std::endl;
            break;
        case Ape:
            std::cout << "Ape has been spawned. HP:" << monster.healthPoint << " DMG:" << monster.damage << std::endl;
            break;
        case Witcher:
            std::cout << "Witcher has been spawned. HP:" << monster.healthPoint << " DMG:" << monster.damage
                      << std::endl;
            break;
        case Tuco:
            std::cout << "Tuco has been spawned. HP:" << monster.healthPoint << " DMG:" << monster.damage << std::endl;
            break;
    }
}

int main() {
    srand(time(nullptr)); // For real random
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    CharacterClass characterClass;

    std::cout << "Hello adventurer! Choose your class wisely" << std::endl;
    std::cout << "Enter 1 for Warrior or 2 for Mage" << std::endl;

    std::cin >> characterClass;

    auto player = Player(characterClass);
    IntroducePlayer(player);

    auto monster = SpawnRandomMonster();
    IntroduceMonster(monster);

    do {
        // Player's Attack
        auto playerRandomDamage = player.GetHitDamage();
        monster.healthPoint -= playerRandomDamage;

        SetConsoleTextAttribute(hConsole, 11);
        std::cout << playerRandomDamage << " damage given to monster" << std::endl;
        std::cout << "Monster HP:" << monster.healthPoint << std::endl;

        if (monster.healthPoint <= 0) {
            SetConsoleTextAttribute(hConsole, 10);
            std::cout << "The monster died, you won!" << std::endl;
            return 0;
        }

        // Monster's Attack
        player.healthPoint -= monster.damage;

        SetConsoleTextAttribute(hConsole, 14);
        std::cout << monster.damage << " damage given to player" << std::endl;
        std::cout << "Player HP:" << player.healthPoint << std::endl;

        if (player.healthPoint <= 0) {
            SetConsoleTextAttribute(hConsole, 12);
            std::cout << "The player died, you lost!" << std::endl;
            return 0;
        }
    } while (player.healthPoint > 0 or monster.healthPoint > 0);
}



