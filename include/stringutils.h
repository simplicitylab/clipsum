/*****************************************************
 *
 * Header StringUtls class
 *
 * @author Glenn De Backer <glenn@simplicity.be>
 *
 *****************************************************/
#include <string>
#include <regex>
#include <vector>
#include <iostream>

/**
 * StringUtils
 *
 * @author Glenn De Backer <glenn@simplicity.be>
 */
class StringUtils
{
  public:
    std::string trim(std::string text);
    std::string extractSentences(int numberOfSentences, std::string text);
    std::string extractWords(int numberOfWords, std::string text);

};
