#ifndef GAME_RULEFORWIN_H
#define GAME_RULEFORWIN_H

template<int condition>
class RuleForWin{
public:
    bool ConditionToWin(Player& player) {
        if (condition % 2 == 0) { // enemies
            if (player.get_killed_enemies() == 5)
                return true;
        } else { //keys
            if (player.get_keys() == 3)
                return true;
        }
        return false;
    }
};

#endif //GAME_RULEFORWIN_H
