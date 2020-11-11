#include "Add.h"

// AddRule( per-player, value)
AddRule::AddRule(Player& variable, int count) {
   // give a point to player who won the round
   variable.playerWins(count);
}
