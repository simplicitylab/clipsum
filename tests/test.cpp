#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "../include/stringutils.h"

/**
 * Test the extraction of sentences
 */
TEST_CASE( "StringUtils extract sentences", "[stringutils.extractSentences]" ) {

    // init string utils
    StringUtils strUtils;

    // text to test
    std::string testText = R"(Hello world. How are you doing ? This is a test!)";

    // extract sentences
    std::vector<std::string> sentences = strUtils.extractSentences(1000, testText);

    // assertions
    CHECK(sentences.size() == 3);
}

/**
 * Test the extraction of words
 */
TEST_CASE( "StringUtils extract words", "[stringutils.extractWords]" ) {

    // init string utils
    StringUtils strUtils;

    // text to test
    std::string testText = R"(Proin dictum metus eget justo fringilla elementum. In faucibus arcu malesuada lacus blandit, sit amet consequat urna pretium. Phasellus interdum orci sit amet est vehicula vestibulum. )";

    // extract words
    std::vector<std::string> sentences = strUtils.extractWords(1000, testText);

    // assertions
    CHECK(sentences.size() == 26);
}
