#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "State.h"
#include "Loader.h"
#include "Helper.h"

class StateTest : public ::testing::Test {
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

// TEST GETTING LISTS FROM STATE
TEST_F(StateTest,List_config) {
  // get list
  string config_rounds_upfrom_1 = "configuration.Rounds.upfrom(1)";
  vector<GameVariant> result = mock_state->getStateList(config_rounds_upfrom_1);
  GameVariant expected = 10;
  EXPECT_TRUE(expected == result[0]);

  // replace with list element inside {}
  GameVariant element = result[0];
  string given_value = "Round {round}. Choose your weapon!";
  string result_str = replaceInString(given_value, element);

  string expected_str = "Round 10. Choose your weapon!";
  EXPECT_TRUE(expected_str == result_str);
}

TEST_F(StateTest, List_weapons){
  // get list
  string weapons = "weapons";
  vector<GameVariant> result = mock_state->getStateList(weapons);

  EXPECT_TRUE(3 == result.size());

}

TEST_F(StateTest, List_players) {
  // get list
  Player m("Michelle");
  Player k("Kamala");
  mock_state->UpdateState_PlayersList(m);
  mock_state->UpdateState_PlayersList(k);

  vector<Player> result = mock_state->getPlayers();
  size_t expected = 2;
  EXPECT_TRUE(expected == result.size());

  // replace with list element
  GameVariant element = result[0];
  string given_value = "{player.name}, choose your weapon!";
  string result_str = replaceInString(given_value, element);
  string expected_str = "Kamala, choose your weapon!";
  EXPECT_TRUE(expected_str == result_str);

}
