#include "Add.h"
#include "State.h"
// AddRule( per-player, value)
AddRule::AddRule(string to,  value): to(to), value(value) {
}
void AddRule::execute(State& state){
   auto findList = findByName(to);
}