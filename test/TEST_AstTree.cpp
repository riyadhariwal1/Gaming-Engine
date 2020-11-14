#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include "AstTree.h"
#include "Loader.h"
#include "Helper.h"

class GameTest : public ::testing::Test
{
protected:
    virtual void TearDown() override
    {
        delete mock_astTree;
    }

    AstTree *mock_astTree;
};

//Read simple Rule
TEST_F(GameTest, List_config)
{
    string filePath = "players.json";
    ifstream ifs(filePath, std::ifstream::binary);
    if (ifs.fail())
    {
        throw std::runtime_error("Cannot open Json file");
    }
    json GAMEJSON = json::parse(ifs);
    json rules = GAMEJSON["rules"];
    mock_astTree = new AstTree(rules);
    EXPECT_TRUE(1 == mock_astTree->getAstTree().size());
};

//Read complex Rule
TEST_F(GameTest, List_config)
{
    string filePath = "rockPaperScissors.json";
    ifstream ifs(filePath, std::ifstream::binary);
    if (ifs.fail())
    {
        throw std::runtime_error("Cannot open Json file");
    }
    json GAMEJSON = json::parse(ifs);
    json rules = GAMEJSON["rules"];
    mock_astTree = new AstTree(rules);
    EXPECT_TRUE(5 == mock_astTree->getAstTree().size());
}
