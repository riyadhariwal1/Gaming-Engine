#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include <string>
#include <fstream>
#include <sstream>

#include "Element.h"
#include "Interpreter.h"
#include "Player.h"

class InterpreterTest : public ::testing::Test {
protected:
  virtual void SetUp() override {
    string filePath = "rockPaperScissors.json";
    ifstream ifs(filePath, std::ifstream::binary);
    if (ifs.fail())
    {
        throw std::runtime_error("Cannot open Json file");
    }
    json GAMEJSON = json::parse(ifs);
    // EXTRACT GAME SPECIFICATION STRUCTURE
    config = GAMEJSON["configuration"];
    constants = GAMEJSON["constants"];
    variables = GAMEJSON["variables"];
    per_player = GAMEJSON["per-player"];
    per_audience = GAMEJSON["per-audience"];
    rules = GAMEJSON["rules"];

    game_settings = new Settings(jsonToMap(config["setup"]));
    configuration = new Configuration(config["name"], config["player count"]["min"],
                  config["player count"]["max"], config["audience"], *game_settings);
    constant = new Constants(jsonToMap(constants));
    variable = new Variables(jsonToMap(variables));
    per_Player = new PerPlayer(jsonToMap(per_player));
    per_Audience = new PerAudience(jsonToMap(per_audience));

    mock_state = new State(allPlayer, *configuration, *constant, *variable, *per_Player, *per_Audience);

  }

    virtual void TearDown() override {
      delete game_settings;
      delete configuration;
      delete constant;
      delete variable;
      delete per_Player;
      delete per_Audience;
      delete mock_state;
    }

  json config;
  json constants;
  json variables;
  json per_player;
  json per_audience;
  json rules;

  Settings* game_settings;
  Configuration* configuration;
  Constants* constant;
  Variables* variable;
  PerPlayer* per_Player;
  PerAudience* per_Audience;
  vector<Player> allPlayer;
  State* mock_state;
};

TEST_F(InterpreterTest, element_round) {
  Element e_round("10");
  string value = "Round {round}. Choose your weapon!";

  string result = INTERPRETER::InterpretString(value, e_round, *mock_state);
  //cout << result << endl;

  EXPECT_TRUE(result == "Round 10. Choose your weapon!");

}

TEST_F(InterpreterTest, element_player) {
  Player new_player("Kamala");
  Element e_round(new_player);
  string value = "{player.name}, choose your weapon!";

  string result = INTERPRETER::InterpretString(value, e_round, *mock_state);
  //cout << result << endl;

  EXPECT_TRUE(result == "Kamala, choose your weapon!");
}

TEST_F(InterpreterTest, noElement_choices_weapons) {
  // don't need use any elements in string
  Element no_element("none");
  string value = "weapons.name";

  string result = INTERPRETER::InterpretString(value, no_element, *mock_state);
  //cout << result << endl;

  EXPECT_TRUE(result == "Rock Paper Scissors ");

}

TEST_F(InterpreterTest, noElement_winners_size) {
  // don't need use any elements in string
  Player new_player("Kamala");
  mock_state->UpdateState_WinnersList(new_player);
  Element no_element("");

  string value = "winners.size";

  string result = INTERPRETER::InterpretString(value, no_element, *mock_state);
  //cout << result << endl;

  EXPECT_TRUE(result == "1");
}

TEST_F(InterpreterTest, noElement_winners_name) {
  // don't need use any elements in string
  Player winner1("Dean");
  Player winner2("Sam");
  mock_state->UpdateState_WinnersList(winner1);
  mock_state->UpdateState_WinnersList(winner2);
  Element no_element("");

  string value = "Winners: {winners.elements.name}";

  string result = INTERPRETER::InterpretString(value, no_element, *mock_state);
  //cout << result << endl;

  EXPECT_TRUE(result == "Winners: Dean Sam ");

}

TEST_F(InterpreterTest, condition_simple_equality) {
  // here (weapon.name) is actually a weapons element
  Player new_player("Kamala");
  mock_state->UpdateState_WinnersList(new_player);

  Element no_element("");
  string value = "winners.size == players.size";

  bool result = INTERPRETER::InterpretCondition(value,no_element, *mock_state);

  EXPECT_TRUE(result==false);

  mock_state->UpdateState_PlayersList(new_player);
  result = INTERPRETER::InterpretCondition(value,no_element, *mock_state);
  EXPECT_TRUE(result==true);

}

TEST_F(InterpreterTest, condition_equality_with0) {
  // here (weapon.name) is actually a weapons element
  Element no_element("");
  string value = "winners.size == 0";

  bool result = INTERPRETER::InterpretCondition(value,no_element, *mock_state);

  EXPECT_TRUE(result==true);

  Player new_player("Kamala");
  mock_state->UpdateState_WinnersList(new_player);

  result = INTERPRETER::InterpretCondition(value,no_element, *mock_state);
  EXPECT_TRUE(result==false);

}

// // test for shunting yard algorithm
// TEST_F(InterpreterTest, element_player_list_function) {
//   Player new_player("Kamala");
//   Element e_round(new_player);
//   string value = "players.elements.collect(player, player.weapon == weapon.beats)";
//
//   string result = INTERPRETER::InterpretString(value, e_round, *mock_state);
//   cout << result << endl;
//
//   EXPECT_TRUE(result == "Kamala, choose your weapon!");
//
// }

TEST_F(InterpreterTest, condition_weapon_element) {
  // does none of the players have a weapon==Rock ?
  Element weapon("Rock");
  string value = "!players.elements.weapon.contains(weapon.name)";

  Player new_player("Kamala");
  mock_state->UpdateState_WinnersList(new_player);

  bool result = INTERPRETER::InterpretCondition(value, weapon, *mock_state);
  EXPECT_TRUE(result==true);

}
