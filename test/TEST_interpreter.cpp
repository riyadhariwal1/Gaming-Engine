#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include <string>

#include "Interpreter.h"
#include "Loader.h"
#include "Parser.h"

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

TEST_F(InterpreterTest, test_print) {
  mock_state->print();
}