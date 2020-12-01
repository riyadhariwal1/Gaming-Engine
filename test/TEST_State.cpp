#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include <string>

#include "State.h"
#include "Loader.h"
#include "Parser.h"

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

TEST_F(StateTest, test_print) {
}

TEST_F(StateTest, get_configuration_rounds_01) {
  // get list
  string config_rounds_upfrom_1 = "configuration.Rounds.upfrom(1)";
  GameVariant result = mock_state->getFromState(config_rounds_upfrom_1);
  GameVariant expected = 10;
  EXPECT_TRUE(expected == result);

  // replace with list element inside {}
  string converted_element = boost::apply_visitor( gameVariant_to_string(), result);
  string given_value = "Round {round}. Choose your weapon!";

  string result_str = replaceInString(given_value, converted_element );
  string expected_str = "Round 10. Choose your weapon!";
  EXPECT_TRUE(expected_str == result_str);

}

// players are not gameVariants
TEST_F(StateTest, get_players_list_02) {

  Player m("Michelle");
  Player k("Kamala");
  mock_state->UpdateState_PlayersList(m);
  mock_state->UpdateState_PlayersList(k);

  vector<Player> result = mock_state->getPlayers();
  size_t expected = 2;
  EXPECT_TRUE(expected == result.size());

  //replace with list element
  string given_value = "{player.name}, choose your weapon!";
  string result_str = replaceInString(given_value, result[0].getPlayerName());
  string expected_str = "Michelle, choose your weapon!";

  EXPECT_TRUE(expected_str == result_str);

}

TEST_F(StateTest, add_result_to_player_03) {

  Player k("Kamala");
  mock_state->UpdateState_PlayersList(k);
  vector<Player> player01 = mock_state->getPlayers();

  //add this new choice to the state
  string selected_choice = "rock";
  string input_choice_result = "player.weapon";

  // interpreter needs to place selected choice into state


}

TEST_F(StateTest, get_weapons_list_04){
  // weapons is a vector<map<str,str>>
  string list = "weapons";
  GameVariant result = mock_state->getFromState(list);

  VARIATION test = boost::apply_visitor( check_type() , result);
  EXPECT_TRUE(test == VARIATION::VECTOR);

  // conversion helps us test the type of gameVariant
  // and also use the original type
  GameVariant_Types values = boost::apply_visitor( conversion(), result );
  EXPECT_TRUE(3 == values.type_vector.size());

  EXPECT_TRUE(values.type_vector[0]["name"]=="Rock");
  EXPECT_TRUE(values.type_vector[1]["name"]=="Paper");


}


TEST_F(StateTest, get_winners_from_variables_06){
  string list = "winners";
  GameVariant result = mock_state->getFromState(list);

  VARIATION test = boost::apply_visitor( check_type() , result);
  EXPECT_TRUE(test == VARIATION::VECTOR);

}

TEST_F(StateTest, random_test){

}
