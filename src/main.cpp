/*****************************************************
 * Main entry
 *
 * @author Glenn De Backer <glenn@simplicity.be>
 *
 *****************************************************/

#include <iostream>
#include <iomanip>
#include <regex>

#include "../include/cxxopts.h"
#include "../include/lorem.h"
#include "../include/en.h"
#include "../include/nl.h"
#include "../include/de.h"
#include "../include/fr.h"
#include "../include/es.h"
#include "../include/it.h"
#include "../include/pt.h"
#include "../include/stringutils.h"

// enum that defines our extract types
enum ExtractTypes { words, sentences};

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
      std::cout<<std::endl;
      exit(0);
    }

    // if text option has been passed
    if (options.count("text"))
    {
      // text that has been chosen
      std::string chosenText =  options["text"].as<std::string>();

      // determine which text we will be using
      if(chosenText.compare("lorem") == 0){
        sourceText = loremText;
      }else if(chosenText.compare("en") == 0){
        sourceText = enText;
      }else if(chosenText.compare("nl") == 0){
        sourceText = nlText;
      }else if(chosenText.compare("fr") == 0){
        sourceText = frText;
      }else if(chosenText.compare("de") == 0){
        sourceText = deText;
      }else if(chosenText.compare("es") == 0){
        sourceText = esText;
      }else if(chosenText.compare("pt") == 0){
        sourceText = ptText;
      }else if(chosenText.compare("it") == 0){
        sourceText = itText;
      }else{
        sourceText = loremText;
      }
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

    switch(extractType)
    {
        case sentences:
          std::cout << strUtils.extractSentences(numberOfItems, sourceText) << std::endl;
          break;
        case words:
          std::cout<< strUtils.extractWords(numberOfItems, sourceText) << std::endl;
          break;
    }

    return 0;
  }catch (const cxxopts::OptionException& e){
    std::cout << e.what() << std::endl;
    exit(1);
  }
}
