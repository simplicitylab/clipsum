/*****************************************************
 *
 * StringUtils class
 *
 * @author Glenn De Backer <glenn@simplicity.be>
 *
 *****************************************************/

#include "../include/stringutils.h"

/**
 * Trim text
 * @param  std::string text  to trim
 * @return std::string trimmed text
 */
std::string StringUtils::trim(std::string text){
  auto wsfront=std::find_if_not(text.begin(),text.end(),[](int c){return std::isspace(c);});
  auto wsback=std::find_if_not(text.rbegin(),text.rend(),[](int c){return std::isspace(c);}).base();
  return (wsback<=wsfront ? std::string() : std::string(wsfront,wsback));
}

/**
 * Extract sentences
 * @param  int numberOfWords of words to extract
 * @param  string text to extract
 * @return string
 */
std::string StringUtils::extractSentences(int numberOfSentences, std::string text){
  // will hold our sentences
  std::vector<std::string> sentences;

  // split our text into sentences
  std::regex rgx ("(.*?)\\.");

  std::regex_iterator<std::string::iterator> rit ( text.begin(), text.end(), rgx );
  std::regex_iterator<std::string::iterator> rend;

  // iterate over sentences to fill our vector of sentences
  std::string sentence;
  while (rit!=rend) {
    // store sentence in our vector of strings
    sentence = ""; sentence =  trim(rit->str()); sentence += " ";
    sentences.push_back(sentence);
    ++rit;
  }

  // be sure that the number of sentences required
  // isn't bigger then what is available
  if(numberOfSentences > sentences.size()){
    numberOfSentences = sentences.size();
  }

  // build our output
  std::string output;

  for(int i = 0, l = numberOfSentences; i < l; i++){
    output += sentences.at(i);
  }
  return output;
}

/**
 * Extract words
 * @param  int numberOfWords to extract
 * @param  string text to extract
 * @return string
 */
std::string StringUtils::extractWords(int numberOfWords, std::string text){
  // will hold our words
  std::vector<std::string> words;

  // split our text into words
  std::regex rgx ("(.*?)\\s");
  std::regex_iterator<std::string::iterator> rit ( text.begin(), text.end(), rgx );
  std::regex_iterator<std::string::iterator> rend;


  // iterate over words
  std::string word;
  while (rit!=rend) {
    // store our word in our vector of words
    word = ""; word =  trim(rit->str()); word += " ";
    words.push_back(word);
    // increase our counters
    ++rit;
  }

  // be sure that the number of words required
  // isn't bigger then what is available
  if(numberOfWords > words.size()){
    numberOfWords = words.size();
  }

  // build our output
  std::string output;

  for(int i = 0, l = numberOfWords; i < l; i++){
    output += words.at(i);
  }

  return output;
}
