/*****************************************************
 * Main entry
 *
 * @author Glenn De Backer <glenn@simplicity.be>
 *
 *****************************************************/

#include <iostream>

#include "../include/cxxopts.h"
#include "../include/stringutils.h"
#include "../include/lorem.h"
#include "../include/en.h"
#include "../include/nl.h"
#include "../include/de.h"
#include "../include/fr.h"
#include "../include/es.h"
#include "../include/it.h"
#include "../include/pt.h"
#include "../include/ru.h"
#include "../include/se.h"
#include "../include/no.h"
#include "../include/fi.h"

// enum that defines our extract types
enum ExtractTypes { words, sentences};

/**
 * Gets our source text
 * @param string textName name of text
 * @return string source text
 */
std::string getSourceText(std::string textName){
  if(textName.compare("lorem") == 0){
    return loremText;
  }else if(textName.compare("en") == 0){
    return enText;
  }else if(textName.compare("nl") == 0){
    return nlText;
  }else if(textName.compare("fr") == 0){
    return frText;
  }else if(textName.compare("de") == 0){
    return deText;
  }else if(textName.compare("es") == 0){
    return esText;
  }else if(textName.compare("pt") == 0){
    return ptText;
  }else if(textName.compare("it") == 0){
    return itText;
  }else if(textName.compare("ru") == 0){
    return ruText;
  }else if(textName.compare("se") == 0){
    return seText;
  }else if(textName.compare("no") == 0){
    return noText;
  }else if(textName.compare("fi") == 0){
    return fiText;
  }else if(textName.compare("dk") == 0){
    return dkText;
  }else{
    return loremText;
  }
}

/**
 * Main entry
 */
int main(int argc, char* argv[])
{
  // our default values
  std::string sourceText = loremText;
  int numberOfItems = 10;
  ExtractTypes extractType = sentences;

  try
  {
    //setup option parser
    cxxopts::Options options("clipsum", " CLI Lipsum generator - written by Glenn De Backer <glenn@simplicity.be>");
    options.add_options()
      ("l,list-text", "List available texts")
      ("t,text", "Text to use a source (default lorem ipsum)",  cxxopts::value<std::string>(), "text-name")
      ("w,words", "Extract words",  cxxopts::value<int>(), "number")
      ("s,sentences", "Extract sentences",  cxxopts::value<int>(), "number")
      ("h,help", "Print help")
      ;

    options.parse(argc, argv);

    // show help
    if (options.count("help"))
    {
      std::cout << options.help({"", "Group"}) << std::endl;
      exit(0);
    }

    // if text option has been passed
    if (options.count("list-text"))
    {
      std::cout<<"Available texts:"<<std::endl;
      std::cout<<"----------------"<<std::endl;
      std::cout<< " * lorem            Lorem ipsum (default)" <<std::endl;
      std::cout<< " * en               English text" <<std::endl;
      std::cout<< " * nl               Dutch text" <<std::endl;
      std::cout<< " * fr               French text" <<std::endl;
      std::cout<< " * de               German text" <<std::endl;
      std::cout<< " * es               Spanish text" <<std::endl;
      std::cout<< " * pt               Portuguese text" <<std::endl;
      std::cout<< " * it               Italian text" <<std::endl;
      std::cout<< " * ru               Russian text" <<std::endl;
      std::cout<< " * se               Swedish text" <<std::endl;
      std::cout<< " * no               Norwegian text" <<std::endl;
      std::cout<< " * fi               Finnish text" <<std::endl;
      std::cout<< " * dk               Danish text" <<std::endl;
      std::cout<<std::endl;
      exit(0);
    }

    // if text option has been passed
    if (options.count("text"))
    {
      // text that has been chosen
      std::string chosenText =  options["text"].as<std::string>();

      // get our source text
      sourceText = getSourceText(chosenText);
    }

    // if sentence option has been passed
    if (options.count("sentences"))
    {
      // set extract type to sentences
      extractType = sentences;

      // set number of items
      numberOfItems =  options["sentences"].as<int>();
    }

    // if words option has been passed
    if (options.count("words"))
    {
      // set extract type to sentences
      extractType = words;

      // set number of items
      numberOfItems =  options["words"].as<int>();
    }

    // generate our "ipsum"
    StringUtils strUtils;
    std::string output;

    switch(extractType)
    {
        case sentences:
        {
          // extract sentences
          std::vector<std::string> extractedSentences;
          extractedSentences = strUtils.extractSentences(numberOfItems, sourceText);

          for(int i = 0, l = extractedSentences.size(); i < l; i++){
            output += extractedSentences.at(i);
          }

          break;
        }
        case words:
        {
          std::vector<std::string> extractedWords;
          extractedWords = strUtils.extractWords(numberOfItems, sourceText);

          for(int i = 0, l = extractedWords.size(); i < l; i++){
            output += extractedWords.at(i);
          }

          break;
        }
    }

    // output
    std::cout<<output<<std::endl;

    return 0;
  }catch (const cxxopts::OptionException& e){
    std::cout << e.what() << std::endl;
    exit(1);
  }
}
