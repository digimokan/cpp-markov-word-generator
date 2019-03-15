/*******************************************************************************
module:   ProgramOpts
author:   digimokan
date:     12 MAR 2019
purpose:  process program options and act on them (make objs, take actions, etc)
*******************************************************************************/

/*******************************************************************************
* SYSTEM INCLUDES
*******************************************************************************/

#include <boost/program_options.hpp>
#include <cstddef>
#include <filesystem>
#include <iostream>
#include <memory>
#include <string>

/*******************************************************************************
* USER INCLUDES
*******************************************************************************/

#include "ProgramOpts.hpp"
#include "WordBatchGenerator.hpp"

/*******************************************************************************
* CONSTRUCTORS
*******************************************************************************/

ProgramOpts::ProgramOpts (int argc, char* argv[])
  : argc{argc},
    argv{argv},
    opts{"OPTIONS"},
    parser{argc, argv},
    order{},
    min_word_length{},
    max_word_length{},
    num_words_to_gen{} {
  this->define_opts();
}

/*******************************************************************************
* SPECIALIZED METHODS
*******************************************************************************/

std::shared_ptr<WordBatchGenerator> ProgramOpts::create_word_generator () {
  try {
    this->parse_opts();
    this->check_opts();
  } catch (const std::exception& ex) {
    std::cerr << ex.what() << '\n';
  }
  return this->make_word_gen();
}

/*******************************************************************************
* HELPER METHODS
*******************************************************************************/

void ProgramOpts::define_opts () {
  this->opts.add_options()
    ("help,h", "print this help message")
    ("order,o", boost::program_options::value<std::size_t>(&this->order)->default_value(2),
      "markov model order (min 1, default 2)")
    ("min-word-length,n", boost::program_options::value<std::size_t>(&this->min_word_length)->default_value(3),
      "min word length to generate (default 3)")
    ("max-word-length,x", boost::program_options::value<std::size_t>(&this->max_word_length)->default_value(10),
      "max word length to generate (default 10")
    ("words-text-file,w", boost::program_options::value<std::string>(&this->words_text_file),
      "text file with words to train model")
    ("num-words-to-gen,g", boost::program_options::value<std::size_t>(&this->num_words_to_gen),
      "number of random words to generate");
  this->posopts.add("words-text-file", 1);
  this->posopts.add("num-words-to-gen", 1);
  this->parser.options(this->opts).positional(this->posopts);
  this->parser.options(this->opts).style(boost::program_options::command_line_style::default_style);
}

void ProgramOpts::parse_opts () {
  boost::program_options::parsed_options parsedopts{ this->parser.run() };
  boost::program_options::store(parsedopts, this->optsmap);
  boost::program_options::notify(this->optsmap);
}

void ProgramOpts::check_opts () {
  if (this->optsmap.count("help") > 0)
    this->opt_help();

  if (this->optsmap.count("order") > 0)
    this->opt_order();

  if (this->optsmap.count("min-word-length") > 0)
    this->opt_min_word_length();

  if (this->optsmap.count("max-word-length") > 0)
    this->opt_max_word_length();

  if (this->optsmap.count("words-text-file") > 0)
    this->opt_words_text_file();
  else
    this->opt_missing("words-text-file");

  if (this->optsmap.count("num-words-to-gen") > 0)
    this->opt_num_words_to_gen();
  else
    this->opt_missing("num-words-to-gen");
}

std::shared_ptr<WordBatchGenerator> ProgramOpts::make_word_gen () {
  return std::make_shared<WordBatchGenerator>(
    order,
    this->words_text_file,
    this->min_word_length,
    this->max_word_length,
    this->num_words_to_gen
  );
}

void ProgramOpts::opt_help () {
  const std::string prog_name{ "./markov-word-gen" };
  std::cout << "USAGE:\n";
  std::cout << "  " << prog_name << "  -h\n";
  std::cout << "  " << prog_name << "  [-o <n>]  [-n <n>]  [-x <n>]\n";
  std::cout << "                     <words-text-file>  <num-words-to-gen>\n";
  std::cout << this->opts;
  std::exit(0);
}

void ProgramOpts::opt_missing (const std::string& optname) {
  std::cerr << "missing option/argument: " << optname;
  std::exit(1);
}

void ProgramOpts::opt_order () {
  if (this->order == 0) {
    std::cerr << "markov model order must be >= 1";
    std::exit(1);
  }
}

void ProgramOpts::opt_min_word_length () {
  if (this->min_word_length == 0) {
    std::cerr << "min word length must be >= 1";
    std::exit(1);
  }
}

void ProgramOpts::opt_max_word_length () {
  if (this->max_word_length == 0) {
    std::cerr << "max word length must be >= 1";
    std::exit(1);
  }
}

void ProgramOpts::opt_words_text_file () {
  std::filesystem::path fpath{ std::filesystem::current_path() / this->words_text_file };
  if (! std::filesystem::exists(fpath)) {
    std::cerr << "words text file does not exist";
    std::exit(1);
  }
}

void ProgramOpts::opt_num_words_to_gen () {
  if (this->num_words_to_gen == 0) {
    std::cerr << "num words to generate must be >= 1";
    std::exit(1);
  }
}

