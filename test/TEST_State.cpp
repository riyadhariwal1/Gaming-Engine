#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "State.h"
#include "Loader.h"

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
  }

    virtual void TearDown() override {
      delete game_settings;
      delete configuration;
      delete constant;
      delete variable;
      delete per_Player;
      delete per_Audience;
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
};


TEST_F(StateTest, State_GlobalMessage_checkIfNeedsState) {
  // EXTRACT STATE
  AllPlayers allPlayer;
  State mock_state(allPlayer.getList(), *configuration, *constant, *variable, *per_Player, *per_Audience);

  //Global Message should have Rounds replaced
  string value = "Round {round}. Choose your weapon!";
  bool gm_needs_state = mock_state.checkIfStateValueNeeded(value);

  EXPECT_TRUE(gm_needs_state);
}
