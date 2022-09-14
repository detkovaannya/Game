#include "game/game.h"
#include "game/Rules/SizeOfFieldRule.h"
#include "game/Rules/RuleForEnemy.h"
#include "game/Rules/RuleForWin.h"


int main(){
    Game<RuleForEnemy <5>, SizeOfFieldRule<20>, RuleForWin<1>> game;
    game.GameStart();

    return 0;
}
